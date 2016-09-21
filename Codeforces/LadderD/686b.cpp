#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];

int ok(int l) {
    int r = l + 1;
    int temp;
    while (r < n && a[l] > a[r]) {
        temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        l += 2;
        r = l + 1;
    }
    return r - 2;
}


int main() {
    cin >> n;
    srand(time(NULL));
    for (int i = 0; i < n; i++) cin >> a[i];
    int i;
    int j = -1;
    for (int it = 0; it < 20000; it++) {
        i = rand() % n;
        j = ok(i);
        if (j > i) cout << i + 1 << " " << j + 1 << endl;
    }
    return 0;
}
