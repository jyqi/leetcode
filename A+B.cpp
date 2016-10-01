#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        //if(b == 0) return a;
        int carry = (a & b) << 1;
        int val = (a ^ b); 
        if(carry != 0) {
        	val = aplusb(val, carry);
        }
        return val;
    }
};

int main() {
	Solution s;
	cout << s.aplusb(1, 2) << endl;
	return 0;
}