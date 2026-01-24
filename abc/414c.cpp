#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 1e5 + 5;

int a, n;

int makee(int x) {
    int now = x;
    while(x) {
        now = now * 10 + x % 10;
        x /= 10;
    }
    return now;
}

int makeo(int x) {
    int now = x;
    x /= 10;
    while(x) {
        now = now * 10 + x % 10;
        x /= 10;
    }
    return now;
}

bool ok(int x) {
    int now = x, to = 0;
    while(x) {
        to = to * a + x % a;
        x /= a;
    }
    return to == now;
}


using namespace std;
signed main() {
    cin >> a >> n;
    int sum = 0;

    int st = 1;
    For(i, 1, 6) {
        st *= 10;
        For(j, st / 10, st - 1) {
            int even = makee(j);
            if(ok(even) && even <= n) sum += even;
            int odd = makeo(j);
            if(ok(odd) && odd <= n) sum += odd; 
            if(odd > n) break;
        }
    }
    cout << sum << '\n';

    return 0;
}
