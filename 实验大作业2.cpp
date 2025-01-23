#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 字符串相加函数
void addStr(char *n1, char *n2, char *r) {
    int l1 = strlen(n1);
    int l2 = strlen(n2);
    int mxL = l1 > l2? l1 : l2;
    int c = 0;
    int i, j;

    for (i = l1 - 1, j = l2 - 1; i >= 0 || j >= 0; i--, j--) {
        int d1 = i >= 0? n1[i] - '0' : 0;
        int d2 = j >= 0? n2[j] - '0' : 0;
        int s = d1 + d2 + c;
        c = s / 10;
        r[mxL--] = s % 10 + '0';
    }

    if (c > 0) {
        r[0] = c + '0';
        r[mxL] = '\0';
    } else {
        memmove(r, r + 1, mxL + 1);
        r[mxL + 1] = '\0';
    }
}

// 字符串相减函数（假设n1 >= n2）
void subStr(char *n1, char *n2, char *r) {
    int l1 = strlen(n1);
    int l2 = strlen(n2);
    int b = 0;
    int i, j;

    for (i = l1 - 1, j = l2 - 1; i >= 0; i--, j--) {
        int d1 = n1[i] - '0';
        int d2 = j >= 0? n2[j] - '0' : 0;
        int dif = d1 - d2 - b;
        if (dif < 0) {
            dif += 10;
            b = 1;
        } else {
            b = 0;
        }
        r[i] = dif + '0';
    }

    // 去除前导0
    int k = 0;
    while (r[k] == '0' && r[k + 1]!= '\0') {
        k++;
    }
    memmove(r, r + k, strlen(r) - k + 1);
}

// 字符串相乘函数
void mulStr(char *n1, char *n2, char *r) {
    int l1 = strlen(n1);
    int l2 = strlen(n2);
    int *t = (int *)malloc((l1 + l2) * sizeof(int));
    memset(t, 0, (l1 + l2) * sizeof(int));

    for (int i = l1 - 1; i >= 0; i--) {
        for (int j = l2 - 1; j >= 0; j--) {
            int m = (n1[i] - '0') * (n2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int sum = m + t[p2];
            t[p1] += sum / 10;
            t[p2] = sum % 10;
        }
    }

    int k = 0;
    while (k < l1 + l2 && t[k] == 0) {
        k++;
    }

    for (int i = k; i < l1 + l2; i++) {
        r[i - k] = t[i] + '0';
    }
    r[l1 + l2 - k] = '\0';
    free(t);
}

int main() {
    char num1[1000], num2[1000], addR[1001], subR[1000], mulR[2000];

    printf("请输入第一个大数：");
    scanf("%s", num1);
    printf("请输入第二个大数：");
    scanf("%s", num2);

    addStr(num1, num2, addR);
    printf("相加结果：%s\n", addR);

    if (strcmp(num1, num2) >= 0) {
        subStr(num1, num2, subR);
        printf("相减结果：%s\n", subR);
    } else {
        subStr(num2, num1, subR);
        printf("相减结果：-%s\n", subR);
    }

    mulStr(num1, num2, mulR);
    printf("相乘结果：%s\n", mulR);

    return 0;
}