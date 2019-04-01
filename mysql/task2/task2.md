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

![image-20190401102417925](<https://github.com/voidspiral/Datawhale/blob/master/mysql/img/task2-3.png>)

