#include <stdio.h>

// 冒泡排序
void bs(int a[], int l) {
    int i, j, t;
    for (i = 0; i < l - 1; i++) {
        int s = 0;
        for (j = 0; j < l - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                s = 1;
            }
        }
        if (s == 0) {
            break;
        }
    }
}

// 选择排序
void ss(int a[], int l) {
    int i, j, mi, t;
    for (i = 0; i < l - 1; i++) {
        mi = i;
        for (j = i + 1; j < l; j++) {
            if (a[j] > a[mi]) {
                mi = j;
            }
        }
        if (mi!= i) {
            t = a[i];
            a[i] = a[mi];
            a[mi] = t;
        }
    }
}

// 插入排序
void is(int a[], int l) {
    int i, k, j;
    for (i = 1; i < l; i++) {
        k = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < k) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = k;
    }
}

// 快速排序的分区函数
int p(int a[], int lo, int hi) {
    int pv = a[hi];
    int i = (lo - 1);
    int t;
    for (int j = lo; j <= hi - 1; j++) {
        if (a[j] >= pv) {
            i++;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    t = a[i + 1];
    a[i + 1] = a[hi];
    a[hi] = t;
    return (i + 1);
}

// 快速排序
void qs(int a[], int lo, int hi) {
    if (lo < hi) {
        int pi = p(a, lo, hi);
        qs(a, lo, pi - 1);
        qs(a, pi + 1, hi);
    }
}

// 打印数组函数
void pa(int a[], int s) {
    int i;
    for (i = 0; i < s; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: ");
    pa(arr, n);

    int bsArr[n], ssArr[n], isArr[n], qsArr[n];
    for (int i = 0; i < n; i++) {
        bsArr[i] = ssArr[i] = isArr[i] = qsArr[i] = arr[i];
    }

    printf("冒泡排序结果: ");
    bs(bsArr, n);
    pa(bsArr, n);

    printf("选择排序结果: ");
    ss(ssArr, n);
    pa(ssArr, n);

    printf("插入排序结果: ");
    is(isArr, n);
    pa(isArr, n);

    printf("快速排序结果: ");
    qs(qsArr, 0, n - 1);
    pa(qsArr, n);

    return 0;
}