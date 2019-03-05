#include <iostream>
using namespace std;
int day31[] = {1,3,5,7,8,10,12};
int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool IsLeapYear(int year) {
  // 若是润年则返回true
  return ((year % 4 == 0) && (year % 100 != 0));
}
int GetYear(int data){
  return data / 10000;
}

int GetMonth(int data) {
  return (data - GetYear(data) * 10000)/100;
}
// 求出中间的月份数
int Months(int month1, int month2) {
  if(month2 > month1)
    return month2 - month1;
  else if(month2 < month1) {
    return 12 - month1 + month2;
  }
  else return 0;
}

int GetDay(int data){
  return (data - GetYear(data) * 10000) - GetMonth(data) * 100;
}
// 31天返回true
bool IsDay31Or30(int month) {
  for(int i = 0; i < sizeof(day31) / sizeof(day31[0]); i++)
    if(i == month) return true;
  return false;
}
int main(int argc, char const *argv[]) {
  int begin, end;
  while (cin >> begin >> end) {
    int result = 1, temp = 0;
    if(begin > end) {
      temp = begin;
      begin = end;
      end = temp;
    }
    int year = GetYear(begin);
    for (; year < GetYear(end); year ++) {
      if(IsLeapYear(year))  result += 366;
      else  result += 365;
    }
    int month = GetMonth(begin);
    for ( int i = 1; i < Months(GetMonth(begin), GetMonth(end)); i ++ ) {
      month = GetMonth(begin) + i;
      if(month > 12)  month = month - 12;
      if(month == 2){
        if(IsLeapYear(GetYear(year)))  result += 29;
        else result += 28;
      }
      else{
        if(IsDay31Or30(month))  result += 31;
        else result += 30;
      }
      // month ++;
    }


    if(GetDay(begin) < GetDay(end)){
      if(month == 2){
        if(IsLeapYear(GetYear(year)))  result += 29;
        else result += 28;
      }
      else{
        result += GetDay(end) - GetDay(begin);
      }
    }
    else if(GetDay(begin) == GetDay(end)){
      result += days[month];
    }
    else{
      result += days[month] - GetDay(begin) + GetDay(end);
      if((IsLeapYear(GetYear(year))) && month == 2) result += 1;
    }
    cout << result << endl;
    cout << GetYear(begin) << "\t" << GetMonth(begin) << "\t" << GetDay(begin) << endl;
    cout << GetYear(end) << "\t" << GetMonth(end) << "\t" << GetDay(end) << endl;
  }
  return 0;
}
