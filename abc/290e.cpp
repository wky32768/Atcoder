/*
Hint: ans(l, r) (that a[l] == a[r]) = min(l, n - r + 1)
how to solve it in O(n)?
compare(a[l], n - a[r] + 1)
a[l] smaller: ans += (r - l) * a[l], l ++;
n - a[r] + 1 smaller: ans += (r - l) * (n - a[r] + 1), r --;
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 3e5 + 5;

int n, a[N], ans;
vector <vector <long long> > num(N);

signed main() {
    cin >> n;
    For(i, 1, n) {
        cin >> a[i];
        num[a[i]].push_back(i);
    }
    For(i, 1, n) if(num[i].size()) {
        int l = 0, r = num[i].size() - 1;
        while(l < r) {
            if(num[i][l] < n - num[i][r] + 1) {
                ans += (r - l) * num[i][l];
                l ++;
            } else {
                ans += (r - l) * (n - num[i][r] + 1);
                r --;
            }
        }
    }
    int ans2 = 0;
    for(int i = n - 1; i >= 1; i --) {
        int mul = (n + 1 - i) / 2;
        ans2 += i * mul;
    }
    cout << ans2 - ans;
    return 0;
} 