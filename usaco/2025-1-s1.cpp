#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
#define int long long
using namespace std;
const int N = 5e5 + 10;
vector <int> a[N], b[N];
int n, ans, tmp[N], sum[N], aa[N], bb[N];
signed main() {
    cin >> n;
    For(i, 1, n) {
        int x; cin >> x;
        a[x].push_back(i);
        aa[i] = x;
    }
    For(i, 1, n) {
        int x; cin >> x;
        b[x].push_back(i);
        bb[i] = x;
    }
    int basicans = 0;
    For(i, 1, n) if(aa[i] == bb[i]) {
        // basicans ++;
        basicans += (i - 1) * i / 2 + (n - i) * (n - i + 1) / 2;
    }
    // cout << "debug basicans: " << basicans << "\n";
    For(i, 1, n) {
        if(!a[i].size() || !b[i].size()) continue;
        sum[0] = 0;
        For(j, 0, b[i].size() - 1) {
            tmp[j] = min(b[i][j], n - b[i][j] + 1);
        }

        // cout << "debug tmp:\n";
        // For(j, 0, b[i].size() - 1) cout << tmp[j] << " ";
        // cout << "\n";
        sort(tmp, tmp + b[i].size());

        For(j, 0, b[i].size() - 1) {
            sum[j + 1] = sum[j] + tmp[j];
        }

        For(j, 0, a[i].size() - 1) {
            int tmpa = min(a[i][j], n - a[i][j] + 1);
            int at = lower_bound(tmp, tmp + b[i].size(), tmpa) - tmp;
            // cout << "debug at: " << at << " " << tmpa << " " << sum[at] << "\n";
            ans += sum[at] + tmpa * (b[i].size() - at);
            // cout << "ans = " << ans << '\n';
        }

    }
    cout << basicans + ans;







    return 0;
}