#include <bits/stdc++.h>
using namespace std;

int n;
string t, a, b;
struct type {
    int t, ast, amp;
    type() : t(0), ast(0), amp(0) {}
    type(int t, int ast, int amp) : t(t), ast(ast), amp(amp) {}
};

map<string, type> mp;

int main() {
    cin >> n;
    mp["void"];
    mp["errtype"] = type(1, 0, 0);
    while (n--) {
        cin >> t >> a;
        if (t == "typedef") {
            cin >> b;
            string s = "";
            int amp = 0, ast = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == '*') ast++;
                else if (a[i] == '&') amp++;
                else s += a[i];
            }
            if (!mp.count(s)) continue;
            type aa = mp[s];
            type bb = aa;
            bb.ast += ast;
            bb.amp += amp;
            if (bb.amp > bb.ast) bb.t = 1;
            mp[b] = bb;
        } else {
            int amp = 0, ast = 0;
            string s = "";
            for (int i = 0; i < a.size(); i++) {
                if (a[i] == '*') ast++;
                else if (a[i] == '&') amp++;
                else s += a[i];
            }
            if (!mp.count(s)) cout << "errtype" << endl;
            else {
                type aa = mp[s];
                aa.amp += amp;
                aa.ast += ast;
                if (aa.amp > aa.ast) aa.t = 1;
                if (aa.t == 0) {
                    cout << "void";
                    for (int i = 0; i < aa.ast - aa.amp; i++) cout << "*";
                    cout << endl;
                } else {
                    cout << "errtype" << endl;
                }
            }
        }
    }
    return 0;
}
