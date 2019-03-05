#include <iostream>
using namespace std;
#define max 100000
int ans[max] = {0};
int cao = 0;
int func(int c, int d){
  // 把C转换成D进制
  int temp = c;
  do{
    temp = c / d;
    // s.append(1,c % d + 48);
    ans[cao ++] = c % d;
    c = temp;
  }while(c != 0);
  return 0;
}
int main(int argc, char const *argv[]) {
  int a, b ,c, d;
  cin >> a >> b >> d;
  c = a + b;
  func(c, d);
  for(int i = cao - 1; i >= 0; i--) cout << ans[i];
  cout << endl;
  return 0;
}
