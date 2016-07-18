#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if(nums.size() == 0) return 0;
    	vector<int> arr;
    	for(int i = 0; i < nums.size(); i++) {
    		if(arr.empty()) arr.push_back(nums[i]);
    		int k = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();
    		if(k == arr.size()) arr.push_back(nums[i]);
    		else arr[k] = nums[i];
    	}    
    	return arr.size();
    }
};

int main() {
	Solution s;
	int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
	vector<int> v(arr, arr + 8);
	printf("%d", s.lengthOfLIS(v));
	return 0;
}