#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        if(A.empty()) return 0;
        int res = 0, bit = 0;
        for(int i = 0; i < 8 * sizeof(int); i++) {
        	bit = 0;
        	for(int j = 0; j < A.size(); j++) {
        		bit += ((A[j] >> i) & 1);
        	}
        	res |= (bit % 3 << i); 
        }
        return res;
    }

    int singleNumberK(vector<int> &A, int k, int l) {
    	if(A.empty()) return 0;
    	int t;
    	vector<int> count(k, 0);
    	count[0] = ~0;
    	for(int i = 0; i < A.size(); i++) {
    		t = count[k - 1];
    		for(int j = k - 1; j > 0; j--) {
    			count[j] = (count[j - 1] & A[i]) | (count[j] & ~A[i]);
    			cout << j << " " << count[j] << endl;
    		}
    		count[0] = (t & A[i]) | (count[0] & ~A[i]);
    		cout << 0 << " " << count[0] << endl;
    	}
    	return count[l];
    }
};

int main() {
	int arr[] = {1,1,2,3,3,3,2,2,4,1};
	vector<int> v(arr, arr + 10);
	//vector<int> v;
	Solution s;
	cout << s.singleNumberK(v, 3, 1) << endl;
	return 0;
}