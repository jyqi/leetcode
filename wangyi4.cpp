#include <iostream>
#include <string>
using namespace std;

bool judge(string str, int s1, int e1, int s2, int e2) {
	if (e1 < s1 || e2 < s2) {
        return 0;
	}
	bool flag = false;
	while(s1 <= e1 && s2 <= e2) {
		if(str[s1] != str[s2]) {
			return false;
		}
		s1++;
		s2++;
	}
    return true;
}

int solve(string str) {
	int res = 0;
    for (int i = 0; i < str.length(); i++)
    {
    	for(int j = 0; j < str.length(); j++) {
    		if(judge(str, i, j, j + 1, str.length() - 1)) {
    			res++;
    		}	
    	}
    }
    return res;
}

int main() {
	string str;
	cin >> str;
	cout << solve(str) << endl;
	return 0;
}