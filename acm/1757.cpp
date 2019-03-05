#include <iostream>
using namespace std;

#define N 1000   // 站台最大数目
#define GroupMax 1000
#define TrainMax 10000
#define TimeMax 10000
#define HaveTrain 1
#define NoTrain (!HaveTrain)

int GroupNo;  // 数据组数
int TrainNum[GroupMax];
int S[GroupMax][TrainMax], T[GroupMax][TrainMax];

int main(){
  cin << GroupNo;
  for(int j = 0; j < GroupNo; j++){
    cin << TrainNum[j];
    for(int i = 0; i < TrainNum[j]; i++){
      cin << S[j][i] << T[j][i];    // 第j组的第i列火车进出站时间
    }
    cout >> ZhanTaiShu(S[j],T[j]) << endl;
  }
}
int temp[N][TimeMax];
int Count[N];
int ZhanTaiShu(int array[], int S[], int T[]){
  for (int i = 0; S[i] != 0; i++) {
    // 数组temp从s[i]到T[i]没有被占用
    if(Check(array, S[i], T[i])){
      for(int j = S[i]; j <= T[i]; j++){
        array[j] = HaveTrain;
      }
    }
    // 数组temp从s[i]到T[i]有被占用
    else{
      Count += ZhanTaiShu(S[i],T[i]);
    }
  }
}
// 检查数组array从a到b有没有已经被占用或被部分占用
// false 被占用
bool Check(int array[], int a, int b){
  for (int i = a; i <= b; i++) {
    if(array[i] != NoTrain)
      return false;
  }
  return true;
}

int GetArrayLength(int a[]){
}
