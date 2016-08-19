#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
       int len = nums.size();
       vector<vector<int> > res;
       if(len < 3) return res;
       int ans = 0;
       sort(nums.begin(), nums.end());
       for(int i = 0; i < len - 2; i++) {
       		if(i > 0 && nums[i] == nums[i - 1]) continue;
       		int j = i + 1;
       		int k = len - 1;
       		while(j < k) {
       			ans = nums[i] + nums[j] + nums[k];
       			if(ans == 0) {
       				//res.push_back( vector<int>({nums[i], nums[j], nums[k]}) );
       				res.push_back({num[i], num[j], num[k]});
       				j++;
       				while(j < len && nums[j] == nums[j - 1]) j++;
       				k--;
       				while(k >= 0 && nums[k] == nums[k + 1]) k--;
       			}
       			else if(ans > 0) k--;
       			else j++;
       		}
       }
       return res;
    }
};

int main() {
	int arr[] = {-1, 0, 1, 2, -1, -4};
	Solution s;
	vector<int> par(arr, arr + 6);
	vector<vector<int> > res;
	res = s.threeSum(par);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i][0] << endl;
		cout << res[i][1] << endl;
		cout << res[i][2] << endl;
	}
	return 0;
}