#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	if(nums1.empty() && nums2.empty()) return 0;
    	int len1 = nums1.size(), len2 = nums2.size();
    	if(nums1.empty()) {
    		return len2 % 2 == 0 ? (nums2[len2 / 2 - 1] + nums2[len2 / 2]) / 2.0 : nums2[len2 / 2];
    	}
    	if(nums2.empty()) {
    		return len1 % 2 == 0 ? (nums2[len1 / 2 - 1] + nums2[len1 / 2]) / 2.0 : nums2[len1 / 2];	
    	}
    	int len = len1 + len2;
    	return len % 2 == 0 ? (findMedian(nums1, 0, nums2, 0, len / 2) + findMedian(nums1, 0, nums2, 0, len / 2 + 1)) / 2.0 : findMedian(nums1, 0, nums2, 0, len / 2 + 1);
    }
private:
	int findMedian(vector<int> A, int aStart, vector<int> B, int bStart, int k) {
		if(aStart > A.size() - 1) {
			return B[bStart + k - 1];
		}
		if(bStart > B.size() - 1) {
			return A[aStart + k - 1];
		}
		if(k == 1) return A[aStart] < B[bStart] ? A[aStart] : B[bStart];
		int akey = aStart + k / 2 - 1 < A.size() ? A[aStart + k / 2 - 1] : INT_MAX;
		int bkey = bStart + k / 2 - 1 < B.size() ? B[bStart + k / 2 - 1] : INT_MAX;
		if(akey > bkey) {
			return findMedian(A, aStart, B, bStart + k / 2,  k - k / 2);
		}
		else {
			return findMedian(A, aStart + k / 2, B, bStart, k - k / 2);
		}
	}
};
int main() {
	int arr1[] = {1, 2, 3, 4, 5, 6};
	int arr2[] = {2, 3, 4, 5};
	vector<int> v1(arr1, arr1 + 6);
	//vector<int> v2(arr2, arr2 + 4);
	vector<int> v2;
	Solution s;
	cout << s.findMedianSortedArrays(v1, v2) << endl;
	return 0;
}