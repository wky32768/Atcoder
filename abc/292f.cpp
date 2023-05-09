#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long
#define For(i, a, b)  for(int i = a; i <= b;i ++)

using namespace std;
const int N = 200005;

double a, b, ans;

signed main() {
    cin >> a >> b;
    if(a > b) swap(a, b);
    if(b > 2.0 * sqrt(3.0) / 3 * a) {
        printf("%.10lf", 2 * sqrt(3.0) / 3 * a);
    } else {
        double sita = atan(2.0 * b / a - sqrt(3.0));
        printf("%.10lf", a / cos(sita));
    }
    return 0;
}