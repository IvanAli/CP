// 81

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define INF 1e9

#define MAX_M 80
#define MAX_N 80


int memo[MAX_M][MAX_N];

int stringToNumber(char* pch) {
    int base = 10;
    int result = 0;
    for(int i = 0; pch[i] != '\0'; i++) {
        result = base * result + pch[i] - '0';
    }
    return result;
}

int findShortestPath(int matrix[MAX_N][MAX_M], int i, int j, int M, int N) {
    if(i == M && j == N - 1) return 0;
    if(i == M - 1 && j == N) return 0;
    if(i == M || j == N) return INF;
    if(memo[i][j] != -1) return memo[i][j];
    return memo[i][j] = min(findShortestPath(matrix, i + 1, j, N, M), findShortestPath(matrix, i, j + 1, N, M)) + matrix[i][j];
}

int main() {
    char input[100000];
    int matrix[MAX_N][MAX_M];
    memset(memo, -1, sizeof memo);
    int i = 0, j = 0;
    /*matrix[0][0] = 131; matrix[0][1] = 673; matrix[0][2] = 234; matrix[0][3] = 103; matrix[0][4] = 18;
    matrix[1][0] = 201; matrix[1][1] = 96; matrix[1][2] = 342; matrix[1][3] = 965; matrix[1][4] = 150;
    matrix[2][0] = 630; matrix[2][1] = 803; matrix[2][2] = 746; matrix[2][3] = 422; matrix[2][4] = 111;
    matrix[3][0] = 537; matrix[3][1] = 699; matrix[3][2] = 497; matrix[3][3] = 121; matrix[3][4] = 956;
    matrix[4][0] = 805; matrix[4][1] = 732; matrix[4][2] = 524; matrix[4][3] = 37; matrix[4][4] = 331;*/
    FILE* fin = fopen("p081_matrix.txt", "r");
    for(i = 0; i < MAX_N; i++) {
        j = 0;
        fscanf(fin, "%s", input);
        char* pch = strtok(input, ",");
        if(i == 0) printf("%s\n", pch);
        while(pch != NULL) {
            matrix[i][j++] = stringToNumber(pch);
            pch = strtok(NULL, ",");
        }
    }
    int ans = findShortestPath(matrix, 0, 0, MAX_M, MAX_N);
    printf("ans: %d\n", ans);
}
