#include <iostream>
using namespace std;
#define MAX 10
#define NUMMAX 60
int main(int argc, char const *argv[]) {
  int hashTable[MAX], min = MAX;
  int result[NUMMAX] = {0}, pos = 0;
  for (int i = 0; i < MAX; i++) {
    cin >> hashTable[i];
    if(i > 0) {
      if(min > i && hashTable[i] > 0)
        min = i;
    }
  }
  // 输出最小的非零元
  hashTable[min] --;
  result[pos ++] = min;
  for(int i = 0; i < MAX; i ++) {
    while(hashTable[i]){
      result[pos ++] = i;
      hashTable[i] --;
    }
  }

  for (int i = 0; i < pos; i++) {
    cout << result[i] ;
  }
  cout << endl;
  // for (int i = 0; i < MAX; i++) {
  //   cout << i << "\t"  <<  hashTable[i] << endl;
  // }
  // cout << "min\t"  <<  min << endl;

  return 0;
}
