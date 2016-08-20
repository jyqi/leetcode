#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    bool Cut(vector<int> L, int k, int x) {
    	int sum = 0;
    	for(int i = 0; i < L.size(); i++) {
    		sum += L[i] / x;
    	}
    	return sum >= k;
    }
    int woodCut(vector<int> L, int k) {
        // write your code here
        if(L.empty()) return 0;
        int start = 0, end = INT_MAX;
        while(start + 1 < end) {
        	int mid = start + (end - start) / 2;
        	if(Cut(L, k, mid)) {
        		start = mid;
        	}
        	else end = mid;
        }
        return start;
    }
};

int main() {
	int arr[] = {232, 124, 456};
	vector<int> v(arr, arr + 3);
	Solution s;
	cout << s.woodCut(v, 7) << endl;
	return 0;
}