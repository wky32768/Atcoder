#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#define For(i, a, b) for(int i = a; i <= b; i ++)
#define int long long
const int N=220005;
using namespace std;
int h, w, rs, cs, n;
map <int, vector <int> > row;
map <int, vector <int> > col;
pair <int, int> p[N];
signed main() {
    cin>>h>>w>>rs>>cs>>n;
    For(i,1,n) {
        int x, y; cin>>x>>y;
        p[i]=make_pair(x, y);
    }
    sort(p+1, p+n+1);
    For(i,1,n) {
        int x=p[i].first, y=p[i].second;
        row[x].push_back(y);
        col[y].push_back(x);
    }
    
    int q; cin>>q;
    while(q--) {
        char ch; int x; cin>>ch>>x;
        if(ch=='L' || ch=='R') {
            if(row[rs].size()==0) {
                if(ch=='L') cs=max(1ll, cs-x);
                if(ch=='R') cs=min(w, cs+x);
            } else {
                if(ch=='L') {
                    int now=upper_bound(row[rs].begin(), row[rs].end(), cs)-row[rs].begin();
                    if(now==0) {cs=max(1ll, cs-x);} else {
                    int wall=row[rs][now-1];
                    if(wall>=1 && wall<=w && wall<cs && wall>=max(1ll, cs-x)) cs=wall+1;
                    else cs=max(1ll, cs-x);}
                } else if(ch=='R') {
                    int now=upper_bound(row[rs].begin(), row[rs].end(),cs)-row[rs].begin();
                    int wall=row[rs][now];
                    if(wall>=1 && wall<=w && wall>cs && wall<=min(w, cs+x)) cs=wall-1;
                    else cs=min(w, cs+x);
                }
            }   
        } else if(ch=='U' || ch=='D') {
            if(col[cs].size()==0) {
                if(ch=='U') rs=max(1ll, rs-x);
                if(ch=='D') rs=min(h, rs+x);
            } else {
                if(ch=='U') {
                    int now=upper_bound(col[cs].begin(), col[cs].end(),rs)-col[cs].begin();
                    if(now==0) {rs=max(1ll, rs-x);} else {
                    int wall=col[cs][now-1];
                    // cout<<col[1][0]<<" "<<col[1][1]<<" "<<col[1][2]<<'\n';
                    // cout<<"Debug "<<now<<" "<<wall<<'\n';
                    if(wall>=1 && wall<=h && wall<rs && wall>=max(1ll, rs-x)) rs=wall+1;
                    else rs=max(1ll, rs-x);}
                } else if(ch=='D') {
                    int now=upper_bound(col[cs].begin(), col[cs].end(),rs)-col[cs].begin();
                    int wall=col[cs][now];
                    if(wall>=1 && wall<=h && wall>rs && wall<=min(h, rs+x)) rs=wall-1;
                    else rs=min(h, rs+x);
                }
            }
        }
        cout<<rs<<" "<<cs<<'\n';
    }
    return 0;
}