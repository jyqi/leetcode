#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> res;

void dfs(string s, int depth, int len) {
	//cout << depth << endl;
	if(depth == len) {
		for(int i = 0; i < res.size(); i++) {
			cout << res[i];
		}
		cout << endl;
		return;
	}
	
	for(int i = depth; i < len; i++) {
		char tmp = s[i];
		s[i] = s[depth];
		s[depth] = tmp;
		res.push_back(tmp);
		dfs(s, depth + 1, len);	
		tmp = s[i];
		s[i] = s[depth];
		s[depth] = tmp;
		res.pop_back();
	}
}

int main() {
	string s;
	cin >> s;
	int len = s.size();
	dfs(s, 0, len);
	return 0;
}