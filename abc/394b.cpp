#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

char ch[55][55];
pair <int, int> a[55];
int n;


signed main() {
    cin >> n;
    For(i, 1, n) {
        scanf("%s", ch[i] + 1);
        a[i] = {strlen(ch[i] + 1), i};
    }
    sort(a + 1, a + n + 1);
    For(i, 1, n) 
        For(j, 1, a[i].first) 
            cout << ch[a[i].second][j];
    cout << endl;

    return 0;
}