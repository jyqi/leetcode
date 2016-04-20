//A simple binary search problem


class Solution {
public:
    bool bSearch(vector<int> m, int beg, int end, int target) {
        if(beg > end) return false;
        int mid = (beg + end) / 2;
        if(m[mid] > target) {
            return bSearch(m, beg, mid - 1, target);
        }
        else if(m[mid] < target) {
            return bSearch(m, mid + 1, end, target);
        }
        else return true;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] <= target && matrix[i][col - 1] >= target)
                return bSearch(matrix[i], 0, col - 1, target);
        }
        return false;
    }
};