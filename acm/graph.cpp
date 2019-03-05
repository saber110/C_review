#include <iostream>
using namespace std;

#define MAX_VERTEX_NUM 20
#define INF 0x7fffffff
#define U 0
/*
1 2 10
1 6 11
2 3 18
2 7 16
2 9 12
3 4 22
3 9 8
4 5 20
4 8 16
4 9 21
5 6 26
5 8 7
6 7 17
7 8 19
https://blog.csdn.net/jnu_simba/article/details/8869876
*/
int vertexnum; // 顶点数目
int wight[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵存储权值
int vertex[MAX_VERTEX_NUM]; // 顶点的集合
int adjvex[MAX_VERTEX_NUM];/* 保存相关顶点下标 */
    // 下标到值的对应为一条边
int lowcost[MAX_VERTEX_NUM];/* 保存相关顶点间边的权值 */
    // lowcost为0的顶点是已经加入最小生成树的集合

bool CreateGraph(){
  int vertex1, vertex2, w;
  cout << "请输入顶点数" << endl;
  cin >> vertexnum;
  for(int i = 0; i < MAX_VERTEX_NUM; i++){
    wight[i][i] = 0;
    for(int j = 0; j < MAX_VERTEX_NUM; j++){
      wight[i][j] = INF;
    }
  }
  cout << "请输入顶点1 顶点2 权值" << endl;
  while(cin >> vertex1 >> vertex2 >> w){
    wight[--vertex1][--vertex2] = w;      // [0][i] [j][0]存储元素
    wight[vertex2][vertex1] = w;
  }

  return true;
}
// 从v0开始生成最小生成树
// 最小生成树的结果与开始的结点无关
// V 为全部顶点的集合
/**
* U = {U0}, TE = {}
* 寻找V-U中的v，使v到U中的距离最小，<u,v>并入TE
* v并入U
* 循环前两步，直到U包含所有顶点
*/
bool prim(int Graph[MAX_VERTEX_NUM][MAX_VERTEX_NUM]){
  lowcost[0] = U;
  adjvex[0] = 0;/* 初始化第一个顶点下标为0 */
  // 计算与第一个顶点相连的最小边
  // 构建循环环境
  for(int i = 1; i < vertexnum; i++){
    lowcost[i] = Graph[0][i]; /* 将v0顶点与之有边的权值存入数组 */
    adjvex[i] = 0; /* 初始化都为v0的下标 */
  }

  for(int i = 1; i < vertexnum; i++){
    int j = 1, k = 0, min = INF;

    //V-U 中寻找下一条最小边
    // 第一次循环找出距离v0最近的顶点k
    while (j < vertexnum) {
      if(lowcost[j] != U && lowcost[j] < min){
        min = lowcost[j];
        k = j;
      }
      j ++;
    }

    cout << "(" << adjvex[k] << ", " << k << ")" << "  "; /* 打印当前顶点边中权值最小的边 */
    // 下一条最小边的顶点并入U
    lowcost[k] = U;

    for(j = 1; j < vertexnum; j++){
      /* 如果下标为k顶点各边权值小于此前这些顶点未被加入生成树权值 */
      if (lowcost[j] != U && Graph[k][j] < lowcost[j]){  // 新集合里面代价最小的更新到lowcost
        lowcost[j] = Graph[k][j]; /* 将较小的权值存入lowcost相应位置 */
        adjvex[j] = k; /* 将下标为k的顶点存入adjvex */
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  CreateGraph();
  prim(wight);
  return 0;
}
