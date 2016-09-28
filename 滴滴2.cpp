#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int base = 5;
	int res = 0;
	while(n / base) {
		res += n / base;
		base *= 5;
	}
	cout << res << endl;
	return 0;
}