#include <iostream>
using namespace std;
#define TeacherNumMax 100
#define Impossible -1
const int MoneyKind[] = {100, 50, 10, 5, 2, 1};
int CouQian(float wage);
int OneGrope(int TeacherNum);

int main(int argc, char const *argv[]) {
  int TeacherNum;
  while(cin >> TeacherNum){
    // cout << "一组数据开始\n";
    int result = OneGrope(TeacherNum);
    if(result != Impossible){
      cout << result << endl;
    }
    else{
      cout << "Impossible" << endl;
    }
  }

  return 0;
}

int OneGrope(int TeacherNum){
  float wage[TeacherNumMax] = {0.0};
  int count = 0, temp = 0;
  for(int i = 0; i < TeacherNum; i++){
    cin >> wage[i];
    temp = CouQian(wage[i]);
    if(temp == Impossible){
      // cout << "分组程序正常返回\n";
      return Impossible;
    }
    else{
      // cout << "temp " << temp << endl;
      count += temp;
    }
  }
  return count;
}

int CouQian(float wage){
  int count = 0;
  // cout << "对" << wage << "凑钱" << count << endl;
  for(int i = 0; ;){
    wage = wage - MoneyKind[i];
    // cout << "wage\t" << "MoneyKind" << endl << wage << "\t" << MoneyKind[i]<<endl;
    // cout << "sizeof(MoneyKind)" << sizeof(MoneyKind)/sizeof(MoneyKind[0]) << endl;
    if(i >= sizeof(MoneyKind)/sizeof(MoneyKind[0])){
      // cout << "凑钱程序正常返回\n";
      return Impossible;
    }
    if(wage == 0){
      // cout << "=0" << endl;
      return ++count;
    }
    else if(wage < 0){
      // cout << "<0" << endl;
      wage = wage + MoneyKind[i];
      i ++;
    }
    else{
      // cout << ">0" << endl;
      count ++;
    }
  }
  // return count;
}
