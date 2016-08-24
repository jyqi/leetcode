#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	int len = digits.size();
    	vector<int> res(len, 0);
    	int carry = 1;
    	for(int i = len - 1; i >= 0; i--) {
    		digits[i] = digits[i] + carry;
    		if(digits[i] > 9) carry = 1;
    		else carry = 0;
    		digits[i] %= 10;
    		res[i] = digits[i];
    	}    
    	if(carry) res.insert(res.begin(), 1);
    	return res;
    }
};

int main() {
	Solution s;
	vector<int> res;
	int arr[] = {1,2,4};
	vector<int> v(arr, arr + 3);
	res = s.plusOne(v);
	for(int i = 0; i < res.size(); i++) cout << res[i] << endl;
	return 0;
}