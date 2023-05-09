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
double a, b, c, d, e;

signed main() {
    cin >> t;
    while(t --) {
        cin >> a >> b >> c >> d >> e;
        double dis = sqrt(pow(c - a, 2) + pow(d - b, 2));
        if(dis > e) puts("no");
        else puts("yes");
    }
    return 0;
}