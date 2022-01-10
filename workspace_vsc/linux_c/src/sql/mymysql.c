#include "mymysql.h"
#include <stdio.h>
#include <string.h>
int connect(MYSQL *mysql, char *host, char *user, char *passwd)
{
   if (!mysql_real_connect(mysql, "127.0.0.1", "root", "", "test", 0, NULL, 0))
   { // 建立数据库连接
      fprintf(stderr, "无法连接数据库，错误原因：%s\n",
              mysql_error(mysql)); // 捕捉MySQL错误
      return 0;
   }
   else
   {
      puts("数据库连接成功");
      return 1;
   }
}
int exe_sql(MYSQL *mysql, char *sql)
{
   unsigned int len = strlen(sql);
   char sqlcmd[len];
   return mysql_real_query(mysql, sqlcmd, len);
}