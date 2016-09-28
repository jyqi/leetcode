#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
    	if(points.empty()) {
    		return 0;
    	}    
    	int res = 0;
    	map<float, int> hash;
    	for(int i = 0; i < points.size(); i++) {
    		hash.clear();
    		hash[INT_MIN] = 0;
    		int dup = 1;
    		for(int j = 0; j < points.size(); j++) {
    			if(i == j) continue;
    			if(points[i].x == points[j].x && points[i].y == points[j].y) {
    				dup++;
    				continue;
    			}
    			float slope;
    			if(points[i].x == points[j].y) {
    				slope = INT_MAX;
    			}
    			else {
    				slope = (points[j].y - points[i].y) * 1.0 / (points[j].x - points[i].x);
    			}
    			hash[slope]++;
    		}
    		for(map<float, int>::iterator it = hash.begin(); it != hash.end(); it++) {
    			res = max(res, it->second + dup);
    		}
    	}
    	return res;
    }
};

