#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 200005;
int n, a[N];
char ch[N];

signed main() {
    scanf("%s", ch + 1);
    n = strlen(ch + 1);
    For(i, 1, n) a[i] = ch[i] - '0';
    a[n + 1] = 1;
    int ans = 0, st = 1;
    while(st <= n) {
        if(a[st] == 0 && a[st + 1] == 0) {
            ans ++; st +=2;
        } else {
            ans ++; st ++;
        }
    }
    cout << ans << '\n';
    return 0;
}