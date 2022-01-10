#include <mysql/mysql.h> //包含MySQL函数库
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymysql.h"
int test_mysql()
{
   MYSQL *mysql;     // 声明MySQL操作符
   MYSQL_RES *res;   // 声明结果集
   MYSQL_ROW row;    // 声明行操作符
   char sqlcmd[200]; // 保存插入语句
   int t, r;
   mysql = mysql_init(NULL); // 初始化连接处理程序
   if (connect(mysql, "127.0.0.1", "root", "test"))
   {
      t = exe_sql(mysql, "insert into users(name,password) value(\'mr\',\'111\')"); // 执行插入语句
      if (t)
         printf("插入数据库失败：%s\n", mysql_error(mysql));
      else
      {
         printf("插入成功！\n");
      }
   }
   else
   {
      printf("error");
   }
   mysql_close(mysql); // 关闭数据库连接
   return EXIT_SUCCESS;
}
