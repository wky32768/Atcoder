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

int t, n;
char ch[N];
int sum[N], calc[N];

using namespace std;
signed main() {
    cin >> t;
    while(t--) {
        cin >> n;
        scanf("%s", ch + 1);
        sum[0] = calc[0] = 0;
        For(i, 1, n) {
            sum[i] = sum[i - 1] + (ch[i] - '0');
            calc[i] = min(calc[i - 1], 2 * sum[i] - i);
        }
        int mn = 0x3f3f3f3f;
        For(i, 1, n) {
            mn = min(mn, sum[n] + calc[i] + i - 2 * sum[i]);
        }
        cout << mn << endl;
    }
    return 0;
}
