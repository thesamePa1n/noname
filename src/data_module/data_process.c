#include "data_process.h"
#include "../data_libs/data_stat.h"
#include <math.h>
#include <stdio.h>

int normalization(double *data, int n)
{
    int result = 1;
    double max_value = max(data, n);
    double min_value = min(data, n);
    double size = max_value - min_value;

    if(fabs(size) > EPS)
    {
        for (int i = 0; i < n; i++)
        {
            data[i] = data[i] / size - min_value / size;
        }
    }
    else
    {
        result = 0;
    }
    
    return result;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *a, int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
        int middle = a[(left + right) / 2];
        do {
            while (a[left] < middle) {
                left++;
            }
            while (a[right] > middle) {
                right--;
            }
            if (left <= right) {
                swap(&a[left], &a[right]);
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort(a, first, right);
        quick_sort(a, left, last);
    }
}