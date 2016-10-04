#include "Model.h"
using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        if(A.empty()) {
            return 0;
        }
        long long index = 1, fac = 1;
        for(int i = A.size() - 1; i >= 0; i--) {
            int rank = 0;
            for(int j = i + 1; j < A.size(); j++) {
                if(A[i] > A[j]) {
                    rank++;
                }
            }
            index += rank * fac;
            fac *= (A.size() - i);
        }
        return index;
    }
};

int main() {
	Solution s;
	vector<int> res;
	int arr[] = {3, 1, 2};
	vector<int> v(arr, arr + 3);
	cout << s.permutationIndex(v) << endl;
	return 0;
}
