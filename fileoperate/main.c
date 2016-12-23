#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
void store();
void makedir();
void delete();
void creatfile();
void writeFile();
int main(int argc, char const *argv[]) {
  int a=0;
  char b[10];
  //store(a,b);
  //makedir();
  //delete();
  creatfile();
  writeFile();
  readFile();
  return 0;
}
void store(int a ,char * b) {
  // fflush();
  FILE * fp;
  int c;
  char str[10];
  str[0] = 'i';
  fp = fopen("learn.txt","a+");
  if(fp==NULL)
    return;
  else
  {
    //fprintf(fp, "%s\n", "This is a test");
    // fscanf(fp,"%s",str);

    while(c=fgetc(fp)==EOF)
    {printf("test");break;}
        printf("%c", c);

  }
  fclose(fp);
}
void makedir()
{
    extern int errno;
    char *path="/home/huhaobin/C/auto";

    if(mkdir(path,0766)==0)
    {
        printf("created %s.\n",path);
    }
    else
    {
        printf("cannot created $s.\n",path);
        printf("errno %d.\n",errno);
        printf("ERR: %s.\n",strerror(errno));
    }
}

void delete()
{
    extern int errno;
    char *path="/home/huhaobin/C/auto";

    if(rmdir(path)==0)
    {
        printf("deleted %s.\n",path);
    }
    else
    {
        printf("cannot delete $s.\n",path);
        printf("errno %d.\n",errno);
        printf("ERR: %s.\n",strerror(errno));
    }
}

void creatfile()
{
//会覆盖原来的文件
    extern int errno;
    char *path="/home/huhaobin/C/auto.txt";

    if(creat(path,0766)!=-1)    //remove mkstemp
    {
        printf("created %s.\n",path);
    }
    else
    {
        printf("cannot creat $s.\n",path);
        printf("errno %d.\n",errno);
        printf("ERR: %s.\n",strerror(errno));
    }
}

void writeFile()
{
    extern int errno;
    char *path="/home/huhaobin/C/auto.txt";
    int fd;
    char s[]="welcome to the new world";

    fd=open(path,O_WRONLY|O_CREAT);
    if(fd!=-1)
    {
        printf("opened %s.\n",path);
        write(fd,s,strlen(s));
        lseek(fd,40,SEEK_SET);
        write(fd,s,strlen(s));
        lseek(fd,40,SEEK_SET);
        write(fd,s,strlen(s));


        sync();
        if(fsync(fd)==0)
        {
            printf("fsync has done\n");
            printf("Write Done");
        }
        else
        {
            printf("fsync function failed\n");
        }
        close(fd);
    }
    else
    {
        printf("connot open %s.\n",path);
        printf("ERR : %s.\n",strerror(errno));
    }
}
void readFile()
{
    extern int errno;
    char *path="/home/huhaobin/C/auto.txt";
    int fd;
    char s[100];
    int size;

    fd=open(path,O_RDONLY);//O_WRONLY|O_CREAT写
    if(fd!=-1)
    {
        printf("opened %s.\n",path);
        //size = read(fd,s,sizeof(s));
        size = read(fd,s,10);
        printf("%d : ",size);
        printf("%s\n",s);

        lseek(fd,50,SEEK_SET);
        size = read(fd,s,10);
        printf("%d : ",size);
        printf("%s\n",s);
        lseek(fd,0,SEEK_SET);
        size = read(fd,s,3);
        printf("%d : ",size);
        printf("%s\n",s);

        printf("Read Done");
        close(fd);
    }
    else
    {
        printf("connot open %s.\n",path);
        printf("ERR : %s.\n",strerror(errno));
    }
}
