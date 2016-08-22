#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int len = nums.size();
		for(int i = 0; i < len; i++) {
			if(nums[i] == val) {
				nums[i] = nums[len - 1];
				i--;
				len--;
			}
		}
		return len;        
    }
};

int main() {
	int arr[] = {3, 2, 2, 3};
	vector<int> v(arr, arr + 4);
	Solution s;
	cout << s.removeElement(v, 3) << endl;
	return 0;
}