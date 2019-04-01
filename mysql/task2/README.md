# #任务二#

MySQL 基础 （一）- 查询语句



\#任务时间#

请于**4月2日22:00前**完成，在本文章评论打卡。逾期尚未打卡的会被清退。



\#学习内容#

\1. 导入示例数据库，教程 <https://www.yiibai.com/mysql/how-to-load-sample-database-into-mysql-database-server.html>

\2. SQL是什么？MySQL是什么？

\3. 查询语句 SELECT FROM 

​    语句解释

​    去重语句

​    前N个语句

​    CASE...END判断语句

\4. 筛选语句 WHERE 

​    语句解释

​    运算符/通配符/操作符

\5. 分组语句 GROUP BY

​    聚集函数

​    语句解释

​    HAVING子句

\6. 排序语句 ORDER BY 

​    语句解释

​    正序、逆序

\7. 函数

​    时间函数

​    数值函数

​    字符串函数

\8. SQL注释

\9. SQL代码规范

​    [SQL编程格式的优化建议] <https://zhuanlan.zhihu.com/p/27466166>

​    [SQL Style Guide] <https://www.sqlstyle.guide/>



\#作业#

项目一：查找重复的电子邮箱（难度：简单）

创建 email表，并插入如下三行数据

+----+---------+

| Id | Email   |

+----+---------+

| 1  | a@b.com |

| 2  | c@d.com |

| 3  | a@b.com |

+----+---------+



编写一个 SQL 查询，查找 Person 表中所有重复的电子邮箱。

根据以上输入，你的查询应返回以下结果：

+---------+

| Email   |

+---------+

| a@b.com |

+---------+

说明：所有电子邮箱都是小写字母。



项目二：查找大国（难度：简单）

创建如下 World 表

+-----------------+------------+------------+--------------+---------------+

| name            | continent  | area       | population   | gdp           |

+-----------------+------------+------------+--------------+---------------+

| Afghanistan     | Asia       | 652230     | 25500100     | 20343000      |

| Albania         | Europe     | 28748      | 2831741      | 12960000      |

| Algeria         | Africa     | 2381741    | 37100000     | 188681000     |

| Andorra         | Europe     | 468        | 78115        | 3712000       |

| Angola          | Africa     | 1246700    | 20609294     | 100990000     |

+-----------------+------------+------------+--------------+---------------+

如果一个国家的面积超过300万平方公里，或者(人口超过2500万并且gdp超过2000万)，那么这个国家就是大国家。

编写一个SQL查询，输出表中所有大国家的名称、人口和面积。

例如，根据上表，我们应该输出:

+--------------+-------------+--------------+

| name         | population  | area         |

+--------------+-------------+--------------+

| Afghanistan  | 25500100    | 652230       |

| Algeria      | 37100000    | 2381741      |

+--------------+-------------+--------------+





#彩蛋#

考虑到本次集训有很多新手，本次作业赠送建表代码，意不意外，开不开心。

直接将附件code内容复制到cmd或者navicat运行就行。



**项目一**

-- 创建表

```sql
CREATE TABLE email (
ID INT NOT NULL PRIMARY KEY,
Email VARCHAR(255)
)
```





-- 插入数据

```sql
INSERT INTO email VALUES('1','a@b.com');
INSERT INTO email VALUES('2','c@d.com');
INSERT INTO email VALUES('3','a@b.com');
```







**项目二**

-- 创建表

```sql
CREATE TABLE World (
name VARCHAR(50) NOT NULL,
continent VARCHAR(50) NOT NULL,
area INT NOT NULL,
population INT NOT NULL,
gdp INT NOT NULL
);
```



-- 插入数据

```sql
INSERT INTO World
  VALUES('Afghanistan','Asia',652230,25500100,20343000);
INSERT INTO World 
  VALUES('Albania','Europe',28748,2831741,12960000);
INSERT INTO World 
  VALUES('Algeria','Africa',2381741,37100000,188681000);
INSERT INTO World
  VALUES('Andorra','Europe',468,78115,3712000);
INSERT INTO World
  VALUES('Angola','Africa',1246700,20609294,100990000);
```

