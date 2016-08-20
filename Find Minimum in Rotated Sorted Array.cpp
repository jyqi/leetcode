#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
    	int start = 0, end = nums.size() - 1;
    	if(end < 0) return -1;
    	while(start + 1 < end) {
    		int mid = start + (end - start) / 2;
    		if(nums[end] > nums[mid]) end = mid;
    		else start = mid;
    	}
    	return nums[start] > nums[end] ? nums[end] : nums[start];
    }
};

int main() {
	int arr[] = {4, 5, 6, 7, 0, 1, 2};
	vector<int> v(arr, arr + 7);
	Solution s;
	cout << s.findMin(v) << endl;
	return 0;
}