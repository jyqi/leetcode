#include <iostream>
using namespace std;

int getDigitSum(int tar) {
	int res = 0;
	while(tar) {
		res += tar % 10;
		tar /= 10;
	}
	return res;
}

int main() {
	int A, B, C, curSum;
	cin >> A >> B >> C;
	int csum = getDigitSum(C);
	for(int i = A; i <= B; i++) {
		curSum = getDigitSum(i);
		if(curSum == csum) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}