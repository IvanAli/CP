#include <bits/stdc++.h>
#define pb push_back
#define MAXN 100000
using namespace std;

int n;
int a[100005];
int b[100005];
int used[100005];
int factor[100005][205];
int factorsz[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= MAXN; i++) {
        for (int j = i; j <= MAXN; j += i) {
            factor[j][factorsz[j]] = i;
            factorsz[j]++;
        }
    }
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    memset(used, -1, sizeof used);
    for (int i = 0; i < n; i++) {
        int ans = 0;
        for (int j = 0; j < factorsz[a[i]]; j++) {
            int fact = factor[a[i]][j];
            if (used[fact] + b[i] < i) ans++;
            used[fact] = i;
        }
        cout << ans << endl;
    }
    return 0;
}
