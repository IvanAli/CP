#include <bits/stdc++.h>
#define INF 1e9
#define fst first
#define snd second
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int r, c;
char grid[1005][1005];
int dist[1005][1005];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

void get(int& sr, int& sc, char ch) {
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
        if (grid[i][j] == ch) {
            sr = i;
            sc = j;
            return;
        }
    }
}

void bfs() {
    queue<ii> q;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) dist[i][j] = INF;
    int sr, sc;
    get(sr, sc, 'E');
    q.push(ii(sr, sc));
    dist[sr][sc] = 0;
    while (!q.empty()) {
        ii top = q.front();
        q.pop();
        int row = top.fst, col = top.snd;
        for (int i = 0; i < 4; i++) {
            int rr = row + dr[i];
            int cc = col + dc[i];
            if (rr < 0 || rr >= r || cc < 0 || cc >= c) continue;
            if (grid[rr][cc] == 'T') continue;
            if (dist[rr][cc] == INF) {
                dist[rr][cc] = dist[row][col] + 1;
                q.push(ii(rr, cc));
            }
        }
    }
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) grid[i][j] = s[j];
    }
    bfs();
    int pr, pc;
    get(pr, pc, 'S');
    int d = dist[pr][pc];
    int ans = 0;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
        if (grid[i][j] > '0' && grid[i][j] <= '9') {
            if (dist[i][j] <= d) ans += grid[i][j] - '0';
        }
    }
    cout << ans << endl;
}
