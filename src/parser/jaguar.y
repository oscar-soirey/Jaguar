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
#include "../parser/nodes/string_literal.h"
#include "../parser/nodes/var_assign.h"
#include "../parser/nodes/binary_op.h"
#include "../parser/nodes/var_ref.h"

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

	ASTNode* node;
	Statement* stmt;
	StatementList* stmtList;
	Expression* expr;
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
%token <strval> L_STRING  //literal string, eg. "hello world!"


/* Expressions */
//operations that produce an int
%type <expr> int_expr
%type <expr> str_expr


//a statement (instruction) produces a Statement object
%type <stmt> statement
%type <stmtList> program


%%

/* rules */
statement
	:
		IDENTIFIER ASSIGN int_expr SEMICOLON {
			std::string name = std::move(*$1);
			//delete $1;

			$$ = new VarAssign(
				name, //var name
				$3, //expr
				@1.begin.line,
				@1.begin.column
			);
		}

		//int declaration without initialization
	| K_INT IDENTIFIER SEMICOLON {
			std::string name = std::move(*$2);
			//delete $2;

			$$ = new VarDecl(
				name,
				"int",
				nullptr,
				@1.begin.line,
				@1.begin.column
			);
		}
		//int declaration with initialization
	| K_INT IDENTIFIER ASSIGN int_expr SEMICOLON {
			std::string name = std::move(*$2);
			//delete $2;
			
			$$ = new VarDecl(
				name, //name
				"int", //type
				$4, //expression
				@1.begin.line,
				@1.begin.column
			);
		}


	//string declation without init
	| K_STRING IDENTIFIER SEMICOLON {
			std::string name = std::move(*$2);
			//delete $2;
			
			$$ = new VarDecl(
				name,
				"string",
				nullptr,
				@1.begin.line,
				@1.begin.column
			);
		}

	| K_STRING IDENTIFIER ASSIGN str_expr SEMICOLON {
			std::string name = std::move(*$2);
			//delete $2;
			
			$$ = new VarDecl(
				name,
				"string",
				$4,
				@1.begin.line,
				@1.begin.column
			);
	}
	;

program
	: /* start of the program */ {
			$$ = new StatementList(RootStatement, 0, 0); //location 0, 0
			driver.root = $$;
		}
	| program statement {
			$1->Add($2);
			$$ = $1;
		}
	;


int_expr
	: L_INT { //literal int, eg. 10, 46
			$$ = new IntLiteral($1, @1.begin.line, @1.begin.column);
		}
	| IDENTIFIER {
			std::string name = *$1;
			//delete $1;
			$$ = new VarRef(name, @1.begin.line, @1.begin.column);
		}
	| int_expr PLUS int_expr { //int plus operation, eg. 40 + 57
			$$ = new BinaryOp($1, $3, '+', @1.begin.line, @1.begin.column);
		}
	| int_expr MINUS int_expr {
			$$ = new BinaryOp($1, $3, '-', @1.begin.line, @1.begin.column);
		}
	;



str_expr
	: L_STRING {
		$$ = new StringLiteral(*$1, @1.begin.line, @1.begin.column);
	}

%%