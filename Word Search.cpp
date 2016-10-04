#include "Model.h"
using namespace std;

int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int row, col;
class Solution {
public:
	bool solve(vector<vector<char> >& board, int sx, int sy, string word, int start, int end, vector<vector<bool> > &visit) {
		if(start == end) {
			return true;
		}
		for(int i = 0; i < 4; i++) {
			int nexx = sx + moves[i][0];
			int nexy = sy + moves[i][1];
			if(nexx >= 0 && nexx < row && nexy >= 0 && nexy < col && board[nexx][nexy] == word[start] && !visit[nexx][nexy]) {
				visit[nexx][nexy] = true;
				if(solve(board, nexx, nexy, word, start + 1, end, visit)) {
					return true;
				}
				visit[nexx][nexy] = false;
			}
		}
		return false;
	}
    bool exist(vector<vector<char> >& board, string word) {
    	int len = word.length();
    	if(len == 0) {
    		return true;
    	}
    	row = board.size();
    	if(row == 0) {
    		return false;
    	}
    	col = board[0].size();
    	vector<vector<bool> > visit(row, vector<bool>(col, 0));
    	for(int i = 0; i < row; i++) {
    		for(int j = 0; j < col; j++) {
    			visit[i][j] = 0;	
    		}
    	}
    	for(int i = 0; i < row; i++) {
    		for(int j = 0; j < col; j++) {
    			if(board[i][j] == word[0]) {
    				visit[i][j] = true;
    				if(solve(board, i, j, word, 1, len, visit)) {
    					return true;
    				}
    				visit[i][j] = false;
    			}
    		}
    	}
    	return false;
    }
};

int main() {
	char arr1[][4] = {{'A','B','C','E'},
					  {'S','F','C','S'},
					  {'A','D','E','E'}};
	
	vector<vector<char> > board;
	for(int i = 0; i < 3; i++) {
		vector<char> tmp(arr1[i], arr1[i] + 4);
		board.push_back(tmp);
	}
	Solution s;
	string str = "ABCB";
	cout << s.exist(board, str) << endl;
	return 0;
}