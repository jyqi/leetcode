#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

struct pairs {
	int index1;
	int index2;
	int sum;
	pairs(int a, int b, int val) {
		index1 = a; 
		index2 = b;
		sum = val;
	}
	bool operator < (const pairs& b) const {
		return sum > b.sum;
	}
};

class Solution {
public:
    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int> > res;
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(!len1 || !len2) return res;
        vector<vector<bool> > vis(len1, vector<bool>(len2, false));
        priority_queue<pairs> q;
        q.push(pairs(0, 0, nums1[0] + nums2[0]));
        vis[0][0] = true;
        int dx[] = {1, 0};
        int dy[] = {0, 1};
        while(k > 0 && !q.empty()) {
        	pairs cur = q.top();
        	q.pop();
        	k--;
        	int x = cur.index1, y = cur.index2;
        	res.push_back(make_pair(nums1[x], nums2[y]));
        	for(int i = 0; i < 2; i++) {
        		int nx = x + dx[i], ny = y + dy[i];
        		if(nx < len1 && ny < len2 && !vis[nx][ny]) {
        			q.push(pairs(nx, ny, nums1[nx] + nums2[ny]));
        			vis[nx][ny] = true;
        		}
        	}
        }
    	return res;
    }
};

int main() {
	int arr[] = {1, 1, 2};
	vector<int> a(arr, arr + 3);
	int arr1[] = {1, 2, 3};
	vector<int> b(arr1, arr1 + 3);
	vector<pair<int, int> > res;
	Solution s;
	res = s.kSmallestPairs(a, b, 100);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i].first << " " << res[i].second << endl;
	}
	return 0;

}