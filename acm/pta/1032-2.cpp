#include <iostream>
using namespace std;
#define MAX 100002
int main(int argc, char const *argv[]) {
  int num,max = -1, sample[MAX] = {0};
  int id, score;
  cin >> num;
  for(int i = 0; i < num; i++){
    cin >> id >> score;
    sample[id] += score;
  }

  for(int i = 1; i <= num; i ++){
    if(max < sample[i]){
      max = sample[i];
      id = i;
    }
  }
  cout << id << " " << max << endl;
  return 0;
}
