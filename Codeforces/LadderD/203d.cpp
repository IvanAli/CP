#include <bits/stdc++.h>
#define eps 1e-9
using namespace std;

double a, b, m;
double vx, vy, vz;

int main() {
    cin >> a >> b >> m;
    cin >> vx >> vy >> vz;
    double tx = a / fabs(vx);
    double ty = m / -vy;
    double tz = b / vz;
    int bx = (int)(ty / (tx / 2.)) ? 1 + (ty - tx / 2.) / tx : 0;
    int bz = ty / tz;
    double fm1 = bx ? fmod(ty - tx / 2., tx) : ty;
    double fm2 = fmod(ty, tz);
    double aa, bb;
    if (vx == 0) aa = a / 2.;
    else aa = (fabs(fm1) < eps ? (bx % 2 ? (vx ? a : 0) : (vx ? 0 : a)) : bx ? ((bx % 2 ? (vx < 0 ? fm1 * -vx : a - fm1 * vx) : (vx < 0 ? a - fm1 * -vx : fm1 * vx))) : (a / 2. + fm1 * vx));
    if (vz == 0) bb = 0;
    else bb = (fabs(fm2) < eps ? (bz % 2 ? b : 0) : (bz % 2 ? b - fm2 * vz : fm2 * vz));
    printf("%.10f %.10f\n", aa, bb);
    return 0;
}
