%{
#include "y.tab.h"
%}

digit      [0-9]
letter     [a-zA-Z]

%%

SIGMA      { return SIGMA; }
ABS        { return ABS; }
ROOT       { return ROOT; }
PRIMEFACTORS { return PRIMEFACTORS; }
TO_BIN     { return TO_BIN; }
TO_OCT     { return TO_OCT; }
TO_HEX     { return TO_HEX; }
pi         { return PI; }
sin        { return SIN; }
cos        { return COS; }
tan        { return TAN; }
cot        { return COT; }
sec        { return SEC; }
csc        { return CSC; }
-?{digit}+(\.{digit}+)?([eE][+-]?{digit}+)? { yylval.num = atof(yytext); return NUMBER; }
{letter}+  { yylval.id = strdup(yytext); return IDENTIFIER; }
\(         { return LPAREN; }
\)         { return RPAREN; }
\=         { return EQUAL; }
\,         { return COMMA; }
\+         { return PLUS; }
\-         { return MINUS; }
\*         { return MULTIPLY; }
\/         { return DIVIDE; }
\^         { return POWER; }
\!         { return FACTORIAL; }
\n         { return EOL; }
[ \t]      ; // Ignore whitespace

.          { printf("Unknown character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}