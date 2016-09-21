#include <bits/stdc++.h>
#define MAXN 200005
#define MAXM 2000005
#define pb push_back
using namespace std;

int n;
int b[MAXM];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[x] = x;
    }
    int ans = 0;
    for (int i = 1; i < MAXM; i++) if (b[i] == 0) b[i] = b[i - 1];
    for (int i = 1; i < MAXM; i++) {
        if (b[i] == i) {
            for (int j = i << 1; j < MAXM; j += i) ans = max(ans, b[j - 1] % i);
        }
    }
    cout << ans << endl;
}
