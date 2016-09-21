#include <bits/stdc++.h>
using namespace std;

int n, k;
double l, v1, v2;
double ans;
//
// double f(double t) {
//     double d1 = v1 * t, d2 = v2 * t;
//     double ret = 0.0, tm = 0.0, tt;
//     for (int i = 0; i < n / k - 1; i++) {
//         ret += d2;
//         tm += t;
//         d1 = v1 * tm;
//         tt = (ret - d1) / (v1 + v2);
//         ret -= v2 * tt;
//         tm += tt;
//     }
//     ret += d2;
//     tm += t;
//     ans = tm;
//     return ret;
// }
//

double f(double t) {
    double ret = 0.0, tm = 0.0, d = 0.0, tt;
    for (int i = 0; i <= (n - 1) / k; i++) {
        tt = (ret - d) / (v1 + v2);
        ret -= v2 * tt;
        d += v1 * tt;
        tm += tt;
        ret += v2 * t;
        d += v1 * t;
        tm += t;
    }
    ans = tm;
    return ret;
}

int main() {
    cin >> n >> l >> v1 >> v2 >> k;
    double low = 0, high = l / v1, mid;
    for (int i = 0; i < 100; i++) {
        mid = (low + high) / 2.;
        if (f(mid) > l) high = mid;
        else low = mid;
    }
    printf("%.10f\n", ans);
}
