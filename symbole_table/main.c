#include "symb_table.h"

int main() {
  init_hash_table();
  insert("x",1,UNDEF,0);
  insert("test",4,CHARACTER,1);
  insert("y",1,UNDEF,4);
  insert("z",1,UNDEF,5);
  symb_show();
  return 0 ;
}
