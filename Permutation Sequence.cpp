#include "Model.h"
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fac = vector<int>(n + 1, 1);
        for(int i = 1; i < n + 1; i++) {
            fac[i] = fac[i - 1] * i;
        }
        vector<int> nums;
        for(int i = 1; i < n + 1; i++) {
            nums.push_back(i);
        }
        vector<int> perm;
        for(int i = 0; i < n; i++) {
            int rank = (k - 1) / fac[n - i - 1];
            k = (k - 1) % fac[n - i - 1] + 1;
            perm.push_back(nums[rank]);
            nums.erase(remove(nums.begin(), nums.end(), nums[rank]), nums.end());
        }
        stringstream res;
        copy(perm.begin(), perm.end(), ostream_iterator<int>(res, ""));
        return res.str();
    }
};

int main() {
	Solution s;
	cout << s.getPermutation(3, 5) << endl;
	return 0;
}
