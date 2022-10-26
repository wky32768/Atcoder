#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define int long long
const int N=105;
using namespace std;
int ans, a[N];
char ch[N];
map <char, int> mp;
signed main() {
    mp['a']=1; mp['t']=2; mp['c']=3; mp['o']=4; mp['d']=5; mp['e']=6; mp['r']=7;
    scanf("%s", ch+1);
    For(i,1,7) a[i]=mp[ch[i]];
    For(i,1,6) For(j,i+1,7) if(a[i]>a[j]) ans++;
    cout<<ans<<'\n';
}