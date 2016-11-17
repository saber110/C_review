#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {
  FILE * fp;
  char ch,filename[10];
  printf("请输入文件名\n");
  scanf("%s", filename);
  if((fp = fopen(filename,"w")) == NULL)
  {
    printf("无法打开\n");
    exit(0);
  }
  ch = getchar();
  printf("请输入准备写入文件的内容（以'#'结束）\n");
  ch = getchar();
  while (ch != '#') {
    fputc(ch,fp);
    putchar(ch);
    ch = getchar();
  }
  fclose(fp);
  putchar(10);//换行符
  return 0;
}
