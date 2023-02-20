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
#line 1 "1905065.y"

 #include "1905065_ICGfunc.h"

void preOrder(SymbolInfo* root,int depth){
    for(int i=0;i<depth;i++)parseout<<' ';
    
    if(root->isLeaf){
        parseout<<root->type<<" : "<<root->name<<"\t<Line: ";
        parseout<<to_string(root->startLine)<<">\n";
    }
    else{
        parseout<<root->name <<" \t<Line: ";
        parseout<<to_string(root->startLine)<<"-"<<to_string(root->endLine)<<">\n";
        if(root->child!=NULL){
            SymbolInfo* curr= root->child;
            while(curr!=NULL){
                preOrder(curr, depth+1);
                curr=curr->next;
            }
        }
    }
}
void printParseTree(){
    preOrder(startSi,0);
}


#line 99 "y.tab.c"

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
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    WHILE = 261,                   /* WHILE  */
    DO = 262,                      /* DO  */
    BREAK = 263,                   /* BREAK  */
    INT = 264,                     /* INT  */
    CHAR = 265,                    /* CHAR  */
    FLOAT = 266,                   /* FLOAT  */
    DOUBLE = 267,                  /* DOUBLE  */
    VOID = 268,                    /* VOID  */
    RETURN = 269,                  /* RETURN  */
    SWITCH = 270,                  /* SWITCH  */
    CASE = 271,                    /* CASE  */
    DEFAULT = 272,                 /* DEFAULT  */
    CONTINUE = 273,                /* CONTINUE  */
    CONST_INT = 274,               /* CONST_INT  */
    CONST_FLOAT = 275,             /* CONST_FLOAT  */
    SEMICOLON = 276,               /* SEMICOLON  */
    CONST_CHAR = 277,              /* CONST_CHAR  */
    ADDOP = 278,                   /* ADDOP  */
    MULOP = 279,                   /* MULOP  */
    INCOP = 280,                   /* INCOP  */
    DECOP = 281,                   /* DECOP  */
    ASSIGNOP = 282,                /* ASSIGNOP  */
    RELOP = 283,                   /* RELOP  */
    BITOP = 284,                   /* BITOP  */
    LOGICOP = 285,                 /* LOGICOP  */
    NOT = 286,                     /* NOT  */
    LPAREN = 287,                  /* LPAREN  */
    RPAREN = 288,                  /* RPAREN  */
    LSQUARE = 289,                 /* LSQUARE  */
    RSQUARE = 290,                 /* RSQUARE  */
    LCURL = 291,                   /* LCURL  */
    RCURL = 292,                   /* RCURL  */
    COMMA = 293,                   /* COMMA  */
    ID = 294,                      /* ID  */
    SINGLE_LINE_STRING = 295,      /* SINGLE_LINE_STRING  */
    MULTILINE_STRING = 296,        /* MULTILINE_STRING  */
    PRINTLN = 297,                 /* PRINTLN  */
    LOWER_THAN_ELSE = 298          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define INT 264
#define CHAR 265
#define FLOAT 266
#define DOUBLE 267
#define VOID 268
#define RETURN 269
#define SWITCH 270
#define CASE 271
#define DEFAULT 272
#define CONTINUE 273
#define CONST_INT 274
#define CONST_FLOAT 275
#define SEMICOLON 276
#define CONST_CHAR 277
#define ADDOP 278
#define MULOP 279
#define INCOP 280
#define DECOP 281
#define ASSIGNOP 282
#define RELOP 283
#define BITOP 284
#define LOGICOP 285
#define NOT 286
#define LPAREN 287
#define RPAREN 288
#define LSQUARE 289
#define RSQUARE 290
#define LCURL 291
#define RCURL 292
#define COMMA 293
#define ID 294
#define SINGLE_LINE_STRING 295
#define MULTILINE_STRING 296
#define PRINTLN 297
#define LOWER_THAN_ELSE 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "1905065.y"

    SymbolInfo* si   ;

#line 242 "y.tab.c"

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
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_DO = 7,                         /* DO  */
  YYSYMBOL_BREAK = 8,                      /* BREAK  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_FLOAT = 11,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 12,                    /* DOUBLE  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_SWITCH = 15,                    /* SWITCH  */
  YYSYMBOL_CASE = 16,                      /* CASE  */
  YYSYMBOL_DEFAULT = 17,                   /* DEFAULT  */
  YYSYMBOL_CONTINUE = 18,                  /* CONTINUE  */
  YYSYMBOL_CONST_INT = 19,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 20,               /* CONST_FLOAT  */
  YYSYMBOL_SEMICOLON = 21,                 /* SEMICOLON  */
  YYSYMBOL_CONST_CHAR = 22,                /* CONST_CHAR  */
  YYSYMBOL_ADDOP = 23,                     /* ADDOP  */
  YYSYMBOL_MULOP = 24,                     /* MULOP  */
  YYSYMBOL_INCOP = 25,                     /* INCOP  */
  YYSYMBOL_DECOP = 26,                     /* DECOP  */
  YYSYMBOL_ASSIGNOP = 27,                  /* ASSIGNOP  */
  YYSYMBOL_RELOP = 28,                     /* RELOP  */
  YYSYMBOL_BITOP = 29,                     /* BITOP  */
  YYSYMBOL_LOGICOP = 30,                   /* LOGICOP  */
  YYSYMBOL_NOT = 31,                       /* NOT  */
  YYSYMBOL_LPAREN = 32,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 33,                    /* RPAREN  */
  YYSYMBOL_LSQUARE = 34,                   /* LSQUARE  */
  YYSYMBOL_RSQUARE = 35,                   /* RSQUARE  */
  YYSYMBOL_LCURL = 36,                     /* LCURL  */
  YYSYMBOL_RCURL = 37,                     /* RCURL  */
  YYSYMBOL_COMMA = 38,                     /* COMMA  */
  YYSYMBOL_ID = 39,                        /* ID  */
  YYSYMBOL_SINGLE_LINE_STRING = 40,        /* SINGLE_LINE_STRING  */
  YYSYMBOL_MULTILINE_STRING = 41,          /* MULTILINE_STRING  */
  YYSYMBOL_PRINTLN = 42,                   /* PRINTLN  */
  YYSYMBOL_LOWER_THAN_ELSE = 43,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_start = 45,                     /* start  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_unit = 48,                      /* unit  */
  YYSYMBOL_func_declaration = 49,          /* func_declaration  */
  YYSYMBOL_before_params = 50,             /* before_params  */
  YYSYMBOL_func_definition = 51,           /* func_definition  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_parameter_list = 54,            /* parameter_list  */
  YYSYMBOL_compound_statement = 55,        /* compound_statement  */
  YYSYMBOL_before_stats = 56,              /* before_stats  */
  YYSYMBOL_var_declaration = 57,           /* var_declaration  */
  YYSYMBOL_type_specifier = 58,            /* type_specifier  */
  YYSYMBOL_declaration_list = 59,          /* declaration_list  */
  YYSYMBOL_statements = 60,                /* statements  */
  YYSYMBOL_statement = 61,                 /* statement  */
  YYSYMBOL_62_4 = 62,                      /* $@4  */
  YYSYMBOL_63_5 = 63,                      /* $@5  */
  YYSYMBOL_64_6 = 64,                      /* $@6  */
  YYSYMBOL_65_7 = 65,                      /* $@7  */
  YYSYMBOL_66_8 = 66,                      /* $@8  */
  YYSYMBOL_67_9 = 67,                      /* $@9  */
  YYSYMBOL_68_10 = 68,                     /* $@10  */
  YYSYMBOL_if_common_part = 69,            /* if_common_part  */
  YYSYMBOL_70_11 = 70,                     /* $@11  */
  YYSYMBOL_exp_void_func = 71,             /* exp_void_func  */
  YYSYMBOL_expression_statement = 72,      /* expression_statement  */
  YYSYMBOL_variable = 73,                  /* variable  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_logic_expression = 75,          /* logic_expression  */
  YYSYMBOL_76_12 = 76,                     /* $@12  */
  YYSYMBOL_rel_expression = 77,            /* rel_expression  */
  YYSYMBOL_simple_expression = 78,         /* simple_expression  */
  YYSYMBOL_error_rr = 79,                  /* error_rr  */
  YYSYMBOL_mulop = 80,                     /* mulop  */
  YYSYMBOL_term = 81,                      /* term  */
  YYSYMBOL_unary_expression = 82,          /* unary_expression  */
  YYSYMBOL_factor = 83,                    /* factor  */
  YYSYMBOL_argument_list = 84,             /* argument_list  */
  YYSYMBOL_arguments = 85                  /* arguments  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   224

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    41,    41,    41,    50,    55,    62,    68,    74,    81,
     126,   149,   154,   154,   168,   168,   185,   195,   204,   211,
     218,   229,   238,   248,   329,   354,   363,   368,   374,   381,
     390,   402,   410,   422,   432,   437,   444,   449,   455,   460,
     462,   470,   477,   460,   499,   506,   506,   520,   525,   520,
     542,   557,   566,   566,   585,   592,   598,   605,   615,   641,
     692,   702,   737,   743,   743,   782,   788,   826,   832,   861,
     867,   873,   878,   884,   926,   942,   964,   970,   979,  1045,
    1059,  1068,  1077,  1088,  1100,  1107,  1115,  1122
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "WHILE", "DO", "BREAK", "INT", "CHAR", "FLOAT", "DOUBLE", "VOID",
  "RETURN", "SWITCH", "CASE", "DEFAULT", "CONTINUE", "CONST_INT",
  "CONST_FLOAT", "SEMICOLON", "CONST_CHAR", "ADDOP", "MULOP", "INCOP",
  "DECOP", "ASSIGNOP", "RELOP", "BITOP", "LOGICOP", "NOT", "LPAREN",
  "RPAREN", "LSQUARE", "RSQUARE", "LCURL", "RCURL", "COMMA", "ID",
  "SINGLE_LINE_STRING", "MULTILINE_STRING", "PRINTLN", "LOWER_THAN_ELSE",
  "$accept", "start", "$@1", "program", "unit", "func_declaration",
  "before_params", "func_definition", "$@2", "$@3", "parameter_list",
  "compound_statement", "before_stats", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement", "$@4",
  "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "if_common_part", "$@11",
  "exp_void_func", "expression_statement", "variable", "expression",
  "logic_expression", "$@12", "rel_expression", "simple_expression",
  "error_rr", "mulop", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-99)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-86)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -99,    17,    93,   -99,    39,   -99,   -99,   -99,    62,   -99,
     -99,   -99,   -99,   -19,   -99,   -99,    36,     4,    15,     9,
     -99,   -99,    25,    45,     5,    51,   -99,    65,    -1,    28,
      69,   -99,    57,    74,    94,   -99,   -99,    61,   -99,   -99,
     -99,    57,    77,   -99,    78,   -99,   -99,    39,    68,   -99,
      76,   179,   -99,   -99,   -99,   185,   185,   179,   -99,    42,
      90,   -99,   -99,    79,   118,   -99,   121,   -99,    86,    10,
     -99,    96,    12,   109,   106,   -99,   -99,   179,   101,   -99,
     -99,   -99,    -2,   -99,   -99,   102,    26,   179,    95,   108,
     -99,   -99,   -99,   -99,   -99,   179,   -99,   -99,   -99,   185,
     179,   -99,   -99,   185,   -99,   164,   179,   115,   -99,   -99,
     107,   105,   110,   111,   158,   -99,   179,   106,   123,   -99,
     114,   -99,   -99,   -99,   -99,   179,   -99,   127,   -99,   -99,
     -99,   164,   119,   -99,   -99,   158,   -99,   -99,   -99,   -99,
     158,   179,   -99,   -99,   120,   158,   -99
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,    26,    27,    28,     0,     5,
       7,     8,     6,     0,    25,     4,    31,     0,     0,     0,
      33,    24,     0,     0,     0,    29,    32,    14,     0,     0,
       0,    10,     0,    12,     0,    20,    18,     0,    23,    15,
       9,     0,    17,    30,     0,    13,    16,    70,     0,    39,
       0,     0,    80,    81,    55,     0,     0,     0,    22,    58,
       0,    38,    36,     0,     0,    34,    44,    37,    77,     0,
      60,    62,    65,     0,    67,    72,    76,     0,     0,    47,
      70,    54,    77,    74,    75,     0,     0,     0,     0,    31,
      21,    35,    45,    82,    83,     0,    57,    56,    63,     0,
       0,    69,    71,     0,    54,     0,     0,     0,    79,    87,
       0,    84,     0,     0,     0,    61,     0,    68,    66,    73,
       0,    40,    54,    51,    78,     0,    59,     0,    46,    64,
      52,     0,     0,    86,    50,     0,    41,    48,    53,    54,
       0,     0,    49,    42,     0,     0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   -99,   143,   -99,   -99,   -99,   -99,   -99,
     -99,   -22,   -99,    13,    20,   -99,   -99,   -63,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -92,   -98,   -47,
     -51,   -82,   -99,    40,    58,   -99,   -99,    63,   -53,   -99,
     -99,   -99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     8,     9,    10,    19,    11,    41,    32,
      28,    61,    44,    62,    63,    17,    64,    65,    78,   131,
     139,   144,   114,   106,   140,    66,   135,   107,    67,    68,
      69,    70,   116,    71,    72,    73,   103,    74,    75,    76,
     110,   111
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    91,    83,    84,   109,    20,    85,   121,    82,    82,
      39,    96,   120,   115,     5,    12,     6,     3,     7,    45,
      16,    12,    13,    93,    94,    21,   104,    80,    13,    35,
     132,    97,    33,   136,    23,    99,   112,    34,    27,    82,
     100,    24,    22,   133,    29,    52,    53,   141,    82,    55,
     119,   128,    82,    82,    42,   122,    82,    56,    57,   -85,
      14,   -19,    -3,     4,    25,    59,   -19,    36,   -11,    82,
      18,     5,   138,     6,    86,     7,    87,   142,    82,    47,
      26,    48,   146,    49,    50,    30,    31,     5,    37,     6,
     143,     7,    51,    38,     4,    40,    43,    52,    53,    54,
      77,    55,     5,     5,     6,     6,     7,     7,    79,    56,
      57,    93,    94,    95,    38,    58,    46,    59,    89,    47,
      60,    48,    88,    49,    50,    92,    98,     5,   101,     6,
     102,     7,    51,   105,   113,   108,   123,    52,    53,    54,
     124,    55,    18,   125,   127,   126,    99,   130,   134,    56,
      57,    15,   137,   145,    38,    90,   129,    59,   118,    47,
      60,    48,   117,    49,    50,    80,     0,     5,     0,     6,
       0,     7,    51,     0,     0,     0,     0,    52,    53,    54,
      80,    55,     0,    52,    53,    54,     0,    55,     0,    56,
      57,     0,     0,     0,    38,    56,    57,    59,    52,    53,
      60,     0,    55,    59,    52,    53,     0,     0,    55,     0,
      56,    57,     0,     0,     0,     0,    56,    57,    59,     0,
       0,     0,     0,     0,    59
};

static const yytype_int16 yycheck[] =
{
      51,    64,    55,    56,    86,     1,    57,   105,    55,    56,
      32,     1,   104,    95,     9,     2,    11,     0,    13,    41,
      39,     8,     2,    25,    26,    21,    77,     1,     8,     1,
     122,    21,    33,   131,    19,    23,    87,    38,    33,    86,
      28,    32,    38,   125,    24,    19,    20,   139,    95,    23,
     103,   114,    99,   100,    34,   106,   103,    31,    32,    33,
      21,    33,     0,     1,    39,    39,    38,    39,    32,   116,
      34,     9,   135,    11,    32,    13,    34,   140,   125,     1,
      35,     3,   145,     5,     6,    34,    21,     9,    19,    11,
     141,    13,    14,    36,     1,    21,    35,    19,    20,    21,
      32,    23,     9,     9,    11,    11,    13,    13,    32,    31,
      32,    25,    26,    27,    36,    37,    39,    39,    39,     1,
      42,     3,    32,     5,     6,     4,    30,     9,    19,    11,
      24,    13,    14,    32,    39,    33,    21,    19,    20,    21,
      33,    23,    34,    38,    33,    35,    23,    33,    21,    31,
      32,     8,    33,    33,    36,    37,   116,    39,   100,     1,
      42,     3,    99,     5,     6,     1,    -1,     9,    -1,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    19,    20,    21,
       1,    23,    -1,    19,    20,    21,    -1,    23,    -1,    31,
      32,    -1,    -1,    -1,    36,    31,    32,    39,    19,    20,
      42,    -1,    23,    39,    19,    20,    -1,    -1,    23,    -1,
      31,    32,    -1,    -1,    -1,    -1,    31,    32,    39,    -1,
      -1,    -1,    -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    46,     0,     1,     9,    11,    13,    47,    48,
      49,    51,    57,    58,    21,    48,    39,    59,    34,    50,
       1,    21,    38,    19,    32,    39,    35,    33,    54,    58,
      34,    21,    53,    33,    38,     1,    39,    19,    36,    55,
      21,    52,    58,    35,    56,    55,    39,     1,     3,     5,
       6,    14,    19,    20,    21,    23,    31,    32,    37,    39,
      42,    55,    57,    58,    60,    61,    69,    72,    73,    74,
      75,    77,    78,    79,    81,    82,    83,    32,    62,    32,
       1,    74,    73,    82,    82,    74,    32,    34,    32,    39,
      37,    61,     4,    25,    26,    27,     1,    21,    30,    23,
      28,    19,    24,    80,    74,    32,    67,    71,    33,    75,
      84,    85,    74,    39,    66,    75,    76,    81,    78,    82,
      71,    72,    74,    21,    33,    38,    35,    33,    61,    77,
      33,    63,    71,    75,    21,    70,    72,    33,    61,    64,
      68,    71,    61,    74,    65,    33,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    46,    45,    47,    47,    48,    48,    48,    49,
      49,    50,    52,    51,    53,    51,    54,    54,    54,    54,
      54,    55,    55,    56,    57,    57,    58,    58,    58,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    61,    62,
      63,    64,    65,    61,    61,    66,    61,    67,    68,    61,
      61,    61,    70,    69,    71,    72,    72,    72,    73,    73,
      74,    74,    75,    76,    75,    77,    77,    78,    78,    78,
      79,    80,    81,    81,    82,    82,    82,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    85,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     1,     1,     7,
       6,     0,     0,     8,     0,     7,     4,     3,     2,     1,
       2,     4,     3,     0,     3,     2,     1,     1,     1,     3,
       6,     1,     4,     2,     1,     2,     1,     1,     1,     0,
       0,     0,     0,    12,     1,     0,     4,     0,     0,     8,
       5,     4,     0,     7,     0,     1,     2,     2,     1,     4,
       1,     3,     1,     0,     4,     1,     3,     1,     3,     2,
       1,     1,     1,     3,     2,     2,     1,     1,     4,     3,
       1,     1,     2,     2,     1,     0,     3,     1
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
  case 2: /* $@1: %empty  */
#line 41 "1905065.y"
      {
    header();
}
#line 1430 "y.tab.c"
    break;

  case 3: /* start: $@1 program  */
#line 43 "1905065.y"
          {
         (yyval.si) = new SymbolInfo( rulePrint("start","program"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);   
        startSi=(yyval.si);
        (yyval.si)->child=(yyvsp[0].si);
        finishing();
}
#line 1441 "y.tab.c"
    break;

  case 4: /* program: program unit  */
#line 50 "1905065.y"
                     {
        (yyval.si) = new SymbolInfo( rulePrint("program","program unit"),(yyvsp[-1].si)->dataType, (yyvsp[-1].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-1].si);
        (yyvsp[-1].si)->next=(yyvsp[0].si);
}
#line 1451 "y.tab.c"
    break;

  case 5: /* program: unit  */
#line 55 "1905065.y"
          {
        (yyval.si) = new SymbolInfo( rulePrint("program","unit"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);      
        (yyval.si)->child=(yyvsp[0].si);
 
    }
#line 1461 "y.tab.c"
    break;

  case 6: /* unit: var_declaration  */
#line 62 "1905065.y"
                     {
    (yyval.si) = new SymbolInfo( rulePrint("unit","var_declaration"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[0].si);

    
}
#line 1472 "y.tab.c"
    break;

  case 7: /* unit: func_declaration  */
#line 68 "1905065.y"
                      {
    (yyval.si) = new SymbolInfo( rulePrint("unit","func_declaration"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine); 
    (yyval.si)->child=(yyvsp[0].si);
   
    
    }
#line 1483 "y.tab.c"
    break;

  case 8: /* unit: func_definition  */
#line 74 "1905065.y"
                     {
     (yyval.si) = new SymbolInfo( rulePrint("unit","func_definition"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);    
    (yyval.si)->child=(yyvsp[0].si);

    }
#line 1493 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID before_params LPAREN parameter_list RPAREN SEMICOLON  */
#line 81 "1905065.y"
                                                                                         {
    (yyval.si) = new SymbolInfo( rulePrint("func_declaration","type_specifier ID LPAREN parameter_list RPAREN SEMICOLON"),(yyvsp[-6].si)->dataType, (yyvsp[-6].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[-6].si);
    (yyvsp[-6].si)->next=(yyvsp[-5].si);
    (yyvsp[-5].si)->next= (yyvsp[-3].si);
   
    (yyvsp[-3].si)->next=(yyvsp[-2].si);
    (yyvsp[-2].si)->next=(yyvsp[-1].si);
    (yyvsp[-1].si)->next=(yyvsp[0].si);
    SymbolInfo syminf(funcName,funcType);
    syminf.isFunc=true;
    syminf.paramTypeList= getStrfromSi(params);
    if(!err_def_func){
    if(!st.insert(syminf)){
        err_cnt++;
        errorPrint(" multiple declaration of "+funcName);
    }
    err_def_func=0;
    }
    if(params.size()==1 && params[0].getType()=="VOID"){
        syminf.paramTypeList.clear();
        /* only parameter is void */
    }
    else{
        st.enterScope();

            for(int i=0;i<params.size();i++){
                
            if(params[i].getType()=="VOID"){
                err_cnt++;
                errorPrint("Parameter '"+params[i].getName()+"' declared void");
            }
            bool success = st.insert(params[i]);
            if(!success) {
                err_cnt++;
                errorPrint("Conflicting types for'"+params[i].getName()+"'");
            }
            
        }
        st.exitScope();
        st.max_scope_id--;
    }
    funcType="";
    params.clear();
}
#line 1543 "y.tab.c"
    break;

  case 10: /* func_declaration: type_specifier ID before_params LPAREN RPAREN SEMICOLON  */
#line 126 "1905065.y"
                                                             {
        (yyval.si) = new SymbolInfo( rulePrint("func_declaration","type_specifier ID LPAREN RPAREN SEMICOLON"),(yyvsp[-5].si)->dataType, (yyvsp[-5].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-5].si);
        (yyvsp[-5].si)->next=(yyvsp[-4].si);
        (yyvsp[-4].si)->next= (yyvsp[-2].si);
        
        (yyvsp[-2].si)->next=(yyvsp[-1].si);
        (yyvsp[-1].si)->next=(yyvsp[0].si);
        
        SymbolInfo syminf(funcName,funcType);
        syminf.isFunc=true;
        syminf.paramTypeList= getStrfromSi(params);
        if(!err_def_func){
        if(!st.insert(syminf)){
            err_cnt++;
            errorPrint(" multiple declaration of "+funcName);
        }
        err_def_func=0;
        }
        funcType="";
        params.clear();
    }
#line 1570 "y.tab.c"
    break;

  case 11: /* before_params: %empty  */
#line 149 "1905065.y"
               {
    
    funcName=idName;
    funcType=idType;    
}
#line 1580 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 154 "1905065.y"
                                                                             {
    codeFuncBegin((yyvsp[-4].si)->getName());
}
#line 1588 "y.tab.c"
    break;

  case 13: /* func_definition: type_specifier ID before_params LPAREN parameter_list RPAREN $@2 compound_statement  */
#line 156 "1905065.y"
                    {
        (yyval.si) = new SymbolInfo( rulePrint("func_definition", "type_specifier ID LPAREN parameter_list RPAREN compound_statement"),(yyvsp[-7].si)->dataType, (yyvsp[-7].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-7].si);
        (yyvsp[-7].si)->next=(yyvsp[-6].si);
        (yyvsp[-6].si)->next= (yyvsp[-4].si);
        
        (yyvsp[-4].si)->next=(yyvsp[-3].si);
        (yyvsp[-3].si)->next=(yyvsp[-2].si);
        (yyvsp[-2].si)->next=(yyvsp[0].si);
        err_def_func=0;
        codeFuncEnd((yyvsp[-6].si)->getName());
}
#line 1605 "y.tab.c"
    break;

  case 14: /* $@3: %empty  */
#line 168 "1905065.y"
                                                   {
    codeFuncBegin((yyvsp[-3].si)->getName());
   }
#line 1613 "y.tab.c"
    break;

  case 15: /* func_definition: type_specifier ID before_params LPAREN RPAREN $@3 compound_statement  */
#line 170 "1905065.y"
                       {
    (yyval.si) = new SymbolInfo( rulePrint("func_definition", "type_specifier ID LPAREN RPAREN compound_statement"),(yyvsp[-6].si)->dataType, (yyvsp[-6].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[-6].si);
    (yyvsp[-6].si)->next=(yyvsp[-5].si);
        (yyvsp[-5].si)->next= (yyvsp[-3].si);
    
        (yyvsp[-3].si)->next=(yyvsp[-2].si);
        (yyvsp[-2].si)->next=(yyvsp[0].si);
        
        err_def_func=0;
    err_def_func=0;
    codeFuncEnd((yyvsp[-5].si)->getName());
   }
#line 1631 "y.tab.c"
    break;

  case 16: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 185 "1905065.y"
                                                      {
        params.push_back( SymbolInfo((yyvsp[0].si)->getName(),(yyvsp[-1].si)->getType(), (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine));
    (yyval.si) = new SymbolInfo( rulePrint("parameter_list","parameter_list COMMA type_specifier ID"),(yyvsp[-3].si)->dataType, (yyvsp[-3].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[-3].si);
    (yyvsp[-3].si)->next=(yyvsp[-2].si);
    (yyvsp[-2].si)->next= (yyvsp[-1].si);
    (yyvsp[-1].si)->next=(yyvsp[0].si);

    err_def_func=0;
}
#line 1646 "y.tab.c"
    break;

  case 17: /* parameter_list: parameter_list COMMA type_specifier  */
#line 195 "1905065.y"
                                         {
        
        params.push_back( SymbolInfo("",(yyvsp[0].si)->getType(), (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine));
        (yyval.si) = new SymbolInfo( rulePrint("parameter_list","parameter_list COMMA type_specifier"),(yyvsp[-2].si)->dataType, (yyvsp[-2].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-2].si);
        (yyvsp[-2].si)->next=(yyvsp[-1].si);
        (yyvsp[-1].si)->next= (yyvsp[0].si);
        
    }
#line 1660 "y.tab.c"
    break;

  case 18: /* parameter_list: type_specifier ID  */
#line 204 "1905065.y"
                       {
        params.clear();
        params.push_back( SymbolInfo((yyvsp[0].si)->getName(),(yyvsp[-1].si)->getType(), (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine));
        (yyval.si) = new SymbolInfo( rulePrint("parameter_list","type_specifier ID"),(yyvsp[-1].si)->dataType, (yyvsp[-1].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-1].si);
        (yyvsp[-1].si)->next=(yyvsp[0].si);
    }
#line 1672 "y.tab.c"
    break;

  case 19: /* parameter_list: type_specifier  */
#line 211 "1905065.y"
                    {
        params.clear();
        params.push_back( SymbolInfo("",(yyvsp[0].si)->getType(), (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine));
        (yyval.si) = new SymbolInfo( rulePrint("parameter_list","type_specifier"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[0].si);

    }
#line 1684 "y.tab.c"
    break;

  case 20: /* parameter_list: type_specifier error  */
#line 218 "1905065.y"
                            {
        yyclearin;
        yyerrok;
        (yyval.si) = new SymbolInfo( rulePrint("parameter_list","type_specifier ID"),"error", (yyvsp[-1].si)->startLine, (yyvsp[-1].si)->endLine);
        (yyval.si)->child=(yyvsp[-1].si);
        
        logout<<"Error at line no "+to_string(line_cnt-multi_line)+" : syntax error"<<'\n';
        err_def_func=1;
    }
#line 1698 "y.tab.c"
    break;

  case 21: /* compound_statement: LCURL before_stats statements RCURL  */
#line 229 "1905065.y"
                                                       {
    (yyval.si) = new SymbolInfo( rulePrint("compound_statement", "LCURL statements RCURL"),(yyvsp[-1].si)->dataType, (yyvsp[-3].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[-3].si);
    (yyvsp[-3].si)->next=(yyvsp[-1].si);
    (yyvsp[-1].si)->next= (yyvsp[0].si);   
    st.printAllScopeTables(logout);
    st.exitScope();
    
}
#line 1712 "y.tab.c"
    break;

  case 22: /* compound_statement: LCURL before_stats RCURL  */
#line 238 "1905065.y"
                              {
        (yyval.si) = new SymbolInfo( rulePrint("compound_statement", "LCURL RCURL"),"INT", (yyvsp[-2].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-2].si);
        (yyvsp[-2].si)->next=(yyvsp[0].si);
        st.printAllScopeTables(logout);
        st.exitScope();
        if(st.getCurrentScopeId()==1)
            globalSc=true;
    }
#line 1726 "y.tab.c"
    break;

  case 23: /* before_stats: %empty  */
#line 248 "1905065.y"
              {
    if(st.getCurrentScopeId()==1)
        {
            globalSc=false;
            offset=0;
        }
    if(funcType!=""){
        SymbolInfo syminf(funcName,funcType);
    syminf.isFunc=true;
    syminf.isFuncDefined=true;
    syminf.paramTypeList= getStrfromSi(params);
    SymbolInfo* temp= st.lookup(syminf.getName());
    if(temp!=NULL){
        bool err=0;
        if(!temp->isFunc){
            err=1;
            errorPrint("'"+funcName+"' redeclared as different kind of symbol");
        }
        else if(temp->isFuncDefined) {
            err=1;
            errorPrint(funcName+" already defined");
        }
        else if(funcType!=temp->type) {
            err=1;
            errorPrint("Conflicting types for '"+funcName+"'");
        }
        else if(temp->paramTypeList.size()!=syminf.paramTypeList.size()){
            err=1;
            errorPrint("Conflicting types for '"+funcName+"'");
        }
        else if(temp->paramTypeList.size()==1 && temp->paramTypeList[0]=="VOID" && syminf.paramTypeList.size()!=0){
            err=1;
            errorPrint(" multiple declaration of "+funcName+" (Parameters does not match)");
        }
        temp->isFuncDefined=true;
        int sz=syminf.paramTypeList.size();
        for(int i=0;!err && i<sz;i++)
            if(temp->paramTypeList[i]!=syminf.paramTypeList[i])
                err=1;
        if(err){
            err_cnt++;
        }
    }
    else{
        if(!err_def_func){
        st.insert(syminf);
        
        }
    }
    st.enterScope();
    if(params.size()==1 && params[0].getType()=="VOID"){
        /* only parameter is void */
    }
    else{
    

            for(int i=0;i<params.size();i++){
                
            if(params[i].getType()=="VOID"){
                err_cnt++;
                errorPrint("Parameter '"+params[i].getName()+"' declared void");
            }
            params[i].isParam=true;
            params[i].offset=4+(params.size()-i)*2;
            bool success = st.insert(params[i]);
            if(!success) {
                err_cnt++;
                errorPrint("Redefinition of parameter '"+params[i].getName()+"'");
            }
            
        }
        
    }
    funcType="";
    params.clear();
    
    }
    else {
        st.enterScope();
    }
}
#line 1812 "y.tab.c"
    break;

  case 24: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 329 "1905065.y"
                                                          {

    (yyval.si) = new SymbolInfo( rulePrint("var_declaration","type_specifier declaration_list SEMICOLON"),(yyvsp[-2].si)->dataType, (yyvsp[-2].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[-2].si);
    (yyvsp[-2].si)->next=(yyvsp[-1].si);
(yyvsp[-1].si)->next= (yyvsp[0].si);
    if((yyvsp[-2].si)->getType()=="VOID")
        {   
            err_cnt++;
            errorPrint("Variable or field '"+vars[0].getName()+"' declared void");
        }   
    else{
        for(int i=0;i<vars.size();i++){
            
            vars[i].setType((yyvsp[-2].si)->getType());
        if(st.getCurrentScopeId()==1) vars[i].isGlobal=1;
        bool success = st.insert(vars[i]);
		if(!success){
            err_cnt++;
            errorPrint("Conflicting types for'"+vars[i].getName()+"'");
		}
        }
    }
    err_def_func=0;
}
#line 1842 "y.tab.c"
    break;

  case 25: /* var_declaration: error SEMICOLON  */
#line 354 "1905065.y"
                        {
        yyclearin;
        yyerrok;
        (yyval.si) = new SymbolInfo("", "error", (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[0].si);
        logout<<"Error at line no "+to_string(line_cnt-multi_line)+" : syntax error"<<'\n';

    }
#line 1855 "y.tab.c"
    break;

  case 26: /* type_specifier: INT  */
#line 363 "1905065.y"
                   {
    (yyval.si) = new SymbolInfo( rulePrint("type_specifier","INT"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[0].si);

}
#line 1865 "y.tab.c"
    break;

  case 27: /* type_specifier: FLOAT  */
#line 368 "1905065.y"
           {
            
        (yyval.si) = new SymbolInfo( rulePrint("type_specifier","FLOAT"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[0].si);

    }
#line 1876 "y.tab.c"
    break;

  case 28: /* type_specifier: VOID  */
#line 374 "1905065.y"
          {
        (yyval.si) = new SymbolInfo( rulePrint("type_specifier","VOID"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[0].si);

    }
#line 1886 "y.tab.c"
    break;

  case 29: /* declaration_list: declaration_list COMMA ID  */
#line 381 "1905065.y"
                                           {
        
        (yyval.si) = new SymbolInfo( rulePrint("declaration_list","declaration_list COMMA ID"),(yyvsp[0].si)->dataType, (yyvsp[-2].si)->startLine, (yyvsp[0].si)->endLine);      
        (yyval.si)->child=(yyvsp[-2].si);
        (yyvsp[-2].si)->next=(yyvsp[-1].si);
        (yyvsp[-1].si)->next= (yyvsp[0].si);
        codeVarDecl((yyvsp[0].si));
        vars.push_back(*(yyvsp[0].si));
}
#line 1900 "y.tab.c"
    break;

  case 30: /* declaration_list: declaration_list COMMA ID LSQUARE CONST_INT RSQUARE  */
#line 390 "1905065.y"
                                                         {
        (yyvsp[-3].si)->setArraySize((yyvsp[-1].si)->name);
        codeVarDecl((yyvsp[-3].si));
        vars.push_back(*(yyvsp[-3].si));
        (yyval.si) = new SymbolInfo( rulePrint("declaration_list","declaration_list COMMA ID LSQUARE CONST_INT RSQUARE"),(yyvsp[-5].si)->dataType, (yyvsp[-5].si)->startLine, (yyvsp[0].si)->endLine);    
        (yyval.si)->child=(yyvsp[-5].si);
        (yyvsp[-5].si)->next=(yyvsp[-4].si);
        (yyvsp[-4].si)->next= (yyvsp[-3].si);
        (yyvsp[-3].si)->next=(yyvsp[-2].si);
        (yyvsp[-2].si)->next=(yyvsp[-1].si);
        (yyvsp[-1].si)->next=(yyvsp[0].si);
    }
#line 1917 "y.tab.c"
    break;

  case 31: /* declaration_list: ID  */
#line 402 "1905065.y"
        {
        vars.clear();
        (yyval.si) = new SymbolInfo( rulePrint("declaration_list","ID"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);      
        (yyval.si)->child=(yyvsp[0].si);
        codeVarDecl((yyvsp[0].si));
         vars.push_back(*(yyvsp[0].si));

    }
#line 1930 "y.tab.c"
    break;

  case 32: /* declaration_list: ID LSQUARE CONST_INT RSQUARE  */
#line 410 "1905065.y"
                                  {
        vars.clear();
        (yyvsp[-3].si)->setArraySize((yyvsp[-1].si)->name);

        codeVarDecl((yyvsp[-3].si));
        vars.push_back(*(yyvsp[-3].si));
        (yyval.si) = new SymbolInfo( rulePrint("declaration_list","ID LSQUARE CONST_INT RSQUARE"),(yyvsp[-3].si)->dataType, (yyvsp[-3].si)->startLine, (yyvsp[0].si)->endLine);    
        (yyval.si)->child=(yyvsp[-3].si);
        (yyvsp[-3].si)->next=(yyvsp[-2].si);
        (yyvsp[-2].si)->next= (yyvsp[-1].si);
        (yyvsp[-1].si)->next=(yyvsp[0].si);
    }
#line 1947 "y.tab.c"
    break;

  case 33: /* declaration_list: declaration_list error  */
#line 422 "1905065.y"
                             {
        yyclearin;
        (yyval.si) = new SymbolInfo((yyvsp[-1].si)->getName(), "error",(yyvsp[-1].si)->startLine, (yyvsp[-1].si)->endLine);
        (yyval.si)->child=(yyvsp[-1].si);

        logout<<"Error at line no "+to_string(line_cnt-multi_line)+" : syntax error"<<'\n';
        err_def_func=1;
    }
#line 1960 "y.tab.c"
    break;

  case 34: /* statements: statement  */
#line 432 "1905065.y"
                     {
    (yyval.si) = new SymbolInfo( rulePrint("statements", "statement"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[0].si);

}
#line 1970 "y.tab.c"
    break;

  case 35: /* statements: statements statement  */
#line 437 "1905065.y"
                          {
        (yyval.si) = new SymbolInfo( rulePrint("statements", "statements statement"),(yyvsp[-1].si)->dataType, (yyvsp[-1].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-1].si);
        (yyvsp[-1].si)->next=(yyvsp[0].si);
    }
#line 1980 "y.tab.c"
    break;

  case 36: /* statement: var_declaration  */
#line 444 "1905065.y"
                          {
    (yyval.si) = new SymbolInfo( rulePrint("statement", "var_declaration"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[0].si);

}
#line 1990 "y.tab.c"
    break;

  case 37: /* statement: expression_statement  */
#line 449 "1905065.y"
                          {
        (yyval.si) = new SymbolInfo( rulePrint("statement", "expression_statement"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[0].si);
    	codePrint("\tPOP AX");

    }
#line 2001 "y.tab.c"
    break;

  case 38: /* statement: compound_statement  */
#line 455 "1905065.y"
                        {
        (yyval.si) = new SymbolInfo( rulePrint("statement", "compound_statement"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[0].si);

    }
#line 2011 "y.tab.c"
    break;

  case 39: /* $@4: %empty  */
#line 460 "1905065.y"
          { 
    
    }
#line 2019 "y.tab.c"
    break;

  case 40: /* $@5: %empty  */
#line 462 "1905065.y"
                                   {
        //initialization
        labels.push_back(newLabel()); //FOR_COND->-4
		labels.push_back(newLabel()); //FOR_STMT->-3
		labels.push_back(newLabel()); //FOR_UPDATE->-2
		labels.push_back(newLabel()); //END_FOR->-1
		codePrint("\tPOP AX");
		codePrint("\t"+labels[labels.size()-4]+":");
    }
#line 2033 "y.tab.c"
    break;

  case 41: /* $@6: %empty  */
#line 470 "1905065.y"
                          {
        //cond check
        codePrint("\tPOP AX"); 
		codePrint("\tCMP AX, 0");
		codePrint("\tJE "+labels[labels.size()-1]); 
		codePrint("\tJMP "+labels[labels.size()-3]);
		codePrint("\t"+labels[labels.size()-2]+":"); 
    }
#line 2046 "y.tab.c"
    break;

  case 42: /* $@7: %empty  */
#line 477 "1905065.y"
                              {
        // update
		codePrint("\tPOP AX");
		codePrint("\tJMP "+labels[labels.size()-4]);
		codePrint("\t"+labels[labels.size()-3]+":");       
    }
#line 2057 "y.tab.c"
    break;

  case 43: /* statement: FOR $@4 LPAREN expression_statement $@5 expression_statement $@6 exp_void_func expression $@7 RPAREN statement  */
#line 482 "1905065.y"
                      {
        //1->3->4->6->9->11->12
        (yyval.si) = new SymbolInfo( rulePrint("statement", "FOR LPAREN expression_statement expression_statement expression RPAREN statement"),(yyvsp[-11].si)->dataType, (yyvsp[-11].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-11].si);
        (yyvsp[-11].si)->next=(yyvsp[-9].si);
        (yyvsp[-9].si)->next= (yyvsp[-8].si);
        (yyvsp[-8].si)->next=(yyvsp[-6].si);
        (yyvsp[-6].si)->next=(yyvsp[-3].si);
        (yyvsp[-3].si)->next=(yyvsp[-1].si);
        (yyvsp[-1].si)->next=(yyvsp[0].si);
        codePrint("\tJMP "+labels[labels.size()-2]);
		codePrint("\t"+labels[labels.size()-1]+":"); 
		labels.pop_back();
        labels.pop_back();
        labels.pop_back();
        labels.pop_back();
    }
#line 2079 "y.tab.c"
    break;

  case 44: /* statement: if_common_part  */
#line 499 "1905065.y"
                                          {
        (yyval.si) = new SymbolInfo( rulePrint("statement", "IF LPAREN expression RPAREN statement"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[0].si)->child;
        // print end label
		codePrint("\t"+labels[labels.size()-1]+":\n");
        labels.pop_back();
    }
#line 2091 "y.tab.c"
    break;

  case 45: /* $@8: %empty  */
#line 506 "1905065.y"
                          {
		labels.push_back(newLabel());// elseend ->-1, ifend->-2
		codePrint("\tJMP "+labels[labels.size()-1]); 
		codePrint("\t"+labels[labels.size()-2]+":\n");
		
	}
#line 2102 "y.tab.c"
    break;

  case 46: /* statement: if_common_part ELSE $@8 statement  */
#line 511 "1905065.y"
                   {
        (yyval.si) = new SymbolInfo( rulePrint("statement", "IF LPAREN expression RPAREN statement ELSE statement"),(yyvsp[-3].si)->dataType, (yyvsp[-3].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-3].si)->child;
        (yyvsp[-3].si)->next->next=(yyvsp[-2].si);
        (yyvsp[-2].si)->next= (yyvsp[0].si);
        codePrint("\t"+labels[labels.size()-1]+":\n");
        labels.pop_back();
        labels.pop_back();
    }
#line 2116 "y.tab.c"
    break;

  case 47: /* $@9: %empty  */
#line 520 "1905065.y"
                   { //1->2->4->6->8
        labels.push_back(newLabel());// wloop->-2
        labels.push_back(newLabel());// wloopend->-1
        codePrint("\t"+labels[labels.size()-2]+":");
    }
#line 2126 "y.tab.c"
    break;

  case 48: /* $@10: %empty  */
#line 525 "1905065.y"
                                       {
		
		codePrint("\tPOP AX");
		codePrint("\tCMP AX,0");
		codePrint("\tJE "+labels[labels.size()-1]);
	}
#line 2137 "y.tab.c"
    break;

  case 49: /* statement: WHILE LPAREN $@9 expression exp_void_func RPAREN $@10 statement  */
#line 530 "1905065.y"
                   {
        (yyval.si) = new SymbolInfo( rulePrint("statement", "WHILE LPAREN expression RPAREN statement"),(yyvsp[-7].si)->dataType, (yyvsp[-7].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-7].si);
        (yyvsp[-7].si)->next=(yyvsp[-6].si);
        (yyvsp[-6].si)->next= (yyvsp[-4].si);
        (yyvsp[-4].si)->next=(yyvsp[-2].si);
        (yyvsp[-2].si)->next=(yyvsp[0].si);
        codePrint("\tJMP "+labels[labels.size()-2]);
		codePrint("\t"+labels[labels.size()-1]+":\n");
        labels.pop_back();
        labels.pop_back();
    }
#line 2154 "y.tab.c"
    break;

  case 50: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 542 "1905065.y"
                                        {
        (yyval.si) = new SymbolInfo( rulePrint("statement", "PRINTLN LPAREN ID RPAREN SEMICOLON"),(yyvsp[-4].si)->dataType, (yyvsp[-4].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-4].si);
        (yyvsp[-4].si)->next=(yyvsp[-3].si);
        (yyvsp[-3].si)->next=(yyvsp[-2].si);
        (yyvsp[-2].si)->next=(yyvsp[-1].si);
        (yyvsp[-1].si)->next=(yyvsp[0].si);
        SymbolInfo* temp= st.lookup((yyvsp[-2].si)->getName());
        if(temp!=NULL)
        {
            codePrint("\tMOV AX, "+getVar(temp));
			codePrint("\tCALL print_output");
            
        }
    }
#line 2174 "y.tab.c"
    break;

  case 51: /* statement: RETURN expression exp_void_func SEMICOLON  */
#line 557 "1905065.y"
                                               {
        (yyval.si) = new SymbolInfo( rulePrint("statement", "RETURN expression SEMICOLON"),(yyvsp[-3].si)->dataType, (yyvsp[-3].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-3].si);
        (yyvsp[-3].si)->next=(yyvsp[-2].si);
        (yyvsp[-2].si)->next= (yyvsp[0].si);
        codePrint("\tPOP AX");
		codePrint("\tMOV [BP+4], AX");     
    }
#line 2187 "y.tab.c"
    break;

  case 52: /* $@11: %empty  */
#line 566 "1905065.y"
                                                          {// creating end label and jeq 0 end
	
    labels.push_back(newLabel());// ifend
	codePrint("\tPOP AX");
	codePrint("\tCMP AX, 0");
	codePrint("\tJE "+labels[labels.size()-1]);
}
#line 2199 "y.tab.c"
    break;

  case 53: /* if_common_part: IF LPAREN expression exp_void_func RPAREN $@11 statement  */
#line 572 "1905065.y"
           {
        (yyval.si)->startLine=(yyvsp[-6].si)->startLine;
        (yyval.si)->endLine= (yyvsp[0].si)->endLine;
        (yyval.si)->dataType= (yyvsp[-6].si)->dataType;
        (yyval.si)->child=(yyvsp[-6].si);
        (yyval.si)->next=(yyvsp[0].si);
        (yyvsp[-6].si)->next=(yyvsp[-5].si);
        (yyvsp[-5].si)->next= (yyvsp[-4].si);
        (yyvsp[-4].si)->next=(yyvsp[-2].si);
        (yyvsp[-2].si)->next=(yyvsp[0].si);

}
#line 2216 "y.tab.c"
    break;

  case 54: /* exp_void_func: %empty  */
#line 585 "1905065.y"
                {
    stat_func_type=idType;
    if(stat_func_type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
    }
 }
#line 2228 "y.tab.c"
    break;

  case 55: /* expression_statement: SEMICOLON  */
#line 592 "1905065.y"
                               {
    idType = "INT";
    (yyval.si) = new SymbolInfo( rulePrint("expression_statement","SEMICOLON"),"INT", (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[0].si);
    codePrint("\tPUSH 1\n");//for infinite loop
}
#line 2239 "y.tab.c"
    break;

  case 56: /* expression_statement: expression SEMICOLON  */
#line 598 "1905065.y"
                           {
        idType= (yyvsp[-1].si)->type;
        (yyval.si)->isBool=(yyvsp[-1].si)->isBool;
        (yyval.si) = new SymbolInfo( rulePrint("expression_statement","expression SEMICOLON"),(yyvsp[-1].si)->dataType, (yyvsp[-1].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-1].si);
        (yyvsp[-1].si)->next=(yyvsp[0].si);
    }
#line 2251 "y.tab.c"
    break;

  case 57: /* expression_statement: expression error  */
#line 605 "1905065.y"
                        {
        yyclearin;
        (yyval.si) = new SymbolInfo("", "error", (yyvsp[-1].si)->startLine, (yyvsp[-1].si)->endLine);
        (yyval.si)->child=(yyvsp[-1].si);
        logout<<"Error at line no "+to_string(line_cnt-multi_line)+" : syntax error"<<'\n';
    
    }
#line 2263 "y.tab.c"
    break;

  case 58: /* variable: ID  */
#line 615 "1905065.y"
            {
 
(yyval.si) = new SymbolInfo( rulePrint("variable", "ID"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[0].si);

    SymbolInfo *temp= st.lookup((yyvsp[0].si)->name);
    if(temp==NULL || temp->isFunc){
        err_cnt++;
        errorPrint("Undeclared variable '"+(yyvsp[0].si)->name+"'");
     
    }
    else{
         (yyvsp[0].si)=new SymbolInfo(temp);
        // // $$->valPointer= $1;
        (yyvsp[0].si)->next=(yyvsp[0].si)->child=NULL;
         (yyval.si)->child=(yyvsp[0].si);
        if(temp->type == "VOID") {
         
           err_cnt++;
           errorPrint("variable "+(yyvsp[0].si)->name+" of type void");
        } else {
            (yyval.si)->setType(temp->dataType); 
        }
    }

}
#line 2294 "y.tab.c"
    break;

  case 59: /* variable: ID LSQUARE expression RSQUARE  */
#line 641 "1905065.y"
                                   {

        (yyval.si) = new SymbolInfo( rulePrint("variable", "ID LSQUARE expression RSQUARE"),(yyvsp[-3].si)->dataType, (yyvsp[-3].si)->startLine, (yyvsp[0].si)->endLine);
    
    
    (yyvsp[-2].si)->next= (yyvsp[-1].si);
    (yyvsp[-1].si)->next=(yyvsp[0].si);
    SymbolInfo *temp= st.lookup((yyvsp[-3].si)->name);

    (yyval.si)->child=(yyvsp[-3].si);
    
    if(temp==NULL || temp->isFunc){
        err_cnt++;
        errorPrint("Undeclared variable '"+(yyvsp[-3].si)->name+"'");
     
    }
            
    else{
        (yyvsp[-3].si)= new SymbolInfo(temp);
         (yyval.si)->child=(yyvsp[-3].si);
         (yyvsp[-3].si)->next=(yyvsp[-2].si);
         (yyvsp[-3].si)->child=NULL;
        if(temp->arraySize==-1){
            err_cnt++;
            errorPrint("'"+(yyvsp[-3].si)->name+"' is not an array");
         
        }
        else{
            if(temp->type == "VOID") {
         
            err_cnt++;
            errorPrint("variable "+(yyvsp[-3].si)->name+" of type void");
        } else {
            (yyval.si)->setType(temp->dataType); 
        }

        }
    }
    if((yyvsp[-1].si)->dataType!="INT"){
            err_cnt++;
            errorPrint("Array subscript is not an integer");
        }
    codePrint("\tPOP AX");
    codePrint("\tSHL AX, 1");
    codePrint("\tLEA SI, "+getVar(temp));
    codePrint("\tSUB SI, AX");
    codePrint("\tPUSH SI\n");
        
}
#line 2348 "y.tab.c"
    break;

  case 60: /* expression: logic_expression  */
#line 692 "1905065.y"
                            {
    (yyval.si) = new SymbolInfo( rulePrint("expression", "logic_expression"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->isBool=(yyvsp[0].si)->isBool;
    (yyval.si)->child=(yyvsp[0].si);

    idType=(yyvsp[0].si)->dataType;
    mulop_flag="";
    current_val=1;
}
#line 2362 "y.tab.c"
    break;

  case 61: /* expression: variable ASSIGNOP logic_expression  */
#line 702 "1905065.y"
                                        {
        (yyval.si) = new SymbolInfo( rulePrint("expression", "variable ASSIGNOP logic_expression"),(yyvsp[-2].si)->dataType, (yyvsp[-2].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-2].si);
        (yyvsp[-2].si)->next=(yyvsp[-1].si);
        (yyvsp[-1].si)->next= (yyvsp[0].si);
        if((yyval.si)->type=="VOID" ){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    else if((yyvsp[0].si)->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
        else if((yyvsp[0].si)->dataType=="FLOAT" && (yyvsp[-2].si)->dataType=="INT" ){
            err_cnt++;
            errorPrint("Warning: possible loss of data in assignment of FLOAT to INT");
        }
        idType=(yyvsp[-2].si)->dataType;
        mulop_flag="";
    current_val=1;
    	codePrint("\tPOP AX");
        //if($1->child->next==NULL)
		    codePrint("\tMOV "+getVar((yyvsp[-2].si)->child,(yyvsp[-2].si)->child->next!=NULL)+", AX");
        //else codePrint("\tMOV "+getVar($1->child,$1->child->next->next->value)+", AX");
		codePrint("\tPUSH AX");
    }
#line 2397 "y.tab.c"
    break;

  case 62: /* logic_expression: rel_expression  */
#line 737 "1905065.y"
                                {
    (yyval.si) = new SymbolInfo( rulePrint("logic_expression", "rel_expression"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->isBool=(yyvsp[0].si)->isBool;
    (yyval.si)->child=(yyvsp[0].si);

}
#line 2408 "y.tab.c"
    break;

  case 63: /* $@12: %empty  */
#line 743 "1905065.y"
                             {
        {
		codePrint("\tPOP AX");
		string pushBool = (yyvsp[0].si)->getName() == "&&" ? "1" : "0";
		codePrint("\tCMP AX, "+pushBool);
		string jmpL = newLabel();
		codePrint("\tJNE "+jmpL);
		(yyvsp[-1].si)->label=jmpL;

	}
    }
#line 2424 "y.tab.c"
    break;

  case 64: /* logic_expression: rel_expression LOGICOP $@12 rel_expression  */
#line 753 "1905065.y"
                    {

       (yyval.si) = new SymbolInfo( rulePrint("logic_expression", "rel_expression LOGICOP rel_expression"),"INT", (yyvsp[-3].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->isBool=true;
        (yyval.si)->child=(yyvsp[-3].si);
        (yyvsp[-3].si)->next=(yyvsp[-2].si);
        (yyvsp[-2].si)->next= (yyvsp[0].si);
        if((yyval.si)->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
    }
    else if((yyvsp[0].si)->type=="VOID" ){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
    }
    codePrint("\tPOP AX");
    string pushBool = (yyvsp[-2].si)->getName() == "&&" ? "1" : "0";
    codePrint("\tCMP AX, "+pushBool);
    codePrint("\tJNE "+(yyvsp[-3].si)->label);
    codePrint("\tPUSH "+pushBool);
    string endLabel = newLabel();
    codePrint("\tJMP "+endLabel);
    codePrint("\t"+(yyvsp[-3].si)->label+":");
    pushBool[0]=('1'-pushBool[0])+'0';
    codePrint("\tPUSH " +pushBool);
    codePrint("\t"+endLabel+":\n");
    }
#line 2456 "y.tab.c"
    break;

  case 65: /* rel_expression: simple_expression  */
#line 782 "1905065.y"
                                 {
    (yyval.si) = new SymbolInfo( rulePrint("rel_expression", "simple_expression"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->isBool=(yyvsp[0].si)->isBool;
    (yyval.si)->child=(yyvsp[0].si);

}
#line 2467 "y.tab.c"
    break;

  case 66: /* rel_expression: simple_expression RELOP simple_expression  */
#line 788 "1905065.y"
                                               {

       (yyval.si) = new SymbolInfo( rulePrint("rel_expression", "simple_expression RELOP simple_expression"),"INT", (yyvsp[-2].si)->startLine, (yyvsp[0].si)->endLine); 
       (yyval.si)->isBool=true;
       (yyval.si)->child=(yyvsp[-2].si);
        (yyvsp[-2].si)->next=(yyvsp[-1].si);
        (yyvsp[-1].si)->next= (yyvsp[0].si);
        if((yyval.si)->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    else if((yyvsp[0].si)->type=="VOID" ){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     
    }
    	string L1 = newLabel(),L2 = newLabel();
		string relJump="";
        if((yyvsp[-1].si)->getName() == "<") relJump= "JL";
        else if((yyvsp[-1].si)->getName() == "!=") relJump= "JNE";
        else if((yyvsp[-1].si)->getName() == "<=") relJump= "JLE";
        else if((yyvsp[-1].si)->getName() == ">") relJump= "JG";
        else if((yyvsp[-1].si)->getName() == ">=") relJump= "JGE";
        else if((yyvsp[-1].si)->getName() == "==") relJump= "JE";
		codePrint("\tPOP BX");
		codePrint("\tPOP AX");
		codePrint("\tCMP AX, BX");
		codePrint("\t"+relJump+" "+L1);
		codePrint("\tPUSH 0\n\tJMP "+L2);
		codePrint("\t"+L1+":\n\tPUSH 1");
		codePrint("\t"+L2+":\n");
        
    }
#line 2507 "y.tab.c"
    break;

  case 67: /* simple_expression: term  */
#line 826 "1905065.y"
                       {
    (yyval.si) = new SymbolInfo( rulePrint("simple_expression", "term"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->isBool=(yyvsp[0].si)->isBool;
    (yyval.si)->child=(yyvsp[0].si);

}
#line 2518 "y.tab.c"
    break;

  case 68: /* simple_expression: simple_expression ADDOP term  */
#line 832 "1905065.y"
                                  {

        (yyval.si) = new SymbolInfo( rulePrint("simple_expression", "simple_expression ADDOP term"),(yyvsp[-2].si)->dataType, (yyvsp[-2].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[-2].si);
        (yyvsp[-2].si)->next=(yyvsp[-1].si);
        (yyvsp[-1].si)->next= (yyvsp[0].si);
        if((yyval.si)->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    else if((yyvsp[0].si)->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
        if((yyvsp[0].si)->dataType=="FLOAT"){
         
        }
        string addop = (yyvsp[-1].si)->getName() == "+" ? "ADD" : "SUB";
    	codePrint("\tPOP BX");
		codePrint("\tPOP AX");
		codePrint("\t"+addop+" AX, BX");
		codePrint("\tPUSH AX");

       
    }
#line 2552 "y.tab.c"
    break;

  case 69: /* simple_expression: error_rr CONST_INT  */
#line 861 "1905065.y"
                        {

    }
#line 2560 "y.tab.c"
    break;

  case 70: /* error_rr: error  */
#line 867 "1905065.y"
                {
     yyclearin;
           
   logout<<"Error at line no "+to_string(line_cnt-multi_line)+" : syntax error"<<'\n';

 }
#line 2571 "y.tab.c"
    break;

  case 71: /* mulop: MULOP  */
#line 873 "1905065.y"
             {
    (yyval.si) = new SymbolInfo( (yyvsp[0].si)->name,(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine,1);
    mulop_flag=(yyvsp[0].si)->name;

 }
#line 2581 "y.tab.c"
    break;

  case 72: /* term: unary_expression  */
#line 878 "1905065.y"
                      {
    (yyval.si) = new SymbolInfo( rulePrint("term", "unary_expression"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->isBool=(yyvsp[0].si)->isBool;
    (yyval.si)->child=(yyvsp[0].si);

}
#line 2592 "y.tab.c"
    break;

  case 73: /* term: term mulop unary_expression  */
#line 884 "1905065.y"
                                  {
    (yyval.si) = new SymbolInfo( rulePrint("term", "term MULOP unary_expression"),(yyvsp[-2].si)->dataType, (yyvsp[-2].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[-2].si);
    (yyvsp[-2].si)->next=(yyvsp[-1].si);
    (yyvsp[-1].si)->next= (yyvsp[0].si);
    if((yyval.si)->type=="VOID" ){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
         else   if((yyvsp[0].si)->type=="VOID" ){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    else if((yyvsp[-1].si)->name=="%" && ((yyvsp[-2].si)->dataType=="FLOAT"|| (yyvsp[0].si)->dataType=="FLOAT")){
        err_cnt++;
        errorPrint("Operands of modulus must be integers");
        (yyval.si)->setType("INT");
    }
    
    else if((yyvsp[-1].si)->name!="%" && ((yyvsp[-2].si)->dataType=="FLOAT"|| (yyvsp[0].si)->dataType=="FLOAT")){
        (yyval.si)->dataType="FLOAT";
    }
    if(((yyvsp[-1].si)->name=="%" || ((yyvsp[-1].si)->name=="/"))&& mulop_flag!="" &&current_val==0){
        errorPrint("Warning: division by zero i=0f=1Const=0");
        err_cnt++;
    }
    mulop_flag="";
    current_val=1;
    string mulop = (yyvsp[-1].si)->getName() == "*" ? "IMUL" : "IDIV" , res = (yyvsp[-1].si)->getName() == "%" ? "DX" : "AX";
    codePrint("\tPOP BX");
    codePrint("\tPOP AX");
    codePrint("\tXOR DX, DX");
    codePrint("\t"+mulop+" BX");
    codePrint("\tPUSH "+res);

    }
#line 2637 "y.tab.c"
    break;

  case 74: /* unary_expression: ADDOP unary_expression  */
#line 926 "1905065.y"
                                        {
    (yyval.si) = new SymbolInfo( rulePrint("unary_expression", "ADDOP unary_expression"),(yyvsp[0].si)->dataType, (yyvsp[-1].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[-1].si);
    (yyvsp[-1].si)->next=(yyvsp[0].si);
    if((yyval.si)->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    mulop_flag="";
    current_val=1;
    codePrint("\tPOP AX");
    codePrint("\tNEG AX");
    codePrint("\tPUSH AX\n");
}
#line 2658 "y.tab.c"
    break;

  case 75: /* unary_expression: NOT unary_expression  */
#line 942 "1905065.y"
                          {
    (yyval.si) = new SymbolInfo( rulePrint("unary_expression", "NOT unary_expression"),(yyvsp[0].si)->dataType, (yyvsp[-1].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->isBool=true;
    (yyval.si)->child=(yyvsp[-1].si);
    (yyvsp[-1].si)->next=(yyvsp[0].si);
    if((yyval.si)->type=="VOID" ){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    mulop_flag="";
    current_val=1;
    	string je = newLabel(), jne = newLabel(); 
    	codePrint("\tPOP AX\t;load "+(yyvsp[0].si)->getName());
		codePrint("\tCMP AX, 0");
		codePrint("\tJE "+je);
		codePrint("\tPUSH 0");
		codePrint("\tJMP "+jne);
		codePrint("\t"+je+":\n\tPUSH 1\n");
		codePrint("\t"+jne+":");
    }
#line 2685 "y.tab.c"
    break;

  case 76: /* unary_expression: factor  */
#line 964 "1905065.y"
            {
    (yyval.si) = new SymbolInfo( rulePrint("unary_expression", "factor"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[0].si);
    }
#line 2694 "y.tab.c"
    break;

  case 77: /* factor: variable  */
#line 970 "1905065.y"
                {
    (yyval.si) = new SymbolInfo( rulePrint("factor", "variable"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[0].si);

    mulop_flag="";
    current_val=1;
    codePrint("\tPUSH "+getVar((yyvsp[0].si)->child, (yyvsp[0].si)->child->next!=NULL));

}
#line 2708 "y.tab.c"
    break;

  case 78: /* factor: ID LPAREN argument_list RPAREN  */
#line 979 "1905065.y"
                                   {
    
    (yyval.si) = new SymbolInfo( rulePrint("factor","ID LPAREN argument_list RPAREN"),(yyvsp[-3].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[-3].si)->endLine);
    (yyval.si)->child=(yyvsp[-3].si);
    (yyvsp[-3].si)->next=(yyvsp[-2].si);
    (yyvsp[-2].si)->next= (yyvsp[-1].si);
    (yyvsp[-1].si)->next=(yyvsp[0].si);
        SymbolInfo *temp= st.lookup((yyvsp[-3].si)->name);
    if(temp==NULL){
        err_cnt++;
        errorPrint("Undeclared function '"+(yyvsp[-3].si)->name+"'");
     
    }
    else{
        (yyval.si)->setType(temp->dataType);
        if(!temp->isFuncDefined){
            err_cnt++;
            errorPrint("no such function definition found");
           
        }
        else{
            if(temp->paramTypeList.size()>args.size()) 
            {
                err_cnt++;
                errorPrint("Too few arguments to function '"+(yyvsp[-3].si)->name+"'");
             
        }else if(temp->paramTypeList.size()<args.size()) 
            {
                err_cnt++;
                errorPrint("Too many arguments to function '"+(yyvsp[-3].si)->name+"'");
             
        }
         else {
            bool okay=1;
            for(int i=0; i<args.size();i++){
                if(temp->paramTypeList[i]!=args[i].dataType || args[i].arraySize!=-1)
                    {
                        err_cnt++;
                        errorPrint("Type mismatch for argument "+to_string(i+1)+" of '"+(yyvsp[-3].si)->name+"'");
                        okay=0;
                    }
            }
            if(okay){
                 (yyval.si)->setType(temp->dataType);
            } 

        }

        }
    }
    
    mulop_flag="";
    current_val=1;

    codePrint("\tPUSH 0"); // BP+4
	codePrint("\tCALL "+(yyvsp[-3].si)->getName());
	codePrint("\tPOP AX");
    codePrint("\tADD SP,"+to_string(args.size()*2));

		if(temp->dataType != "void"){
			codePrint("\tPUSH AX");
		}else{
			codePrint("\tPUSH 0");
		}
        args.clear();
   }
#line 2779 "y.tab.c"
    break;

  case 79: /* factor: LPAREN expression RPAREN  */
#line 1045 "1905065.y"
                             {
    (yyval.si) = new SymbolInfo( rulePrint("factor","LPAREN expression RPAREN"),(yyvsp[-1].si)->dataType, (yyvsp[-2].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[-2].si);
    (yyvsp[-2].si)->next=(yyvsp[-1].si);
    (yyvsp[-1].si)->next= (yyvsp[0].si);
    if((yyval.si)->type=="VOID"){
        err_cnt++;
        errorPrint("Void cannot be used in expression");
     

    }
    mulop_flag="";
    current_val=1;
   }
#line 2798 "y.tab.c"
    break;

  case 80: /* factor: CONST_INT  */
#line 1059 "1905065.y"
               {
    (yyval.si) = new SymbolInfo( rulePrint("factor","CONST_INT"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[0].si);
 
    if(mulop_flag=="/" || mulop_flag=="%"){
            current_val=stoi((yyvsp[0].si)->name);
        }
    codePrint("\tPUSH " + (yyvsp[0].si)->getName());
    }
#line 2812 "y.tab.c"
    break;

  case 81: /* factor: CONST_FLOAT  */
#line 1068 "1905065.y"
                 {
        (yyval.si) = new SymbolInfo( rulePrint("factor","CONST_FLOAT"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);
        (yyval.si)->child=(yyvsp[0].si);

        if(mulop_flag=="/" || mulop_flag=="%"){
            current_val=stoi((yyvsp[0].si)->name);
        }
        codePrint("\tPUSH " + (yyvsp[0].si)->getName());
    }
#line 2826 "y.tab.c"
    break;

  case 82: /* factor: variable INCOP  */
#line 1077 "1905065.y"
                    {
    (yyval.si) = new SymbolInfo( rulePrint("factor","variable INCOP"),(yyvsp[-1].si)->dataType, (yyvsp[-1].si)->startLine, (yyvsp[0].si)->endLine);
    (yyval.si)->child=(yyvsp[-1].si);
    (yyvsp[-1].si)->next=(yyvsp[0].si);
    mulop_flag="";
    current_val=1;

    string var = getVar((yyvsp[-1].si)->child,(yyvsp[-1].si)->child->next!=NULL );
    codePrint("\tPUSH " + var);
    codePrint("\tINC " + var);
    }
#line 2842 "y.tab.c"
    break;

  case 83: /* factor: variable DECOP  */
#line 1088 "1905065.y"
                    {
         (yyval.si) = new SymbolInfo( rulePrint("factor","variable DECOP"),(yyvsp[-1].si)->dataType, (yyvsp[-1].si)->startLine, (yyvsp[0].si)->endLine);
         (yyval.si)->child=(yyvsp[-1].si);
        (yyvsp[-1].si)->next=(yyvsp[0].si);
            mulop_flag="";
         current_val=1;
    string var = getVar((yyvsp[-1].si)->child,(yyvsp[-1].si)->child->next!=NULL );
    codePrint("\tPUSH " + var);
    codePrint("\tDEC " + var);
    }
#line 2857 "y.tab.c"
    break;

  case 84: /* argument_list: arguments  */
#line 1100 "1905065.y"
                        {
    (yyval.si) = new SymbolInfo( rulePrint("argument_list","arguments"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);       
    (yyval.si)->child=(yyvsp[0].si);

        mulop_flag="";
    current_val=1;
}
#line 2869 "y.tab.c"
    break;

  case 85: /* argument_list: %empty  */
#line 1107 "1905065.y"
     {
    (yyval.si) = new SymbolInfo( rulePrint("argument_list","<epsilon-production>"),"INT", line_cnt-multi_line, line_cnt-multi_line);              
    

    mulop_flag="";
    current_val=1;
    }
#line 2881 "y.tab.c"
    break;

  case 86: /* arguments: arguments COMMA logic_expression  */
#line 1115 "1905065.y"
                                           {
    (yyval.si) = new SymbolInfo( rulePrint("arguments","arguments COMMA logic_expression"),(yyvsp[-2].si)->dataType, (yyvsp[-2].si)->startLine, (yyvsp[0].si)->endLine);       
    (yyval.si)->child=(yyvsp[-2].si);
    (yyvsp[-2].si)->next=(yyvsp[-1].si);
    (yyvsp[-1].si)->next= (yyvsp[0].si);
    args.push_back(*(yyvsp[0].si));
}
#line 2893 "y.tab.c"
    break;

  case 87: /* arguments: logic_expression  */
#line 1122 "1905065.y"
                      {
    (yyval.si) = new SymbolInfo( rulePrint("arguments","logic_expression"),(yyvsp[0].si)->dataType, (yyvsp[0].si)->startLine, (yyvsp[0].si)->endLine);       
    (yyval.si)->child=(yyvsp[0].si);
 
        args.clear();
        args.push_back(*(yyvsp[0].si));
    }
#line 2905 "y.tab.c"
    break;


#line 2909 "y.tab.c"

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

#line 1131 "1905065.y"


main(int argc, char* argv[], char* endp[])
{
    if(argc != 2){
        cout<<"provide file name\n"  ;
        exit(1)  ;
    }

    FILE* filein = fopen(argv[1], "r")  ;
    if(filein == NULL){
        cout<<"Cannot open file\n"   ;
        exit(1)  ;
    }
    parseout.open("1905065_parsetree.txt", ios::out);
    logout.open("1905065_log.txt", ios::out);
    errorout.open("1905065_error.txt", ios::out);
    asmout.open("1905065_code.asm", ios::out);
    codeout.open("1905065_temp.asm", ios::out);
   yyin = filein   ;
    yyparse();
    logout << "Total Lines: " << line_cnt << '\n' ;
    logout << "Total Errors: " << err_cnt << '\n'   ;
    printParseTree();
    logout.close()  ;
    fclose(yyin) ;
    parseout.close();
    errorout.close();
    asmout.close();
    codeout.close();
    exit(0)  ;
}
