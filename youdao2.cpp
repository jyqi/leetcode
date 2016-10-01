#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string.h>
using namespace std;

double p[3605];
int ball[3605];
double m[3605][3605];
double lot(int begin, int end, int times) {
	if(m[begin][end] != 0) {
		return m[begin][end];
	}
	if(begin > end) return 1;
	if(times <= 0) return 0;
	double res = p[ball[begin]] * lot(begin + 1, end, times - 1) + (1 - p[ball[begin]]) * lot(0, end, times - 1);
	m[begin][end] = res;
	//cout << res << endl;
	return res;
}

int main() {
	int n, m;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> ball[i];
	}
	string end;
	cin >> end;
	int min = 0;
	int sec = 0;
	bool flag = true;
	for(int i = 0; i < end.size(); i++) {
		if(flag) {
			if(end[i] != ':') {
				min = min * 10 + end[i] - '0';
			}
			else {
				flag = false;
			}
		}
		else {
			sec = sec * 10 + end[i] - '0';
		}
	}
	int times = min * 60 + sec;
	cout << times << endl;
	double res = lot(0, m, times);
	cout << res << endl;
	return 0;
}