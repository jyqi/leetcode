#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int olen = nums.size();      
      if(olen < 2) return olen;
      int nlen = 1;
      int ori = nums[0];
      for(int i = 1; i < olen; i++) {
        if(nums[i] == ori) continue;
        else {
          nums[nlen] = nums[i];
          ori = nums[i];
          nlen++;
        }
      }
      return nlen;
    }
};

int main() {
	int arr[] = {1, 1, 1, 2, 2, 3};
	vector<int> v(arr, arr + 6);
	Solution s;
	cout << s.removeDuplicates(v) << endl;
	return 0;
}