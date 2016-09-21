#include <bits/stdc++.h>
using namespace std;

int n;
double p[105];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    double ans = 0.0;
    sort(p, p + n);
    for (int i = 0; i < n; i++) if (p[i] >= 0.5) ans = max(ans, p[i]);
    if (ans > 0) {
        printf("%.12f\n", ans);
    } else {
        double curr = 0.0, no = 1.0;
        for (int i = n - 1; i >= 0; i--) {
            ans = max(ans, p[i] * (1 - p[i + 1] + p[i + 1] * (1 - p[i])));
            curr *= (1.0 - p[i]);
            curr += no * p[i];
            no *= (1.0 - p[i]);
            ans = max(ans, curr);
        }
        printf("%.12f\n", ans);
    }
    return 0;
}
