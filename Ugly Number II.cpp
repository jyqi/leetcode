#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
    	vector<long long> ugly(n, 1);
    	int i2 = 0, i3 = 0, i5 = 0;
    	for(int i = 1; i < n; i++) {
    		long long current = min(ugly[i2] * 2, min(ugly[i3] * 3, ugly[i5] * 5));
    		if(current == ugly[i2] * 2) i2++;
    		if(current == ugly[i3] * 3) i3++;
    		if(current == ugly[i5] * 5) i5++;
    		ugly[i] = current;
    	}
    	return ugly[n - 1];
    }
};

int main() {
	Solution s;
	cout << s.nthUglyNumber(10) << endl;
	return 0;
}