
// 学号, 姓名, 入学时间
create table student(
    `id` int not null autoincrement,
    `xuehao` varchar(20) not null,
    `name` varchar(255) not null,
    `entime` datetime not null,
    primiary key('xuehao')
);

// 2020 入学的所有 姓罗的同学
select * from student where datetime(entime) > 2020 && name like '罗%';






