#include<iostream>
#include<vector>
#include<algorithm>
#define MAXROADNUM (100 * 100 *2)
#define MAXVERTEXNUM 100
#define ROOT -1
using namespace std;

typedef struct _Road {
	int s;	// source
	int e;	//end
	int cost;	//
	int parent;	// Union Find
} Road;

bool roadSort(Road road1, Road road2) {
	return road1.cost < road2.cost;
}

int UnionFind(int mst[], int a){
	// mst[a] : the parent of a 
	if(mst[a] == ROOT)	return a;
	else{
		int temp = UnionFind(mst, mst[a]);
		mst[a] = temp;
		return temp;
	}
}

void testPrintRoad(vector<Road> road){
	for(vector<Road>::iterator it = road.begin(); it != road.end(); it ++){
		cout << it->s << '\t' << it->e << '\t' << it->cost << '\t'; 
		cout <<endl;
	}
}

void testPrintMST(int mst[], int num){
	for(int i = 0; i < num ; i++){
		cout << i << ':' << mst[i] << '\t' ;
	} 
	cout << endl;
}
int main() {
	
	int vellegeNum;
	while(cin >> vellegeNum) {
		if(vellegeNum != 0) {
			vector<Road> road;
			int roadNum = vellegeNum * (vellegeNum - 1) / 2;
			int mst[MAXVERTEXNUM], ans = 0;
			// init for union find
			for(int i = 0; i < MAXVERTEXNUM; i ++) {
				mst[i] = ROOT;
			}
			// input
			for(int i = 0; i < roadNum; i ++) {
				Road roadTemp;
				cin >> roadTemp.s >> roadTemp.e >> roadTemp.cost;
				roadTemp.parent = -1;
//				if(i == 0)	road.push_back(roadTemp);
				road.push_back(roadTemp);
			}
			// sort by cost
			sort(road.begin(), road.end(), roadSort);
//			testPrintRoad(road);
//			testPrintMST(mst, vellegeNum);
			// generate MST by Union Find
			for(int i = 0; i < roadNum; i ++) {
				int a = UnionFind(mst, road[i].s);
				int b = UnionFind(mst, road[i].e);
				if(a != b){
					mst[b] = a;		// Uoion
					ans += road[i].cost;
				}
			}
//			testPrintMST(mst, vellegeNum);
			cout << ans << endl;
		}
		else  break;
	}
	return 0;
}
