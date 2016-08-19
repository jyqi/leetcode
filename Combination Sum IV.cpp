#include <iostream>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	int len = nums.size();
  		vector<int> dp(target + 1, 0);
  		dp[0] = 1;
  		sort(nums.begin(), nums.end());
  		for(int i = 1; i <= target; i++) {
  			for(int j = 0; j < nums.size(); j++) {
  				if(i < nums[j]) break;
  				dp[i] += dp[i - nums[j]];
  			}
  		}
  		return dp.back();
    }
};