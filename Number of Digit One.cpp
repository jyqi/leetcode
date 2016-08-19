#include <iostream>
using namespace std;

<<<<<<< HEAD
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
=======
int dp[15][15];
int digit[15];
class Solution {
public:
	int dfs(int l, int have, bool bound) {
		//cout << "位数：" << l << endl;
		if(l == -1) return have;
		if(!bound && dp[l][have] != -1) return dp[l][have];
		int end = bound ? digit[l] : 9;
		//cout << "end:" << end << endl;
		int res = 0;
		for(int i = 0; i <= end; i++) {
			if(i == 1) res = res + dfs(l - 1, have + 1, bound && i == end);
			else res = res + dfs(l - 1, have, bound && i == end);
			//cout << "res : " << res << endl;
		}
		//cout << res << endl;
		if(!bound) dp[l][have] = res;
		return res;
	}

    int countDigitOne(int n) {
        memset(dp, -1, sizeof(dp));
        int pos = 0;
        while(n) {
        	digit[pos++] = n % 10;
        	n = n / 10;
        }
        //cout << pos << endl;
        return dfs(pos - 1, 0, true);	//位数  是否有1  是否边界
>>>>>>> origin/master
    }
};

int main() {
	Solution s;
	cout << s.countDigitOne(13) << endl;
<<<<<<< HEAD
}

=======
}
>>>>>>> origin/master
