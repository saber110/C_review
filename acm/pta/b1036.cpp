#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int num , row, column;
  char ch;
  cin >> num >> ch;
  column = num;
  if(num % 2 == 0)
    row = num / 2;
  else
    row = (num + 1)/2;

  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      if(j == 0 || j == column - 1){
        cout << ch;
      }
      else{
        if(i == 0|| i == row - 1){
          cout << ch;
        }
        else{
          cout << " ";
        }
      }
    }
    cout << endl;
  }
  return 0;
}
