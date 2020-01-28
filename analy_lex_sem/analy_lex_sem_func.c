#include "analy_lex_sem_func.h"
#include "analy_lex_sem_dec.h"

void push() {
  Sym_Arr_Struct *new_node = (Sym_Arr_Struct*)malloc(sizeof(Sym_Arr_Struct));
  new_node->data = (Sym_Struct*)malloc(sizeof(Sym_Struct));
  while(test->next != NULL) {
    test=test->next;
  }
  test->next=(Sym_Arr_Struct*)malloc(sizeof(Sym_Arr_Struct));
  test->next=new_node;
}
void Next_Car() {
  Car_Cour = fgetc(file);
}
void Next_Word() {
  int count_car = 0 ;
  *(Token_Cour->WORD+count_car)=Car_Cour;
  count_car++;
  Next_Car();
  while(('a'<=Car_Cour && Car_Cour<='z')||('A'<=Car_Cour && Car_Cour<='Z')||('0'<=Car_Cour && Car_Cour<='9')) {
    *(Token_Cour->WORD+count_car)=Car_Cour;
    count_car++;
    Next_Car();
  }
  if(count_car>=20) {}
  //printf("%s\n",Token_Cour->WORD);
  Check_Token();
}
void Next_Number() {
  int count_car = 0 ;
  *(Token_Cour->WORD+count_car)=Car_Cour;
  Next_Car();
  while(('0'<=Car_Cour && Car_Cour<='9')) {
    *(Token_Cour->WORD+count_car)=Car_Cour;
    count_car++;
    Next_Car();
  }
  if(count_car>=11) {}
  Token_Cour->TOKEN = NUM_TOKEN ;
}
void Next_Character() {
  int count_car = 0 ;
  const char type_start_char = Car_Cour ;
  *(Token_Cour->WORD+count_car)=Car_Cour;
  count_car++;
  Next_Car();
  while(1) {
    if(Car_Cour == type_start_char) {
      if(strcmp(*(Token_Cour->WORD+count_car-1),'\\')==0) {}
      else {
        Token_Cour->TOKEN = CHARACTER_TOKEN ;
        break;
      }
    }
    *(Token_Cour->WORD+count_car)=Car_Cour;
    count_car++;
    Next_Car();
  }
  if(type_start_char == '\'') {
    Token_Cour->TOKEN = APOST_TOKEN ;
    *Token_Cour->WORD = '\'' ;
  }
  else {
    Token_Cour->TOKEN = GUIL_TOKEN ;
    *Token_Cour->WORD = '"' ;
  }
  Next_Car();
}
void Check_Token() {
  if(strcmp("if",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = IF_TOKEN ;
  }
  else if(strcmp("else",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = ELSE_TOKEN ;
  }
  else if(strcmp("repeat",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = REPEAT_TOKEN ;
  }
  else if(strcmp("while",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = WHILE_TOKEN ;
  }
  else if(strcmp("for",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = FOR_TOKEN ;
  }
  else if(strcmp("in",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = IN_TOKEN ;
  }
  else if(strcmp("function",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = FUNCTION_TOKEN ;
  }
  else if(strcmp("next",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = NEXT_TOKEN ;
  }
  else if(strcmp("break",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = BREAK_TOKEN ;
  }
  else if(strcmp("true",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = TRUE_TOKEN ;
  }
  else if(strcmp("false",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = FALSE_TOKEN ;
  }
  else if(strcmp("null",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = NULL_TOKEN ;
  }
  else if(strcmp("print",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = PRINT_TOKEN ;
  }
  else if(strcmp("readline",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = READLINE_TOKEN ;
  }
  else if(strcmp("return",Token_Cour->WORD)==0) {
    Token_Cour->TOKEN = RETURN_TOKEN ;
  }
  else {
    Token_Cour->TOKEN = ID_TOKEN ;
  }
}
void Break_Comment() {
  Next_Car();
  while(1) {
    if(Car_Cour == 42) {
      Next_Car();
      if(Car_Cour == 125) {
        break;
      }
    }
    else {
      Next_Car();
    }
  }
}
void Next_Sym() {
  Token_Cour->TOKEN = NULL_TOKEN ;
  Token_Cour->WORD=memset(Token_Cour->WORD,'\0',sizeof(Token_Cour->WORD));
  switch(Car_Cour) {
    case 10 : Next_Car(); break;
    case 32 : Next_Car(); break;
    case ';': Token_Cour->TOKEN = PV_TOKEN ;
              *Token_Cour->WORD = ';' ;
              Next_Car(); break;
    case '+': Token_Cour->TOKEN = ADD_TOKEN ;
              *Token_Cour->WORD = '+' ;
              Next_Car(); break;
    //
    case '-': Next_Car();
              switch(Car_Cour) {
                case '>' : Next_Car();
                           switch(Car_Cour) {
                             case '>' : Token_Cour->TOKEN = RIGHT_ASGN_TOKEN ;
                                        Token_Cour->WORD=strcpy(Token_Cour->WORD,"->>");
                                        Next_Car(); break;
                             default  : Token_Cour->TOKEN = RIGHT_ASGN_TOKEN ;
                                        Token_Cour->WORD=strcpy(Token_Cour->WORD,"->");
                                        Next_Car(); break;
                           }; break ;
                default  : Token_Cour->TOKEN = SUB_TOKEN ;
                           *Token_Cour->WORD = '-' ;
                           Next_Car(); break;
              }; break ;
    //
    case '*': Token_Cour->TOKEN = MULT_TOKEN ;
              *Token_Cour->WORD = '*' ;
              Next_Car(); break;
    //
    case '/': Token_Cour->TOKEN = DIV_TOKEN ;
              *Token_Cour->WORD = '/' ;
              Next_Car(); break;
    //
    case '^': Token_Cour->TOKEN = EXPONENT_TOKEN ;
              *Token_Cour->WORD = '^' ;
              Next_Car(); break;
    //
    case '%': Next_Car();
              switch(Car_Cour) {
                case '%' : Token_Cour->TOKEN = MODULUS_TOKEN ;
                           Token_Cour->WORD=strcpy(Token_Cour->WORD,"%%");
                           Next_Car(); break;
                case '/' : Next_Car();
                           switch(Car_Cour) {
                             case '%' : Token_Cour->TOKEN = INT_DIV_TOKEN ;
                                        Token_Cour->WORD=strcpy(Token_Cour->WORD,"%/%");
                                        Next_Car(); break;
                             default  : Token_Cour->TOKEN = ERREUR_TOKEN ;
                           }; break ;
                default  : Token_Cour->TOKEN = ERREUR_TOKEN ;
              }; break ;
    //
    case '&': Next_Car();
              switch(Car_Cour) {
                case '&' : Token_Cour->TOKEN = LOGICAL_AND_TOKEN ;
                           Token_Cour->WORD=strcpy(Token_Cour->WORD,"&&");
                           Next_Car(); break;
                default  : Token_Cour->TOKEN = ELEMENTWISE_LOGICAL_AND_TOKEN ;
                           *Token_Cour->WORD = '&' ;
                           Next_Car(); break;
              }; break ;
    //
    case '|': Next_Car();
              switch(Car_Cour) {
                case '|' : Token_Cour->TOKEN = LOGICAL_OR_TOKEN ;
                           Token_Cour->WORD=strcpy(Token_Cour->WORD,"||");
                           Next_Car(); break;
                default  : Token_Cour->TOKEN = ELEMENTWISE_LOGICAL_OR_TOKEN ;
                           *Token_Cour->WORD = '|' ;
                           Next_Car(); break;
              }; break ;
    //
    case '=': Next_Car();
              switch(Car_Cour) {
                case '=' : Token_Cour->TOKEN = EQUALTO_TOKEN ;
                           Token_Cour->WORD=strcpy(Token_Cour->WORD,"==");
                           Next_Car(); break;
                default  : Token_Cour->TOKEN = LEFT_ASGN_TOKEN ;
                           *Token_Cour->WORD = '=' ;
                           Next_Car(); break;
              }; break ;
    //
    case '!': Next_Car();
              switch(Car_Cour) {
                case '=' : Token_Cour->TOKEN = NOT_EQUAL_TOKEN ;
                           Token_Cour->WORD=strcpy(Token_Cour->WORD,"!=");
                           Next_Car(); break;
                default  : Token_Cour->TOKEN = LOGICAL_NOT_TOKEN ;
                           *Token_Cour->WORD = '!' ;
                           Next_Car(); break;
              }; break ;
    //
    case '<': Next_Car();
              switch(Car_Cour) {
                case '=' : Token_Cour->TOKEN = INFEG_TOKEN ;
                           Token_Cour->WORD=strcpy(Token_Cour->WORD,"<=");
                           Next_Car(); break;
                //
                case '-' : Token_Cour->TOKEN = LEFT_ASGN_TOKEN ;
                           Token_Cour->WORD=strcpy(Token_Cour->WORD,"<-");
                           Next_Car(); break;
                //
                case '<' : Next_Car();
                           switch(Car_Cour) {
                             case '-' : Token_Cour->TOKEN = LEFT_ASGN_TOKEN ;
                                        Token_Cour->WORD=strcpy(Token_Cour->WORD,"<<-");
                                        Next_Car(); break;
                             default  : Token_Cour->TOKEN = ERREUR_TOKEN ;
                           }; break ;
                default  : Token_Cour->TOKEN = INF_TOKEN ;
                           *Token_Cour->WORD = '<' ;
                           Next_Car(); break;
              }; break ;
    //
    case '>': Next_Car();
              switch(Car_Cour) {
                case '=' : Token_Cour->TOKEN = SUPEG_TOKEN ;
                           Token_Cour->WORD=strcpy(Token_Cour->WORD,">=");
                           Next_Car(); break;
                default  : Token_Cour->TOKEN = SUP_TOKEN ;
                           *Token_Cour->WORD = '>' ;
                           Next_Car(); break;
              }; break ;
    //
    case '(': Token_Cour->TOKEN = PO_TOKEN ;
              *Token_Cour->WORD = '(' ;
              Next_Car(); break;
    //
    case ')': Token_Cour->TOKEN = PF_TOKEN ;
              *Token_Cour->WORD = ')' ;
              Next_Car(); break;
    //
    case '{': Token_Cour->TOKEN = AO_TOKEN ;
              *Token_Cour->WORD = '{' ;
              Next_Car(); break;
    //
    case '}': Token_Cour->TOKEN = AF_TOKEN ;
              *Token_Cour->WORD = '}' ;
              Next_Car(); break;
    //
    case '\'' :
    case '"'  : Next_Character(); break;
    default : if(('a'<=Car_Cour && Car_Cour<='z')||('A'<=Car_Cour && Car_Cour<='Z')){Next_Word();}
              else if('0'<=Car_Cour && Car_Cour<='9') {Next_Number();}
              else {Next_Car();}
    }
}

int analy_lex_sem_dec(char *filename) {
  file=fopen(filename,"a+");
  Token_Cour = (Sym_Struct*)malloc(sizeof(Sym_Struct));
  Token_Cour->WORD = (char*)malloc(21);
  Next_Car();
  while(Car_Cour != EOF) {
    Next_Sym();
    if(Token_Cour->TOKEN != NULL_TOKEN) {
      printf("%s ----> %s\n",ARR_TOK[Token_Cour->TOKEN].TOKENS,Token_Cour->WORD);
    }
  }
  return 0;
}
