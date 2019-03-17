
#include <stdio.h>
#include <stdlib.h>
int Tree[100]; //��������ÿ���ڵ�����ϲ�ĸ��׽ڵ㣬��ʼ�ĸ��ڵ�ĸ��׽ڵ�Ϊ-1
int findRoot(int x){
    if(Tree[x]==-1) return x; //˵���õ�ĸ��׽ڵ����Լ����൱���Ǹ��ڵ�
    else{
        int tmp=findRoot(Tree[x]);//�ݹ�Ѱ������ĸ��׽ڵ�
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
    return (*(Edge*)x).cost-(*(Edge*)y).cost; //������<��������
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF && n!=0){
        for(int i=1;i<=n*(n-1)/2;i++){
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
        }
        qsort(edge+1,n*(n-1)/2,sizeof(Edge),cmp);//��·������������ ÿ������ȡ��̵�·��
        for(int i=1;i<=n;i++){
            Tree[i]=-1;
        }
        int ans=0;
        for(int i=1;i<=n*(n-1)/2;i++){
            int a=findRoot(edge[i].a);
            int b=findRoot(edge[i].b);
            if(a!=b){ //����ñߵ������˵�ĸ��ڵ���ͬ��˵���γ��˻�����ô����������
                Tree[a]=b;
                ans+=edge[i].cost;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
