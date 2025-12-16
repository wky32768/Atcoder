#include <bits/stdc++.h>

#define For(i, a, b) for(int i = a;i <= b;i++)

using namespace std;

const int N = 200005;

int t, n, k, a[N], blk[N], len[N];

bool ok(int l, int r, int k) {
    if(k == 1) {
        bool flag = 1;
        For(i, l + 1, r) if(a[i] != a[l]) return 0;
        return 1;
    } else if(k == 2) {
        // 111222
        int blocknum = 0, last = l;
        For(i, l, r) if(a[i] != a[i - 1] || i == l)
            blk[++blocknum] = a[i], len[blocknum - 1] = i - last, last = i;
        len[blocknum] = r - last + 1;
        // For(i, 1, blocknum) {
        //     cout << "debug " << blk[i] << " " << len[i] << '\n';
        // }
        if(blocknum <= 2) return 1;
        if(blocknum % 2) return 0;
        // 122122122
        For(i, 1, blocknum - 2) if(blk[i] != blk[i + 2] || len[i] != len[i + 2]) return 0;
        return 1;
    } else if(k == 3) {
        if(ok(l, r, 1) || ok(l, r, 2)) return 1;
        For(i, 1, sqrt(r - l + 1)) if((r - l + 1) % i == 0) {
            int flag = 1, j = (r - l + 1) / i;
            For(st, l, r - i) if(a[st] != a[st + i]) {flag = 0; break;}
            // cout << "debug " << i << " " << flag << '\n';
            if(flag)
                For(sep, l + 1, l + i - 1) {
                    if(ok(l, sep - 1, 1) && ok(sep, l + i - 1, 2)) return 1;
                    if(ok(l, sep - 1, 2) && ok(sep, l + i - 1, 1)) return 1;
                }
            flag = 1;
            For(st, l, r - j) if(a[st] != a[st + j]) {flag = 0; break;}
            // cout << "debug " << j << " " << flag << '\n';
            if(flag)
                For(sep, l + 1, l + j - 1) {
                    if(ok(l, sep - 1, 1) && ok(sep, l + j - 1, 2)) return 1;
                    if(ok(l, sep - 1, 2) && ok(sep, l + j - 1, 1)) return 1;
                }
        }
        return 0;
    }
}

signed main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        For(i, 1, n) cin >> a[i];
        cout << (ok(1, n, k) ? "YES" : "NO") << '\n';
    }
    return 0;
}