#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	int n, temp, result = 0, a, b;
	priority_queue<int, vector<int> , greater<int>> q;
	// 用小顶堆实现哈夫曼的构造 
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		q.push(temp);
	}
	while(q.size() > 1){
		// 找到两个最小的节点生成新节点 
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

