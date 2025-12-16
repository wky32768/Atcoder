#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

const int N = 1e5 + 5;

using namespace std;
struct room {
    int num;
    string name;
} s[N];

signed main() {
    int n;
    cin >> n;
    For(i, 1, n) {
        cin >> s[i].name;
        s[i].num = i;
    }
    int x;
    string nm;
    cin >> x >> nm;
    if(s[x].name == nm) puts("Yes");
    else puts("No"); 
    return 0;
}