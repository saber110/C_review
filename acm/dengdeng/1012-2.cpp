#include <iostream>
#define MAXPEOPLENUM 10000
#define MAXQUEUENUM MAXPEOPLENUM

using namespace std;

int main() {
  int peopleNum;
  while(cin >> peopleNum) {
    // cout << "people:\t" << peopleNum;
    if(0 < peopleNum && peopleNum <= MAXPEOPLENUM) {
      int queue[MAXQUEUENUM];
      int queueNum = 0, height[MAXPEOPLENUM];
      for(int i = 0; i < peopleNum; i++) {
        cin >> height[i];
      }
      // for (int i = 0; i < peopleNum; i++) {
      //   cout << height[i] << "\t";
      // }

      queue[queueNum ++] = height[0];
      for(int i = 1; i < peopleNum; i++){
        bool flag = false; // 标志是否已经有可以排入的队列
        for(int j = 0; j <= queueNum - 1 ; j++){
          if(height[i] <= queue[j]){  //和每个队列的最后一个元素做比较
            queue[j] = height[i];
            flag = true;
            break;
          }
        }
        if(!flag){
          queue[queueNum ++] = height[i];
          // cout << "front:\t" << height[i] << endl;
        }
      }
      cout << queueNum << endl;
    }

  }
  return 0;
}
