import scipy.cluster.hierarchy as sch
import numpy as np
import pandas as pd


"""
계층적 클러스터링 참고자료 : https://datascienceschool.net/view-notebook/094bcb7b86574711a2e8d81f26bce2f5/
"""
# 계층적 클러스터링
class Hrp_method():

    # 상관관계에 기초한 거리행렬 계산
    def correlDist(self, corr):
        """

        :param corr: 상관계수 행렬
        :return: 거리행렬
        """
        # 거리행렬 계산
        dist = ((1 - corr)/2.0) ** 0.5

        return dist


    # 역분산 포트폴리오 계산
    def getIVP(self, cov, **kargs):
        """

        :param cov: 공분산 행렬
        :param kargs:
        :return: 역분산포트폴리오
        """
        ivp = 1.0/np.diag(cov)

        ivp /= ivp.sum()

        return ivp


    # 클러스터별 분산 계산
    def getClusterVar(self,cov, cItems):
        """

        :param cov: covariance 의 pd.DataFrame
        :param cItems: 행렬 분할을 pd.Series
        :return: 공분산 float(double)
        """
        # 행렬분할
        cov_ = cov.loc[cItems,cItems]
        w_ = self.getIVP(cov_).reshape(-1,1)

        cVar = np.dot(np.dot(w_.T, cov_), w_)[0,0]

        return cVar


    # 클러스터된 아이템을 거리별로 정렬
    def getQuasiDiag(self, link):
        """

        :param link:
        :return:
        """

        link = link.astype(int)


        sortIx = pd.Series([link[-1,0], link[-1,1]])

        numItems = link[-1,3]  # 원시 아이템 개수

        while sortIx.max() >= numItems :
            sortIx.index =  range(0, sortIx.shape[0]*2, 2)  # 공간확보

            # 클러스터 찾기
            df_cluster_01 = sortIx[sortIx >= numItems]
            i = df_cluster_01.index
            j = df_cluster_01.values - numItems

            # 아이템 1 할당
            sortIx[i] = link[j,0]

            # 아이템 2 할당
            df_cluster_02 = pd.Series(link[j,1], index=i+1)
            sortIx = sortIx.append(df_cluster_02)

            # 재정렬 및 인덱스 재할당
            sortIx = sortIx.sort_index()
            sortIx.index = range(sortIx.shape[0])


        return sortIx.tolist()

    # 재귀적으로 이분 배분 계산
    def getRecBipart(self, cov, sortIx):

        # HRP 배분 계산
        w = pd.Series(1, index=sortIx)

        # 모든 아이템을 하나의 클러스터로 초기화
        cItems = [sortIx]

        while len(cItems) > 0 :
            # 데이터 이분
            cItems_tmp = []
            for cluster in cItems :
                # 각 클러스터를 1/2 로 나누기
                if len(cluster) > 1 :
                    cItems_tmp.append(cluster[0:len(cluster)//2])
                    cItems_tmp.append(cluster[len(cluster) // 2 : len(cluster)])
            # 클러스터 업데이트
            cItems = cItems_tmp

            for i in range(0,len(cItems), 2):
                cluster_01 = cItems[i]
                cluster_02 = cItems[i+1]

                # 각 클러스터의 variance 구하기
                cVar_01 = self.getClusterVar(cov, cluster_01)
                cVar_02 = self.getClusterVar(cov, cluster_02)

                # Alpha value 계산
                alpha = 1 - (cVar_01 / (cVar_01 + cVar_02))

                # 각 가중값 1,2 반영
                w[cluster_01] *= alpha
                w[cluster_02] *= 1 - alpha

        return w




    # HRP Method
    # 계층적 포트폴리오 구성
    def getHRP(self, cov, corr, link_method = 'single'):
        """

        :param cov: 공분산 행렬
        :param corr: 상관계수 행렬
        :param link_method: 클러스터링 구축 method = 'single','complete','average','weighted','centroid','ward'
        :return: HRP 이용한 최종 포트폴리오 가중치
        """
        corr, cov = pd.DataFrame(corr), pd.DataFrame(cov)

        # 상관 계수를 이용한 거리 행렬 구하기
        dist = self.correlDist(corr)

        # 클러스터링 구축 method = 'single','complete','average','weighted','centroid','ward'
        link = sch.linkage(dist, link_method)


        # 클러스터된 아이템 거리별정렬
        sortIx = self.getQuasiDiag(link)

        # 레이블 복구
        sortIx = corr.index[sortIx].tolist()

        # 최종 hrp 구하기
        hrp = self.getRecBipart(cov, sortIx)

        return hrp.sort_index()


# Frac Diff 함수
class FracDiffProc() :

    def __init__(self):
        return

    # 가중값 구하는 함수
    def getWeights(self, window_width, total_size) :
        """

        :param d: window size
        :param size: return 할 가중값 총 길이
        :return:
        """
        weight = [1.0]

        for k in range(1, total_size) :
            weight_temp = -weight[-1]/k * (window_width-k+1)
            weight.append(weight_temp)
        # Flatten
        weight = np.array(weight[::-1]).reshape(-1,1)

        return weight



    def fracDiff(self, series, d, thres = 0.01):


        # 1) 가장 긴 계열에 대한 가중값 계산
        weight = self.getWeights(d, series.shape[0])

        # 2) 가중값-손실 임계값에 기반을 두고 누락할 초기 calcs 를 결정(skip_idx)
        weight_temp = np.cumsum(abs(weight))
        weight_temp /= weight_temp[-1]
        skip_idx = weight_temp[weight_temp > thres].shape[0]

        # 3) 값에 가중값을 적용
        df_ret = {} # 최종 반환할 DataFrame
        for idx_name in series.columns :
            seriesF = series[[idx_name]].fillna(method='ffil').dropna()
            series_temp = pd.Series()

            for idx in range(skip_idx, seriesF.shape[0]):
                idx_F = seriesF.index[idx]

                if not np.isfinite(series.loc[idx_F,idx_name]) :
                    continue # NA 값은 pass
                series_temp[idx_F] = np.dot(weight[-(idx+1):,:].T, seriesF.loc[:idx_F])[0,0]
            df_ret[idx_name] = series_temp.copy(deep=True)

        # Dictionary로 묶여있는 Series -> DataFrame 전환
        df_ret = pd.concat(df_ret, axis=1)

        return df_ret


# 향후 진행 예정 : 머신러닝 전 데이터 전처리
class BaseDataProcessor :

    def __init__(self):

        return






# 임의 데이터 생성 후 HRP 테스트 코드

if __name__ == "__main__" :

    import random


    HRP = Hrp_method()

    def generateData(nObs, sLength, size0, size1, mu0, sigma0, sigma1F) :
        # 상관된 변수의 시계열
        # 1) 상관되지 않은 데이터의 랜덤 생성
        x = np.random.normal(mu0, sigma0, size = (nObs, size0))

        # 2) 변수 간 상관관계 생성
        cols = [random.randint(0, size0 -1) for i in range(size1)]
        y = x[:,cols] + np.random.normal(0, sigma0 * sigma1F, size=(nObs, len(cols)))
        x = np.append(x,y,axis=1)

        # 3) 공통 랜덤 충격
        point_c = np.random.randint(sLength, nObs - 1, size = 2)
        x[np.ix_(point_c, [cols[0], size0])] = np.array([[-0.5,  -0.5], [2,2]])

        # 4) 특정 랜덤 충격
        point_s = np.random.randint(sLength, nObs - 1, size = 2)
        x[point_s, cols[-1]] = np.array([-0.5, 2])
        print(x, cols)
        return x, cols



    def hrpMC(numIters = 1e2, nObs = 520, size0 = 5, size1 = 5, mu0 = 0, sigma0 = 1e-2, sigma1F=0.25, sLength = 260, rebal = 22) :
        """

        :param numIters:
        :param nObs:
        :param size0:
        :param size1:
        :param mu0:
        :param sigma0:
        :param sigma1F:
        :param sLength:
        :param rebal:
        :return:
        """

        numIter = 0
        pointers = range(sLength, nObs, rebal)
        stats = pd.Series(data=np.zeros(int(numIters)))

        while numIter < numIters :
            # 1) 데이터 준비
            x, cols = generateData(nObs, sLength, size0, size1, mu0, sigma0, sigma1F)
            # 결과 기록 series
            r = pd.Series()

            # 2) In smaple 포트폴리오 계산
            for pointer in pointers :
                x_ = x[pointer - sLength:pointer]
                cov_, corr_ = np.cov(x_, rowvar=0), np.corrcoef(x_, rowvar=0)
                # 3) Out of Sample 성능 계산
                x_ = x[pointer:pointer+rebal]

            w_ = HRP.getHRP(cov=cov_, corr=corr_)
            r_ = pd.Series(np.dot(x_, w_))
            r = r.append(r_)


            # 4) 결과 평가 및 저장
            r_ = r.reset_index(drop=True)
            p_ = (1 + r_).cumprod()
            stats.loc[numIter] = p_.iloc[-1] -1

            numIter += 1

        # 5) 결과 보고
        stats = pd.DataFrame(stats)
        stats.to_csv('stats.csv')
        df0, df1 = stats.std(), stats.var()
        print(pd.concat([df0,df1], axis=1))
        return

    hrpMC()