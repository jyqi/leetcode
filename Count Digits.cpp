#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
     int count(int k, int n, char d, int pos, int len) {
     	int num = d - '0';
     	long base = pow(10, pos);
     	long base10 = base * 10;
     	int down = (n / base10) * base;
     	int up = down + base;
     	int right = n % base;
     	//cout << num << " " << down << " " << up << " " << right << endl;
     	//cout << base << " " << base10 << endl;
     	if(num < k) {
     		return down;
     	}
     	else if(num == k) {
     		return down + right + 1;
     	}
     	return up;
     }

    int digitCounts(int k, int n) {
        // write your code here
        if(n < 0) return -1;
        if(k == 0 && n == 0) return 1;
        vector<char> v;
        int tmp = n;
        while(tmp) {
        	v.push_back(char('0' + tmp % 10));
        	tmp /= 10;
        }
        int res= 0;
        int len = v.size();
        for(int i = 0; i < len; i++) {
        	res += count(k, n, v[i], i, len);
        }
        //cout << res << endl;
        if(k == 0) {
        	for(int i = 1; i < len; i++) {
    			res -= pow(10, i);	
    		}    	
        }
        return res;
    }

    int digitCounts1(int k, int n) {
    	int count = 0;
    	char ck = (char)(k + '0');
    	vector<char> v;
    	for(int i = k; i <= n; i++) {
    		v.clear();
    		int tmp = i;
    		while(tmp) {
    			v.push_back(char('0' + tmp % 10));
        		tmp /= 10;
    		}	
    		for(int j = 0; j < v.size(); j++) {
    			if(v[j] == ck) count++;
    		}
    	}
    	return count;
    }
};

int main() {
	int k = 0;
	int n = 9;
	Solution s;
	cout << s.digitCounts(k, n) << endl;
	return 0;
}