/*
ID: ivanali1
LANG: C++
TASK: transform
*/

#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int N;

bool rotation(const vii& aux, const vii& transformed) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(aux[i][j] != transformed[i][j]) return false;
        }
    }
    return true;
}

void ninety_degree(const vii& matrix, vii& aux) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            aux[j][N - i - 1] = matrix[i][j];
        }
    }
}

void hundred_degree(const vii& matrix, vii& aux) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            aux[N - i - 1][N - j - 1] = matrix[i][j];
        }
    }
}

void twohundredseventy_degree(const vii& matrix, vii& aux) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            aux[N - j - 1][i] = matrix[i][j];
        }
    }
}

void horizontal_reflection(const vii& matrix, vii& aux) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            aux[i][N - j - 1] = matrix[i][j];
        }
    }
}
int main() {
    FILE* fin = fopen("transform.in", "r");
    FILE* fout = fopen("transform.out", "w+");
    fscanf(fin, "%d", &N);
    char str[11];
    vii matrix;
    vii matrix_transformed;
    vii aux_matrix;
    vii aux_matrix2;
    matrix = vii(N, vi(N));
    aux_matrix = vii(N, vi(N));
    aux_matrix2 = vii(N, vi(N));
    matrix_transformed = vii(N, vi(N));
    for(int i = 0; i < N; i++) {
        fscanf(fin, "%s", str);
        for(int j = 0; /*str[j] != '\0'*/ j < N; j++) {
            matrix[i][j] = str[j];
        }
    }
    for(int i = 0; i < N; i++) {
        fscanf(fin, "%s", str);
        for(int j = 0; j < N; j++) {
            matrix_transformed[i][j] = str[j];
        }
    }

    /*
    #1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.
    #2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.
    #3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees.
    #4: Reflection: The pattern was reflected horizontally (turned into a mirror image of itself by reflecting around a vertical line in the middle of the image).
    #5: Combination: The pattern was reflected horizontally and then subjected to one of the rotations (#1-#3).
    #6: No Change: The original pattern was not changed.
    #7: Invalid Transformation: The new pattern was not obtained by any of the above methods.
    */

    /*puts("read matrix");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ffprintf(fout, fout, "%d ", matrix[i][j]);
        }
        fprintf(fout, "\n");
    }
    puts("transformed matrix");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            fprintf(fout, "%d ", matrix_transformed[i][j]);
        }
        fprintf(fout, "\n");
    }*/
    // #1
    ninety_degree(matrix, aux_matrix);
    // puts("ninety degree");
    /*for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            fprintf(fout, "%d ", aux_matrix[i][j]);
        }
        fprintf(fout, "\n");
    }*/
    // check if it's a 90 degree rotation
    if(rotation(aux_matrix, matrix_transformed)) {
        fprintf(fout, "1\n");
        return 0;
    }
    hundred_degree(matrix, aux_matrix);
    if(rotation(aux_matrix, matrix_transformed)) {
        fprintf(fout, "2\n");
        return 0;
    }
    twohundredseventy_degree(matrix, aux_matrix);
    if(rotation(aux_matrix, matrix_transformed)) {
        fprintf(fout, "3\n");
        return 0;
    }
    horizontal_reflection(matrix, aux_matrix);
    if(rotation(aux_matrix, matrix_transformed)) {
        fprintf(fout, "4\n");
        return 0;
    }
    // Combination
    ninety_degree(aux_matrix, aux_matrix2);
    if(rotation(aux_matrix2, matrix_transformed)) {
        fprintf(fout, "5\n");
        return 0;
    }
    hundred_degree(aux_matrix, aux_matrix2);
    if(rotation(aux_matrix2, matrix_transformed)) {
        fprintf(fout, "5\n");
        return 0;
    }
    twohundredseventy_degree(aux_matrix, aux_matrix2);
    if(rotation(aux_matrix2, matrix_transformed)) {
        fprintf(fout, "5\n");
        return 0;
    }
    if(rotation(matrix, matrix_transformed)) {
        fprintf(fout, "6\n");
        return 0;
    }
    fprintf(fout, "7\n");

    return 0;
}
