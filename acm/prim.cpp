
//  百度百科版本，正确性未知

#define MAXN 1000
#define INF  1<<30
int closest[MAXN],lowcost[MAXN],m;//m为节点的个数
int G[MAXN][MAXN];//邻接矩阵
int prim()
{
  for(int i=0;i<m;i++)
  {
    lowcost[i]=INF;
    closest[i]=0;
  }

  closest[0]=-1;//加入第一个点，-1表示该点在集合U中，否则在集合V中
  int num=0,ans=0,e=0;//e为最新加入集合的点
  while(num<m-1)//加入m-1条边
  {
    int micost=INF,miedge=-1;
    for(int i=0;i<m;i++)
      if(closest[i]!=-1)
      {
        int temp=G[e][i];
        if(temp<lowcost[i])
        {
          lowcost[i]=temp;
          closest[i]=e;
        }
        if(lowcost[i]<micost)
          micost=lowcost[miedge=i];
      }
    ans+=micost;
    closest[e=miedge]=-1;
    num++;
  }
  return ans;
}
