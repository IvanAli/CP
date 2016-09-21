#include <bits/stdc++.h>
using namespace std;

long long n, m;
bool row[100005];
bool col[100005];

int main() {
    cin >> n >> m;
    long long ans = n * n;
    long long side1 = n, side2 = n;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (!row[a]) side1--;
        if (!col[b]) side2--;
        cout << side1 * side2 << " ";
        row[a] = true;
        col[b] = true;
    }
    cout << endl;
    return 0;
}
