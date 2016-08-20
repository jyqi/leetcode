#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
  		if(matrix.empty()) return false;
  		int row = matrix.size();
  		int col = matrix[0].size();
  		int i = col - 1, j = 0;
  		while(i >= 0 && j < row) {
  			if(matrix[j][i] < target) j++;
  			else if(matrix[j][i] > target) i--;
  			else return true;
  		}      
  		return false;
    }
};

int main() {
	
}