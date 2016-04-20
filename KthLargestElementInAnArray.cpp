/********************************************************************************** 
 * 
 * Find the kth largest element in an unsorted array. 
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * 
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
 *               
 **********************************************************************************/


//Idea of quicksort

class Solution {
public:
    int partition(vector<int> &nums, int begin, int end) {
        int pivot = nums[begin];
        int l = begin + 1;
        int r = end;
        while(l <= r) {
            if(nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
        }
        swap(nums[begin], nums[r]);
        return r;
    }
    
    int qsort(vector<int>& nums, int k) {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end) {
            int par = partition(nums, begin, end);
            if(par == k - 1) return nums[par];
            else if(par < k - 1) begin = par + 1;
            else end = par - 1;
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return qsort(nums, k);
    }
};

//Using STL to solve
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};