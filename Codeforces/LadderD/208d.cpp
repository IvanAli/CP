#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

ll n, a, b, c, d, e;
ll p[55];
ll ans[5];
ll sum;
int prizes[5];

int main() {
    cin >> n;
    memset(ans, 0L, sizeof ans);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < 5; i++) cin >> prizes[i];
    sum = 0;
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        sum += p[i];
        for (int j = 4; j >= 0; j--) {
            ans[j] += (sum / prizes[j]);
            sum %= prizes[j];
        }
    }
    for (int i = 0; i < 5; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    cout << sum << endl;
    return 0;
}
