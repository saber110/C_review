#include <iostream>
using namespace std;
#define MAXN 1100
#define MAXZ 1100

int hashTable[MAXZ][MAXN] = {0};
bool hashAll[MAXN] = {false}; // 存储全部元素
bool hashZu[MAXZ] = {false};
int main(int argc, char const *argv[]) {
  int num[2][MAXN] = {0} , samples, temp, numn, max_ys = 0, max_zu = 0 , num_ys;
  cin >> samples;
  for(int s = 0; s < samples; s++){
    for(int m = 0; m < MAXN; m ++ ){
      hashAll[m] = false;
      hashZu[m] = false;
      num[0][m] = 0;
      num[1][m] = 0;
      for(int a = 0; a < MAXZ; a ++){
        hashTable[a][m] = 0;
     }
   }


    cin >> numn;
    // 变量清零啊老哥
    max_ys = 0;
    max_zu = 0;
    for(int j = 0; j < numn; j++){
      cin >> temp;
      num[0][j] = temp;  // 暂存数
      hashAll[temp] = true;
      if(max_ys < temp) max_ys = temp;
    }
    for(int j = 0; j < numn; j++){
      cin >> temp;
      num[1][j] = temp; // 暂存分组
      hashZu[temp] = true;
      if(max_zu < temp) max_zu = temp;
    }

    for(int i = 0; i < numn; i ++){
      hashTable[num[1][i]][num[0][i]] ++;   // 对该组的第n个元素计数
    }

    for(int i = 0; i <= max_zu; i++){
      if(hashZu[i]) {
        cout << i << "={" ;
        for(int j = 0; j <= max_ys; j ++) {
          if(hashAll[j]){
            cout << j << "=" << hashTable[i][j];
            if(j != max_ys) cout << ",";
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
  // for(int j = 0; j <= max_ys; j ++) {
  //   cout << hashAll[j] << "\t";
  // }
  // cout << endl;

  return 0;
}
