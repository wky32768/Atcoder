#include <bits/stdc++.h>

#define int long long
#define For(i, a, b) for(int i = a;i <= b;i++)

using namespace std;

const int N = 3e5 + 5;

int t, k, n, ans[N];
char s[N];

signed main() {
    cin >> t >> k;
    while(t--) {
        cin >> n;
        scanf("%s", s + 1);
        if(n % 2 == 1) {
            puts("-1");
            continue;
        }

        int one = 1;
        For(i, 1, n * 3 / 2)
            if(s[i] != s[n * 3 / 2 + i]) one = 0;

        if(one == 1) {
            puts("1");
            For(i, 1, n * 3) cout << "1 ";
            puts("");
        } else {
            For(i, 1, n * 3) ans[i] = 1;
            for(int i = 1;i <= n * 3 / 2;i += 3) {
                if(s[i] == s[n * 3 / 2 + i]) continue;
                else if(s[i] == s[n * 3 / 2 + i + 2]) { // ABC BCA
                    ans[i] = ans[n * 3 / 2 + i + 2] = 2;
                } else if(s[i] == s[n * 3 / 2 + i + 1]) { // ABC CAB
                    ans[i + 2] = ans[n * 3 / 2 + i] = 2;
                }
            }
            
            puts("2");
            For(i, 1, n * 3) cout << ans[i] << " ";
            puts("");
        }
    }

    return 0;
}