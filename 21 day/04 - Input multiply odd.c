// Copyright 2022 finchren
#include <stdio.h>

int main() {
    int number = 0;
    int counter = 0;
    int array[5];
    while(counter != 5) {
        scanf("%d", &number);
        array[counter] = number;
        counter++;
    }
    int result_to_return = array[0];
    if (counter == 2) {
        printf("0");
    } 
    else if (counter == 1) {
        printf("%d", array[0]);
    } else {
        for (int i = 0; i < counter; i++) {
            if (i % 2 == 0) {
                printf("i isn't even %d\n", array[i]);
                result_to_return *= array[i];
            }
        }
    }
    printf("result - %d\n", result_to_return);
    return 0;
}

/*
ввод не ограничен количеством целых чисел
на вывод: произведение нечетных чисел, если всего 2 числа  - выводить ноль, если одно число - вывести его (но положительным)
ввод 	  | вывод
--------------------
1 2 3 4   | 3
--------------------
2 4         | 0
--------------------
-3    	   | 3
*/
