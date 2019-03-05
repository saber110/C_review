---
title: 复试
categories:
  - 考研
date: 2019-03-01
tags: oj
---
1. sort
<algorithm>
bool ZuSort(testee t1, testee t2) {
  if(t1.score == t2.score) return t1.id < t2.id;
  return t1.score > t2.score;
}
sort(result, result + resultPos, ZuSort); // result[MAX]

2. 时间、日期等周期性数据应该从最小位自加，逐步控制更高一层的周期
3. 空间换取时间：(散列)

  - 查找集合N 中的元素在集合M{2,6,7}中是否出现以及出现的次数

      可以用bool M[MAX], M[2] = true; M[6] = true; M[7] = true;

      求出现的次数时，可以用int M[MAX], M[2] ++; M[6] ++; M[7] ++;

4. 老哥，一定要记得多组数组共享变量的清零

5. 利用printf("%.2f\n" ,ans);格式化输出保留小数点两位

6. 所有单调性函数求解问题都可以用二分法
