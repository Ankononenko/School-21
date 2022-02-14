CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

# $(CC) $(CFLAGS) data_io.c data_stat.c data_module_entry.c data_process.c 
# main_executable_module.c decision.c yet_another_decision_module.c -o main

all: main 

main: main.o data_io.o data_stat.o data_module_entry.o data_process.o decision.o yet_another_decision_module_entry.o
	$(CC) $(CFLAGS) -c main.o data_io.o data_stat.o data_module_entry.o data_process.o decision.o yet_another_decision_module_entry.o -o main

main.o: main_executable_module.c data_io.h data_stat.h
	$(CC) $(CFLAGS) -c main_executable_module.c

data_io.o: data_io.c data_io.h
	$(CC) $(CFLAGS) -c data_io.c

data_stat.o: data_stat.c data_stat.h
	$(CC) $(CFLAGS) -c data_stat.c

data_module_entry.o: data_module_entry.c data_io.h data_stat.h
	$(CC) $(CFLAGS) -c data_module_entry.c

data_process.o: data_process.c data_process.h data_stat.h
	$(CC) $(CFLAGS) -c data_process.c

decision.o: decision.c decision.h data_stat.h
	$(CC) $(CFLAGS) -c decision.c

yet_another_decision_module_entry.o: yet_another_decision_module_entry.c decision.h
	$(CC) $(CFLAGS) -c yet_another_decision_module_entry.c

clean: rm -rf *.o main