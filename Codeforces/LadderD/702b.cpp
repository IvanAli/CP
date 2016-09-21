#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005];
map<long long, long long> hash;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (long long j = 1; j <= (long long)1e13; j <<= 1LL) {
            if (hash.count(j - a[i])) {
                ans += hash[j - a[i]];
            }
        }
        hash[a[i]]++;
    }
    cout << ans << endl;
    return 0;
}
