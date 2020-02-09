#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SYMBOL_TABLE_SIZE 211

typedef enum {
  UNDEF , COMPLEX , HEX , NUM , CHARACTER , FUNCTION , ARRAY , MATRIX
} Type_Sym ;

typedef enum {
  BY_VALUE , BY_REFER
} Pass_Param;

typedef union Values{
  int IntValue ;
  double FloatValue ;
  char *StringValue ;
}Values ;

typedef struct Param_Function {
  Type_Sym TypeParam ;
  char NameParam[90] ;
  Values ValueParam ;
}Param_Function ;

typedef struct RefList{
  int LineNo ;
  int TYPE ;
  struct RefList *NEXT ;
} Ref_List;

typedef struct List_Symb {
  char NameSymbol[90] ;
  int SCOPE ;
  Type_Sym TYPE ;
  // if TYPE == ARRAY || MATRIX || FUNCTION
  Type_Sym UnderType ;
  //
  Values ValueSymbol ;
  // if TYPE  == FUNCTION
  Param_Function *PARAMS;
  int ParamCount;
  //
  Ref_List *LINES;
  struct List_Symb *NEXT ;
} List_Symb ;
//
static List_Symb **symbol_table;
//
void init_hash_table() ;
unsigned int hash(char *key) ;
void insert(char *name,int len,Type_Sym type,int lineno) ;
List_Symb *lookup(char *name) ;
List_Symb *lookup_scope(char *name,int scope) ;
void hide_scope() ;
void incr_scope() ;
void symb_show() ;
