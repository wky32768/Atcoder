#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 2e5 + 5;

int n, k, ans[N], now;
char ch[N];

signed main() {
    cin >> n >> k;
    scanf("%s", ch + 1);
    For(i, 1, n) {
        if(ch[i] == 'o' && now < k) {
            ans[i] = 1;
            now ++;
        }
    }
    For(i, 1 ,n) cout << (ans[i] == 1 ? 'o' : 'x');
    return 0;
} 