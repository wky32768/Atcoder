#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 5e5 + 5;

int t, n, a[N], b[N];

bool cmp(int a, int b) {
    return abs(a) < abs(b);
}

map <int, int> tims;

using namespace std;
signed main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int z = 0, f = 0, oi = 0;
        tims.clear();
        For(i, 1, n) {
            cin >> a[i];
            if(a[i] > 0) z++;
            else f++;
            tims[abs(a[i])]++;
            if(tims[abs(a[i])] == n) oi = 1;
        }
        if(!f || !z) {
            sort(a + 1, a + n + 1);
        } else if(oi) {
            if(abs(z - f) <= 1) puts("Yes");
            else puts("No");
            continue;
        } else {
            if(abs(z - f) >= 2) {
                puts("No");
                continue;
            }
            
            sort(a + 1, a + n + 1, cmp);   
        }
        int ok = 1;
        For(i, 2, n - 1) if(a[i] * a[i] != a[i - 1] * a[i + 1]) ok = 0;
        puts(ok ? "Yes" : "No");
    }

    return 0;
}
