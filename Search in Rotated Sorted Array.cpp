#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int solve(vector<int> nums, int start, int end, int target) {
		if(end < start) return -1;
		int mid = start + (end - start) / 2;
		if(nums[mid] == target) {
			return mid;
		}
		if(nums[start] < nums[mid]) {
			if(target >= nums[start] && target <= nums[mid]) {
				return solve(nums, start, mid - 1, target);
			}
			else return solve(nums, mid + 1, end, target);
		}
		else if(nums[start] > nums[mid]) {
			if(target >= nums[mid] && target <= nums[end]) return solve(nums, mid + 1, end, target);
			else return solve(nums, start, mid - 1, target);
		}
		else if(nums[start] == nums[mid]) {
			if(nums[mid] != nums[end]) return solve(nums, mid + 1, end, target);
			else {
				int res = solve(nums, start, mid - 1, target);
				if(res == -1) return solve(nums, mid + 1, end, target);
				else return res;
			}
		}
		return -1;
	}
    int search(vector<int>& nums, int target) {
		int start = 0, end = nums.size() - 1;
		if(end < 0) return -1;        
		return solve(nums, start, end, target);
    }
};

int main() {
	int arr[] = {1};
	//int arr[] = {2, 2, 2, 3, 4, 2};
	vector<int> v(arr, arr + 1);
	Solution s;
	cout << s.search(v, 0) << endl;
	return 0;
}