#include "analy_syn_func.h"

void Symbole_Suiv(void) {
  Head_Arr_temp = Head_Arr_temp->next ;
  Token_Cour = Head_Arr_temp->Data ;
  printf("%s\n",Token_Cour->WORD);
}

void Test_Symbole(TOKENS token,ERRORS erreur) {
  if(Token_Cour->TOKEN == token) {
    if(token != EOF_TOKEN) {
      Symbole_Suiv();
    }
  }
  else {
    raise_error(erreur);
  }
}

void INSTS() {
  if(Token_Cour->TOKEN  == AO_TOKEN) {
    Symbole_Suiv();
    INST();
    Test_Symbole(AF_TOKEN,EXPECTED_TOKEN_AF);
    Test_Symbole(EOF_TOKEN,EXPECTED_TOKEN_EOF);
  }
  else {
    INST();
    while(Token_Cour->TOKEN == PRINT_TOKEN || Token_Cour->TOKEN == WHILE_TOKEN || Token_Cour->TOKEN == FOR_TOKEN  || Token_Cour->TOKEN == IF_TOKEN  || Token_Cour->TOKEN == ID_TOKEN ) {
      INST();
    }
    Test_Symbole(EOF_TOKEN,EXPECTED_TOKEN_EOF);
  }
}

void INST() {
  switch (Token_Cour->TOKEN) {
    case PRINT_TOKEN : Symbole_Suiv();PRINT()        ; break ;
    case WHILE_TOKEN : Symbole_Suiv();BOUCLE_WHILE() ; break ;
    case FOR_TOKEN   : Symbole_Suiv();BOUCLE_FOR()   ; break ;
    case IF_TOKEN    : Symbole_Suiv();IF()           ; break ;
    case ID_TOKEN    : Symbole_Suiv();ASSIGN()  ; break ;
    case NUM_TOKEN   : EXPR();
                       if(Token_Cour->TOKEN == RIGHT_ASGN_TOKEN) {
                         Symbole_Suiv();
                         RIGHT_ASSIGN();
                      }; break ;
    case GUIL_TOKEN  : EXPR();
                       if(Token_Cour->TOKEN == RIGHT_ASGN_TOKEN) {
                         Symbole_Suiv();
                         RIGHT_ASSIGN();
                      }; break ;
    case PO_TOKEN    : EXPR();
                       if(Token_Cour->TOKEN == RIGHT_ASGN_TOKEN) {
                         Symbole_Suiv();
                         RIGHT_ASSIGN();
                      }; break ;
  }
}

void ASSIGN(void) {
  switch (Token_Cour->TOKEN) {
    case LEFT_ASGN_TOKEN  : Symbole_Suiv();
                            LEFT_ASSIGN();
                            break ;
   default                : EXPR();
                            if(Token_Cour->TOKEN == RIGHT_ASGN_TOKEN) {
                              Symbole_Suiv();
                              RIGHT_ASSIGN();
                            }; break ;
  }
}
void LEFT_ASSIGN(void) {
  switch (Token_Cour->TOKEN) {
    case FUNCTION_TOKEN   : Symbole_Suiv();
                            FUNC();
                            break ;
    case READLINE_TOKEN   : Symbole_Suiv();
                            READ_LINE();
                            break ;
    default               : printf("inst");INST() ; break ;
  }
}
void RIGHT_ASSIGN(void) {
  Test_Symbole(ID_TOKEN,EXPECTED_TOKEN_ID);
}
//
void PRINT(void) {
  Test_Symbole(PO_TOKEN,EXPECTED_TOKEN_PO);
  EXPR();
  Test_Symbole(PF_TOKEN,EXPECTED_TOKEN_PF);
}
//
void IF(void) {
  Test_Symbole(PO_TOKEN,EXPECTED_TOKEN_PO);
  COND();
  Test_Symbole(PF_TOKEN,EXPECTED_TOKEN_PF);
  INSTS();
  while(Token_Cour->TOKEN  == ELSE_TOKEN) {
    INSTS();
  }
}
//
void BOUCLE_FOR(void) {
  Test_Symbole(PO_TOKEN,EXPECTED_TOKEN_PO);
  Test_Symbole(ID_TOKEN,EXPECTED_TOKEN_ID);
  Test_Symbole(IN_TOKEN,EXPECTED_TOKEN_EOF);
  SEQ();
  Test_Symbole(PF_TOKEN,EXPECTED_TOKEN_PF);
  Test_Symbole(AO_TOKEN,EXPECTED_TOKEN_AO);
  INST();
  Test_Symbole(AF_TOKEN,EXPECTED_TOKEN_AF);
  }
void BOUCLE_WHILE(void) {
  Test_Symbole(PO_TOKEN,EXPECTED_TOKEN_PO);
  COND();
  Test_Symbole(PF_TOKEN,EXPECTED_TOKEN_PF);
  Test_Symbole(AO_TOKEN,EXPECTED_TOKEN_AO);
  INST();
  Test_Symbole(AF_TOKEN,EXPECTED_TOKEN_AF);
  }
//
void FUNC(void) {
  Test_Symbole(PO_TOKEN,EXPECTED_TOKEN_PO);
  Test_Symbole(ID_TOKEN,EXPECTED_TOKEN_ID);
  while( Token_Cour->TOKEN == VIR_TOKEN) {
    Symbole_Suiv();
    Test_Symbole(ID_TOKEN,EXPECTED_TOKEN_ID);
  }
  Test_Symbole(PF_TOKEN,EXPECTED_TOKEN_PF);
  Test_Symbole(AO_TOKEN,EXPECTED_TOKEN_AO);
  INST();
  Test_Symbole(RETURN_TOKEN,EXPECTED_TOKEN_RETURN);
  Test_Symbole(PO_TOKEN,EXPECTED_TOKEN_PO);
  EXPR();
  Test_Symbole(PF_TOKEN,EXPECTED_TOKEN_PF);
  Test_Symbole(AF_TOKEN,EXPECTED_TOKEN_AF);
}
//
void SEQ() {}
void READ_LINE(void) {
  Test_Symbole(PO_TOKEN,EXPECTED_TOKEN_PO);
  if(Token_Cour->TOKEN == GUIL_TOKEN ) {
    Test_Symbole(CHARACTER_TOKEN,EXPECTED_TOKEN_CHARACTER);
    Test_Symbole(GUIL_TOKEN,EXPECTED_TOKEN_GUIL);
  }
  Test_Symbole(PF_TOKEN,EXPECTED_TOKEN_PF);
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
    Test_Symbole(PF_TOKEN,EXPECTED_TOKEN_PF);
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
  while(Token_Cour->TOKEN == ADD_TOKEN || Token_Cour->TOKEN == SUB_TOKEN) {
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
    case ID_TOKEN  : Symbole_Suiv();
                     if(Token_Cour->TOKEN == PO_TOKEN ) {

                       Symbole_Suiv();
                       CALL_FUNC();
                       Test_Symbole(PF_TOKEN,EXPECTED_TOKEN_PF);
                     }
                     break ;
    case GUIL_TOKEN : Symbole_Suiv();
                      Test_Symbole(CHARACTER_TOKEN,EXPECTED_TOKEN_CHARACTER);
                      Test_Symbole(GUIL_TOKEN,EXPECTED_TOKEN_GUIL);
                      break ;
    case PO_TOKEN  : Symbole_Suiv();EXPR(); Test_Symbole(PF_TOKEN,EXPECTED_TOKEN_PF); break ;
  }
}
void CALL_FUNC(void) {

  EXPR();
  while(Token_Cour->TOKEN == VIR_TOKEN) {
    EXPR();
  }
}
//
int analy_syn() {
  Head_Arr_temp = Head_Arr_Symb->next ;
  Token_Cour = (Sym_Struct*)malloc(sizeof(Sym_Struct));
  Token_Cour->WORD = (char*)malloc(90);
  Token_Cour = Head_Arr_temp->Data;
  printf("first == %s\n",Token_Cour->WORD);
  INSTS();
  return 0;
}
