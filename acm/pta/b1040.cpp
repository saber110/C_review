#include <iostream>
#include <string>
using namespace std;
#define MAX 100 * 100 * 11
#define MOD 1000000007
int main(int argc, char const *argv[]) {
  string s;
  int result = 0, leftNumP[MAX], rightNumT[MAX];
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if(i > 0)
      leftNumP[i] = leftNumP[i - 1];
    if(s[i] == 'P')
      leftNumP[i] ++;
  }

  for(int i = s.length() - 1; i > 0; i --) {
    if(i < s.length() - 1)
      rightNumT[i] = rightNumT[i + 1];
    if(s[i] == 'T')
      rightNumT[i] ++;

    if(s[i] == 'A'){
      result = (result + leftNumP[i] * rightNumT[i]) % MOD;
    }
  }
  cout << result << endl;
  // for (int i = 1; i < s.length() - 1; i++) {
  //   if(leftNumP[i] > 0){
  //     cout <<
  //   }
  // }
  return 0;
}
