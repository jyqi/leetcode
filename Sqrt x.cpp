#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
		if(x < 1) return 0;
		int start = 1, end = x;
		while(start + 1 < end) {
			long long mid = start + (end - start) / 2;
			if(mid * mid == x) return mid;
			else if(mid * mid > x) end = mid;
			else start = mid;
		}
		return start;
    }
};

int main() {
	int x = 10;
	Solution s;
	cout << s.mySqrt(x) << endl;
	return 0;
}