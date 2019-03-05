#include <iostream>
#include <list>
using namespace std;
void printList(list<char> test){
  for(auto it = test.begin(); it != test.end(); it ++){
    cout << *it << '\t';
  }
  cout << endl;
  // cout << test.size() <<"\t" << test.front() << "\t" << test.back() << endl;
}
int main(int argc, char const *argv[]) {
  list<char> test = {'a','c','b','d'};
  int i = 0;
  test.push_front('f');
  test.push_back('r');
  while (!test.empty()) {
    printList(test);

    test.pop_front();
  }
  test = {'a','c','b','d'};
  while (!test.empty()) {
    if(i < 7)
    {
      test.push_front('f');
      test.push_back('r');
    }
    test.sort();
    // cout << test << endl;
    test.pop_back();
    printList(test);
    i++;
  }
  test = {'a','c','b','d'};
  // for(auto it = test.begin(); it != test.end(); it ++){
  //   cout << *it << '\t';
  // }
  test.insert(test.end(),'p');
  printList(test);
  test.clear();
  printList(test);
  return 0;
}
