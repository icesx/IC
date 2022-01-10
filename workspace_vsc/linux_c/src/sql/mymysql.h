#include <mysql/mysql.h>
int connect(MYSQL *mysql,char* host, char* user,char* passwd);
int exe_sql(MYSQL *mysql, char *sql);