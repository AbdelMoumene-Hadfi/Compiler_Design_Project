#include "symb_table_dec.h"

void init_hash_table() ;
unsigned int hash(char *key) ;
void insert(char *name,int len,Type_Sym type,int lineno) ;
List_Symb *lookup(char *name) ;
List_Symb *lookup_scope(char *name,int scope) ;
void set_type(char *name,Type_Sym type,Type_Sym undertype) ;
Type_Sym get_type(char *name) ;
void hide_scope() ;
void incr_scope() ;
void symb_show() ;
