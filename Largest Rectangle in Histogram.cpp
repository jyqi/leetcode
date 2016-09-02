#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height)
    {
        if (height.size() == 0) return 0;
        stack<int> helper;
        int res = 0;
        height.push_back(0);
        for (int i=0; i<height.size(); i++){
            if (helper.empty() || height[helper.top()] <= height[i] ) {
                helper.push(i);
            }
            else{
                while(!helper.empty() && height[helper.top()] > height[i]){
                    int tmp = helper.top();
                    cout << height[tmp] << endl;
                    helper.pop();
                    if (!helper.empty()){
                        //前一点不一定与当前点紧挨着，因此之前先pop，然后再top。
                        int pre = helper.top();
                        res = max(res, height[tmp] * (i - pre - 1));

                    }
                    else {
                        res = max(res, height[tmp] * (i));
                    }
                    cout << res << endl;
                }
                helper.push(i);
            }
        }
        return res;
    }
};

int main() {
	int arr[] = {1, 2, 5, 3};
	std::vector<int> v(arr, arr + 4);
	Solution s;
	cout << s.largestRectangleArea(v) << endl;
	return 0;
}