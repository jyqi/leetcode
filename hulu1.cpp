#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string str1,string str2)
{
    return str1.size() > str2.size();
}


bool canBuild(string &s, bool isOriginalWord, map<string, bool> &mp) {
    if (mp.find(s) != mp.end() && !isOriginalWord) return mp[s];
    for (int i = 1; i < s.length(); ++i) {
        string left = s.substr(0, i);
        string right = s.substr(i);
        if (mp.find(left) != mp.end() && mp[left] && canBuild(right, false, mp)) {
            return true;
        }
    }
    mp[s] = false;
    return false;
}

string getLongest(vector<string> str) {
    map<string, bool> mp;
    for (int i = 0; i < str.size(); i++) { 
        mp[str[i]] = true;
    }
    sort(str.begin(), str.end(), comp);

    for (int i = 0; i < str.size(); i++) {
        if (canBuild(str[i], true, mp)) return str[i];
    }
    return "";
}

int main() {
    vector<string> s;
    string input;
    getline(cin, input);
    string tmp = "";
    for(int i = 0; i < input.size(); i++) {
        if(input[i] == ' ') {
            if(tmp.length() != 0) {
                //cout << tmp << "111" << endl;
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
    cout << getLongest(s) << endl;
    return 0;
}