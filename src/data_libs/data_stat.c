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
    double result = 0;

    for (int i = 0; i < n; i++) {
        result += data[i];
    }

    return result / n;
}

double variance(double *data, int n) {
    double average = mean(data, n);
    double result = 0;

    for (int i = 0; i < n; i++) {
        result += (data[i] - average) * (data[i] - average);
    }

    return result / n;
}