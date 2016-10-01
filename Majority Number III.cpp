#include <iostream>
#include <vector>
using namespace std;

struct element {
	int val;
	int count;
	element(int x = 0, int y = 0) : val(x), count(y) {}
};
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        int len = nums.size();
        if(len == 0) return -1;
        vector<element> m(k - 1, element());
        for(int i = 0; i < len; i++) {
        	int l;
        	for(l = 0; l < k - 1; l++) {
        		if(m[l].val == nums[i]) {
        			m[l].count++;
        			break;
        		}
        	}
        	if(l == k - 1) {
        		for(l = 0; l < k - 1; l++) {
        			if(m[l].count == 0) {
        				m[l].val = nums[i];
        				m[l].count++;
        				break;
        			}
        		}
        		if(l == k - 1) {
        			for(l = 0; l < k - 1; l++) {
        				m[l].count--;
        			}
        		}
        	}
        }
        for(int j = 0; j < k - 1; j++) {
        	m[j].count = 0;
        }
        for(int i = 0; i < len; i++) {
        	for(int j = 0; j < k - 1; j++) {
        		if(m[j].val == nums[i]) m[j].count++;
        		if(m[j].count > len / k) return m[j].val;
        	}
        }
        return -1;
    }
};

int main() {
	int arr[] = {3,1,2,3,2,3,3,4,4,4};
	std::vector<int> v(arr, arr + 10);
	Solution s;
	cout << s.majorityNumber(v, 3) << endl; return 0;
}
