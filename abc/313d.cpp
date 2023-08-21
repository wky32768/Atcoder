// figure out a_1 ~ a_{k + 1} by k + 1 asks
// then calculate a_{k + 2} ~ a_{n}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define int long long
#define For(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 200005;
int n, k, exc[N], a[N];
signed main() {
    cin >> n >> k;
    int sum = 0;
    For(i, 1, k + 1) {
        cout << "? ";
        For(j, 1, k + 1) if (i != j) cout << j << " ";
        cout << endl;
        cin >> exc[i];
        sum += exc[i];
    }
    For(i, 1, k + 1) a[i] = (2 + sum % 2 - exc[i]) % 2;
    For(i, k + 2, n) {
        cout << "? ";
        For(j, 1, k - 1) cout << j << " ";
        cout << i << endl;
        int temp = 0;
        cin >> temp;
        a[i] = (temp - exc[k + 1] - a[k] + 2) % 2;
    }
    cout << "! ";
    For(i, 1, n) cout << a[i] << " ";
    cout << endl;
    return 0;
}
