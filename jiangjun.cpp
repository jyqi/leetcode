#include <iostream>
using namespace std;

int main() {
	int T, n;
	int a[10001];
	cin >> T;
	while(T--) {
		cin >> n;
		int curRes = -1;
		int count = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] > curRes) {
				curRes = a[i];
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}