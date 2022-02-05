#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define ll long long
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define g(x) (x - (ll)(sqrt(x)))

int n, q, a[200005];

struct node
{
	int l, r;
	ll setv, addv, sumv, mn, mx;
}t[800005];

int read()
{
	int x = 0, fl = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') fl = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
	return x * fl;
}

void push_up(int p)
{
	t[p].sumv = t[ls(p)].sumv + t[rs(p)].sumv;
	t[p].mx = max(t[ls(p)].mx, t[rs(p)].mx);
	t[p].mn = min(t[ls(p)].mn, t[rs(p)].mn);
	return;
}

void push_down(int p)
{
	if (t[p].setv != -1)
	{
		t[ls(p)].addv = t[rs(p)].addv = 0;
		t[ls(p)].setv = t[rs(p)].setv = t[p].setv;
		t[ls(p)].sumv = 1ll * t[p].setv * (t[ls(p)].r - t[ls(p)].l + 1);
		t[rs(p)].sumv = 1ll * t[p].setv * (t[rs(p)].r - t[rs(p)].l + 1);
		t[ls(p)].mn = t[p].setv, t[rs(p)].mn = t[p].setv;
		t[ls(p)].mx = t[p].setv, t[rs(p)].mx = t[p].setv;
		t[p].setv = -1;
	}
	if (t[p].addv)
	{
		t[ls(p)].addv += t[p].addv;
		t[rs(p)].addv += t[p].addv;
		t[ls(p)].sumv += 1ll * t[p].addv * (t[ls(p)].r - t[ls(p)].l + 1);
		t[rs(p)].sumv += 1ll * t[p].addv * (t[rs(p)].r - t[rs(p)].l + 1);
		t[ls(p)].mn += t[p].addv, t[rs(p)].mn += t[p].addv;
		t[ls(p)].mx += t[p].addv, t[rs(p)].mx += t[p].addv;
		t[p].addv = 0;
	}
	return;
}

void build(int p, int l0, int r0)
{
	t[p].l = l0; t[p].r = r0; t[p].setv = -1;
	if (l0 == r0)
	{
		t[p].sumv = t[p].mn = t[p].mx = a[l0];
		return;
	}
	int mid = (l0 + r0) >> 1;
	build(ls(p), l0, mid);
	build(rs(p), mid + 1, r0);
	push_up(p);
	return;
}

void update(int p, int l0, int r0, ll d, int tp)
{
	if (l0 <= t[p].l && t[p].r <= r0)
	{
		if (tp == 1) // set
		{
			t[p].setv = d; t[p].addv = 0;
			t[p].sumv = d * (t[p].r - t[p].l + 1);
			t[p].mn = t[p].mx = d;
			return;
		} 
		else if (tp == 2) // add
		{
			t[p].addv += d; t[p].mn += d; t[p].mx += d;
   			t[p].sumv += d * (t[p].r - t[p].l + 1);
			return;
		}
		else // sqrt
		{
			if (g(t[p].mx) == g(t[p].mn))
			{
				ll v = -g(t[p].mx);
				t[p].sumv += 1ll * (t[p].r - t[p].l + 1) * v;
				t[p].addv += v; t[p].mn += v; t[p].mx += v;
				return;
			}
		}
	}
	push_down(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (l0 <= mid) update(ls(p), l0, r0, d, tp);
	if (r0 > mid) update(rs(p), l0, r0, d, tp);
	push_up(p);
	return;
}

ll query(int p, int l0, int r0)
{
	if (l0 <= t[p].l && t[p].r <= r0) return t[p].sumv;
	push_down(p);
	int mid = (t[p].l + t[p].r) >> 1; ll sum = 0;
	if (l0 <= mid) sum += query(ls(p), l0, r0);
	if (r0 > mid) sum += query(rs(p), l0, r0);
	return sum;
}

struct nnode {
	int l,r;
	friend bool operator < (nnode a,nnode b) {
		return a.r-a.l>b.r-b.l;	
	}
};
priority_queue <nnode> qq;
vector <nnode> ve;
int main()
{
//	n = read(); q = read();
//	for (int i = 1; i <= n; i ++ )
//		a[i] = read();
//	build(1, 1, n);
//	while (q -- )
//	{
//		int opt = read();
//		if (opt == 1) // query
//		{
//			int l0 = read(), r0 = read();
//			printf("%lld\n", query(1, l0, r0));
//		}
//		else if (opt == 2) // set
//		{
//			int l0 = read(), r0 = read(), x = read();
//			update(1, l0, r0, x, 1);
//		}
//		else if (opt == 3) // add
//		{
//			int l0 = read(), r0 = read(), x = read();
//			update(1, l0, r0, x, 2);
//		}
//		else
//		{
//			int l0 = read(), r0 = read();
//			update(1, l0, r0, 0, 3);
//		}
//	}
	cin>>n>>q;
	for(int i=1;i<=n;i++) a[i]=1;
	build(1,1,n);
	while(q--) {
		int x,y;
		cin>>x>>y;
		qq.push((nnode) {x,y});
	}
	while(!qq.empty()) {
			nnode now=qq.top();
			qq.pop();
			int lll=now.l,rrr=now.r;
			if(query(1,lll,rrr)!=1) {
				ve.clear();
				while(!qq.empty() && query(1,lll,rrr)!=1) {
					ve.push_back(now);
					now=qq.top();
					qq.pop();
					lll=now.l, rrr=now.r;	
				}
				if(qq.empty() && query(1,lll,rrr)!=1) {
					puts("No");
					return 0;
				} else if(query(1,lll,rrr)==1) {
					update(1,lll,rrr,0,1);	
					for(int i=0;i<ve.size();i++) qq.push(ve[i]);
				}
			} else update(1,lll,rrr,0,1);
		}
	puts("Yes");
	return 0;
}
