#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
char ch[1000005];
int n, x, lev=0, l[1000005];
signed main()
{
	cin>>n>>x;
	scanf("%s", ch+1);
	For(i,1,n) {
		if(ch[i]=='U') lev--;
		else lev++;
		l[i]=lev;
	}
	For(i,1,n) {
		if(ch[i]=='U') {
			if(l[i-1]<=max(0ll, lev)) x/=2;
		} else {
			if(l[i]<=max(0ll, lev)) {
				if(ch[i]=='L') x*=2;
				else x=x*2+1;
			}
		}
	}
	cout<<x;
    return 0;
}
