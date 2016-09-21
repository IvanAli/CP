#include <bits/stdc++.h>
using namespace std;

int t;
double a, b;

int main() {
    scanf("%d", &t);
    double ans;
    for (int i = 0; i < t; i++) {
        scanf("%lf %lf", &a, &b);
        if (a == 0 && b == 0) {
            ans = 1;
        } else if (a == 0) {
            ans = (b + min(b, a / 4.)) / (2 * b);
        } else if (b == 0) {
            ans = 1;
        } else {
            double q = min(a / 4., b);
            double p = 4 * q;
            ans = 4 * q * q / 2. + max(0.0, a - 4 * q) * q;
            ans /= (2 * a * b);
            ans += 0.5;
        }
        printf("%.10f\n", ans);
    }
}
