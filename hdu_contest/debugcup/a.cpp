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

int t, a[5];
signed main() {
    t = read(); 
    For(i, 1, t) {
        For(j, 1, 4) a[j] = read();
        int tot3 = 0, tot8 = 0;
        For(j, 1, 4) {
            if(a[j] == 3) tot3 ++;
            else tot8 ++;
        }
        if(tot8 == 4) puts("no");
        else puts("yes");
    }
    return 0;

}
