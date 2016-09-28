#include <iostream>
#include <string>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	string res = "";
	if(M == 0) {
		cout << "0" << endl;
		return 0;
	}
	bool neg = false;
	if(M < 0) {
		M = 0 - M;
		neg = true;
	}
	while(M) {
		int tmp = M % N;
		if(tmp > 10) {
			res = char('A' + tmp - 10) + res;
		}
		else {
			res = char('0' + tmp) + res;
		}
		M = M / N;
	}
	if(neg) {
		res = "-" + res;
	}
	cout << res << endl;
	return 0;
}