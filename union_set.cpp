#include <iostream>
using namespace std;

int set[10001];

int find(int x) {
	int r = x;
	while(set[r] != r) {		//找到代表集合
		r = set[r];
	}
	int i = x;
	while(i != r) {		//使得r代表的集合中，所有节点都指向r
		int j = set[i];
		set[i] = r;
		i = j;
	}
	return r;
}

void merge(int x, int y) {
	int h = find(x);
	int t = find(y);
	if(h < t) {
		set[t] = h;
	}
	else {
		set[h] = t;
	}
}

int friends(int n, int m, int *r[]) {
	for(int i = 1; i <= n; i++) {		//初始化
		set[i] = i;
	}
	for(int i = 0; i < m; i++) {
		merge(r[i][0], r[i][1]);
	}
	int count = 0;
	for(int i = 1; i <= n; i++) {
		if(set[i] == i) {
			count++;
		}
	}
	return count;
}

int main() {
	int tmp[3][2] = {{1, 2}, {2, 3}, {4, 5}};
	int *r[3] = {tmp[0], tmp[1], tmp[2]};
	cout << friends(5, 3, r) << endl;
	return 0;
}