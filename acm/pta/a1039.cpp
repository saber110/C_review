#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define STUDENTS 40000
//#define ALLSTUDENTS 40000
using namespace std;
//bool course[ALLSTUDENTS] = {false};
int FindTemp(vector<string> &temp, string name) {
//	在temp中查找有没有这个人，有的话返回id
//  没有的话插入并返回id
	for(int i = 0; i < temp.size(); i ++) {
		if(temp[i] == name)	return i;
	}
	temp.push_back(name);
	return temp.size() - 1;
}

int main() {
	int N, K, i, Ni;
	string nameTemp, queryLists;
	cin >> N >> K;
	vector<string> temp;		// 构建二维表的一维缓冲
	vector<int> table[STUDENTS];	// 存储姓名-课程表

	for(int p = 0; p < K; p ++) {
		cin >> i >> Ni;
		for(int j = 0; j < Ni; j ++) {
			cin >> nameTemp;
			int count =  FindTemp(temp, nameTemp);
			table[count].push_back(i);
		}
	}
	for(int p = 0; p < N; p ++) {
		cin >> nameTemp;
		int count = FindTemp(temp, nameTemp);
		sort(table[count].begin(), table[count].end());
		int size = table[count].size();
		cout << nameTemp << ' ' << size;
		if(size != 0)
			cout << " ";
		for(int j = 0; j < size; j++) {	
			cout << table[count][j] ;
			if(j != table[count].size() - 1) cout << ' ';
		}
		if(p != N - 1)	
			cout << endl;
	}
	
}
