#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4
void print_matrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_multiply(int result[SIZE][SIZE], int a[SIZE][SIZE], int b[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}


void matrix_add(int result[SIZE][SIZE], int a[SIZE][SIZE], int b[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}


void matrix_subtract(int result[SIZE][SIZE], int a[SIZE][SIZE], int b[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

int main() {
    srand(time(NULL)); 

    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    int identity[SIZE][SIZE] = {0}; 
    for (int i = 0; i < SIZE; i++) {
        identity[i][i] = 1;
    }

    for (int m = 0; m < 3; m++) {
        if (m == 0) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    A[i][j] = rand() % 10 + 1; 
                }
            }
        } else if (m == 1) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    B[i][j] = rand() % 10 + 1; 
                }
            }
        } else {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    C[i][j] = rand() % 10 + 1; 
                }
            }
        }

        int left[SIZE][SIZE];
        matrix_add(left, A, identity);
        matrix_subtract(B, A, identity);
        matrix_multiply(left, left, B);

        int right[SIZE][SIZE];
        matrix_multiply(right, A, A);
        matrix_subtract(right, right, identity);

        int diff[SIZE][SIZE];
        matrix_subtract(diff, left, right);

        printf("矩阵 A:\n");
        print_matrix(A);
        printf("检查公式: (A + I)(A - I) = A^2 - I\n");
        printf("差值矩阵:\n");
        print_matrix(diff);

        bool is_zero = true;
        for (int i = 0; i < SIZE && is_zero; i++) {
            for (int j = 0; j < SIZE && is_zero; j++) {
                if (diff[i][j] != 0) {
                    is_zero = false;
                }
            }
        }

        if (is_zero) {
            printf("该矩阵满足公式。\n");
        } else {
            printf("该矩阵不满足公式。\n");
        }
    }

    return 0;
}