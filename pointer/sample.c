#include<stdio.h>
/**
*指针的初始化以及赋值
*/
// int main(int argc, char const *argv[]) {
//   int a = 100,b =10;
//   int *pointer_a ,*pointer_b;
//   pointer_a = &a;
//   pointer_b = &b;
//   // *pointer_a = &a;
//   // *pointer_b = &b;
//   printf("pointer_a %d\n", *pointer_a);
//   printf("pointer_b %d\n", *pointer_b);
//   *pointer_b = a;
//   printf("pointer_b %d\n", *pointer_b);
//   printf("b %d\n", b);
//   return 0;
// }

/**
*指针与数组的相互指代
*可以用指针读入数组元素 p=a,scanf('%d',p)
*/
// int main(int argc, char const *argv[]) {
//   int a[10];
//   int * p,i;
//   printf("please input ten numbers");
//   for(i=0;i<10;i++)
//     scanf("%d",&a[i]);
//   for(p=a;p<(a+10);p++)   //地址自加
//     printf("%d\n",*p );   //读出地址所对应的内容
//   printf("\n");
//   return 0;
// }


/**
*如果用指针变量作为实参，指针变量必须要有具体的值，即必须**指向对应已定义的对象**
*/
// int main(int argc, char const *argv[]) {
//   void inv(int *x,int n);
//   int i,*arr;             //不正确使用arr
//   printf("The original\n");
//   for(i=0;i<10;i++)
//     scanf("%d",arr+i );
//   printf("\n");
//   inv(arr,10);
//   printf("The inverted\n");
//   for(i=0;i<10;i++)
//     printf("%d",*(arr+i));
//   printf("\n");
//   return 0;
// }
//
// void inv(int *x,int n)
// {
//   int *p,m,temp,*i,*j;
//   m = (n-1)/2;
//   i = x;
//   j = x+n-1;
//   p = x+m;
//   for(;i<=p;i++,j--)
//   {
//     temp = *i;
//     *i = *j;
//     *j = temp;
//   }
//   return;
// }


/*
*指针形参直接改变实参的值
*从大到小排序
*/
// int main(int argc, char const *argv[]) {
//   void sort(int x[],int n);
//   int i,*p,a[10];
//   p = a;
//   printf("please enter 10 numbers\n");
//   for(i=0;i<10;i++)
//     scanf("%d", p++);
//   p =a;
//   sort(p,10);
//   for(p=a,i=0;i<10;i++)
//   {
//     printf("%d ", *p);
//     p++;
//   }
//   printf("\n");
//   return 0;
// }
//
// void sort(int x[],int n)
// {
//   int i,j,k,t;
//   for(i=0;i<n-1;i++)
//   {
//     k = i;
//     for(j=i+1;j<n;j++)
//     {
//       if(x[j]>x[k])
//         k=j;
//     }
//     if(k!=i)
//     {
//       t=x[i];
//       x[i]=x[k];
//       x[k]=t;
//     }
//   }
// }


/**
*通过指针函数，根据用户不同的需求调用不同的函数
*/
int main(int argc, char const *argv[]) {
  void fun(int x,int y,int(*p)(int,int));
  int max(int,int);
  int min(int,int);
  printf("please chose 1 or 2\n");
  int a=34,b=-21,n;
  scanf("%d",&n);
  switch (n) {
    case 1:fun(a,b,max);break;
    case 2:fun(a,b,min);break;
  }
  return 0;
}

void fun(int x,int y,int(*p)(int,int))
{
  int result = (*p)(x,y);
  printf("%d\n", result);
}
int max(int x,int y)
{
  int z;
  if(x>y) z=x;
  else z=y;
  printf("max = \n");
  return z;
}
int min(int x,int y)
{
  int z;
  if(x<y) z=x;
  else z=y;
  printf("min = \n");
  return z;
}
