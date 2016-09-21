#include <bits/stdc++.h>
using namespace std;

int n;
int p[2000005];

void go(int k) {
    int r = n / k;
    if (r * k < n) p[n + k - 2] = p[r * k + k - 2];
    for (int i = r - 1; i >= 0; i--) {
        p[i * k + k + k - 2] = p[i * k + k - 2];
        // p[i * k + k - 2] = p[i * k - 2];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < n - 1; i++) go(i + 2);
    for (int i = 0; i < n; i++) cout << p[i + n - 1] + 1 << " ";
    cout << endl;
    return 0;
}
