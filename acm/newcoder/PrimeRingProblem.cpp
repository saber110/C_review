#include<iostream>
#include<stack>
#define MAX 20
#define MAXPRIME 50
using namespace std;

int n, no, box[MAX];
stack<int> s;
bool Prime[MAXPRIME], mark[MAX] = {false};

void printPrime() {
	for(int i = 0; i < MAXPRIME; i ++)
		if(Prime[i]) {
			cout << i << '\t';
		}
	cout << endl;
}
void getPrime() {
	// generate prime between 1 and MAXPRIME
	// the multiple of prime is not prime
	// the minimum prime is 2
	for(int i = 2; i < MAXPRIME; i ++)
		Prime[i] = true;
//	Prime[2] = true;
	for(int i = 2; i < MAXPRIME; i ++) {
		for(int j = 2; j * i < MAXPRIME; j ++) {
			Prime[i * j] = false;
		}
	}
}
bool valid(int box[], int n) {
	for(int i = 0; i < n - 1; i++) {
		if(!Prime[box[i] + box[i + 1]])
			return false;
	}
	if(!Prime[box[0] + box[n - 1]])
		return false;
	return true;
}

bool valid2(int box[], int n) {
//	for(int i = 0; i < n - 1; i++) {
//		if(!Prime[box[i] + box[i + 1]])
//			return false;
//	}
	if(!Prime[box[0] + box[n - 1]])
		return false;
	return true;
}
void generate(int step) {
	if(step == n) {
		if(valid2(box, n))
		{
			for(int i = 0; i < n; i++) {
				cout << box[i];
				if(i != n - 1) cout << " ";
			}
			cout << endl;
		}
		return;
	}

	for(int i = 2; i <= n; i ++) {
		if(!mark[i]) {
			mark[i] = true;
			// value i for stepth
			if(Prime[box[step - 1] + i]) {
				box[step] = i;
				generate(step + 1);
			}
			mark[i] = false;
		}
	}
}

void generatep(int step) {
	if(step == n) {
		if(valid(box, n)) {
			for(int i = 0; i < n; i++) {
				cout << box[i];
				if(i != n - 1) cout << " ";
			}
			cout << endl;
		}
		return;
	}

	for(int i = 2; i <= n; i ++) {
		if(!mark[i]) {
			mark[i] = true;
			// value i for stepth
			box[step] = i;
			generatep(step + 1);
			mark[i] = false;
		}
	}
}
int main() {
	getPrime();
//	printPrime();
	while(cin >> n) {
		s.push(1);
		box[0] = 1;
//		cout << "Case " << ++ no << ":" << endl;
//		generatep(1);
		generate(1);
	}
}
