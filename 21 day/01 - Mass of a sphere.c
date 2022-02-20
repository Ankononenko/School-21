// Copyright 2022 finchren
#include <stdio.h>
#include <math.h>

int main() {
    // float density_of_the_sphere = 21500 кг/м^3 = 0,0215 кг/см^3
    double r = 0.0;
    char endline;
    if (scanf("%lf", &r)) {
        endline = getchar();
        if (endline == ' ' || endline == '\n') {
            double v = (4.0/3.0) * M_PI * pow(r, 3.0);
            double p = 0.0215;
            double m = p * v;
            double rounded_mass = round(m);
            printf("%lf\n", m);
            printf("%0lf", rounded_mass);
            } else {
                printf("n/a");
            }
    } else {
        printf("n/a");
    }
    return 0;
}
/*
Найти массу шара. Радиус шара вводится в консоль ( радиус имеет тип double). Плотность шара = 21500 кг/м^3
Даны формулы:
V = (4/3) * pi * R^3
P = m / V
Вывести массу округлив ее до целого числа математически верно.
Примечание:
Использовать константу M_PI, и функцию double round(double) из библиотеки math.h
Вывод должен выглядеть так:
printf("%.0lf", result) ;
*/

/*
+ 1. Посчитать обьем шара
+ 2. Вывести формулу массы, посчитать
+ 3. Вывести результат 
+ 4. Сделать проверку на корректность ввода
+ 5. Cpplint
+ 6. Test for leaks
*/
