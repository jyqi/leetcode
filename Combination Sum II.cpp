#include "Model.h"
#include <unordered_map>
using namespace std;

class Solution {
public:
    void solve(int start, int end, int target, vector<int> & candidates, vector<int> &tmp, vector<vector<int> > &res) {
        if(target == 0) {
            res.push_back(tmp);
            return;
        }
        else if(target < 0) {
            return;
        }
        for(int i = start; i <= end; i++) {
            if(i != start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            tmp.push_back(candidates[i]);
            // hash[candidates[i]] = true;
            solve(i + 1, end, target - candidates[i], candidates, tmp, res);
            // hash[candidates[i]] = false;
            tmp.pop_back();    
        }
    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;   
        int len = candidates.size();
        vector<int> tmp;
        // unordered_map<int, bool> hash;
        sort(candidates.begin(), candidates.end());
        solve(0, len - 1, target, candidates, tmp, res);
        return res;
    }
};

int main() {
	Solution s;
    int arr[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> v(arr, arr + 7);
	vector<vector<int> > res;
    res = s.combinationSum2(v, 8);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
