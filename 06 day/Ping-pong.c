#include <stdio.h>

int widht = 80;
int height = 25;
int p1 = 0, p2 = 0;
int ball_x = 13;
int ball_y = 40;
int ball_step_x = 1;
int ball_step_y = 1;
char input;
int rocket_left_pos = 13;
int rocket_right_pos = 13;


int temp_move_ball = 0;

void greeting_fun();
void render_field();
void move_ball();
void move_raket(char);
void count_score();
void print_victory();

int main() {
    int winner = 0;
    while (!winner) {
        render_field();
        greeting_fun();
        scanf("%c", &input);
        move_raket(input);
        move_ball();
        count_score();
        winner = (p1 == 21 || p2 == 21) ? 1 : 0;
        // q - чтобы выйти из игры
        if (input == 'q' || input == 'Q') {
            printf("\033[H\033[J");
            break;
        }
    }
        print_victory();
    return 0;
}

void render_field() {
    char border = '|';
    char top_bot_border = '-';
    char space = ' ';
    char left_raket = '[';
    char right_raket = ']';
    char ball = '*';

    printf("\033[H\033[J");
    // Начало цикла для печати строки
    for (int i = 0; i <= height; i++) {
        // Начало цикла для печати столбцов
        for (int j = 0; j <= widht; j ++) {
            if ((i == 0) || (i == 25)) {
                printf("%c", top_bot_border);  // Условие для печати нижней и верхней границы
            } else if ((i == ball_x) && (j == ball_y)) {
                printf("%c", ball);  // Условие для печати меча
            } else if ((i == 3) && (j == 20)) {
                printf("%d", p1);  // Условие для печати счета левого игрока
            } else if ((i == 3) && (j == 60)) {
                printf("%d", p2);  // Условие для печати счета правого игрока
            } else if ((j == 0) || (j == 40) || (j == 80)) {
                printf("%c", border);  // Условие для печати границ слева-справо-посередине
                } else if (j == 76) {
                if ( i == rocket_right_pos - 1 || i == rocket_right_pos || i == rocket_right_pos +1 ) {  
                    // Условие для печати правой ракетки с учетом движения
                    printf("%c", right_raket);
                } else {
                printf("%c", space);  // Условие для печати пробелов в столбце ракеток
                }
            } else if (j == 4) {
                if (i == rocket_left_pos - 1 || i == rocket_left_pos || i == rocket_left_pos + 1)
                {
                    // Условие для печати левой ракетки с учетом движения
                    printf("%c", left_raket);
            } else { 
                printf("%c", space);  // Печать пробелов в столбцах
                }
            } else {
                printf("%c", space);  // Печать пробелов в строках 
            }
         } 
    printf("\n");
    }
}

// Фунция для отображения приветсвия в игре
void greeting_fun() {
    char game_title[10] = "Ping Pong";
    char controls[87] = "Controls for the game are: a/z - left player, k/m - right player, q - to quit the game";
    char game_start[35] = "Please make a move to start a game";
    printf("%s\n%s\n%s\n", game_title, controls, game_start);
}

// Функция движения мячика. Когда значения достигают краев игрового поля, мы меняем направление 
// Движения на противоположное
void move_ball() {
    ball_x += ball_step_x;
    ball_y += ball_step_y;
    if (ball_x == 25 || ball_x == 1) {
        ball_step_x = -ball_step_x;
        }
    if (ball_y == 80 || ball_y == 1) {
        ball_step_y = -ball_step_y;
    }
    if ((ball_y == 5) && (ball_x == rocket_left_pos || ball_x == rocket_left_pos + 1 || ball_x == rocket_left_pos - 1)) {
        ball_step_x = -ball_step_x;
        ball_step_y = -ball_step_y;
    }
    if ((ball_y == 75) && (ball_x == rocket_right_pos || ball_x == rocket_right_pos + 1 || ball_x == rocket_right_pos - 1)) {
        ball_step_x = -ball_step_x;
        ball_step_y = -ball_step_y;
    }
}

// Функция для движения ракеток
void move_raket(char character) {
        if ((character == 'z' || character == 'Z')) rocket_left_pos++;
        if ((character == 'a' || character == 'A')) rocket_left_pos--;
        if ((character == 'k' || character == 'K'))  rocket_right_pos--;
        if ((character == 'm' || character == 'M')) rocket_right_pos++;

        if (rocket_right_pos == 1) {
            rocket_right_pos += 1;
        } else if (rocket_right_pos == 24) {
            rocket_right_pos -= 1;
        } else if (rocket_left_pos == 1) {
            rocket_left_pos += 1;
        } else if (rocket_left_pos == 24) {
            rocket_left_pos -= 1;
        }
}

// Функция учета счета
void count_score() {
    if (ball_y == 1) {
        p2 += 1;
    } else if (ball_y == 80) {
        p1 += 1;
    }
}

// Печать победителя
void print_victory() {
    printf("\033[H\033[J");
    if (p1 == 21) {
        printf("Left player won!");
    } else if (p2 == 21) {
        printf("Right player won!");
    }
}
