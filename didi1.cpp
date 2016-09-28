#include <iostream>
#include <string>
#include <vector>
using namespace std;
int b[11][11], c[11][11], mat[11][11];
vector<string> res;
int n, m, p, minn;
int moves[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

void display() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(c[i][j]) {
				cout << "(" << i << "," << j << ")" << endl;
			}
		}
	}

}

void change() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			c[i][j] = b[i][j];
		}
	}
}

void solve(int i, int j, int count) {
	if(i == 0 && j == m - 1) {
		if(count < minn) {
			minn = count;
			change();
		}
		return;
	}
	for(int k = 0; k < 4; k++) {
		int x = i + moves[k][0];
		int y = j + moves[k][1];
		if(x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1) {
			b[x][y] = 1;
			mat[x][y] = 0;
			count++;
			solve(x, y, count + 1);
			count--;
			b[x][y] = 0;
			mat[x][y] = 1;
		}
	}
}
int main() {

	cin >> n >> m >> p;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	b[0][m - 1] = 1;
	solve(0, 0, p);
	display();
	return 0;
}