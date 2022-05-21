//https://blog.csdn.net/m0_51979134/article/details/124275800
//要点在于, 在枚举的过程中, 不能有落单的点或边存在
//即, 若不连通, 前面必须是两条平行线, 不然后期无法让他联通
//其他情况存在, 但是计算非联通是为后面转移联通服务的, 所以没救的情况不考虑
//也就是说, 即使是把前边不满足的转移, 也要保证上下都连上边才能维持"不满足状态"

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n, p;
int f[3005][3005][2]; //考虑到前i列, 删掉了j条边, 第i列的上下两个点是否联通
void Add(int &x, int y) {x=(x+y)%p;}
signed main() {
    cin>>n>>p;
    For(i,1,n) f[i][0][1]=1;
    f[1][1][0]=1;
    For(i,2,n) {
        For(j,1,i) { //至少要平行线, 即最多删i条
            Add(f[i][j][0], f[i-1][j-2][1]*2%p);
            Add(f[i][j][0], f[i-1][j-1][0]);            
            //①只留上边or下边②原本不连通, 只连上下边

            Add(f[i][j][1], f[i-1][j][1]);
            Add(f[i][j][1], f[i-1][j][0]);
            Add(f[i][j][1], f[i-1][j-1][1]*3%p);
            //①原本联通再加三条仍联通②平行线三条都加后联通
            //③原本联通不留孤点(可删任意一条)并联通

        }
    }
    For(i,1,n-1) cout<<f[n][i][1]<<" ";
    return 0;
}