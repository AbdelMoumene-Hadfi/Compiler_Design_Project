#define SYMBOL_SIZE 997

typedef enum {
  COMPLEX , HEX , NUM , CHARACTER , FUNCTION
} Type_Sym ;

typedef struct symbol {
  char* WORD;
  Type_Sym TYPE_SYM;
} symbol_t;

typedef struct node {
  symbol_t SYMBOL;
  int HASH;
  struct node* NEXT;
} node_t;

typedef struct sym_table {
    node_t* HASH_TABLE[SYMBOL_SIZE];
    char** addr_table;
}sym_table;

sym_table *sym_table_t;

static int symbol_hash(char *id) ;
node_t* symbol_search(char* name,int* hash,int* index ) ;
void symbol_add(char* name,Type_Sym type_sym) ;
void symbol_print() ;
