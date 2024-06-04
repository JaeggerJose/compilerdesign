%{
#include "scanner.h"
%}

%%
:                   return COLON;
"db_type"           return TYPE;
"db_id"             return ID;
"db_table_prefix"   return PREFIX;
"db_port"           return PORT;

[a-zA-Z][_a-zA-Z0-9]*   return IDENTIFIER;
[1-9][0-9]*         return INTEGER;
[ \t\n]             ;
.                   printf("Unrecognized character\n");

%%

int yywrap(void) {
    return 1;
}