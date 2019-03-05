#include <iostream>
#include <string>
using namespace std;
typedef struct {
  int val;
  int i;
} MAX;
int main(int argc, char const *argv[]) {
  string s;
  MAX m;
  while(cin >> s) {
    int count[1000]={0}; //记录0-9的出现频次
    for (int i = s.length()-1; i >= 0; i--) {
      count[(int)s[i] - 48] ++;
      // cout << (int)s[i] - 48 << "\t";
    }
    m.val = 0;
    for (int i = 0; i < 10; i++) {
      if(m.val < count[i]) {
        m.val = count[i];
        m.i = i;
      }
    }
    cout << m.i << endl;

  }

  return 0;
}
