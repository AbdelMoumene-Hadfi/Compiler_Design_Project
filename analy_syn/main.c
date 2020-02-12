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
//
void BOUCLE_WHILE(void) {
  Test_Symbole(PO_TOKEN,PO_TOKEN_ERREUR);
  COND();
  Test_Symbole(PF_TOKEN,PO_TOKEN_ERREUR);
  Test_Symbole(AO_TOKEN,PO_TOKEN_ERREUR);
  INST();
  Test_Symbole(AF_TOKEN,PO_TOKEN_ERREUR);
  }
//
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
