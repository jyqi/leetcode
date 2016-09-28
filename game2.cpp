#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

char s[10][10];
int a[10][10];
int moves[8][2] = {-1,0,1,0,0,1,0,-1,-1,-1,-1,1,1,-1,1,1};
int main()
{
	int t;
	scanf("%d", &t);
	while(t--) {
		for(int i = 0; i < 8; i++) {
			scanf("%s", s[i]);
			for(int j = 0; j < 8; j++) {
				if(s[i][j] == '.') a[i][j] = -1;
				else if(s[i][j] == '*') a[i][j] = 0;
				else if(s[i][j] == 'o') a[i][j] = 1;
			}
		}
		int n;
		scanf("%d", &n);
		while(n--) {
			int x, y, f;
			scanf("%d%d%d", &x, &y, &f);
			a[x][y] = f;
			for(int i = 0; i < 8; i++) {
				int h = 1 - f;
				int b, c, d, e;
				int flag = 0;
				int j;
				for(j = 1; ;j++) {
					d = x + j * moves[i][0];
					e = y + j * moves[i][1];
					if(d < 0 || d > 7 || e < 0 || e > 7) break;
					if(a[d][e] == f) {
						flag = 2;
						break;
					}
					if(a[d][e] == h) continue;
					if(a[d][e] == -1) {
						flag = 1;
						break;
					}
				}
				if(flag == 2) {
					for(int k = j-1; k > 0; k--) {
						d = x + k * moves[i][0];
						e = y + k * moves[i][1];
						a[d][e] = f;
					}
				}
			}
		}
		int ans1 = 0, ans2 = 0;
		for(int i = 0; i < 8; i++) {
			for(int j = 0; j < 8; j++) {
				if(a[i][j] == 0) ans1++;
				if(a[i][j] == 1) ans2++;
			}
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}