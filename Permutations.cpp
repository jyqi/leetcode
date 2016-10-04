#include "Model.h"
using namespace std;

class Solution {
public:
	/*
	Recursion
	void solve(vector<int> &nums, int cur, vector<int> &tmp, vector<vector<int> > &res) {
		if(tmp.size() == nums.size()) {
			res.push_back(tmp);
			return;
		}
		for(int i = 0; i < nums.size(); i++) {
			bool flag = true;
			for(int j = 0; j < tmp.size(); j++) {
				if(tmp[j] == nums[i]) {
					flag = false;
				}
			}
			if(flag) {
				tmp.push_back(nums[i]);
				solve(nums, i + 1, tmp, res);
				tmp.pop_back();	
			}
		}
	}
	*/
    vector<vector<int> > permute(vector<int>& nums) {
    	vector<vector<int> > res;    
    	if(nums.empty() || nums.size() <= 1) {
    		res.push_back(nums);
    		return res;
    	}
    	sort(nums.begin(), nums.end());
    	while(true) {
    		res.push_back(nums);
    		//find nums[i] < nums[i + 1]
    		int i = 0;
    		for(i = nums.size() - 2; i >= 0; i--) {
    			if(nums[i] < nums[i + 1]) {
    				break;
    			}
    			else if(i == 0) {
    				return res;
    			}
    		}
    		//find nums[i] < nums[j]
    		int j = 0;
    		for(j = nums.size() - 1; j > i; --j) {
    			if(nums[i] < nums[j]) {
    				break;
    			}
    		}
    		//swap between nums[i] and nums[j]
    		int temp = nums[j];
    		nums[j] = nums[i];
    		nums[i] = temp;

    		//reverse between [i + 1, n - 1]
    		reverse(nums, i + 1, nums.size() - 1);
    	}
    	return res;
    }
    void reverse(vector<int> &nums, int start, int end) {
    	for(int i = start, j = end; i < j; i++, j--) {
    		int temp = nums[i];
    		nums[i] = nums[j];
    		nums[j] = temp;
    	}
    }
};

int main() {
	Solution s;
	vector<vector<int> > res;
	int arr[] = {1, 2, 2};
	vector<int> v(arr, arr + 3);
	res = s.permute(v);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
