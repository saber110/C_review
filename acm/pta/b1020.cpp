#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define MAXLEI 1010
#define MAXDEMAND 510

typedef struct {
  double stock;  // 存量
  double priceAll;
  double priceOne;
} mooncakes;
mooncakes mc[MAXLEI];
double result = 0.0;

bool sortMooncakes(mooncakes m1, mooncakes m2) {
  return m1.priceOne > m2.priceOne;
}

float func(double demand, int i) {
  if(demand - mc[i].stock > 0 && i < MAXLEI){
    result += mc[i].priceAll;
    func(demand - mc[i].stock, i + 1);
  }
  else{
    result += demand * mc[i].priceOne;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  int numLei;
  double demand;  // 库存的种类数和需求
  cin >> numLei >> demand;
  for (int i = 0; i < numLei; i++) {
    cin >> mc[i].stock;
  }
  for (int i = 0; i < numLei; i++) {
    cin >> mc[i].priceAll;

      mc[i].priceOne = mc[i].priceAll / mc[i].stock;  // 计算出单价
  }

  sort(mc, mc + numLei, sortMooncakes);
  // double ans;
  // for(int i = 0; i < numLei ; i++){
  //   if(demand - mc[i].stock > 0){
  //     ans += mc[i].priceAll;
  //     demand -= mc[i].stock;
  //   }
  //   else{
  //     ans += demand * mc[i].priceOne;
  //     break;
  //   }
  // }
  printf("%.2f\n", func(demand, 0));
  // printf("%.2f\n", ans);

  // for (int i = 0; i < numLei; i++) {
  //   cout << mc[i].stock << "\t" << mc[i].priceAll << "\t" << mc[i].priceOne << endl;
  // }
  return 0;
}
