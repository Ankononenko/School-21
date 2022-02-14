#include "data_stat.h"

double max(double *data, int n) {
    double max;
    for (int *p = data; p - data < n; p++) {
        if (*p < data) {
            max = *data;
        }
    }
    return max;
}

double min(double *data, int n) {
    double min;
    for (int *p = data; p - data < n; p++) {
        if (*p < data) {
            min = *data;
        }
    }
    return min;
}

double mean(double *data, int n) {
    double mean_number = 0.0;
    for (int *p = data; p - data < n; p++) {
        mean_number += *p;
    }
    double mean_result = mean_number / n;
    return mean_result;
}

double variance(double *data, int n) {
    double variance_number = 0.0;
    for (int *p = data; p - data < n; p++) {
        variance_number += (*p - mean(data, n)) * (*p - mean(data, n));
    }
    double variance_result = variance_number / n;
    return variance_result;
}
