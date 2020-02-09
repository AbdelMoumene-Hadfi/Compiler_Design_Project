CC = gcc
FLAGS_C = -c
FLAGS_L = -o
OBJ = ./obj
LEX = ./analy_lex_sem
SYM = ./symbole_table

main : ${OBJ}/main.o ${OBJ}/analy_lex_sem_func.o ${OBJ}/symb_table.o
	${CC} ${OBJ}/main.o ${OBJ}/analy_lex_sem_func.o ${OBJ}/symb_table.o ${FLAGS_L} main

${OBJ}/main.o : ${LEX}/main.c ${LEX}/analy_lex_sem_func.h
	${CC} ${FLAGS_C} ${LEX}/main.c -o $@

${OBJ}/analy_lex_sem_func.o : ${LEX}/analy_lex_sem_func.c	${LEX}/analy_lex_sem_func.h ${LEX}/analy_lex_sem_dec.h ${SYM}/symb_table_func.h
	${CC} ${FLAGS_C} ${LEX}/analy_lex_sem_func.c -o $@

${OBJ}/symb_table.o : ${SYM}/symb_table.c	${SYM}/symb_table_dec.h ${SYM}/symb_table_func.h
		${CC} ${FLAGS_C} ${SYM}/symb_table.c -o $@
