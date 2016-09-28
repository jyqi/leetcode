#include <iostream>
using namespace std;

int res = 0;
int A[1005];
void dfs(int target, int n, int A[])
{
    if(target <= 0 || n < 0)return;

    if(target == A[n])
    {
        res++;
    }
    dfs(target - A[n], n-1, A);
    dfs(target, n-1, A);
}

int main()
{
    int n, sum;
    cin >> n >> sum;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    res = 0;
    dfs(sum, n - 1, A);
    cout << res << endl;
    return 0;
}