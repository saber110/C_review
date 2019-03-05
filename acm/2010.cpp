#include <iostream>
using namespace std;
#define N 10
int _b[N] = {0};
int _a[N] = {0};
bool BiaoShi(unsigned int a, unsigned int b);
bool Zhengchu(unsigned int a, unsigned int b);
int XinYunShu(unsigned int a){
  int count = 0;
  for(unsigned int j = 1; j < a; j++){
    if(Zhengchu(a,j)){          // 便历求因数
      // cout << a << " 的因数 " << j << endl;
      if(BiaoShi(a, j))
        count ++;
    }
  }
  return count +1;
}

// 可以整除的时候返回true
bool Zhengchu(unsigned int a, unsigned int b){
  if(a%b == 0)
    return true;
  return false;
}

bool BiaoShi(unsigned int a, unsigned int b){
  int i=0, j=0;
  // 找到b的各个十进制表示
  for(b; ; ){
    _b[i++] = b - (int)(b/10)*10;
    if(b < 10){
      break;
    }
    b/=10;
  }
  // for(int l = 0; l < i; l++)
  //   cout << b <<"的"<<l<<"位数字" << _b[l] << '\t';
  // cout << endl;
  // if(a < 10)
  // {
  //   _a[j++] = a;
  //   cout << a <<"a的1位数字" << _a[j];
  //   for(int m = 0; m < i; m++){
  //     if(_a[j] == _b[m])
  //       return true;
  //   }
  // }
  // else{
    for(a;;){
      _a[j] = a - (int)(a/10)*10;
      // cout << a <<"a的"<<j<<"位数字" << _a[j] << '\t';
      for(int m = 0; m < i; m++){
        // cout << b <<"b的"<<m<<"位数字" << _b[m] << endl;
        if(_a[j] == _b[m]){
          // cout << "a的第" << j << "位和b的第" << m << "位的值都是" << _a[j] << endl;
          return true;
        }
      }
      if(a < 10)
        break;
      a = a / 10;
      j ++;
    }
  // }
  return false;
}

int main(){
  unsigned int T, a;
  cin >> T;
  if(T <= 0 || T >= 1000)
    return -1;
  for(int i=0; i < T ; i++){
    cin >> a;
    cout << "Case #" << i + 1 << ": "<< XinYunShu(a) << endl;
  }
  return 0;
}
