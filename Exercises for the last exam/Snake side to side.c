// snake side to side
#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int my_matrix[n][n];

        int count = 1;
        int dir_ball = 0;
        int x_b = 0;
        int y_b = 0;

        int left = 0;
        int right = n - 1;

        while (count != (n * n + 1)) {
            my_matrix[y_b][x_b] = count;
            count++;

            if (dir_ball == 0) {  // move right
                if (x_b == right) {
                    y_b++;
                    dir_ball = 1;
                } else {
                    x_b++;
                }
            } else if (dir_ball == 1) {  // move left
                if (x_b == left) {
                    y_b++;
                    dir_ball = 0;
                } else {
                    x_b--;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", my_matrix[i][j]);
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
}
