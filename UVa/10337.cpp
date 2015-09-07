/*Author: Ivan
    UVA 10337 - Flight Planner
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int flight[10][1001];
int memo[10][100000];
int X;

int optimalFlight(int r, int c) {
    if(r < 0 || r > 9) return 1 << 30;
    if(c == (X / 100)) {
        if(r == 0) return 0;
        return 1 << 30;
    }
    int ans = 1 << 30;
    if(memo[r][c] != -1) return memo[r][c];
    ans = min(
        optimalFlight(r, c + 1) + 30 - flight[9 - r][c],
        min(optimalFlight(r + 1, c + 1) + 60 - flight[9 - r][c],
        optimalFlight(r - 1, c + 1) + 20 - flight[9 - r][c])
    );
    return memo[r][c] = ans;
}

int main() {
    int T;

    scanf("%d", &T);
    for(int t = 0; t < T; t++) {
        scanf("%d", &X);
        // if(t) printf("\n");
        memset(memo, -1, sizeof memo);
        memset(flight, 0, sizeof flight);
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < (X / 100); j++) {
                scanf("%d", &flight[i][j]);
            }
        }
        // algorithm
        int ans = optimalFlight(0, 0);
        printf("%d\n\n", ans);
    }
    return 0;
}
