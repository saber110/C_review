#include <iostream>
using namespace std;
int a[10];
template <class Type>
void MaxMin(int i, int j, Type &max, Type &min)
// a[1:n] 全局数组
// 1<=i<=j<=n, 寻找i:j的最值
{
  if(i == j) max = min = a[i];
  else if(i == j-1)
  {
    if(a[i] < a[j]) {max = a[j]; min = a[i];}
    else { min = a[j]; max = a[i];}
  }
  else
  {
    int mid = (i + j)/2; Type max1, min1;
    MaxMin(i, mid, max, min);
    MaxMin(mid, j, max1, min1);

    // 合并子问题的解
    if(max < max1) max = max1;
    if(min < min1) min = min1;
  }
}
