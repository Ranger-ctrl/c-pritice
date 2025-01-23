#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_question(int *num1, char *operation, int *num2) {
    srand(time(NULL));
    *operation = rand() % 2 ? '+' : '-';
    if (*operation == '+') {
        *num1 = rand() % 10; 
        *num2 = rand() % (10 - *num1);
    } else {        
        *num1 = rand() % 9 + 1; 
        *num2 = rand() % *num1; 
    }
}

int main() {
    int n, num1, num2, user_answer, correct_answer;
    char operation;
    float score_per_question, total_score = 0;

    printf("你想做多少道题？ ");
    scanf("%d", &n);
    score_per_question = 100.0 / n;
    for (int i = 0; i < n; i++) {
        generate_question(&num1, &operation, &num2);
        printf("计算: %d %c %d = ", num1, operation, num2);
        scanf("%d", &user_answer);
        if (operation == '+') {
            correct_answer = num1 + num2;
        } else {
            correct_answer = num1 - num2;
        }
        if (user_answer == correct_answer) {
            printf("答对了！\n");
            total_score += score_per_question;
        } else {
            printf("答错了，正确答案是: %d\n", correct_answer);
        }
    }
    printf("你的总分是: %.0f\n", total_score);

    return 0;
}