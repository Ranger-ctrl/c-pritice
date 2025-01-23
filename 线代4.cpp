#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int rowsA, colsA, rowsB, colsB;

    printf("请输入第一个矩阵的行数和列数(以空格分隔): ");
    scanf("%d %d", &rowsA, &colsA);

    printf("请输入第二个矩阵的行数和列数(以空格分隔): ");
    scanf("%d %d", &rowsB, &colsB);

    if (colsA != rowsB) {
        printf("错误：矩阵A的列数必须等于矩阵B的行数。\n");
        return 1;
    }

    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    srand(time(NULL));

    printf("随机生成的矩阵A (%dx%d):\n", rowsA, colsA);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            matrixA[i][j] = rand() % 10;
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("随机生成的矩阵B (%dx%d):\n", rowsB, colsB);
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            matrixB[i][j] = rand() % 10;
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    printf("矩阵A与矩阵B的乘积 (%dx%d):\n", rowsA, colsB);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}