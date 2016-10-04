#include "Model.h"
using namespace std;

class Solution {
public:
    void solve(int start, int end, int target, vector<int> & candidates, vector<int> &tmp, vector<vector<int> > &res) {
        if(start > end) { 
            return;
        }
        if(target == 0) {
            res.push_back(tmp);
            return;
        }
        else if(target < 0) {
            return;
        }
        for(int i = start; i <= end; i++) {
            tmp.push_back(candidates[i]);
            solve(i, end, target - candidates[i], candidates, tmp, res);
            tmp.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;   
        int len = candidates.size();
        vector<int> tmp;
        solve(0, len - 1, target, candidates, tmp, res);
        return res;
    }
};

int main() {
	Solution s;
    int arr[] = {2, 3, 6, 7};
    vector<int> v(arr, arr + 4);
	vector<vector<int> > res;
    res = s.combinationSum(v, 7);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
