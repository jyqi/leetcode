#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> res;
    	int len = nums.size();
    	if(len == 0) return res;
  		unordered_map<int, int> hash(len);
  		for(int i = 0; i < len; i++) {
  			if(hash.find(target - nums[i]) != hash.end()) {
  				res.push_back(hash[target - nums[i]]);
  				res.push_back(i);
  				//cout << nums[i] << endl;
  				return res;
  			}
  			else {
  				hash[nums[i]] = i;
  			}
  		}
  		return res;      
    }
};

int main() {
	int arr[] = {2, 7, 11, 15};
	Solution s;
	vector<int> par(arr, arr + 4);
	vector<int> res;
	res = s.twoSum(par, 9);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}