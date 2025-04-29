create table balance
(
    id                      bigint(10) auto_increment
        primary key,
    account                 varchar(255)                         not null comment '계좌번호',
    date                    datetime                             not null comment '날짜',
    total_purchage_amount   varchar(255)                         null comment '총매입금액',
    total_evaluation_amount varchar(255)                         null comment '총평가금액',
    total_evaluation_profit varchar(255)                         null comment '총평가손익금액',
    total_profit_ratio      varchar(255)                         null comment '총수익률',
    presume_deposit_asset   varchar(255)                         null comment '추정예탁자산',
    ts                      datetime default current_timestamp() null,
    constraint balance_account_date_uindex
        unique (account, date)
)
    comment '계좌평가잔고내역요청 opw00018';

create table balance_detail
(
    id                    bigint(10) auto_increment
        primary key,
    account               varchar(255)                         not null comment '계좌번호',
    date                  datetime                             not null comment '날짜',
    total_net_asset_early varchar(255)                         null comment '순자산액계_초',
    total_net_asset_late  varchar(255)                         null comment '순자산액계_말',
    evaluate_profit       varchar(255)                         null comment '평가손익',
    profit_ratio          varchar(255)                         null comment '수익률',
    turnover              varchar(255)                         null comment '회전율',
    ts                    datetime default current_timestamp() null,
    constraint balance_detail_account_date_uindex
        unique (account, date)
)
    comment '일별계좌수익률상세현황요청 opw00016';

create table balance_stock
(
    id              bigint(10) auto_increment
        primary key,
    account         varchar(255)                         not null comment '계좌번호',
    date            datetime                             not null comment '날짜',
    stock_num       varchar(255)                         null comment '종목번호',
    stock_name      varchar(255)                         null comment '종목명',
    evaluate_profit varchar(255)                         null comment '평가손익',
    profit_ratio    varchar(255)                         null comment '수익률',
    bought_price    varchar(255)                         null comment '매입가',
    cur_price       varchar(255)                         null comment '현재가',
    possess_amount  varchar(255)                         null comment '보유수량',
    evaluate_price  varchar(255)                         null comment '평가금액',
    possess_weight  varchar(255)                         null comment '보유비중',
    ts              datetime default current_timestamp() null,
    constraint balance_stock_account_date_stock_num_uindex
        unique (account, date, stock_num)
)
    comment '계좌평가잔고내역요청 opw00018';

create table complete_manage
(
    id          bigint(10) auto_increment
        primary key,
    date        datetime                             not null,
    is_complete tinyint(1)                           not null,
    ts          datetime default current_timestamp() null,
    constraint complete_manage_date_uindex
        unique (date)
)
    comment '관리 수집 완료여부';

create table trade
(
    id               bigint(10) auto_increment
        primary key,
    account          varchar(255)                         not null comment '계좌번호',
    date             datetime                             null comment '날짜',
    order_num        varchar(255)                         null comment '주문번호',
    stock_num        varchar(255)                         null comment '종목번호',
    trade_gubun      varchar(255)                         null comment '매매구분',
    order_kind_gubun varchar(255)                         null comment '주문유형구분',
    order_amount     varchar(255)                         null comment '주문수량',
    order_price      varchar(255)                         null comment '주문단가',
    fill_num         varchar(255)                         null comment '체결번호',
    fill_amount      varchar(255)                         null comment '체결수량',
    fill_price       varchar(255)                         null comment '체결단가',
    fill_time        datetime                             null comment '체결시간',
    ts               datetime default current_timestamp() null
)
    comment '계좌별주문체결현황요청 opw00009';

