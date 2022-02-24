// snake to center

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int my_matrix[n][n];

        int count = 0;
        int dir_ball = 0;
        int x_b = -1;
        int y_b = 0;

        int up = 1;
        int down = n - 1;
        int left = 0;
        int right = n - 1;

        while (count != (n * n + 1)) {
            my_matrix[y_b][x_b] = count;
            count++;

            if (dir_ball == 0) {  // move right
                x_b++;
                if (x_b == right) {
                    right--;
                    dir_ball = dir_ball + 1;
                }
            } else if (dir_ball == 1) {  // move down
                y_b++;
                if (y_b == down) {
                    down--;
                    dir_ball = dir_ball + 1;
                }
            } else if (dir_ball == 2) {  // move left
                x_b--;
                if (x_b == left) {
                    left++;
                    dir_ball = dir_ball + 1;
                }
            } else if (dir_ball == 3) {  // move up
                y_b--;
                if (y_b == up) {
                    up++;
                    dir_ball = 0;
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
