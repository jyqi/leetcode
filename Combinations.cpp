#include "Model.h"
using namespace std;

class Solution {
public:
    void solve(int start, int end, int target, vector<int> &tmp, vector<vector<int> > &res) {
        if(tmp.size() == target) {
            res.push_back(tmp);
            return;
        }
        for(int i = start; i <= end; i++) {
            tmp.push_back(i);
            solve(i + 1, end, target, tmp, res);
            tmp.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;      
        vector<int> tmp;
        solve(1, n, k, tmp, res);
        return res;
    }
};

int main() {
	Solution s;
    // string str = "aabb";
	vector<vector<int> > res;
    res = s.combine(5, 2);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
