#include <bits/stdc++.h>
#define eps 1e-9
using namespace std;

double s, a, b, c;
double x, y, z;

int main() {
    cin >> s;
    cin >> a >> b >> c;
    if (a < eps && b < eps && c < eps) {
        cout << fixed << setprecision(12) << x << " " << y << " " << z << endl;
    } else {
        x = a * s / (a + b + c);
        y = b * s / (a + b + c);
        z = c * s / (a + b + c);
        cout << fixed << setprecision(12) << x << " " << y << " " << z << endl;
    }
    return 0;
}
