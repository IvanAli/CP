#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    if (max(c, d) - min(c, d) > 1) cout << -1 << endl;
    else if (c > a) cout << -1 << endl;
    else if (c > b) cout << -1 << endl;
    else if (d > a) cout << -1 << endl;
    else if (d > b) cout << -1 << endl;
    else if (a == c && b == d) cout << -1 << endl;
    else {
        if (c == d) {
            if (a > c) {
                for (int i = 0; i < a - c - 1; i++) cout << 4;
                for (int i = 0; i < c; i++) cout << 47;
                for (int i = 0; i < b - d; i++) cout << 7;
                cout << 4;
                cout << endl;
            } else {
                cout << 74;
                for (int i = 0; i < a - c; i++) cout << 4;
                for (int i = 0; i < c - 1; i++) cout << 74;
                for (int i = 0; i < b - d; i++) cout << 7;
                cout << endl;
            }
        } else if (c > d) {
            for (int i = 0; i < a - c; i++) cout << 4;
            for (int i = 0; i < c; i++) cout << 47;
            for (int i = 0; i < b - d - 1; i++) cout << 7;
            cout << endl;
        } else {
            cout << 74;
            for (int i = 0; i < a - c - 1; i++) cout << 4;
            for (int i = 0; i < d - 2; i++) cout << 74;
            for (int i = 0; i < b - d + 1; i++) cout << 7;
            if (a > 1) cout << 4;
            cout << endl;
        }
    }
    return 0;
}
