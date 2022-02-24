#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int my_matrix[n][n];

        int bad = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (scanf("%d", &my_matrix[i][j]) != 1)
                    bad = 1;
                if (bad)
                    break;
            }
            if (bad)
                break;
        }
        if (!bad) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d", my_matrix[j][i]);
                    if (j < n - 1) {
                        printf(" ");
                    }
                }
                if (i < n - 1)
                    printf("\n");
            }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}
