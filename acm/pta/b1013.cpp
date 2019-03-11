#include <iostream>
#define MAXN 1000100
using namespace std;
bool deleted[MAXN] = {false};
bool Prime[MAXN] , pos = 0;
int Prime2[MAXN], pos2 = 0;
bool p[MAXN] = {false};  // 如果p[i]为素数,则为false 

void FindPrime2(int n) {
	for(int i = 2; i < n; i ++){
		if(!p[i]){	// p[i] 为素数 
			for(int j = i + i; j < n; j += i){
				p[j] = true;
			} 
			Prime2[pos2 ++] = i;
		}
	}
}
// 输入最大的需要求的数
void FindPrime(int n) {
	for(int i = 2; i < n;) {
		for(int j = i + i; j < n; j += i) {
			deleted[j] = true;		// 删掉i的倍数
		}
		Prime[i] = !deleted[i];
//		cout << Prime[i] << '\t';
		for(int l = i + 1; l <= n; l ++) {
			if(!deleted[l]) {
				i = l;
				break;
			}
		}
	}
}

int main1() {
	int begin, end;
	FindPrime(MAXN);
	cin >> begin >> end;
	int pos = 0, temp = 0;

	for(int i = 0; i < MAXN; i++) {
		if(Prime[i]) {
			temp ++;

			if(temp >= begin && temp <= end) {
				pos ++;
				if(pos % 10 == 0) cout << i << endl;
				else if(pos <= end - begin) {
					cout << i << " ";
				} else cout << i;
			}
			if(pos > end - begin)	break;

		}
	}


	return 0;
}

int main() {
	FindPrime2(100);
	for(int i = 0; i < pos2; i ++)
		cout << Prime2[i] << '\t';
}
