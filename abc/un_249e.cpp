#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=3005;
int n, p, ans;
int f[2][30][N][2];
void add(int &x, int y) {
    x=(x+y)%p;
}
signed main() {
    cin>>n>>p;
    For(i,1,26) f[1][i][1][0]=1;
    For(i,2,n) {
        For(j,1,26)  {//当前的位置
            //换新
            For(now,1,26) { //前一位的字母
                For(k,1,i-1) { //前一位连了几位
                    add(f[i%2][j][1][1], f[1-i%2][now][k][1]);
                    add(f[i%2][j][1][0], f[1-i%2][now][k][0]);
                    // cout<<"debug "<<f[i%2][j][1][1]<<'\n';
                }
            }

            For(k,2,i) { 
                //和前一位一样
                // cout<<"k="<<k<<endl;
                if(k-1>=3) add(f[i%2][j][k][1], f[1-i%2][j][k-1][1]);
                if(k==3) {
                    add(f[i%2][j][k][1], f[1-i%2][j][k-1][0]);
                    add(f[i%2][j][k][1], f[1-i%2][j][k-1][1]);
                    // cout<<f[i%2][j][k][1]<<'\n';
                    // return 0;
                }
                if(k<=2) {
                    add(f[i%2][j][k][0], f[1-i%2][j][k-1][0]);
                    add(f[i%2][j][k][1], f[1-i%2][j][k-1][1]);
                }
            }
            
        }
        For(j,1,26) For(k,1,n) For(l,0,1) f[1-i%2][j][k][l]=0;
    }
    For(i,1,26) For(j,1,n) add(ans, f[n%2][i][j][1]);
    cout<<ans<<'\n';
    return 0;
}