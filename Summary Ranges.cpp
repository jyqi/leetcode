#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        string range;
        int begin;
        int end;
        vector<string> res;
        if(nums.empty()) return res;
        begin = end = nums[0];
        for(int i = 1; i < nums.size(); i++) {
        	if(nums[i] - end == 1) end = nums[i];
        	else {
        		stringstream ss;
        		if(begin != end) {
        			ss << begin;
        			ss << "->";
        			ss << end;
        		}
        		else ss << begin;
        		res.push_back(ss.str());
        		begin = end = nums[i]; 	        		
        	}
        }
        stringstream ss;
		if(begin != end) {
			ss << begin;
			ss << "->";
			ss << end;
		}
		else ss << begin;
		res.push_back(ss.str());
		return res;
    }
};

int main() {
	Solution s;
	int arr[] = {0, 1, 2, 4, 5, 7};
	vector<int> v(arr, arr + 6);
	vector<string> res;
	res = s.summaryRanges(v);
	for(int i = 0; i < res.size(); i++) cout << res[i] << endl;
	return 0;
}
