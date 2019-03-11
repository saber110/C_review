#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int a, b;
	while(cin >> a >> b)
		cout << gcd(a,b) << endl;
}
