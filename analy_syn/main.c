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
    case PRINT_TOKEN : Symbole_Suiv();PRINT()        ; break ;
    case WHILE_TOKEN : Symbole_Suiv();BOUCLE_WHILE() ; break ;
    case FOR_TOKEN   : Symbole_Suiv();BOUCLE_FOR()   ; break ;
    case IF_TOKEN    : Symbole_Suiv();IF()           ; break ;
    case ID_TOKEN    : Symbole_Suiv();ASSIGN()        ; break ;

  }
}

void ASSIGN(void) {
  switch (Token_Cour->TOKEN) {
    case LEFT_ASGN_TOKEN  : Symbole_Suiv();
                            LEFT_ASSIGN();
                            break ;
    case RIGHT_ASGN_TOKEN : Symbole_Suiv();
                            RIGHT_ASSIGN();
                            break ;
    case NUM_TOKEN        :       ;
    case GUIL_TOKEN       :       ;
    case PO_TOKEN         : Symbole_Suiv();
                            EXPR();
                            break ;
    default               : Erreur(ASSGN_ERR) ; break ;
  }
}
void LEFT_ASSIGN(void) {
  switch (Token_Cour->TOKEN) {
    case FUNCTION_TOKEN   : Symbole_Suiv();
                            FUNCTION();
                            break ;
    case READLINE_TOKEN   : Symbole_Suiv();
                            READ_LINE();
                            break ;
    case ID_TOKEN         :       ;
    case NUM_TOKEN        :       ;
    case GUIL_TOKEN       :       ;
    case PO_TOKEN         : Symbole_Suiv();
                            EXPR();
                            break ;
    default               : Erreur(ASSGN_ERR) ; break ;
  }
}
void RIGHT_ASSIGN(void) {
  Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
}
//
void PRINT(void) {
  Test_Symbole(PO_TOKEN,PO_TOKEN_ERREUR);
  EXPR();
  Test_Symbole(PF_TOKEN,PF_TOKEN_ERREUR);
}
//
void IF(void) {
  Test_Symbole(PO_TOKEN,PO_TOKEN_ERREUR);
  COND();
  Test_Symbole(PF_TOKEN,PF_TOKEN_ERREUR);
  INSTS();
  while(Token_Cour->TOKEN  == ELSE_TOKEN) {
    INSTS();
  }
}
//
void BOUCLE_FOR(void) {
  Test_Symbole(PO_TOKEN,PO_TOKEN_ERREUR);
  Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
  Test_Symbole(IN_TOKEN,IN_TOKEN_ERREUR);
  SEQ();
  Test_Symbole(PF_TOKEN,PO_TOKEN_ERREUR);
  Test_Symbole(AO_TOKEN,PO_TOKEN_ERREUR);
  INST();
  Test_Symbole(AF_TOKEN,PO_TOKEN_ERREUR);
  }
void BOUCLE_WHILE(void) {
  Test_Symbole(PO_TOKEN,PO_TOKEN_ERREUR);
  COND();
  Test_Symbole(PF_TOKEN,PO_TOKEN_ERREUR);
  Test_Symbole(AO_TOKEN,PO_TOKEN_ERREUR);
  INST();
  Test_Symbole(AF_TOKEN,PO_TOKEN_ERREUR);
  }
//
void FUNC(void) {
  Test_Symbole(PO_TOKEN,PO_TOKEN_ERREUR);
  Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
  while( Token_Cour->TOKEN == VIR_TOKEN) {
    Symbole_Suiv();
    Test_Symbole(ID_TOKEN,ID_TOKEN_ERREUR);
  }
  Test_Symbole(PF_TOKEN,PO_TOKEN_ERREUR);
  Test_Symbole(AO_TOKEN,PO_TOKEN_ERREUR);
  INST();
  Test_Symbole(RETURN_TOKEN,RETURN_TOKEN_ERREUR);
  Test_Symbole(PO_TOKEN,PO_TOKEN_ERREUR);
  EXPR();
  Test_Symbole(PF_TOKEN,PO_TOKEN_ERREUR);
  Test_Symbole(AF_TOKEN,PO_TOKEN_ERREUR);
}
//
void READ_LINE(void) {
  Test_Symbole(PO_TOKEN,PO_TOKEN_ERREUR);
  if(Token_Cour->TOKEN == GUIL_TOKEN ) {
    Test_Symbole(CHARACTER_TOKEN,CHARACTER_TOKEN_ERREUR);
    Test_Symbole(GUIL_TOKEN,GUIL_TOKEN_ERREUR);
  }
  Test_Symbole(PF_TOKEN,PF_TOKEN_ERREUR);
}
//
void COND(void) {
  COND1();
  while(Token_Cour->TOKEN == LOGICAL_AND_TOKEN || Token_Cour->TOKEN == LOGICAL_OR_TOKEN ) {
    Symbole_Suiv();
    COND1();
  }
}
void COND1(void) {
  if(Token_Cour->TOKEN == PO_TOKEN ) {
    COND2();
    Test_Symbole(PF_TOKEN,PF_TOKEN_ERREUR);
  }
  COND2();
}
void COND2(void) {
  if(Token_Cour->TOKEN == LOGICAL_NOT_TOKEN) {Symbole_Suiv();}
  COND3();
}
void COND3(void) {
  COND4() ;
  while(Token_Cour->TOKEN == INF_TOKEN || Token_Cour->TOKEN == SUP_TOKEN || Token_Cour->TOKEN == INFEG_TOKEN || Token_Cour->TOKEN == SUPEG_TOKEN || Token_Cour->TOKEN == EQUALTO_TOKEN || Token_Cour->TOKEN == NOT_EQUAL_TOKEN) {
    Symbole_Suiv();
    COND4();
  }
}
void COND4(void) {
  switch(Token_Cour->TOKEN) {
    case TRUE_TOKEN  : Symbole_Suiv() ; break ;
    case FALSE_TOKEN : Symbole_Suiv() ; break ;
    default          : Symbole_Suiv() ; EXPR(); break ;
  }
}
//
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
    case NUM_TOKEN : Symbole_Suiv(); break ;
    case ID_TOKEN  : Symbole_Suiv(); break ;
    case GUIL_TOKEN : Symbole_Suiv();
                      Test_Symbole(CHARACTER_TOKEN,CHARACTER_TOKEN_ERREUR);
                      Test_Symbole(GUIL_TOKEN,GUIL_TOKEN_ERREUR);
                      break ;
    case PO_TOKEN  : EXPR(); Test_Symbole(PF_TOKEN,PF_TOKEN_ERREUR); break ;
  }
}
//
int analy_syn() {
  (Sym_Arr_Struct*) Head_Arr_temp = Head_Arr_Symb ;
  Token_Cour = (Sym_Struct*)malloc(sizeof(Sym_Struct));
  Token_Cour->WORD = (char*)malloc(90);
  Symbole_Suiv();
  INSTS();
  return 0;
}
