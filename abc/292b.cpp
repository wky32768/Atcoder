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

int n, q, opt, x;
int yellow[N], red[N], rem[N];

signed main() {
    cin >> n >> q;
    while(q --) {
        cin >> opt >> x;
        if(opt == 1) {
            yellow[x] ++;
            if(yellow[x] == 2) rem[x] = 1;
        } else if(opt == 2) {
            red[x] ++; rem[x] = 1;
        } else if(opt == 3) {
            cout << (rem[x] == 1 ? "Yes" : "No") << endl;
        }
    }
    return 0;
} 