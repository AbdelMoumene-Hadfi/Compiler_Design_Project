#include "symbol_table.h"
static int symbol_hash(char *id) {
  int count = 0,i=0;
  while(*(id+i) != '\0') {
    count+= *(id+i) ;
    i++;
  }
  return count ;
}

node_t* symbol_search(char* name,int* hash,int* index ) {
  *hash=symbol_hash(name);
  *index=(*hash % SYMBOL_SIZE );
  if(sym_table_t->HASH_TABLE[*index]==NULL) {
    return NULL ;
  }
  else {
    for(node_t* nodepointer=sym_table_t->HASH_TABLE[*index];nodepointer!=NULL;nodepointer=nodepointer->NEXT) {
      int cmp = strcmp(name,nodepointer->SYMBOL.WORD);
      if(cmp==0){return nodepointer;}
    }
  }
}

void symbol_add(char* name,Type_Sym type_sym) {
  int hash,index;
  node_t* node = symbol_search(name,&hash,&index);
  if(node==NULL) {
    node_t* temp = (node_t*) malloc(sizeof(node_t*));
    temp->SYMBOL.WORD = (char*) malloc(90);
    strcpy(temp->SYMBOL.WORD,name);
    temp->SYMBOL.TYPE_SYM = type_sym ;
    temp->HASH=hash;
    temp->NEXT=sym_table_t->HASH_TABLE[index];
    sym_table_t->HASH_TABLE[index]=temp;
  }
}



void symbol_print() {
  for(int i=0;i<SYMBOL_SIZE;i++) {
    for(node_t* nodepointer=sym_table_t->HASH_TABLE[i];nodepointer!=NULL;nodepointer=nodepointer->NEXT) {
      printf("%d\t",nodepointer->HASH);
      printf("%s   ",nodepointer->SYMBOL.WORD);
      printf("%d\n",nodepointer->SYMBOL.TYPE_SYM);


    }
  }
}
