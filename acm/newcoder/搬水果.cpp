#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	int n, temp, result = 0, a, b;
	priority_queue<int, vector<int> , greater<int>> q;
	// ��С����ʵ�ֹ������Ĺ��� 
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		q.push(temp);
	}
	while(q.size() > 1){
		// �ҵ�������С�Ľڵ������½ڵ� 
		a = q.top();
		q.pop();
		b = q.top();
		q.pop(); 
		q.push(a + b); 
//		cout << q.top() << endl;
		result += (a + b);
//		q.pop();
	}
	cout << result << endl;
}

