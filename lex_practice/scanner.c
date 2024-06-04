#include <stdio.h>
#include "scanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "db_type", "db_id", "db_table_prefix", "db_port"};

int main(void) {

    int ntoken, vtoken;
    ntoken = yylex();
    while(ntoken) {
        printf("%d\n", ntoken);
        if(yylex() != COLON) {
            printf("Syntax error in line %d, expected a colon, but found %s\n", yylineno, yytext);
            return 1;
        }
        vtoken = yylex();
        switch(ntoken) {
            case TYPE:
            case ID:
            case PREFIX:
                if(vtoken != IDENTIFIER) {
                    printf("Syntax error in line %d, expected an identifier, but found %s\n", yylineno, yytext);
                    return 1;
                }
                printf("%s is %s\n", names[ntoken], yytext);
                break;
            case PORT:
                if(vtoken != INTEGER) {
                    printf("Syntax error in line %d, expected an integer, but found %s\n", yylineno, yytext);
                    return 1;
                }
                printf("Port number is %s\n", yytext);
                break;
            default:
                printf("Syntax error in line %d\n", yylineno);
                return 1;
        }
        ntoken = yylex();
    }
    return 0;

}