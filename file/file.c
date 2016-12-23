
#include <stdio.h>
void store();
void main(int argc, char const *argv[]) {
  int a=0;
  char b[10];
  store(a,b);
}
void store(int a ,char * b) {
  // fflush();
  FILE * fp;
  int c;
  char str[10];
  str[0] = 'i';
  fp = fopen("learn.txt","r");
  if(fp==NULL)
    return;
  else
  {
    // fprintf(fp, "%s\n", "This is a test");
    // fscanf(fp,"%s",str);
    while(c=fgetc(fp)==EOF)
    {printf("test");break;}
      printf("%c", c);
  }
  fclose(fp);
}
/*
void main1()
{
  int  fd;
  if((fd=creat("file.hole",FILE_MODE))<0)
    printf("creat error");
  if(write(fd,buff1,10) != 10)
    printf("buff1  write error");
  if(lseek(fd,16384,SEEK_SET) == -1)
    printf("seek error");
  if(write(fd,buff2,10)!=10)
    printf("buff2 write error");
  // fsync(fd)
  // close(fd);
  printf("%d\n", fd);
  // printf("%d\n", close(fd));
}
*/
