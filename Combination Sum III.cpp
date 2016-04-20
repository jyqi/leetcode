/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

//Using Simple DFS algorithm to solve this.
//each number should be selected or ignored.

class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int> tmp, int k, int n, int beg) {
        if(k == 0) {
            if(n == 0) {
                res.push_back(tmp);
            }
            return;
        }
        for(int i = beg; i < 10; i++) {
            if(n - i < 0) return;
            tmp.push_back(i);
            dfs(res, tmp, k- 1, n - i, i + 1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, tmp, k, n, 1);
        return res;
    }
};