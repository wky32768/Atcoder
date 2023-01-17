#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 5005;
int n, ans;
char ch[N];


signed main() {
    cin >> n;
    scanf("%s", ch + 1);
    For(i, 1, n - 1) {
        ans = 0; int nowat = 1;
        while(ch[nowat] != ch[nowat + i] && nowat + i <= n) nowat ++;
        cout << nowat - 1 << '\n';
    }

    return 0;
} 