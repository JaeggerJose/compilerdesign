/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    SIGMA = 260,                   /* SIGMA  */
    PI = 261,                      /* PI  */
    ABS = 262,                     /* ABS  */
    ROOT = 263,                    /* ROOT  */
    PRIMEFACTORS = 264,            /* PRIMEFACTORS  */
    TO_BIN = 265,                  /* TO_BIN  */
    TO_OCT = 266,                  /* TO_OCT  */
    TO_DEC = 267,                  /* TO_DEC  */
    TO_HEX = 268,                  /* TO_HEX  */
    SIN = 269,                     /* SIN  */
    COS = 270,                     /* COS  */
    TAN = 271,                     /* TAN  */
    COT = 272,                     /* COT  */
    SEC = 273,                     /* SEC  */
    CSC = 274,                     /* CSC  */
    EOL = 275,                     /* EOL  */
    LPAREN = 276,                  /* LPAREN  */
    RPAREN = 277,                  /* RPAREN  */
    EQUAL = 278,                   /* EQUAL  */
    LBRACE = 279,                  /* LBRACE  */
    RBRACE = 280,                  /* RBRACE  */
    COMMA = 281,                   /* COMMA  */
    PLUS = 282,                    /* PLUS  */
    MINUS = 283,                   /* MINUS  */
    MULTIPLY = 284,                /* MULTIPLY  */
    DIVIDE = 285,                  /* DIVIDE  */
    POWER = 286,                   /* POWER  */
    FACTORIAL = 287                /* FACTORIAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUMBER 258
#define IDENTIFIER 259
#define SIGMA 260
#define PI 261
#define ABS 262
#define ROOT 263
#define PRIMEFACTORS 264
#define TO_BIN 265
#define TO_OCT 266
#define TO_DEC 267
#define TO_HEX 268
#define SIN 269
#define COS 270
#define TAN 271
#define COT 272
#define SEC 273
#define CSC 274
#define EOL 275
#define LPAREN 276
#define RPAREN 277
#define EQUAL 278
#define LBRACE 279
#define RBRACE 280
#define COMMA 281
#define PLUS 282
#define MINUS 283
#define MULTIPLY 284
#define DIVIDE 285
#define POWER 286
#define FACTORIAL 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 93 "calc.y"

    double num;
    char *id;

#line 136 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
