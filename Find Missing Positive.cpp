#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 1;
        //int i = 0;
        for(int i = 0; i < len; i++) {
        	while(nums[i] > 0 && nums[i] != i + 1 && nums[i] <= len && nums[i] != nums[nums[i] - 1]) {
        		int temp = nums[nums[i] - 1];
        		nums[nums[i] - 1] = nums[i];
        		nums[i] = temp;
        	}
        }
        for(int i = 0; i < len; i++) {
        	if(nums[i] != i + 1) return i + 1;
        }
        return len + 1;
    }
};

int main() {
	int arr[] = {3, 4, -1, 1};
	vector<int> v(arr, arr + 4);
	Solution s;
	cout << s.firstMissingPositive(v) << endl;
	return 0;
}