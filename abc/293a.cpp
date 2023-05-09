#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 200005;
char ch[N];
signed main() {
    scanf("%s", ch + 1);
    For(i, 1, strlen(ch + 1)) {
        if(i % 2 == 1) swap(ch[i], ch[i + 1]);
    }
    cout << ch + 1 << endl;
}