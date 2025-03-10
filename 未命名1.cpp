#include <bits/stdc++.h>
#define int unsigned long long
#define For(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

const int N = 1e4 + 10;
int n, cow[N],  cha[N];
char ch;

int calc(int k) {
    For(i, 1, n) cha[i] = 0;
    int sumcha = 0, tot = 0;
    For(i, 1, n) {
        int now = cow[i];
        sumcha += cha[i];
        // if(k == 3) cout << now << " " << sumcha << '\n';
        if((now + sumcha) % 2 == 0) continue;
        else {
            if(i + k >= n + 2) {
                return 0x3f3f3f3f;
            }
            cha[i + 1]++;
            cha[i + k]++;
            tot++;
        }
    }
    return tot; 
}


signed main() {
    cin >> n;
    For(i, 1, n) {
        cin >> ch;
        cow[i] = (ch == 'F' ? 0 : 1);
    }
    int mn = 0x3f3f3f3f, mnat = 0;
    For(i, 1, n) {
        int now = calc(i);
        if(now < mn) {
            mn = now; mnat = i;
        }
    }
    cout << mnat << " " << calc(mnat) << '\n';
    return 0;
}
