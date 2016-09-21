#include <bits/stdc++.h>
using namespace std;

long long n, d;
long long a[105];
int x[105], y[105];
long long dist[105][105];

int main() {
    cin >> n >> d;
    for (int i = 0; i < n - 2; i++) cin >> a[i + 1];
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (i == j) dist[i][j] = 0;
        else dist[i][j] = d * (abs(x[i] - x[j]) + abs(y[i] - y[j])) - a[i];
    }
    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    cout << dist[0][n - 1] << endl;
    return 0;
}
