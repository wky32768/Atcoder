#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int n;
struct node {
    char ch[105];
} a[105];

signed main() {
    cin >> n;
    For(i,1,n) {
        scanf("%s", a[i].ch + 1);
    }
    for(int i=n;i>=1;i--) cout << a[i].ch + 1 << '\n';

    return 0;
}