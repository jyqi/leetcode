#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
     	if(pushV.empty()) {
            return true;
        }   
        stack<int> help;
        int j = 0;
        for(int i = 0; i < popV.size(); i++) {
            if(help.empty() || help.top() != popV[i]) {
				for(; j < pushV.size(); j++) {
                    if(pushV[j] != popV[i]) {
                        cout << popV[i] << " " << pushV[j] << endl;
                        help.push(pushV[j]);
                    }
                    else {
                        j++;
                        break;
                    }
                }                
            }
            else {
                cout << help.top() << endl;
                help.pop();
            }
        }
        if(help.empty()) return true;
        return false;
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int arr1[] = {4, 5, 3, 2, 1};
    std::vector<int> v1(arr, arr + 5);
    std::vector<int> v2(arr1, arr1 + 5);
    Solution s;
    cout << s.IsPopOrder(v1, v2) << endl;
}