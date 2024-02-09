// declarations
%{
    #include <stdio.h>
    int yylex();
    int yyerror();
%}

%%
// rules
%token NUMBER PLUS MINUS TIMES DIVIDE LAMDA LPAREN RPAREN LCURL RCURL;
%token TRUE FALSE IDENTIFIER APPLY IFTOKEN ELSETOKEN THENTOKEN;
%left PLUS MINUS;
%left TIMES DIVIDE;
%left APPLY;

term :  
      LAMDA LPAREN IDENTIFIER RPAREN LCURL term RCURL { printf("Lamda node %d\n", $6); }
      | term APPLY term { printf("Apply node\n"); } 
      | term operation term  { printf("Operation node\n"); }
      | IFTOKEN LPAREN term RPAREN THENTOKEN LCURL term RCURL ELSETOKEN LCURL term RCURL { printf("if then else node\n"); }
      | IDENTIFIER
      | TRUE
      | FALSE
      | NUMBER
;
operation : PLUS | MINUS | DIVIDE | TIMES;
%%
// programs
#include "lex.yy.c"
struct node {
	int type;
	int value;
}

int main() {
  yyparse();
  return 1;
}
