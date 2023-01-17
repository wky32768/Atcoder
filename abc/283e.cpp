#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 1005;
int h, w, f[N][2][2]; //第i行, 第i行是否修改, 第i-1行是否修改
int a[N][N], tmp[3][N];

signed main() {
    cin >> h >> w;
    For(i, 1, h) For(j, 1, w) cin >> a[i][j];
    memset(f, 0x3f3f3f3f, sizeof f);
    f[0][1][0] = f[0][0][0] = 0;
    For(i, 1, h) {
        For(j, 0, 1) For(k, 0, 1) For(l, 0, 1) {
            //i, i-1, i-2
            For(tmpx, i-2, i) For(tmpy, 1, w) 
                tmp[2 + tmpx - i][tmpy] = (tmpx >= 1 ? a[tmpx][tmpy] : -1);
            if(j & 1) For(tmpy, 1, w) tmp[2][tmpy] = 1 - tmp[2][tmpy];
            if(k & 1) For(tmpy, 1, w) tmp[1][tmpy] = 1 - tmp[1][tmpy];
            if(l & 1) For(tmpy, 1, w) tmp[0][tmpy] = 1 - tmp[0][tmpy];
            // For(tmpx, 0, 2) {
            //     For(tmpy, 1, w) cout << tmp[tmpx][tmpy] << " ";
            //     puts("");
            // }
            bool ok = 1;
            For(tmpy, 1, w) {
                if(tmpy != 1 && tmp[1][tmpy - 1] == tmp[1][tmpy]) continue;
                if(tmpy != w && tmp[1][tmpy] == tmp[1][tmpy + 1]) continue;
                if(tmp[1][tmpy] == tmp[0][tmpy] || tmp[1][tmpy] == tmp[2][tmpy]) continue;
                ok = 0; break;
            }
            if(i == h && ok == 1) {
                For(tmpy, 1, w) {
                    if(tmpy != 1 && tmp[2][tmpy - 1] == tmp[2][tmpy]) continue;
                    if(tmpy != w && tmp[2][tmpy] == tmp[2][tmpy + 1]) continue;
                    if(tmp[1][tmpy] == tmp[2][tmpy]) continue;
                    ok = 0; break;
                }
            }
            if(ok == 1) f[i][j][k] = min(f[i][j][k], f[i - 1][k][l] + j);
            // cout << "f: " << i << " " << j << " " << k << " " << f[i][j][k] << "\n\n";
        }
    }
    int ans = 0x3f3f3f3f;
    For(j, 0, 1) For(k, 0, 1) ans = min(ans, f[h][j][k]);
    cout << (ans > 10000000 ? -1 : ans) << '\n';
    return 0;
}