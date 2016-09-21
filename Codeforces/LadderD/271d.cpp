#include <bits/stdc++.h>
using namespace std;

string s;
string t;
int k;
struct Node {
    Node* children[26];
    Node() {
        for (int i = 0; i < 26; i++) children[i] = NULL;
    }
} *root;

void insert(int x) {
    Node* curr = root;
    for (int i = x; i < s.size(); i++) {
        int p = s[i] - 'a';
        if (!curr->children[p]) curr->children[p] = new Node();
        curr = curr->children[p];
    }
}

int solve() {
    int ret = 0;
    queue<Node*> q;
    queue<int> q2;
    q.push(root);
    q2.push(0);
    while (!q.empty()) {
        Node* curr = q.front();
        int bad = q2.front();
        q.pop();
        q2.pop();
        for (int i = 0; i < 26; i++) {
            if (curr->children[i]) {
                if (bad + 1 - t[i] + '0' <= k) {
                    q.push(curr->children[i]);
                    q2.push(bad + 1 - t[i] + '0');
                    ret++;
                }
            }
        }
    }
    return ret;
}

int main() {
    cin >> s;
    cin >> t;
    cin >> k;
    root = new Node();
    for (int i = 0; i < s.size(); i++) insert(i);
    int ans = solve();
    cout << ans << endl;
    return 0;
}
