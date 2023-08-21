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

int t, n, k;
int a[2000005];
signed main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        For(i, 1, n) a[i] = read();
        int moved = 0, tot = 0;
        For(i, 1, n) {
            if(a[i] != i - moved) {
                moved ++;
                tot ++;
            }
        }
        if(tot == 0) puts("0");
        else cout << (tot - 1) / k + 1 << '\n';
    }
    return 0;
}