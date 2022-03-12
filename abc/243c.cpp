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
const int N=2000005;
struct node {
	int x, y, dir; //dir=1:left, 2:right;	
} a[N];
int n;
char ch[N];
map <int,int> mn, mx;
vector <int> road;
signed main() {
	cin>>n;
	For(i,1,n) cin>>a[i].x>>a[i].y;
	scanf("%s", ch+1);
	For(i,1,n) a[i].dir=(ch[i]=='L')?1:2;
	For(i,1,n) {
		road.push_back(a[i].y);
		if(a[i].dir==2) if(!mn.count(a[i].y) || mn[a[i].y]>a[i].x) mn[a[i].y]=a[i].x;
		if(a[i].dir==1) if(!mn.count(a[i].y) || mx[a[i].y]<a[i].x) mx[a[i].y]=a[i].x;
	}
	For(i,0,road.size()-1) 
		if(mn.count(road[i]) && mx.count(road[i]) && mn[road[i]]<mx[road[i]]) {puts("Yes");return 0;}
	puts("No");
	return 0;
}

