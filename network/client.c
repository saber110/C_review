#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define REMOTEPORT 4567
#define REMOTEIP "127.0.0.1"

int main()
{
    int s,len;
    struct sockaddr_in addr;
    int addr_len;
    char msg[256];
    int i = 0;

    if((s = socket(AF_INET,SOCK_DGRAM,0))<0)
    {
        perror("error");
        exit(1);
    }
    else
    {
        printf("socket connected.\n");
        printf("socket id :%d\n",s);
        printf("REMOTE IP : %s\n",REMOTEIP);
        printf("Remote port: %d\n",REMOTEPORT);
    }

    len=sizeof(struct sockaddr_in);
    bzero(&addr,sizeof(addr));        //将结构体所在空间清零
    addr.sin_family=AF_INET;
    addr.sin_port=htons(REMOTEPORT);
    addr.sin_addr.s_addr = inet_addr(REMOTEIP);     //用长整数的形式设置ip

    while(1)
    {
        bzero(msg,sizeof(msg));
        addr_len=sizeof(struct sockaddr_in);        //设置地址结构的长度
        len=read(STDIN_FILENO,msg,sizeof(msg));
        sendto(s,msg,len,0,(struct sockaddr*)&addr,addr_len);
        printf("\nInput message: %s\n",msg);
        len=recvfrom(s,msg,sizeof(msg),0,(struct sockaddr*)&addr,&addr_len);

        printf("%d : ",i);
        i++;
        printf("Received message: %s\n",msg);
    }

    return 0;
}
