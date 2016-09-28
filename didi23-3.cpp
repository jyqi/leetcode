#include <iostream>
#include <algorithm>
using namespace std;

int A[1005];
dp[1005][1005];
int res;

int main()
{
    int n, sum, curSum;
    cin >> n >> sum;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        dp[0][sum] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < sum; j++) {
            dp[i][j] = max(dp[i - 1])
        }
    }
    return 0;
}