#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
        	res = res ^ A[i];
        }
        return res;
    }
};

int main() {
	int arr[] = {1, 2, 2, 1, 3, 4, 3};
	//vector<int> v(arr, arr + 7);
	vector<int> v;
	Solution s;
	cout << s.singleNumber(v) << endl;
	return 0;
}