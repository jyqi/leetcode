#include "Model.h"
using namespace std;

class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        //find nums[i] < nums[i + 1]
        if(nums.size() <= 1) {
            return;
        }
        int i, j;
        for(i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                break;
            }
            else if(i == 0) {
                reverse(nums, 0, nums.size() - 1);
                return;
            }
        }
        //find nums[i] < nums[j]
        for(j = nums.size() - 1; j > i; j--) {
            if(nums[i] < nums[j]) {
                break;
            }
        }
        //swap nums[i] and nums[j]
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        //reverse [i + 1, n - 1]
        reverse(nums, i + 1, nums.size() - 1);
    }

    void reverse(vector<int> &nums, int start, int end) {
    	for(int i = start, j = end; i < j; i++, j--) {
    		int temp = nums[i];
    		nums[i] = nums[j];
    		nums[j] = temp;
    	}
    }
};

int main() {
	Solution s;
	vector<int> res;
	int arr[] = {1, 3, 2};
	vector<int> v(arr, arr + 3);
	s.nextPermutation(v);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
    cout <<endl;
	return 0;
}
