/*Author: Ivan
    UVA 11450 - Wedding Shopping
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[25][25];
int memo[205][25];
int dp[25][201];
int T, M, C;

// top-down approach
int buy(int money, int garment) {
    if(money < 0) return -10000000;
    if(garment == C) return M - money;
    if(memo[money][garment] != -1) return memo[money][garment];
    int ans = -1;
    for(int j = 1; j <= arr[garment][0]; j++) {
        ans = max(ans, buy(money - arr[garment][j], garment + 1));
    }
    return memo[money][garment] = ans;
}

// bottom-up approach
int dpbuild() {
    for(int i = 1; i <= arr[0][0]; i++) {
        if(M - arr[0][i] >= 0) dp[0][M - arr[0][i]] = 1;
    }
    for(int k = 0; k < C - 1; k++) {
        for(int i = 0; i <= 200; i++) {
            if(dp[k][i])
                for(int j = 1; j <= arr[k + 1][0]; j++)
                    if(i - arr[k + 1][j] >= 0) dp[k + 1][i - arr[k + 1][j]] = 1;
        }
    }
    for(int i = 0; i <= 200; i++)
        if(dp[C - 1][i]) return M - i;
    return -1;
}

int main() {

    scanf("%d", &T);
    for(int t = 0; t < T; t++) {
        scanf("%d %d", &M, &C);
        // memset(memo, -1, sizeof memo);
        memset(dp, 0, sizeof dp);
        for(int c = 0; c < C; c++) {
            scanf("%d", &arr[c][0]);
            for(int i = 1; i <= arr[c][0]; i++) {
                scanf("%d", &arr[c][i]);
            }
        }

        // algorithm
        // int ans = buy(M, 0);
        int ans = dpbuild();
        if(ans < 0) printf("no solution\n");
        else printf("%d\n", ans);
    }
    return 0;
}
