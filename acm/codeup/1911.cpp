#include<iostream>
#define MAXK 30
using namespace std;

int max(int a, int b) {
	return a>b?a:b;
}
int main() {
	int k;
	while(cin >> k) {
		if(k == 0) break;
		int data[MAXK], list[MAXK];
		for(int i = 0; i < k; i++) {
			cin >> list[i];
		}
	
		for(int i = 0; i < k; i ++) {
			int tmax = 1;
			for(int j = 0; j < i; j++) {
//				cout << j << "----" << i << endl;
//				cout << list[j] << "------" << list[i] << endl;
				if(list[j] >= list[i]){
					tmax = max(tmax, data[j] + 1);
//					cout << i << " : " << data[i] << endl;
				}
			}
			data[i] = tmax;
//			cout << i << " : " << data[i] << endl;
		}

		int ans = 0;
		for(int i = 0; i < k; i++)
			ans = max(ans,data[i]);
		cout << ans << endl;
	}
}
