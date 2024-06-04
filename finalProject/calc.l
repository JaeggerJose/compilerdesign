%{
#include "y.tab.h"
#include <openssl/md5.h>
#include <openssl/sha.h>
%}

digit      [0-9]
letter     [a-zA-Z]

%%

SIGMA         { return SIGMA; }
ABS           { return ABS; }
ROOT          { return ROOT; }
PRIMEFACTORS  { return PRIMEFACTORS; }
TO_BIN        { return TO_BIN; }
TO_OCT        { return TO_OCT; }
TO_DEC        { return TO_DEC; }
TO_HEX        { return TO_HEX; }
pi            { return PI; }
sin           { return SIN; }
cos           { return COS; }
tan           { return TAN; }
cot           { return COT; }
sec           { return SEC; }
csc           { return CSC; }
sinh          { return SINH; }
cosh          { return COSH; }
tanh          { return TANH; }
coth          { return COTH; }
sech          { return SECH; }
csch          { return CSCH; }
sha256        { return SHA256HASH; }
md5           { return MD5HASH; }
log           { return LOG; }
">"           { return GT; }
"<"           { return LT; }
"=="          { return EQ; }
"!="          { return NE; }
"%"           { return MOD; }
-?{digit}+(\.{digit}+)?([eE][+-]?{digit}+)? { yylval.num = atof(yytext); return NUMBER; }
{letter}+     { yylval.id = strdup(yytext); return IDENTIFIER; }
\(            { return LPAREN; }
\)            { return RPAREN; }
\=            { return EQUAL; }
\,            { return COMMA; }
\+            { return PLUS; }
\-            { return MINUS; }
\*            { return MULTIPLY; }
\/            { return DIVIDE; }
\^            { return POWER; }
\!            { return FACTORIAL; }
\n            { return EOL; }
[ \t]         ; // Ignore whitespace

.             { printf("Unknown character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
