#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define For(i, a, b) for(int i = a; i <= b; i++)
#define int long long

const int N = 5e5 + 5;
using namespace std;

int n, m;
struct node {
    char ch[12];
} s[N];
int f0[N], f1[N];
// f0: step from 1 to i
// f1: step from i to n

signed main() {
    cin >> n >> m;
    For(i, 1, n) scanf("%s", s[i].ch + 1);
    memset(f0, 0x3f3f3f3f, sizeof f0);
    memset(f1, 0x3f3f3f3f, sizeof f1);
    f0[1] = f1[n] = 0;
    For(i, 1, n) For(j, i - 10, i - 1) {
        if(i - j > m) continue;
        if(s[j].ch[i - j] == '1')
            f0[i] = min(f0[i], f0[j] + 1);
    }
    for(int i = n; i >= 1; i--) 
        for(int j = i + 1; j <= i + 10; j++) {
            if(j - i > m) continue;
            if(s[i].ch[j - i] == '1')
                f1[i] = min(f1[i], f1[j] + 1);
        }
    // For(i, 1, n) cout << f0[i] << " ";
    // puts("");
    For(k, 2, n - 1) {
        int mn = 0x3f3f3f3f;
        For(pre, k - 10, k - 1) For(nxt, k + 1, k + 10) {
            if(nxt - pre > m) continue;
            if(s[pre].ch[nxt - pre] == '1')
                mn = min(mn, f0[pre] + 1 + f1[nxt]);
        }
        if(mn < 100000) cout << mn << " ";
        else cout << "-1" << " ";
    }
    return 0;
}