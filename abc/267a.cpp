#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
string s;
signed main() {
    cin>>s;
    if(s=="Monday") puts("5");
    else if(s=="Tuesday") puts("4");
    else if(s=="Wednesday") puts("3");
    else if(s=="Thursday") puts("2");
    else if(s=="Friday") puts("1");
    return 0;
}