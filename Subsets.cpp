#include "Model.h"
using namespace std;

class Solution {
public:
	void solve(const vector<int> &nums, vector<int> &tmp, vector<vector<int> > &res, int cur) {
		res.push_back(tmp);
		for(int i = cur; i < nums.size(); i++) {
			tmp.push_back(nums[i]);
			solve(nums, tmp, res, i + 1);
			tmp.pop_back();
		}
	}

    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size() == 0) {
        	return res;
        } 
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        solve(nums, tmp, res, 0);
        return res;
    }
};

int main() {
	Solution s;
	vector<vector<int> > res;
	int arr[] = {1, 2, 3};
	vector<int> v(arr, arr + 3);
	res = s.subsets(v);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
