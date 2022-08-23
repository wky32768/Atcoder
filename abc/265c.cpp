#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
const int N=505;
int h, w;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool vis[N][N];
char ch[N][N];
signed main() {
    cin>>h>>w;
    For(i,1,h) scanf("%s", ch[i]+1);
    int nowx=1, nowy=1, viss=0;
    while(1) {
        // cout<<"Debug "<<nowx<<" "<<nowy<<'\n';
        vis[nowx][nowy]=1;
        int dir=0;
        switch(ch[nowx][nowy]) {
            case 'U': dir=0; break;
            case 'D': dir=1; break;
            case 'L': dir=2; break;
            case 'R': dir=3; break;
        }
        int nxtx=nowx+dx[dir], nxty=nowy+dy[dir];
        if(nxtx<=0 || nxtx>h) break;
        if(nxty<=0 || nxty>w) break;
        if(vis[nxtx][nxty]) {viss=1; break;}
        nowx=nxtx, nowy=nxty;
    }
    if(!viss) cout<<nowx<<" "<<nowy<<'\n';
    else puts("-1");
    return 0;
}