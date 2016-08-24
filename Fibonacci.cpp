#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        vector<int> v(n, 0);
        v[0] = 0;
        v[1] = 1;
        for(int i = 2; i < n; i++) {
        	v[i] = v[i - 1] + v[i - 2];
        }
        return v[n - 1];
    }
};

int main() {
	Solution s;
	cout << s.fibonacci(10) << endl;
	return 0;
}