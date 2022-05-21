#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
char ch[25];
int num[35][35]; //第i个字符里j字符有几个
int s[35]; //是否选择
int tot[35];
int n, k, ans;
void dfs(int x) {
    if(x==n+1) {
        memset(tot, 0, sizeof(tot));
        For(i,1,n) if(s[i]==1) {//选中
            For(j,0,25) tot[j]+=num[i][j];
        }
        int cnt=0;
        For(j,0,25) if(tot[j]==k) cnt++;
        ans=max(ans, cnt);
        return;
    }
    s[x]=1;
    dfs(x+1);
    s[x]=0;
    dfs(x+1);
}
signed main() {
    cin>>n>>k;
    For(i,1,n) {
        scanf("%s", ch+1);
        int nn=strlen(ch+1);
        // cout<<"nn="<<nn<<'\n'; 
        For(j,1,nn) {
            num[i][ch[j]-'a']++;
            // cout<<"debug "<<i<<" "<<ch[j]-'a'<<'\n';
        }
    }
    dfs(1);
    cout<<ans<<'\n';
    return 0;
}
