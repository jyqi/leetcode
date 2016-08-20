#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
  		vector<int> res;
  		int start = -1, end = nums.size();

  		if(end == 0) return res;
  		while(start + 1 < end) {
  			int mid = start + (end - start) / 2;
  			if(nums[mid] < target) start = mid;
  			else end = mid;
  		}
  		if(start + 1 < nums.size() && nums[start + 1] == target) {
  			res.push_back(start + 1);
  		}
  		else {
  			res.push_back(-1);
  			res.push_back(-1);
  			return res;
  		}
  		//start = -1;
  		end = nums.size();
  		while(start + 1 < end) {
  			int mid = start + (end - start) / 2;
  			if(nums[mid] > target) end = mid;
  			else start = mid;
  		}
  		res.push_back(end - 1);
  		return res;
    }
};

int main() {
	int arr[] = {5, 7, 7, 8, 8, 10};
	vector<int> v(arr, arr + 6);
	vector<int> res;
	Solution s;
	res = s.searchRange(v, 8);
	for(int i = 0; i < 2; i++) 
		cout << res[i] << endl;
	return 0;
}