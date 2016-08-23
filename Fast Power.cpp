#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
    	if(n == 1) {
    		return a % b;
    	}
    	else if(n == 0) {
    		return 1 % b;
    	}
    	else if(0 > n) {
    		return -1;
    	}
        // write your code here
        long long product =  fastPower(a, b, n / 2;)
    }
};