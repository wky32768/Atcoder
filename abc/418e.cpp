#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <utility>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 1e5 + 5;

int n;
int x[N], y[N];
int px;
unordered_map <double, int> xl;
unordered_map <double, unordered_map <double, int> > dis;

double calc_xl(int i, int j) {
    if(x[i] == x[j]) return 1e9 + 7;
    else return (double)(y[i] - y[j]) / (x[i] - x[j]);
}

double calc_dis(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int calc(int i, int j) {
    double xlij = calc_xl(i, j), disij = calc_dis(i, j);
    int now = 0;
    now += xl[xlij]; xl[xlij] ++;
    px += dis[xlij][disij]; dis[xlij][disij] ++;
    return now;
}

using namespace std;
signed main() {
    cin >> n;
    int ans = 0;
    For(i, 1, n) {
        cin >> x[i] >> y[i];
        For(j, 1, i - 1)
            ans += calc(i, j);
    }
    cout << ans - px / 2 << '\n';

    return 0;
}