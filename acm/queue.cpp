#include <queue>
#include <iostream>
#include <list>
using namespace std;

int main(int argc, char const *argv[]) {
  queue<int> intQueueQueue;
  queue<int, list<int>> intListQueue;
  intListQueue.push(2);
  intListQueue.push(4);
  intListQueue.push(3);
  intListQueue.push(1);
  cout << intListQueue.size() << endl;
  cout << "intListQueue.front()\t" << "intListQueue.back()" << endl;
  while(!intListQueue.empty()){
    cout << intListQueue.front() <<"\t" << intListQueue.back() << endl;
    intListQueue.pop();
  }
  return 0;
}
