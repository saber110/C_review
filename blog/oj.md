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

5. 最大公约数用辗转相除法
	```
	gcd(a, b) = gcd(b, a%b);
	gcd(a, 0) = a
	```
6. 最小公倍数的计算
	```
	lcm(a, b) = (a/ gcd(a, b)) * b;
	```
7. 分数表示
```
struct franction {
long long up,  down;
}
```
我们约定，若分母(down)小于0,则令分子，分母为本身的相反数
约分即是分子分母同除以他们的最大公约数
若分子为0，则令分母为1
带分数：整数部分是up/down, 分子是abs(up)%down, 分母是down

8. 求素数的方法:
方法一：
	- 如果n对i, (i 属于[2,sqrt(n)]) 有约数（余数为0），则n不是素数
	- 如果n对i, (i 属于[2,sqrt(n)]) 没有约数（余数不为0），则n是素数
方法二：
	- 最小的素数的倍数肯定不是素数
	- 2是素数
	- 循环筛选
9. 求质因子的方法
质因子要么全部在[2,sqrt(n)]， 要么只有一个在[sqrt(n), n]。将前面的小于sqrt(n)的质因子全部除掉，剩下的如果！=1，那就是大于sqrt（n）的唯一的质因子

10. vector是一个边长数组
	set是一个内部自动有序（递增）且不含重复元素的容器
	set只能通过迭代器来访问， set<typename>::iterator it  // 通过* it访问内容

	multiset可以处理元素不唯一的情况
	uordered_set处理只去重但不排序的需求

11. 除了vector和string之外的STL都不支持*(it + i)这种形式，只能通过图iteratorBianli.png形式来访问，
	其他STL的各种操作都要通过迭代器来实现


