#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
  		if(x <= 0) return x;
  		unsigned long long start = 1, end = x;
  		unsigned long long target = x;
  		while(start + 1 < end) {
  			unsigned long long mid = start + (end - start) / 2;
  			if(mid * mid == target) return mid;
  			else if(mid * mid < target) start = mid;
  			else end = mid; 
  		}      
  		return start;
    }
};

int main() {
	Solution s;
	cout << s.mySqrt(140) << endl;
	return 0;
}