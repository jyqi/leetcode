#include <cstdio>
#include <cstring>

const int N = 1010;

int compare(int x, int y) {
    return x < y ? x : y;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, l;
        int array[N];
        bool flag[N];
        int method = 0;
        scanf("%d%d", &n, &l);
        for (int i = 0; i < l; ++i) {
            scanf("%d", array + i);
        }
        for (int i = 0; i < compare(n, l); ++i) {
            bool isB = false;
            memset(flag, false, sizeof(bool) * (n + 1));
            int j = 0;
            for (j = 0; j < i && isB == false; ++j) {
                if (flag[array[j]] == true) {
                    isB = true;
                    ++method;
                } else {
                    flag[array[j]] = true;
                }
            }

            for (; j + n < l && isB == false; j += n) {
                memset(flag, false, sizeof(bool) * (n + 1));
                for (int k = j; k < j + n && isB == false; ++k) {
                    if (flag[array[k]] == true) {
                        isB = true;
                        ++method;
                    } else {
                        flag[array[k]] = true;
                    }
                }
            }
            memset(flag, false, sizeof(bool) * (n + 1));
            for (; j < l && isB == false; ++j) {
                if (flag[array[j]] == true) {
                    isB = true;
                    ++method;
                } else {
                    flag[array[j]] = true;
                }
            }
        }
        if (method == compare(n, l)) printf("B\n");
        else printf("CAN'T DECIDE\n");
    }

    return 0;
} 