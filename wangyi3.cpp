#include <iostream>
#include <string>
using namespace std;

int Mod;
long long matrix[55][55];

long long howmany(string str) {
    long long result = 0;
    for (int i = 0; i < str.Length - 1; i++)
    {
        result += Cal(str, 0, i, i + 1, str.length() - 1);
        result -= Cal(str, 0, i, i + 2, str.length() - 1);
    }

    return (result % Mod + Mod) % Mod;
}

long Cal(string str, int s1, int e1, int s2, int e2)
{
    if (e1 < s1 || e2 < s2)
        return 0;

    int m = e1 - s1 + 1, n = e2 - s2 + 1;
    for (int i = s1; i <= e1; i++)
    {
        int index1 = i - s1 + 1;
        for (int j = s2; j <= e2; j++)
        {
            int index2 = j - s2 + 1;
            if (str[i] == str[j])
                matrix[index1][index2] = (matrix[index1 - 1][index2] + matrix[index1][index2 - 1] + 1) % Mod;
            else
                matrix[index1][index2] = (matrix[index1 - 1][index2] + matrix[index1][index2 - 1] - matrix[index1 - 1][index2 - 1]) % Mod;
        }
    }

    return matrix[m][n];
}

int main() {
    string s;
    cin >> s;
    Mod = 1000000007;
    cout << howmany(s) << endl;
    return 0;
}