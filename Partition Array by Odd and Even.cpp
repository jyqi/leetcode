#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if(len < 2) return;
        int p = 0;
        int q = len - 1;
        while(p < q) {
        	while(p < q && nums[p] % 2) p++;
        	while(p < q && nums[q] % 2 == 0) q--;
        	if(p < q) {
        		int temp = nums[p];
        		nums[p] = nums[q];
        		nums[q] = temp;
        	}
        }
    }
};

int main() {
	int arr[] = {1, 2, 3, 4};
	vector<int> v(arr, arr + 4);
	Solution s;
	s.partitionArray(v);
	for(int i = 0; i < 4; i++) cout << v[i] << endl;
	return 0;
}