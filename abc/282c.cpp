#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int N = 200005;
int n;
char ch[N];
bool in;

signed main() {
    cin >> n;
    scanf("%s", ch + 1);
    For(i, 1, n) {
        if(ch[i] == '"') in ^= 1;
        if(ch[i] == ',' && !(in % 2)) ch[i] = '.';
    }
    cout << ch + 1;
    return 0;
}