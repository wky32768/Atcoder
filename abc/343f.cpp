#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>

#define int long long
#define For(i, a, b) for(int i = a; i <= b; ++i)
#define l_rt (rt << 1)
#define r_rt (rt << 1 | 1)


using namespace std;

const int N = 2e5 + 5;

int n, q, a[N], opt, x, y;
int mx[N << 2], mx_num[N << 2], se[N << 2], se_num[N << 2];

// using a segment tree to store the largest and second largest number in a range and the number of times they appear

void push_up(int rt) {
    if(mx[l_rt] > mx[r_rt]) {
        mx[rt] = mx[l_rt];
        mx_num[rt] = mx_num[l_rt];
        if(se[l_rt] > mx[r_rt]) {
            se[rt] = se[l_rt];
            se_num[rt] = se_num[l_rt];
        } else if(se[l_rt] < mx[r_rt]) {
            se[rt] = mx[r_rt];
            se_num[rt] = mx_num[r_rt];
        } else {
            se[rt] = se[l_rt];
            se_num[rt] = se_num[l_rt] + mx_num[r_rt];
        }
    } else if(mx[l_rt] < mx[r_rt]) {
        mx[rt] = mx[r_rt];
        mx_num[rt] = mx_num[r_rt];
        if(mx[l_rt] > se[r_rt]) {
            se[rt] = mx[l_rt];
            se_num[rt] = mx_num[l_rt];
        } else if(mx[l_rt] < se[r_rt]) {
            se[rt] = se[r_rt];
            se_num[rt] = se_num[r_rt];
        } else {
            se[rt] = mx[l_rt];
            se_num[rt] = mx_num[l_rt] + se_num[r_rt];
        }
    } else {
        mx[rt] = mx[l_rt];
        mx_num[rt] = mx_num[l_rt] + mx_num[r_rt];
        if(se[l_rt] > se[r_rt]) {
            se[rt] = se[l_rt];
            se_num[rt] = se_num[l_rt];
        } else if(se[l_rt] < se[r_rt]) {
            se[rt] = se[r_rt];
            se_num[rt] = se_num[r_rt];
        } else {
            se[rt] = se[l_rt];
            se_num[rt] = se_num[l_rt] + se_num[r_rt];
        }
    }
}

void build(int rt, int l, int r) {
    if(l == r) {
        mx[rt] = a[l];
        mx_num[rt] = 1;
        se[rt] = -1;
        se_num[rt] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l_rt, l, mid);
    build(r_rt, mid + 1, r);
    push_up(rt);
}

void change(int rt, int l, int r, int x, int y) {
    if(l == r) {
        mx[rt] = y;
        mx_num[rt] = 1;
        se[rt] = -1;
        se_num[rt] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) change(l_rt, l, mid, x, y);
    else change(r_rt, mid + 1, r, x, y);
    push_up(rt);
}

struct node {
    int mx, mx_num, se, se_num;
};

// search for the number of times of the second largest number in a range
node query(int rt, int l, int r, int x, int y) {
    if(x <= l && r <= y) {
        return (node){mx[rt], mx_num[rt], se[rt], se_num[rt]};
    }
    int mid = (l + r) >> 1;
    if(y <= mid) return query(l_rt, l, mid, x, y);
    else if(x > mid) return query(r_rt, mid + 1, r, x, y);
    else {
        node left = query(l_rt, l, mid, x, y);
        node right = query(r_rt, mid + 1, r, x, y);
        node res;
        if(left.mx > right.mx) {
            res.mx = left.mx;
            res.mx_num = left.mx_num;
            if(left.se > right.mx) {
                res.se = left.se;
                res.se_num = left.se_num;
            } else if(left.se < right.mx) {
                res.se = right.mx;
                res.se_num = right.mx_num;
            } else {
                res.se = left.se;
                res.se_num = left.se_num + right.mx_num;
            }
        } else if(left.mx < right.mx) {
            res.mx = right.mx;
            res.mx_num = right.mx_num;
            if(left.mx > right.se) {
                res.se = left.mx;
                res.se_num = left.mx_num;
            } else if(left.mx < right.se) {
                res.se = right.se;
                res.se_num = right.se_num;
            } else {
                res.se = left.mx;
                res.se_num = left.mx_num + right.se_num;
            }
        } else {
            res.mx = left.mx;
            res.mx_num = left.mx_num + right.mx_num;
            if(left.se > right.se) {
                res.se = left.se;
                res.se_num = left.se_num;
            } else if(left.se < right.se) {
                res.se = right.se;
                res.se_num = right.se_num;
            } else {
                res.se = left.se;
                res.se_num = left.se_num + right.se_num;
            }
        }
        return res;
    }
}


signed main() {
    cin >> n >> q;
    For(i, 1, n) cin >> a[i];
    build(1, 1, n);
    while(q--) {
        cin >> opt >> x >> y;
        if(opt == 1) {
            change(1, 1, n, x, y);
        } else {
            node res = query(1, 1, n, x, y);
            cout << res.se_num << '\n';
        }
    }

    return 0;
}