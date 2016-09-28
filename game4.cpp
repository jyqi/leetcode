#include <cstdio>
#include <algorithm>
using namespace std;

const int SIZE = 50005;

struct people {
	int t;
	int s;
	int n;
	int dir;
	int res;
	int index;
	bool done;
};

bool cmp1(struct people a, struct people b) {
	return a.t < b.t;
}
bool cmp2(struct people a, struct people b) {
	return a.index < b.index;
}

int main() {
	int T, N;
	int start, all;
	bool init;
	struct people p[SIZE];
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		start = 1;
		init = true;
		all = 0;
		for(int i = 0; i < N; i++) {
			scanf("%d%d%d", &p[i].t, &p[i].s, &p[i].n);
			if(p[i].s < p[i].n) {
				p[i].dir = 1;		
			}
			else if(p[i].s < p[i].n) {
				p[i].dir = -1;
			}
			else {
				p[i].dir = 0;
			}
			p[i].res = 0;
			p[i].index = i;
		}
		sort(p, p + N, cmp1);
		for(int i = 0; i < N; i++) {
			if(init) {
				p[i].res = p[i].s - start;
				for(int j = i + 1; p[j].t < p[i].n; j++) {
					if(p[j].dir == p[i].dir) {
						if(p[j].s >= p[j].t - p[i].t + 1) {
							p[j].res = all + p[j].s - p[j].t + p[i].t - 1;
						}
					}
				}
			}
			start = p[i].n;
		}
		sort(p, p + N, cmp2);
		for(int i = 0; i < N; i++) {
			printf("%d\n", p[i].res);
		}
		printf("\n");
	}
	return 0;
}