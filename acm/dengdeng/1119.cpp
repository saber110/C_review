#include <iostream>
#define INF 0x7fffffff
#define MAX 1000
using namespace std;
// 寻找sum里面最小的加入即可

int main(int argc, char const *argv[]) {
  int num, result;
  while (cin >> num) {
    int shizi[MAX], sum[MAX];
    for(int i = 0; i < num; i++) {
      cin >> shizi[i];
    }
    result = 0;
    if(num == 1){
      result = shizi[0];
    }
    else{
      while(num > 1){
        int sumMin = INF, iMin;
        for(int i = 0; i < num ; i++){
          if(i == 0){
            sum[i] = shizi[num - 1] + shizi[0];
          }
          else
            sum[i] = shizi[i - 1] + shizi[i];

          if(sumMin >= sum[i]){
            sumMin = sum[i];
            iMin = i;
          }
        }
        // 补充最小值
        // if(sumMin >= sum[num]){
        //   sumMin = sum[num];
        //   iMin = num;
        // }

        cout << "___________________________________________"<< endl;
        for(int i = 0; i < num; i++){
          cout << "shizi1 \t" << shizi[i] << '\t';
        }

        shizi[iMin - 1] = sumMin;

        if(iMin == 0){
          shizi[iMin] = shizi[0] + shizi[num - 1];
        }
        else
          for (int i = iMin; i < num; i++) {
            shizi[i]= shizi[i+1];
          }
        result += sumMin;

        cout << endl;
        for(int i = 0; i < num; i++){
          cout << "sum \t" << sum[i] << '\t';

        }
        cout << sum[num] ;
        cout << endl;

        for(int i = 0; i < num; i++){
          cout << "shizi2 \t" << shizi[i] << '\t';
        }

        cout << endl <<"sumMin: "<<sumMin <<"\tiMin: " << iMin << endl;
        cout << "___________________________________________"<< endl;

        num --;
      }
    }

    cout << result << endl;
  }
  return 0;
}


// int hh(int num, int shizi[]){
//   if(num == 1) return shizi[0];
//   else
// }
