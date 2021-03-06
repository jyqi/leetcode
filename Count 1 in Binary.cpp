#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        int count = 0;
       	while(num) {
       		num &= (num - 1);
       		count++;
       	}
       	return count;
    }
};

int main() {
	Solution s;
	cout << s.countOnes(1023) << endl;
	return 0;
}