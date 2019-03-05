#include <iostream>

using namespace std;
int main(int argc, char const *argv[]) {
  int length; // 木棍的长度
  int temp, a = 1, b; // a，b：矩形的长宽
  int count; // 矩形种数
  while (cin >> length) {
    count = 0;
    if(!(length % 2)){
      temp = length / 2;
      b = temp - 1;

      while(a < b){
        a ++;
        b --;
        count ++;
      }
    }
    cout << count << endl;
  }
  return 0;
}
