#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define MAXPEOPLENUM 1000
#define MAXQUEUENUM 100

int main(int argc, char const *argv[]) {
  int peopleNum, height[MAXPEOPLENUM];
  stack<int> queue[MAXQUEUENUM];
  while(cin >> peopleNum) {
    int queueNum = 0;
    for(int i = 0; i < peopleNum; i++) {
      cin >> height[i];
    }

    queue[queueNum ++].push(height[0]);
    for(int i = 1; i < peopleNum; i++){
      bool flag = false; // 标志是否已经有可以排入的队列
      for(int j = queueNum - 1; j >= 0 ; j--){
        if(height[i] < queue[j].top()){
          queue[j].push(height[i]);
          flag = true;
          break;
        }
      }
      if(!flag){
        queue[queueNum ++].push(height[i]);
      }
    }
    cout << queueNum << endl;
  }
  return 0;
}
