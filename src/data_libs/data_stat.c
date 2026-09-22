#include "data_stat.h"
#include <stdio.h>

double max(double *data, int n) {
    double result = data[0];

    for (int i = 1; i < n; i++) {
        if (data[i] > result) {
            result = data[i];
        }
    }

    return result;
}

double min(double *data, int n) {
    double result = data[0];

    for (int i = 1; i < n; i++) {
        if (data[i] < result) {
            result = data[i];
        }
    }

    return result;
}

double mean(double *data, int n) {
    return (min(data, n) + max(data, n)) / 2.0;
}

double variance(double *data, int n) {
    int minimum = min(data, n);
    int maximum = max(data, n);
    return (((maximum - minimum + 1) * (maximum - minimum + 1)) - 1) / 12.0;
}