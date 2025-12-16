#include <bits/stdc++.h>

#define For(i, a, b) for(int i = a;i <= b;i++)

using namespace std;

const int N = 2005;

int n, m, s[N][N], ans;
char ch[N][N];

void init() {
    For(i, 1, n / 2) For(j, 1, n / 2) {
        if(ch[n / 2 - j + 1][n / 2 + i] == '#') s[i][j] ++;
        if(ch[n / 2 - j + 1][n / 2 - i + 1] == '#') s[i][j] ++;
        if(ch[n / 2 + j][n / 2 + i] == '#') s[i][j] ++;
        if(ch[n / 2 + j][n / 2 - i + 1] == '#') s[i][j] ++;
        if(s[i][j] == 1 || s[i][j] == 3) ans ++;
        else if(s[i][j] == 2) ans += 2;
    }
}

signed main() {
    cin >> n >> m;
    For(i, 1, n) {
        scanf("%s", ch[i] + 1);
    }
    init();
    cout << ans << '\n';
    while(m--) {
        int x, y, i, j; cin >> x >> y;
        if(x <= n / 2 && y > n / 2) i = y - n / 2, j = n / 2 + 1 - x;
        if(x <= n / 2 && y <= n / 2) i = n / 2 + 1 - y, j = n / 2 + 1 - x;
        if(x > n / 2 && y > n / 2) i = y - n / 2, j = x - n / 2;
        if(x > n / 2 && y <= n / 2) i = n / 2 + 1 - y, j = x - n / 2;
        if(ch[x][y] == '#') {
            ch[x][y] = '.';
            if(s[i][j] <= 2) ans--;
            else ans++;
            s[i][j] --;
        } else if(ch[x][y] == '.') {
            ch[x][y] = '#';
            if(s[i][j] <= 1) ans++;
            else ans--;
            s[i][j] ++;
        }
        cout << ans << '\n';
    }
    return 0;
}