#include <iostream>
using namespace std;

// return true when n is even,else return false
bool Even(int n) {
  if(n % 2 == 0)
    return true;
  return false;
}

int main(int argc, char const *argv[]) {
  int n, count;
  cin >> n;
  count = 0;
  while (n != 1) {
    if(n % 2 == 0){
      n = n / 2;
    }
    else
      n = (3*n + 1)/2;

    count ++;
  }
  cout << count << endl;

  return 0;
}
