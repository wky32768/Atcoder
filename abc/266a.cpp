#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=200005;
char ch[N];
signed main() {
    scanf("%s", ch+1);
    int n=strlen(ch+1);
    cout<<ch[(n+1)/2]<<'\n';
    return 0;
}