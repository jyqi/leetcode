#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        int ones = ~0;
        int mask = 0;
        if(j < 31) {
        	int left = ones << (j + 1);
	        int right = ((1 << i) - 1);
	        mask = left | right;	
        }
        else {
        	mask = (1 << i) - 1;
        }
        
        return (n & mask) | (m << i);
    }

    int updateBits(int n, int m, int i, int j) {
    	int ones = ~0;
    	int bit = 8 * sizeof(n);
    	unsigned int mask = ones << (bit - (j - i + 1));
    	mask >> (bit - j - 1);
    	return (n & ~(mask)) | (m << i);
    }
};