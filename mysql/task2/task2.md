### 1.导入示例数据库，教程 <https://www.yiibai.com/mysql/how-to-load-sample-database-into-mysql-database-server.html>

### 2.SQL是什么？MySQL是什么？

SQL(发音为字母S-Q-L或sequel)是结构化查询语言(Structured Query Language)的缩写。SQL是一种专门用来与数据库沟通的语言。

MySQL 是一个关系型数据库管理系统，由瑞典 MySQL AB 公司开发，目前属于 Oracle 公司。MySQL 是一种关联数据库管理系统，关联数据库将数据保存在不同的表中，而不是将所有数据放在一个大仓库内，这样就增加了速度并提高了灵活性。

### 3. 查询语句 SELECT FROM

使用`SELECT`语句从表或[视图](http://www.yiibai.com/mysql/views.html)获取数据。表由行和列组成，如电子表格。 通常，我们只希望看到子集行，列的子集或两者的组合。`SELECT`语句的结果称为结果集，它是行列表，每行由相同数量的列组成。

`SELECT`语句的语法：

```sql
SELECT 
    column_1, column_2, ...
FROM
    table_1
[INNER | LEFT |RIGHT] JOIN table_2 ON conditions
WHERE
    conditions
GROUP BY column_1
HAVING group_conditions
ORDER BY column_1
LIMIT offset, length;

```

`SELECT`语句由以下列表中所述的几个子句组成：

```sql
SELECT之后是逗号分隔列或星号(`*`)的列表，表示要返回所有列。
FROM 指定要查询数据的表或视图。
JOIN 根据某些连接条件从其他表中获取数据。
WHERE过滤结果集中的行。
GROUP BY将一组行组合成小分组，并对每个小分组应用聚合函数。
HAVING 过滤器基于 GROUP BY 子句定义的小分组。
ORDER BY 指定用于排序的列的列表。
LIMIT 限制返回行的数量。


```

##### 去重语句  

```sql
DISTINCT
```

![image-20190401101219819](https://github.com/voidspiral/Datawhale/blob/master/mysql/img/task2-1.png)

```sql
SELECT DISTINCT jobtitle FROM employees;
```

![image-20190401101349233](https://github.com/voidspiral/Datawhale/blob/master/mysql/img/task2-2.png)

##### 前N个语句

SELECT语句返回指定表中所有匹配的行，很可能是每一行。如果你只想返回第一行或者一定数量的行，该怎么办呢?这是可行的，然而遗憾的

是，各种数据库中的这一SQL实现并不相同。

在SQL Server和Access中使用SELECT时，可以使用TOP关键字来限制最多返回多少行，如下所示:

```sql
SELECT customerName
FROM customers
LIMIT 5;
```

![task2-3.png](https://github.com/voidspiral/Datawhale/blob/master/mysql/img/task2-3.png)

也可以实现M至N(某一段的)记录查询

LIMIT offset, recnum 

其中offset

```sql
SELECT customerName
FROM customers
LIMIT 2, 5; 
```

其中offset为从第几条（M+1）记录开始，recnum为返回的记录条数。

![task2-4.png](https://github.com/voidspiral/Datawhale/blob/master/mysql/img/task2-4.png)

#### CASE...END判断语句

<https://dev.mysql.com/doc/refman/5.7/en/case.html>                                                                                                                     

```mysql
CASE case_value
    WHEN when_value THEN statement_list
    [WHEN when_value THEN statement_list] ...
    [ELSE statement_list]
END CASE
```

Or:

```mysql
CASE
    WHEN search_condition THEN statement_list
    [WHEN search_condition THEN statement_list] ...
    [ELSE statement_list]
END CASE
```

当然我们可以在那个教程提供的数据库上随便试一下

```mysql
SELECT 
(CASE
		WHEN customerNumber  > 150 THEN 'A'
		WHEN customerNumber <= 150 THEN 'B'
END)
FROM 	payments;
```

### 4.筛选语句 WHERE

如果使用[SELECT语句](http://www.yiibai.com/mysql/select-statement-query-data.html)但不使用WHERE子句在表中查询数据，则会获取表中的所有行记录，这些行记录中大部分是不想要的行记录。例如，在一些表中存放商业交易中的数据。 从这些表中获取所有行，尤其是对于诸如员工，销售订单，采购订单，生产订单等的大型表格来说，这是没有意义的，因为我们经常想要的是一些特定的数据，例如本季度的销售额 ，今年销量比去年同期的销量等等。

WHERE子句允许根据指定的过滤表达式或条件来指定要选择的行。

#### 可用于 WHERE 子句中的比较运算符

![task2-5.png](https://github.com/voidspiral/Datawhale/blob/master/mysql/img/task2-5.png)

```mysql
BETWEEN 运算符
expr [NOT] BETWEEN begin_expr AND end_expr;
```

取值范围 [begin_expr, end_expr]

MySQL LIKE运算符

```mysql
LIKE 匹配基于模式匹配的值。

LIKE操作符通常用于基于模式查询选择数据。以正确的方式使用LIKE运算符对于增加/减少查询性能至关重要。
LIKE操作符允许您根据指定的模式从表中查询选择数据。 因此，LIKE运算符通常用在SELECT语句的WHERE子句中。
MySQL提供两个通配符，用于与 LIKE 运算符一起使用，
它们分别是：百分比符号 '%'  和下划线 '_'。

百分比('%')通配符允许匹配任何字符串的零个或多个字符。下划线('_')通配符允许匹配任何单个字符。

```

#### MySQL LIKE 与 ESCAPE子句

```mysql
有时想要匹配的模式包含通配符，例如 10%，_20 等这样的字符串时。在这种情况下，您可以使用 ESCAPE 子句指定转义字符，以便 MySQL 将通配符解释为文字字符。如果未明确指定转义字符，则反斜杠字符 \ 是默认转义字符。
SELECT 
    productCode, productName
FROM
    products
WHERE
    productCode LIKE '%\_20%';
```

OR

```mysql
SELECT 
    productCode, productName
FROM
    products
WHERE
    productCode LIKE '%$_20%' ESCAPE '$';
```

**LIKE 操作符强制MySQL扫描整个表以找到匹配的行记录，因此，它不允许数据库引擎使用索引进行快速搜索。因此，当要从具有大量行的表查询数据时，使用`LIKE`运算符来查询数据的性能会大幅降低。**

#### MySQL IN操作符介绍

```mysql
SELECT 
    column1,column2,...
FROM
    table_name
WHERE 
 (expr|column_1) IN ('value1','value2',...);
```

####  MySQL IN与子查询

```mysql
SELECT 
    orderNumber, customerNumber, status, shippedDate
FROM
    orders
WHERE
    orderNumber IN (SELECT 
            orderNumber
        FROM
            orderDetails
        GROUP BY orderNumber
        HAVING SUM(quantityOrdered * priceEach) > 60000);
```

上面的整个查询可以分为`2`个查询。

首先，子查询使用`orderDetails`表中的[GROUP BY](http://www.yiibai.com/mysql/group-by.html)和[HAVING子句](http://www.yiibai.com/mysql/having.html)返回总额大于`60000`的订单号列表。

```mysql
SELECT 
    orderNumber
FROM
    orderDetails
GROUP BY orderNumber
HAVING SUM(quantityOrdered * priceEach) > 60000;
```

```shell
mysql> SELECT 
    orderNumber
FROM
    orderDetails
GROUP BY orderNumber
HAVING SUM(quantityOrdered * priceEach) > 60000;
+-------------+
| orderNumber |
+-------------+
|       10165 |
|       10287 |
|       10310 |
+-------------+
3 rows in set


```

```mysql
其次，主查询从 orders 表中获取数据，并在 WHERE 子句中应用 IN 运算符。
SELECT 
    orderNumber, customerNumber, status, shippedDate
FROM
    orders
WHERE
    orderNumber IN (10165,10287,10310);
```

```shell
mysql> SELECT 
    orderNumber, customerNumber, status, shippedDate
FROM
    orders
WHERE
    orderNumber IN (10165,10287,10310);
+-------------+----------------+---------+-------------+
| orderNumber | customerNumber | status  | shippedDate |
+-------------+----------------+---------+-------------+
|       10165 |            148 | Shipped | 2013-12-26  |
|       10287 |            298 | Shipped | 2014-09-01  |
|       10310 |            259 | Shipped | 2014-10-18  |
+-------------+----------------+---------+-------------+
3 rows in set
```

5. 分组语句 GROUP BY

####  MySQL GROUP BY子句简介

```mysql
GROUP BY子句通过列或表达式的值将一组行分组为一个小分组的汇总行记录。 GROUP BY子句为每个分组返回一行。换句话说，它减少了结果集中的行数。
经常使用 GROUP BY子句与聚合函数一起使用，如 SUM， AVG， MAX， MIN 和 COUNT。 SELECT子句中使用聚合函数来计算有关每个分组的信息。
GROUP BY子句是SELECT语句的可选子句。 下面是 GROUP BY子句语法：

SELECT 
    c1, c2,..., cn, aggregate_function(ci)
FROM
    table
WHERE
    where_conditions
GROUP BY c1 , c2,...,cn;

GROUP BY 子句必须出现在 FROM 和 WHERE 子句之后。 在 GROUP BY关键字之后是一个以逗号分隔的列或表达式的列表，这些是要用作为条件来对行进行分组。


```

#### MySQL GROUP BY与聚合函数

<https://www.yiibai.com/mysql/group-by.html>

```mysql
可使用聚合函数来执行一组行的计算并返回单个值。 GROUP BY子句通常与聚合函数一起使用以执行计算每个分组并返回单个值。
例如，如果想知道每个状态中的订单数，可以使用COUNT函数与GROUP BY子句查询语句，如下所示：
SELECT 
    status, COUNT(*) AS total_number
FROM
    orders
GROUP BY status;
```

#### MySQL GROUP BY与HAVING子句

```mysql
可使用HAVING子句过滤GROUP BY子句返回的分组。以下查询使用HAVING子句来选择2013年以后的年销售总额。

```

### 6 排序语句 MySQL ORDER BY子句简介

```mysql
当使用 SELECT 语句查询表中的数据时，结果集不按任何顺序进行排序。要对结果集进行排序，请使用 ORDER BY子句。 ORDER BY子句允许：

对单个列或多个列排序结果集。按升序或降序对不同列的结果集进行排序。

ORDER BY子句的语法：
SELECT column1, column2,...
FROM tbl
ORDER BY column1 [ASC|DESC], column2 [ASC|DESC],...

```

#### 7.函数

[MySQL聚合函数](http://www.yiibai.com/mysql/aggregate-functions.html) - 提供最常用的MySQL聚合函数的简要概述。

数值函数

[avg()函数](http://www.yiibai.com/mysql/avg.html) -  计算一组值或表达式的平均值。

[count()函数](http://www.yiibai.com/mysql/count.html) - 计算表中的行数。

[instr()函数](http://www.yiibai.com/mysql/instr.html) - 返回子字符串在字符串中第一次出现的位置。

[sum()函数](http://www.yiibai.com/mysql/sum.html) - 计算一组值或表达式的总和。

[min()函数](http://www.yiibai.com/mysql/min.html) - 在一组值中找到最小值。

[max()函数](http://www.yiibai.com/mysql/max-function.html) - 在一组值中找到最大值。

[group_concat()函数](http://www.yiibai.com/mysql/group_concat.html) - 将字符串从分组中连接成具有各种选项(如`DISTINCT`，`ORDER BY`和`SEPARATOR`)的字符串。

日期和时间函数

[curdate()函数](http://www.yiibai.com/mysql/curdate.html) - 返回当前日期。

[datediff()函数](http://www.yiibai.com/mysql/datediff.html) - 计算两个`DATE`值之间的天数。

[day()函数](http://www.yiibai.com/mysql/day.html) - 获取指定日期月份的天(日)。

[date_add()函数](http://www.yiibai.com/mysql/date_add.html) - 将时间值添加到日期值。

[date_sub()函数](http://www.yiibai.com/mysql/date_sub.html) - 从日期值中减去时间值。

[date_format()函数](http://www.yiibai.com/mysql/date_format.html) - 根据指定的日期格式格式化日期值。

[dayname()函数](http://www.yiibai.com/mysql/dayname.html) - 获取指定日期的工作日的名称。

[dayofweek()函数](http://www.yiibai.com/mysql/dayofweek.html) - 返回日期的工作日索引。

[extract()函数](http://www.yiibai.com/mysql/extract.html) - 提取日期的一部分。

[now()函数](http://www.yiibai.com/mysql/now.html) - 返回当前日期和时间。

[month()函数](http://www.yiibai.com/mysql/month.html) - 返回一个表示指定日期的月份的整数。

[str_to_date()函数](http://www.yiibai.com/mysql/str_to_date.html) - 将字符串转换为基于指定格式的日期和时间值。

[sysdate()函数](http://www.yiibai.com/mysql/sysdate.html) - 返回当前日期。

[timediff()函数](http://www.yiibai.com/mysql/timediff.html) - 计算两个`TIME`或`DATETIME`值之间的差值。

[timestampdiff()函数](http://www.yiibai.com/mysql/timestampdiff.html) - 计算两个`DATE`或`DATETIME`值之间的差值。

[week()函数](http://www.yiibai.com/mysql/week.html) -  返回一个日期的星期数值。

[weekday()函数](http://www.yiibai.com/mysql/weekday.html) - 返回一个日期表示为工作日/星期几的索引。

[year()函数](http://www.yiibai.com/mysql/year.html) - 返回日期值的年份部分。

字符串函数

[concat()函数](http://www.yiibai.com/mysql/sql-concat-in-mysql.html) - 将两个或多个字符串组合成一个字符串。

[length()函数&char_length()函数](http://www.yiibai.com/mysql/string-length.html) - 以字节和字符获取字符串的长度。

[left()函数](http://www.yiibai.com/mysql/left-function.html) - 获取指定长度的字符串的左边部分。

[replace()函数](http://www.yiibai.com/mysql/string-replace-function.html) - 搜索并替换字符串中的子字符串。

[substring()函数](http://www.yiibai.com/mysql/substring.html) - 从具有特定长度的位置开始提取一个子字符串。

[trim()函数](http://www.yiibai.com/mysql/trim.html) - 从字符串中删除不需要的字符。

[find_in_set()函数](http://www.yiibai.com/mysql/find_in_set.html) - 在逗号分隔的字符串列表中找到一个字符串。

[format()函数](http://www.yiibai.com/mysql/format-function.html) - 格式化具有特定区域设置的数字，舍入到小数位数。

### 8.SQL注释

```sql
1.
SELECT prod_name -- 这是一条注释 FROM Products;
2.
# 这是一条注释 
SELECT prod_name FROM Products;
3.
/* SELECT prod_name, vend_id FROM Products; */
SELECT prod_name
FROM Products;
```

### 9.SQL代码规范

[SQL编程格式的优化建议] <https://zhuanlan.zhihu.com/p/27466166>

[SQL Style Guide] [https://www.](https://www.sqlstyle.guide/)[,](https://www.sqlstyle.guide/)d[sqlstyle.guide/](https://www.sqlstyle.guide/)



\#作业#

项目一：查找重复的电子邮箱（难度：简单）

创建 email表，并插入如下三行数据

```sql
+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
```





编写一个 SQL 查询，查找 Email 表中所有重复的电子邮箱。

根据以上输入，你的查询应返回以下结果：

```sql
+---------+
| Email   |
+---------+
| a@b.com |
+---------+
```

答案:

```sql
SELECT Email
FROM
		email
GROUP BY Email
HAVING COUNT(Email) > 1;
```



说明：所有电子邮箱都是小写字母。

![task2-ans1.png](https://github.com/voidspiral/Datawhale/blob/master/mysql/img/task2-ans1.png)

项目二：查找大国（难度：简单）

创建如下 World 表

```sql
+-----------------+------------+------------+--------------+---------------+
| name            | continent  | area       | population   | gdp           |
+-----------------+------------+------------+--------------+---------------+
| Afghanistan     | Asia       | 652230     | 25500100     | 20343000      |
| Albania         | Europe     | 28748      | 2831741      | 12960000      |
| Algeria         | Africa     | 2381741    | 37100000     | 188681000     |
| Andorra         | Europe     | 468        | 78115        | 3712000       |
| Angola          | Africa     | 1246700    | 20609294     | 100990000     |
+-----------------+------------+------------+--------------+---------------+
```

如果一个国家的面积超过300万平方公里，或者(人口超过2500万并且gdp超过2000万)，那么这个国家就是大国家。

编写一个SQL查询，输出表中所有大国家的名称、人口和面积。

例如，根据上表，我们应该输出:

```sql
+--------------+-------------+--------------+
| name         | population  | area         |
+--------------+-------------+--------------+
| Afghanistan  | 25500100    | 652230       |
| Algeria      | 37100000    | 2381741      |
+--------------+-------------+--------------+

```

答案2 :

```mysql
SELECT name, population, area
FROM
		World
WHERE	area > 3000000 or (population > 25000000 AND gdp > 20000000);
```

![task2-ans2.png](https://github.com/voidspiral/Datawhale/blob/master/mysql/img/task2-ans2.png)