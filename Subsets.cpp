//寻找一个数组的所有子集
//采用深度优先搜索的方法，因为子集中，元素只存在选与不选
//空间复杂度为O(n),时间复杂度为O(n^2)

#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tRes;
        sort(nums.begin(), nums.end());
        solve(res, tRes, nums, 0, nums.size());
        return res;
    }
    void solve(vector<vector<int>> &res, vector<int> tRes, vector<int> nums, int nBegin, int nEnd) {
        if(nBegin == nEnd) {
            res.push_back(tRes);
            return;
        }
        solve(res, tRes, nums, nBegin + 1, nEnd);
        tRes.push_back(nums[nBegin]);
        solve(res, tRes, nums, nBegin + 1, nEnd);
    }
};

int main() {
    Solution s;
    vector<int> a{1, 2};
    s.subsets(a);
    cout << "aa" << endl;
    return 0;
}