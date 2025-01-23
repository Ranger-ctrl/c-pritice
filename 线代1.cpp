#include <stdio.h>

double det3diag(double a[], double b[], double c[], int n) {
    double d[n], x[n];
    d[0] = b[0];
    for (int i = 1; i < n; i++) {
        d[i] = b[i] - c[i-1] * a[i-1] / d[i-1];
    }
    x[n-1] = 1.0 / d[n-1];
    for (int i = n-2; i >= 0; i--) {
        x[i] = a[i] * x[i+1] / d[i];
    }
    return d[0] * x[0];
}

int main() {
    int n;
    scanf("%d", &n);
    double a[n], b[n], c[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }
    for (int i = 0; i < n-1; i++) {
        scanf("%lf", &a[i]);
        scanf("%lf", &c[i]);
    }
    printf("%.6f\n", det3diag(a, b, c, n));
    return 0;
}

