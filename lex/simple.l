%{
    #include <stdio.h>
    extern int yylval;
%}

%%
"@"         {return APPLY; }
"if"        { return IFTOKEN;}
"then"      {return THENTOKEN;}
"else"      {return ELSETOKEN;}
"("         {   return LPAREN; }
")"         { return RPAREN; }
"{"         {return LCURL; }
"}"         {return RCURL;}
"lamda"     { return LAMDA; }
"true"      { return TRUE; }
"false"     { return FALSE; }
[a-zA-Z]+   { return IDENTIFIER; }
[0-9]+      { yylval = atoi(yytext); return NUMBER; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return TIMES; }
"/"         { return DIVIDE; }
[ \t\r\n]     {}

%%

int yywrap(void){ return 1; }
