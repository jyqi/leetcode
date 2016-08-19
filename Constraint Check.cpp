#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N, T;
	int var[26];
	string cons[20];
	bool flag[26];
	cin >> N;
	int count = 0;
	for(int i = 0; i < 26; i++) flag[i] = false;
	for(int i = 0; i < N; i++) {
		cin >> cons[i];
		//cout << cons[i] << endl;
		for(int j = 0; j < cons[i].size(); j++) {
			if(cons[i][j] >= 'A' && cons[i][j] <= 'Z' && !flag[cons[i][j] - 'A']) {
				count++;
				//cout << cons[i][j] << endl;
				flag[cons[i][j] - 'A'] = true;
			}
		}
	}
	//cout << count << endl;
	cin >> T;
	for(int i = 0; i < T; i++) {
		for(int t = 0; t < 26; t++) var[t] = 0;
		char c;
		int val;
		for(int j = 0; j < count; j++) {
			cin >> c >> val;
			var[c - 'A'] = val;
		}
		bool satisfy = true;
		for(int j = 0; j < N; j++) {
			if(!satisfy) break;
			//cout << cons[j] << endl;
			for(int k = 0; k < cons[j].size(); k++) {
				if(cons[j][k] == '<' && cons[j][k + 1] != '=') {
					int p = k - 1;
					int left = 0;
					int right = 0;
					if(cons[j][p] >= 'A' && cons[j][p] <= 'Z') {
						left = var[cons[j][p] - 'A'];
					}
					else {
						int wei = 1;
						while(p >= 0 && cons[j][p] >= '0' && cons[j][p] <= '9') {
							left = left + (cons[j][p] - '0') * wei;
							wei = wei * 10;
							p--;
						}
					}
					//cout << left << endl;
					int q = k + 1;
					if(cons[j][q] >= 'A' && cons[j][q] <= 'Z') {
						right = var[cons[j][q] - 'A'];
					}
					else {
						while(q < cons[j].size() && cons[j][q] >= '0' && cons[j][q] <= '9') {
							right = right * 10 + (cons[j][q] - '0');
							q++;
						}
					}
					//cout << right << endl;
					if(left < right) continue;
					else satisfy = false;
				}
				else if(cons[j][k] == '<' && cons[j][k + 1] == '=') {
					int p = k - 1;
					int left = 0;
					int right = 0;
					if(cons[j][p] >= 'A' && cons[j][p] <= 'Z') {
						left = var[cons[j][p] - 'A'];
					}
					else {
						int wei = 1;
						while(p >= 0 && cons[j][p] >= '0' && cons[j][p] <= '9') {
							left = left + (cons[j][p] - '0') * wei;
							wei = wei * 10;
							p--;
						}
					}
					//cout << left << endl;
					int q = k + 2;
					if(cons[j][q] >= 'A' && cons[j][q] <= 'Z') {
						right = var[cons[j][q] - 'A'];
					}
					else {
						while(q < cons[j].size() && cons[j][q] >= '0' && cons[j][q] <= '9') {
							right = right * 10 + (cons[j][q] - '0');
							q++;
						}
					}
					//cout << right << endl;
					if(left <= right) continue;	
					else satisfy = false;
				}
				if(!satisfy) break;
			}
		}
		if(satisfy) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}