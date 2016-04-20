/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/


//A simple idea: using STL map to store the times of each number appears;
//output the majority element which appears more than n/2 times;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int i;
        int n = nums.size();
        for(i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            if(m[nums[i]] > n / 2) break;
        }
        return nums[i];
    }
};

// Moore Voting Algorithm
// Refer to: 
// http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html
int majorityElement(vector<int> &num) {
    int majority;
    int cnt = 0;
    for(int i=0; i<num.size(); i++){
        if ( cnt ==0 ){
            majority = num[i];
            cnt++;
        }else{
            majority == num[i] ? cnt++ : cnt --;
            if (cnt >= num.size()/2) return majority;
        }
    }
    return majority;

}