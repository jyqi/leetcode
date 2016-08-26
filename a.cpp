#include <iostream>
#include <map>
#include <cstdlib>
#include <stdio.h>
#include <vector>
//#include <pair>
using namespace std;

int main() {
	int n;
	int x1, y1, x2, y2;
	map<pair<int, int>, vector<pair<int, int> > > points;
	cin >> n;
	map<pair<int, int>, vector<pair<int, int> > >::iterator it1;
	map<pair<int, int>, vector<pair<int, int> > >::reverse_iterator it2;
	for(int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		pair<int, int> p1 = make_pair(x1, y1);
		pair<int, int> p2 = make_pair(x2, y2);
		points[p1].push_back(p1);
		points[p2].push_back(p2);
	}
	for(it1 = points.begin(); it1 != points.end(); it1++) {
		for(it2 = points.rbegin()·; it2 != points.rend(); it2++) {
			int count = 0;
			for(int i = 0; i < it1->second.size(); i++) {
				for(int j = 0; j < it2->second.size(); j++) {
					if(it1->second[i].first == it2->second[j].first && it1->second[i].second == it2->second[j].second && count) {
						cout << it1->first.first << " " << it1->first.second <<  " " << it2->first.first << " " << it2->first.second << endl;
						return 0;
					}
					else if(it1->second[i].first == it2->second[j].first && it1->second[i].second == it2->second[j].second) count++; 
				}
			}
		}
	}
	return 0;

}