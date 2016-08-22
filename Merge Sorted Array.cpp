#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int len = m + n - 1;
        while(i >= 0 && j >= 0) {
        	if(nums1[i] > nums2[j]) {
        		nums1[len] = nums1[i];
        		len--;
        		i--;
        	}
        	else {
        		nums1[len] = nums2[j];
        		len--;
        		j--;
        	}
        }
        while(j >= 0) {
        	nums1[len] = nums2[j];
        	j--;
        	len--;
        }
        return;
    }
};

int main() {
	int arr[] = {1, 2, 3};
	vector<int> v(5, 0);
	v[0] = arr[0];
	v[1] = arr[1];
	v[2] = arr[2];
	vector<int> v2;
	v2.push_back(4);
	v2.push_back(5);
	Solution s;
	s.merge(v, 3, v2, 2);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}