#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1000005;
int t, n, k1, k2;
bool ans[N];
double a[N], p;
inline int read()//inline 加速读入
{
	int x=0;char c=getchar();//x代表返回值，c代表读取的字符
	while (c<'0'||c>'9') c=getchar();//读取所有非数部分
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();//如果读取的字符为数，加入返回值
	return x;
}
signed main() {
    cin>>t;
    while(t--) {
        cin>>n;
        For(i,1,n) a[i]=double(read());
        cin>>k1>>k2>>p;
        For(i,1,n) ans[i]=0;
        int now=k2;
        double sum1=0, sum2=0;
        For(i,now-k1+1, now) sum1+=a[i];
        For(i,1,now) sum2+=a[i];
        // cout<<"debug "<<sum1<<" "<<sum2<<'\n';
        if(sum1/k1<sum2/k2*p/100) {
            ans[k2]=1;
        } 
        For(i,now+1,n) {
            sum1=sum1-a[i-k1]+a[i];
            sum2=sum2-a[i-k2]+a[i];
            // cout<<"debug "<<sum1<<" "<<sum2<<'\n';
            // cout<<"debug "<<sum1/k1<<" "<<sum2/k2*p/100<<'\n';
            if(sum1/k1<sum2/k2*p/100) {
                ans[i]=1;
            }
        }
        For(i,1,n) putchar(ans[i]==1?'1':'0');
        puts("");
    }
    return 0;
}