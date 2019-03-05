#include <iostream>
#include <algorithm>
#include <string>
#define MAXL 300
#define MAXT 100
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
  return t1.score > t2.score;
}
int main(int argc, char const *argv[]) {
  testee sample[MAXTESTEES];
  int zushu, num;
  cin >> zushu;
  for(int j = 0; j < zushu; j++) {
    int numold = num;
    cin >> num;
    for(int i = 0; i < num; i ++){
      cin >> sample[i].id >> sample[i].score;
      sample[i].num = num;
    }
  }
  
  sort(sample[0], sample[0] + sample[0][0].num, ZuSort);
  sort(sample[1], sample[1] + sample[1][0].num, ZuSort);


  for(int j = 0; j < zushu; j++){
    sample[j][0].lrank = 1;
    for (int i = 0; i < sample[j][i].num ; i++) {
      if(sample[j][i].score == sample[j][i-1].score)
        sample[j][i].lrank = sample[j][i-1].lrank;
      else
        sample[j][i].lrank = i + 1;
    }
  }

  cout << endl << "print:" << endl;

  for(int j = 0; j < zushu; j++)
    for (int i = 0; i < sample[j][i].num ; i++) {

      cout << sample[j][i].id << " " << sample[j][i].location << " " << sample[j][i].lrank << "\t" <<sample[j][i].score << endl;;
    }
  return 0;
}
