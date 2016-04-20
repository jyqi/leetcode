/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/

//To solve this problem, I just simplely use enumeration method.
//the complexity of my solution is O(n^3)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        if(matrix.empty()) return res;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == '1') {
                    int k = 2;
                    bool flag = 1;
                    while(flag) {
                        if(i + k - 1 == row) break;
                        if(j + k - 1 == col) break;
                        for(int p = 0; p < k; p++) {
                            if(matrix[i + k - 1][j + p] == '0' || matrix[i + p][j + k - 1] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if(flag) k++;
                    }
                    k--;
                    if(res < k * k) res = k * k;
                }
            }
        }
        return res;
    }
};