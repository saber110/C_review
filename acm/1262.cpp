#include <iostream>
#include <string>
using namespace std;
#define MinLength 8
#define MinGroup 3
const string SpecialCode = "~!@#$%^";
bool OneGroup(string psd);

int main(int argc, char const *argv[]) {
  string Password;
  while (cin >> Password) {
    if(OneGroup(Password)){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
  return 0;
}

bool OneGroup(string psd){
  int Count[4] = {0};
  int Length = psd.length();
  if(Length < MinLength){
    return false;
  }
  for(int i = 0; i < Length; i++){
    if(Count[0] + Count[1] + Count[2] + Count[3] > 2){
      return true;
    }
    if(psd.at(i) >= 'a' && psd.at(i) <= 'z'){
      Count[0] = 1;
    }
    else if(psd.at(i) >= 'A' && psd.at(i) <= 'Z'){
      Count[1] = 1;
    }
    else if(psd.at(i) >= '0' && psd.at(i) <= '9'){
      Count[2] = 1;
    }
    else{
      for(int j = 0; j< SpecialCode.length(); j++){
        if(psd.at(i) == SpecialCode.at(j)){
          Count[3] = 1;
          break;
        }
      }
    }
  }
  return false;

}
