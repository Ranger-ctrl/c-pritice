#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int rows, cols;

    printf("请输入矩阵的行数和列数(以空格分隔): ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0 || rows > MAX_SIZE || cols > MAX_SIZE) {
        printf("错误：请确保行列数在合理范围内。\n");
        return 1;
    }

    int matrix[MAX_SIZE][MAX_SIZE];
    srand(time(NULL));

    printf("随机生成的矩阵 (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("矩阵的转置 (%dx%d):\n", cols, rows);
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}