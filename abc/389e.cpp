#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int __int128
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;

#define int __int128
inline void read(int &n){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    n=x*f;
}
inline void print(int n){
    if(n<0){
        putchar('-');
        n*=-1;
    }
    if(n>9) print(n/10);
    putchar(n % 10 + '0');
}


const int N = 2e5 + 10;
int n, m, p[N], ans, l, r, mid, sum;



bool ok(int x) {
    int onlyx = 0, xandxp1 = 0, money = m, money2 = m;
    For(i, 1, n) {
        int k1 = (x / p[i] + 1) / 2;
        if(k1 * k1 >= 2e18 / p[i]) return false;
        onlyx += k1;
        money -= k1 * k1 * p[i];
        int k2 = ((x + 1) / p[i] + 1) / 2;
        xandxp1 += k2;
        money2 -= k2 * k2 * p[i]; 
        if(money < 0 && money2 < 0) return false;
    }
    if(money < 0 && money2 < 0) return false;
    if(money >= 0 && money2 < 0) {
        sum = max(sum, onlyx + money / (x + 1));
        return true;
    }
    if(money >= 0 && money2 > 0) {
        sum = max(sum, xandxp1);
        return true;
    }
}

signed main() {
    read(n), read(m);
    sum = 0;
    For(i, 1, n) read(p[i]);
    l = 0, r = 1e18;
    while(l <= r) {
        mid = (l + r) / 2;
        // cout << "debug " << mid << " " << ok(mid) << '\n';
        if(ok(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    print(sum);
    return 0;
}