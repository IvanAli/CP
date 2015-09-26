/*
ID: ivanali1
LANG: C++
TASK: friday
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    int N;
    FILE* fin = fopen("friday.in", "r");
    FILE* fout = fopen("friday.out", "w+");
    int currentday = 0;
    // int thirteenth[7];
    vector<int> thirteenth (7, 0);
    // 0 - monday, 1 - tuesday etc
    fscanf(fin, "%d", &N);

    for(int year = 1900; year < 1900 + N; year++) {
        for(int month = 1; month <= 12; month++) {
            // September, April, June and November have 30 days
            if(month == 4 || month == 6 || month == 9 || month == 11) {
                for(int day = 1; day <= 30; day++) {
                    if(day == 13) thirteenth[currentday]++;
                    currentday = (currentday + 1) % 7;
                }
            }
            else {
                if(month == 2) {
                    if(year % 4 == 0) { // leap year maybe
                        if(year % 100 == 0) { // century year
                            if(year % 400 == 0) { // leap year and century year
                                for(int day = 1; day <= 29; day++) {
                                    if(day == 13) thirteenth[currentday]++;
                                    currentday = (currentday + 1) % 7;
                                }
                            }
                            else { // not leap year and century year
                                for(int day = 1; day <= 28; day++) {
                                    if(day == 13) thirteenth[currentday]++;
                                    currentday = (currentday + 1) % 7;
                                }
                            }
                        }
                        else { // not century year, leap year
                            for(int day = 1; day <= 29; day++) {
                                if(day == 13) thirteenth[currentday]++;
                                currentday = (currentday + 1) % 7;
                            }
                        }
                    }
                    else { // not leap year
                        for(int day = 1; day <= 28; day++) {
                            if(day == 13) thirteenth[currentday]++;
                            currentday = (currentday + 1) % 7;
                        }
                    }
                }
                else {
                    for(int day = 1; day <= 31; day++) {
                        if(day == 13) thirteenth[currentday]++;
                        currentday = (currentday + 1) % 7;
                    }
                }
            }
        }
    }
    for(int i = 0; i < 7; i++) {
        if(i) fprintf(fout, " ");
        fprintf(fout, "%d", thirteenth[(i + 5) % 7]);
    }
    fprintf(fout, "\n");
}
