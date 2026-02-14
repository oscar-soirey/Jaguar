%define api.pure full
%define parse.error detailed
%define api.namespace {jaguar::parser}
%define parser.class.name {parser}
%language "c++"

/* includes in the generated header file */
%code requires 
{
#include "../parser/driver.h"
}
//pass the driver
%parse-param { Driver& driver }

/* Only in the cpp file */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "../parser/parser.h"
%}

%start program

//ajouter += -= ++ -- ? ^

//operator tokens
%token PLUS MINUS STAR SLASH ASSIGN
%token EQ NE LT LE GT GE  //Equal (==), Not equal (!=), Less than, Less equal, Greater than, Greater Equal
%token AND OR //&& ||
%token UMINUS // -x
%token NOT //!

//operator priority rules
%right ASSIGN

%left OR
%left AND

%left EQ NE LT LE GT GE

%left PLUS MINUS
%left STAR SLASH

%left UMINUS
%left NOT



/* Types */
%union {
  int ival;
  std::string* strval;
}

/* Tokens */
//simple tokens
%token <strval> IDENTIFIER
%token K_INT

//val tokens
%token <ival> L_INT


/* Expressions */
//operations that produce an int
%type <ival> int_expr


%%

/* rules */
statement
  : int_expr ';'
    {
      driver.result = $1;
    }
  | K_INT IDENTIFIER ASSIGN int_expr ';'
  ;

program
  : /* empty */
  | program statement
  ;

int_expr
  : L_INT { $$ = $1; }
  | int_expr PLUS int_expr { $$ = $1 + $3; }
  | int_expr MINUS int_expr { $$ = $1 - $3; }
  ;

%%

/* C++ code */
