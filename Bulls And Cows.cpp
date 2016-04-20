//a simple simulation problem
//the key point is we should travel all the secret string. And get the count of each number appear.


class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> sec(10, 0);
        int A = 0;
        int B = 0;
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i]) {
                A++;
            }
            else sec[secret[i] - '0']++;
        }
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] != guess[i] && sec[guess[i] - '0'] != 0) {
                B++;
                sec[guess[i] - '0']--;
            }
        }
        string res = to_string(A) + "A" + to_string(B) + "B";
        return res;
    }
};