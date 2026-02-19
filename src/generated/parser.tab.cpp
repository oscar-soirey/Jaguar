// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 46 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory>
#include "../parser/parser.h"

#line 49 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"


#include "parser.tab.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 3 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
namespace jaguar { namespace parser {
#line 147 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"

  /// Build a parser object.
  parser::parser (Driver& driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}


  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // statement: type_spec IDENTIFIER SEMICOLON
#line 165 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                       {
			std::string name = std::move(*(yystack_[1].value.strval));
			std::string type = std::move(*(yystack_[2].value.strval));

			(yylhs.value.stmt) = new VarDecl(
				name,
				type,
				nullptr,
				yystack_[2].location.begin.line,
				yystack_[2].location.begin.column
			);
		}
#line 631 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 3: // statement: type_spec IDENTIFIER ASSIGN opaque_expr SEMICOLON
#line 178 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                                            {
			std::string name = std::move(*(yystack_[3].value.strval));
			std::string type = std::move(*(yystack_[4].value.strval));
			//delete $2;
			
			(yylhs.value.stmt) = new VarDecl(
				name, //name
				type, //type
				(yystack_[1].value.expr), //expression
				yystack_[4].location.begin.line,
				yystack_[4].location.begin.column
			);
		}
#line 649 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 4: // statement: IDENTIFIER ASSIGN opaque_expr SEMICOLON
#line 193 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                                          {
			std::string name = std::move(*(yystack_[3].value.strval));
			//delete $1;

			(yylhs.value.stmt) = new VarAssign(
				name, //var name
				(yystack_[1].value.expr), //expr
				yystack_[3].location.begin.line,
				yystack_[3].location.begin.column
			);
		}
#line 665 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 5: // statement: IDENTIFIER LPAREN RPAREN SEMICOLON
#line 206 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                                     {
			std::string name = std::move(*(yystack_[3].value.strval));
			(yylhs.value.stmt) = new FuncCall(
				name,
				yystack_[3].location.begin.line,
				yystack_[3].location.begin.column
			);
		}
#line 678 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 6: // statement: block
#line 216 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                {
			(yylhs.value.stmt) = (yystack_[0].value.stmt);
		}
#line 686 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 7: // program: %empty
#line 223 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                     {
			(yylhs.value.stmtList) = new StatementList(0, 0); //location 0, 0
			driver.root = (yylhs.value.stmtList);
		}
#line 695 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 8: // program: program statement
#line 227 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                            {
			(yystack_[1].value.stmtList)->Add((yystack_[0].value.stmt));
			(yylhs.value.stmtList) = (yystack_[1].value.stmtList);
		}
#line 704 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 9: // stmt_list: %empty
#line 237 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                              {
				(yylhs.value.stmtList) = new StatementList(0, 0);
		}
#line 712 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 10: // stmt_list: stmt_list statement
#line 240 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                      {
				(yystack_[1].value.stmtList)->Add((yystack_[0].value.stmt));
				(yylhs.value.stmtList) = (yystack_[1].value.stmtList);
		}
#line 721 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 11: // block: LBRACE stmt_list RBRACE
#line 247 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                  {
			(yylhs.value.stmt) = new BlockStatement((yystack_[1].value.stmtList), yystack_[2].location.begin.line, yystack_[2].location.begin.column);
		}
#line 729 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 12: // block: K_IF LPAREN bool_expr RPAREN LBRACE stmt_list RBRACE
#line 252 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                                               {
			(yylhs.value.stmt) = new IfStatement((yystack_[1].value.stmtList), (yystack_[4].value.expr), yystack_[6].location.begin.line, yystack_[6].location.begin.column);
		}
#line 737 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 13: // block: type_spec IDENTIFIER LPAREN RPAREN LBRACE stmt_list RBRACE
#line 257 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                                                     {
			std::string name = *(yystack_[5].value.strval);
			std::string ret_type = *(yystack_[6].value.strval);
			(yylhs.value.stmt) = new FuncDecl(name, ret_type, (yystack_[1].value.stmtList), yystack_[6].location.begin.line, yystack_[6].location.begin.column);
		}
#line 747 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 14: // type_spec: K_INT
#line 266 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                {(yylhs.value.strval) = new std::string("int");}
#line 753 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 15: // type_spec: K_FLOAT
#line 267 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                  {(yylhs.value.strval) = new std::string("float");}
#line 759 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 16: // type_spec: K_STRING
#line 268 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                   {(yylhs.value.strval) = new std::string("string");}
#line 765 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 17: // type_spec: K_BOOL
#line 269 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                 {(yylhs.value.strval) = new std::string("bool");}
#line 771 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 18: // type_spec: K_VOID
#line 270 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                 {(yylhs.value.strval) = new std::string("void");}
#line 777 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 19: // int_expr: L_INT
#line 276 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                { //literal int, eg. 10, 46
			(yylhs.value.expr) = new IntLiteral((yystack_[0].value.ival), yystack_[0].location.begin.line, yystack_[0].location.begin.column);
		}
#line 785 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 20: // int_expr: LPAREN int_expr RPAREN
#line 279 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                 {
			(yylhs.value.expr) = (yystack_[1].value.expr);
		}
#line 793 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 21: // int_expr: IDENTIFIER
#line 282 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                     {
			std::string name = *(yystack_[0].value.strval);
			//delete $1;
			(yylhs.value.expr) = new VarRef(name, yystack_[0].location.begin.line, yystack_[0].location.begin.column);
		}
#line 803 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 22: // int_expr: int_expr PLUS int_expr
#line 287 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                 { //int plus operation, eg. 40 + 57
			(yylhs.value.expr) = new BinaryOp((yystack_[2].value.expr), (yystack_[0].value.expr), BinaryOp::PLUS, yystack_[2].location.begin.line, yystack_[2].location.begin.column);
		}
#line 811 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 23: // int_expr: int_expr MINUS int_expr
#line 290 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                  {
			(yylhs.value.expr) = new BinaryOp((yystack_[2].value.expr), (yystack_[0].value.expr), BinaryOp::MINUS, yystack_[2].location.begin.line, yystack_[2].location.begin.column);
		}
#line 819 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 24: // int_expr: int_expr STAR int_expr
#line 293 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                 {
			(yylhs.value.expr) = new BinaryOp((yystack_[2].value.expr), (yystack_[0].value.expr), BinaryOp::STAR, yystack_[2].location.begin.line, yystack_[2].location.begin.column);
		}
#line 827 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 25: // int_expr: int_expr SLASH int_expr
#line 296 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                  {
			(yylhs.value.expr) = new BinaryOp((yystack_[2].value.expr), (yystack_[0].value.expr), BinaryOp::SLASH, yystack_[2].location.begin.line, yystack_[2].location.begin.column);
		}
#line 835 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 26: // float_expr: L_FLOAT
#line 302 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                  {  //literal float
			(yylhs.value.expr) = new FloatLiteral((yystack_[0].value.fval), yystack_[0].location.begin.line, yystack_[0].location.begin.column);
		}
#line 843 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 27: // float_expr: LPAREN float_expr RPAREN
#line 305 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                   {
			(yylhs.value.expr) = (yystack_[1].value.expr);
		}
#line 851 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 28: // bool_expr: L_BOOL
#line 312 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                 {
			(yylhs.value.expr) = new BoolLiteral((yystack_[0].value.ival), yystack_[0].location.begin.line, yystack_[0].location.begin.column);
		}
#line 859 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 29: // bool_expr: LPAREN bool_expr RPAREN
#line 315 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                  {
			(yylhs.value.expr) = (yystack_[1].value.expr);
		}
#line 867 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 30: // bool_expr: IDENTIFIER
#line 318 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                     {
			std::string name = *(yystack_[0].value.strval);
			(yylhs.value.expr) = new VarRef(name, yystack_[0].location.begin.line, yystack_[0].location.begin.column);
		}
#line 876 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 31: // bool_expr: bool_expr AND bool_expr
#line 322 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                  {
			(yylhs.value.expr) = new BinaryOp((yystack_[2].value.expr), (yystack_[0].value.expr), BinaryOp::AND, yystack_[2].location.begin.line, yystack_[2].location.begin.column);
		}
#line 884 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 32: // bool_expr: bool_expr OR bool_expr
#line 325 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                                 {
			(yylhs.value.expr) = new BinaryOp((yystack_[2].value.expr), (yystack_[0].value.expr), BinaryOp::OR, yystack_[2].location.begin.line, yystack_[2].location.begin.column);
		}
#line 892 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 33: // str_expr: L_STRING
#line 331 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                   {
		(yylhs.value.expr) = new StringLiteral(*(yystack_[0].value.strval), yystack_[0].location.begin.line, yystack_[0].location.begin.column);
		}
#line 900 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 34: // str_expr: IDENTIFIER
#line 334 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                     {
			std::string name = *(yystack_[0].value.strval);
			//delete $1;
			(yylhs.value.expr) = new VarRef(name, yystack_[0].location.begin.line, yystack_[0].location.begin.column);
		}
#line 910 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 35: // opaque_expr: int_expr
#line 343 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                   { (yylhs.value.expr) = (yystack_[0].value.expr); }
#line 916 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 36: // opaque_expr: float_expr
#line 344 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                     { (yylhs.value.expr) = (yystack_[0].value.expr); }
#line 922 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 37: // opaque_expr: bool_expr
#line 345 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                    { (yylhs.value.expr) = (yystack_[0].value.expr); }
#line 928 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;

  case 38: // opaque_expr: str_expr
#line 346 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
                   { (yylhs.value.expr) = (yystack_[0].value.expr); }
#line 934 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"
    break;


#line 938 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "PLUS", "MINUS", "STAR",
  "SLASH", "ASSIGN", "EQ", "NE", "LT", "LE", "GT", "GE", "AND", "OR",
  "UMINUS", "NOT", "IDENTIFIER", "K_INT", "K_FLOAT", "K_STRING", "K_BOOL",
  "K_VOID", "K_IF", "K_ELSE", "K_WHILE", "K_FOR_LOOP", "K_FOR_EACH",
  "K_FOR_MAP", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON",
  "COMMA", "DECORATOR", "PREPROCESSOR", "L_INT", "L_FLOAT", "L_STRING",
  "L_BOOL", "$accept", "statement", "program", "stmt_list", "block",
  "type_spec", "int_expr", "float_expr", "bool_expr", "str_expr",
  "opaque_expr", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -60;

  const signed char parser::yytable_ninf_ = -31;

  const signed char
  parser::yypact_[] =
  {
     -60,     9,   -60,    13,   -60,   -60,   -60,   -60,   -60,   -12,
     -60,   -60,   -60,    -8,    18,    -9,    19,    55,    10,     1,
      24,   -60,   -60,   -60,   -60,    65,   -60,    31,   -60,    21,
      27,   -60,    19,   -10,   -60,   -60,    18,    16,   -60,     1,
       8,    22,    36,    34,    34,    34,    34,    19,    19,   -60,
     -60,    57,    32,    58,   -60,   -60,   -60,   -60,    34,    -4,
      -4,   -60,   -60,   -60,    77,   -60,   -60,   -60,    62,    78,
     -60,   -60
  };

  const signed char
  parser::yydefact_[] =
  {
       7,     0,     1,     0,    14,    15,    16,    17,    18,     0,
       9,     8,     6,     0,     0,     0,     0,     0,     0,    21,
       0,    19,    26,    33,    28,    35,    36,    37,    38,     0,
       0,    30,     0,     0,    11,    10,     0,     0,     2,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,    20,    27,    29,    21,     0,    22,
      23,    24,    25,    31,    32,     9,     3,     9,     0,     0,
      12,    13
  };

  const signed char
  parser::yypgoto_[] =
  {
     -60,    91,   -60,   -59,   -60,   -60,   -20,    73,   -13,   -60,
      67
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,    35,     1,    17,    12,    13,    25,    26,    27,    28,
      29
  };

  const signed char
  parser::yytable_[] =
  {
      40,    45,    46,    33,    47,    48,    68,    42,    69,     2,
      18,    43,    44,    45,    46,   -30,   -30,    36,    16,    42,
      14,    51,    30,    59,    60,    61,    62,     3,     4,     5,
       6,     7,     8,     9,    63,    64,    19,    31,    40,    54,
      37,    10,    39,    15,    38,    47,    48,    53,    20,    32,
      47,    48,    57,    55,    20,    49,    21,    22,    23,    24,
      24,    50,    21,    22,    58,    24,    66,    56,    43,    44,
      45,    46,    21,     3,     4,     5,     6,     7,     8,     9,
       3,     4,     5,     6,     7,     8,     9,    10,    34,    65,
      67,    47,    11,    41,    10,    70,     3,     4,     5,     6,
       7,     8,     9,    52,     0,     0,     0,     0,     0,     0,
      10,    71
  };

  const signed char
  parser::yycheck_[] =
  {
      20,     5,     6,    16,    14,    15,    65,    20,    67,     0,
      18,     3,     4,     5,     6,    14,    15,     7,    30,    32,
       7,    31,    31,    43,    44,    45,    46,    18,    19,    20,
      21,    22,    23,    24,    47,    48,    18,    18,    58,    31,
      30,    32,    18,    30,    34,    14,    15,    31,    30,    30,
      14,    15,    18,    31,    30,    34,    38,    39,    40,    41,
      41,    34,    38,    39,    30,    41,    34,    31,     3,     4,
       5,     6,    38,    18,    19,    20,    21,    22,    23,    24,
      18,    19,    20,    21,    22,    23,    24,    32,    33,    32,
      32,    14,     1,    20,    32,    33,    18,    19,    20,    21,
      22,    23,    24,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33
  };

  const signed char
  parser::yystos_[] =
  {
       0,    44,     0,    18,    19,    20,    21,    22,    23,    24,
      32,    43,    46,    47,     7,    30,    30,    45,    18,    18,
      30,    38,    39,    40,    41,    48,    49,    50,    51,    52,
      31,    18,    30,    50,    33,    43,     7,    30,    34,    18,
      48,    49,    50,     3,     4,     5,     6,    14,    15,    34,
      34,    31,    52,    31,    31,    31,    31,    18,    30,    48,
      48,    48,    48,    50,    50,    32,    34,    32,    45,    45,
      33,    33
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    42,    43,    43,    43,    43,    43,    44,    44,    45,
      45,    46,    46,    46,    47,    47,    47,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    49,    49,    50,    50,
      50,    50,    50,    51,    51,    52,    52,    52,    52
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,     5,     4,     4,     1,     0,     2,     0,
       2,     3,     7,     7,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     3,     3,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     1,     1,     1,     1,     1
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   165,   165,   178,   193,   206,   216,   223,   227,   237,
     240,   247,   252,   257,   266,   267,   268,   269,   270,   276,
     279,   282,   287,   290,   293,   296,   302,   305,   312,   315,
     318,   322,   325,   331,   334,   343,   344,   345,   346
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
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
      35,    36,    37,    38,    39,    40,    41
    };
    // Last valid token kind.
    const int code_max = 296;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 3 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
} } // jaguar::parser
#line 1464 "E:/Code/Horizon/Jaguar/src/generated/parser.tab.cpp"

#line 350 "E:/Code/Horizon/Jaguar/src/parser/jaguar.y"
