#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
    	if(n < 0) return 0;
  		long long fac = 5;	//注意溢出！
  		int res = 0;
  		while(n / fac) {
  			res += n / fac;
  			n /= 5;
  		}      
  		return res;
    }
    
    int trailingZeroes(int n) {
    long power = 5;
    long sum = 0;
    while(power<=n){
        sum +=  n/power ;
        power = (power << 2) + power;
    }
    return sum;
}
};

int main() {
	int a = 11;
	Solution s;
	cout << s.trailingZeroes(a) << endl;
	return 0;
}