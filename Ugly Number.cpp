#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
    	if(num == 0) return false;
        while(num != 1) {
        	if(num % 2 == 0) num = num / 2;
        	else if(num % 3 == 0) num = num / 3;
        	else if(num % 5 == 0) num = num / 5;
        	else return false;
        }
        return true;
    }
};

int main() {
	int arr[] = {1, 2, 4, 5, 7, 6, 8, 14, 28, 50};
	Solution s;
	for(int i = 0; i < 10; i++) {
		cout << s.isUgly(arr[i]) << endl; 
	}
	return 0;
}