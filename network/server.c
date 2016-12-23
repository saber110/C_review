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

#define LOCALPORT 4567

int main(int argc, char const *argv[]) {
    int mysock,len;
    struct sockaddr_in addr,client_addr;
    int i = 0;
    char msg[256];
    int addr_len;

    if((mysock=socket(AF_INET,SOCK_DGRAM,0))<0)
    {
      perror("error:");
      exit(1);
    }
    else
    {
      printf("socket created.\n");
      printf("socked id : %d\n",mysock);
    }

    bzero(&addr,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port=htons(LOCALPORT);
    addr.sin_addr.s_addr=htonl(INADDR_ANY);

    bzero(&client_addr,sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port=htons(LOCALPORT);

    if(bind(mysock,(struct sockaddr*)&addr,sizeof(addr))<0)//在socket上绑定端口与ip
    {
      perror("connect");
      exit(1);
    }
    else
    {
      printf("bind ok.\n");
      printf("local port :%d\n", LOCALPORT);
    }

    while (1) {
      bzero(&msg,sizeof(msg));
      addr_len=sizeof(struct sockaddr_in);
      len=recvfrom(mysock,msg,sizeof(msg),0,(struct sockaddr*)&client_addr,&addr_len);

      printf("%d :", i);
      i++;
      printf("message from : %s\n", inet_ntoa(addr.sin_addr));

      printf("message length :%d\n", len);
      printf("message :%s\n\n", msg);
      sendto(mysock,msg,len,0,(struct sockaddr*)&client_addr,addr_len);

    }
    return 0;
}
