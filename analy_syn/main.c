#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void Symbole_Suiv(void) {
  Token_Cour = Head_Arr_Symb->Data ;
  Head_Arr_Symb = Head_Arr_Symb->Next ;
}

void Test_Symbole(TOKENS token,ERREURS erreur) {
  if(Token_Cour->TOKEN == token) {
    Symbole_Suiv();
  }
  else {
    Erreur(erreur);
  }
}

void INSTS() {
  if(Token_Cour->TOKEN  == AO_TOKEN) {
    Symbole_Suiv();
    INST();
    Test_Symbole(AF_TOKEN,AF_TOKEN_ERREUR);
    Test_Symbole(EOF_TOKEN,EOF_TOKEN_ERREUR);
  }
  else {
    INST();
    Test_Symbole(EOF_TOKEN,EOF_TOKEN_ERREUR);
  }
}

void INST() {
  switch (Token_Cour->TOKEN) {
    case PRINT_TOKEN : PRINT()      ; break ;
    case WHILE_TOKEN : BOUCLE_FOR() ; break ;
    case FOR_TOKEN   : BOUCLE_FOR() ; break ;
    case IF_TOKEN    : IF()         ; break ;
    case ID_TOKEN    : AFFECTATION(); break ;

  }
  
}

void CONSTS(void) {
  switch (Token_Cour->TOKEN) {
    case CONST_TOKEN : Symbole_Suiv();
                       Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
                       Test_Symbole(EGAL_TOKEN,EGAL_TOKEN_ERREUR);
                       Test_Symbole(NUM_TOKEN,NUM_TOKEN_ERREUR);
                       Test_Symbole(PV_TOKEN,PV_TOKEN_ERREUR);
                       while(Token_Cour->TOKEN == ID_TOKEN) {
                         Symbole_Suiv();
                         Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
                         Test_Symbole(EGAL_TOKEN,EGAL_TOKEN_ERREUR);
                         Test_Symbole(NUM_TOKEN,NUM_TOKEN_ERREUR);
                         Test_Symbole(PV_TOKEN,PV_TOKEN_ERREUR);
                       } ; break ;
    case VAR_TOKEN :   break ;
    case BEGIN_TOKEN : break ;
    default          : Erreur(CONST_VAR_BEGIN_ERR) ; break ;
  }
}
void VARS(void) {
  switch (Token_Cour->TOKEN) {
    case VAR_TOKEN : Symbole_Suiv();
                     Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
                     while(Token_Cour->TOKEN == VIR_TOKEN) {
                        Symbole_Suiv();
                        Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
                     }
                     Test_Symbole(PV_TOKEN,PV_TOKEN_ERREUR); ; break ;
    case BEGIN_TOKEN : break ;
    default          : Erreur(CONST_VAR_BEGIN_ERR) ; break ;
  }
}
void INSTS(void) {
  Test_Symbole(BEGIN_TOKEN,BEGIN_TOKEN_ERREUR);
  INST();
  while(Token_Cour->TOKEN == PV_TOKEN ) {
    Symbole_Suiv();
    INST();
  }
  Test_Symbole(END_TOKEN,END_TOKEN_ERREUR);
}
void INST(void) {
  switch (Token_Cour->TOKEN) {
    case BEGIN_TOKEN : INSTS() ; break ;
    case ID_TOKEN    : AFFEC() ; break ;
    case IF_TOKEN    : SI()    ; break ;
    case WHILE_TOKEN : TANTQUE();break ;
    case WRITE_TOKEN : ECRIRE(); break ;
    case READ_TOKEN  : LIRE()  ; break ;
    default          : Erreur(INST_ERR) ; break ;
}
void AFFEC(void) {
  Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
  Test_Symbole(AFFEC_TOKEN,AFFEC_TOKEN_ERREUR);
  EXPR();
}
void SI(void) {
  Test_Symbole(IF_TOKEN,IF_TOKEN_ERREUR);
  COND();
  Test_Symbole(THEN_TOKEN,THEN_TOKEN_ERREUR);
  INST();
}
void TANTQUE(void) {
  Test_Symbole(WHILE_TOKEN,WHILE_TOKEN_ERREUR);
  COND();
  Test_Symbole(DO_TOKEN,DO_TOKEN_ERREUR);
  INST();
}
void ECRIRE(void) {
  Test_Symbole(WRITE_TOKEN,WRITE_TOKEN_ERREUR);
  Test_Symbole(PO_TOKEN,PO_TOKEN_ERREUR);
  EXPR();
  while(Token_Cour->TOKEN == VIR_TOKEN) {
    Symbole_Suiv();
    EXPR();
  }
  Test_Symbole(PF_TOKEN,PF_TOKEN_ERREUR);
}
void LIRE(void) {
  Test_Symbole(READ_TOKEN,READ_TOKEN_ERREUR);
  Test_Symbole(PO_TOKEN,PO_TOKEN_ERREUR);
  Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
  while(Token_Cour->TOKEN == VIR_TOKEN) {
    Symbole_Suiv();
    Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
  }
  Test_Symbole(PF_TOKEN,PF_TOKEN_ERREUR);
}
void COND(void) {
  EXPR();
  switch(Token_Cour->TOKEN) {
    case EGAL_TOKEN: break;
    case DIFF_TOKEN: break;
    case INF_TOKEN:  break;
    case SUP_TOKEN:  break;
    case INFEG_TOKEN:break;
    case SUPEG_TOKEN:break;
    default: Erreur(COND_ERR) ; break ;
  }
  EXPR();
}
void EXPR(void) {
  TERM();
  while(Token_Cour->TOKEN == PLUS_TOKEN || Token_Cour->TOKEN == MOINS_TOKEN) {
    Symbole_Suiv();
    TERM();
  }
}
void TERM(void) {
  FACT();
  while(Token_Cour->TOKEN == MULT_TOKEN || Token_Cour->TOKEN == DIV_TOKEN) {
    Symbole_Suiv();
    FACT();
  }
}
void FACT(void) {
  switch(Token_Cour->TOKEN) {
    case ID_TOKEN : break ;
    case PO_TOKEN : EXPR(); Test_Symbole(PF_TOKEN,PF_TOKEN_ERREUR); break ;
  }
}
int analy_syn() {
  (Sym_Arr_Struct*) Head_Arr_temp = Head_Arr_Symb ;
  Token_Cour = (Sym_Struct*)malloc(sizeof(Sym_Struct));
  Token_Cour->WORD = (char*)malloc(90);
  Symbole_Suiv();
  INSTS();
  return 0;
}
