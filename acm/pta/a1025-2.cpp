#include <iostream>
#include <algorithm>
#include <string>
#define MAXL 110
#define MAXT 310
#define MAXTESTEES MAXL * MAXT
using namespace std;
typedef struct {
  string id;
  int frank;
  int location;
  int lrank;
  int score;
  int num; // 本组总共的测试数
} testee;
bool ZuSort(testee t1, testee t2) {
  if(t1.score == t2.score) return t1.id < t2.id;
  return t1.score > t2.score;
}
int main(int argc, char const *argv[]) {
  testee sample[MAXL][MAXT];
  testee result[MAXTESTEES];
  int resultPos = 0;
  int zushu, num;
  cin >> zushu;
  for(int j = 0; j < zushu; j++){
    cin >> num;
    for(int i = 0; i < num; i ++){
      cin >> sample[j][i].id >> sample[j][i].score;
      sample[j][i].num = num;
      sample[j][i].location = j + 1;
    }

  }
  for(int j = 0; j < zushu; j++)
    sort(sample[j], sample[j] + sample[j][0].num, ZuSort);
  // sort(sample[1], sample[1] + sample[1][0].num, ZuSort);

  for(int j = 0; j < zushu; j++){
    sample[j][0].lrank = 1;
    result[resultPos ++] = sample[j][0];
    // 注意边界为1, 防止i-1溢出
    for (int i = 1; i < sample[j][0].num ; i++) {
      if(sample[j][i].score == sample[j][i-1].score)
        sample[j][i].lrank = sample[j][i-1].lrank;
      else
        sample[j][i].lrank = i + 1;

      result[resultPos ++] = sample[j][i];
    }
  }

  sort(result, result + resultPos, ZuSort);
  result[0].frank = 1;
  for(int i = 1; i < resultPos; i++) {
    if(result[i].score == result[i-1].score)
      result[i].frank = result[i-1].frank;
    else
      result[i].frank = i + 1;
  }

  // cout << endl << "print:" << endl;
  // resultPos = 0;
  // for(int j = 0; j < zushu; j++)
  cout << resultPos << endl;
  for (int i = 0; i < resultPos ; i++) {
    cout << result[i].id << " " << result[i].frank << " " << result[i].location << " " << result[i].lrank << endl;
  }
  return 0;
}
