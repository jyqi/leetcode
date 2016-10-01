#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int len = nums.size();
    	if(len == 0) return -1;
  		int res =  nums[0];
  		int count = 1;
  		for(int i = 1; i < len; i++) {
  			if(res == nums[i]) count++;
  			else count--;
  			if(count == 0) {
  				res = nums[i];
  				count = 1;
  			}
  		}
  		return res;
    }
};

int main() {
	int arr[] = {1, 1, 1, 1, 2, 2, 2};
	std::vector<int> v(arr, arr + 7);
	Solution s;
	cout << s.majorityElement(v) << endl;
	return 0;
}