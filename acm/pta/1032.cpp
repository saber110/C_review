#include <iostream>
using namespace std;
#define MAX 1000
typedef struct {
  int id;  // 学校编号
  int score;// 比赛成绩
} player;
int main(int argc, char const *argv[]) {
  player sample[MAX];
  int num ,max = 0, maxid = 0;
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> sample[i].id >> sample[i].score;
    for(int j = 0; j < i; j++){
      if(sample[j].id == sample[i].id){
        sample[j].score += sample[i].score;
        sample[i].id = 0;
        if(max < sample[j].score){
          max = sample[j].score;
          maxid = sample[j].id;
        }
      }
    }
  }
  // cout << "\ti:\t" <<  "id\t" << "score\tmax" << endl;
  //
  // for(int i = 0; i < num; i++){
  //   cout << "i:\t" << i << "\t" << sample[i].id  << "\t" << sample[i].score << "\t" << max << endl;
  // }
  cout <<maxid << " " << max << endl;
  return 0;
}
