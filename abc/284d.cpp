#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

int t, n;
bool prime[3000005];

signed main() {
    For(i, 2, 3000005) prime[i] = 1;
    for(int i = 2; i <= 3000005; i++) {
        if(prime[i] == 1) {
            for(int j = i * 2; j <= 3000005; j += i) prime[j] =0;
        }

    }
    cin >> t;
    while(t--) {
        cin >> n;
        For(i, 2, 3000000) if(n % i == 0 && prime[i]) {
            if((n/i) % i == 0) {
                cout << i << " " << n / (i * i) <<'\n';
                break;
            } else {
                cout << (int)sqrt(n/i) << " " << i << '\n';
                break;
            }
        }
    }    
    return 0;
}