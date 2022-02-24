#include <stdio.h>
int main() {
    int x, y;
    if (scanf("%d%d", &y, &x) == 2 && y > 0 && x > 0) {
        int my_matrix[y][x];
        int bad = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (scanf("%d", &my_matrix[j][i]) != 1)
                    bad = 1;
                if (bad)
                    break;
            }
            if (bad)
                break;
        }
        if (!bad) {
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++) {
                    printf("%d", my_matrix[i][j] * my_matrix[i][j]);
                    if (j < x - 1) {
                        printf(" ");
                    }
                }
                if (i < y - 1)
                    printf("\n");
            }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}
