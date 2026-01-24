#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)
#define mp make_pair

using namespace std;

const int N = 4e5 + 5;

int n, l, num[N];


using namespace std;
signed main() {
    cin >> n >> l;
    num[0] = 1;
    int now = 0;
    For(i, 1, n - 1) {
        int x; cin >> x;
        now =(now + x) % l;
        num[now] ++;
    }
    if(l % 3) {
        puts("0");
        return 0;
    }
    int ans = 0;
    For(i, 0, l / 3 - 1) 
        if(num[i] && num[i + l / 3] && num[i + l / 3 * 2])
            ans += num[i] * num[i + l / 3] * num[i + l / 3 * 2];
    cout << ans << '\n';
    return 0;
}
