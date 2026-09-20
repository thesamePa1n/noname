#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *c) {
    if (scanf("%d", n) != 1) {
        printf("n/a");
        return 0;
    }
    if (*n <= 0 || *n > NMAX) {
        printf("n/a");
        return 0;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            printf("n/a");
            return 0;
        }
    }
    if (scanf("%d", c) != 1) {
        printf("n/a");
        return 0;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch != ' ' && ch != '\t') {
            printf("n/a");
            return 0;
        }
    }
    return 1;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p == a + n - 1) {
            printf("%d", *p);
        } else {
            printf("%d ", *p);
        }
    }
}

void my_cycle_shift(int *a, int n, int c) {
    c = c % n;

    if (c < 0) {
        c += n;
    }

    for (int j = 0; j < c; j++) {
        int temp = a[0];

        for (int i = 0; i < n - 1; i++) {
            a[i] = a[i + 1];
        }

        a[n - 1] = temp;
    }
}

int main() {
    int n, A[NMAX], c;
    if (input(A, &n, &c) == 0) {
        return 0;
    }

    my_cycle_shift(A, n, c);
    output(A, n);

    return 0;
}
