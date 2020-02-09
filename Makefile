CC = gcc
FLAGS_C = -c
FLAGS_L = -o
OBJ = ./obj
LEX = ./analy_lex_sem

main : ${OBJ}/main.o ${OBJ}/analy_lex_sem_func.o
	${CC} ${OBJ}/main.o ${OBJ}/analy_lex_sem_func.o ${FLAGS_L} main

${OBJ}/main.o : ${LEX}/main.c ${LEX}/analy_lex_sem_func.h
	${CC} ${FLAGS_C} ${LEX}/main.c -o $@

${OBJ}/analy_lex_sem_func.o : ${LEX}/analy_lex_sem_func.c	${LEX}/analy_lex_sem_func.h ${LEX}/analy_lex_sem_dec.h
	${CC} ${FLAGS_C} ${LEX}/analy_lex_sem_func.c -o $@
