// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 71 "./parser.yy"

    #include "ParserDriver.h"

#line 49 "parser.cc"


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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 140 "parser.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (ParserDriver &driver_yyarg, yyscan_t yyscanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg),
      yyscanner (yyscanner_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



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

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 105: // arg
        value.YY_MOVE_OR_COPY< AstArgument * > (YY_MOVE (that.value));
        break;

      case 102: // atom
        value.YY_MOVE_OR_COPY< AstAtom * > (YY_MOVE (that.value));
        break;

      case 90: // fact
        value.YY_MOVE_OR_COPY< AstClause * > (YY_MOVE (that.value));
        break;

      case 106: // component
      case 107: // component_head
      case 111: // component_body
        value.YY_MOVE_OR_COPY< AstComponent * > (YY_MOVE (that.value));
        break;

      case 112: // comp_init
        value.YY_MOVE_OR_COPY< AstComponentInit * > (YY_MOVE (that.value));
        break;

      case 108: // comp_type
        value.YY_MOVE_OR_COPY< AstComponentType * > (YY_MOVE (that.value));
        break;

      case 103: // constraint
        value.YY_MOVE_OR_COPY< AstConstraint * > (YY_MOVE (that.value));
        break;

      case 5: // "number"
        value.YY_MOVE_OR_COPY< AstDomain > (YY_MOVE (that.value));
        break;

      case 99: // exec_order_list
      case 100: // non_empty_exec_order_list
        value.YY_MOVE_OR_COPY< AstExecutionOrder * > (YY_MOVE (that.value));
        break;

      case 97: // exec_plan
      case 98: // exec_plan_list
        value.YY_MOVE_OR_COPY< AstExecutionPlan * > (YY_MOVE (that.value));
        break;

      case 113: // functor_decl
        value.YY_MOVE_OR_COPY< AstFunctorDeclaration * > (YY_MOVE (that.value));
        break;

      case 116: // pragma
        value.YY_MOVE_OR_COPY< AstPragma * > (YY_MOVE (that.value));
        break;

      case 84: // non_empty_record_type_list
        value.YY_MOVE_OR_COPY< AstRecordType * > (YY_MOVE (that.value));
        break;

      case 83: // type
        value.YY_MOVE_OR_COPY< AstType * > (YY_MOVE (that.value));
        break;

      case 85: // union_type_list
        value.YY_MOVE_OR_COPY< AstUnionType * > (YY_MOVE (that.value));
        break;

      case 94: // body
      case 95: // disjunction
      case 96: // conjunction
      case 101: // term
        value.YY_MOVE_OR_COPY< RuleBody * > (YY_MOVE (that.value));
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 6: // "relational operator"
      case 114: // non_empty_functor_arg_type_list
      case 115: // functor_type
      case 122: // kvp_value
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 104: // non_empty_arg_list
        value.YY_MOVE_OR_COPY< std::vector<AstArgument *> > (YY_MOVE (that.value));
        break;

      case 93: // head
        value.YY_MOVE_OR_COPY< std::vector<AstAtom *> > (YY_MOVE (that.value));
        break;

      case 88: // non_empty_attributes
        value.YY_MOVE_OR_COPY< std::vector<AstAttribute *> > (YY_MOVE (that.value));
        break;

      case 91: // rule
      case 92: // rule_def
        value.YY_MOVE_OR_COPY< std::vector<AstClause *> > (YY_MOVE (that.value));
        break;

      case 119: // io_directive_list
      case 120: // io_relation_list
        value.YY_MOVE_OR_COPY< std::vector<AstIO *> > (YY_MOVE (that.value));
        break;

      case 117: // load_head
        value.YY_MOVE_OR_COPY< std::vector<AstLoad *> > (YY_MOVE (that.value));
        break;

      case 86: // relation_decl
      case 87: // relation_list
        value.YY_MOVE_OR_COPY< std::vector<AstRelation *> > (YY_MOVE (that.value));
        break;

      case 118: // store_head
        value.YY_MOVE_OR_COPY< std::vector<AstStore *> > (YY_MOVE (that.value));
        break;

      case 109: // type_params
      case 110: // type_param_list
        value.YY_MOVE_OR_COPY< std::vector<AstTypeIdentifier> > (YY_MOVE (that.value));
        break;

      case 121: // non_empty_key_value_pairs
        value.YY_MOVE_OR_COPY< std::vector<std::pair
            <std::string, std::string>> > (YY_MOVE (that.value));
        break;

      case 82: // identifier
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case 89: // qualifiers
        value.YY_MOVE_OR_COPY< uint32_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 105: // arg
        value.move< AstArgument * > (YY_MOVE (that.value));
        break;

      case 102: // atom
        value.move< AstAtom * > (YY_MOVE (that.value));
        break;

      case 90: // fact
        value.move< AstClause * > (YY_MOVE (that.value));
        break;

      case 106: // component
      case 107: // component_head
      case 111: // component_body
        value.move< AstComponent * > (YY_MOVE (that.value));
        break;

      case 112: // comp_init
        value.move< AstComponentInit * > (YY_MOVE (that.value));
        break;

      case 108: // comp_type
        value.move< AstComponentType * > (YY_MOVE (that.value));
        break;

      case 103: // constraint
        value.move< AstConstraint * > (YY_MOVE (that.value));
        break;

      case 5: // "number"
        value.move< AstDomain > (YY_MOVE (that.value));
        break;

      case 99: // exec_order_list
      case 100: // non_empty_exec_order_list
        value.move< AstExecutionOrder * > (YY_MOVE (that.value));
        break;

      case 97: // exec_plan
      case 98: // exec_plan_list
        value.move< AstExecutionPlan * > (YY_MOVE (that.value));
        break;

      case 113: // functor_decl
        value.move< AstFunctorDeclaration * > (YY_MOVE (that.value));
        break;

      case 116: // pragma
        value.move< AstPragma * > (YY_MOVE (that.value));
        break;

      case 84: // non_empty_record_type_list
        value.move< AstRecordType * > (YY_MOVE (that.value));
        break;

      case 83: // type
        value.move< AstType * > (YY_MOVE (that.value));
        break;

      case 85: // union_type_list
        value.move< AstUnionType * > (YY_MOVE (that.value));
        break;

      case 94: // body
      case 95: // disjunction
      case 96: // conjunction
      case 101: // term
        value.move< RuleBody * > (YY_MOVE (that.value));
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 6: // "relational operator"
      case 114: // non_empty_functor_arg_type_list
      case 115: // functor_type
      case 122: // kvp_value
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 104: // non_empty_arg_list
        value.move< std::vector<AstArgument *> > (YY_MOVE (that.value));
        break;

      case 93: // head
        value.move< std::vector<AstAtom *> > (YY_MOVE (that.value));
        break;

      case 88: // non_empty_attributes
        value.move< std::vector<AstAttribute *> > (YY_MOVE (that.value));
        break;

      case 91: // rule
      case 92: // rule_def
        value.move< std::vector<AstClause *> > (YY_MOVE (that.value));
        break;

      case 119: // io_directive_list
      case 120: // io_relation_list
        value.move< std::vector<AstIO *> > (YY_MOVE (that.value));
        break;

      case 117: // load_head
        value.move< std::vector<AstLoad *> > (YY_MOVE (that.value));
        break;

      case 86: // relation_decl
      case 87: // relation_list
        value.move< std::vector<AstRelation *> > (YY_MOVE (that.value));
        break;

      case 118: // store_head
        value.move< std::vector<AstStore *> > (YY_MOVE (that.value));
        break;

      case 109: // type_params
      case 110: // type_param_list
        value.move< std::vector<AstTypeIdentifier> > (YY_MOVE (that.value));
        break;

      case 121: // non_empty_key_value_pairs
        value.move< std::vector<std::pair
            <std::string, std::string>> > (YY_MOVE (that.value));
        break;

      case 82: // identifier
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      case 89: // qualifiers
        value.move< uint32_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 105: // arg
        value.copy< AstArgument * > (that.value);
        break;

      case 102: // atom
        value.copy< AstAtom * > (that.value);
        break;

      case 90: // fact
        value.copy< AstClause * > (that.value);
        break;

      case 106: // component
      case 107: // component_head
      case 111: // component_body
        value.copy< AstComponent * > (that.value);
        break;

      case 112: // comp_init
        value.copy< AstComponentInit * > (that.value);
        break;

      case 108: // comp_type
        value.copy< AstComponentType * > (that.value);
        break;

      case 103: // constraint
        value.copy< AstConstraint * > (that.value);
        break;

      case 5: // "number"
        value.copy< AstDomain > (that.value);
        break;

      case 99: // exec_order_list
      case 100: // non_empty_exec_order_list
        value.copy< AstExecutionOrder * > (that.value);
        break;

      case 97: // exec_plan
      case 98: // exec_plan_list
        value.copy< AstExecutionPlan * > (that.value);
        break;

      case 113: // functor_decl
        value.copy< AstFunctorDeclaration * > (that.value);
        break;

      case 116: // pragma
        value.copy< AstPragma * > (that.value);
        break;

      case 84: // non_empty_record_type_list
        value.copy< AstRecordType * > (that.value);
        break;

      case 83: // type
        value.copy< AstType * > (that.value);
        break;

      case 85: // union_type_list
        value.copy< AstUnionType * > (that.value);
        break;

      case 94: // body
      case 95: // disjunction
      case 96: // conjunction
      case 101: // term
        value.copy< RuleBody * > (that.value);
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 6: // "relational operator"
      case 114: // non_empty_functor_arg_type_list
      case 115: // functor_type
      case 122: // kvp_value
        value.copy< std::string > (that.value);
        break;

      case 104: // non_empty_arg_list
        value.copy< std::vector<AstArgument *> > (that.value);
        break;

      case 93: // head
        value.copy< std::vector<AstAtom *> > (that.value);
        break;

      case 88: // non_empty_attributes
        value.copy< std::vector<AstAttribute *> > (that.value);
        break;

      case 91: // rule
      case 92: // rule_def
        value.copy< std::vector<AstClause *> > (that.value);
        break;

      case 119: // io_directive_list
      case 120: // io_relation_list
        value.copy< std::vector<AstIO *> > (that.value);
        break;

      case 117: // load_head
        value.copy< std::vector<AstLoad *> > (that.value);
        break;

      case 86: // relation_decl
      case 87: // relation_list
        value.copy< std::vector<AstRelation *> > (that.value);
        break;

      case 118: // store_head
        value.copy< std::vector<AstStore *> > (that.value);
        break;

      case 109: // type_params
      case 110: // type_param_list
        value.copy< std::vector<AstTypeIdentifier> > (that.value);
        break;

      case 121: // non_empty_key_value_pairs
        value.copy< std::vector<std::pair
            <std::string, std::string>> > (that.value);
        break;

      case 82: // identifier
        value.copy< std::vector<std::string> > (that.value);
        break;

      case 89: // qualifiers
        value.copy< uint32_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 105: // arg
        value.move< AstArgument * > (that.value);
        break;

      case 102: // atom
        value.move< AstAtom * > (that.value);
        break;

      case 90: // fact
        value.move< AstClause * > (that.value);
        break;

      case 106: // component
      case 107: // component_head
      case 111: // component_body
        value.move< AstComponent * > (that.value);
        break;

      case 112: // comp_init
        value.move< AstComponentInit * > (that.value);
        break;

      case 108: // comp_type
        value.move< AstComponentType * > (that.value);
        break;

      case 103: // constraint
        value.move< AstConstraint * > (that.value);
        break;

      case 5: // "number"
        value.move< AstDomain > (that.value);
        break;

      case 99: // exec_order_list
      case 100: // non_empty_exec_order_list
        value.move< AstExecutionOrder * > (that.value);
        break;

      case 97: // exec_plan
      case 98: // exec_plan_list
        value.move< AstExecutionPlan * > (that.value);
        break;

      case 113: // functor_decl
        value.move< AstFunctorDeclaration * > (that.value);
        break;

      case 116: // pragma
        value.move< AstPragma * > (that.value);
        break;

      case 84: // non_empty_record_type_list
        value.move< AstRecordType * > (that.value);
        break;

      case 83: // type
        value.move< AstType * > (that.value);
        break;

      case 85: // union_type_list
        value.move< AstUnionType * > (that.value);
        break;

      case 94: // body
      case 95: // disjunction
      case 96: // conjunction
      case 101: // term
        value.move< RuleBody * > (that.value);
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 6: // "relational operator"
      case 114: // non_empty_functor_arg_type_list
      case 115: // functor_type
      case 122: // kvp_value
        value.move< std::string > (that.value);
        break;

      case 104: // non_empty_arg_list
        value.move< std::vector<AstArgument *> > (that.value);
        break;

      case 93: // head
        value.move< std::vector<AstAtom *> > (that.value);
        break;

      case 88: // non_empty_attributes
        value.move< std::vector<AstAttribute *> > (that.value);
        break;

      case 91: // rule
      case 92: // rule_def
        value.move< std::vector<AstClause *> > (that.value);
        break;

      case 119: // io_directive_list
      case 120: // io_relation_list
        value.move< std::vector<AstIO *> > (that.value);
        break;

      case 117: // load_head
        value.move< std::vector<AstLoad *> > (that.value);
        break;

      case 86: // relation_decl
      case 87: // relation_list
        value.move< std::vector<AstRelation *> > (that.value);
        break;

      case 118: // store_head
        value.move< std::vector<AstStore *> > (that.value);
        break;

      case 109: // type_params
      case 110: // type_param_list
        value.move< std::vector<AstTypeIdentifier> > (that.value);
        break;

      case 121: // non_empty_key_value_pairs
        value.move< std::vector<std::pair
            <std::string, std::string>> > (that.value);
        break;

      case 82: // identifier
        value.move< std::vector<std::string> > (that.value);
        break;

      case 89: // qualifiers
        value.move< uint32_t > (that.value);
        break;

      default:
        break;
    }

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
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
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
  parser::yypop_ (int n)
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
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
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
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (driver, yyscanner));
            yyla.move (yylookahead);
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

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
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
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 105: // arg
        yylhs.value.emplace< AstArgument * > ();
        break;

      case 102: // atom
        yylhs.value.emplace< AstAtom * > ();
        break;

      case 90: // fact
        yylhs.value.emplace< AstClause * > ();
        break;

      case 106: // component
      case 107: // component_head
      case 111: // component_body
        yylhs.value.emplace< AstComponent * > ();
        break;

      case 112: // comp_init
        yylhs.value.emplace< AstComponentInit * > ();
        break;

      case 108: // comp_type
        yylhs.value.emplace< AstComponentType * > ();
        break;

      case 103: // constraint
        yylhs.value.emplace< AstConstraint * > ();
        break;

      case 5: // "number"
        yylhs.value.emplace< AstDomain > ();
        break;

      case 99: // exec_order_list
      case 100: // non_empty_exec_order_list
        yylhs.value.emplace< AstExecutionOrder * > ();
        break;

      case 97: // exec_plan
      case 98: // exec_plan_list
        yylhs.value.emplace< AstExecutionPlan * > ();
        break;

      case 113: // functor_decl
        yylhs.value.emplace< AstFunctorDeclaration * > ();
        break;

      case 116: // pragma
        yylhs.value.emplace< AstPragma * > ();
        break;

      case 84: // non_empty_record_type_list
        yylhs.value.emplace< AstRecordType * > ();
        break;

      case 83: // type
        yylhs.value.emplace< AstType * > ();
        break;

      case 85: // union_type_list
        yylhs.value.emplace< AstUnionType * > ();
        break;

      case 94: // body
      case 95: // disjunction
      case 96: // conjunction
      case 101: // term
        yylhs.value.emplace< RuleBody * > ();
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 6: // "relational operator"
      case 114: // non_empty_functor_arg_type_list
      case 115: // functor_type
      case 122: // kvp_value
        yylhs.value.emplace< std::string > ();
        break;

      case 104: // non_empty_arg_list
        yylhs.value.emplace< std::vector<AstArgument *> > ();
        break;

      case 93: // head
        yylhs.value.emplace< std::vector<AstAtom *> > ();
        break;

      case 88: // non_empty_attributes
        yylhs.value.emplace< std::vector<AstAttribute *> > ();
        break;

      case 91: // rule
      case 92: // rule_def
        yylhs.value.emplace< std::vector<AstClause *> > ();
        break;

      case 119: // io_directive_list
      case 120: // io_relation_list
        yylhs.value.emplace< std::vector<AstIO *> > ();
        break;

      case 117: // load_head
        yylhs.value.emplace< std::vector<AstLoad *> > ();
        break;

      case 86: // relation_decl
      case 87: // relation_list
        yylhs.value.emplace< std::vector<AstRelation *> > ();
        break;

      case 118: // store_head
        yylhs.value.emplace< std::vector<AstStore *> > ();
        break;

      case 109: // type_params
      case 110: // type_param_list
        yylhs.value.emplace< std::vector<AstTypeIdentifier> > ();
        break;

      case 121: // non_empty_key_value_pairs
        yylhs.value.emplace< std::vector<std::pair
            <std::string, std::string>> > ();
        break;

      case 82: // identifier
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      case 89: // qualifiers
        yylhs.value.emplace< uint32_t > ();
        break;

      default:
        break;
    }


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
  case 3:
#line 263 "./parser.yy"
              {
        driver.addType(std::unique_ptr<AstType>(yystack_[0].value.as < AstType * > ()));

        yystack_[0].value.as < AstType * > () = nullptr;
    }
#line 1237 "parser.cc"
    break;

  case 4:
#line 268 "./parser.yy"
                      {
        driver.addFunctorDeclaration(std::unique_ptr<AstFunctorDeclaration>(yystack_[0].value.as < AstFunctorDeclaration * > ()));

        yystack_[0].value.as < AstFunctorDeclaration * > () = nullptr;
    }
#line 1247 "parser.cc"
    break;

  case 5:
#line 273 "./parser.yy"
                       {
        for (auto* cur : yystack_[0].value.as < std::vector<AstRelation *> > ()) {
            driver.addRelation(std::unique_ptr<AstRelation>(cur));
        }

        yystack_[0].value.as < std::vector<AstRelation *> > ().clear();
    }
#line 1259 "parser.cc"
    break;

  case 6:
#line 280 "./parser.yy"
                   {
        for (auto* cur : yystack_[0].value.as < std::vector<AstLoad *> > ()) {
            driver.addLoad(std::unique_ptr<AstLoad>(cur));
        }

        yystack_[0].value.as < std::vector<AstLoad *> > ().clear();
    }
#line 1271 "parser.cc"
    break;

  case 7:
#line 287 "./parser.yy"
                    {
        for (auto* cur : yystack_[0].value.as < std::vector<AstStore *> > ()) {
            driver.addStore(std::unique_ptr<AstStore>(cur));
        }

        yystack_[0].value.as < std::vector<AstStore *> > ().clear();
    }
#line 1283 "parser.cc"
    break;

  case 8:
#line 294 "./parser.yy"
              {
        driver.addClause(std::unique_ptr<AstClause>(yystack_[0].value.as < AstClause * > ()));

        yystack_[0].value.as < AstClause * > () = nullptr;
    }
#line 1293 "parser.cc"
    break;

  case 9:
#line 299 "./parser.yy"
              {
        for (auto* cur : yystack_[0].value.as < std::vector<AstClause *> > ()) {
            driver.addClause(std::unique_ptr<AstClause>(cur));
        }

        yystack_[0].value.as < std::vector<AstClause *> > ().clear();
    }
#line 1305 "parser.cc"
    break;

  case 10:
#line 306 "./parser.yy"
                   {
        driver.addComponent(std::unique_ptr<AstComponent>(yystack_[0].value.as < AstComponent * > ()));

        yystack_[0].value.as < AstComponent * > () = nullptr;
    }
#line 1315 "parser.cc"
    break;

  case 11:
#line 311 "./parser.yy"
                   {
        driver.addInstantiation(std::unique_ptr<AstComponentInit>(yystack_[0].value.as < AstComponentInit * > ()));

        yystack_[0].value.as < AstComponentInit * > () = nullptr;
    }
#line 1325 "parser.cc"
    break;

  case 12:
#line 316 "./parser.yy"
                {
        driver.addPragma(std::unique_ptr<AstPragma>(yystack_[0].value.as < AstPragma * > ()));

        yystack_[0].value.as < AstPragma * > () = nullptr;
    }
#line 1335 "parser.cc"
    break;

  case 13:
#line 321 "./parser.yy"
           {
    }
#line 1342 "parser.cc"
    break;

  case 14:
#line 330 "./parser.yy"
          {
        yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ());
    }
#line 1350 "parser.cc"
    break;

  case 15:
#line 334 "./parser.yy"
                                          {
        yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > ();
        yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ());

        yystack_[2].value.as < std::vector<std::string> > ().clear();
    }
#line 1361 "parser.cc"
    break;

  case 16:
#line 348 "./parser.yy"
                      {
        yylhs.value.as < AstType * > () = new AstPrimitiveType(yystack_[0].value.as < std::string > (), true);
        yylhs.value.as < AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1370 "parser.cc"
    break;

  case 17:
#line 352 "./parser.yy"
                      {
        yylhs.value.as < AstType * > () = new AstPrimitiveType(yystack_[0].value.as < std::string > (), false);
        yylhs.value.as < AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1379 "parser.cc"
    break;

  case 18:
#line 356 "./parser.yy"
               {
        yylhs.value.as < AstType * > () = new AstPrimitiveType(yystack_[0].value.as < std::string > ());
        yylhs.value.as < AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1388 "parser.cc"
    break;

  case 19:
#line 360 "./parser.yy"
                                      {
        yylhs.value.as < AstType * > () = yystack_[0].value.as < AstUnionType * > ();
        yylhs.value.as < AstType * > ()->setName(yystack_[2].value.as < std::string > ());
        yylhs.value.as < AstType * > ()->setSrcLoc(yylhs.location);

        yystack_[0].value.as < AstUnionType * > () = nullptr;
    }
#line 1400 "parser.cc"
    break;

  case 20:
#line 367 "./parser.yy"
                                        {
        yylhs.value.as < AstType * > () = new AstRecordType();
        yylhs.value.as < AstType * > ()->setName(yystack_[3].value.as < std::string > ());
        yylhs.value.as < AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1410 "parser.cc"
    break;

  case 21:
#line 372 "./parser.yy"
                                                                   {
        yylhs.value.as < AstType * > () = yystack_[1].value.as < AstRecordType * > ();
        yylhs.value.as < AstType * > ()->setName(yystack_[4].value.as < std::string > ());
        yylhs.value.as < AstType * > ()->setSrcLoc(yylhs.location);

        yystack_[1].value.as < AstRecordType * > () = nullptr;
    }
#line 1422 "parser.cc"
    break;

  case 22:
#line 383 "./parser.yy"
                           {
        yylhs.value.as < AstRecordType * > () = new AstRecordType();
        yylhs.value.as < AstRecordType * > ()->add(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::vector<std::string> > ());
        yylhs.value.as < AstRecordType * > ()->setSrcLoc(yylhs.location);

        yystack_[0].value.as < std::vector<std::string> > ().clear();
    }
#line 1434 "parser.cc"
    break;

  case 23:
#line 390 "./parser.yy"
                                                                         {
        yylhs.value.as < AstRecordType * > () = yystack_[4].value.as < AstRecordType * > ();
        yylhs.value.as < AstRecordType * > ()->add(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::vector<std::string> > ());

        yystack_[4].value.as < AstRecordType * > () = nullptr;
        yystack_[0].value.as < std::vector<std::string> > ().clear();
    }
#line 1446 "parser.cc"
    break;

  case 24:
#line 401 "./parser.yy"
               {
        yylhs.value.as < AstUnionType * > () = new AstUnionType();
        yylhs.value.as < AstUnionType * > ()->add(yystack_[0].value.as < std::vector<std::string> > ());

        yystack_[0].value.as < std::vector<std::string> > ().clear();
    }
#line 1457 "parser.cc"
    break;

  case 25:
#line 407 "./parser.yy"
                                                {
        yylhs.value.as < AstUnionType * > () = yystack_[2].value.as < AstUnionType * > ();
        yylhs.value.as < AstUnionType * > ()->add(yystack_[0].value.as < std::vector<std::string> > ());

        yystack_[0].value.as < std::vector<std::string> > ().clear();
        yystack_[2].value.as < AstUnionType * > () = nullptr;
    }
#line 1469 "parser.cc"
    break;

  case 26:
#line 422 "./parser.yy"
                                                {
        for (auto* rel : yystack_[3].value.as < std::vector<AstRelation *> > ()) {
            rel->setQualifier(yystack_[0].value.as < uint32_t > ());
        }
        yylhs.value.as < std::vector<AstRelation *> > () = yystack_[3].value.as < std::vector<AstRelation *> > ();

        yystack_[3].value.as < std::vector<AstRelation *> > ().clear();
    }
#line 1482 "parser.cc"
    break;

  case 27:
#line 430 "./parser.yy"
                                                                     {
        for (auto* rel : yystack_[4].value.as < std::vector<AstRelation *> > ()) {
            rel->setQualifier(yystack_[0].value.as < uint32_t > ());
            for (auto* attr : yystack_[2].value.as < std::vector<AstAttribute *> > ()) {
                rel->addAttribute(std::unique_ptr<AstAttribute>(attr->clone()));
            }
        }
        yylhs.value.as < std::vector<AstRelation *> > () = yystack_[4].value.as < std::vector<AstRelation *> > ();

        yystack_[4].value.as < std::vector<AstRelation *> > ().clear();
    }
#line 1498 "parser.cc"
    break;

  case 28:
#line 445 "./parser.yy"
          {
        auto* rel = new AstRelation();
        rel->setName(yystack_[0].value.as < std::string > ());
        rel->setSrcLoc(yylhs.location);

        yylhs.value.as < std::vector<AstRelation *> > ().push_back(rel);
    }
#line 1510 "parser.cc"
    break;

  case 29:
#line 452 "./parser.yy"
                                         {
        auto* rel = new AstRelation();
        rel->setName(yystack_[0].value.as < std::string > ());
        rel->setSrcLoc(yystack_[0].location);

        yylhs.value.as < std::vector<AstRelation *> > () = yystack_[2].value.as < std::vector<AstRelation *> > ();
        yylhs.value.as < std::vector<AstRelation *> > ().push_back(rel);

        yystack_[2].value.as < std::vector<AstRelation *> > ().clear();
    }
#line 1525 "parser.cc"
    break;

  case 30:
#line 466 "./parser.yy"
                           {
        auto attr = new AstAttribute(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::vector<std::string> > ());
        attr->setSrcLoc(yystack_[0].location);

        yylhs.value.as < std::vector<AstAttribute *> > ().push_back(attr);

        yystack_[0].value.as < std::vector<std::string> > ().clear();
    }
#line 1538 "parser.cc"
    break;

  case 31:
#line 474 "./parser.yy"
                                                                 {
        auto attr = new AstAttribute(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::vector<std::string> > ());
        attr->setSrcLoc(yystack_[0].location);

        yylhs.value.as < std::vector<AstAttribute *> > () = yystack_[4].value.as < std::vector<AstAttribute *> > ();
        yylhs.value.as < std::vector<AstAttribute *> > ().push_back(attr);

        yystack_[4].value.as < std::vector<AstAttribute *> > ().clear();
        yystack_[0].value.as < std::vector<std::string> > ().clear();
    }
#line 1553 "parser.cc"
    break;

  case 32:
#line 488 "./parser.yy"
                                {
        if(yystack_[1].value.as < uint32_t > () & OUTPUT_RELATION)
            driver.error(yystack_[0].location, "output qualifier already set");
        yylhs.value.as < uint32_t > () = yystack_[1].value.as < uint32_t > () | OUTPUT_RELATION;
    }
#line 1563 "parser.cc"
    break;

  case 33:
#line 493 "./parser.yy"
                               {
        if(yystack_[1].value.as < uint32_t > () & INPUT_RELATION)
            driver.error(yystack_[0].location, "input qualifier already set");
        yylhs.value.as < uint32_t > () = yystack_[1].value.as < uint32_t > () | INPUT_RELATION;
    }
#line 1573 "parser.cc"
    break;

  case 34:
#line 498 "./parser.yy"
                                   {
        if(yystack_[1].value.as < uint32_t > () & PRINTSIZE_RELATION)
            driver.error(yystack_[0].location, "printsize qualifier already set");
        yylhs.value.as < uint32_t > () = yystack_[1].value.as < uint32_t > () | PRINTSIZE_RELATION;
    }
#line 1583 "parser.cc"
    break;

  case 35:
#line 503 "./parser.yy"
                                     {
        if(yystack_[1].value.as < uint32_t > () & OVERRIDABLE_RELATION)
            driver.error(yystack_[0].location, "overridable qualifier already set");
        yylhs.value.as < uint32_t > () = yystack_[1].value.as < uint32_t > () | OVERRIDABLE_RELATION;
    }
#line 1593 "parser.cc"
    break;

  case 36:
#line 508 "./parser.yy"
                                {
        if(yystack_[1].value.as < uint32_t > () & INLINE_RELATION)
            driver.error(yystack_[0].location, "inline qualifier already set");
        yylhs.value.as < uint32_t > () = yystack_[1].value.as < uint32_t > () | INLINE_RELATION;
    }
#line 1603 "parser.cc"
    break;

  case 37:
#line 513 "./parser.yy"
                              {
        if(yystack_[1].value.as < uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION))
            driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as < uint32_t > () = yystack_[1].value.as < uint32_t > () | BRIE_RELATION;
    }
#line 1613 "parser.cc"
    break;

  case 38:
#line 518 "./parser.yy"
                               {
        if(yystack_[1].value.as < uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION))
            driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as < uint32_t > () = yystack_[1].value.as < uint32_t > () | BTREE_RELATION;
    }
#line 1623 "parser.cc"
    break;

  case 39:
#line 523 "./parser.yy"
                               {
        if(yystack_[1].value.as < uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION))
            driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as < uint32_t > () = yystack_[1].value.as < uint32_t > () | EQREL_RELATION;
    }
#line 1633 "parser.cc"
    break;

  case 40:
#line 528 "./parser.yy"
           {
        yylhs.value.as < uint32_t > () = 0;
    }
#line 1641 "parser.cc"
    break;

  case 41:
#line 539 "./parser.yy"
             {
        yylhs.value.as < AstClause * > () = new AstClause();
        yylhs.value.as < AstClause * > ()->setHead(std::unique_ptr<AstAtom>(yystack_[1].value.as < AstAtom * > ()));
        yylhs.value.as < AstClause * > ()->setSrcLoc(yylhs.location);

        yystack_[1].value.as < AstAtom * > () = nullptr;
    }
#line 1653 "parser.cc"
    break;

  case 42:
#line 550 "./parser.yy"
             {
        yylhs.value.as < std::vector<AstClause *> > () = yystack_[0].value.as < std::vector<AstClause *> > ();

        yystack_[0].value.as < std::vector<AstClause *> > ().clear();
    }
#line 1663 "parser.cc"
    break;

  case 43:
#line 555 "./parser.yy"
                             {
        yylhs.value.as < std::vector<AstClause *> > () = yystack_[1].value.as < std::vector<AstClause *> > ();
        for (auto* rule : yylhs.value.as < std::vector<AstClause *> > ()) {
            rule->setFixedExecutionPlan();
        }

        yystack_[1].value.as < std::vector<AstClause *> > ().clear();
    }
#line 1676 "parser.cc"
    break;

  case 44:
#line 563 "./parser.yy"
                                {
        yylhs.value.as < std::vector<AstClause *> > () = yystack_[1].value.as < std::vector<AstClause *> > ();
        for (auto* rule : yylhs.value.as < std::vector<AstClause *> > ()) {
            rule->setExecutionPlan(std::unique_ptr<AstExecutionPlan>(yystack_[0].value.as < AstExecutionPlan * > ()->clone()));
        }

        yystack_[1].value.as < std::vector<AstClause *> > ().clear();
    }
#line 1689 "parser.cc"
    break;

  case 45:
#line 575 "./parser.yy"
                     {
        auto heads = yystack_[3].value.as < std::vector<AstAtom *> > ();
        auto bodies = yystack_[1].value.as < RuleBody * > ()->toClauseBodies();

        bool generated = heads.size() != 1 || bodies.size() != 1;

        for (const auto* head : heads) {
            for (const auto* body : bodies) {
                AstClause* cur = body->clone();
                cur->setHead(std::unique_ptr<AstAtom>(head->clone()));
                cur->setSrcLoc(yylhs.location);
                cur->setGenerated(generated);
                yylhs.value.as < std::vector<AstClause *> > ().push_back(cur);
            }
        }

        for (auto* body : bodies) {
            delete body;
        }
    }
#line 1714 "parser.cc"
    break;

  case 46:
#line 599 "./parser.yy"
         {
        yylhs.value.as < std::vector<AstAtom *> > ().push_back(yystack_[0].value.as < AstAtom * > ());

        yystack_[0].value.as < AstAtom * > () = nullptr;
    }
#line 1724 "parser.cc"
    break;

  case 47:
#line 604 "./parser.yy"
                               {
        yylhs.value.as < std::vector<AstAtom *> > () = yystack_[2].value.as < std::vector<AstAtom *> > ();
        yylhs.value.as < std::vector<AstAtom *> > ().push_back(yystack_[0].value.as < AstAtom * > ());

        yystack_[2].value.as < std::vector<AstAtom *> > ().clear();
        yystack_[0].value.as < AstAtom * > () = nullptr;
    }
#line 1736 "parser.cc"
    break;

  case 48:
#line 615 "./parser.yy"
                {
        yylhs.value.as < RuleBody * > () = yystack_[0].value.as < RuleBody * > ();

        yystack_[0].value.as < RuleBody * > () = nullptr;
    }
#line 1746 "parser.cc"
    break;

  case 49:
#line 624 "./parser.yy"
                {
        yylhs.value.as < RuleBody * > () = yystack_[0].value.as < RuleBody * > ();

        yystack_[0].value.as < RuleBody * > () = nullptr;
    }
#line 1756 "parser.cc"
    break;

  case 50:
#line 629 "./parser.yy"
                                                        {
        yylhs.value.as < RuleBody * > () = yystack_[2].value.as < RuleBody * > ();
        yylhs.value.as < RuleBody * > ()->disjunct(std::move(*yystack_[0].value.as < RuleBody * > ()));

        yystack_[2].value.as < RuleBody * > () = nullptr;
    }
#line 1767 "parser.cc"
    break;

  case 51:
#line 639 "./parser.yy"
         {
        yylhs.value.as < RuleBody * > () = yystack_[0].value.as < RuleBody * > ();

        yystack_[0].value.as < RuleBody * > () = nullptr;
    }
#line 1777 "parser.cc"
    break;

  case 52:
#line 644 "./parser.yy"
                                             {
        yylhs.value.as < RuleBody * > () = yystack_[2].value.as < RuleBody * > ();
        yylhs.value.as < RuleBody * > ()->conjunct(std::move(*yystack_[0].value.as < RuleBody * > ()));

        yystack_[2].value.as < RuleBody * > () = nullptr;
    }
#line 1788 "parser.cc"
    break;

  case 53:
#line 654 "./parser.yy"
                        {
        yylhs.value.as < AstExecutionPlan * > () = yystack_[0].value.as < AstExecutionPlan * > ();

        yystack_[0].value.as < AstExecutionPlan * > () = nullptr;
    }
#line 1798 "parser.cc"
    break;

  case 54:
#line 663 "./parser.yy"
                                               {
        yystack_[1].value.as < AstExecutionOrder * > ()->setSrcLoc(yystack_[2].location);
        yylhs.value.as < AstExecutionPlan * > () = new AstExecutionPlan();
        yylhs.value.as < AstExecutionPlan * > ()->setOrderFor(yystack_[4].value.as < AstDomain > (), std::unique_ptr<AstExecutionOrder>(yystack_[1].value.as < AstExecutionOrder * > ()));

        yystack_[1].value.as < AstExecutionOrder * > () = nullptr;
    }
#line 1810 "parser.cc"
    break;

  case 55:
#line 670 "./parser.yy"
                                                                               {
        yystack_[1].value.as < AstExecutionOrder * > ()->setSrcLoc(yystack_[2].location);
        yylhs.value.as < AstExecutionPlan * > () = yystack_[6].value.as < AstExecutionPlan * > ();
        yylhs.value.as < AstExecutionPlan * > ()->setOrderFor(yystack_[4].value.as < AstDomain > (), std::unique_ptr<AstExecutionOrder>(yystack_[1].value.as < AstExecutionOrder * > ()));

        yystack_[6].value.as < AstExecutionPlan * > () = nullptr;
        yystack_[1].value.as < AstExecutionOrder * > () = nullptr;
    }
#line 1823 "parser.cc"
    break;

  case 56:
#line 682 "./parser.yy"
                              {
        yylhs.value.as < AstExecutionOrder * > () = yystack_[0].value.as < AstExecutionOrder * > ();

        yystack_[0].value.as < AstExecutionOrder * > () = nullptr;
    }
#line 1833 "parser.cc"
    break;

  case 57:
#line 687 "./parser.yy"
           {
        yylhs.value.as < AstExecutionOrder * > () = new AstExecutionOrder();
    }
#line 1841 "parser.cc"
    break;

  case 58:
#line 692 "./parser.yy"
           {
        yylhs.value.as < AstExecutionOrder * > () = new AstExecutionOrder();
        yylhs.value.as < AstExecutionOrder * > ()->appendAtomIndex(yystack_[0].value.as < AstDomain > ());
    }
#line 1850 "parser.cc"
    break;

  case 59:
#line 696 "./parser.yy"
                                                      {
        yylhs.value.as < AstExecutionOrder * > () = yystack_[2].value.as < AstExecutionOrder * > ();
        yylhs.value.as < AstExecutionOrder * > ()->appendAtomIndex(yystack_[0].value.as < AstDomain > ());

        yystack_[2].value.as < AstExecutionOrder * > () = nullptr;
    }
#line 1861 "parser.cc"
    break;

  case 60:
#line 710 "./parser.yy"
         {
        yylhs.value.as < RuleBody * > () = new RuleBody(RuleBody::atom(yystack_[0].value.as < AstAtom * > ()));

        yystack_[0].value.as < AstAtom * > () = nullptr;
    }
#line 1871 "parser.cc"
    break;

  case 61:
#line 715 "./parser.yy"
               {
        yylhs.value.as < RuleBody * > () = new RuleBody(RuleBody::constraint(yystack_[0].value.as < AstConstraint * > ()));

        yystack_[0].value.as < AstConstraint * > () = nullptr;
    }
#line 1881 "parser.cc"
    break;

  case 62:
#line 720 "./parser.yy"
                                  {
        yylhs.value.as < RuleBody * > () = yystack_[0].value.as < RuleBody * > ();
        yylhs.value.as < RuleBody * > ()->negate();

        yystack_[0].value.as < RuleBody * > () = nullptr;
    }
#line 1892 "parser.cc"
    break;

  case 63:
#line 726 "./parser.yy"
                              {
        yylhs.value.as < RuleBody * > () = yystack_[1].value.as < RuleBody * > ();

        yystack_[1].value.as < RuleBody * > () = nullptr;
    }
#line 1902 "parser.cc"
    break;

  case 64:
#line 735 "./parser.yy"
                                                {
        yylhs.value.as < AstAtom * > () = new AstAtom();

        for (auto* arg : yystack_[1].value.as < std::vector<AstArgument *> > ()) {
            yylhs.value.as < AstAtom * > ()->addArgument(std::unique_ptr<AstArgument>(arg));
        }

        yylhs.value.as < AstAtom * > ()->setName(yystack_[3].value.as < std::vector<std::string> > ());
        yylhs.value.as < AstAtom * > ()->setSrcLoc(yylhs.location);

        yystack_[3].value.as < std::vector<std::string> > ().clear();
        yystack_[1].value.as < std::vector<AstArgument *> > ().clear();
    }
#line 1920 "parser.cc"
    break;

  case 65:
#line 748 "./parser.yy"
                             {
        yylhs.value.as < AstAtom * > () = new AstAtom();
        yylhs.value.as < AstAtom * > ()->setName(yystack_[2].value.as < std::vector<std::string> > ());
        yylhs.value.as < AstAtom * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < std::vector<std::string> > ().clear();
    }
#line 1932 "parser.cc"
    break;

  case 66:
#line 760 "./parser.yy"
                               {
        yylhs.value.as < AstConstraint * > () = new AstBinaryConstraint(yystack_[1].value.as < std::string > (),
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstConstraint * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 1946 "parser.cc"
    break;

  case 67:
#line 769 "./parser.yy"
                            {
        yylhs.value.as < AstConstraint * > () = new AstBinaryConstraint(BinaryConstraintOp::LT,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstConstraint * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 1960 "parser.cc"
    break;

  case 68:
#line 778 "./parser.yy"
                            {
        yylhs.value.as < AstConstraint * > () = new AstBinaryConstraint(BinaryConstraintOp::GT,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstConstraint * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 1974 "parser.cc"
    break;

  case 69:
#line 787 "./parser.yy"
                                {
        yylhs.value.as < AstConstraint * > () = new AstBinaryConstraint(BinaryConstraintOp::EQ,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstConstraint * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 1988 "parser.cc"
    break;

  case 70:
#line 798 "./parser.yy"
                                                    {
        yylhs.value.as < AstConstraint * > () = new AstBinaryConstraint(BinaryConstraintOp::MATCH,
                std::unique_ptr<AstArgument>(yystack_[3].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[1].value.as < AstArgument * > ()));
        yylhs.value.as < AstConstraint * > ()->setSrcLoc(yylhs.location);

        yystack_[3].value.as < AstArgument * > () = nullptr;
        yystack_[1].value.as < AstArgument * > () = nullptr;
    }
#line 2002 "parser.cc"
    break;

  case 71:
#line 807 "./parser.yy"
                                                       {
        yylhs.value.as < AstConstraint * > () = new AstBinaryConstraint(BinaryConstraintOp::CONTAINS,
                std::unique_ptr<AstArgument>(yystack_[3].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[1].value.as < AstArgument * > ()));
        yylhs.value.as < AstConstraint * > ()->setSrcLoc(yylhs.location);

        yystack_[3].value.as < AstArgument * > () = nullptr;
        yystack_[1].value.as < AstArgument * > () = nullptr;
    }
#line 2016 "parser.cc"
    break;

  case 72:
#line 818 "./parser.yy"
         {
        yylhs.value.as < AstConstraint * > () = new AstBooleanConstraint(true);
        yylhs.value.as < AstConstraint * > ()->setSrcLoc(yylhs.location);
    }
#line 2025 "parser.cc"
    break;

  case 73:
#line 822 "./parser.yy"
          {
        yylhs.value.as < AstConstraint * > () = new AstBooleanConstraint(false);
        yylhs.value.as < AstConstraint * > ()->setSrcLoc(yylhs.location);
    }
#line 2034 "parser.cc"
    break;

  case 74:
#line 830 "./parser.yy"
        {
        yylhs.value.as < std::vector<AstArgument *> > ().push_back(yystack_[0].value.as < AstArgument * > ());

        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2044 "parser.cc"
    break;

  case 75:
#line 835 "./parser.yy"
                                                {
        yylhs.value.as < std::vector<AstArgument *> > () = yystack_[2].value.as < std::vector<AstArgument *> > ();
        yylhs.value.as < std::vector<AstArgument *> > ().push_back(yystack_[0].value.as < AstArgument * > ());

        yystack_[2].value.as < std::vector<AstArgument *> > ().clear();
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2056 "parser.cc"
    break;

  case 76:
#line 846 "./parser.yy"
           {
        yylhs.value.as < AstArgument * > () = new AstStringConstant(driver.getSymbolTable(), yystack_[0].value.as < std::string > ());
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2065 "parser.cc"
    break;

  case 77:
#line 850 "./parser.yy"
           {
        yylhs.value.as < AstArgument * > () = new AstNumberConstant(yystack_[0].value.as < AstDomain > ());
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2074 "parser.cc"
    break;

  case 78:
#line 854 "./parser.yy"
               {
        yylhs.value.as < AstArgument * > () = new AstUnnamedVariable();
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2083 "parser.cc"
    break;

  case 79:
#line 858 "./parser.yy"
           {
        yylhs.value.as < AstArgument * > () = new AstCounter();
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2092 "parser.cc"
    break;

  case 80:
#line 862 "./parser.yy"
          {
        yylhs.value.as < AstArgument * > () = new AstVariable(yystack_[0].value.as < std::string > ());
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2101 "parser.cc"
    break;

  case 81:
#line 866 "./parser.yy"
                                  {
        yylhs.value.as < AstArgument * > () = yystack_[1].value.as < AstArgument * > ();

        yystack_[1].value.as < AstArgument * > () = nullptr;
    }
#line 2111 "parser.cc"
    break;

  case 82:
#line 873 "./parser.yy"
                                                      {
        yylhs.value.as < AstArgument * > () = new AstTypeCast(std::unique_ptr<AstArgument>(yystack_[3].value.as < AstArgument * > ()), yystack_[1].value.as < std::vector<std::string> > ());
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[3].value.as < AstArgument * > () = nullptr;
        yystack_[1].value.as < std::vector<std::string> > ().clear();
    }
#line 2123 "parser.cc"
    break;

  case 83:
#line 882 "./parser.yy"
        {
        yylhs.value.as < AstArgument * > () = new AstNullConstant();
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2132 "parser.cc"
    break;

  case 84:
#line 887 "./parser.yy"
                      {
        yylhs.value.as < AstArgument * > () = new AstRecordInit();
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2141 "parser.cc"
    break;

  case 85:
#line 891 "./parser.yy"
                                         {
        auto record = new AstRecordInit();

        for (auto* arg : yystack_[1].value.as < std::vector<AstArgument *> > ()) {
            record->add(std::unique_ptr<AstArgument>(arg));
        }

        yylhs.value.as < AstArgument * > () = record;
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[1].value.as < std::vector<AstArgument *> > ().clear();
    }
#line 2158 "parser.cc"
    break;

  case 86:
#line 905 "./parser.yy"
                           {
        auto functor = new AstUserDefinedFunctor();
        functor->setName(yystack_[2].value.as < std::string > ());
        yylhs.value.as < AstArgument * > () = functor;
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2169 "parser.cc"
    break;

  case 87:
#line 911 "./parser.yy"
                                              {
        auto functor = new AstUserDefinedFunctor();
        functor->setName(yystack_[3].value.as < std::string > ());

        for (auto* arg : yystack_[1].value.as < std::vector<AstArgument *> > ()) {
            functor->add(std::unique_ptr<AstArgument>(arg));
        }

        yylhs.value.as < AstArgument * > () = functor;
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[1].value.as < std::vector<AstArgument *> > ().clear();
    }
#line 2187 "parser.cc"
    break;

  case 88:
#line 927 "./parser.yy"
                                    {
        if (const AstNumberConstant* original = dynamic_cast<const AstNumberConstant*>(yystack_[0].value.as < AstArgument * > ())) {
            yylhs.value.as < AstArgument * > () = new AstNumberConstant(-1 * original->getIndex());
            yylhs.value.as < AstArgument * > ()->setSrcLoc(yystack_[0].location);
        } else {
            yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::NEG,
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
            yystack_[0].value.as < AstArgument * > () = nullptr;
            yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);
        }

    }
#line 2204 "parser.cc"
    break;

  case 89:
#line 939 "./parser.yy"
                           {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BNOT,
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2216 "parser.cc"
    break;

  case 90:
#line 946 "./parser.yy"
                           {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LNOT,
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2228 "parser.cc"
    break;

  case 91:
#line 953 "./parser.yy"
                                      {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::ORD,
                std::unique_ptr<AstArgument>(yystack_[1].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[1].value.as < AstArgument * > () = nullptr;
    }
#line 2240 "parser.cc"
    break;

  case 92:
#line 960 "./parser.yy"
                                         {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::STRLEN,
                std::unique_ptr<AstArgument>(yystack_[1].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[1].value.as < AstArgument * > () = nullptr;
    }
#line 2252 "parser.cc"
    break;

  case 93:
#line 967 "./parser.yy"
                                           {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::TONUMBER,
                std::unique_ptr<AstArgument>(yystack_[1].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[1].value.as < AstArgument * > () = nullptr;
    }
#line 2264 "parser.cc"
    break;

  case 94:
#line 974 "./parser.yy"
                                           {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::TOSTRING,
                std::unique_ptr<AstArgument>(yystack_[1].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[1].value.as < AstArgument * > () = nullptr;
    }
#line 2276 "parser.cc"
    break;

  case 95:
#line 983 "./parser.yy"
                              {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::ADD,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2290 "parser.cc"
    break;

  case 96:
#line 992 "./parser.yy"
                               {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::SUB,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2304 "parser.cc"
    break;

  case 97:
#line 1001 "./parser.yy"
                              {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MUL,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2318 "parser.cc"
    break;

  case 98:
#line 1010 "./parser.yy"
                               {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::DIV,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2332 "parser.cc"
    break;

  case 99:
#line 1019 "./parser.yy"
                                 {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MOD,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2346 "parser.cc"
    break;

  case 100:
#line 1028 "./parser.yy"
                               {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::EXP,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2360 "parser.cc"
    break;

  case 101:
#line 1037 "./parser.yy"
                               {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BOR,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2374 "parser.cc"
    break;

  case 102:
#line 1046 "./parser.yy"
                                {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BXOR,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2388 "parser.cc"
    break;

  case 103:
#line 1055 "./parser.yy"
                                {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BAND,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2402 "parser.cc"
    break;

  case 104:
#line 1064 "./parser.yy"
                              {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LOR,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2416 "parser.cc"
    break;

  case 105:
#line 1073 "./parser.yy"
                               {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LAND,
                std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[0].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstArgument * > () = nullptr;
    }
#line 2430 "parser.cc"
    break;

  case 106:
#line 1084 "./parser.yy"
                                                                {
        std::vector<std::unique_ptr<AstArgument>> args;
        args.emplace_back(yystack_[3].value.as < AstArgument * > ());

        for (auto* arg : yystack_[1].value.as < std::vector<AstArgument *> > ()) {
            args.emplace_back(arg);
        }

        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MAX, std::move(args));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[3].value.as < AstArgument * > () = nullptr;
        yystack_[1].value.as < std::vector<AstArgument *> > ().clear();
    }
#line 2449 "parser.cc"
    break;

  case 107:
#line 1098 "./parser.yy"
                                                                {
        std::vector<std::unique_ptr<AstArgument>> args;
        args.emplace_back(yystack_[3].value.as < AstArgument * > ());

        for (auto* arg : yystack_[1].value.as < std::vector<AstArgument *> > ()) {
            args.emplace_back(arg);
        }

        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MIN, std::move(args));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[3].value.as < AstArgument * > () = nullptr;
        yystack_[1].value.as < std::vector<AstArgument *> > ().clear();
    }
#line 2468 "parser.cc"
    break;

  case 108:
#line 1112 "./parser.yy"
                                                                {
        std::vector<std::unique_ptr<AstArgument>> args;
        args.emplace_back(yystack_[3].value.as < AstArgument * > ());

        for (auto* arg : yystack_[1].value.as < std::vector<AstArgument *> > ()) {
            args.emplace_back(arg);
        }

        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::CAT, std::move(args));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[3].value.as < AstArgument * > () = nullptr;
        yystack_[1].value.as < std::vector<AstArgument *> > ().clear();
    }
#line 2487 "parser.cc"
    break;

  case 109:
#line 1128 "./parser.yy"
                                                                       {
        yylhs.value.as < AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::SUBSTR,
                std::unique_ptr<AstArgument>(yystack_[5].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[3].value.as < AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[1].value.as < AstArgument * > ()));
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[5].value.as < AstArgument * > () = nullptr;
        yystack_[3].value.as < AstArgument * > () = nullptr;
        yystack_[1].value.as < AstArgument * > () = nullptr;
    }
#line 2503 "parser.cc"
    break;

  case 110:
#line 1141 "./parser.yy"
                     {
        auto aggr = new AstAggregator(AstAggregator::count);

        aggr->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as < AstAtom * > ()));

        yylhs.value.as < AstArgument * > () = aggr;
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[0].value.as < AstAtom * > () = nullptr;
    }
#line 2518 "parser.cc"
    break;

  case 111:
#line 1151 "./parser.yy"
                                   {
        auto aggr = new AstAggregator(AstAggregator::count);

        auto bodies = yystack_[1].value.as < RuleBody * > ()->toClauseBodies();

        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }

        for (auto& cur : bodies[0]->getBodyLiterals()) {
            aggr->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];

        yylhs.value.as < AstArgument * > () = aggr;
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2541 "parser.cc"
    break;

  case 112:
#line 1170 "./parser.yy"
                                    {
        auto aggr = new AstAggregator(AstAggregator::sum);

        aggr->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()));
        aggr->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as < AstAtom * > ()));

        yylhs.value.as < AstArgument * > () = aggr;
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstAtom * > () = nullptr;
    }
#line 2558 "parser.cc"
    break;

  case 113:
#line 1182 "./parser.yy"
                                                  {
        auto aggr = new AstAggregator(AstAggregator::sum);
        aggr->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[4].value.as < AstArgument * > ()));

        auto bodies = yystack_[1].value.as < RuleBody * > ()->toClauseBodies();

        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }

        for (auto& cur : bodies[0]->getBodyLiterals()) {
            aggr->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];

        yylhs.value.as < AstArgument * > () = aggr;
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[4].value.as < AstArgument * > () = nullptr;
    }
#line 2584 "parser.cc"
    break;

  case 114:
#line 1204 "./parser.yy"
                                    {
        auto aggr = new AstAggregator(AstAggregator::min);

        aggr->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()));
        aggr->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as < AstAtom * > ()));
        yystack_[0].value.as < AstAtom * > () = nullptr;

        yylhs.value.as < AstArgument * > () = aggr;
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstAtom * > () = nullptr;
    }
#line 2602 "parser.cc"
    break;

  case 115:
#line 1217 "./parser.yy"
                                                  {
        auto aggr = new AstAggregator(AstAggregator::min);
        aggr->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[4].value.as < AstArgument * > ()));

        auto bodies = yystack_[1].value.as < RuleBody * > ()->toClauseBodies();

        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }

        for (auto& cur : bodies[0]->getBodyLiterals()) {
            aggr->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];

        yylhs.value.as < AstArgument * > () = aggr;
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[4].value.as < AstArgument * > () = nullptr;
    }
#line 2628 "parser.cc"
    break;

  case 116:
#line 1239 "./parser.yy"
                                    {
        auto aggr = new AstAggregator(AstAggregator::max);

        aggr->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as < AstArgument * > ()));
        aggr->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as < AstAtom * > ()));

        yylhs.value.as < AstArgument * > () = aggr;
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[2].value.as < AstArgument * > () = nullptr;
        yystack_[0].value.as < AstAtom * > () = nullptr;
    }
#line 2645 "parser.cc"
    break;

  case 117:
#line 1251 "./parser.yy"
                                                  {
        auto aggr = new AstAggregator(AstAggregator::max);
        aggr->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[4].value.as < AstArgument * > ()));

        auto bodies = yystack_[1].value.as < RuleBody * > ()->toClauseBodies();

        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }

        for (auto& cur : bodies[0]->getBodyLiterals()) {
            aggr->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];

        yylhs.value.as < AstArgument * > () = aggr;
        yylhs.value.as < AstArgument * > ()->setSrcLoc(yylhs.location);

        yystack_[4].value.as < AstArgument * > () = nullptr;
    }
#line 2671 "parser.cc"
    break;

  case 118:
#line 1280 "./parser.yy"
                                                {
        yylhs.value.as < AstComponent * > () = yystack_[1].value.as < AstComponent * > ();
        auto* type = yystack_[3].value.as < AstComponent * > ()->getComponentType()->clone();
        yylhs.value.as < AstComponent * > ()->setComponentType(std::unique_ptr<AstComponentType>(type));
        yylhs.value.as < AstComponent * > ()->copyBaseComponents(yystack_[3].value.as < AstComponent * > ());
        yylhs.value.as < AstComponent * > ()->setSrcLoc(yylhs.location);

        yystack_[1].value.as < AstComponent * > () = nullptr;
    }
#line 2685 "parser.cc"
    break;

  case 119:
#line 1293 "./parser.yy"
                        {
        yylhs.value.as < AstComponent * > () = new AstComponent();
        yylhs.value.as < AstComponent * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[0].value.as < AstComponentType * > ()));

        yystack_[0].value.as < AstComponentType * > () = nullptr;
    }
#line 2696 "parser.cc"
    break;

  case 120:
#line 1299 "./parser.yy"
                                         {
        yylhs.value.as < AstComponent * > () = yystack_[2].value.as < AstComponent * > ();
        yylhs.value.as < AstComponent * > ()->addBaseComponent(std::unique_ptr<AstComponentType>(yystack_[0].value.as < AstComponentType * > ()));

        yystack_[2].value.as < AstComponent * > () = nullptr;
        yystack_[0].value.as < AstComponentType * > () = nullptr;
    }
#line 2708 "parser.cc"
    break;

  case 121:
#line 1306 "./parser.yy"
                                         {
        yylhs.value.as < AstComponent * > () = yystack_[2].value.as < AstComponent * > ();
        yylhs.value.as < AstComponent * > ()->addBaseComponent(std::unique_ptr<AstComponentType>(yystack_[0].value.as < AstComponentType * > ()));

        yystack_[2].value.as < AstComponent * > () = nullptr;
        yystack_[0].value.as < AstComponentType * > () = nullptr;
    }
#line 2720 "parser.cc"
    break;

  case 122:
#line 1317 "./parser.yy"
                      {
        yylhs.value.as < AstComponentType * > () = new AstComponentType(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<AstTypeIdentifier> > ());

        yystack_[0].value.as < std::vector<AstTypeIdentifier> > ().clear();
    }
#line 2730 "parser.cc"
    break;

  case 123:
#line 1326 "./parser.yy"
                          {
        yylhs.value.as < std::vector<AstTypeIdentifier> > () = yystack_[1].value.as < std::vector<AstTypeIdentifier> > ();

        yystack_[1].value.as < std::vector<AstTypeIdentifier> > ().clear();
    }
#line 2740 "parser.cc"
    break;

  case 124:
#line 1331 "./parser.yy"
           {
        yylhs.value.as < std::vector<AstTypeIdentifier> > () = std::vector<AstTypeIdentifier>();
    }
#line 2748 "parser.cc"
    break;

  case 125:
#line 1338 "./parser.yy"
          {
        yylhs.value.as < std::vector<AstTypeIdentifier> > ().push_back(yystack_[0].value.as < std::string > ());
    }
#line 2756 "parser.cc"
    break;

  case 126:
#line 1341 "./parser.yy"
                                           {
        yylhs.value.as < std::vector<AstTypeIdentifier> > () = yystack_[2].value.as < std::vector<AstTypeIdentifier> > ();
        yylhs.value.as < std::vector<AstTypeIdentifier> > ().push_back(yystack_[0].value.as < std::string > ());

        yystack_[2].value.as < std::vector<AstTypeIdentifier> > ().clear();
    }
#line 2767 "parser.cc"
    break;

  case 127:
#line 1351 "./parser.yy"
                              {
        yylhs.value.as < AstComponent * > () = yystack_[1].value.as < AstComponent * > ();
        yylhs.value.as < AstComponent * > ()->addType(std::unique_ptr<AstType>(yystack_[0].value.as < AstType * > ()));

        yystack_[1].value.as < AstComponent * > () = nullptr;
        yystack_[0].value.as < AstType * > () = nullptr;
    }
#line 2779 "parser.cc"
    break;

  case 128:
#line 1358 "./parser.yy"
                                       {
        yylhs.value.as < AstComponent * > () = yystack_[1].value.as < AstComponent * > ();
        for (auto* rel : yystack_[0].value.as < std::vector<AstRelation *> > ()) {
            yylhs.value.as < AstComponent * > ()->addRelation(std::unique_ptr<AstRelation>(rel));
        }

        yystack_[1].value.as < AstComponent * > () = nullptr;
        yystack_[0].value.as < std::vector<AstRelation *> > ().clear();
    }
#line 2793 "parser.cc"
    break;

  case 129:
#line 1367 "./parser.yy"
                                   {
        yylhs.value.as < AstComponent * > () = yystack_[1].value.as < AstComponent * > ();
        for (auto* io : yystack_[0].value.as < std::vector<AstLoad *> > ()) {
            yylhs.value.as < AstComponent * > ()->addLoad(std::unique_ptr<AstLoad>(io));
        }

        yystack_[1].value.as < AstComponent * > () = nullptr;
        yystack_[0].value.as < std::vector<AstLoad *> > ().clear();
    }
#line 2807 "parser.cc"
    break;

  case 130:
#line 1376 "./parser.yy"
                                    {
        yylhs.value.as < AstComponent * > () = yystack_[1].value.as < AstComponent * > ();
        for (auto* io : yystack_[0].value.as < std::vector<AstStore *> > ()) {
            yylhs.value.as < AstComponent * > ()->addStore(std::unique_ptr<AstStore>(io));
        }

        yystack_[1].value.as < AstComponent * > () = nullptr;
        yystack_[0].value.as < std::vector<AstStore *> > ().clear();
    }
#line 2821 "parser.cc"
    break;

  case 131:
#line 1385 "./parser.yy"
                              {
        yylhs.value.as < AstComponent * > () = yystack_[1].value.as < AstComponent * > ();
        yylhs.value.as < AstComponent * > ()->addClause(std::unique_ptr<AstClause>(yystack_[0].value.as < AstClause * > ()));

        yystack_[1].value.as < AstComponent * > () = nullptr;
        yystack_[0].value.as < AstClause * > () = nullptr;
    }
#line 2833 "parser.cc"
    break;

  case 132:
#line 1392 "./parser.yy"
                              {
        yylhs.value.as < AstComponent * > () = yystack_[1].value.as < AstComponent * > ();
        for (auto* rule : yystack_[0].value.as < std::vector<AstClause *> > ()) {
            yylhs.value.as < AstComponent * > ()->addClause(std::unique_ptr<AstClause>(rule));
        }

        yystack_[1].value.as < AstComponent * > () = nullptr;
        yystack_[0].value.as < std::vector<AstClause *> > ().clear();
    }
#line 2847 "parser.cc"
    break;

  case 133:
#line 1401 "./parser.yy"
                                        {
        yylhs.value.as < AstComponent * > () = yystack_[2].value.as < AstComponent * > ();
        yylhs.value.as < AstComponent * > ()->addOverride(yystack_[0].value.as < std::string > ());

        yystack_[2].value.as < AstComponent * > () = nullptr;
    }
#line 2858 "parser.cc"
    break;

  case 134:
#line 1407 "./parser.yy"
                                   {
        yylhs.value.as < AstComponent * > () = yystack_[1].value.as < AstComponent * > ();
        yylhs.value.as < AstComponent * > ()->addInstantiation(std::unique_ptr<AstComponentInit>(yystack_[0].value.as < AstComponentInit * > ()));

        yystack_[1].value.as < AstComponent * > () = nullptr;
        yystack_[0].value.as < AstComponentInit * > () = nullptr;
    }
#line 2870 "parser.cc"
    break;

  case 135:
#line 1414 "./parser.yy"
                                   {
        yylhs.value.as < AstComponent * > () = yystack_[1].value.as < AstComponent * > ();
        yylhs.value.as < AstComponent * > ()->addComponent(std::unique_ptr<AstComponent>(yystack_[0].value.as < AstComponent * > ()));

        yystack_[1].value.as < AstComponent * > () = nullptr;
        yystack_[0].value.as < AstComponent * > () = nullptr;
    }
#line 2882 "parser.cc"
    break;

  case 136:
#line 1421 "./parser.yy"
           {
        yylhs.value.as < AstComponent * > () = new AstComponent();
    }
#line 2890 "parser.cc"
    break;

  case 137:
#line 1428 "./parser.yy"
                                       {
        yylhs.value.as < AstComponentInit * > () = new AstComponentInit();
        yylhs.value.as < AstComponentInit * > ()->setInstanceName(yystack_[2].value.as < std::string > ());
        yylhs.value.as < AstComponentInit * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[0].value.as < AstComponentType * > ()));
        yylhs.value.as < AstComponentInit * > ()->setSrcLoc(yylhs.location);

        yystack_[0].value.as < AstComponentType * > () = nullptr;
    }
#line 2903 "parser.cc"
    break;

  case 138:
#line 1444 "./parser.yy"
                                                   {
        auto typesig = yystack_[0].value.as < std::string > ();
        yylhs.value.as < AstFunctorDeclaration * > () = new AstFunctorDeclaration(yystack_[4].value.as < std::string > (), typesig);
        yylhs.value.as < AstFunctorDeclaration * > ()->setSrcLoc(yylhs.location);
    }
#line 2913 "parser.cc"
    break;

  case 139:
#line 1449 "./parser.yy"
                                                                                   {
        auto typesig = yystack_[3].value.as < std::string > () + yystack_[0].value.as < std::string > ();
        yylhs.value.as < AstFunctorDeclaration * > () = new AstFunctorDeclaration(yystack_[5].value.as < std::string > (), typesig);
        yylhs.value.as < AstFunctorDeclaration * > ()->setSrcLoc(yylhs.location);
    }
#line 2923 "parser.cc"
    break;

  case 140:
#line 1458 "./parser.yy"
                 {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 2931 "parser.cc"
    break;

  case 141:
#line 1461 "./parser.yy"
                                                                  {
        yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > () + yystack_[0].value.as < std::string > ();
    }
#line 2939 "parser.cc"
    break;

  case 142:
#line 1468 "./parser.yy"
          {
        if (yystack_[0].value.as < std::string > () == "number") {
            yylhs.value.as < std::string > () = "N";
        } else if (yystack_[0].value.as < std::string > () == "symbol") {
            yylhs.value.as < std::string > () = "S";
        } else {
            driver.error(yystack_[0].location, "number or symbol identifier expected");
        }
    }
#line 2953 "parser.cc"
    break;

  case 143:
#line 1485 "./parser.yy"
                                     {
        yylhs.value.as < AstPragma * > () = new AstPragma(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > ());
        yylhs.value.as < AstPragma * > ()->setSrcLoc(yylhs.location);
    }
#line 2962 "parser.cc"
    break;

  case 144:
#line 1489 "./parser.yy"
                          {
        yylhs.value.as < AstPragma * > () = new AstPragma(yystack_[0].value.as < std::string > (), "");
        yylhs.value.as < AstPragma * > ()->setSrcLoc(yylhs.location);
    }
#line 2971 "parser.cc"
    break;

  case 145:
#line 1497 "./parser.yy"
                                 {
        for (const auto* io : yystack_[0].value.as < std::vector<AstIO *> > ()) {
            yylhs.value.as < std::vector<AstLoad *> > ().push_back(new AstLoad(*io));
        }
    }
#line 2981 "parser.cc"
    break;

  case 146:
#line 1506 "./parser.yy"
                                  {
        for (const auto* io : yystack_[0].value.as < std::vector<AstIO *> > ()) {
            yylhs.value.as < std::vector<AstStore *> > ().push_back(new AstStore(*io));
        }
    }
#line 2991 "parser.cc"
    break;

  case 147:
#line 1511 "./parser.yy"
                                     {
        for (const auto* io : yystack_[0].value.as < std::vector<AstIO *> > ()) {
            yylhs.value.as < std::vector<AstStore *> > ().push_back(new AstPrintSize(*io));
        }
    }
#line 3001 "parser.cc"
    break;

  case 148:
#line 1520 "./parser.yy"
                     {
        yylhs.value.as < std::vector<AstIO *> > () = yystack_[0].value.as < std::vector<AstIO *> > ();

        yystack_[0].value.as < std::vector<AstIO *> > ().clear();
    }
#line 3011 "parser.cc"
    break;

  case 149:
#line 1525 "./parser.yy"
                                   {
        yylhs.value.as < std::vector<AstIO *> > () = yystack_[2].value.as < std::vector<AstIO *> > ();

        yystack_[2].value.as < std::vector<AstIO *> > ().clear();
    }
#line 3021 "parser.cc"
    break;

  case 150:
#line 1530 "./parser.yy"
                                                             {
        for (auto* io : yystack_[3].value.as < std::vector<AstIO *> > ()) {
            for (const auto& kvp : yystack_[1].value.as < std::vector<std::pair
            <std::string, std::string>> > ()) {
                io->addKVP(kvp.first, kvp.second);
            }
        }
        yylhs.value.as < std::vector<AstIO *> > () = yystack_[3].value.as < std::vector<AstIO *> > ();

        yystack_[3].value.as < std::vector<AstIO *> > ().clear();
        yystack_[1].value.as < std::vector<std::pair
            <std::string, std::string>> > ().clear();
    }
#line 3039 "parser.cc"
    break;

  case 151:
#line 1545 "./parser.yy"
               {
        auto* io = new AstIO();
        io->setName(yystack_[0].value.as < std::vector<std::string> > ());
        io->setSrcLoc(yystack_[0].location);

        yylhs.value.as < std::vector<AstIO *> > ().push_back(io);

        yystack_[0].value.as < std::vector<std::string> > ().clear();
    }
#line 3053 "parser.cc"
    break;

  case 152:
#line 1554 "./parser.yy"
                                                 {
        auto* io = new AstIO();
        io->setName(yystack_[0].value.as < std::vector<std::string> > ());
        io->setSrcLoc(yystack_[0].location);

        yylhs.value.as < std::vector<AstIO *> > () = yystack_[2].value.as < std::vector<AstIO *> > ();
        yylhs.value.as < std::vector<AstIO *> > ().push_back(io);

        yystack_[2].value.as < std::vector<AstIO *> > ().clear();
        yystack_[0].value.as < std::vector<std::string> > ().clear();
    }
#line 3069 "parser.cc"
    break;

  case 153:
#line 1569 "./parser.yy"
                           {
        yylhs.value.as < std::vector<std::pair
            <std::string, std::string>> > ().push_back(std::make_pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()));
    }
#line 3078 "parser.cc"
    break;

  case 154:
#line 1572 "./parser.yy"
                                                                    {
        yylhs.value.as < std::vector<std::pair
            <std::string, std::string>> > () = yystack_[4].value.as < std::vector<std::pair
            <std::string, std::string>> > ();
        yylhs.value.as < std::vector<std::pair
            <std::string, std::string>> > ().push_back(std::make_pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()));

        yystack_[4].value.as < std::vector<std::pair
            <std::string, std::string>> > ().clear();
    }
#line 3093 "parser.cc"
    break;

  case 155:
#line 1580 "./parser.yy"
           {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 3101 "parser.cc"
    break;

  case 156:
#line 1583 "./parser.yy"
          {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
    }
#line 3109 "parser.cc"
    break;

  case 157:
#line 1586 "./parser.yy"
         {
        yylhs.value.as < std::string > () = "true";
    }
#line 3117 "parser.cc"
    break;

  case 158:
#line 1589 "./parser.yy"
          {
        yylhs.value.as < std::string > () = "false";
    }
#line 3125 "parser.cc"
    break;


#line 3129 "parser.cc"

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
      YY_STACK_PRINT ();

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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
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

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

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
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

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
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -200;

  const signed char parser::yytable_ninf_ = -15;

  const short
  parser::yypact_[] =
  {
    -200,    10,   331,  -200,  -200,    21,    38,    54,   126,   126,
     126,   144,   162,   176,   183,   194,    13,  -200,  -200,  -200,
      99,  -200,   -21,   -48,  -200,    30,  -200,  -200,  -200,  -200,
    -200,    95,  -200,   -22,   119,   152,  -200,    39,  -200,  -200,
     139,   149,  -200,   158,  -200,  -200,   336,   221,  -200,   228,
    -200,   276,   126,  -200,   162,   162,  -200,  -200,     4,   230,
      11,    23,   126,     3,   232,  -200,   162,  -200,  -200,  -200,
     184,   185,   186,   187,   456,   516,   180,   576,   190,   192,
     193,   242,  -200,   140,  -200,  -200,   576,   576,  -200,   576,
     576,    90,   359,  -200,   201,   195,    68,   210,   213,  -200,
    -200,   276,   276,   188,   209,   216,  -200,  -200,  -200,   191,
    -200,  -200,  -200,   169,   212,  -200,   115,  -200,  -200,   217,
     122,  -200,   215,  -200,   155,   152,     8,   152,   227,  -200,
     -40,  -200,   576,   576,   576,   576,   576,   624,   576,   640,
      15,   656,   576,   576,   576,   231,  -200,   -29,   223,   681,
     223,   223,  -200,   576,   576,   576,   576,   576,   576,   576,
     576,   576,   576,   576,   576,   234,   286,   576,   576,  -200,
     -15,     0,  -200,   276,   276,   576,   576,   576,   576,   300,
    -200,  -200,  -200,  -200,    99,  -200,  -200,  -200,  -200,   126,
      94,  -200,   301,   302,   249,   302,    22,  -200,   304,   252,
    -200,   -20,   126,   307,  -200,   698,   723,   748,   765,   583,
      17,   608,    18,   276,  -200,    19,   790,   815,   832,   396,
    -200,  -200,   359,    73,    73,   223,   223,   223,   223,    89,
     104,   219,   479,   419,   308,   254,   849,   866,  -200,   216,
    -200,   359,   359,   359,   359,  -200,   152,  -200,  -200,  -200,
    -200,  -200,  -200,  -200,  -200,    94,   256,  -200,   302,  -200,
    -200,  -200,  -200,  -200,  -200,   253,   126,  -200,   312,   152,
    -200,   576,  -200,  -200,   576,   576,   276,  -200,   576,   276,
    -200,   255,   276,  -200,  -200,  -200,   126,  -200,   159,  -200,
     261,   268,   273,   576,   576,   126,  -200,    22,   152,   274,
     166,   883,   170,   265,   173,   266,  -200,   269,    70,  -200,
    -200,   337,   308,   908,   933,   152,  -200,   126,  -200,   576,
    -200,  -200,  -200,  -200,  -200,  -200,  -200,   280,  -200,  -200,
     152,   958,  -200,  -200
  };

  const unsigned char
  parser::yydefact_[] =
  {
      13,     0,     2,     1,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     5,     8,
       9,    42,     0,    46,    10,     0,    11,     4,    12,     6,
       7,   144,    28,     0,     0,   151,   145,   148,   146,   147,
      18,   124,   119,     0,    16,    17,     0,     0,    43,     0,
      44,     0,     0,    41,     0,     0,   136,   143,     0,     0,
       0,     0,     0,     0,     0,   122,     0,    76,    80,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,    78,    79,     0,     0,    65,     0,
       0,     0,    74,    15,     0,    53,    80,     0,     0,    72,
      73,     0,     0,     0,    48,    49,    51,    60,    61,     0,
      47,   121,   120,     0,     0,    40,     0,    29,   142,     0,
       0,   140,     0,   149,     0,   152,     0,    24,    19,   125,
       0,   137,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,    88,     0,
      89,    90,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
     118,   127,   128,   131,   132,   135,   134,   129,   130,     0,
      26,    40,     0,     0,     0,     0,     0,   150,     0,     0,
      20,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,     0,     0,
      85,    81,    75,    95,    96,    97,    98,   100,    99,   103,
     101,   102,   105,   104,    57,     0,     0,     0,    63,    50,
      52,    66,    69,    67,    68,   133,    30,    32,    33,    34,
      37,    38,    39,    35,    36,    27,     0,   138,     0,   141,
     155,   156,   157,   158,   153,     0,     0,    21,     0,    25,
     126,     0,    91,    92,     0,     0,     0,   114,     0,     0,
     116,     0,     0,   112,    93,    94,     0,    86,     0,    58,
       0,    56,     0,     0,     0,     0,   139,     0,    22,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,    87,
      54,     0,    57,     0,     0,    31,   154,     0,   108,     0,
     107,   115,   106,   117,   113,    82,    59,     0,    70,    71,
      23,     0,    55,   109
  };

  const short
  parser::yypgoto_[] =
  {
    -200,  -200,  -200,    -8,   233,  -200,  -200,   235,  -200,  -200,
     153,   236,   238,  -200,  -200,  -199,   241,   172,  -200,  -200,
      35,  -200,   -96,     9,  -200,   -79,   -43,   239,  -200,   -16,
    -200,  -200,  -200,   260,  -200,  -200,  -177,  -200,   262,   263,
     141,  -200,  -200,    77
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     1,     2,    16,    17,   201,   128,    18,    33,   116,
     190,    19,    20,    21,    22,   103,   104,   105,    50,    95,
     290,   291,   106,   107,   108,    91,   109,    24,    25,    42,
      65,   130,   113,    26,    27,   120,   121,    28,    29,    30,
      36,    37,   124,   264
  };

  const short
  parser::yytable_[] =
  {
      35,    35,    35,    92,   147,   169,   175,     4,   114,    51,
       3,    23,   199,    53,   281,   118,   257,   203,   259,     4,
     220,     4,     4,     4,    31,   260,   261,   122,   153,   267,
     204,   137,   139,    58,   141,    59,    52,   268,   111,   112,
      92,   238,    32,   148,   149,   173,   150,   151,   262,   263,
     131,   126,   154,   155,   125,   127,   221,   200,    34,   171,
     115,   110,   176,   156,   157,   158,   159,   119,    46,   177,
     178,   160,   161,   162,    47,   163,   164,   303,   240,   123,
     305,   296,   213,   307,   276,   279,   282,    54,    55,   205,
     206,   207,   208,   209,    61,   211,    62,    56,    57,   216,
     217,   218,   247,   248,   249,   250,   251,   252,   253,   254,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,    23,   -14,   236,   237,   325,    48,    49,   -14,
       4,    47,   241,   242,   243,   244,   156,   157,   158,   159,
     288,   154,   155,    67,    68,    69,   152,   153,    40,   214,
      38,    39,   156,   157,   158,   159,   154,   155,    70,    71,
      72,    73,    74,    75,    76,    77,    41,   156,   157,   158,
     159,   191,   192,     4,    60,   160,    92,   162,   194,   195,
      43,   246,    78,    79,    80,    81,    82,    44,    83,   146,
      84,    85,   300,    86,   269,    87,   302,   175,    45,   304,
       6,    63,     8,     9,    10,   179,    11,    12,    13,    14,
      15,   197,   198,    47,    89,   309,   153,    90,    64,   277,
      66,   280,   318,   153,   283,    93,   320,   153,    92,   322,
     153,   301,    92,    94,   117,    92,   129,   180,   140,   132,
     133,   134,   135,   154,   155,   142,   145,   143,   144,   172,
     313,   314,   166,   176,   156,   157,   158,   159,   298,   165,
     177,   178,   160,   161,   162,   167,   163,   164,   168,   173,
     189,   154,   155,   174,   202,   193,   331,   196,   308,    67,
      96,    69,   156,   157,   158,   159,   219,   315,   158,   234,
     160,   235,    97,    98,    70,    71,    72,    73,    74,    75,
      76,    77,    99,   100,   245,   256,   118,   258,   265,   330,
     266,   270,   292,   289,   295,   297,   299,   310,    78,    79,
      80,    81,    82,   306,    83,   311,    84,    85,   312,    86,
     101,   102,   317,   321,   323,     4,   332,   324,     5,    67,
      68,    69,   326,   170,   255,   239,   181,   327,   182,   183,
      89,   184,   185,    90,    70,    71,    72,    73,    74,    75,
      76,    77,     6,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,   186,   316,   187,   188,     0,    78,    79,
      80,    81,    82,     0,    83,     0,    84,    85,     0,    86,
       0,    87,    88,     0,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
      89,   154,   155,    90,    70,    71,    72,    73,    74,    75,
      76,    77,   156,   157,   158,   159,     0,     0,     0,     0,
     160,   161,   162,     0,   163,   164,     0,     0,    78,    79,
      80,    81,    82,     0,    83,     0,    84,    85,     0,    86,
       0,    87,   287,     0,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
      89,   154,   155,    90,    70,    71,    72,    73,    74,    75,
      76,    77,   156,   157,   158,   159,     0,     0,     0,     0,
     160,   161,   162,     0,   163,     0,     0,     0,    78,    79,
      80,    81,    82,     0,    83,     0,    84,    85,     0,    86,
       0,   136,     0,     0,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
      89,   154,   155,    90,    70,    71,    72,    73,    74,    75,
      76,    77,   156,   157,   158,   159,     0,     0,     0,     0,
     160,   161,   162,     0,     0,     0,     0,     0,    78,    79,
      80,    81,    82,     0,    83,     0,    84,    85,     0,    86,
       0,   138,     0,     0,     0,     0,     0,     0,     0,    67,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,    90,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
      80,    81,    82,     0,    83,     0,    84,    85,     0,    86,
       0,    87,     0,     0,     0,   154,   155,     0,     0,   221,
     275,     0,     0,     0,     0,     0,   156,   157,   158,   159,
      89,     0,     0,    90,   160,   161,   162,     0,   163,   164,
     154,   155,     0,     0,   221,   278,     0,     0,     0,     0,
       0,   156,   157,   158,   159,     0,   154,   155,     0,   160,
     161,   162,   210,   163,   164,     0,     0,   156,   157,   158,
     159,     0,   154,   155,     0,   160,   161,   162,   212,   163,
     164,     0,     0,   156,   157,   158,   159,     0,   154,   155,
       0,   160,   161,   162,   215,   163,   164,     0,     0,   156,
     157,   158,   159,     0,     0,     0,     0,   160,   161,   162,
       0,   163,   164,   154,   155,     0,     0,   221,     0,     0,
       0,     0,     0,     0,   156,   157,   158,   159,     0,     0,
     154,   155,   160,   161,   162,   271,   163,   164,     0,     0,
       0,   156,   157,   158,   159,     0,     0,     0,     0,   160,
     161,   162,     0,   163,   164,   154,   155,     0,     0,   272,
       0,     0,     0,     0,     0,     0,   156,   157,   158,   159,
       0,     0,     0,     0,   160,   161,   162,     0,   163,   164,
     154,   155,     0,     0,   273,     0,     0,     0,     0,     0,
       0,   156,   157,   158,   159,     0,     0,   154,   155,   160,
     161,   162,   274,   163,   164,     0,     0,     0,   156,   157,
     158,   159,     0,     0,     0,     0,   160,   161,   162,     0,
     163,   164,   154,   155,     0,     0,   284,     0,     0,     0,
       0,     0,     0,   156,   157,   158,   159,     0,     0,     0,
       0,   160,   161,   162,     0,   163,   164,   154,   155,     0,
       0,   285,     0,     0,     0,     0,     0,     0,   156,   157,
     158,   159,     0,     0,   154,   155,   160,   161,   162,   286,
     163,   164,     0,     0,     0,   156,   157,   158,   159,     0,
       0,   154,   155,   160,   161,   162,   293,   163,   164,     0,
       0,     0,   156,   157,   158,   159,     0,     0,   154,   155,
     160,   161,   162,   294,   163,   164,     0,     0,     0,   156,
     157,   158,   159,     0,     0,   154,   155,   160,   161,   162,
     319,   163,   164,     0,     0,     0,   156,   157,   158,   159,
       0,     0,     0,     0,   160,   161,   162,     0,   163,   164,
     154,   155,     0,     0,   328,     0,     0,     0,     0,     0,
       0,   156,   157,   158,   159,     0,     0,     0,     0,   160,
     161,   162,     0,   163,   164,   154,   155,     0,     0,   329,
       0,     0,     0,     0,     0,     0,   156,   157,   158,   159,
       0,     0,     0,     0,   160,   161,   162,     0,   163,   164,
     154,   155,     0,     0,   333,     0,     0,     0,     0,     0,
       0,   156,   157,   158,   159,     0,     0,     0,     0,   160,
     161,   162,     0,   163,   164
  };

  const short
  parser::yycheck_[] =
  {
       8,     9,    10,    46,    83,   101,     6,     4,     4,    30,
       0,     2,     4,    61,   213,     4,   193,    57,   195,     4,
      49,     4,     4,     4,     3,     3,     4,     4,    57,    49,
      70,    74,    75,    55,    77,    57,    57,    57,    54,    55,
      83,    56,     4,    86,    87,    60,    89,    90,    26,    27,
      66,    48,    52,    53,    62,    63,    56,    49,     4,   102,
      56,    52,    62,    63,    64,    65,    66,    56,    55,    69,
      70,    71,    72,    73,    61,    75,    76,   276,   174,    56,
     279,   258,    67,   282,    67,    67,    67,    57,    58,   132,
     133,   134,   135,   136,    55,   138,    57,    67,     3,   142,
     143,   144,     8,     9,    10,    11,    12,    13,    14,    15,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   113,    55,   167,   168,    56,    28,    29,    61,
       4,    61,   175,   176,   177,   178,    63,    64,    65,    66,
     219,    52,    53,     3,     4,     5,    56,    57,     4,   140,
       9,    10,    63,    64,    65,    66,    52,    53,    18,    19,
      20,    21,    22,    23,    24,    25,     4,    63,    64,    65,
      66,    56,    57,     4,    55,    71,   219,    73,    56,    57,
       4,   189,    42,    43,    44,    45,    46,     4,    48,    49,
      50,    51,   271,    53,   202,    55,   275,     6,     4,   278,
      31,    62,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    56,    57,    61,    74,    56,    57,    77,    69,   210,
      62,   212,    56,    57,   215,     4,    56,    57,   271,    56,
      57,   274,   275,     5,     4,   278,     4,    68,    58,    55,
      55,    55,    55,    52,    53,    55,     4,    55,    55,    61,
     293,   294,    57,    62,    63,    64,    65,    66,   266,    58,
      69,    70,    71,    72,    73,    55,    75,    76,    55,    60,
      58,    52,    53,    57,    47,    58,   319,    62,   286,     3,
       4,     5,    63,    64,    65,    66,    55,   295,    65,    55,
      71,     5,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     4,     4,     4,    58,     4,   317,
      58,     4,    58,     5,    58,    62,     4,    56,    42,    43,
      44,    45,    46,    68,    48,    57,    50,    51,    55,    53,
      54,    55,    58,    68,    68,     4,    56,    68,     7,     3,
       4,     5,     5,   102,   191,   173,   113,   312,   113,   113,
      74,   113,   113,    77,    18,    19,    20,    21,    22,    23,
      24,    25,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    41,   113,   297,   113,   113,    -1,    42,    43,
      44,    45,    46,    -1,    48,    -1,    50,    51,    -1,    53,
      -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    52,    53,    77,    18,    19,    20,    21,    22,    23,
      24,    25,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    75,    76,    -1,    -1,    42,    43,
      44,    45,    46,    -1,    48,    -1,    50,    51,    -1,    53,
      -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    52,    53,    77,    18,    19,    20,    21,    22,    23,
      24,    25,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    75,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    -1,    48,    -1,    50,    51,    -1,    53,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    52,    53,    77,    18,    19,    20,    21,    22,    23,
      24,    25,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    -1,    48,    -1,    50,    51,    -1,    53,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    77,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    -1,    48,    -1,    50,    51,    -1,    53,
      -1,    55,    -1,    -1,    -1,    52,    53,    -1,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      74,    -1,    -1,    77,    71,    72,    73,    -1,    75,    76,
      52,    53,    -1,    -1,    56,    57,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    52,    53,    -1,    71,
      72,    73,    58,    75,    76,    -1,    -1,    63,    64,    65,
      66,    -1,    52,    53,    -1,    71,    72,    73,    58,    75,
      76,    -1,    -1,    63,    64,    65,    66,    -1,    52,    53,
      -1,    71,    72,    73,    58,    75,    76,    -1,    -1,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,
      -1,    75,    76,    52,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,
      52,    53,    71,    72,    73,    57,    75,    76,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    -1,    75,    76,    52,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    73,    -1,    75,    76,
      52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    52,    53,    71,
      72,    73,    57,    75,    76,    -1,    -1,    -1,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,    -1,
      75,    76,    52,    53,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    73,    -1,    75,    76,    52,    53,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    -1,    -1,    52,    53,    71,    72,    73,    57,
      75,    76,    -1,    -1,    -1,    63,    64,    65,    66,    -1,
      -1,    52,    53,    71,    72,    73,    57,    75,    76,    -1,
      -1,    -1,    63,    64,    65,    66,    -1,    -1,    52,    53,
      71,    72,    73,    57,    75,    76,    -1,    -1,    -1,    63,
      64,    65,    66,    -1,    -1,    52,    53,    71,    72,    73,
      57,    75,    76,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    73,    -1,    75,    76,
      52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    -1,    75,    76,    52,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    73,    -1,    75,    76,
      52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    -1,    75,    76
  };

  const signed char
  parser::yystos_[] =
  {
       0,    80,    81,     0,     4,     7,    31,    32,    33,    34,
      35,    37,    38,    39,    40,    41,    82,    83,    86,    90,
      91,    92,    93,   102,   106,   107,   112,   113,   116,   117,
     118,     3,     4,    87,     4,    82,   119,   120,   119,   119,
       4,     4,   108,     4,     4,     4,    55,    61,    28,    29,
      97,    30,    57,    61,    57,    58,    67,     3,    55,    57,
      55,    55,    57,    62,    69,   109,    62,     3,     4,     5,
      18,    19,    20,    21,    22,    23,    24,    25,    42,    43,
      44,    45,    46,    48,    50,    51,    53,    55,    56,    74,
      77,   104,   105,     4,     5,    98,     4,    16,    17,    26,
      27,    54,    55,    94,    95,    96,   101,   102,   103,   105,
     102,   108,   108,   111,     4,    56,    88,     4,     4,    56,
     114,   115,     4,    56,   121,    82,    48,    82,    85,     4,
     110,   108,    55,    55,    55,    55,    55,   105,    55,   105,
      58,   105,    55,    55,    55,     4,    49,   104,   105,   105,
     105,   105,    56,    57,    52,    53,    63,    64,    65,    66,
      71,    72,    73,    75,    76,    58,    57,    55,    55,   101,
      95,   105,    61,    60,    57,     6,    62,    69,    70,    36,
      68,    83,    86,    90,    91,   106,   112,   117,   118,    58,
      89,    56,    57,    58,    56,    57,    62,    56,    57,     4,
      49,    84,    47,    57,    70,   105,   105,   105,   105,   105,
      58,   105,    58,    67,   102,    58,   105,   105,   105,    55,
      49,    56,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,    55,     5,   105,   105,    56,    96,
     101,   105,   105,   105,   105,     4,    82,     8,     9,    10,
      11,    12,    13,    14,    15,    89,     4,   115,    58,   115,
       3,     4,    26,    27,   122,     4,    58,    49,    57,    82,
       4,    57,    56,    56,    57,    57,    67,   102,    57,    67,
     102,    94,    67,   102,    56,    56,    57,    56,   104,     5,
      99,   100,    58,    57,    57,    58,   115,    62,    82,     4,
     104,   105,   104,    94,   104,    94,    68,    94,    82,    56,
      56,    57,    55,   105,   105,    82,   122,    58,    56,    57,
      56,    68,    56,    68,    68,    56,     5,    99,    56,    56,
      82,   105,    56,    56
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    79,    80,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    82,    82,    83,    83,    83,    83,
      83,    83,    84,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    91,    91,    91,    92,    93,    93,    94,    95,
      95,    96,    96,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   101,   101,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   103,   104,   104,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   106,   107,
     107,   107,   108,   109,   109,   110,   110,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   112,   113,   113,
     114,   114,   115,   116,   116,   117,   118,   118,   119,   119,
     119,   120,   120,   121,   121,   122,   122,   122,   122
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     0,     1,     3,     2,     2,     2,     4,
       5,     6,     3,     5,     1,     3,     5,     6,     1,     3,
       3,     5,     2,     2,     2,     2,     2,     2,     2,     2,
       0,     2,     1,     2,     2,     4,     1,     3,     1,     1,
       3,     1,     3,     2,     5,     7,     1,     0,     1,     3,
       1,     1,     2,     3,     4,     3,     3,     3,     3,     3,
       6,     6,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     6,     1,     2,     3,     4,     5,     2,     2,
       2,     4,     4,     4,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     6,     6,     6,     8,
       3,     5,     4,     6,     4,     6,     4,     6,     4,     2,
       3,     3,     2,     3,     0,     1,     3,     2,     2,     2,
       2,     2,     2,     3,     2,     2,     0,     4,     6,     7,
       1,     3,     1,     3,     2,     2,     2,     2,     1,     3,
       4,     1,     3,     3,     5,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"symbol\"",
  "\"identifier\"", "\"number\"", "\"relational operator\"",
  "\"pragma directive\"", "\"relation qualifier output\"",
  "\"relation qualifier input\"", "\"relation qualifier printsize\"",
  "\"BRIE datastructure qualifier\"", "\"BTREE datastructure qualifier\"",
  "\"equivalence relation qualifier\"",
  "\"relation qualifier overidable\"", "\"relation qualifier inline\"",
  "\"match predicate\"",
  "\"checks whether substring is contained in a string\"",
  "\"concatenation of two strings\"", "\"ordinal number of a string\"",
  "\"length of a string\"", "\"sub-string of a string\"",
  "\"min aggregator\"", "\"max aggregator\"", "\"count aggregator\"",
  "\"sum aggregator\"", "\"true literal constraint\"",
  "\"false literal constraint\"", "\"strict marker\"", "\"plan keyword\"",
  "\":-\"", "\"relation declaration\"", "\"functor declaration\"",
  "\"input directives declaration\"", "\"output directives declaration\"",
  "\"printsize directives declaration\"",
  "\"override rules of super-component\"", "\"type declaration\"",
  "\"component declaration\"", "\"component instantiation\"",
  "\"numeric type declaration\"", "\"symbolic type declaration\"",
  "\"convert string to number\"", "\"convert number to string\"",
  "\"type cast\"", "\"@\"", "\"nil reference\"", "\"|\"", "\"[\"", "\"]\"",
  "\"_\"", "\"$\"", "\"+\"", "\"-\"", "\"!\"", "\"(\"", "\")\"", "\",\"",
  "\":\"", "\"::\"", "\";\"", "\".\"", "\"=\"", "\"*\"", "\"/\"", "\"^\"",
  "\"%\"", "\"{\"", "\"}\"", "\"<\"", "\">\"", "\"band\"", "\"bor\"",
  "\"bxor\"", "\"bnot\"", "\"land\"", "\"lor\"", "\"lnot\"", "NEG",
  "$accept", "program", "unit", "identifier", "type",
  "non_empty_record_type_list", "union_type_list", "relation_decl",
  "relation_list", "non_empty_attributes", "qualifiers", "fact", "rule",
  "rule_def", "head", "body", "disjunction", "conjunction", "exec_plan",
  "exec_plan_list", "exec_order_list", "non_empty_exec_order_list", "term",
  "atom", "constraint", "non_empty_arg_list", "arg", "component",
  "component_head", "comp_type", "type_params", "type_param_list",
  "component_body", "comp_init", "functor_decl",
  "non_empty_functor_arg_type_list", "functor_type", "pragma", "load_head",
  "store_head", "io_directive_list", "io_relation_list",
  "non_empty_key_value_pairs", "kvp_value", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   258,   258,   263,   268,   273,   280,   287,   294,   299,
     306,   311,   316,   321,   330,   334,   348,   352,   356,   360,
     367,   372,   383,   390,   401,   407,   422,   430,   445,   452,
     466,   474,   488,   493,   498,   503,   508,   513,   518,   523,
     528,   539,   550,   555,   563,   575,   599,   604,   615,   624,
     629,   639,   644,   654,   663,   670,   682,   687,   692,   696,
     710,   715,   720,   726,   735,   748,   760,   769,   778,   787,
     798,   807,   818,   822,   830,   835,   846,   850,   854,   858,
     862,   866,   873,   882,   887,   891,   905,   911,   927,   939,
     946,   953,   960,   967,   974,   983,   992,  1001,  1010,  1019,
    1028,  1037,  1046,  1055,  1064,  1073,  1084,  1098,  1112,  1128,
    1141,  1151,  1170,  1182,  1204,  1217,  1239,  1251,  1280,  1293,
    1299,  1306,  1317,  1326,  1331,  1338,  1341,  1351,  1358,  1367,
    1376,  1385,  1392,  1401,  1407,  1414,  1421,  1428,  1444,  1449,
    1458,  1461,  1468,  1485,  1489,  1497,  1506,  1511,  1520,  1525,
    1530,  1545,  1554,  1569,  1572,  1580,  1583,  1586,  1589
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
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


} // yy
#line 3900 "parser.cc"

#line 1594 "./parser.yy"


void yy::parser::error(const location_type &l, const std::string &m) {
    driver.error(l, m);
}
