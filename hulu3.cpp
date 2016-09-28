#include <iostream>
using namespace std;

bool vis[55][105];
int n, m, l, s;
int N;
char mat[55][105];
int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int ans;

bool climb(int curx, int cury, int &nexx, int &nexy) {
	for(int i = 0; i < l; i++) {
		if(curx + i < n && mat[curx + i][cury] == '#' && !vis[curx + i][cury]) {
			nexx = curx + i;
			nexy = cury;
			return true;
		}
	}
	for(int i = 0; i < l; i++) {
		if(curx - i >= 0 && mat[curx + i][cury] == '#' && !vis[curx - i][cury]) {
			nexx = curx + i;
			nexy = cury;
			return true;
		}
	}
	return false;
}

bool jump(int curx, int cury, int nexx, int nexy) {
	for(int i = 0; cury + i < m; i++) {
		if(mat[curx][cury] == '#' && !vis[curx][cury + i]) {
			nexx = curx;
			nexy = cury + i;
			return true;
		}
	}
	for(int i = 0; cury - i >= 0; i++) {
		if(mat[curx][cury] == '#' && !vis[curx][cury - i]) {
			nexx = curx;
			nexy = cury - i;
			return true;
		}
	}
	return false;
}

void dfs(int curx, int cury, int &res) {
	if(curx < 0 || cury < 0 || curx > n || cury > m) {
		return;
	}
	for(int i = 0; i < 4; i++) {
		int nexx = curx + moves[i][0];
		int nexy = cury + moves[i][1];
		if(nexx >= 0 && nexx < n && nexy >= 0 && nexy < m) {
			if(mat[nexx][nexy] == '#' && !vis[nexx][nexy]) {
				res += 1;
				if(ans < res) {
					ans = res;
				}
				vis[nexx][nexy] = 1;
				dfs(nexx, nexy, res);
				res -= 1;
				vis[nexx][nexy] = 0;
			}
		}
		else if(climb(curx, cury, nexx, nexy)) {
			res += 1;
			if(ans < res) {
				ans = res;
			}
			vis[nexx][nexy] = 1;
			dfs(nexx, nexy, res);
			res -= 1;
			vis[nexx][nexy] = 0;
		}
		else if(jump(curx, cury, nexx, nexy)) {
			res += 1;
			vis[nexx][nexy] = 1;
			if(ans < res) {
				ans = res;
			}
			dfs(nexx, nexy, res);
			res -= 1;
			vis[nexx][nexy] = 0;	
		}
	}
}

int main() {	
	while(N--) {
		cin >> n >> m >> l >> s;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> mat[i][j];
				vis[i][j] = 0;
			}
		}
		ans = -1;
		int res = 1;
		dfs(0, 0, res);
		cout << ans << endl;
	}
}