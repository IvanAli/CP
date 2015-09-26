/*
ID: ivanali1
LANG: C++
TASK: beads
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main() {
    FILE* fin = fopen("beads.in", "r");
    FILE* fout = fopen("beads.out", "w+");
    int N;
    char str1[355];
    char str[710];
    bool left, right;
    int countleft, countright;
    char chl, chr;
    fscanf(fin, "%d", &N);
    fscanf(fin, " %s", str1);
    strcpy(str, str1);
    strcat(str, str1);
    /*puts("good");
    fprintf(fout, "%s\n", str);
    fprintf(fout, "%d\n", strlen(str));*/
    left = true; right = true;
    countleft = 0; countright = 0;
    int indexleft = 0, indexright = 0;
    int sum = 0;
    int cutindex = 0;
    for(int i = 1; i < 2 * N; i++) {
        indexleft = i - 1;
        indexright = i;
        left = true; right = true;
        chl = str[indexleft];
        chr = str[indexright];
        countleft = 0; countright = 0;
        while(left || right) {
            if(left) {
                if((str[indexleft] == chl || str[indexleft] == 'w') && indexleft >= 0) {
                    countleft++;
                    indexleft--;
                    if(indexleft >= 0) {
                        if(str[indexleft] != 'w' && chl == 'w') chl = str[indexleft];
                    }

                }
                else left = false;
            }
            if(right) {
                if((str[indexright] == chr || str[indexright] == 'w') && indexright < 2 * N) {
                    // if(str[indexright] == 'w' && chr != 'w')
                    countright++;
                    indexright++;
                    if(indexright < 2 * N)
                        if(str[indexright] != 'w' && chr == 'w') chr = str[indexright];
                }
                else right = false;
            }
        }
        if(countleft + countright >= sum) {
            sum = countleft + countright;
            cutindex = i;
        }
    }
    fprintf(fout, "%d\n", sum > N ? N : sum);
    // fprintf(fout, "cut index: %d\n", cutindex);
    return 0;
}
