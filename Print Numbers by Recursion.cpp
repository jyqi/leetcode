#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        // write your code here
        vector<int> res;
        if(n < 1) return res;
        solve(n, res);
        return res;
    }
    void solve(int n, vector<int> &res) {
    	if(n == 0) return;
    	solve(n - 1, res);
    	int base = (int)pow(10, n - 1);
    	int size = res.size();
    	for(int i = 1; i < 10; i++) {
    		res.push_back(i * base);
    		for(int j = 0; j < size; j++) {
    			res.push_back(res[j] + base * i);
    		}
    	}
    }
};

int main() {
	Solution s;
	vector<int> res;
	res = s.numbersByRecursion(5);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}