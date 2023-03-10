#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define For(i, a, b) for(int i = a; i <= b; i++)
#define int long long

const int N = 1e5 + 5;
using namespace std;

char ch[N];

signed main() {
    scanf("%s", ch + 1);
    For(i, 1, strlen(ch + 1)) {
        if(ch[i] >= 'A' && ch[i] <= 'Z') {
            cout << i << '\n';
            return 0;
        }
    }    
    return 0;
}