#include<iostream>
#define MAX 15
// https://www.bilibili.com/video/av9830088?from=search&seid=6277695671597713304
using namespace std;
void printA(int A[], int n){
	for(int i = 0; i < n; i ++)
	{
		cout << A[i] ;
		if(i != n - 1)  cout << ' ';
	}
	cout << endl;
}

void swap(int A[], int p, int q){
	int temp = A[p];
	A[p] = A[q];
	A[q] = temp;
}

void perm(int A[], int p, int q) {
	if(p == q) {
		printA(A, q + 1);
	}
	else{
		for(int i = p; i <= q; i++){
			swap(A, p, i);
			perm(A, p + 1, q);
			swap(A, p, i);
		}
	}
}

int main(){
	int A[MAX], n;
	cin >> n;
	for(int i = 0; i < n; i ++){
		A[i] = i + 1;
	}
	perm(A, 0, n - 1 );
	return 0;
} 
