#include "Model.h"
using namespace std;

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        if(A.empty()) {
            return 0;
        }
        long long index = 1, fac = 1;
        for(int i = A.size() - 1; i >= 0; i--) {
            int rank = 0;
            unordered_map<int, int> hash;
            ++hash[A[i]];
            for(int j = i + 1; j < A.size(); j++) {
                ++hash[A[j]];
                if(A[i] > A[j]) {
                    rank++;
                }
            }
            index += rank * fac / dupPerm(hash);
            fac *= (A.size() - i);
        }
        return index;
    }

    long long dupPerm(unordered_map<int, int> hash) {
        if(hash.empty()) {
            return 1;
        }
        long long dup  = 1;
        for(auto it = hash.begin(); it != hash.end(); it++) {
            dup *= fact(it->second);
        }
    }

    long long fact(int num) {
        long long val = 1;
        for(int i = 1; i <= num; i++) {
            val *= i;
        }
        return val;
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
