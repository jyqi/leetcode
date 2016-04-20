//很简单的一个素数打表题

class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        vector<bool> m(n, true);
        int count = 0;
        for(int i = 2; i *i < n; i++) {
            if(m[i]) {
                for(int j = i * i; j < n; j += i) {
                    m[j] = 0;
                }
            }
        }
        for(int i = 2; i < n; i++) {
            if(m[i]) count++;
        }
        return count;
    }
};

//O(n)的方法

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        vector<int> vis;
        int num = 0;
        for(int i = 2; i < n; i++) {
            if(prime[i]) {
                num++;
                vis.push_back(i);
            }
            for(int j = 0; j < vis.size(); j++) {
                if(vis[j] * i >= n) break;
                prime[vis[j] * i] = false;
                if(i % vis[j] == 0) break; // 最关键的在于寻找最小的质数因子，如果条件成立，则vis[j + 1]不是i * vis[j + 1]的最
                                           // 小的质数因子，因此可以跳出。即说明之前在vis[j]*i中已经遍历到了！
            }
        }
        
        return vis.size();
    }
};


//跳过所有的偶数的方法（36ms)
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        // cnt = 1 for number 2, because we do not count it next
        int cnt = 1;
        vector<bool> isprimes(n, true);
        

        // skip all even number
        for(int i = 3; i*i <= n; i+=2){
            if(isprimes[i] )
                // i is a odd number so, i*i + i, i*i + 3i... are even number, so we skip these number by doing j += 2*i
                for(int j = i*i; j < n; j+=2*i)
                    isprimes[j] = false;
        }

        // skip all even number
        for(int i = 3; i < n; i+=2){
            if(isprimes[i] == true)
                cnt++;
        }                
        return cnt;
    }
};