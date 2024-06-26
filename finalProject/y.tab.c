/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "calc.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

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

void to_decimal(int n) {
    printf("%d\n", n);
}

void to_hex(int n) {
    char buffer[33];
    itoa(n, buffer, 16);
    printf("%s\n", buffer);
}

void sha256_string(const char *string) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)string, strlen(string), hash);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

void md5_string(const char *string) {
    unsigned char hash[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)string, strlen(string), hash);
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}


#line 183 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    SINH = 275,                    /* SINH  */
    COSH = 276,                    /* COSH  */
    TANH = 277,                    /* TANH  */
    COTH = 278,                    /* COTH  */
    SECH = 279,                    /* SECH  */
    CSCH = 280,                    /* CSCH  */
    SHA256HASH = 281,              /* SHA256HASH  */
    MD5HASH = 282,                 /* MD5HASH  */
    LOG = 283,                     /* LOG  */
    GT = 284,                      /* GT  */
    LT = 285,                      /* LT  */
    EQ = 286,                      /* EQ  */
    NE = 287,                      /* NE  */
    MOD = 288,                     /* MOD  */
    EOL = 289,                     /* EOL  */
    LPAREN = 290,                  /* LPAREN  */
    RPAREN = 291,                  /* RPAREN  */
    EQUAL = 292,                   /* EQUAL  */
    LBRACE = 293,                  /* LBRACE  */
    RBRACE = 294,                  /* RBRACE  */
    COMMA = 295,                   /* COMMA  */
    PLUS = 296,                    /* PLUS  */
    MINUS = 297,                   /* MINUS  */
    MULTIPLY = 298,                /* MULTIPLY  */
    DIVIDE = 299,                  /* DIVIDE  */
    POWER = 300,                   /* POWER  */
    FACTORIAL = 301                /* FACTORIAL  */
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
#define SINH 275
#define COSH 276
#define TANH 277
#define COTH 278
#define SECH 279
#define CSCH 280
#define SHA256HASH 281
#define MD5HASH 282
#define LOG 283
#define GT 284
#define LT 285
#define EQ 286
#define NE 287
#define MOD 288
#define EOL 289
#define LPAREN 290
#define RPAREN 291
#define EQUAL 292
#define LBRACE 293
#define RBRACE 294
#define COMMA 295
#define PLUS 296
#define MINUS 297
#define MULTIPLY 298
#define DIVIDE 299
#define POWER 300
#define FACTORIAL 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 113 "calc.y"

    double num;
    char *id;

#line 333 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_SIGMA = 5,                      /* SIGMA  */
  YYSYMBOL_PI = 6,                         /* PI  */
  YYSYMBOL_ABS = 7,                        /* ABS  */
  YYSYMBOL_ROOT = 8,                       /* ROOT  */
  YYSYMBOL_PRIMEFACTORS = 9,               /* PRIMEFACTORS  */
  YYSYMBOL_TO_BIN = 10,                    /* TO_BIN  */
  YYSYMBOL_TO_OCT = 11,                    /* TO_OCT  */
  YYSYMBOL_TO_DEC = 12,                    /* TO_DEC  */
  YYSYMBOL_TO_HEX = 13,                    /* TO_HEX  */
  YYSYMBOL_SIN = 14,                       /* SIN  */
  YYSYMBOL_COS = 15,                       /* COS  */
  YYSYMBOL_TAN = 16,                       /* TAN  */
  YYSYMBOL_COT = 17,                       /* COT  */
  YYSYMBOL_SEC = 18,                       /* SEC  */
  YYSYMBOL_CSC = 19,                       /* CSC  */
  YYSYMBOL_SINH = 20,                      /* SINH  */
  YYSYMBOL_COSH = 21,                      /* COSH  */
  YYSYMBOL_TANH = 22,                      /* TANH  */
  YYSYMBOL_COTH = 23,                      /* COTH  */
  YYSYMBOL_SECH = 24,                      /* SECH  */
  YYSYMBOL_CSCH = 25,                      /* CSCH  */
  YYSYMBOL_SHA256HASH = 26,                /* SHA256HASH  */
  YYSYMBOL_MD5HASH = 27,                   /* MD5HASH  */
  YYSYMBOL_LOG = 28,                       /* LOG  */
  YYSYMBOL_GT = 29,                        /* GT  */
  YYSYMBOL_LT = 30,                        /* LT  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_NE = 32,                        /* NE  */
  YYSYMBOL_MOD = 33,                       /* MOD  */
  YYSYMBOL_EOL = 34,                       /* EOL  */
  YYSYMBOL_LPAREN = 35,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 36,                    /* RPAREN  */
  YYSYMBOL_EQUAL = 37,                     /* EQUAL  */
  YYSYMBOL_LBRACE = 38,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 39,                    /* RBRACE  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_PLUS = 41,                      /* PLUS  */
  YYSYMBOL_MINUS = 42,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 43,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 44,                    /* DIVIDE  */
  YYSYMBOL_POWER = 45,                     /* POWER  */
  YYSYMBOL_FACTORIAL = 46,                 /* FACTORIAL  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_input = 48,                     /* input  */
  YYSYMBOL_line = 49,                      /* line  */
  YYSYMBOL_expression = 50,                /* expression  */
  YYSYMBOL_condition = 51                  /* condition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   528

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  5
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   140,   140,   141,   145,   146,   147,   148,   149,   150,
     151,   152,   156,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   197
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIFIER",
  "SIGMA", "PI", "ABS", "ROOT", "PRIMEFACTORS", "TO_BIN", "TO_OCT",
  "TO_DEC", "TO_HEX", "SIN", "COS", "TAN", "COT", "SEC", "CSC", "SINH",
  "COSH", "TANH", "COTH", "SECH", "CSCH", "SHA256HASH", "MD5HASH", "LOG",
  "GT", "LT", "EQ", "NE", "MOD", "EOL", "LPAREN", "RPAREN", "EQUAL",
  "LBRACE", "RBRACE", "COMMA", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "POWER", "FACTORIAL", "$accept", "input", "line", "expression",
  "condition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -34,    40,   -34,   -34,   -33,   -34,   -32,   -31,   -11,   -10,
      -8,    -7,    -1,     6,     7,     9,    34,    35,    36,    37,
      38,    45,    46,    48,    49,    63,    65,    79,    71,    71,
     -34,    78,   126,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,   127,   129,    71,    96,   482,    71,    71,    71,
      71,    71,   -34,    71,    71,    71,    71,    71,   -34,    94,
     114,   132,   150,   168,   186,   204,   222,   240,   258,   276,
     294,   312,   330,   348,   366,   384,   402,   420,   438,    99,
     100,   456,   -34,   -34,   -34,   -34,   -34,   446,    72,    72,
     446,   446,   482,   144,   -34,   -34,   115,   117,   118,   119,
     120,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,   -34,   133,   135,    71,   134,   130,   -34,   -34,
     -34,   -34,   -34,   -34,   -34,   474,   167,   -34,   -34,   -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    41,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,     0,
       0,     0,     4,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,    13,    14,    15,    16,    21,    17,    18,
      19,    20,    22,     0,    24,    23,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,     0,     0,    12,    25,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,   -34,   -28,   -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    30,    31,   127
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,    56,    32,    33,    34,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    35,    36,    91,    37,    38,    93,
      94,    95,    96,    97,    39,    98,    99,   100,   101,   102,
       2,    40,    41,     3,    42,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    43,
      44,    45,    46,    47,     3,    28,     4,     5,     6,     7,
      48,    49,    29,    50,    51,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   135,    52,    27,
      53,    57,    58,    59,    60,    61,    28,    57,    58,    59,
      60,    61,    62,    29,    54,    65,    66,    67,    68,    63,
      64,    65,    66,    67,    68,    57,    58,    59,    60,    61,
      69,    89,    92,    90,   103,   123,   124,    63,    64,    65,
      66,    67,    68,    57,    58,    59,    60,    61,   126,   128,
     104,   129,   130,   131,   132,    63,    64,    65,    66,    67,
      68,    57,    58,    59,    60,    61,   137,   133,   105,   134,
     139,   136,     0,    63,    64,    65,    66,    67,    68,    57,
      58,    59,    60,    61,     0,     0,   106,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    57,    58,    59,
      60,    61,     0,     0,   107,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    57,    58,    59,    60,    61,
       0,     0,   108,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    57,    58,    59,    60,    61,     0,     0,
     109,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    57,    58,    59,    60,    61,     0,     0,   110,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    57,
      58,    59,    60,    61,     0,     0,   111,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    57,    58,    59,
      60,    61,     0,     0,   112,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    57,    58,    59,    60,    61,
       0,     0,   113,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    57,    58,    59,    60,    61,     0,     0,
     114,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    57,    58,    59,    60,    61,     0,     0,   115,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    57,
      58,    59,    60,    61,     0,     0,   116,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    57,    58,    59,
      60,    61,     0,     0,   117,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    57,    58,    59,    60,    61,
       0,     0,   118,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    57,    58,    59,    60,    61,     0,     0,
     119,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    57,    58,    59,    60,    61,     0,     0,   120,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    57,
      58,    59,    60,    61,     0,     0,   121,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    57,    58,    59,
      60,    61,     0,     0,   122,    57,    58,    59,    60,    63,
      64,    65,    66,    67,    68,    57,    58,    59,    60,    61,
       0,    67,    68,     0,     0,     0,   125,    63,    64,    65,
      66,    67,    68,    57,    58,    59,    60,    61,     0,     0,
     138,    57,    58,    59,    60,    63,    64,    65,    66,    67,
      68,     0,     0,     0,     0,     0,     0,     0,    68
};

static const yytype_int8 yycheck[] =
{
      28,    29,    35,    35,    35,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    35,    35,    54,    35,    35,    57,
      58,    59,    60,    61,    35,    63,    64,    65,    66,    67,
       0,    35,    35,     3,    35,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    35,
      35,    35,    35,    35,     3,    35,     5,     6,     7,     8,
      35,    35,    42,    35,    35,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   125,    35,    28,
      35,    29,    30,    31,    32,    33,    35,    29,    30,    31,
      32,    33,    34,    42,    35,    43,    44,    45,    46,    41,
      42,    43,    44,    45,    46,    29,    30,    31,    32,    33,
       4,     4,    36,     4,    40,    36,    36,    41,    42,    43,
      44,    45,    46,    29,    30,    31,    32,    33,     4,    34,
      36,    34,    34,    34,    34,    41,    42,    43,    44,    45,
      46,    29,    30,    31,    32,    33,    36,    34,    36,    34,
       3,    37,    -1,    41,    42,    43,    44,    45,    46,    29,
      30,    31,    32,    33,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    29,    30,    31,
      32,    33,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    29,    30,    31,    32,    33,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    29,    30,    31,    32,    33,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    29,    30,    31,    32,    33,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    29,
      30,    31,    32,    33,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    29,    30,    31,
      32,    33,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    29,    30,    31,    32,    33,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    29,    30,    31,    32,    33,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    29,    30,    31,    32,    33,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    29,
      30,    31,    32,    33,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    29,    30,    31,
      32,    33,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    29,    30,    31,    32,    33,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    29,    30,    31,    32,    33,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    29,    30,    31,    32,    33,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    29,
      30,    31,    32,    33,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    29,    30,    31,
      32,    33,    -1,    -1,    36,    29,    30,    31,    32,    41,
      42,    43,    44,    45,    46,    29,    30,    31,    32,    33,
      -1,    45,    46,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    29,    30,    31,    32,    33,    -1,    -1,
      36,    29,    30,    31,    32,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,     0,     3,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    35,    42,
      49,    50,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    50,    50,    29,    30,    31,
      32,    33,    34,    41,    42,    43,    44,    45,    46,     4,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,     4,
       4,    50,    36,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    40,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    40,     4,    51,    34,    34,
      34,    34,    34,    34,    34,    50,    37,    36,    36,     3
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    49,    49,    49,    49,
      49,    49,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    51
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     5,     5,     5,     5,     5,
       5,     5,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     2,     2,
       3,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* line: expression EOL  */
#line 145 "calc.y"
                   { printf("Result: %g\n", (yyvsp[-1].num)); }
#line 1515 "y.tab.c"
    break;

  case 5: /* line: PRIMEFACTORS LPAREN expression RPAREN EOL  */
#line 146 "calc.y"
                                                { printf("Prime Factors: "); prime_factors((int)(yyvsp[-2].num)); }
#line 1521 "y.tab.c"
    break;

  case 6: /* line: TO_BIN LPAREN expression RPAREN EOL  */
#line 147 "calc.y"
                                          { printf("Binary: "); to_binary((int)(yyvsp[-2].num)); }
#line 1527 "y.tab.c"
    break;

  case 7: /* line: TO_OCT LPAREN expression RPAREN EOL  */
#line 148 "calc.y"
                                          { printf("Octal: "); to_octal((int)(yyvsp[-2].num)); }
#line 1533 "y.tab.c"
    break;

  case 8: /* line: TO_DEC LPAREN expression RPAREN EOL  */
#line 149 "calc.y"
                                          { printf("Decimal: "); to_decimal((int)(yyvsp[-2].num)); }
#line 1539 "y.tab.c"
    break;

  case 9: /* line: TO_HEX LPAREN expression RPAREN EOL  */
#line 150 "calc.y"
                                          { printf("Hexadecimal: "); to_hex((int)(yyvsp[-2].num)); }
#line 1545 "y.tab.c"
    break;

  case 10: /* line: SHA256HASH LPAREN IDENTIFIER RPAREN EOL  */
#line 151 "calc.y"
                                              { printf("SHA256: "); sha256_string((yyvsp[-2].id)); }
#line 1551 "y.tab.c"
    break;

  case 11: /* line: MD5HASH LPAREN IDENTIFIER RPAREN EOL  */
#line 152 "calc.y"
                                           { printf("MD5: "); md5_string((yyvsp[-2].id)); }
#line 1557 "y.tab.c"
    break;

  case 12: /* expression: SIGMA LPAREN IDENTIFIER COMMA condition RPAREN  */
#line 156 "calc.y"
                                                   {
        int var_value = (int)(yyvsp[-1].num);
        double result = 0;
        for (int i = 0; i <= var_value; i++) {
            result += i;
        }
        (yyval.num) = result;
    }
#line 1570 "y.tab.c"
    break;

  case 13: /* expression: expression GT expression  */
#line 164 "calc.y"
                               { (yyval.num) = (yyvsp[-2].num) > (yyvsp[0].num); }
#line 1576 "y.tab.c"
    break;

  case 14: /* expression: expression LT expression  */
#line 165 "calc.y"
                               { (yyval.num) = (yyvsp[-2].num) < (yyvsp[0].num); }
#line 1582 "y.tab.c"
    break;

  case 15: /* expression: expression EQ expression  */
#line 166 "calc.y"
                               { (yyval.num) = (yyvsp[-2].num) == (yyvsp[0].num); }
#line 1588 "y.tab.c"
    break;

  case 16: /* expression: expression NE expression  */
#line 167 "calc.y"
                               { (yyval.num) = (yyvsp[-2].num) != (yyvsp[0].num); }
#line 1594 "y.tab.c"
    break;

  case 17: /* expression: expression PLUS expression  */
#line 168 "calc.y"
                                 { (yyval.num) = (yyvsp[-2].num) + (yyvsp[0].num); }
#line 1600 "y.tab.c"
    break;

  case 18: /* expression: expression MINUS expression  */
#line 169 "calc.y"
                                  { (yyval.num) = (yyvsp[-2].num) - (yyvsp[0].num); }
#line 1606 "y.tab.c"
    break;

  case 19: /* expression: expression MULTIPLY expression  */
#line 170 "calc.y"
                                     { (yyval.num) = (yyvsp[-2].num) * (yyvsp[0].num); }
#line 1612 "y.tab.c"
    break;

  case 20: /* expression: expression DIVIDE expression  */
#line 171 "calc.y"
                                   { (yyval.num) = (yyvsp[-2].num) / (yyvsp[0].num); }
#line 1618 "y.tab.c"
    break;

  case 21: /* expression: expression MOD expression  */
#line 172 "calc.y"
                                { (yyval.num) = fmod((yyvsp[-2].num), (yyvsp[0].num)); }
#line 1624 "y.tab.c"
    break;

  case 22: /* expression: expression POWER expression  */
#line 173 "calc.y"
                                  { (yyval.num) = pow((yyvsp[-2].num), (yyvsp[0].num)); }
#line 1630 "y.tab.c"
    break;

  case 23: /* expression: ROOT LPAREN expression RPAREN  */
#line 174 "calc.y"
                                    { (yyval.num) = sqrt((yyvsp[-1].num)); }
#line 1636 "y.tab.c"
    break;

  case 24: /* expression: ABS LPAREN expression RPAREN  */
#line 175 "calc.y"
                                   { (yyval.num) = fabs((yyvsp[-1].num)); }
#line 1642 "y.tab.c"
    break;

  case 25: /* expression: LOG LPAREN expression COMMA expression RPAREN  */
#line 176 "calc.y"
                                                    { (yyval.num) = log((yyvsp[-3].num)) / log((yyvsp[-1].num)); }
#line 1648 "y.tab.c"
    break;

  case 26: /* expression: SIN LPAREN expression RPAREN  */
#line 177 "calc.y"
                                   { (yyval.num) = sin((yyvsp[-1].num)); }
#line 1654 "y.tab.c"
    break;

  case 27: /* expression: COS LPAREN expression RPAREN  */
#line 178 "calc.y"
                                   { (yyval.num) = cos((yyvsp[-1].num)); }
#line 1660 "y.tab.c"
    break;

  case 28: /* expression: TAN LPAREN expression RPAREN  */
#line 179 "calc.y"
                                   { (yyval.num) = tan((yyvsp[-1].num)); }
#line 1666 "y.tab.c"
    break;

  case 29: /* expression: COT LPAREN expression RPAREN  */
#line 180 "calc.y"
                                   { (yyval.num) = 1/tan((yyvsp[-1].num)); }
#line 1672 "y.tab.c"
    break;

  case 30: /* expression: SEC LPAREN expression RPAREN  */
#line 181 "calc.y"
                                   { (yyval.num) = 1/cos((yyvsp[-1].num)); }
#line 1678 "y.tab.c"
    break;

  case 31: /* expression: CSC LPAREN expression RPAREN  */
#line 182 "calc.y"
                                   { (yyval.num) = 1/sin((yyvsp[-1].num)); }
#line 1684 "y.tab.c"
    break;

  case 32: /* expression: SINH LPAREN expression RPAREN  */
#line 183 "calc.y"
                                    { (yyval.num) = sinh((yyvsp[-1].num)); }
#line 1690 "y.tab.c"
    break;

  case 33: /* expression: COSH LPAREN expression RPAREN  */
#line 184 "calc.y"
                                    { (yyval.num) = cosh((yyvsp[-1].num)); }
#line 1696 "y.tab.c"
    break;

  case 34: /* expression: TANH LPAREN expression RPAREN  */
#line 185 "calc.y"
                                    { (yyval.num) = tanh((yyvsp[-1].num)); }
#line 1702 "y.tab.c"
    break;

  case 35: /* expression: COTH LPAREN expression RPAREN  */
#line 186 "calc.y"
                                    { (yyval.num) = 1/tanh((yyvsp[-1].num)); }
#line 1708 "y.tab.c"
    break;

  case 36: /* expression: SECH LPAREN expression RPAREN  */
#line 187 "calc.y"
                                    { (yyval.num) = 1/cosh((yyvsp[-1].num)); }
#line 1714 "y.tab.c"
    break;

  case 37: /* expression: CSCH LPAREN expression RPAREN  */
#line 188 "calc.y"
                                    { (yyval.num) = 1/sinh((yyvsp[-1].num)); }
#line 1720 "y.tab.c"
    break;

  case 38: /* expression: expression FACTORIAL  */
#line 189 "calc.y"
                           { (yyval.num) = factorial((yyvsp[-1].num)); }
#line 1726 "y.tab.c"
    break;

  case 39: /* expression: MINUS expression  */
#line 190 "calc.y"
                                   { (yyval.num) = -(yyvsp[0].num); }
#line 1732 "y.tab.c"
    break;

  case 40: /* expression: LPAREN expression RPAREN  */
#line 191 "calc.y"
                               { (yyval.num) = (yyvsp[-1].num); }
#line 1738 "y.tab.c"
    break;

  case 41: /* expression: NUMBER  */
#line 192 "calc.y"
             { (yyval.num) = (yyvsp[0].num); }
#line 1744 "y.tab.c"
    break;

  case 42: /* expression: PI  */
#line 193 "calc.y"
         { (yyval.num) = M_PI; }
#line 1750 "y.tab.c"
    break;

  case 43: /* condition: IDENTIFIER EQUAL NUMBER  */
#line 197 "calc.y"
                            { (yyval.num) = (yyvsp[0].num); }
#line 1756 "y.tab.c"
    break;


#line 1760 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 200 "calc.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}
