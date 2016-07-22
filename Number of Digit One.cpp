#include <iostream>
using namespace std;

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
    }
};

int main() {
	Solution s;
	cout << s.countDigitOne(13) << endl;
}