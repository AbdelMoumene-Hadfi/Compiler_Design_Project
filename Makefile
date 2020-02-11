CC = gcc
FLAGS_C = -c
FLAGS_L = -o
OBJ = ./obj
LEX = ./analy_lex
SYM = ./symbole_table

main : ${OBJ}/main.o ${OBJ}/analy_lex_func.o ${OBJ}/symb_table_func.o
	${CC} ${OBJ}/main.o ${OBJ}/analy_lex_func.o ${OBJ}/symb_table_func.o ${FLAGS_L} main

${OBJ}/main.o : main.c ${LEX}/analy_lex_func.h
	${CC} ${FLAGS_C} main.c -o $@

${OBJ}/analy_lex_func.o : ${LEX}/analy_lex_func.c	${LEX}/analy_lex_func.h ${LEX}/analy_lex_dec.h ${SYM}/symb_table_func.h
	${CC} ${FLAGS_C} ${LEX}/analy_lex_func.c -o $@

${OBJ}/symb_table_func.o : ${SYM}/symb_table_func.c	${SYM}/symb_table_dec.h ${SYM}/symb_table_func.h
		${CC} ${FLAGS_C} ${SYM}/symb_table_func.c -o $@
