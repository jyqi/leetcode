#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct params {
	string name;
	int need;
	int multi;
	int neg;
	vector<string> val;
};

void getVal(string input, vector<string> &val) {
	string tmp = "";
	for(int i = 0; i < input.size(); i++) {
    if(input[i] == ' ') {
        if(tmp.length() != 0) {
            val.push_back(tmp);
        }
        tmp = "";
    }
    else {
        tmp = tmp + input[i];   
    }
    }
    if(tmp.length() != 0) {
        val.push_back(tmp);
    }
}

void getCombine(const vector<string> &val, vector<string> &combine) {
	int len = val.size();
	int n = 1 << len;
	for(int i = 1; i < n; i++) {
		string tmp = "";
		for(int j = 0; j < len; j++) {
			int temp = i;
			if(temp & (1 << j)) {
				tmp = tmp + val[j];
				tmp = tmp + ",";
			}
		}
		tmp.erase(tmp.end() - 1);
		combine.push_back(tmp);
	}
}

void getRequests(params p, const vector<string> &val, vector<string> request) {
	string tmp;
	vector<string> combine;
	if(p.multi) {
		getCombine(val, combine);
	}
	if(combine.empty()) {
		combine = val;
	}
	if(p.neg) {
		int curLen = combine.size();
		for(int i = 0; i < curLen; i++) {
			string tmp = "-" + combine[i];
			combine.push_back(tmp);
		}	
	}
	for(int i = 0; i < combine.size(); i++) {
		tmp = p.name + "=";
		tmp = tmp + combine[i];
		request.push_back(tmp);
	}
}

bool comp(struct params &a, struct params &b) {
	return a.name < b.name;
}

void getRes(const struct params p[], const vector<vector<string> > requests, vector<string> &res, int beg, int end, string &cur) {
	if(beg > end) {
		if(cur[cur.length() - 1] == '&') {
			cur.erase(cur.end());
		}
		res.push_back(cur);
		return;
	}
	for(int i = 0; i < requests[beg].size(); i++) {
		if(beg < end) {
			string tmp = cur;
			if(!p[beg].need) {
				getRes(p, requests, res, beg + 1, end, cur);	
				cur = tmp;
			}
			cur = cur + requests[beg][i] + "&";
			getRes(p, requests, res, beg + 1, end, cur);
			cur = tmp;
		}
		else {
			string tmp = cur;
			if(!p[beg].need) {
				getRes(p, requests, res, beg + 1, end, cur);	
				cur = tmp;
			}
			cur = cur + requests[beg][i];
			getRes(p, requests, res, beg + 1, end, cur);	
			cur = tmp;
		}
	}
}

int main() {
	int N;
	cin >> N;
	params p[5];
	string input;
	vector<vector<string> > requests(5, vector<string>());
	for(int i = 0; i < N; i++) {
		cin >> p[i].name >> p[i].need >> p[i].multi >> p[i].neg;
		cin >> input;
		getVal(input, p[i].val);
	}
	sort(p, p + N, comp);
	for(int i = 0; i < N; i++) {
		getRequests(p[i], p[i].val, requests[i]);	
		/*for(int j = 0; j < requests[i].size(); j++) {
			cout << requests[i][j] << endl;
		}*/
	}
	vector<string> res;
	string cur;
	getRes(p, requests, res, 0, N - 1, cur);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}	
	return 0;
}