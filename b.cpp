#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	int n, k;
	vector<int> card(205, 0);
	vector<int> left(105, 0);
	vector<int> right(105, 0);
	while(T--) {
		cin >> n >> k;
		for(int i = 0; i < 2 * n; i++) {
			cin >> card[i];
			if(i < n) left[i] = card[i];
			else right[i - n] = card[i];
		}
		while(k--) {
			for(int i = n - 1; i >= 0; i--) {
				card[2 * i + 1] = right[i];
				card[2 * i] = left[i];
			}
			for(int i = 0; i < 2 * n; i++)	{
				if(i < n) left[i] = card[i];
				else right[i - n] = card[i];
			}
		}
		for(int i = 0; i < 2 * n - 1; i++) {
			cout << card[i] << " ";
		}
		cout << card[2 * n - 1] << endl;

	}
	return 0;
}