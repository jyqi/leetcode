#include "Model.h"
using namespace std;

class Solution {
public:
	void solve(vector<int> &nums, int cur, vector<int> &tmp, vector<vector<int> > &res) {
		res.push_back(tmp);
		for(int i = cur; i < nums.size(); i++) {
			if(i != cur && nums[i] == nums[i - 1]) {
				continue;
			}
			tmp.push_back(nums[i]);
			solve(nums, i + 1, tmp, res);
			tmp.pop_back();
		}
	}

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    	vector<vector<int> > res;    
    	if(nums.size() == 0) {
    		return res;
    	}
    	vector<int> tmp;
    	sort(nums.begin(), nums.end());
    	solve(nums, 0, tmp, res);
    	return res;
    }
};

int main() {
	Solution s;
	vector<vector<int> > res;
	int arr[] = {1, 2, 2};
	vector<int> v(arr, arr + 3);
	res = s.subsetsWithDup(v);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
