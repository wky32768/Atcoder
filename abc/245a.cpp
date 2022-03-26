#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int a, b, c, d;
bool higher() {
    if(a!=c) return a>c;
    else return b>d;
}
signed main() {
    cin>>a>>b>>c>>d;
    if(higher()) puts("Aoki");
    else puts("Takahashi");
    return 0;
}