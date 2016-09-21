#include <bits/stdc++.h>
using namespace std;

int b, d;
string a, c;
int dp[105];

int main() {
    cin >> b >> d >> a >> c;
    for (int i = 0; i < c.size(); i++) for (int j = 0; j < a.size(); j++)
    if (a[j] == c[(i + dp[i]) % c.size()]) dp[i]++;
    int ans = 0;
    for (int i = 0; i < b; i++) ans += dp[ans % c.size()];
    cout << ans / (c.size() * d) << endl;
}
