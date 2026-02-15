%define api.pure full
%define parse.error detailed
%define api.namespace {jaguar::parser}
%define parser.class.name {parser}
%language "c++"

/* includes in the generated header file */
%code requires 
{
#include "../parser/driver.h"
#include "../parser/ast_node.h"
#include "../parser/nodes/statement.h"
#include "../parser/nodes/statement_list.h"
#include "../parser/nodes/var_decl.h"
#include "../parser/nodes/expression.h"
#include "../parser/nodes/int_literal.h"

//location structure for debugging
struct location_t {
  struct point {
    int line;
    int column;
  };

  point begin;
  point end;

  location_t() : begin{0,0}, end{0,0} {}
};
}

/* Only in the cpp file */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory>
#include "../parser/parser.h"
%}

/* Types */
%union {
  int ival;
  float fval;
  std::string* strval;

  std::unique_ptr<ASTNode> node;
  std::unique_ptr<Statement> stmt;
  std::unique_ptr<StatementList> stmtList;
  std::unique_ptr<Expression> expr;
}

//pass the driver and activate locations for debugging
%parse-param { Driver& driver }
%define api.location.type {location_t}
%locations

//set the rule entry point
%start program

//add += -= ++ -- ? ^

//operator tokens
%token PLUS MINUS STAR SLASH ASSIGN
%token EQ NE LT LE GT GE  //Equal (==), Not equal (!=), Less than, Less equal, Greater than, Greater Equal
%token AND OR //&& ||
%token UMINUS // -x
%token NOT //!

//operator priority rules
%right ASSIGN     //=

%left OR
%left AND

%left EQ NE LT LE GT GE

%left PLUS MINUS
%left STAR SLASH

%left UMINUS
%left NOT



/* Tokens */
//simple tokens
%token <strval> IDENTIFIER

//keyword tokens
%token K_INT        //int
%token K_FLOAT      //float
%token K_STRING     //string

//separator tokens
%token LPAREN     //(
%token RPAREN     //)
%token LBRACE     //{
%token RBRACE     //}
%token SEMICOLON  //;
%token COMMA      //,

%token <strval> DECORATOR      //@
%token <strval> PREPROCESSOR   //#

//val tokens
%token <ival> L_INT   //literal int, eg. 10, 57, ...


/* Expressions */
//operations that produce an int
%type <expr> int_expr


//a statement (instruction) produces a Statement object
%type <stmt> statement
%type <stmtList> program


%%

/* rules */
statement
  : int_expr SEMICOLON
    {
      //driver.result = $1;
    }
  | K_INT IDENTIFIER ASSIGN int_expr SEMICOLON
    {
      //$2 is the identifier and $4 is the expression
      $$ = std::make_unique<VarDecl>(
        *$2, //name
        "int", //type
        std::unique_ptr<Expression>($4), //expression init
        @1.begin.line,
        @1.begin.column);
      //free the var name (string)
      delete $2;
    }
  ;

program
  : /* start of the program */ {
      $$ = std::make_unique<StatementList>(RootStatement, 0,0); //location 0, 0
    }
  | program statement {
      $1->Add(std::move($2));
      $$ = std::move($1);
    }
  ;

int_expr
  : L_INT { //literal int, eg. 10, 46
      $$ = std::make_unique<IntLiteral>($1, @1.begin.line, @1.begin.column);
    }
  | int_expr PLUS int_expr { //int plus operation, eg. 40 + 57
      //$$ = new BinaryOperation();
    }
  | int_expr MINUS int_expr { 
      //$$ = 
    }
  ;

%%