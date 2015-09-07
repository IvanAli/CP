// Author: Ivan
//  UVA 10040 - Game Show Math
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

#define PLUS 0
#define MINUS 1
#define BY 2
#define DIVIDEDBY 3

int T;
int array[100];
char op[100];
bool found;
/*
void backtrack(int pos, int value, int operation) {
  if(found) return;
  if(pos == array[0] + 1) {
    op[pos - 2] = '=';
    if(value == array[array[0] + 1]) {
      found = true;
      for(int i = 1; i <= array[0]; i++) {
        printf("%d", array[i]);
        printf("%c", op[i - 1]);
      }
      printf("%d", array[array[0] + 1]);
      printf("\n");
    }
    return;
  }

  if(operation == PLUS) {
    value += array[pos];
    op[pos - 2] = '+';
  }
  if(operation == MINUS) {
    value -= array[pos];
    op[pos - 2] = '-';
  }
  if(operation == BY) {
    value *= array[pos];
    op[pos - 2] = '*';
  }
  if(operation == DIVIDEDBY && value % array[pos] == 0) {
    value /= array[pos];
    op[pos - 2] = '/';
  }

  backtrack(pos + 1, value, PLUS);
  backtrack(pos + 1, value, MINUS);
  backtrack(pos + 1, value, BY);
  backtrack(pos + 1, value, DIVIDEDBY);
}
*/

int dp[101][64001];
stack<char> stk;

void fillStack(int p, int k) {
    int target = array[array[0] + 1];
    if(!p) return;
    stk.push(dp[p][k]);
    if(dp[p][k] == '+')
        fillStack(p - 1, ((k - 32000) - array[p + 1]) + 32000);
    if(dp[p][k] == '-')
        fillStack(p - 1, ((k - 32000) + array[p + 1]) + 32000);
    if(dp[p][k] == '*')
        fillStack(p - 1, ((k - 32000) / array[p + 1]) + 32000);
    if(dp[p][k] == '/')
        fillStack(p - 1, ((k - 32000) * array[p + 1]) + 32000);
}

void dpbuild() {
    int p = array[0];
    int target = array[array[0] + 1];
    dp[0][array[1] + 32000] = 1;
    /*for(int i = 1; i <= p; i++) {
        if(i == 1) printf("Working with %d\n", array[i]);
        dp[0][array[i] + 32000] = 1;
    }*/
    /*for(int i = 0; i < 10; i++) {
        printf("%d: %d, ", i, dp[0][i + 32000]);
    }*/
    // printf("\n");
    for(int i = 1; i < p; i++) {
        for(int j = -32000; j <= 32000; j++) {
            if(dp[i - 1][j + 32000]) {
                if(abs(j + array[i + 1]) <= 32000)
                    dp[i][j + array[i + 1] + 32000] = '+';
                if(abs(j - array[i + 1]) <= 32000)
                    dp[i][j - array[i + 1] + 32000] = '-';
                if(abs(j * array[i + 1]) <= 32000)
                    dp[i][j * array[i + 1] + 32000] = '*';
                if(abs(j / array[i + 1]) <= 32000)
                    if(!(j % array[i + 1])) dp[i][j / array[i + 1] + 32000] = '/';
                // dp[i][j / array[i + 1] + 32000] = (!(j % array[i + 1])) ? 1 : 0;
            }
        }
        /*printf("Iteration: %d\n", i);
        for(int x = -10; x < 51; x++) {
            printf("h%d: %d, ", x, dp[i][x + 32000]);
        }
        printf("\n");*/
    }
    /*for(int i = 0; i < 50; i++) {
        printf("%d:%d, ", i, dp[p - 1][i + 32000]);
    }*/
    while(!stk.empty()) stk.pop();
    if(dp[p - 1][target + 32000]) {
        stk.push('=');
        fillStack(p - 1, target + 32000);
        for(int i = 1; i <= p; i++) {
            printf("%d", array[i]);
            printf("%c", stk.top()); stk.pop();
        }
        printf("%d\n", array[p + 1]);
    }
    else printf("NO EXPRESSION\n");

}

int main() {

  scanf("%d", &T);
  for(int t = 0; t < T; t++) {
      memset(array, 0, sizeof array);
      // memset(op, '\0', sizeof op);
      memset(dp, 0, sizeof dp);
      // found = false;
      scanf("%d", &array[0]);
      for(int i = 0; i < array[0]; i++) scanf("%d", &array[i + 1]);
      scanf("%d", &array[array[0] + 1]);

      // algorithm
      /*backtrack(1, array[1], -1);
      if(!found) printf("NO EXPRESSION\n");*/
      dpbuild();
  }

  return 0;
}
