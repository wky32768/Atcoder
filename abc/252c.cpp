#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=100005;
int n, ans=0x3f3f3f3f;
int temp[N];
struct node {
    char ch[12];
} c[N];
vector <int> at;
signed main() {
    cin>>n;
    For(i,1,n) scanf("%s", c[i].ch+1);
    For(i, 0, 9) {
        at.clear();
        For(j,1,n) For(k,1,10) {
            if(c[j].ch[k]-'0'==i) {at.push_back(k); break;}
        }
        sort(at.begin(),at.end());
        int mx=0;
        memset(temp, 0, sizeof(temp));
        For(j,0,at.size()-1) {
            // cout<<"now:"<<at[j]<<'\n';
            if(j!=0 && at[j]==at[j-1]) temp[j]=temp[j-1]+10;
            else temp[j]=at[j];
            mx=max(mx, temp[j]-1);
            // cout<<"mx="<<mx<<endl;
        }
        ans=min(mx,ans);
    }
    cout<<ans<<'\n';
    return 0;
}