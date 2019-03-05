#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 4
#define Kaprekar 6174
int num[MAX] = {0};

void getNumber(int number) {
	for(int i = MAX - 1; i >= 0; i --) {
		num[i] = number % 10;
		number = number / 10;
//		cout << num[i] << endl;
	}
}

int printNum() {
//	for(int i = 0; i < MAX; i++) {
////		cout << num[i] << "\t";
//	}
//	cout << endl;
	return num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
}

bool SortDiZeng(int a, int b) {
	return a <= b;
}
bool SortDiJian(int a, int b) {
	return a >= b;
}

int main(int argc, char** argv) {
	int number, large , little;
	while(cin >> number) {
		do {
			getNumber(number);
			sort(num, num + MAX, SortDiZeng);
			little = printNum();
			sort(num, num + MAX, SortDiJian);
			large = printNum();
			number = large - little;
//			printf("%4d - %4d = %4d\n",large,little,number);
			cout << setfill('0') << setw(4) << right << large << " - " <<  setw(4) << right <<little << " = " << setw(4) << right <<number << endl;
		} while(number != 0 && number != Kaprekar);
	}


	return 0;
}
