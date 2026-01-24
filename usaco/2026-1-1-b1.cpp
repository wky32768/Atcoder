#include <bits/stdc++.h>

#define int long long
#define For(i, a, b) for(int i = a;i <= b;i++)

using namespace std;

const int N = 505;

int t, a, b, ca, cb, fa, ans;


signed main() {

    cin >> t;
    while(t--) {
        cin >> a >> b >> ca >> cb >> fa;

        // 首先, 把手里有的b全部换成a
        int ex1 = b / cb;
        b -= cb * ex1; 
        a += ca * ex1;
        
        if(a >= fa) {
            cout << 0 << endl;
            continue;
        }

        if(ca > cb) {
            // 把b给到cb - 1, 剩下给a
            int ans1 = 0;
            ans1 = cb - 1 - b + fa - a;
            cout << max(0ll, ans1) << endl;
        } else {
            int ans2 = 0;
            // 把a给到差值为cb倍数+1, 剩下的用cb换
            ans2 += (fa - a - 1) % ca;
            a += ans2;
            int need = (fa - a + ca - 1) / ca;
            ans2 += (need * cb - b);
            cout << max(0ll, ans2) << endl;
        }

    }

    return 0;
}