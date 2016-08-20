#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if(matrix.size() == 0) return false;
		int row = matrix.size();
		int col = matrix[0].size();
		int start = -1, end = row * col;
		while(start + 1 < end) {
			int mid = start + (end - start) / 2;
			if(matrix[mid / col][mid % col] == target) return true;
			else if(matrix[mid / col][mid % col] < target) start = mid;
			else end = mid;
		}        
		return false;
    }
};

int main() {
	
}