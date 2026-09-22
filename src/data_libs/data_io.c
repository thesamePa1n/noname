#include "data_io.h"
#include <stdio.h>
#include <stdlib.h>

int input(double **data, int *n) {
    if (scanf("%d", n) != 1) {
      printf("ERROR");
      return 1;
    }
    *data = malloc(*n * sizeof(double));
    for (int i = 0; i < *n; i++) {
        if (scanf("%lf", &(*data)[i]) != 1) {
          printf("ERROR");
          return 1;
        }
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch != ' ' && ch != '\t') {
            printf("ERROR");
            return 1;
        }
    }
    return 0;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);

        if (i < n - 1) {
            printf(" ");
        }
    }
}