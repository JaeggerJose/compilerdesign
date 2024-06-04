%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern int yylex();
extern int yyparse();
void yyerror(const char *s);

double factorial(double n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void prime_factors(int n) {
    while (n % 2 == 0) {
        printf("%d ", 2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n = n / i;
        }
    }
    if (n > 2)
        printf("%d", n);
    printf("\n");
}

void itoa(int num, char* str, int base) {
    int i = 0;
    int isNegative = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    if (isNegative)
        str[i++] = '-';

    str[i] = '\0';

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void to_binary(int n) {
    char buffer[33];
    itoa(n, buffer, 2);
    printf("%s\n", buffer);
}

void to_octal(int n) {
    char buffer[33];
    itoa(n, buffer, 8);
    printf("%s\n", buffer);
}


void to_hex(int n) {
    char buffer[33];
    itoa(n, buffer, 16);
    printf("%s\n", buffer);
}

%}

%union {
    double num;
    char *id;
}

%token <num> NUMBER
%token <id> IDENTIFIER
%token SIGMA PI ABS ROOT PRIMEFACTORS TO_BIN TO_OCT TO_HEX
%token SIN COS TAN COT SEC CSC
%token EOL
%token LPAREN RPAREN EQUAL LBRACE RBRACE COMMA
%token PLUS MINUS MULTIPLY DIVIDE POWER

%type <num> expression condition

%left PLUS MINUS
%left MULTIPLY DIVIDE
%left POWER
%right FACTORIAL
%left LPAREN RPAREN

%%

input:
    | input line
    ;

line:
    expression EOL { printf("Result: %g\n", $1); }
    | PRIMEFACTORS LPAREN expression RPAREN EOL { printf("Prime Factors: "); prime_factors((int)$3); }
    | TO_BIN LPAREN expression RPAREN EOL { printf("Binary: "); to_binary((int)$3); }
    | TO_OCT LPAREN expression RPAREN EOL { printf("Octal: "); to_octal((int)$3); }
    | TO_HEX LPAREN expression RPAREN EOL { printf("Hexadecimal: "); to_hex((int)$3); }
    ;

expression:
    SIGMA LPAREN IDENTIFIER COMMA condition RPAREN {
        int var_value = (int)$5;
        double result = 0;
        for (int i = 0; i <= var_value; i++) {
            result += i;
        }
        $$ = result;
    }
    | expression PLUS expression { $$ = $1 + $3; }
    | expression MINUS expression { $$ = $1 - $3; }
    | expression MULTIPLY expression { $$ = $1 * $3; }
    | expression DIVIDE expression { $$ = $1 / $3; }
    | expression POWER expression { $$ = pow($1, $3); }
    | ROOT LPAREN expression RPAREN { $$ = sqrt($3); }
    | ABS LPAREN expression RPAREN { $$ = fabs($3); }
    | SIN LPAREN expression RPAREN { $$ = sin($3); }
    | COS LPAREN expression RPAREN { $$ = cos($3); }
    | TAN LPAREN expression RPAREN { $$ = tan($3); }
    | COT LPAREN expression RPAREN { $$ = 1/tan($3); }
    | SEC LPAREN expression RPAREN { $$ = 1/cos($3); }
    | CSC LPAREN expression RPAREN { $$ = 1/sin($3); }
    | expression FACTORIAL { $$ = factorial($1); }
    | MINUS expression %prec POWER { $$ = -$2; }
    | LPAREN expression RPAREN { $$ = $2; }
    | NUMBER { $$ = $1; }
    | PI { $$ = M_PI; }
    ;

condition:
    IDENTIFIER EQUAL NUMBER { $$ = $3; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}