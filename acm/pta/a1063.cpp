#include<iostream>
#include<cstdio>
#include<unordered_set>
#define MAXSETS 55
using namespace std;
void coutTest(string name, int value) {
	cout << "--------------------------------" << endl;
	cout << name <<"\t" << value << endl;
	cout << "--------------------------------" << endl;
}
int main() {
	unordered_set<int> sets[MAXSETS];
	int totalNum, numTemp, queryList[MAXSETS];
	int localTemp;
	float result;
	cin >> totalNum;
	for(int i = 0; i < totalNum; i ++) {
		cin >> numTemp;
		for(int j = 0; j < numTemp; j ++) {
			cin >> localTemp;
			sets[i].insert(localTemp);
		}
	}

//	for(int i = 0; i < totalNum; i ++) {
//		cout << "sets" << i << '\t' ;
//		for(set<int>::iterator it = sets[i].begin(); it != sets[i].end(); it ++) {
//			cout << *it << "\t";
//		}
//		cout << endl;
//	}
	// 将query中的组合成一个set, 放在sets[MAXSETS - 1]
	// Nc = sum(size) - new.size()
	// Nt = sum(size)
	cin >> numTemp;

	for(int i = 0; i < numTemp; i ++) {
		int oldSizeSum = 0;
		sets[MAXSETS - 1].clear();
		for(int j = 0; j < 2; j++) {
			cin >> localTemp;			// 输入一组查询
//			coutTest("localTemp", localTemp);
			//queryList[i] = localTemp;
			for(unordered_set<int>::iterator it = sets[localTemp - 1].begin(); it != sets[localTemp - 1].end(); it ++) {
				sets[MAXSETS - 1].insert(*it);
			}
			//sets[MAXSETS - 1] += sets[localTemp - 1];
			oldSizeSum += sets[localTemp - 1].size();
		}

//		cout << "sets" << MAXSETS - 1 << '\t' ;
//		for(set<int>::iterator it = sets[MAXSETS - 1].begin(); it != sets[MAXSETS - 1].end(); it ++) {
//			cout << *it << "\t";
//		}
//		cout << endl;


		int Nc = oldSizeSum - sets[MAXSETS - 1].size();
//		coutTest("Nc", Nc);
//		coutTest("Nt", sets[MAXSETS - 1].size());
		result = Nc / (sets[MAXSETS - 1].size() * 1.0) * 100;
		printf("%.1f%\n", result);

	}
	return 0;
}
