#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
char ch[105];
int n, have_big=0, have_small=0;
map <char,int> mp;
signed main() {
    scanf("%s", ch+1);
    n=strlen(ch+1);
    For(i,1,n) {
        if(ch[i]>='A' && ch[i]<='Z') have_big=1;
        if(ch[i]>='a' && ch[i]<='z') have_small=1;
        if(mp[ch[i]]) {puts("No"); return 0;}
        else mp[ch[i]] = 1;
    }
    if(have_big && have_small) puts("Yes");
    else puts("No");
    return 0;
}