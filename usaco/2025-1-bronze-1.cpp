#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
#define int long long
using namespace std;
const int N = 1200;
int t, n, a, b, f[N][N], used[N][N];
char ch[N];
signed main() {
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        For(i, 1, n) {
            scanf("%s", ch + 1);
            For(j, 1, n) {
                if(ch[j] == 'B') f[i][j] = 2;
                else if(ch[j] == 'G') f[i][j] = 1;
                else f[i][j] = 0;
            }
        }

        // For(i, 1 ,n) {
        //     For(j, 1, n)
        //         cout << f[i][j] << " ";
        //     cout << endl;
        // }

        memset(used, 0, sizeof used);

        int ans = 0, valid = 1;
        for(int i = n; i >= 1; i--)
            for(int j = n; j >= 1; j--)
                if(f[i][j] > 0) {
                    // cout << "debug: " << i << " " << j << " " << f[i][j] << endl;
                    if(f[i][j] == 2) { 
                        // itself + moving from (i - b, j - a)
                        ans += (a == 0 && b == 0 ? 1 : 2); 
                        int ii = i - b, jj = j - a;
                        if(ii <= 0 || jj <= 0) {
                            valid = 0;
                            break;
                        } else if(f[ii][jj] <= 0) {
                            valid = 0;
                            break;
                        }
                        f[ii][jj] --;
                        used[ii][jj] = 1;
                        f[i][j] = 0;
                    } else if(f[i][j] == 1) {
                        // A: itself and vanished
                        // B: moving from (i - b, j - a)
                        int ii = i - b, jj = j - a;
                        if(ii >= 1 && jj >= 1 && f[ii][jj] >= 1) { // B
                            ans ++;
                            f[ii][jj] --;
                            used[ii][jj] = 1;
                        } else { // A
                            if(used[i][j] == 1) {
                                valid = 0;
                                break;
                            } else {
                                ans ++;
                                used[i][j] = 1;
                            }
                        }
                        f[i][j] = 0;
                    }
                }
        if(!valid) puts("-1");
        else cout << ans << endl;
    }
    return 0;
}