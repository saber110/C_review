
#include <stdio.h>
#include <stdlib.h>
int Tree[100]; //用来保存每个节点的最上层的父亲节点，起始的根节点的父亲节点为-1
int findRoot(int x){
    if(Tree[x]==-1) return x; //说明该点的父亲节点是自己，相当于是根节点
    else{
        int tmp=findRoot(Tree[x]);//递归寻找最早的父亲节点
        Tree[x]=tmp;
        return tmp;
    }
}
struct Edge{
    int a;
    int b;
    int cost;
}edge[6000];
typedef struct Edge Edge;
int cmp(const void *x,const void *y){
    return (*(Edge*)x).cost-(*(Edge*)y).cost; //这里用<会有问题
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF && n!=0){
        for(int i=1;i<=n*(n-1)/2;i++){
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
        }
        qsort(edge+1,n*(n-1)/2,sizeof(Edge),cmp);//将路径按距离排序 每次优先取最短的路径
        for(int i=1;i<=n;i++){
            Tree[i]=-1;
        }
        int ans=0;
        for(int i=1;i<=n*(n-1)/2;i++){
            int a=findRoot(edge[i].a);
            int b=findRoot(edge[i].b);
            if(a!=b){ //如果该边的两个端点的根节点相同，说明形成了环，那么这条边舍弃
                Tree[a]=b;
                ans+=edge[i].cost;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
