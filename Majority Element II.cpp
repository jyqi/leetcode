#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		int cnt1 = 0, cnt2 = 0, maj1 = 0, maj2 = 0;
		int len = nums.size();
		vector<int> res;
		//cout << 1 << endl;
		for(int i = 0; i < len; i++) {
			if(cnt1 == 0 && nums[i] != maj2) {
				maj1 = nums[i];
				cnt1 = 1;
			}
			else if(nums[i] == maj1) {
				cnt1++;
			}
			else if(cnt2 == 0 && nums[i] != maj1) {
				maj2 = nums[i];
				cnt2 = 1;
			}
			else if(nums[i] == maj2) {
				cnt2++;
			}
			else {
				cnt1--;
				cnt2--;
			}

		}

		cnt1 = cnt2 = 0;
		for(int i = 0; i < len; i++) {
			if(nums[i] == maj1) cnt1++;
			else if(nums[i] == maj2) cnt2++;
		}
		if(cnt1 > len / 3) res.push_back(maj1);
		if(cnt2 > len / 3) res.push_back(maj2);
		return res;
    }
};

int main() {
	int arr[] = {1, 2, 1, 2, 1, 3, 3};
	Solution s;
	vector<int> v(arr, arr + 7);
	vector<int> res;
	res = s.majorityElement(v);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}