
typedef enum _error_codes {
  ERR_CAR_INC,ERR_FICH_VID,UNEXPECTED_TOKEN,EXPECTED_TOKEN_IF,EXPECTED_TOKEN_ELSE,EXPECTED_TOKEN_FOR,
  EXPECTED_TOKEN_REPEAT,EXPECTED_TOKEN_WHILE,EXPECTED_TOKEN_FUNCTION,EXPECTED_TOKEN_IN,EXPECTED_TOKEN_NEXT,EXPECTED_TOKEN_BREAK,EXPECTED_TOKEN_TRUE,
  EXPECTED_TOKEN_FALSE,EXPECTED_TOKEN_NULL,
  EXPECTED_TOKEN_ADD,EXPECTED_TOKEN_SUB,EXPECTED_TOKEN_MULT,EXPECTED_TOKEN_DIV,EXPECTED_TOKEN_EXPONENT,EXPECTED_TOKEN_MODULUS,EXPECTED_TOKEN_INT_DIV,
  EXPECTED_TOKEN_INF,EXPECTED_TOKEN_SUP,EXPECTED_TOKEN_INFEG,EXPECTED_TOKEN_SUPEG,EXPECTED_TOKEN_EQUALTO,EXPECTED_TOKEN_NOT_EQUAL,
  EXPECTED_TOKEN_LOGICAL_NOT,EXPECTED_TOKEN_LOGICAL_AND,EXPECTED_TOKEN_LOGICAL_OR,EXPECTED_TOKEN_ELEMENTWISE_LOGICAL_AND,EXPECTED_TOKEN_ELEMENTWISE_LOGICAL_OR,
  EXPECTED_TOKEN_LEFT_ASGN,EXPECTED_TOKEN_RIGHT_ASGN,EXPECTED_TOKEN_PO,EXPECTED_TOKEN_PF,EXPECTED_TOKEN_AO,EXPECTED_TOKEN_AF,EXPECTED_TOKEN_PRINT,EXPECTED_TOKEN_READLINE,EXPECTED_TOKEN_RETURN,EXPECTED_TOKEN_CHARACTER,
  EXPECTED_TOKEN_PV,EXPECTED_TOKEN_COMPLEX,EXPECTED_TOKEN_HEX,EXPECTED_TOKEN_NUM,EXPECTED_TOKEN_ID,EXPECTED_TOKEN_ERREUR,EXPECTED_TOKEN_APOST,
  EXPECTED_TOKEN_GUIL,EXPECTED_TOKEN_TWO_POINT,EXPECTED_TOKEN_VIR,EXPECTED_TOKEN_COND,EXPECTED_TOKEN_AFF,ERRORS_NUMBER
}ERRORS;

typedef struct ERROR_STRUCT {
  ERRORS ERROR ; CHAR ERROR_ST[30];
}ERROR_STRUCT ;
// Error messages
ERROR_STRUCT errors[ERRORS_NUMBER] = {
    {ERR_CAR_INC,"Undefined caracter"},{ERR_FICH_VID,"error 'empty'"},{UNEXPECTED_TOKEN,"unexpected symbol"},{EXPECTED_TOKEN_IF,"if() expression cannot be executed."},
    {EXPECTED_TOKEN_ELSE,"unexpected 'else'"},{EXPECTED_TOKEN_FOR,"unexpected 'for'"},{EXPECTED_TOKEN_REPEAT,"unexpected 'repeat'"},
    {EXPECTED_TOKEN_WHILE,"unexpected 'while'"},{EXPECTED_TOKEN_FUNCTION,"unexpected 'function'"},{EXPECTED_TOKEN_IN,"unexpected 'in'"},
    {EXPECTED_TOKEN_NEXT,"unexpected 'next'"},{EXPECTED_TOKEN_BREAK,"unexpected 'break'"},{EXPECTED_TOKEN_TRUE,"unexpected 'true'"},
    {EXPECTED_TOKEN_FALSE,"unexpected 'false'"},{EXPECTED_TOKEN_NULL,"unexpected 'null'"},{EXPECTED_TOKEN_ADD,"unexpected '+'"},
    {EXPECTED_TOKEN_SUB,"unexpected '-'"},{EXPECTED_TOKEN_MULT,"unexpected '*'"},{EXPECTED_TOKEN_DIV,"unexpected '/'"},
    {EXPECTED_TOKEN_EXPONENT,"unexpected 'exp'"},{EXPECTED_TOKEN_MODULUS,"unexpected 'mod'"},{EXPECTED_TOKEN_INT_DIV,"unexpected 'whole division'"},
    {EXPECTED_TOKEN_INF,"unexpected '<'"},{EXPECTED_TOKEN_SUP,"unexpected '>'"},{EXPECTED_TOKEN_INFEG,"unexpected '<='"},
    {EXPECTED_TOKEN_SUPEG,"unexpected '>='"},{EXPECTED_TOKEN_EQUALTO,"unexpected '=='"},{EXPECTED_TOKEN_NOT_EQUAL,"unexpected '!='"},
    {EXPECTED_TOKEN_LOGICAL_NOT,"unexpected 'not'"},{EXPECTED_TOKEN_LOGICAL_AND,"unexpected '&&'"},
    {EXPECTED_TOKEN_LOGICAL_OR,"unexpected '||'"},{EXPECTED_TOKEN_ELEMENTWISE_LOGICAL_AND,"unexpected 'and'"},
    {EXPECTED_TOKEN_ELEMENTWISE_LOGICAL_OR,"unexpected 'ELEMENTWISE LOGICAL OR'"},{EXPECTED_TOKEN_LEFT_ASGN,"EXPECTED_TOKEN_LEFT_ASGN"},
    {EXPECTED_TOKEN_RIGHT_ASGN,"EXPECTED_TOKEN_RIGHT_ASGN"},{EXPECTED_TOKEN_PO,"unexpected 'PO'"},{EXPECTED_TOKEN_PF,"unexpected 'PF'"},
    {EXPECTED_TOKEN_AO,"unexpected 'AO'"},{EXPECTED_TOKEN_AF,"unexpected 'AF'"},{EXPECTED_TOKEN_PRINT,"unexpected 'print'"},
    {EXPECTED_TOKEN_READLINE,"unexpected 'readline'"},{EXPECTED_TOKEN_RETURN,"unexpected 'return'"},{EXPECTED_TOKEN_CHARACTER,"unexpected 'character'"},
    {EXPECTED_TOKEN_PV,"unexpected ';'"},{EXPECTED_TOKEN_COMPLEX,"unexpected 'complex'"},{EXPECTED_TOKEN_HEX,"unexpected 'hex'"},
    {EXPECTED_TOKEN_NUM,"unexpected 'number'"},{EXPECTED_TOKEN_ID,"unexpected 'identifier'"},{EXPECTED_TOKEN_ERREUR,"unexpected 'error'"},
    {EXPECTED_TOKEN_APOST,"unexpected 'post'"},{EXPECTED_TOKEN_GUIL,"unexpected '''"},{EXPECTED_TOKEN_TWO_POINT,"unexpected ':'"},
    {EXPECTED_TOKEN_VIR,"unexpected ','"},{EXPECTED_TOKEN_COND,"unexpected 'condition'"},{EXPECTED_TOKEN_AFF,"unexpected '?'"},
    
  }
    // 1+"one" : number + char
    //Error: unexpected symbol in "5x" => 5*x # OK  or x + 2 y * 3## Error: unexpected symbol in "x + 2 y" => x + 2; y * 3 # OK
    //if x > 0 {} ## Error: unexpected symbol in "if x" if(x > 0) {} # OK
    //In an if-else statement, the keyword else must appear on the same line as the end of the if block.
    //'=' instead of '=='
    //  c(1 2) => c(1,2)
    // Not quoting file paths 'path.expand("")
    //Error: unexpected symbol in ""x"y"   "x\"y" # OK 'x"y'  # OK
    // {}}
    // {{}
    // when you’ve got an list of numeric strings which you want R to treat as numbers.
    // when you sending a missing value (Null or N/A) to a field where a Boolean True / False is required
};
void raise_error(ERRORS error);
//
