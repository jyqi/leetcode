#include "Model.h"
using namespace std;

class Solution {
public:
    bool palindrome(string s) {
        if(s.empty()) {
            return false;
        }
        int len = s.size();
        for(int i = 0; i < len; i++) {
            if(s[i] != s[len - 1 - i]) return false;
        }
        return true;
    }

    void solve(string s, int pos, vector<string> &tmp, vector<vector<string> > &res) {
        if(pos == s.size()) {
            res.push_back(tmp);
            return;
        }
        for(int i = pos + 1; i <= s.size(); i++) {
            string substr = s.substr(pos, i - pos);
            if(!palindrome(substr)) {
                continue;
            }
            tmp.push_back(substr);
            solve(s, i, tmp, res);
            tmp.pop_back();
        }
    }

    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        int len = s.size();
        if(len < 1) {
            return res;
        }
        vector<string> tmp;
        solve(s, 0, tmp, res);
        return res;
    }
};

int main() {
	Solution s;
    string str = "aabb";
	vector<vector<string> > res;
    res = s.partition(str);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
	return 0;
}
