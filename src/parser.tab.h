/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KEYWORD_STRICT_AS = 258,
    KEYWORD_STRICT_BREAK = 259,
    KEYWORD_STRICT_CONST = 260,
    KEYWORD_STRICT_CONTINUE = 261,
    KEYWORD_STRICT_CRATE = 262,
    KEYWORD_STRICT_ELSE = 263,
    KEYWORD_STRICT_ENUM = 264,
    KEYWORD_STRICT_EXTERN = 265,
    KEYWORD_STRICT_FALSE = 266,
    KEYWORD_STRICT_FN = 267,
    KEYWORD_STRICT_FOR = 268,
    KEYWORD_STRICT_IF = 269,
    KEYWORD_STRICT_IMPL = 270,
    KEYWORD_STRICT_IN = 271,
    KEYWORD_STRICT_LET = 272,
    KEYWORD_STRICT_LOOP = 273,
    KEYWORD_STRICT_MATCH = 274,
    KEYWORD_STRICT_MOD = 275,
    KEYWORD_STRICT_MOVE = 276,
    KEYWORD_STRICT_MUT = 277,
    KEYWORD_STRICT_PUB = 278,
    KEYWORD_STRICT_REF = 279,
    KEYWORD_STRICT_RETURN = 280,
    KEYWORD_STRICT_SELFVALUE = 281,
    KEYWORD_STRICT_SELFTYPE = 282,
    KEYWORD_STRICT_STATIC = 283,
    KEYWORD_STRICT_STRUCT = 284,
    KEYWORD_STRICT_SUPER = 285,
    KEYWORD_STRICT_TRAIT = 286,
    KEYWORD_STRICT_TRUE = 287,
    KEYWORD_STRICT_TYPE = 288,
    KEYWORD_STRICT_UNSAFE = 289,
    KEYWORD_STRICT_USE = 290,
    KEYWORD_STRICT_WHERE = 291,
    KEYWORD_STRICT_WHILE = 292,
    KEYWORD_STRICT_ASYNC = 293,
    KEYWORD_STRICT_AWAIT = 294,
    KEYWORD_STRICT_DYN = 295,
    KEYWORD_RES_ABSTRACT = 296,
    KEYWORD_RES_BECOME = 297,
    KEYWORD_RES_BOX = 298,
    KEYWORD_RES_DO = 299,
    KEYWORD_RES_FINAL = 300,
    KEYWORD_RES_MACRO = 301,
    KEYWORD_RES_OVERRIDE = 302,
    KEYWORD_RES_PRIV = 303,
    KEYWORD_RES_TYPEOF = 304,
    KEYWORD_RES_UNSIZED = 305,
    KEYWORD_RES_VIRTUAL = 306,
    KEYWORD_RES_YILED = 307,
    KEYWORD_RES_TRY = 308,
    KEYWORD_WEAK_UNION = 309,
    KEYWORD_WEAK_STATICLIFETIME = 310,
    KEYWORD_WEAK_DYN = 311,
    ADDOP = 312,
    SUBOP = 313,
    MULOP = 314,
    DIVOP = 315,
    INCR = 316,
    DECR = 317,
    OROP = 318,
    ANDOP = 319,
    NOTOP = 320,
    EQUOP = 321,
    NEQUOP = 322,
    GT = 323,
    LT = 324,
    GTEQ = 325,
    LTEQ = 326,
    COLON = 327,
    LPAREN = 328,
    RPAREN = 329,
    LBRACK = 330,
    RBRACK = 331,
    LBRACE = 332,
    RBRACE = 333,
    SEMI = 334,
    DOTDOT = 335,
    DOT = 336,
    COMMA = 337,
    ASSIGN = 338,
    REFER = 339,
    ID = 340,
    UNDERSCORE = 341,
    HASH = 342,
    ARROW = 343,
    ICONST = 344,
    FCONST = 345,
    CCONST = 346,
    STRING = 347
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
