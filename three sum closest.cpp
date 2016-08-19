#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int len = nums.size();
       int res = 0;
       if(len < 3) return 0;
       int ans = 0;
       sort(nums.begin(), nums.end());
       res = nums[0] + nums[1] + nums[2];
       for(int i = 0; i < len - 2; i++) {
       		if(i > 0 && nums[i] == nums[i - 1]) continue;
       		int j = i + 1;
       		int k = len - 1;
       		while(j < k) {
       			ans = nums[i] + nums[j] + nums[k];
       			if(abs(target - ans) < abs(target - res)) {
       				res = ans;
       			}
       			else if(target == ans) return res;
       			ans < target ? j++ : k--;
       		}
       }
       return res;
    }
};

int main() {
	int arr[] = {-1, 2, 1, 4};
	Solution s;
	vector<int> par(arr, arr + 4);
	int res;
	res = s.threeSumClosest(par, 1);
	cout << res << endl;
	return 0;
}