#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
double determinant(int n, double mat[MAX_SIZE][MAX_SIZE]) {
    double det = 0;
    if (n == 1)
        return mat[0][0];
    if (n == 2)
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

    double temp[MAX_SIZE][MAX_SIZE];
    int sign = 1;

    for (int f = 0; f < n; f++) {
        int m = 0, n;
        for (int i = 1; i < n; i++) {
            n = 0;
            for (int j = 0; j < n; j++) {
                if (j == f)
                    continue;
                temp[m][n] = mat[i][j];
                n++;
            }
            m++;
        }
        det += sign * mat[0][f] * determinant(n - 1, temp);
        sign = -sign;
    }
    return det;
}


void cofactor(int n, double mat[MAX_SIZE][MAX_SIZE], double cof[MAX_SIZE][MAX_SIZE]) {
    if (n == 1) {
        cof[0][0] = 1;
        return;
    }

    int sign = 1;
    double temp[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int m = 0, n;
            for (int row = 0; row < n; row++) {
                if (row == i)
                    continue;
                n = 0;
                for (int col = 0; col < n; col++) {
                    if (col == j)
                        continue;
                    temp[m][n] = mat[row][col];
                    n++;
                }
                m++;
            }
            cof[j][i] = ((sign) * determinant(n - 1, temp));
            sign = -sign;
        }
    }
}

void printMatrix(int n, double mat[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%.2f ", mat[i][j]);
        printf("\n");
    }
}

int main() {
    int n;

    printf("请输入矩阵的阶数（至少为3）: ");
    scanf("%d", &n);

    if (n < 3 || n > MAX_SIZE) {
        printf("错误：请确保矩阵阶数在合理范围内。\n");
        return 1;
    }

    double mat[MAX_SIZE][MAX_SIZE];
    printf("请输入矩阵的元素:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &mat[i][j]);

    double cof[MAX_SIZE][MAX_SIZE];
    cofactor(n, mat, cof);

    printf("伴随矩阵:\n");
    printMatrix(n, cof);

    return 0;
}