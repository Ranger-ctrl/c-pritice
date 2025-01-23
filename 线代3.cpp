#include <stdio.h>

int main() {
    double matrix[3][3];
    double sum = 0.0;

    printf("请输入一个3x3矩阵的元素:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        sum += matrix[i][i];
    }

    printf("主对角线元素之和: %.2f\n", sum);

    return 0;
}