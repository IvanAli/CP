#include <bits/stdc++.h>
using namespace std;

int x, y, z;
int xx, yy, zz;
int a[6];

int main() {
    cin >> x >> y >> z;
    cin >> xx >> yy >> zz;
    for (int i = 0; i < 6; i++) cin >> a[i];
    int ans = 0;
    if (x > xx) ans += a[5];
    if (x < 0) ans += a[4];
    if (y > yy) ans += a[1];
    if (y < 0) ans += a[0];
    if (z > zz) ans += a[3];
    if (z < 0) ans += a[2];
    cout << ans << endl;
    return 0;
}
