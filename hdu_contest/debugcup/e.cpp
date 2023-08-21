#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for(int i = a; i <= b;i ++)
using namespace std;
int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f * x;
}

void write(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) write(x / 10);
    putchar('0' + x % 10);
    return;
}

int t;
int f[1005], a[1005];

signed main() {
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        memset(f, 0, sizeof f);
        For(i, 1, n) a[i] = read();
        For(i, 1, n) {
            For(j, max(0ll, i - k), i - 1)
                f[i] = max(f[i], f[j] + a[i]);
        }
        int mx = 0;
        For(i, 1, n) mx = max(mx, f[i]);
        cout << mx << '\n';

    }
    return 0;
}