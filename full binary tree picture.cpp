#include <iostream>
#include <math>
using namespace std;

int main() {
	int N, M;
	int corr[20];
	corr[0] = 2;
	corr[1] = 3;
	corr[2] = 6;
	corr[3] = 13;
	corr[4] = 24;
	for(int i = 5; i < 20; i++) {
		corr[i] = 2*corr[i - 1];
	}
	int height[20];
	height[0] = 0;
	for(int i = 1; i < 20; i++) {
		height[i] = corr[i - 1] + height[i - 1];
	}
	for(int i = 0; i < 20; i++) cout << corr[i] << endl;
	cin >> N;
	int x1, y1, x2, y2;
	for(int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		int upper = 0;
		int down = 0;
		if(x1 == 0) upper = 0;
		int flag = false;
		for(int i = 1; i < N; i++) {
			if(height[i] > x1 && height[i - 1] < x1) upper = i - 1;
			else if(height[i] == x1) {
				flag = true;
				upper = i;
			}
			if(height[i] > x2 && height[i - 1] < x2) down = i - 1;
			else if(height[i] == x2) {
				down = i;
				flag = true;
			}
		}
		if(down == upper) {
			if(flag) cout << pow(2, upper) << endl;
			else cout << 0 << endl;
		}
		int count = pow(2, down) - pow(2, upper);
		int ver = 0 - height[N - 1];
		for(int i = 0; ; i++) {
			ver = ver + i%2 == 0 ? 4 : 2;
			if(ver > y1) break;
			count--;
		}
		
	}
}