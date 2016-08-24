#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */

    int hashCode(string key,int HASH_SIZE) {
    	if(key.size() == 0) return 0;
    	long hashSum = 0;
    	for(int i = 0; i < key.size(); i++) {
    		hashSum = 33 * hashSum + key[i];
    		hashSum %= HASH_SIZE;
    	}
    	return (int)hashSum;
    }
    int hashCode_1(string key,int HASH_SIZE) {
        // write your code here
        if(key.size() == 0) return 0;
        long long hashSum = 0;
        for(int i = 0; i < key.size(); i++) {
        	hashSum += key[i] * solve(33, key.size() - i - 1, HASH_SIZE);
        	hashSum %= HASH_SIZE;
        }
        return (int)hashSum;
    }

    long long solve(int a, int n, int b) {
    	if(n == 1) return a % b;
    	else if(n == 0) return 1;
    	else {
    		long long product = solve(a, n / 2, b);
    		product = (product % b) * (product % b) % b;
    		//cout << "product: " << product << endl;
    		if(n % 2 == 0) return product;
    		else return ((product % b) * (a % b)) % b;
    	}
    }
};

int main() {
	Solution s;
	cout << s.hashCode("Wrong answer or accepted?", 1000000007) << endl;
}