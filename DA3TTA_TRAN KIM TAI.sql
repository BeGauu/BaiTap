create database HANGHOA
use HANGHOA

create table HANGHOA( 
ma_hang nvarchar(4)primary key,
ten_hang nvarchar (50),
don_vi_tinh nvarchar (15)
)

create table DAIY( 
ma_dl nchar(4)primary key,
ten_dl nchar (40),
dchi_dl nvarchar (50)
)

create table MUA( 
ma_hang nvarchar(4),
ma_dl nchar(4),
ngay_mua nvarchar(10),
constraint KC primary key(ma_hang,ma_dl,ngay_mua),
soluong_mua int,
trigia_mua float
)

create table BAN( 
ma_hang nvarchar(4),
ma_dl nchar(4),
ngay_ban nvarchar(10),
constraint KCC primary key(ma_hang,ma_dl,ngay_ban),
soluong_ban int,
trigia_ban float
)
insert into HANGHOA values
('b001','nuoc uong dong chai lavie','thung'),
('b002','nuoc suoi vinh hao','thung'),
('b003','nuoc uong dong chai tra vi','thung'),
('c001','nescafe','hop'),
('c002','cafe g7','hop'),
('c003','vinacafe','hop'),
('d001','coca cola','thung'),
('d002','pepsi','thung'),
('d003','7up','thung'),
('m001','mi hao hao','thung'),
('m002','mi tien vua','thung'),
('m003','mi de nhat','thung'),
('s001','sua hop ong tho','hop'),
('s002','sua hop co gai ha lan','hop'),
('s003','sua hop ngoi sao phuong nam','hop');


insert into DAIY values
('a001','trung tinh','NULL'),
('a002','tien dat','NULL'),
('a003','phat dat','NULL');


insert into MUA values
('c001','a003','12/12/2012','2','50'),
('c002','a003','10/12/2012','4','100'),
('d001','a001','13/12/2012','5','200'),
('d001','a002','15/12/2012','20','800'),
('d002','a001','15/12/2012','20','300'),
('s002','a002','20/12/2012','30','300'),
('s002','a002','22/12/2012','10','100');

insert into BAN values
('b001','a002','12/12/2012','3','200'),
('b001','a003','11/12/2012','5','300'),
('b001','a003','14/12/2012','2','100'),
('c003','a003','16/12/2012','4','300'),
('d001','a001','18/12/2012','4','200'),
('d001','a002','25/12/2012','5','100'),
('d002','a001','20/12/2012','20','300'),
('d003','a002','25/12/2012','5','250');

select * from BAN
select * from DAIY
select * from HANGHOA
select * from MUA

--1) Viết câu truy vấn hiển thị tên và địa chỉ các đại lý có mua pepsi
select dl.ten_dl
from MUA m, DAIY dl, HANGHOA hh
where m.ma_dl=dl.ma_dl
and m.ma_hang=hh.ma_hang
and hh.ten_hang in ('pepsi')
group by dl.ten_dl

--2)  Viết câu truy vấn tìm trị giá bán nhỏ nhất trong ngày 25/12/2012
select min(b.trigia_ban) as trigiabannhonhat 
from  BAN b
where b.ngay_ban like '25/12/2012'

--3) Viết câu truy vấn tính tổng giá trị mua của sửa hôp cô gái hà lan
select sum(m.trigia_mua) as tongtrigiamua
from MUA m, DAIY dl, HANGHOA hh
where dl.ma_dl = m.ma_dl
and hh.ma_hang = m.ma_hang
and hh.ten_hang = 'sua hop co gai ha lan'

--4) Viết câu truy vấn tìm tổng giá trị mua theo từng đại lý
select dl.ten_dl, sum(m.trigia_mua) as tongtrigiamua
from MUA m, DAIY dl, HANGHOA hh
where dl.ma_dl = m.ma_dl
and hh.ma_hang =m.ma_hang
group by dl.ten_dl




