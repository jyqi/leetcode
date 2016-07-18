#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

struct bound{
	int min;
	int max;
	bool flag;
	bound() {
		min = INT_MAX;
		max = INT_MIN;
		flag = false;
	}
};
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int nmin = INT_MAX, nmax = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
        	if(nmin > nums[i]) nmin = nums[i];
        	if(nmax < nums[i]) nmax = nums[i];
        }
        cout << "max = " << nmax << " min = " << nmin << endl;
        int len = (nmax - nmin) / nums.size() + 1;
        if(nmax == nmin) return 0;
        cout << "len = " << len << endl;
        unordered_map<int, bound> hash;
        for(int i = 0; i < nums.size(); i++) {
        	int index = nmin + len * ((nums[i] - nmin) / len);
        	hash[index].flag = true;
        	if(hash[index].min > nums[i]) hash[index].min = nums[i];
        	if(hash[index].max < nums[i]) hash[index].max = nums[i];
        	cout << "index = " << index << " min = " << hash[index].min << " max = " << hash[index].max << endl;  
        }
        int gap;
        int lower;
        bool uplower = false;
        if(hash[nmin].flag) {
        	gap = hash[nmin].max - hash[nmin].min;
        	lower = hash[nmin].max;
        	uplower = true;
        }
        else gap = 0;
        for(int i = nmin + len; i <= nmax; i = i + len) {
        	cout << "lower = " << lower << endl;
        	if(hash[i].flag) {
        		if(!uplower) {
        			lower = hash[i].min;
        			uplower = true;
        		}
    			if(gap < hash[i].min - lower) gap = hash[i].min - lower;
    			lower = hash[i].min;
    			if(gap < hash[i].max - lower) gap = hash[i].max - lower;
    			lower = hash[i].max;
        	}
        	cout << "gap = " << gap << endl;
        }
        return gap;
    }
};

class Solution {
public:
    int maximumGap(vector<int> &num) {
       if (num.size() < 2) return 0;
        //遍历一遍，找出最大最小值
        int maxNum = num[0];
        int minNum = num[0];
        for (int i : num) {
            maxNum=max(maxNum,i);
            minNum=min(minNum,i);
        }
        // 每个桶的长度len,向上取整所以加+
        int len = (maxNum - minNum) / num.size() + 1;
        
        //桶的个数:(maxNum - minNum) / len + 1,每个桶里面存储属于该桶的最大值和最小值即可，注意这里的最大最小值是局部的
        vector<vector<int>> buckets((maxNum - minNum) / len + 1);
        for (int x : num) {
            int i = (x - minNum) / len;
            if (buckets[i].empty()) {
                buckets[i].reserve(2);
                buckets[i].push_back(x);
                buckets[i].push_back(x);
            } else {
                if (x < buckets[i][0]) buckets[i][0] = x;
                if (x > buckets[i][1]) buckets[i][1] = x;
            }
        }
        //gap的计算，For each non-empty buckets p, find the next non-empty buckets q, return min（ q.min - p.max ）
        int gap = 0;
        int prev = 0;
        for (int i = 1; i < buckets.size(); i++) {
            if (buckets[i].empty()) continue;
            gap = max(gap, buckets[i][0] - buckets[prev][1]);
            prev = i;
        }
        return gap;
    }
};

int main() {
	int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
	//vector<int> v(arr, arr + 8);
	//int arr[] = {1,1,1,1,1,5,5,5,5,5};
	vector<int> v(arr, arr + 8);
	Solution s;
	s.maximumGap(v);
}