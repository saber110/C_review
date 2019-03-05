#include <iostream>
using namespace std;
#define MaxW 10
#define MaxH 10
#define MaxVertex (MaxW * MaxH)
#define VertexType char
#define INF 0x7fffffff

#define KD 0  // 空地
#define XJ INF  // 陷阱
#define XS 2
#define XX 3
#define XZ 4
#define XY 5
// 原出发点也算一个方格，如果可以挪动的话
// 根据提示，允许有不被访问的点 哈哈哈哈哈哈　
bool visited[MaxVertex];
typedef struct {
  int adj;
} AdjMatrix[MaxW][MaxH];
typedef struct {
  VertexType vexs[MaxVertex];
  AdjMatrix arcs;
  int vexnum, arcnum, entry;
}MGraph;
// 获取起始点的下标
// int GetEntry(MGraph G) {
//
// }
int FirstAdjVex(MGraph G, int v) {
  for (int i = 0; i < G.vexnum; i++) {
    if(!G.arcs[v][i].adj)
      return i;
  }
  return -1;
}
int NextAdjVex(MGraph G, int v, int w) {
  for (int i = w; i < G.vexnum; i++) {
    if(!G.arcs[v][i].adj)
      return i;
  }
  return -1;
}
void DFS(MGraph G, int v) {
  visited[v] = true;
  for(int w = FirstAdjVex(G,v); w >= 0; w = NextAdjVex(G,v,w))
    if(!visited[w]) DFS(G, w);
}
void DFST(MGraph G) {
  for (int i = 0; i < G.vexnum; i++) visited[i] = false;
  for (int i = 0; i < G.vexnum; i++)
    if(!visited[i]) DFS(G, i);
}
int main(int argc, char const *argv[]) {
  MGraph G;
  int w, h; //迷宫的行和列
  char temp; // 缓存输入的字符
  int i, j;
  while (cin >> w >> h) {
    // G.vexnum = w * h ;
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++) {
        cin >> temp;
        switch (temp) {
          case '.': G.arcs[i][j].adj = KD; break;
          case '*': G.arcs[i][j].adj = XJ; break;
          case 'U': {G.arcs[i][j].adj = XS; G.entry = i;} break;
          case 'D': {G.arcs[i][j].adj = XX; G.entry = i;} break;
          case 'L': {G.arcs[i][j].adj = XZ; G.entry = i;} break;
          case 'R': {G.arcs[i][j].adj = XY; G.entry = i;} break;
        }
      }
    }
    // 补足图结构
    temp = w - h;
    if(temp < 0){
      G.vexnum = h;
      for (int i = 0; i < h; i++) {
        for (int j = w; j < h; j++) {
          G.arcs[j][i].adj = INF;
        }
      }
    }
    else if(temp > 0){
      G.vexnum = w;
      for (int i = 0; i < w; i++) {
        for (int j = h; j < w; j++) {
          G.arcs[j][i].adj = INF;
        }
      }
    }
    else
      G.vexnum = w;

    for (int i = 0; i < G.vexnum; i++) {
      for (int j = 0; j < G.vexnum; j++) {
        cout << G.arcs[i][j].adj << '\t';
      }
      cout <<  endl;
    }
    cout << "entry:\t" << G.entry << endl;
  }
  return 0;
}
