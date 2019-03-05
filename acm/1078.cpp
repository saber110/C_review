#include <iostream>
#define M 50
#define MaxM_ 50
#define MaxN 10
using namespace std;
int LCS[M][M], data[MaxN][MaxM_];
int main(){
  int N = 0; //N个整数序列
  int M_ = 0; //每个序列均包含有M个不同的非负整数
  cin >> N >> M_ ;
  for(int i = 0; i < N; i ++){
    for(int j = 0; j < M_; j ++)
      cin >在需要你用这个木棍做一个矩形（但是不能是正方形），矩形的每条边的长度为整数。> data[i][j];
    // cout << i << "\t" << j<< endl;
  }

  // for(int i = 0; i < N; i ++)
  //   for(int j = 0; j < M_; j ++)
  //     cout << data[i][j] << "\t";

  return 0;
}

int CalculateLCS(int  M_){
  LCS[0][0] = 0;
  for(int i = 0; i < M_; i ++)
    for(int j = 0; j < M_; j ++){
      if(i == 0 || j == 0)
        LCS[i][j] = 0;
      else if(data[0][i] == data[1][j])
        LCS[i][j] = LCS[i-1][j-1] + 1;
      else
        LCS[i][j] = (LCS[i][j-1] > LCS[i-1][j] ? LCS[i][j-1]:LCS[i-1][j]);
    }

}
