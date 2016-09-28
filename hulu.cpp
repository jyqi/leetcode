#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string str1,string str2)
{
    return str1.size() < str2.size();
}

bool isMatch(vector<string>& str,string s,int k) 
{
    for(int i = k-1;i >= 0; i--)
    {
        if(str[i] == s)
            return true;
        if(str[i].size() < s.size())
            break;
    }
    for(int i = 1; i < s.size(); i++)
    {
        if(isMatch(str,s.substr(0,i), k) && isMatch(str,s.substr(i),k))
            return true;
    }
    return false;
}

int main() {
	vector<string> s;
	string input;
	getline(cin, input);
	string tmp;
	for(int i = 0; i < input.size(); i++) {
		if(input[i] == ' ') {
			//cout << tmp << endl;
			if(tmp.length() != 0) {
				s.push_back(tmp);
			}
			tmp = "";
		}
		else {
			tmp = tmp + input[i];	
		}
	}
	if(tmp.length() != 0) {
		s.push_back(tmp);
	}
	sort(s.begin(),s.end(),comp);
	string res;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if(isMatch(s, s[i], i))
        {
        	res = s[i];
            break;
        }
    }
    cout << res << endl;
	return 0;
}