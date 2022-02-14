#include "data_io.h"

void input(double *data, int n) {
    scanf("%d", &n);
    for (int *p = data; p - data < n; p++) {
        scanf("%lf", p);
}
void output(double *data, int n) {
    printf("%d", n);
    for (int *p = data; p - data < n; p++) {
        printf("%%2lf", p);
}
