#include "symb_table.h"
int cur_scope =0;

void init_hash_table() {
  symbol_table = malloc(SYMBOL_TABLE_SIZE * sizeof(List_Symb*));
  for(int i=0;i<SYMBOL_TABLE_SIZE;i++) {symbol_table[i] == NULL ;}
}
unsigned int hash(char *key){
  unsigned int hashval = 0 ;
  for(;*key!='\0';key++) {
    hashval += *key ;
  }
  hashval += key[0]%11 + (key[0]<<3) - key[0];
  return hashval % SYMBOL_TABLE_SIZE ;
}
void insert(char *name,int len,Type_Sym type,int lineno) {
  unsigned int hashval = hash(name) ;
  List_Symb *l = symbol_table[hashval];
  while((l!=NULL) && (strcmp(name,l->NameSymbol)!=0)) {
    l = l->NEXT ;
  }
  if(l==NULL) {
    l = (List_Symb*) malloc(sizeof(List_Symb));
    strncpy(l->NameSymbol,name,len);
    l->TYPE = type ;
    l->SCOPE = cur_scope ;
    l->LINES = (Ref_List*) malloc(sizeof(Ref_List));
    l->LINES->LineNo = lineno ;
    l->LINES->TYPE = type ;
    l->LINES->NEXT = NULL ;
    l->NEXT = symbol_table[hashval] ;
    symbol_table[hashval] = l ;
  }
  else {
    l->SCOPE = cur_scope ;
    Ref_List *t = l->LINES ;
    while(t->NEXT != NULL) {
      t = t->NEXT ;
    }
    t->NEXT =  (Ref_List*) malloc(sizeof(Ref_List));
    t->NEXT->LineNo = lineno ;
    t->NEXT->NEXT = NULL ;
  }
}
List_Symb *lookup(char *name) {
  unsigned int hashval = hash(name);
  List_Symb *l = symbol_table[hashval];
  while((l!=NULL) && (strcmp(name,l->NameSymbol)!=0)) {
    l=l->NEXT ;
  }
  return l ;
}
List_Symb *lookup_scope(char *name,int scope) {
  unsigned int hashval = hash(name);
  List_Symb *l = symbol_table[hashval];
  while((l!=NULL) && (strcmp(name,l->NameSymbol)!=0) && (scope != l->SCOPE)) {
    l=l->NEXT ;
  }
  return l ;
}
void hide_scope() {
  if(cur_scope>0) {
    cur_scope-- ;
  }
}
void incr_scope() {
  cur_scope++;
}
void symb_show() {
  for(int i=0;i<SYMBOL_TABLE_SIZE;i++) {
    List_Symb *l = symbol_table[i];
    while(l!=NULL) {
      Ref_List *ref = l->LINES ;
      printf("%s ",l->NameSymbol);
      printf("%d ",l->SCOPE);
      printf("%d ",l->TYPE);
      while(ref!=NULL) {
        printf("%d ",ref->LineNo);
        ref = ref->NEXT ;
      }
      printf("\n");
      l = l->NEXT ;
    }
  }
}
