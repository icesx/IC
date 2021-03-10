#include<netdb.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
int main(int argc,char *argv[])
{
char *p1,**p2,len[INET6_ADDRSTRLEN];
struct hostent *pstr;
if(argc<2)
{
printf("usage:%s hostname\n",argv[0]);
return 1;
}
p1=*(&argv[1]);
if((pstr=gethostbyname(p1))==NULL)
{
printf("call error:%s,%s\n",p1,hstrerror(h_errno));
return 1;
}
printf("hostname:%s\n",pstr->h_name);
switch(pstr->h_addrtype)
{
case AF_INET:
case AF_INET6:
p2=pstr->h_addr_list;
for(;*p2!=NULL;p2++)
printf("address:%s\n",inet_ntop(pstr->h_addrtype,*p2,len,sizeof(len)));
break;
default:
printf("unknown addrtype!\n");
break;
}
return 0;
}

