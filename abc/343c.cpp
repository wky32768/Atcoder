#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;

const int N = 1e5 + 5;

int n;

signed main() {
    cin >> n;
    for(int i = 1e6 + 10; i >= 0; i--) {
        // check if i^3 is palindromic1
        int x = i * i * i;
        if(x > n) continue;
        string s = to_string(x);
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t) {
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}