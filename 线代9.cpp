#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

double determinant_3x3(int matrix[SIZE][SIZE]) {
    return 
        matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
        matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
        matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}


void matrix_add(int result[SIZE][SIZE], int a[SIZE][SIZE], int b[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void print_matrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int inverse_matrix(double result[SIZE][SIZE], int a[SIZE][SIZE], double det) {
    if (det == 0) {
        printf("Matrix is not invertible.\n");
        return 0;
    }


    double temp = 1 / det;

    result[0][0] = temp * (a[1][1] * a[2][2] - a[1][2] * a[2][1]);
    result[0][1] = temp * -(a[0][1] * a[2][2] - a[0][2] * a[2][1]);
    result[0][2] = temp * (a[0][1] * a[1][2] - a[0][2] * a[1][1]);

    result[1][0] = temp * -(a[1][0] * a[2][2] - a[1][2] * a[2][0]);
    result[1][1] = temp * (a[0][0] * a[2][2] - a[0][2] * a[2][0]);
    result[1][2] = temp * -(a[0][0] * a[1][2] - a[0][2] * a[1][0]);

    result[2][0] = temp * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
    result[2][1] = temp * -(a[0][0] * a[2][1] - a[0][1] * a[2][0]);
    result[2][2] = temp * (a[0][0] * a[1][1] - a[0][1] * a[1][0]);

    return 1;
}

int main() {
    srand(time(NULL));

    int A[SIZE][SIZE], B[SIZE][SIZE];
    int sum[SIZE][SIZE];


    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 10; 
            B[i][j] = rand() % 10; 
        }
    }


    printf("Matrix A:\n");
    print_matrix(A);
    printf("Matrix B:\n");
    print_matrix(B);


    matrix_add(sum, A, B);
    printf("Matrix A + B:\n");
    print_matrix(sum);

  
    double detA = determinant_3x3(A);
    double detB = determinant_3x3(B);
    double detSum = determinant_3x3(sum);

 
    printf("检查det(A+B) = det(A) + det(B)\n");
    printf("det(A+B): %.2f, det(A) + det(B): %.2f\n", detSum, detA + detB);
    printf("结果是 %s.\n", labs(detSum - (detA + detB)) < 1e-6 ? "true" : "false");

    // Verify det(A+B) = det(A) * det(B)
    printf("检查 det(A+B) = det(A) * det(B)\n");
    printf("det(A+B): %.2f, det(A) * det(B): %.2f\n", detSum, detA * detB);
    printf("结果是 %s.\n", labs(detSum - (detA * detB)) < 1e-6 ? "true" : "false");


    double invA[SIZE][SIZE];
    if (detA != 0 && inverse_matrix(invA, A, detA)) {
        double detInvA = determinant_3x3((int(*)[SIZE])invA); 
        printf("检查 det(A^-1) = (det(A))^(-1)\n");
        printf("det(A^-1): %.2f, (det(A))^(-1): %.2f\n", detInvA, 1/detA);
        printf("结果是 %s.\n", labs(detInvA - 1/detA) < 1e-6 ? "true" : "false");
    } else {
        printf("Matrix A 不是 det(A^-1).\n");
    }

    return 0;
}