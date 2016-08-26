#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    int idx, value;
};

list<node> l;
vector<node> v;

void init(int n) {
    l.clear();
    v.clear();
    for (int i = 1; i <= n; ++i) {
        node tmp;
        tmp.idx = i;
        l.push_back(tmp);
    }
}

void process(int n) {
    int i = 1;
    bool flag = false;
    list<node>::iterator itor = l.begin();

    while (!l.empty()) {
        if (flag == false) {
            itor++;
        }
        else {
            if (itor == l.end()) {
                itor = l.begin();
            }
            (*itor).value = i++;
            v.push_back(*itor);
            itor = l.erase(itor);
            if (itor == l.end()) {
                itor = l.begin();
            }
        }
        flag = !flag;
    }
}

bool cmp(const node & a, const node & b) {
    return a.idx < b.idx;
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        init(n);
        process(n);
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size() - 1; ++i) {
            cout << v[i].value << " ";
        }
        cout << v[v.size() - 1].value << endl;
    }

    return 0;
}