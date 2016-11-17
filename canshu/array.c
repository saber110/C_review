#include<stdio.h>
int main(int argc, char const *argv[]) {
  float average(float array[],int n);   //函数声明
  float score1[5] = {98.5,97,91,60,55.5};
  float score2[10] = {67.5,89.5,99,69.5,77,89.5,76.5,54,60,99.5};
  printf("%d\n",(int)(sizeof(score1)/sizeof(float)));
  printf("%d\n",(int)(sizeof(score2)/sizeof(float)));
  printf("class A %6.2f\n", average(score1,(int)(sizeof(score1)/sizeof(float))));
  printf("class B %6.2f\n", average(score2,(int)(sizeof(score2)/sizeof(float))));
  return 0;
}

float average(float array[],int n)
{
  int i;
  float average,sum = array[0];
  for(i=1;i<n;i++)
  {
    sum += array[i];
  }
  average = sum/n;
  return average;
}
