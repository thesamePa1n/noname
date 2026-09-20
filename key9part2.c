#include <stdio.h>

#define LEN 100

int read_number(int *a) {
    int len = 0;
    int ch;
    while (len < LEN) {
        if (scanf("%d", &a[len]) != 1) {
            return 0;
        }
        if (a[len] < 0 || a[len] > 9) {
            return 0;
        }
        len++;
        do {
            ch = getchar();
        } while (ch == ' ' || ch == '\t');
        if (ch == '\n' || ch == EOF) {
            break;
        }
        ungetc(ch, stdin);
    }
    if (len == 0) {
        return 0;
    }
    if (len == LEN && ch != '\n' && ch != EOF) {
        return 0;
    }
    return len;
}

int input(int *a, int *b, int *len1, int *len2) {
    *len1 = read_number(a);
    if (*len1 == 0) {
        printf("n/a");
        return 0;
    }
    *len2 = read_number(b);
    if (*len2 == 0) {
        printf("n/a");
        return 0;
    }
    return 1;
}

void output(int *a, int n) {
    int start = 0;
    while (start < n - 1 && a[start] == 0) {
        start++;
    }
    for (int *p = a + start; p < a + n; p++) {
        printf("%d", *p);
        if (p < a + n - 1) {
            printf(" ");
        }
    }
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int i = len1 - 1;
    int j = len2 - 1;
    int k = LEN;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int a = i >= 0 ? buff1[i--] : 0;
        int b = j >= 0 ? buff2[j--] : 0;
        int value = a + b + carry;
        result[k--] = value % 10;
        carry = value / 10;
    }
    *result_length = LEN - k;
    for (int i = 0; i < *result_length; i++) {
        result[i] = result[k + 1 + i];
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int i = len1 - 1;
    int j = len2 - 1;
    int borrow = 0;
    while (i >= 0) {
        int a = buff1[i] - borrow;
        int b = j >= 0 ? buff2[j--] : 0;
        if (a < b) {
            a += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i--] = a - b;
    }
    int start = 0;
    while (start < len1 - 1 && result[start] == 0) {
        start++;
    }
    *result_length = len1 - start;
    for (int i = 0; i < *result_length; i++) {
        result[i] = result[start + i];
    }
}

int compare(int *a, int len1, int *b, int len2) {
    int i = 0;
    int j = 0;
    while (i < len1 - 1 && a[i] == 0) {
        i++;
    }
    while (j < len2 - 1 && b[j] == 0) {
        j++;
    }
    if (len1 - i != len2 - j) {
        return len1 - i > len2 - j;
    }
    while (i < len1) {
        if (a[i] != b[j]) {
            return a[i] > b[j];
        }
        i++;
        j++;
    }
    return 1;
}

int main() {
    int A[LEN], B[LEN];
    int result_sum[LEN + 1], result_sub[LEN];
    int len1, len2, sum_length, sub_length;

    if (!input(A, B, &len1, &len2)) {
        return 0;
    }

    sum(A, len1, B, len2, result_sum, &sum_length);
    output(result_sum, sum_length);
    printf("\n");

    if (compare(A, len1, B, len2)) {
        sub(A, len1, B, len2, result_sub, &sub_length);
        output(result_sub, sub_length);
    } else {
        printf("n/a");
    }

    return 0;
}