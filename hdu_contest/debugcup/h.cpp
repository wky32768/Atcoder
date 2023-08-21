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
int a, b, c;
int calc_gcd(int a, int b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    else return calc_gcd(b, a % b);
}


signed main() {
    cin >> t;
    while(t--) {
        a = read(), b = read(), c = read();
        int gcd = calc_gcd(a, b);
        if(c > max(a, b)) puts("no");
        else if(gcd == 1) puts("yes");
        else {
            if(c % gcd == 0) puts("yes");
            else puts("no");
        }
    }
    return 0;
}