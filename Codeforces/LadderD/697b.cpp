#include <bits/stdc++.h>
using namespace std;

string s;

bool zeros(int a, int b) {
    for (int i = a; i < b; i++) if (s[i] != '0') return false;
    return true;
}

int main() {
    cin >> s;
    int e = s.find('e');
    int dot = s.find('.');
    int len = e - 1;
    int n = 0;
    for (int i = e + 1; i < s.size(); i++) n = n * 10 + s[i] - '0';
    dot += n;
    for (int i = 0; i <= dot; i++) {
        if (i >= e) cout << 0;
        else if (s[i] == '.') continue;
        else cout << s[i];
    }
    if (zeros(dot + 1, e)) {
        cout << endl;
        return 0;
    }
    if (dot < e - 1) cout << ".";
    for (int i = dot + 1; i < e; i++) cout << s[i];
    // for (int i = 0; i < 2 * n - dot - 2; i++) cout << 0;
    cout << endl;
    return 0;
}
