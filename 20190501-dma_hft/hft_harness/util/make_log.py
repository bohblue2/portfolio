import os
from datetime import datetime

def save_csv(sth, dir_name):
    if not os.path.isdir(dir_name):
        os.mkdir(dir_name)
    filename = 'CoinData_' + datetime.now().strftime('%y%m%d') + '.csv'
    with open(dir_name + '/' + filename, 'w') as f:
        sth.to_csv(f)

# sth : pandas DataFrame 사용
def save_log_filename(sth, dir_name, filename):
    if not os.path.isdir(dir_name):
        os.mkdir(dir_name)
    sth['time'] = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    with open(dir_name + '/'+ filename + '.csv', 'a') as f:
        sth.to_csv(f, index='time')

# sth : numpy 사용
def save_log(sth, dir_name, prefix='Log_'):
    if not os.path.isdir(dir_name):
        os.mkdir(dir_name)

    filename = prefix + datetime.now().strftime("%y%m%d") + ".csv"
    time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    st = ""
    for val in sth:
        st = st + "," + str(val)
    st = time + st +"\n"
    with open(dir_name + '/' + filename, 'a') as f:
        f.write(st)

# sth : numpy 사용
def save_log_wotime(sth, dir_name, prefix='Log_'):
    if not os.path.isdir(dir_name):
        os.mkdir(dir_name)

    filename = prefix + ".csv"
    time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    st = ""
    for val in sth:
        st = st + "," + str(val)
    st = time + st +"\n"
    with open(dir_name + '/' + filename, 'a') as f:
        f.write(st)

# 모델 기록 함수 ( 매 반복 시 마다 교체)
def save_model(sth, dir_name, no):
    if not os.path.isdir(dir_name):
        os.mkdir(dir_name)
    sth['iteration'] = no
    with open(dir_name + '/model.csv', 'w') as f:
        sth.to_csv(f)
    print('model_saved')

def get_file_names():
    if os.path.exists('data'):
        data_folder_name = 'data'
    else:
        data_folder_name = os.listdir()[1]

    file_path = os.getcwd()
    full_file_path = os.path.join(file_path, data_folder_name)
    file_names = os.listdir(full_file_path)
    file_list = []
    for filename in file_names:
        if filename.find('btc') == 0:
            file_list.append(filename)
    return full_file_path, file_list