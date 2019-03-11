#include <iostream>
#include <cmath>
#define MAXN 1000000
using namespace std;

int Prime2[MAXN], pos2 = 0;
bool p[MAXN] = {false};  // 如果p[i]为素数,则为false

struct factor {
	int x, cnt;     // 对质因子x的计数cnt
} fac[10];
void FindPrime2(int n) {
	for(int i = 2; i < n; i ++) {
		if(!p[i]) {	// p[i] 为素数
			for(int j = i + i; j < n; j += i) {
				p[j] = true;
			}
			Prime2[pos2 ++] = i;
		}
	}
}

int main() {
	int n, n_;
	FindPrime2(1000000);		// 产生1000000以内的质数
	cin >> n;
	n_ = n;
	int num = 0;
	for(int i = 0; i < sqrt(n); i ++) {
		if(n % Prime2[i] == 0) {
			fac[num].x = Prime2[i];
			fac[num].cnt = 0;
			while(n % Prime2[i] == 0) {
				fac[num].cnt ++;
				n /= Prime2[i];
			}
			num ++;
		}
	}

	if(n != 1) {
//		cout << "not" << endl;
		fac[num].x = n;
		fac[num ++].cnt = 1;
	}

	cout << n_ << "=";
	if(n_ != 1)
		for(int i = 0; i < num; i++) {
			cout << fac[i].x ;
			if(fac[i].cnt != 1)
				cout << "^" << fac[i].cnt;
			if(i < num - 1)
				cout << "*";
		}
	else	cout <<  1;
	cout << endl;

	return 0;
}
