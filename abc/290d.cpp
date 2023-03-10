#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 3e5 + 5;

int t, n, d, k;

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

signed main() {
    cin >> t;
    while(t --) {
        cin >> n >> d >> k;
        int num = gcd(n, d);
        if(num == 1) {
            cout << d * (k - 1) % n << '\n';
        } else {
            int lcm = n * d / num;
            int round_num = lcm / d;
            int st = (k - 1) / round_num;
            // cout << "debug " << lcm << " " << round << " " << st << '\n';
            cout << (st + d * ((k - 1) % round_num)) % n << '\n';
        }
    }
    return 0;
} 