#include <iostream>
using namespace std;

int dp[20];
int digit[20];
class Solution {
public:
	int all[20], num0[20], num1[20];	//all[i]表示i位数的个数, num[0]表示不含数字1的i位数的个数
	//num1[i]表示i位数含有数字1出现的总次数
	void init(int n = 11) {
		all[0] = 1;
		num0[0] = 1;
		for(int i = 1; i <= n; i++) {
			all[i] = all[i - 1] * 10;
			num0[i] = num0[i - 1] * 9;
		}


	}
    int countDigitOne(int n) {
    	int digit[20], pos = 0, x = n;
    	while(x) {
    		digit[pos++] = x % 10;
    		x /= 10;
    	}
    	int count = 0;
    	int sum = 0;
    	for(int i = pos - 1; i >= 0; i--) {
    		sum += digit[i] *
    	}
    }
};

int main() {
	Solution s;
	cout << s.countDigitOne(13) << endl;
}

