#include <iostream>
using namespace std;
#define MAXN 1100
#define MAXZ 110

int hashTable[MAXZ][MAXN] = {0};
bool hashAll[MAXN] = {false}; // 存储全部元素
int main(int argc, char const *argv[]) {
  int num[2][MAXN] = {0} , samples, temp, numn, max_ys = 0, max_zu = 0, num_ys;
  cin >> samples;
  for(int i = 0; i < samples; i++){
    for(int l = 0; l < MAXN; l ++ ){
      hashAll[l] = false;
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
      hashAll[temp] = true;
      if(max_ys < temp) max_ys = temp;
    }
    for(int j = 0; j < numn; j++){
      cin >> temp;
      num[1][j] = temp; // 暂存分组
      if(max_zu < temp) max_zu = temp;
    }

    for(int i = 0; i < numn; i ++){
      hashTable[num[1][i]][num[0][i]] ++;   // 对该组的第n个元素计数
    }

    for(int j = 1; j <= max_ys; j ++) {
      if(hashAll[j]) num_ys ++;
    }

    for(int i = 1; i <= max_zu; i++){
      cout << i << "={" ;
      for(int j = 1; j <= max_ys; j ++) {
        if(hashAll[j]){
          cout << j << "=" << hashTable[i][j];
          if(j < num_ys) cout << ",";
        }
      }
      cout << "}" << endl;
    }
  }
  //
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
