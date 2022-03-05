#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++) 
using namespace std;
const int N=200005;
char ch[N];
int n, a[N*2];
signed main() {
	cin>>n;
	scanf("%s", ch+1);
	int cnt=0;
	For(i,1,n) {
		if(ch[i]=='B' || ch[i]=='C') a[++cnt]=ch[i]-'A';
		else a[++cnt]=1, a[++cnt]=1;	
	}
	For(i,1,cnt) {
		if(a[i]==1 && a[i+1]==1) {
			cout<<"A";i++;
		} else cout<<(char)(a[i]+'A');
	}
	return 0;
}

