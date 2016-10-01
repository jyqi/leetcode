#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        vector<int> res;
        if(A.empty()) return res;
        int x1orx2 = 0;
        for(int i = 0; i < A.size(); i++) {
        	x1orx2 ^= A[i];
        }
        int lastbit = x1orx2 - (x1orx2 & (x1orx2 - 1));
        int single1 = 0, single2 = 0;
        for(int i = 0; i < A.size(); i++) {
        	if(lastbit & A[i]) single1 ^= A[i];
        	else single2 ^= A[i];
        }
        res.push_back(single1);
        res.push_back(single2);
        return res;
    }
};

int main() {
	int arr[] = {1, 2, 2, 3, 4, 4, 5, 3};
	vector<int> v(arr, arr + 8);
	Solution s;
	std::vector<int> res;
	res = s.singleNumberIII(v);
	cout << res[0] << res[1] << endl;
	return 0;
}