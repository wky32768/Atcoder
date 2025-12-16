#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 1e6 + 5;

int n;
char s[N];

int calc1() {
    int tot = 0;
    int last = 1;
    For(i, 1, n * 2) if(s[i] == 'A') {
        // cout << "debug " << i << " " << last << '\n';
        tot += abs(i - last);
        last += 2;
    }
    return tot;
}

int calc2() {
    int tot = 0;
    int last = 1;
    For(i, 1, n * 2) if(s[i] == 'B') {
        tot += abs(i - last);
        last += 2;
    }
    return tot;
}



signed main() {
    cin >> n;
    scanf("%s", s + 1);
    int ans1 = calc1(), ans2 = calc2();
    // cout << "debug " << ans1 << " " << ans2 << '\n';
    cout << min(ans1, ans2) << '\n';
    return 0;
}