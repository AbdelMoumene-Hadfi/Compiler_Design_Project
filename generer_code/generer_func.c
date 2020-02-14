#include "generer_func.h"
#include<stdio.h>
int PC=0 ;
MNEMON_STR afficher_mnemon_str[20]={
  {ADD,"ADD"},
  {SUB,"SUB"},
  {MUL,"MUL"},
  {DIV,"DIV"},
  {EQL,"EQL"},//==
  {NEQ,"NEQ"},//!=
  {GTR,"GTR"},//>
  {LSS,"LSS"},//<
  {GEQ,"GEQ"},//>=
  {LEQ,"LEQ"},//<=
  {PRN,"PRN"},
  {INN,"INN"},
  {INT,"INT"},
  {LDI,"LDI"},{LDA,"LDA"},{LDV,"LDV"},{STO,"STO"},
  {BRN,"BRN"},{BZE,"BZE"},
  {HLT,"HLT"}
};
void generer1(MNEMONICS mne) {
  printf("pc --> %d\n",PC);
  if(PC==TAILLECODE) {}
  else {
    Pcode[PC].MNE=mne ;
    PC++;
  }
}
void generer2(MNEMONICS mne,int entier) {
  printf("pc --> %d\n",PC);
  if(PC==TAILLECODE) {}
  else {
    Pcode[PC].MNE=mne ;
    Pcode[PC].ENTIER=entier ;
    PC++;
  }

}
void afficher_pcode() {
  for(int i=0;i<PC;i++) {
    printf("%s\n",afficher_mnemon_str[Pcode[PC].MNE].WORD);
  }
}
