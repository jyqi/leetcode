#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
  		int end = s.size();
  		if(end == 0) return 0;
  		end = end - 1;
  		int res = 0;
  		while(end >= 0 && s[end] == ' ') end--;
  		while(end >= 0 && s[end] != ' ') {
  			end--;
  			res++;
  		}
  		return res; 
    }
};

int main() {
	string s = "Hello World";
	Solution ss;
	cout << ss.lengthOfLastWord(s) << endl;
	return 0;
}