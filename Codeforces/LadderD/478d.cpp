#include <bits/stdc++.h>
#define mp make_pair
#define INF 1e9
using namespace std;

typedef pair<int, int> ii;

const int mod = 1e9 + 7;
int r, g;
int dp[2][400005];

int main() {
    cin >> r >> g;
    dp[0][0] = 1;
    int h;
    for (h = 0; ((h * h + h) >> 1) <= r + g; h++); h--;
    for (int i = 1; i <= h; i++) for (int j = 0; j <= r; j++)
    dp[i % 2][j] = (dp[(i - 1) % 2][j] + (i <= j ? dp[(i - 1) % 2][j - i] : 0)) % mod;
    int ans = 0;
    for (int i = 0; i <= r; i++) if (((h * h + h) >> 1) - i <= g) ans = (ans + dp[h % 2][i]) % mod;
    cout << ans << endl;
    return 0;
}
