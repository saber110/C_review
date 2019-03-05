#include <iostream>
using namespace std;
#define MAXN 1100
#define MAXZ 110
#define ZERON MAXN / 2
#define ZEROZ MAXZ / 2

int hashTable[MAXZ][MAXN] = {0};
bool hashAll[MAXN] = {false}; // 存储全部元素
bool hashZu[MAXZ] = {false};
// 将这些hash的负索引右移ZERO
int main(int argc, char const *argv[]) {
  int num[2][MAXN] = {0} , samples, temp, numn, max_ys = 0, max_zu = 0;
  cin >> samples;
  for(int i = 0; i < samples; i++){
    for(int l = 0; l < MAXN; l ++ ){
      hashAll[l] = false;
      hashZu[l] = false;
      num[0][l] = 0;
      num[1][l] = 0;
      for(int a = 0; a < MAXZ; a ++){
        hashTable[a][l] = 0;
      }
    }

    cin >> numn;
    for(int j = 0; j < numn; j++){
      cin >> temp;
      num[0][j] = temp;  // 暂存数
      hashAll[temp + ZERON] = true;
      if(max_ys < temp) max_ys = temp;
    }
    for(int j = 0; j < numn; j++){
      cin >> temp;
      num[1][j] = temp; // 暂存分组
      hashZu[temp + ZEROZ] = true;
      if(max_zu < temp) max_zu = temp;
    }

    for(int i = 0; i < numn; i ++){
      hashTable[num[1][i] + ZEROZ][num[0][i] + ZERON] ++;   // 对该组的第n个元素计数
    }

    for(int i = 0; i <= max_zu + ZEROZ; i++){
      if(hashZu[i]) {
        cout << i - ZEROZ << "={" ;
        for(int j = 0; j <= max_ys + ZERON; j ++) {
          if(hashAll[j]){
            cout << j - ZERON << "=" << hashTable[i][j];
            if(j != max_ys + ZERON) cout << ",";
          }
        }
        cout << "}" << endl;
      }
    }
  }

  // for (int i = 0; i <= max_zu; i++) {
  //   for(int j = 0; j <= max_ys; j ++) {
  //     cout << hashTable[i][j] << "\t";
  //   }
  //   cout << endl;
  //   // cout << hashTable[i].val << "\t" << hashTable[i].zu << endl;
  // }
  //
  // cout << endl;
  // for(int j = 0; j <= max_ys; j ++) {
  //   cout << hashAll[j] << "\t";
  // }
  // cout << endl;

  return 0;
}
