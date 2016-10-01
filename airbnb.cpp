#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * Complete the function below.
 */
string extract_id(string str) {
    string tmp = "";
    for(int i = 0; str[i] != ','; i++) {
        tmp = tmp + str[i];
    }
    return tmp;
}

vector < string > paginate(int num, vector < string > results) {
    list<string> mylist;
    vector<string> res;
    set<string> hash;
    list<string>::iterator it;
    for(int i = 0; i < results.size(); i++) {
        mylist.push_back(results[i]);
    }
    while(!mylist.empty()) {
        int curNum = 0;
        hash.clear();
        for(it = mylist.begin(); it != mylist.end();) {
            string host_id = extract_id(*it);
            //cout << host_id << endl;
            if(hash.find(host_id) != hash.end()) {
                it++;
            }
            else {
                hash.insert(host_id);
                res.push_back(*it);
                it = mylist.erase(it);
                curNum++;
                if(curNum == num) {
                    break;
                }
                continue;
            }
        }
        it = mylist.begin();
        while(it != mylist.end() && curNum < num) {
            res.push_back(*it);
            it = mylist.erase(it);
            curNum++;
            //it++;
        }
        res.push_back("");
    }
    return res;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    vector < string > res;
    int _num;
    cin >> _num;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    
    int _results_size = 0;
    cin >> _results_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _results;
    string _results_item;
    for(int _results_i=0; _results_i<_results_size; _results_i++) {
        getline(cin, _results_item);
        _results.push_back(_results_item);
    }
    
    res = paginate(_num, _results);
    for(int res_i=0; res_i < res.size(); res_i++) {
        fout << res[res_i] << endl;;
    }
    
    fout.close();
    return 0;
}
