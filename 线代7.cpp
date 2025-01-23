#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void printMatrix(int mat[SIZE][SIZE]);
void randomMatrix(int mat[SIZE][SIZE]);
int multiplyMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]);

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    int AB[SIZE][SIZE], AC[SIZE][SIZE], ABC[SIZE][SIZE], CAB[SIZE][SIZE];
    int ABCt[SIZE][SIZE], CBT[SIZE][SIZE], BTAT[SIZE][SIZE], AT[SIZE][SIZE];

    srand(time(NULL));

    randomMatrix(A);
    randomMatrix(B);
    randomMatrix(C);

    printf("矩阵A:\n");
    printMatrix(A);
    printf("矩阵B:\n");
    printMatrix(B);
    printf("矩阵C:\n");
    printMatrix(C);

    multiplyMatrices(A, B, AB);
    multiplyMatrices(A, C, AC);
    multiplyMatrices(A, (B + C), ABC);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            ABC[i][j] = AB[i][j] + AC[i][j];
        }
    }

    printf("验证公式(1) AB + AC = A(B + C):\n");
    printf("左边: AB + AC\n");
    printMatrix(ABC);
    printf("右边: A(B + C)\n");
    printMatrix(ABC);

    multiplyMatrices(A, B, AB);
    multiplyMatrices(B, C, CAB);
    multiplyMatrices(AB, C, ABC);
    multiplyMatrices(A, CAB, CAB);

    printf("验证公式(2) (AB)C = A(BC):\n");
    printf("左边: (AB)C\n");
    printMatrix(ABC);
    printf("右边: A(BC)\n");
    printMatrix(CAB);

    multiplyMatrices(A, B, AB);
    multiplyMatrices(AB, C, ABC);
    multiplyMatrices(C, C, CBT);
    multiplyMatrices(B, B, BTAT);
    multiplyMatrices(A, A, AT);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            ABCt[i][j] = ABC[j][i];
            CBT[i][j] = CBT[j][i];
            BTAT[i][j] = BTAT[j][i];
            AT[i][j] = AT[j][i];
        }
    }
    multiplyMatrices(CBT, BTAT, CAB);
    multiplyMatrices(CAB, AT, CAB);

    printf("验证公式(3) (ABC)^T = C^T * B^T * A^T:\n");
    printf("左边: (ABC)^T\n");
    printMatrix(ABCt);
    printf("右边: C^T * B^T * A^T\n");
    printMatrix(CAB);

    return 0;
}

void printMatrix(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void randomMatrix(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            mat[i][j] = rand() % 10;
    }
}

int multiplyMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return 0;
}