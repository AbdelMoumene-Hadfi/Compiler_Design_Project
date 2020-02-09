CC = gcc
FLAGS_C = -c
FLAGS_L = -o


main : main.o symb_table.o
	${CC} main.o symb_table.o ${FLAGS_L} main

main.o : main.c symb_table.h
	${CC} ${FLAGS_C} main.c
symb_table.o : symb_table.c	symb_table.h
	${CC} ${FLAGS_C} symb_table.c
