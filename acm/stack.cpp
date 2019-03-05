#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;
// template < typename T, typename Container=deque > class stack;

stack<int>  intDequeStack;
stack<int, vector<int>> intVectorStack;
stack<int, list<int>> intListStack;

int main(int argc, char const *argv[]) {
  intDequeStack.push(21);
  intDequeStack.push(21);
  cout << intDequeStack.size() << endl;
  while(intDequeStack.empty()){
    cout << intDequeStack.top() << endl;
    intDequeStack.pop();
  }

  return 0;
}
