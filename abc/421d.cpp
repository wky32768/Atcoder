#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 5e5 + 5;

int X1, Y1, X2, Y2;
int n, m, l;
int a[N], b[N], suma[N], sumb[N];
char s[N], t[N];
int cut[N];

int calc(int x1, int y1, int x2, int y2, int t1, int t2, char c1, char c2) {
    if(c1 != c2) {
        int len = (abs(x1 - x2) + abs(y1 - y2)) / 2;
        if(len > t2 - t1) return 0;
        if(x1 == x2 && y1 == y2) return 0;

        int xx1, yy1, xx2, yy2;
        if(c1 == 'L') xx1 = x1, yy1 = y1 - len;
        if(c1 == 'R') xx1 = x1, yy1 = y1 + len;
        if(c1 == 'U') xx1 = x1 - len, yy1 = y1;
        if(c1 == 'D') xx1 = x1 + len, yy1 = y1;
        if(c2 == 'L') xx2 = x2, yy2 = y2 - len;
        if(c2 == 'R') xx2 = x2, yy2 = y2 + len;
        if(c2 == 'U') xx2 = x2 - len, yy2 = y2;
        if(c2 == 'D') xx2 = x2 + len, yy2 = y2;
        if(xx1 == xx2 && yy1 == yy2) return 1;
        else return 0;
    } else {
        if(x1 == x2 && y1 == y2) return t2 - t1;
        else return 0;
    }
}


signed main() {
    cin >> X1 >> Y1 >> X2 >> Y2 >> n >> m >> l;
    int sum1 = 0, sum2 = 0;
    For(i, 1, m) {
        cin >> s[i] >> a[i];
        sum1 += a[i];
        suma[i] = sum1;
        cut[++cut[0]] = sum1;
    }
    For(i, 1, l) {
        cin >> t[i] >> b[i];
        sum2 += b[i];
        sumb[i] = sum2;
        cut[++cut[0]] = sum2;
    }
    sort(cut + 1, cut + cut[0] + 1);
    cut[0] = unique(cut + 1, cut + cut[0] + 1) - cut - 1;

    int at1 = 1, at2 = 1, ans = 0;
    For(i, 1, cut[0]) {
        ans += calc(X1, Y1, X2, Y2, i == 1 ? 0 : cut[i - 1], cut[i], s[at1], t[at2]);
        if(s[at1] == 'L') Y1 -= cut[i] - (i == 1 ? 0 : cut[i - 1]);
        if(s[at1] == 'R') Y1 += cut[i] - (i == 1 ? 0 : cut[i - 1]);
        if(s[at1] == 'U') X1 -= cut[i] - (i == 1 ? 0 : cut[i - 1]);
        if(s[at1] == 'D') X1 += cut[i] - (i == 1 ? 0 : cut[i - 1]);
        if(t[at2] == 'L') Y2 -= cut[i] - (i == 1 ? 0 : cut[i - 1]);
        if(t[at2] == 'R') Y2 += cut[i] - (i == 1 ? 0 : cut[i - 1]);
        if(t[at2] == 'U') X2 -= cut[i] - (i == 1 ? 0 : cut[i - 1]);
        if(t[at2] == 'D') X2 += cut[i] - (i == 1 ? 0 : cut[i - 1]);
        if(suma[at1] == cut[i]) at1++;
        if(sumb[at2] == cut[i]) at2++;
    }
    cout << ans << endl;
    return 0;
}