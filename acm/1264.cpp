#include <iostream>
#include <string>
using namespace std;
bool HuiWenChuan(string s);
string SourceString;
int main(int argc, char const *argv[]) {
  int count = 1;
  while (cin >> SourceString) {
    if(HuiWenChuan(SourceString)){
      cout << "case" << count << ": " << "yes" << endl;
    }
    else{
      cout << "case" << count << ": " << "no" << endl;
    }
    count ++;
  }
  return 0;
}

// 是回文串就返回true
bool HuiWenChuan(string s){
  int length = s.length();
  int pos = length / 2;
  while(pos > 0){
    if(SourceString.at(pos - 1) != SourceString.at(length - pos)){
      return false;
    }
    pos --;
  }
  return true;
}
