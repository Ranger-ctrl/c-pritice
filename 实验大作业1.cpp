#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成10以内加减法题目
void genQues(int n) {
    int tScore = 0;
    int sPerQues = 100 / n;
    int rmdr = 100 % n;
    int i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < n; i++) {
        int op = rand() % 2;  // 0表示加法，1表示减法
        int n1 = rand() % 10 + 1;
        int n2 = rand() % 10 + 1;

        if (op == 0) {  // 加法
            while (n1 + n2 > 10 || n1 + n2 <= 0) {
                n1 = rand() % 10 + 1;
                n2 = rand() % 10 + 1;
            }
            printf("%d + %d = \n", n1, n2);
            tScore += sPerQues;
        } else {  // 减法
            while (n1 - n2 <= 0 || n1 - n2 > 10) {
                n1 = rand() % 10 + 1;
                n2 = rand() % 10 + 1;
            }
            printf("%d - %d = \n", n1, n2);
            tScore += sPerQues;
        }
    }

    // 处理余数，将余数加到前面几道题上，使总分是100
    for (i = 0; i < rmdr; i++) {
        tScore++;
    }

    printf("总分：%d\n", tScore);
}

int main() {
    int num;
    printf("请输入要生成的题目数量：");
    scanf("%d", &num);
    genQues(num);
    return 0;
}