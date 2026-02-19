%define api.pure full
%define parse.error detailed
%define api.namespace {jaguar::parser}
%define parser.class.name {parser}
%language "c++"

/* includes in the generated header file */
%code requires 
{
#include "../parser/driver.h"
#include "../parser/nodes/ast_node.h"

#include "../parser/nodes/statements/statement.h"
#include "../parser/nodes/statements/statement_list.h"
#include "../parser/nodes/statements/var_decl.h"
#include "../parser/nodes/statements/var_assign.h"
#include "../parser/nodes/statements/func_call.h"

#include "../parser/nodes/expressions/expression.h"
#include "../parser/nodes/expressions/binary_op.h"
#include "../parser/nodes/expressions/var_ref.h"
#include "../parser/nodes/expressions/literal/int_literal.h"
#include "../parser/nodes/expressions/literal/float_literal.h"
#include "../parser/nodes/expressions/literal/string_literal.h"
#include "../parser/nodes/expressions/literal/bool_literal.h"

#include "../parser/nodes/blocks/block_statement.h"
#include "../parser/nodes/blocks/if_statement.h"
#include "../parser/nodes/blocks/func_decl.h"

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
//types
%token K_INT        //int
%token K_FLOAT      //float
%token K_STRING     //string
%token K_BOOL				//bool
%token K_VOID				//void

//block statements
%token K_IF
%token K_ELSE
%token K_WHILE
%token K_FOR_LOOP
%token K_FOR_EACH
%token K_FOR_MAP

//separator tokens
%token LPAREN     //(
%token RPAREN     //)
%token LBRACE     //{
%token RBRACE     //}
%token SEMICOLON  //;
%token COMMA      //,

%token <strval> DECORATOR      //@
%token <strval> PREPROCESSOR   //#

//literals
%token <ival> L_INT   //literal int, eg. 10, 57, ...
%token <fval> L_FLOAT		//literal float, eg. 11.2, 55. , 84.15
%token <strval> L_STRING  //literal string, eg. "hello world!"
%token <ival> L_BOOL  //literal bool, eg. true, false


/* Expressions */
%type <expr> int_expr
%type <expr> float_expr
%type <expr> str_expr
%type <expr> bool_expr

%type <expr> opaque_expr

//return the string of the type
%type <strval> type_spec


//a statement (instruction) produces a Statement object pointer
%type <stmt> statement
%type <stmtList> program

//blocks statement
%type <stmt> block
%type <stmtList> stmt_list


%%


/* an instruction */
statement
	:
		//int declaration without initialization
	type_spec IDENTIFIER SEMICOLON {
			std::string name = std::move(*$2);
			std::string type = std::move(*$1);

			$$ = new VarDecl(
				name,
				type,
				nullptr,
				@1.begin.line,
				@1.begin.column
			);
		}
		//declaration with initialization
	| type_spec IDENTIFIER ASSIGN opaque_expr SEMICOLON {
			std::string name = std::move(*$2);
			std::string type = std::move(*$1);
			//delete $2;
			
			$$ = new VarDecl(
				name, //name
				type, //type
				$4, //expression
				@1.begin.line,
				@1.begin.column
			);
		}

		//assignation after declaration
		| IDENTIFIER ASSIGN opaque_expr SEMICOLON {
			std::string name = std::move(*$1);
			//delete $1;

			$$ = new VarAssign(
				name, //var name
				$3, //expr
				@1.begin.line,
				@1.begin.column
			);
		}

		//Function call
		| IDENTIFIER LPAREN RPAREN SEMICOLON {
			std::string name = std::move(*$1);
			$$ = new FuncCall(
				name,
				@1.begin.line,
				@1.begin.column
			);
		}

	//Bloc statement (with braces {})
	| block {
			$$ = $1;
		}



program
	: /* start of the program */ {
			$$ = new StatementList(0, 0); //location 0, 0
			driver.root = $$;
		}
	| program statement {
			$1->Add($2);
			$$ = $1;
		}
	;

	

/* A block statement */
stmt_list
		: /* empty */ {
				$$ = new StatementList(0, 0);
		}
		| stmt_list statement {
				$1->Add($2);
				$$ = $1;
		}
	;

block
	: LBRACE stmt_list RBRACE {
			$$ = new BlockStatement($2, @1.begin.line, @1.begin.column);
		}

	//if statement
	| K_IF LPAREN bool_expr RPAREN LBRACE stmt_list RBRACE {
			$$ = new IfStatement($6, $3, @1.begin.line, @1.begin.column);
		}

	/* Function Declaration */
	| type_spec IDENTIFIER LPAREN RPAREN LBRACE stmt_list RBRACE {
			std::string name = *$2;
			std::string ret_type = *$1;
			$$ = new FuncDecl(name, ret_type, $6, @1.begin.line, @1.begin.column);
		}
	;


type_spec
	: K_INT {$$ = new std::string("int");}
	| K_FLOAT {$$ = new std::string("float");}
	| K_STRING {$$ = new std::string("string");}
	| K_BOOL {$$ = new std::string("bool");}
	| K_VOID {$$ = new std::string("void");}
	;



int_expr
	: L_INT { //literal int, eg. 10, 46
			$$ = new IntLiteral($1, @1.begin.line, @1.begin.column);
		}
	| LPAREN int_expr RPAREN {
			$$ = $2;
		}
	| IDENTIFIER {
			std::string name = *$1;
			//delete $1;
			$$ = new VarRef(name, @1.begin.line, @1.begin.column);
		}
	| int_expr PLUS int_expr { //int plus operation, eg. 40 + 57
			$$ = new BinaryOp($1, $3, BinaryOp::PLUS, @1.begin.line, @1.begin.column);
		}
	| int_expr MINUS int_expr {
			$$ = new BinaryOp($1, $3, BinaryOp::MINUS, @1.begin.line, @1.begin.column);
		}
	| int_expr STAR int_expr {
			$$ = new BinaryOp($1, $3, BinaryOp::STAR, @1.begin.line, @1.begin.column);
		}
	| int_expr SLASH int_expr {
			$$ = new BinaryOp($1, $3, BinaryOp::SLASH, @1.begin.line, @1.begin.column);
		}
	;

float_expr
	: L_FLOAT {  //literal float
			$$ = new FloatLiteral($1, @1.begin.line, @1.begin.column);
		}
	| LPAREN float_expr RPAREN {
			$$ = $2;
		}
	;


bool_expr
	: L_BOOL {
			$$ = new BoolLiteral($1, @1.begin.line, @1.begin.column);
		}
	| LPAREN bool_expr RPAREN {
			$$ = $2;
		}
	| IDENTIFIER {
			std::string name = *$1;
			$$ = new VarRef(name, @1.begin.line, @1.begin.column);
		}
	| bool_expr AND bool_expr {
			$$ = new BinaryOp($1, $3, BinaryOp::AND, @1.begin.line, @1.begin.column);
		}
	| bool_expr OR bool_expr {
			$$ = new BinaryOp($1, $3, BinaryOp::OR, @1.begin.line, @1.begin.column);
		}
	;

str_expr
	: L_STRING {
		$$ = new StringLiteral(*$1, @1.begin.line, @1.begin.column);
		}
	| IDENTIFIER {
			std::string name = *$1;
			//delete $1;
			$$ = new VarRef(name, @1.begin.line, @1.begin.column);
		}
	;


opaque_expr
	: int_expr { $$ = $1; }
	| float_expr { $$ = $1; }
	| bool_expr { $$ = $1; }
	| str_expr { $$ = $1; }
	;


%%