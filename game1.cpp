#include <cstdio>
#include <cstring>

const int N = 120;

int check(bool *flag, int len) {
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < len; ++i) {
        if (flag[i] == false) {
            ++tmp;
            if (ans < tmp)
                ans = tmp;
        } else {
            tmp = 0;
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int k, len;
        char str[N];
        bool flag[N];
        scanf("%d%s", &k, str);
        len = strlen(str);
        int ans = 0;
        for (int i = 0; i < len; ++i)
            flag[i] = str[i] == '0' ? false : true;
        for (int i = 0; i < k - 1; ++i)
            flag[i] = !flag[i];
        for (int i = k - 1; i < len; ++i) {
            flag[i] = !flag[i];
            flag[i - k] = !flag[i - k];
            int tmp = check(flag, len);
            if (ans < tmp) ans = tmp;
        }
        printf("%d\n", ans);
    }
    return 0;
}
