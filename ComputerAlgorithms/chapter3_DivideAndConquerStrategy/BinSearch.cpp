#include <iostream>
using namespace std;

/**
  * @OUTPUT : 若存在x==a[j],返回j。否则返回0
  */
template <class Type>
int BinSearch(Type a[],int i, int l, Type x)
// a[i:l] 已经按降序排好，1 <= i <= l，判断x是否存在
{
  if(i == l)
  {
    if(x == a[i]) return i;
    else return 0;
  }
  else
  {
    int mid = (i + l)/2;
    if(x == a[mid]) return mid;
    else if(x > a[mid]) BinSearch(a, mid +1, l ,x);
    else BinSearch(a, i, mid -1 ,x);
  }
}

// 循环的过程中只做了一次比较
template <class Type>
int BinSearch1(Type a[],int n, Type x)
// a[i:l] 已经按降序排好，1 <= i <= l，判断x是否存在
{
  int low = 1, high = n + 1;
  while (low < (high - 1))
  {
    int mid = (low + high)/2;
    if(x < a[mid]) high = mid;
    else low = mid;
  }
  if(x == a[low]) return low;
  else return 0;
}
