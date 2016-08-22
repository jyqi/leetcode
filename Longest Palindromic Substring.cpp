#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    	int len = s.size();
  		int dp[len][len];
  		memset(dp, 0, sizeof(dp));
  		int maxL = 0, start = 0, end = 0;
  		int i = 0, j = 0;
  		for(i = 0; i < s.size(); i++) {
  			for(j = 0; j < i; j++) {
  				dp[j][i] = (s[i] == s[j]) && (i - j < 2 || dp[j + 1][i - 1]);
  				if(dp[j][i] && maxL < (i - j + 1)) {
  					maxL = i - j + 1;
  					start = j;
  					end = i;
  				}
  			}
  			dp[i][i] = 1;	
  		}
  		return s.substr(start, end - start + 1);
  		
    }
};

int main() {
	string s = "abccb";
	Solution ss;
	cout << ss.longestPalindrome(s) << endl; 
	return 0;
}