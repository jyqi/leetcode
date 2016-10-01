#include <iostream>

using namespace std;

long long dp[25][3];
int digit[25];

long long calc(long long a, int sp) {
	int m = 0;
	long long ans = 0;
	bool flag = false;
	while(a) {
		digit[++m] = a % 10;
		a /= 10;
	}
	digit[m + 1] = 0;
	for(int i = m; i >= 1; i--) {
		ans += dp[i - 1][2] * digit[i];
		if(flag) {
			ans += dp[i - 1][0] * digit[i];
		}
		else {
			if(digit[i] > sp - 1) ans += dp[i - 1][1];
			if(digit[i + 1] == sp - 1 && digit[i] == sp) flag = true; 
		}
	}
	if(flag) ans++;
	return ans;
}

int main() {
	long long sp, a, b;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1; i <= 22; i++) {
		dp[i][0] = dp[i - 1][0] * 10 - dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1];
	}
	
	cin >> sp >> a >> b;
	long long ansa = calc(a, sp);
	long long ansb = calc(b, sp);
	cout << ansb - ansa << endl;
	return 0;
}