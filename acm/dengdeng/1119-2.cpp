#include<iostream>
#include<stdio.h>
#include <cstring>
using namespace std;
#define M 104
#define INF 1000000000
int n,dp[M][M],sum[M],stone[M];
inline int min(int a,int b)
{
    return a>b?b:a;
}
int main()
{
    //freopen("b.txt","r",stdin);
    int i,j,k,t,len;
    while(scanf("%d",&n)==1)
    {
        memset(sum,0,sizeof(sum));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&stone[i]);
            sum[i]=sum[i-1]+stone[i];
        }
        memset(dp,0,sizeof(dp));
        for(len=2;len<=n;len++)//归并的石子长度
        {
            for(i=1;i<=n-len+1;i++)//i为起点，j为终点
            {
                j=i+len-1;
                dp[i][j]=INF;
                for(k=i;k<=j;k++)
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
