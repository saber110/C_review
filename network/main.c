#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "socket.h"
void getproto();
void getip();
void getallnetworkservice();
int main()
{
    //getproto();
    SocketConnect();
    return 0;
}
void getip()            //由域名获取ip
{
    struct hostent *host;
    char hostname[] = "www.163.com";
    char hostname2[]="www.gytsdfuerghfieuhr.com";
    struct in_addr in;
    struct sockaddr_in addr_in;
    extern int h_errno;

    if((host=gethostbyname(hostname))!=NULL)
    {
        memcpy(&addr_in.sin_addr.s_addr,host->h_addr_list,4);
        in.s_addr = addr_in.sin_addr.s_addr;
        printf("Domain : %s\n",hostname);
        printf("IP type : %d\n",host->h_addrtype);
        printf("IP addr : %s\n",inet_ntoa(in));
    }
    else
    {
        printf("Domain : %s\n",hostname);
        printf("error: %d\n",h_errno);
        printf("%s\n",hstrerror(h_errno));
    }

    if((host=gethostbyname(hostname2))!=NULL)
    {
        memcpy(&addr_in.sin_addr.s_addr,host->h_addr_list,4);
        in.s_addr = addr_in.sin_addr.s_addr;
        printf("Domain : %s\n",hostname2);
        printf("IP type : %d/n",host->h_addrtype);
        printf("IP addr : %s\n",inet_ntoa(in));
    }
    else
    {
        printf("Domain : %s\n",hostname2);
        printf("error: %d\n",h_errno);
        printf("%s\n",hstrerror(h_errno));
    }

}

void getproto()
{
    //getprotocolbyname
    struct protoent *pro;
    pro = getprotobyname("icmp");
    printf("proto name: %s\n",pro->p_name);
    printf("protocol number: %d\n",pro->p_proto);
    printf("protocol alias: %s\n",pro->p_aliases[0]);
    pro = getprotobyname("udp");
    printf("proto name: %s\n",pro->p_name);
    printf("protocol number: %d\n",pro->p_proto);
    printf("protocol alias: %s\n",pro->p_aliases[0]);
    pro = getprotobyname("tcp");
    printf("proto name: %s\n",pro->p_name);
    printf("protocol number: %d\n",pro->p_proto);
    printf("protocol alias: %s\n",pro->p_aliases[0]);
    //getprotobynumber
    for(int i =0;i<6;i++)
    {
        pro=getprotobynumber(i);
        printf("proto name: %s\n",pro->p_name);
        printf("protocol number: %d\n",pro->p_proto);
        printf("protocol alias: %s\n",pro->p_aliases[0]);
    }
}
//get all protos supportted
void getallproto()
{
    struct protoent *pro;
    while(pro=getprotoent())
    {
        printf("proto name: %s",pro->p_name);
        printf("protocol number: %d",pro->p_proto);
        printf("protocol alias: %s\n",pro->p_aliases[0]);
    }
}
//get all network service supportted
void getallnetworkservice()
{
    struct servent *ser;
    while(ser=getservent())
    {
        printf("name: %s",ser->s_name);
        printf("port: %d",ntohs(ser->s_port));
        printf("protocol : %s",ser->s_proto);
        printf("alias: %s\n",ser->s_aliases[0]);
    }
}
