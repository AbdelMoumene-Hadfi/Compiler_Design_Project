typedef enum {
  IF_TOKEN,ELSE_TOKEN,REPEAT_TOKEN,WHILE_TOKEN,FUNCTION_TOKEN,FOR_TOKEN,IN_TOKEN,NEXT_TOKEN,BREAK_TOKEN,TRUE_TOKEN,
  FALSE_TOKEN,NULL_TOKEN,INF_TOKEN,NAN_TOKEN,NA_INTEGER_TOKEN,NA_REAL_TOKEN,NA_COMPLEX_TOKEN,NA_CHARACTER_TOKEN,
  ADD_TOKEN,SUB_TOKEN,MULT_TOKEN,DIV_TOKEN,EXPONENT_TOKEN, MODULUS_TOKEN,INT_DIV_TOKEN,
  INF_TOKEN,SUP_TOKEN,INFEG_TOKEN,SUPEG_TOKEN,EQUALTO_TOKEN,NOT_EQUAL_TOKEN,
  LOGICAL_NOT_TOKEN,LOGICAL_AND_TOKEN,LOGICAL_OR_TOKEN,ELEMENTWISE_LOGICAL_AND_TOKEN,ELEMENTWISE_LOGICAL_OR_TOKEN,
  LEFT_ASGN_TOKEN,RIGHT_ASGN_TOKEN,PO_TOKEN,PF_TOKEN,AO_TOKEN,AF_TOKEN,PRINT_TOKEN,READ_LINE_TOKEN,RETURN_TOKEN,
  CHARACTER_TOKEN,PV_TOKEN,
} TOKENS ;
typedef struct {
  TOKENS TOKEN ; char* WORD ;
} Sym_Struct ;
typedef struct {
  Sym_Struct *Data ;
  struct Sym_Arr_Struct *next;
} Sym_Arr_Struct ;
Sym_Struct *Token_Cour;
typedef struct sym_arr{
  Sym_Struct *Data ;
  struct sym_arr *next;
} Sym_Arr_Struct ;
Sym_Arr_Struct *Head_Arr_Symb;
//
typedef struct {
  TOKENS TOKEN ; char TOKENS[30] ;
} TokenS_Struct ;
TokenS_Struct ARR_TOK[] = {};
//
char Car_Cour;
FILE *file;
