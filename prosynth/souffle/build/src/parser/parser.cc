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
#line 112 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"

   #include "parser/ParserDriver.h"
   #define YY_DECL yy::parser::symbol_type yylex(souffle::ParserDriver& driver, yyscan_t yyscanner)
   YY_DECL;

#line 51 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"


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
#line 142 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"


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
      case 138: // aggregate_func
        value.YY_MOVE_OR_COPY< AggregateOp > (YY_MOVE (that.value));
        break;

      case 136: // arg
        value.YY_MOVE_OR_COPY< Mov<Own<ast::Argument>> > (YY_MOVE (that.value));
        break;

      case 132: // atom
        value.YY_MOVE_OR_COPY< Mov<Own<ast::Atom>> > (YY_MOVE (that.value));
        break;

      case 118: // attribute
      case 154: // functor_attribute
        value.YY_MOVE_OR_COPY< Mov<Own<ast::Attribute>> > (YY_MOVE (that.value));
        break;

      case 113: // adt_branch
        value.YY_MOVE_OR_COPY< Mov<Own<ast::BranchType>> > (YY_MOVE (that.value));
        break;

      case 124: // fact
        value.YY_MOVE_OR_COPY< Mov<Own<ast::Clause>> > (YY_MOVE (that.value));
        break;

      case 144: // component_decl
      case 145: // component_head
      case 149: // component_body
        value.YY_MOVE_OR_COPY< Mov<Own<ast::Component>> > (YY_MOVE (that.value));
        break;

      case 150: // component_init
        value.YY_MOVE_OR_COPY< Mov<Own<ast::ComponentInit>> > (YY_MOVE (that.value));
        break;

      case 146: // component_type
        value.YY_MOVE_OR_COPY< Mov<Own<ast::ComponentType>> > (YY_MOVE (that.value));
        break;

      case 133: // constraint
        value.YY_MOVE_OR_COPY< Mov<Own<ast::Constraint>> > (YY_MOVE (that.value));
        break;

      case 142: // plan_order
        value.YY_MOVE_OR_COPY< Mov<Own<ast::ExecutionOrder>> > (YY_MOVE (that.value));
        break;

      case 140: // query_plan
      case 141: // query_plan_list
        value.YY_MOVE_OR_COPY< Mov<Own<ast::ExecutionPlan>> > (YY_MOVE (that.value));
        break;

      case 121: // dependency
        value.YY_MOVE_OR_COPY< Mov<Own<ast::FunctionalConstraint>> > (YY_MOVE (that.value));
        break;

      case 151: // functor_decl
        value.YY_MOVE_OR_COPY< Mov<Own<ast::FunctorDeclaration>> > (YY_MOVE (that.value));
        break;

      case 155: // pragma
        value.YY_MOVE_OR_COPY< Mov<Own<ast::Pragma>> > (YY_MOVE (that.value));
        break;

      case 109: // type_decl
        value.YY_MOVE_OR_COPY< Mov<Own<ast::Type>> > (YY_MOVE (that.value));
        break;

      case 128: // body
      case 129: // disjunction
      case 130: // conjunction
      case 131: // term
      case 139: // aggregate_body
        value.YY_MOVE_OR_COPY< Mov<RuleBody> > (YY_MOVE (that.value));
        break;

      case 134: // arg_list
      case 135: // non_empty_arg_list
        value.YY_MOVE_OR_COPY< Mov<VecOwn<ast::Argument>> > (YY_MOVE (that.value));
        break;

      case 127: // head
        value.YY_MOVE_OR_COPY< Mov<VecOwn<ast::Atom>> > (YY_MOVE (that.value));
        break;

      case 110: // record_type_list
      case 116: // attributes_list
      case 117: // non_empty_attributes
      case 152: // functor_arg_type_list
      case 153: // non_empty_functor_arg_type_list
        value.YY_MOVE_OR_COPY< Mov<VecOwn<ast::Attribute>> > (YY_MOVE (that.value));
        break;

      case 112: // adt_branch_list
        value.YY_MOVE_OR_COPY< Mov<VecOwn<ast::BranchType>> > (YY_MOVE (that.value));
        break;

      case 125: // rule
      case 126: // rule_def
        value.YY_MOVE_OR_COPY< Mov<VecOwn<ast::Clause>> > (YY_MOVE (that.value));
        break;

      case 156: // directive_head
      case 158: // directive_list
      case 159: // relation_directive_list
        value.YY_MOVE_OR_COPY< Mov<VecOwn<ast::Directive>> > (YY_MOVE (that.value));
        break;

      case 122: // dependency_list_aux
      case 123: // dependency_list
        value.YY_MOVE_OR_COPY< Mov<VecOwn<ast::FunctionalConstraint>> > (YY_MOVE (that.value));
        break;

      case 114: // relation_decl
      case 115: // relation_names
        value.YY_MOVE_OR_COPY< Mov<VecOwn<ast::Relation>> > (YY_MOVE (that.value));
        break;

      case 143: // non_empty_plan_order_list
        value.YY_MOVE_OR_COPY< Mov<ast::ExecutionOrder::ExecOrder> > (YY_MOVE (that.value));
        break;

      case 108: // qualified_name
        value.YY_MOVE_OR_COPY< Mov<ast::QualifiedName> > (YY_MOVE (that.value));
        break;

      case 137: // functor_built_in
      case 161: // kvp_value
        value.YY_MOVE_OR_COPY< Mov<std::string> > (YY_MOVE (that.value));
        break;

      case 111: // union_type_list
      case 147: // component_type_params
      case 148: // component_param_list
        value.YY_MOVE_OR_COPY< Mov<std::vector<ast::QualifiedName>> > (YY_MOVE (that.value));
        break;

      case 160: // non_empty_key_value_pairs
        value.YY_MOVE_OR_COPY< Mov<std::vector<std::pair
            <std::string, std::string>>> > (YY_MOVE (that.value));
        break;

      case 120: // non_empty_attribute_names
        value.YY_MOVE_OR_COPY< Mov<std::vector<std::string>> > (YY_MOVE (that.value));
        break;

      case 157: // directive_head_decl
        value.YY_MOVE_OR_COPY< ast::DirectiveType > (YY_MOVE (that.value));
        break;

      case 119: // relation_tags
        value.YY_MOVE_OR_COPY< std::set<RelationTag> > (YY_MOVE (that.value));
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 5: // "number"
      case 6: // "unsigned number"
      case 7: // "float"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
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
      case 138: // aggregate_func
        value.move< AggregateOp > (YY_MOVE (that.value));
        break;

      case 136: // arg
        value.move< Mov<Own<ast::Argument>> > (YY_MOVE (that.value));
        break;

      case 132: // atom
        value.move< Mov<Own<ast::Atom>> > (YY_MOVE (that.value));
        break;

      case 118: // attribute
      case 154: // functor_attribute
        value.move< Mov<Own<ast::Attribute>> > (YY_MOVE (that.value));
        break;

      case 113: // adt_branch
        value.move< Mov<Own<ast::BranchType>> > (YY_MOVE (that.value));
        break;

      case 124: // fact
        value.move< Mov<Own<ast::Clause>> > (YY_MOVE (that.value));
        break;

      case 144: // component_decl
      case 145: // component_head
      case 149: // component_body
        value.move< Mov<Own<ast::Component>> > (YY_MOVE (that.value));
        break;

      case 150: // component_init
        value.move< Mov<Own<ast::ComponentInit>> > (YY_MOVE (that.value));
        break;

      case 146: // component_type
        value.move< Mov<Own<ast::ComponentType>> > (YY_MOVE (that.value));
        break;

      case 133: // constraint
        value.move< Mov<Own<ast::Constraint>> > (YY_MOVE (that.value));
        break;

      case 142: // plan_order
        value.move< Mov<Own<ast::ExecutionOrder>> > (YY_MOVE (that.value));
        break;

      case 140: // query_plan
      case 141: // query_plan_list
        value.move< Mov<Own<ast::ExecutionPlan>> > (YY_MOVE (that.value));
        break;

      case 121: // dependency
        value.move< Mov<Own<ast::FunctionalConstraint>> > (YY_MOVE (that.value));
        break;

      case 151: // functor_decl
        value.move< Mov<Own<ast::FunctorDeclaration>> > (YY_MOVE (that.value));
        break;

      case 155: // pragma
        value.move< Mov<Own<ast::Pragma>> > (YY_MOVE (that.value));
        break;

      case 109: // type_decl
        value.move< Mov<Own<ast::Type>> > (YY_MOVE (that.value));
        break;

      case 128: // body
      case 129: // disjunction
      case 130: // conjunction
      case 131: // term
      case 139: // aggregate_body
        value.move< Mov<RuleBody> > (YY_MOVE (that.value));
        break;

      case 134: // arg_list
      case 135: // non_empty_arg_list
        value.move< Mov<VecOwn<ast::Argument>> > (YY_MOVE (that.value));
        break;

      case 127: // head
        value.move< Mov<VecOwn<ast::Atom>> > (YY_MOVE (that.value));
        break;

      case 110: // record_type_list
      case 116: // attributes_list
      case 117: // non_empty_attributes
      case 152: // functor_arg_type_list
      case 153: // non_empty_functor_arg_type_list
        value.move< Mov<VecOwn<ast::Attribute>> > (YY_MOVE (that.value));
        break;

      case 112: // adt_branch_list
        value.move< Mov<VecOwn<ast::BranchType>> > (YY_MOVE (that.value));
        break;

      case 125: // rule
      case 126: // rule_def
        value.move< Mov<VecOwn<ast::Clause>> > (YY_MOVE (that.value));
        break;

      case 156: // directive_head
      case 158: // directive_list
      case 159: // relation_directive_list
        value.move< Mov<VecOwn<ast::Directive>> > (YY_MOVE (that.value));
        break;

      case 122: // dependency_list_aux
      case 123: // dependency_list
        value.move< Mov<VecOwn<ast::FunctionalConstraint>> > (YY_MOVE (that.value));
        break;

      case 114: // relation_decl
      case 115: // relation_names
        value.move< Mov<VecOwn<ast::Relation>> > (YY_MOVE (that.value));
        break;

      case 143: // non_empty_plan_order_list
        value.move< Mov<ast::ExecutionOrder::ExecOrder> > (YY_MOVE (that.value));
        break;

      case 108: // qualified_name
        value.move< Mov<ast::QualifiedName> > (YY_MOVE (that.value));
        break;

      case 137: // functor_built_in
      case 161: // kvp_value
        value.move< Mov<std::string> > (YY_MOVE (that.value));
        break;

      case 111: // union_type_list
      case 147: // component_type_params
      case 148: // component_param_list
        value.move< Mov<std::vector<ast::QualifiedName>> > (YY_MOVE (that.value));
        break;

      case 160: // non_empty_key_value_pairs
        value.move< Mov<std::vector<std::pair
            <std::string, std::string>>> > (YY_MOVE (that.value));
        break;

      case 120: // non_empty_attribute_names
        value.move< Mov<std::vector<std::string>> > (YY_MOVE (that.value));
        break;

      case 157: // directive_head_decl
        value.move< ast::DirectiveType > (YY_MOVE (that.value));
        break;

      case 119: // relation_tags
        value.move< std::set<RelationTag> > (YY_MOVE (that.value));
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 5: // "number"
      case 6: // "unsigned number"
      case 7: // "float"
        value.move< std::string > (YY_MOVE (that.value));
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
      case 138: // aggregate_func
        value.copy< AggregateOp > (that.value);
        break;

      case 136: // arg
        value.copy< Mov<Own<ast::Argument>> > (that.value);
        break;

      case 132: // atom
        value.copy< Mov<Own<ast::Atom>> > (that.value);
        break;

      case 118: // attribute
      case 154: // functor_attribute
        value.copy< Mov<Own<ast::Attribute>> > (that.value);
        break;

      case 113: // adt_branch
        value.copy< Mov<Own<ast::BranchType>> > (that.value);
        break;

      case 124: // fact
        value.copy< Mov<Own<ast::Clause>> > (that.value);
        break;

      case 144: // component_decl
      case 145: // component_head
      case 149: // component_body
        value.copy< Mov<Own<ast::Component>> > (that.value);
        break;

      case 150: // component_init
        value.copy< Mov<Own<ast::ComponentInit>> > (that.value);
        break;

      case 146: // component_type
        value.copy< Mov<Own<ast::ComponentType>> > (that.value);
        break;

      case 133: // constraint
        value.copy< Mov<Own<ast::Constraint>> > (that.value);
        break;

      case 142: // plan_order
        value.copy< Mov<Own<ast::ExecutionOrder>> > (that.value);
        break;

      case 140: // query_plan
      case 141: // query_plan_list
        value.copy< Mov<Own<ast::ExecutionPlan>> > (that.value);
        break;

      case 121: // dependency
        value.copy< Mov<Own<ast::FunctionalConstraint>> > (that.value);
        break;

      case 151: // functor_decl
        value.copy< Mov<Own<ast::FunctorDeclaration>> > (that.value);
        break;

      case 155: // pragma
        value.copy< Mov<Own<ast::Pragma>> > (that.value);
        break;

      case 109: // type_decl
        value.copy< Mov<Own<ast::Type>> > (that.value);
        break;

      case 128: // body
      case 129: // disjunction
      case 130: // conjunction
      case 131: // term
      case 139: // aggregate_body
        value.copy< Mov<RuleBody> > (that.value);
        break;

      case 134: // arg_list
      case 135: // non_empty_arg_list
        value.copy< Mov<VecOwn<ast::Argument>> > (that.value);
        break;

      case 127: // head
        value.copy< Mov<VecOwn<ast::Atom>> > (that.value);
        break;

      case 110: // record_type_list
      case 116: // attributes_list
      case 117: // non_empty_attributes
      case 152: // functor_arg_type_list
      case 153: // non_empty_functor_arg_type_list
        value.copy< Mov<VecOwn<ast::Attribute>> > (that.value);
        break;

      case 112: // adt_branch_list
        value.copy< Mov<VecOwn<ast::BranchType>> > (that.value);
        break;

      case 125: // rule
      case 126: // rule_def
        value.copy< Mov<VecOwn<ast::Clause>> > (that.value);
        break;

      case 156: // directive_head
      case 158: // directive_list
      case 159: // relation_directive_list
        value.copy< Mov<VecOwn<ast::Directive>> > (that.value);
        break;

      case 122: // dependency_list_aux
      case 123: // dependency_list
        value.copy< Mov<VecOwn<ast::FunctionalConstraint>> > (that.value);
        break;

      case 114: // relation_decl
      case 115: // relation_names
        value.copy< Mov<VecOwn<ast::Relation>> > (that.value);
        break;

      case 143: // non_empty_plan_order_list
        value.copy< Mov<ast::ExecutionOrder::ExecOrder> > (that.value);
        break;

      case 108: // qualified_name
        value.copy< Mov<ast::QualifiedName> > (that.value);
        break;

      case 137: // functor_built_in
      case 161: // kvp_value
        value.copy< Mov<std::string> > (that.value);
        break;

      case 111: // union_type_list
      case 147: // component_type_params
      case 148: // component_param_list
        value.copy< Mov<std::vector<ast::QualifiedName>> > (that.value);
        break;

      case 160: // non_empty_key_value_pairs
        value.copy< Mov<std::vector<std::pair
            <std::string, std::string>>> > (that.value);
        break;

      case 120: // non_empty_attribute_names
        value.copy< Mov<std::vector<std::string>> > (that.value);
        break;

      case 157: // directive_head_decl
        value.copy< ast::DirectiveType > (that.value);
        break;

      case 119: // relation_tags
        value.copy< std::set<RelationTag> > (that.value);
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 5: // "number"
      case 6: // "unsigned number"
      case 7: // "float"
        value.copy< std::string > (that.value);
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
      case 138: // aggregate_func
        value.move< AggregateOp > (that.value);
        break;

      case 136: // arg
        value.move< Mov<Own<ast::Argument>> > (that.value);
        break;

      case 132: // atom
        value.move< Mov<Own<ast::Atom>> > (that.value);
        break;

      case 118: // attribute
      case 154: // functor_attribute
        value.move< Mov<Own<ast::Attribute>> > (that.value);
        break;

      case 113: // adt_branch
        value.move< Mov<Own<ast::BranchType>> > (that.value);
        break;

      case 124: // fact
        value.move< Mov<Own<ast::Clause>> > (that.value);
        break;

      case 144: // component_decl
      case 145: // component_head
      case 149: // component_body
        value.move< Mov<Own<ast::Component>> > (that.value);
        break;

      case 150: // component_init
        value.move< Mov<Own<ast::ComponentInit>> > (that.value);
        break;

      case 146: // component_type
        value.move< Mov<Own<ast::ComponentType>> > (that.value);
        break;

      case 133: // constraint
        value.move< Mov<Own<ast::Constraint>> > (that.value);
        break;

      case 142: // plan_order
        value.move< Mov<Own<ast::ExecutionOrder>> > (that.value);
        break;

      case 140: // query_plan
      case 141: // query_plan_list
        value.move< Mov<Own<ast::ExecutionPlan>> > (that.value);
        break;

      case 121: // dependency
        value.move< Mov<Own<ast::FunctionalConstraint>> > (that.value);
        break;

      case 151: // functor_decl
        value.move< Mov<Own<ast::FunctorDeclaration>> > (that.value);
        break;

      case 155: // pragma
        value.move< Mov<Own<ast::Pragma>> > (that.value);
        break;

      case 109: // type_decl
        value.move< Mov<Own<ast::Type>> > (that.value);
        break;

      case 128: // body
      case 129: // disjunction
      case 130: // conjunction
      case 131: // term
      case 139: // aggregate_body
        value.move< Mov<RuleBody> > (that.value);
        break;

      case 134: // arg_list
      case 135: // non_empty_arg_list
        value.move< Mov<VecOwn<ast::Argument>> > (that.value);
        break;

      case 127: // head
        value.move< Mov<VecOwn<ast::Atom>> > (that.value);
        break;

      case 110: // record_type_list
      case 116: // attributes_list
      case 117: // non_empty_attributes
      case 152: // functor_arg_type_list
      case 153: // non_empty_functor_arg_type_list
        value.move< Mov<VecOwn<ast::Attribute>> > (that.value);
        break;

      case 112: // adt_branch_list
        value.move< Mov<VecOwn<ast::BranchType>> > (that.value);
        break;

      case 125: // rule
      case 126: // rule_def
        value.move< Mov<VecOwn<ast::Clause>> > (that.value);
        break;

      case 156: // directive_head
      case 158: // directive_list
      case 159: // relation_directive_list
        value.move< Mov<VecOwn<ast::Directive>> > (that.value);
        break;

      case 122: // dependency_list_aux
      case 123: // dependency_list
        value.move< Mov<VecOwn<ast::FunctionalConstraint>> > (that.value);
        break;

      case 114: // relation_decl
      case 115: // relation_names
        value.move< Mov<VecOwn<ast::Relation>> > (that.value);
        break;

      case 143: // non_empty_plan_order_list
        value.move< Mov<ast::ExecutionOrder::ExecOrder> > (that.value);
        break;

      case 108: // qualified_name
        value.move< Mov<ast::QualifiedName> > (that.value);
        break;

      case 137: // functor_built_in
      case 161: // kvp_value
        value.move< Mov<std::string> > (that.value);
        break;

      case 111: // union_type_list
      case 147: // component_type_params
      case 148: // component_param_list
        value.move< Mov<std::vector<ast::QualifiedName>> > (that.value);
        break;

      case 160: // non_empty_key_value_pairs
        value.move< Mov<std::vector<std::pair
            <std::string, std::string>>> > (that.value);
        break;

      case 120: // non_empty_attribute_names
        value.move< Mov<std::vector<std::string>> > (that.value);
        break;

      case 157: // directive_head_decl
        value.move< ast::DirectiveType > (that.value);
        break;

      case 119: // relation_tags
        value.move< std::set<RelationTag> > (that.value);
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 5: // "number"
      case 6: // "unsigned number"
      case 7: // "float"
        value.move< std::string > (that.value);
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
      case 138: // aggregate_func
        yylhs.value.emplace< AggregateOp > ();
        break;

      case 136: // arg
        yylhs.value.emplace< Mov<Own<ast::Argument>> > ();
        break;

      case 132: // atom
        yylhs.value.emplace< Mov<Own<ast::Atom>> > ();
        break;

      case 118: // attribute
      case 154: // functor_attribute
        yylhs.value.emplace< Mov<Own<ast::Attribute>> > ();
        break;

      case 113: // adt_branch
        yylhs.value.emplace< Mov<Own<ast::BranchType>> > ();
        break;

      case 124: // fact
        yylhs.value.emplace< Mov<Own<ast::Clause>> > ();
        break;

      case 144: // component_decl
      case 145: // component_head
      case 149: // component_body
        yylhs.value.emplace< Mov<Own<ast::Component>> > ();
        break;

      case 150: // component_init
        yylhs.value.emplace< Mov<Own<ast::ComponentInit>> > ();
        break;

      case 146: // component_type
        yylhs.value.emplace< Mov<Own<ast::ComponentType>> > ();
        break;

      case 133: // constraint
        yylhs.value.emplace< Mov<Own<ast::Constraint>> > ();
        break;

      case 142: // plan_order
        yylhs.value.emplace< Mov<Own<ast::ExecutionOrder>> > ();
        break;

      case 140: // query_plan
      case 141: // query_plan_list
        yylhs.value.emplace< Mov<Own<ast::ExecutionPlan>> > ();
        break;

      case 121: // dependency
        yylhs.value.emplace< Mov<Own<ast::FunctionalConstraint>> > ();
        break;

      case 151: // functor_decl
        yylhs.value.emplace< Mov<Own<ast::FunctorDeclaration>> > ();
        break;

      case 155: // pragma
        yylhs.value.emplace< Mov<Own<ast::Pragma>> > ();
        break;

      case 109: // type_decl
        yylhs.value.emplace< Mov<Own<ast::Type>> > ();
        break;

      case 128: // body
      case 129: // disjunction
      case 130: // conjunction
      case 131: // term
      case 139: // aggregate_body
        yylhs.value.emplace< Mov<RuleBody> > ();
        break;

      case 134: // arg_list
      case 135: // non_empty_arg_list
        yylhs.value.emplace< Mov<VecOwn<ast::Argument>> > ();
        break;

      case 127: // head
        yylhs.value.emplace< Mov<VecOwn<ast::Atom>> > ();
        break;

      case 110: // record_type_list
      case 116: // attributes_list
      case 117: // non_empty_attributes
      case 152: // functor_arg_type_list
      case 153: // non_empty_functor_arg_type_list
        yylhs.value.emplace< Mov<VecOwn<ast::Attribute>> > ();
        break;

      case 112: // adt_branch_list
        yylhs.value.emplace< Mov<VecOwn<ast::BranchType>> > ();
        break;

      case 125: // rule
      case 126: // rule_def
        yylhs.value.emplace< Mov<VecOwn<ast::Clause>> > ();
        break;

      case 156: // directive_head
      case 158: // directive_list
      case 159: // relation_directive_list
        yylhs.value.emplace< Mov<VecOwn<ast::Directive>> > ();
        break;

      case 122: // dependency_list_aux
      case 123: // dependency_list
        yylhs.value.emplace< Mov<VecOwn<ast::FunctionalConstraint>> > ();
        break;

      case 114: // relation_decl
      case 115: // relation_names
        yylhs.value.emplace< Mov<VecOwn<ast::Relation>> > ();
        break;

      case 143: // non_empty_plan_order_list
        yylhs.value.emplace< Mov<ast::ExecutionOrder::ExecOrder> > ();
        break;

      case 108: // qualified_name
        yylhs.value.emplace< Mov<ast::QualifiedName> > ();
        break;

      case 137: // functor_built_in
      case 161: // kvp_value
        yylhs.value.emplace< Mov<std::string> > ();
        break;

      case 111: // union_type_list
      case 147: // component_type_params
      case 148: // component_param_list
        yylhs.value.emplace< Mov<std::vector<ast::QualifiedName>> > ();
        break;

      case 160: // non_empty_key_value_pairs
        yylhs.value.emplace< Mov<std::vector<std::pair
            <std::string, std::string>>> > ();
        break;

      case 120: // non_empty_attribute_names
        yylhs.value.emplace< Mov<std::vector<std::string>> > ();
        break;

      case 157: // directive_head_decl
        yylhs.value.emplace< ast::DirectiveType > ();
        break;

      case 119: // relation_tags
        yylhs.value.emplace< std::set<RelationTag> > ();
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 5: // "number"
      case 6: // "unsigned number"
      case 7: // "float"
        yylhs.value.emplace< std::string > ();
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
#line 312 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    { }
#line 1380 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 4:
#line 314 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      for (auto&& cur : yystack_[0].value.as < Mov<VecOwn<ast::Directive>> > ())
        driver.addDirective(std::move(cur));
    }
#line 1389 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 5:
#line 319 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      for (auto&& cur : yystack_[0].value.as < Mov<VecOwn<ast::Clause>> > ()   )
        driver.addClause(std::move(cur));
    }
#line 1398 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 6:
#line 324 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      driver.addClause(yystack_[0].value.as < Mov<Own<ast::Clause>> > ());
    }
#line 1406 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 7:
#line 328 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      driver.addComponent(yystack_[0].value.as < Mov<Own<ast::Component>> > ());
    }
#line 1414 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 8:
#line 332 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      driver.addInstantiation(yystack_[0].value.as < Mov<Own<ast::ComponentInit>> > ());
    }
#line 1422 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 9:
#line 336 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      driver.addPragma(yystack_[0].value.as < Mov<Own<ast::Pragma>> > ());
    }
#line 1430 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 10:
#line 340 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      driver.addType(yystack_[0].value.as < Mov<Own<ast::Type>> > ());
    }
#line 1438 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 11:
#line 344 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      driver.addFunctorDeclaration(yystack_[0].value.as < Mov<Own<ast::FunctorDeclaration>> > ());
    }
#line 1446 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 12:
#line 348 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      for (auto&& rel : yystack_[0].value.as < Mov<VecOwn<ast::Relation>> > ()) {
        driver.addIoFromDeprecatedTag(*rel);
        driver.addRelation(std::move(rel));
      }
    }
#line 1457 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 13:
#line 362 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<ast::QualifiedName> > () = yystack_[0].value.as < std::string > ();
    }
#line 1465 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 14:
#line 366 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<ast::QualifiedName> > () = yystack_[2].value.as < Mov<ast::QualifiedName> > (); yylhs.value.as < Mov<ast::QualifiedName> > ()->append(yystack_[0].value.as < std::string > ());
    }
#line 1473 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 15:
#line 376 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Type>> > () = mk<ast::SubsetType>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Mov<ast::QualifiedName> > (), yylhs.location);
    }
#line 1481 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 16:
#line 380 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      if (yystack_[0].value.as < Mov<std::vector<ast::QualifiedName>> > ().size() > 1) {
         yylhs.value.as < Mov<Own<ast::Type>> > () = mk<ast::UnionType>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Mov<std::vector<ast::QualifiedName>> > (), yylhs.location);
      } else {
         assert(yystack_[0].value.as < Mov<std::vector<ast::QualifiedName>> > ().size() == 1 && "qualified name missing for alias type");
         yylhs.value.as < Mov<Own<ast::Type>> > () = mk<ast::AliasType>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Mov<std::vector<ast::QualifiedName>> > ()[0], yylhs.location);
      }
    }
#line 1494 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 17:
#line 389 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Type>> > () = mk<ast::RecordType>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Mov<VecOwn<ast::Attribute>> > (), yylhs.location);
    }
#line 1502 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 18:
#line 393 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Type>> > () = mk<ast::AlgebraicDataType>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Mov<VecOwn<ast::BranchType>> > (), yylhs.location);
    }
#line 1510 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 19:
#line 398 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Type>> > () = driver.mkDeprecatedSubType(yystack_[0].value.as < std::string > (), "number", yylhs.location);
    }
#line 1518 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 20:
#line 402 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Type>> > () = driver.mkDeprecatedSubType(yystack_[0].value.as < std::string > (), "symbol", yylhs.location);
    }
#line 1526 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 21:
#line 406 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Type>> > () = driver.mkDeprecatedSubType(yystack_[0].value.as < std::string > (), "symbol", yylhs.location);
    }
#line 1534 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 22:
#line 415 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    { }
#line 1540 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 23:
#line 417 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Attribute>> > () = yystack_[1].value.as < Mov<VecOwn<ast::Attribute>> > ();
    }
#line 1548 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 24:
#line 425 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::vector<ast::QualifiedName>> > ().push_back(yystack_[0].value.as < Mov<ast::QualifiedName> > ());
    }
#line 1556 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 25:
#line 429 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::vector<ast::QualifiedName>> > () = yystack_[2].value.as < Mov<std::vector<ast::QualifiedName>> > ();
      yylhs.value.as < Mov<std::vector<ast::QualifiedName>> > ().push_back(yystack_[0].value.as < Mov<ast::QualifiedName> > ());
    }
#line 1565 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 26:
#line 437 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::BranchType>> > ().push_back(yystack_[0].value.as < Mov<Own<ast::BranchType>> > ());
    }
#line 1573 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 27:
#line 441 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::BranchType>> > () = yystack_[2].value.as < Mov<VecOwn<ast::BranchType>> > ();
      yylhs.value.as < Mov<VecOwn<ast::BranchType>> > ().push_back(yystack_[0].value.as < Mov<Own<ast::BranchType>> > ());
    }
#line 1582 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 28:
#line 449 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::BranchType>> > () = mk<ast::BranchType>(yystack_[2].value.as < std::string > (), VecOwn<ast::Attribute>{}, yylhs.location);
    }
#line 1590 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 29:
#line 453 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::BranchType>> > () = mk<ast::BranchType>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Mov<VecOwn<ast::Attribute>> > (), yylhs.location);
    }
#line 1598 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 30:
#line 467 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      auto tags = yystack_[1].value.as < std::set<RelationTag> > ();
      auto attributes_list = yystack_[2].value.as < Mov<VecOwn<ast::Attribute>> > ();
      yylhs.value.as < Mov<VecOwn<ast::Relation>> > () = yystack_[3].value.as < Mov<VecOwn<ast::Relation>> > ();
      for (auto&& rel : yylhs.value.as < Mov<VecOwn<ast::Relation>> > ()) {
        for (auto tag : tags) {
          if (isRelationQualifierTag(tag)) {
            rel->addQualifier(getRelationQualifierFromTag(tag));
          } else if (isRelationRepresentationTag(tag)) {
            rel->setRepresentation(getRelationRepresentationFromTag(tag));
          } else {
            assert(false && "unhandled tag");
          }
        }
        for (auto&& fd : yystack_[0].value.as < Mov<VecOwn<ast::FunctionalConstraint>> > ()) {
          rel->addDependency(souffle::clone(fd));
        }
        rel->setAttributes(clone(attributes_list));
      }
    }
#line 1623 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 31:
#line 494 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Relation>> > ().push_back(mk<ast::Relation>(yystack_[0].value.as < std::string > (), yystack_[0].location));
    }
#line 1631 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 32:
#line 498 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Relation>> > () = yystack_[2].value.as < Mov<VecOwn<ast::Relation>> > ();
      yylhs.value.as < Mov<VecOwn<ast::Relation>> > ().push_back(mk<ast::Relation>(yystack_[0].value.as < std::string > (), yystack_[0].location));
    }
#line 1640 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 33:
#line 509 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
    }
#line 1647 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 34:
#line 512 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Attribute>> > () = yystack_[1].value.as < Mov<VecOwn<ast::Attribute>> > ();
    }
#line 1655 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 35:
#line 519 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Attribute>> > ().push_back(yystack_[0].value.as < Mov<Own<ast::Attribute>> > ());
    }
#line 1663 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 36:
#line 523 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Attribute>> > () = yystack_[2].value.as < Mov<VecOwn<ast::Attribute>> > ();
      yylhs.value.as < Mov<VecOwn<ast::Attribute>> > ().push_back(yystack_[0].value.as < Mov<Own<ast::Attribute>> > ());
    }
#line 1672 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 37:
#line 531 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Attribute>> > () = mk<ast::Attribute>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Mov<ast::QualifiedName> > (), yystack_[0].location);
    }
#line 1680 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 38:
#line 541 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    { }
#line 1686 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 39:
#line 543 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < std::set<RelationTag> > () = driver.addTag(RelationTag::OVERRIDABLE, yystack_[0].location, yystack_[1].value.as < std::set<RelationTag> > ());
    }
#line 1694 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 40:
#line 547 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < std::set<RelationTag> > () = driver.addTag(RelationTag::INLINE, yystack_[0].location, yystack_[1].value.as < std::set<RelationTag> > ());
    }
#line 1702 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 41:
#line 551 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < std::set<RelationTag> > () = driver.addTag(RelationTag::NO_INLINE, yystack_[0].location, yystack_[1].value.as < std::set<RelationTag> > ());
    }
#line 1710 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 42:
#line 555 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < std::set<RelationTag> > () = driver.addTag(RelationTag::MAGIC, yystack_[0].location, yystack_[1].value.as < std::set<RelationTag> > ());
    }
#line 1718 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 43:
#line 559 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < std::set<RelationTag> > () = driver.addTag(RelationTag::NO_MAGIC, yystack_[0].location, yystack_[1].value.as < std::set<RelationTag> > ());
    }
#line 1726 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 44:
#line 563 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < std::set<RelationTag> > () = driver.addReprTag(RelationTag::BRIE, yystack_[0].location, yystack_[1].value.as < std::set<RelationTag> > ());
    }
#line 1734 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 45:
#line 567 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < std::set<RelationTag> > () = driver.addReprTag(RelationTag::BTREE, yystack_[0].location, yystack_[1].value.as < std::set<RelationTag> > ());
    }
#line 1742 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 46:
#line 571 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < std::set<RelationTag> > () = driver.addReprTag(RelationTag::BTREE_DELETE, yystack_[0].location, yystack_[1].value.as < std::set<RelationTag> > ());
    }
#line 1750 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 47:
#line 575 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < std::set<RelationTag> > () = driver.addReprTag(RelationTag::EQREL, yystack_[0].location, yystack_[1].value.as < std::set<RelationTag> > ());
    }
#line 1758 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 48:
#line 580 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < std::set<RelationTag> > () = driver.addDeprecatedTag(RelationTag::OUTPUT, yystack_[0].location, yystack_[1].value.as < std::set<RelationTag> > ());
    }
#line 1766 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 49:
#line 584 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < std::set<RelationTag> > () = driver.addDeprecatedTag(RelationTag::INPUT, yystack_[0].location, yystack_[1].value.as < std::set<RelationTag> > ());
    }
#line 1774 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 50:
#line 588 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < std::set<RelationTag> > () = driver.addDeprecatedTag(RelationTag::PRINTSIZE, yystack_[0].location, yystack_[1].value.as < std::set<RelationTag> > ());
    }
#line 1782 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 51:
#line 598 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::vector<std::string>> > ().push_back(yystack_[0].value.as < std::string > ());
    }
#line 1790 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 52:
#line 603 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::vector<std::string>> > () = yystack_[2].value.as < Mov<std::vector<std::string>> > ();
      yylhs.value.as < Mov<std::vector<std::string>> > ().push_back(yystack_[0].value.as < std::string > ());
    }
#line 1799 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 53:
#line 614 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
        yylhs.value.as < Mov<Own<ast::FunctionalConstraint>> > () = mk<ast::FunctionalConstraint>(mk<ast::Variable>(yystack_[0].value.as < std::string > (), yylhs.location), yylhs.location);
    }
#line 1807 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 54:
#line 618 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      VecOwn<ast::Variable> keys;
      for (std::string s : yystack_[1].value.as < Mov<std::vector<std::string>> > ()) {
        keys.push_back(mk<ast::Variable>(s, yylhs.location));
      }
      yylhs.value.as < Mov<Own<ast::FunctionalConstraint>> > () = mk<ast::FunctionalConstraint>(std::move(keys), yylhs.location);
    }
#line 1819 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 55:
#line 629 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::FunctionalConstraint>> > ().push_back(yystack_[0].value.as < Mov<Own<ast::FunctionalConstraint>> > ());
    }
#line 1827 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 56:
#line 633 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::FunctionalConstraint>> > () = std::move(yystack_[2].value.as < Mov<VecOwn<ast::FunctionalConstraint>> > ());
      yylhs.value.as < Mov<VecOwn<ast::FunctionalConstraint>> > ().push_back(std::move(yystack_[0].value.as < Mov<Own<ast::FunctionalConstraint>> > ()));
    }
#line 1836 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 57:
#line 641 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    { }
#line 1842 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 58:
#line 643 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::FunctionalConstraint>> > () = std::move(yystack_[0].value.as < Mov<VecOwn<ast::FunctionalConstraint>> > ());
    }
#line 1850 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 59:
#line 657 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Clause>> > () = mk<ast::Clause>(yystack_[1].value.as < Mov<Own<ast::Atom>> > (), Mov<VecOwn<ast::Literal>> {}, nullptr, yylhs.location);
    }
#line 1858 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 60:
#line 667 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Clause>> > () = yystack_[0].value.as < Mov<VecOwn<ast::Clause>> > ();
    }
#line 1866 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 61:
#line 671 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Clause>> > () = yystack_[1].value.as < Mov<VecOwn<ast::Clause>> > ();
      auto query_plan = yystack_[0].value.as < Mov<Own<ast::ExecutionPlan>> > ();
      for (auto&& rule : yylhs.value.as < Mov<VecOwn<ast::Clause>> > ()) {
        rule->setExecutionPlan(clone(query_plan));
      }
    }
#line 1878 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 62:
#line 679 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      auto bodies = yystack_[1].value.as < Mov<RuleBody> > ()->toClauseBodies();
      Own<ast::Atom> lt = nameUnnamedVariables(std::move(yystack_[5].value.as < Mov<Own<ast::Atom>> > ()));
      Own<ast::Atom> gt = std::move(yystack_[3].value.as < Mov<Own<ast::Atom>> > ());
      for (auto&& body : bodies) {
        auto cur = mk<ast::SubsumptiveClause>(clone(lt)); 
        cur->setBodyLiterals(clone(body->getBodyLiterals()));
        auto literals = cur->getBodyLiterals();
        cur->setHead(clone(lt));
        cur->addToBodyFront(clone(gt));
        cur->addToBodyFront(clone(lt));
        cur->setSrcLoc(yylhs.location);
        yylhs.value.as < Mov<VecOwn<ast::Clause>> > ().push_back(std::move(cur));
      }
    }
#line 1898 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 63:
#line 695 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      auto bodies = yystack_[2].value.as < Mov<RuleBody> > ()->toClauseBodies();
      Own<ast::Atom> lt = nameUnnamedVariables(std::move(yystack_[6].value.as < Mov<Own<ast::Atom>> > ()));
      Own<ast::Atom> gt = std::move(yystack_[4].value.as < Mov<Own<ast::Atom>> > ());
      for (auto&& body : bodies) {
        auto cur = mk<ast::SubsumptiveClause>(clone(lt)); 
        cur->setBodyLiterals(clone(body->getBodyLiterals()));
        auto literals = cur->getBodyLiterals();
        cur->setHead(clone(lt));
        cur->addToBodyFront(clone(gt));
        cur->addToBodyFront(clone(lt));
        cur->setSrcLoc(yylhs.location);
        cur->setExecutionPlan(clone(yystack_[0].value.as < Mov<Own<ast::ExecutionPlan>> > ()));
        yylhs.value.as < Mov<VecOwn<ast::Clause>> > ().push_back(std::move(cur));
      }
    }
#line 1919 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 64:
#line 718 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      auto bodies = yystack_[1].value.as < Mov<RuleBody> > ()->toClauseBodies();
      for (auto&& head : yystack_[3].value.as < Mov<VecOwn<ast::Atom>> > ()) {
        for (auto&& body : bodies) {
          auto cur = clone(body);
          cur->setHead(clone(head));
          cur->setSrcLoc(yylhs.location);
          yylhs.value.as < Mov<VecOwn<ast::Clause>> > ().push_back(std::move(cur));
        }
      }
    }
#line 1935 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 65:
#line 736 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Atom>> > ().push_back(yystack_[0].value.as < Mov<Own<ast::Atom>> > ());
    }
#line 1943 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 66:
#line 740 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Atom>> > () = yystack_[2].value.as < Mov<VecOwn<ast::Atom>> > (); yylhs.value.as < Mov<VecOwn<ast::Atom>> > ().push_back(yystack_[0].value.as < Mov<Own<ast::Atom>> > ());
    }
#line 1951 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 67:
#line 750 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<RuleBody> > () = yystack_[0].value.as < Mov<RuleBody> > ();
    }
#line 1959 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 68:
#line 757 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<RuleBody> > () = yystack_[0].value.as < Mov<RuleBody> > ();
    }
#line 1967 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 69:
#line 761 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<RuleBody> > () = yystack_[2].value.as < Mov<RuleBody> > ();
      yylhs.value.as < Mov<RuleBody> > ()->disjunct(yystack_[0].value.as < Mov<RuleBody> > ());
    }
#line 1976 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 70:
#line 769 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<RuleBody> > () = yystack_[0].value.as < Mov<RuleBody> > ();
    }
#line 1984 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 71:
#line 773 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<RuleBody> > () = yystack_[2].value.as < Mov<RuleBody> > ();
      yylhs.value.as < Mov<RuleBody> > ()->conjunct(yystack_[0].value.as < Mov<RuleBody> > ());
    }
#line 1993 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 72:
#line 784 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<RuleBody> > () = RuleBody::atom(yystack_[0].value.as < Mov<Own<ast::Atom>> > ());
    }
#line 2001 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 73:
#line 788 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<RuleBody> > () = RuleBody::constraint(yystack_[0].value.as < Mov<Own<ast::Constraint>> > ());
    }
#line 2009 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 74:
#line 792 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<RuleBody> > () = yystack_[1].value.as < Mov<RuleBody> > ();
    }
#line 2017 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 75:
#line 796 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<RuleBody> > () = yystack_[0].value.as < Mov<RuleBody> > ()->negated();
    }
#line 2025 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 76:
#line 806 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Atom>> > () = mk<ast::Atom>(yystack_[3].value.as < Mov<ast::QualifiedName> > (), yystack_[1].value.as < Mov<VecOwn<ast::Argument>> > (), yylhs.location);
    }
#line 2033 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 77:
#line 817 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Constraint>> > () = mk<ast::BinaryConstraint>(BinaryConstraintOp::LT, yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > (), yylhs.location);
    }
#line 2041 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 78:
#line 821 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Constraint>> > () = mk<ast::BinaryConstraint>(BinaryConstraintOp::GT, yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > (), yylhs.location);
    }
#line 2049 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 79:
#line 825 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Constraint>> > () = mk<ast::BinaryConstraint>(BinaryConstraintOp::LE, yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > (), yylhs.location);
    }
#line 2057 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 80:
#line 829 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Constraint>> > () = mk<ast::BinaryConstraint>(BinaryConstraintOp::GE, yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > (), yylhs.location);
    }
#line 2065 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 81:
#line 833 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Constraint>> > () = mk<ast::BinaryConstraint>(BinaryConstraintOp::EQ, yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > (), yylhs.location);
    }
#line 2073 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 82:
#line 837 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Constraint>> > () = mk<ast::BinaryConstraint>(BinaryConstraintOp::NE, yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > (), yylhs.location);
    }
#line 2081 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 83:
#line 843 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Constraint>> > () = mk<ast::BinaryConstraint>(BinaryConstraintOp::MATCH, yystack_[3].value.as < Mov<Own<ast::Argument>> > (), yystack_[1].value.as < Mov<Own<ast::Argument>> > (), yylhs.location);
    }
#line 2089 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 84:
#line 847 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
       yylhs.value.as < Mov<Own<ast::Constraint>> > () = mk<ast::BinaryConstraint>(BinaryConstraintOp::CONTAINS, yystack_[3].value.as < Mov<Own<ast::Argument>> > (), yystack_[1].value.as < Mov<Own<ast::Argument>> > (), yylhs.location);
    }
#line 2097 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 85:
#line 853 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Constraint>> > () = mk<ast::BooleanConstraint>(true , yylhs.location);
    }
#line 2105 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 86:
#line 857 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Constraint>> > () = mk<ast::BooleanConstraint>(false, yylhs.location);
    }
#line 2113 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 87:
#line 867 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
    }
#line 2120 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 88:
#line 870 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Argument>> > () = yystack_[0].value.as < Mov<VecOwn<ast::Argument>> > ();
    }
#line 2128 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 89:
#line 876 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Argument>> > ().push_back(yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2136 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 90:
#line 880 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Argument>> > () = yystack_[2].value.as < Mov<VecOwn<ast::Argument>> > (); yylhs.value.as < Mov<VecOwn<ast::Argument>> > ().push_back(yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2144 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 91:
#line 891 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::StringConstant>(yystack_[0].value.as < std::string > (), yylhs.location);
    }
#line 2152 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 92:
#line 895 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::NumericConstant>(yystack_[0].value.as < std::string > (), ast::NumericConstant::Type::Float, yylhs.location);
    }
#line 2160 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 93:
#line 899 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      auto&& n = yystack_[0].value.as < std::string > (); // drop the last character (`u`)
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::NumericConstant>(n.substr(0, n.size() - 1), ast::NumericConstant::Type::Uint, yylhs.location);
    }
#line 2169 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 94:
#line 904 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::NumericConstant>(yystack_[0].value.as < std::string > (), yylhs.location);
    }
#line 2177 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 95:
#line 908 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::UnnamedVariable>(yylhs.location);
    }
#line 2185 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 96:
#line 912 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = driver.addDeprecatedCounter(yylhs.location);
    }
#line 2193 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 97:
#line 916 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::Counter>(yylhs.location);
    }
#line 2201 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 98:
#line 920 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::Variable>(yystack_[0].value.as < std::string > (), yylhs.location);
    }
#line 2209 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 99:
#line 924 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::NilConstant>(yylhs.location);
    }
#line 2217 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 100:
#line 928 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::RecordInit>(yystack_[1].value.as < Mov<VecOwn<ast::Argument>> > (), yylhs.location);
    }
#line 2225 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 101:
#line 932 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::BranchInit>(yystack_[3].value.as < Mov<ast::QualifiedName> > (), yystack_[1].value.as < Mov<VecOwn<ast::Argument>> > (), yylhs.location);
    }
#line 2233 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 102:
#line 936 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = yystack_[1].value.as < Mov<Own<ast::Argument>> > ();
    }
#line 2241 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 103:
#line 940 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::TypeCast>(yystack_[3].value.as < Mov<Own<ast::Argument>> > (), yystack_[1].value.as < Mov<ast::QualifiedName> > (), yylhs.location);
    }
#line 2249 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 104:
#line 944 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::UserDefinedFunctor>(yystack_[3].value.as < std::string > (), *yystack_[1].value.as < Mov<VecOwn<ast::Argument>> > (), yylhs.location);
    }
#line 2257 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 105:
#line 948 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yystack_[3].value.as < Mov<std::string> > (), *yystack_[1].value.as < Mov<VecOwn<ast::Argument>> > (), yylhs.location);
    }
#line 2265 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 106:
#line 954 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      VecOwn<ast::Argument> arg_list = yystack_[1].value.as < Mov<VecOwn<ast::Argument>> > ();
      arg_list.insert(arg_list.begin(), yystack_[3].value.as < Mov<Own<ast::Argument>> > ());
      auto agg_2_func = [](AggregateOp op) -> char const* {
        switch (op) {
          case AggregateOp::COUNT : return {};
          case AggregateOp::MAX   : return "max";
          case AggregateOp::MEAN  : return {};
          case AggregateOp::MIN   : return "min";
          case AggregateOp::SUM   : return {};
          default                 :
            fatal("missing base op handler, or got an overload op?");
        }
      };
      if (auto* func_op = agg_2_func(yystack_[5].value.as < AggregateOp > ())) {
        yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(func_op, std::move(arg_list), yylhs.location);
      } else {
        driver.error(yylhs.location, "aggregate operation has no functor equivalent");
        yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::UnnamedVariable>(yylhs.location);
      }
    }
#line 2291 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 107:
#line 979 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      // If we have a constant that is not already negated we just negate the constant value.
      auto nested_arg = *yystack_[0].value.as < Mov<Own<ast::Argument>> > ();
      const auto* asNumeric = as<ast::NumericConstant>(*nested_arg);
      if (asNumeric && !isPrefix("-", asNumeric->getConstant())) {
        yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::NumericConstant>("-" + asNumeric->getConstant(), asNumeric->getFixedType(), yystack_[0].location);
      } else { // Otherwise, create a functor.
        yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, FUNCTOR_INTRINSIC_PREFIX_NEGATE_NAME, std::move(nested_arg));
      }
    }
#line 2306 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 108:
#line 990 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "~", yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2314 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 109:
#line 994 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "!", yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2322 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 110:
#line 1000 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "+"  , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2330 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 111:
#line 1004 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "-"  , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2338 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 112:
#line 1008 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "*"  , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2346 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 113:
#line 1012 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "/"  , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2354 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 114:
#line 1016 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "%"  , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2362 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 115:
#line 1020 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "**" , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2370 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 116:
#line 1024 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "&&" , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2378 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 117:
#line 1028 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "||" , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2386 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 118:
#line 1032 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "^^" , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2394 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 119:
#line 1036 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "&"  , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2402 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 120:
#line 1040 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "|"  , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2410 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 121:
#line 1044 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "^"  , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2418 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 122:
#line 1048 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, "<<" , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2426 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 123:
#line 1052 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, ">>" , yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2434 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 124:
#line 1056 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::IntrinsicFunctor>(yylhs.location, ">>>", yystack_[2].value.as < Mov<Own<ast::Argument>> > (), yystack_[0].value.as < Mov<Own<ast::Argument>> > ());
    }
#line 2442 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 125:
#line 1062 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      auto bodies = yystack_[0].value.as < Mov<RuleBody> > ()->toClauseBodies();
      if (bodies.size() != 1) {
        driver.error("ERROR: disjunctions in aggregation clauses are currently not supported");
      }
      // TODO: move this to a semantic check when aggs are extended to multiple exprs
      auto given    = yystack_[2].value.as < Mov<VecOwn<ast::Argument>> > ().size();
      auto required = aggregateArity(yystack_[3].value.as < AggregateOp > ());
      if (given < required.first || required.second < given) {
        driver.error("ERROR: incorrect expression arity for given aggregate mode");
      }
      auto expr = yystack_[2].value.as < Mov<VecOwn<ast::Argument>> > ().empty() ? nullptr : std::move(yystack_[2].value.as < Mov<VecOwn<ast::Argument>> > ()[0]);
      auto body = (bodies.size() == 1) ? clone(bodies[0]->getBodyLiterals()) : VecOwn<ast::Literal> {};
      yylhs.value.as < Mov<Own<ast::Argument>> > () = mk<ast::Aggregator>(yystack_[3].value.as < AggregateOp > (), std::move(expr), std::move(body), yylhs.location);
    }
#line 2462 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 126:
#line 1081 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = "cat";
    }
#line 2470 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 127:
#line 1085 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = "ord";
    }
#line 2478 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 128:
#line 1089 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = "range";
    }
#line 2486 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 129:
#line 1093 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = "strlen";
    }
#line 2494 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 130:
#line 1097 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = "substr";
    }
#line 2502 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 131:
#line 1101 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = "to_float";
    }
#line 2510 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 132:
#line 1105 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = "to_number";
    }
#line 2518 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 133:
#line 1109 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = "to_string";
    }
#line 2526 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 134:
#line 1113 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = "to_unsigned";
    }
#line 2534 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 135:
#line 1120 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < AggregateOp > () = AggregateOp::COUNT;
    }
#line 2542 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 136:
#line 1124 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < AggregateOp > () = AggregateOp::MAX;
    }
#line 2550 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 137:
#line 1128 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < AggregateOp > () = AggregateOp::MEAN;
    }
#line 2558 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 138:
#line 1132 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < AggregateOp > () = AggregateOp::MIN;
    }
#line 2566 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 139:
#line 1136 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < AggregateOp > () = AggregateOp::SUM;
    }
#line 2574 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 140:
#line 1143 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<RuleBody> > () = yystack_[1].value.as < Mov<RuleBody> > ();
    }
#line 2582 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 141:
#line 1147 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<RuleBody> > () = RuleBody::atom(yystack_[0].value.as < Mov<Own<ast::Atom>> > ());
    }
#line 2590 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 142:
#line 1157 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::ExecutionPlan>> > () = yystack_[0].value.as < Mov<Own<ast::ExecutionPlan>> > ();
    }
#line 2598 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 143:
#line 1163 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::ExecutionPlan>> > () = mk<ast::ExecutionPlan>();
      yylhs.value.as < Mov<Own<ast::ExecutionPlan>> > ()->setOrderFor(RamSignedFromString(yystack_[2].value.as < std::string > ()), Own<ast::ExecutionOrder>(yystack_[0].value.as < Mov<Own<ast::ExecutionOrder>> > ()));
    }
#line 2607 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 144:
#line 1168 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::ExecutionPlan>> > () = yystack_[4].value.as < Mov<Own<ast::ExecutionPlan>> > ();
      yylhs.value.as < Mov<Own<ast::ExecutionPlan>> > ()->setOrderFor(RamSignedFromString(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < Mov<Own<ast::ExecutionOrder>> > ());
    }
#line 2616 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 145:
#line 1176 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::ExecutionOrder>> > () = mk<ast::ExecutionOrder>(ast::ExecutionOrder::ExecOrder(), yylhs.location);
    }
#line 2624 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 146:
#line 1180 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::ExecutionOrder>> > () = mk<ast::ExecutionOrder>(yystack_[1].value.as < Mov<ast::ExecutionOrder::ExecOrder> > (), yylhs.location);
    }
#line 2632 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 147:
#line 1187 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<ast::ExecutionOrder::ExecOrder> > ().push_back(RamUnsignedFromString(yystack_[0].value.as < std::string > ()));
    }
#line 2640 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 148:
#line 1191 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<ast::ExecutionOrder::ExecOrder> > () = yystack_[2].value.as < Mov<ast::ExecutionOrder::ExecOrder> > (); yylhs.value.as < Mov<ast::ExecutionOrder::ExecOrder> > ().push_back(RamUnsignedFromString(yystack_[0].value.as < std::string > ()));
    }
#line 2648 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 149:
#line 1205 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      auto head = yystack_[3].value.as < Mov<Own<ast::Component>> > ();
      yylhs.value.as < Mov<Own<ast::Component>> > () = yystack_[1].value.as < Mov<Own<ast::Component>> > ();
      yylhs.value.as < Mov<Own<ast::Component>> > ()->setComponentType(clone(head->getComponentType()));
      yylhs.value.as < Mov<Own<ast::Component>> > ()->copyBaseComponents(**head);
      yylhs.value.as < Mov<Own<ast::Component>> > ()->setSrcLoc(yylhs.location);
    }
#line 2660 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 150:
#line 1219 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Component>> > () = mk<ast::Component>();
      yylhs.value.as < Mov<Own<ast::Component>> > ()->setComponentType(yystack_[0].value.as < Mov<Own<ast::ComponentType>> > ());
    }
#line 2669 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 151:
#line 1224 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Component>> > () = yystack_[2].value.as < Mov<Own<ast::Component>> > ();
      yylhs.value.as < Mov<Own<ast::Component>> > ()->addBaseComponent(yystack_[0].value.as < Mov<Own<ast::ComponentType>> > ());
    }
#line 2678 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 152:
#line 1229 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Component>> > () = yystack_[2].value.as < Mov<Own<ast::Component>> > ();
      yylhs.value.as < Mov<Own<ast::Component>> > ()->addBaseComponent(yystack_[0].value.as < Mov<Own<ast::ComponentType>> > ());
    }
#line 2687 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 153:
#line 1240 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::ComponentType>> > () = mk<ast::ComponentType>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < Mov<std::vector<ast::QualifiedName>> > (), yylhs.location);
    }
#line 2695 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 154:
#line 1249 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    { }
#line 2701 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 155:
#line 1251 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::vector<ast::QualifiedName>> > () = yystack_[1].value.as < Mov<std::vector<ast::QualifiedName>> > ();
    }
#line 2709 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 156:
#line 1261 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::vector<ast::QualifiedName>> > ().push_back(yystack_[0].value.as < std::string > ());
    }
#line 2717 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 157:
#line 1265 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::vector<ast::QualifiedName>> > () = yystack_[2].value.as < Mov<std::vector<ast::QualifiedName>> > ();
      yylhs.value.as < Mov<std::vector<ast::QualifiedName>> > ().push_back(yystack_[0].value.as < std::string > ());
    }
#line 2726 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 158:
#line 1276 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Component>> > () = mk<ast::Component>();
    }
#line 2734 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 159:
#line 1280 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Component>> > () = yystack_[1].value.as < Mov<Own<ast::Component>> > ();
      for (auto&& x : yystack_[0].value.as < Mov<VecOwn<ast::Directive>> > ()) {
        yylhs.value.as < Mov<Own<ast::Component>> > ()->addDirective(std::move(x));
      }
    }
#line 2745 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 160:
#line 1287 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Component>> > () = yystack_[1].value.as < Mov<Own<ast::Component>> > ();
      for (auto&& x : yystack_[0].value.as < Mov<VecOwn<ast::Clause>> > ()) {
        yylhs.value.as < Mov<Own<ast::Component>> > ()->addClause(std::move(x));
      }
    }
#line 2756 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 161:
#line 1294 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Component>> > () = yystack_[1].value.as < Mov<Own<ast::Component>> > ();
      yylhs.value.as < Mov<Own<ast::Component>> > ()->addClause(yystack_[0].value.as < Mov<Own<ast::Clause>> > ());
    }
#line 2765 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 162:
#line 1299 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Component>> > () = yystack_[2].value.as < Mov<Own<ast::Component>> > ();
      yylhs.value.as < Mov<Own<ast::Component>> > ()->addOverride(yystack_[0].value.as < std::string > ());
    }
#line 2774 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 163:
#line 1304 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Component>> > () = yystack_[1].value.as < Mov<Own<ast::Component>> > ();
      yylhs.value.as < Mov<Own<ast::Component>> > ()->addInstantiation(yystack_[0].value.as < Mov<Own<ast::ComponentInit>> > ());
    }
#line 2783 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 164:
#line 1309 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Component>> > () = yystack_[1].value.as < Mov<Own<ast::Component>> > ();
      yylhs.value.as < Mov<Own<ast::Component>> > ()->addComponent(yystack_[0].value.as < Mov<Own<ast::Component>> > ());
    }
#line 2792 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 165:
#line 1314 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Component>> > () = yystack_[1].value.as < Mov<Own<ast::Component>> > ();
      yylhs.value.as < Mov<Own<ast::Component>> > ()->addType(yystack_[0].value.as < Mov<Own<ast::Type>> > ());
    }
#line 2801 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 166:
#line 1319 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Component>> > () = yystack_[1].value.as < Mov<Own<ast::Component>> > ();
      for (auto&& rel : yystack_[0].value.as < Mov<VecOwn<ast::Relation>> > ()) {
        driver.addIoFromDeprecatedTag(*rel);
        yylhs.value.as < Mov<Own<ast::Component>> > ()->addRelation(std::move(rel));
      }
    }
#line 2813 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 167:
#line 1333 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::ComponentInit>> > () = mk<ast::ComponentInit>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Mov<Own<ast::ComponentType>> > (), yylhs.location);
    }
#line 2821 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 168:
#line 1347 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::FunctorDeclaration>> > () = mk<ast::FunctorDeclaration>(yystack_[5].value.as < std::string > (), yystack_[3].value.as < Mov<VecOwn<ast::Attribute>> > (), mk<ast::Attribute>("return_type", yystack_[0].value.as < Mov<ast::QualifiedName> > (), yystack_[0].location), false, yylhs.location);
    }
#line 2829 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 169:
#line 1351 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::FunctorDeclaration>> > () = mk<ast::FunctorDeclaration>(yystack_[6].value.as < std::string > (), yystack_[4].value.as < Mov<VecOwn<ast::Attribute>> > (), mk<ast::Attribute>("return_type", yystack_[1].value.as < Mov<ast::QualifiedName> > (), yystack_[1].location), true, yylhs.location);
    }
#line 2837 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 170:
#line 1360 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
           { }
#line 2843 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 171:
#line 1362 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Attribute>> > () = yystack_[0].value.as < Mov<VecOwn<ast::Attribute>> > ();
    }
#line 2851 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 172:
#line 1369 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Attribute>> > ().push_back(yystack_[0].value.as < Mov<Own<ast::Attribute>> > ());
    }
#line 2859 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 173:
#line 1373 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Attribute>> > () = yystack_[2].value.as < Mov<VecOwn<ast::Attribute>> > (); yylhs.value.as < Mov<VecOwn<ast::Attribute>> > ().push_back(yystack_[0].value.as < Mov<Own<ast::Attribute>> > ());
    }
#line 2867 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 174:
#line 1380 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Attribute>> > () = mk<ast::Attribute>("", yystack_[0].value.as < Mov<ast::QualifiedName> > (), yystack_[0].location);
    }
#line 2875 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 175:
#line 1384 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Attribute>> > () = mk<ast::Attribute>(yystack_[2].value.as < std::string > (), yystack_[0].value.as < Mov<ast::QualifiedName> > (), yystack_[0].location);
    }
#line 2883 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 176:
#line 1398 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Pragma>> > () = mk<ast::Pragma>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::string > (), yylhs.location);
    }
#line 2891 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 177:
#line 1402 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<Own<ast::Pragma>> > () = mk<ast::Pragma>(yystack_[0].value.as < std::string > (), "", yylhs.location);
    }
#line 2899 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 178:
#line 1412 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      auto directive_head_decl = yystack_[1].value.as < ast::DirectiveType > ();
      for (auto&& io : yystack_[0].value.as < Mov<VecOwn<ast::Directive>> > ()) {
        io->setType(directive_head_decl);
        yylhs.value.as < Mov<VecOwn<ast::Directive>> > ().push_back(std::move(io));
      }
    }
#line 2911 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 179:
#line 1423 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < ast::DirectiveType > () = ast::DirectiveType::input;
    }
#line 2919 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 180:
#line 1427 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < ast::DirectiveType > () = ast::DirectiveType::output;
    }
#line 2927 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 181:
#line 1431 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < ast::DirectiveType > () = ast::DirectiveType::printsize;
    }
#line 2935 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 182:
#line 1435 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < ast::DirectiveType > () = ast::DirectiveType::limitsize;
    }
#line 2943 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 183:
#line 1445 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Directive>> > () = yystack_[0].value.as < Mov<VecOwn<ast::Directive>> > ();
    }
#line 2951 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 184:
#line 1449 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Directive>> > () = yystack_[2].value.as < Mov<VecOwn<ast::Directive>> > ();
    }
#line 2959 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 185:
#line 1453 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Directive>> > () = yystack_[3].value.as < Mov<VecOwn<ast::Directive>> > ();
      for (auto&& kvp : yystack_[1].value.as < Mov<std::vector<std::pair
            <std::string, std::string>>> > ()) {
        for (auto&& io : yylhs.value.as < Mov<VecOwn<ast::Directive>> > ()) {
          io->addParameter(kvp.first, kvp.second);
        }
      }
    }
#line 2973 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 186:
#line 1468 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Directive>> > ().push_back(mk<ast::Directive>(ast::DirectiveType::input, yystack_[0].value.as < Mov<ast::QualifiedName> > (), yystack_[0].location));
    }
#line 2981 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 187:
#line 1472 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<VecOwn<ast::Directive>> > () = yystack_[2].value.as < Mov<VecOwn<ast::Directive>> > ();
      yylhs.value.as < Mov<VecOwn<ast::Directive>> > ().push_back(mk<ast::Directive>(ast::DirectiveType::input, yystack_[0].value.as < Mov<ast::QualifiedName> > (), yystack_[0].location));
    }
#line 2990 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 188:
#line 1483 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::vector<std::pair
            <std::string, std::string>>> > ().push_back({yystack_[2].value.as < std::string > (), yystack_[0].value.as < Mov<std::string> > ()});
    }
#line 2999 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 189:
#line 1487 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::vector<std::pair
            <std::string, std::string>>> > () = yystack_[4].value.as < Mov<std::vector<std::pair
            <std::string, std::string>>> > ();
      yylhs.value.as < Mov<std::vector<std::pair
            <std::string, std::string>>> > ().push_back({yystack_[2].value.as < std::string > (), yystack_[0].value.as < Mov<std::string> > ()});
    }
#line 3011 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 190:
#line 1495 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = yystack_[0].value.as < std::string > ();
    }
#line 3019 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 191:
#line 1499 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = yystack_[0].value.as < std::string > ();
    }
#line 3027 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 192:
#line 1503 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = yystack_[0].value.as < std::string > ();
    }
#line 3035 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 193:
#line 1507 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = "true";
    }
#line 3043 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;

  case 194:
#line 1511 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"
    {
      yylhs.value.as < Mov<std::string> > () = "false";
    }
#line 3051 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"
    break;


#line 3055 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"

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


  const short parser::yypact_ninf_ = -192;

  const signed char parser::yytable_ninf_ = -14;

  const short
  parser::yypact_[] =
  {
    -192,    21,   235,  -192,  -192,    22,    41,    53,  -192,  -192,
    -192,  -192,    78,    93,    96,   109,   131,   -53,  -192,  -192,
    -192,  -192,   115,   -26,   -62,  -192,    20,  -192,  -192,  -192,
    -192,   158,    87,  -192,    26,    90,   -15,    76,  -192,    85,
    -192,  -192,   264,   162,   163,  -192,   151,   158,  -192,   158,
      93,    93,  -192,    88,  -192,    39,  -192,     4,   165,  -192,
     166,    14,   158,   167,  -192,    93,  -192,  -192,  -192,  -192,
    -192,    99,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,   116,   184,  -192,   264,
    -192,   158,   264,   264,   264,   264,   119,   120,   638,   117,
     317,  -192,   121,   124,    13,   123,   127,  -192,  -192,   151,
     151,   122,   129,   133,  -192,  -192,  -192,   374,  -192,   170,
    -192,  -192,   187,     5,   158,   126,  -192,    29,  -192,  -192,
      23,   134,    88,   137,   141,  -192,   136,     6,    88,  -192,
     147,   153,  -192,    88,  -192,   -43,  -192,   152,   264,   155,
     173,    15,   142,   440,   142,   142,  -192,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   169,   168,   237,   264,   264,
    -192,    24,   341,  -192,   151,   151,   264,   264,   264,   264,
     264,   264,   151,   239,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,   171,  -192,    59,    88,   158,  -192,   242,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,     8,  -192,   158,   172,   166,    -1,  -192,   -48,   158,
     243,   245,  -192,  -192,   473,   264,  -192,   264,  -192,   638,
      27,    27,   142,   142,   142,   142,   745,   741,   321,    -7,
      -7,    -7,   712,   671,   704,   178,   407,     2,    10,  -192,
     179,   506,   539,  -192,   133,  -192,   638,   638,   638,   638,
     638,   638,   180,  -192,    19,  -192,   253,    88,  -192,  -192,
     254,  -192,   185,    88,   158,  -192,  -192,   -16,  -192,    88,
     136,  -192,  -192,   158,   191,   200,  -192,   264,   151,  -192,
    -192,  -192,  -192,    64,   168,   264,   264,   115,  -192,  -192,
    -192,  -192,  -192,  -192,   181,  -192,    66,     8,   -10,  -192,
      -8,  -192,  -192,    86,   195,  -192,   282,  -192,   572,   605,
    -192,    19,  -192,   284,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192
  };

  const unsigned char
  parser::yydefact_[] =
  {
       3,     0,     2,     1,    13,     0,     0,     0,   179,   180,
     181,   182,     0,     0,     0,     0,     0,     0,    10,    12,
       6,     5,    60,     0,    65,     7,     0,     8,    11,     9,
       4,     0,   177,    31,     0,     0,    21,   154,   150,     0,
      19,    20,    87,     0,     0,    61,     0,     0,    59,     0,
       0,     0,   158,   186,   178,   183,   176,     0,     0,    38,
     170,     0,     0,     0,   153,     0,    91,    98,    94,    93,
      92,     0,   126,   127,   128,   129,   130,   137,   138,   136,
     135,   139,   131,   132,   133,   134,     0,     0,    99,    87,
      95,    96,     0,     0,     0,     0,     0,    88,    89,     0,
      87,    14,     0,   142,    98,     0,     0,    85,    86,     0,
       0,     0,    67,    68,    70,    72,    73,     0,    66,     0,
     152,   151,     0,     0,     0,     0,    33,     0,    35,    32,
      57,    13,   174,     0,   171,   172,    13,     0,    24,    17,
      16,    18,    26,    15,   156,     0,   167,     0,     0,     0,
       0,     0,   107,     0,   108,   109,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,     0,     0,     0,     0,     0,
      75,     0,     0,    64,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   149,   165,   166,   161,   160,   164,
     163,   159,     0,   184,     0,   187,     0,    34,     0,    48,
      49,    50,    44,    45,    46,    47,    39,    40,    41,    42,
      43,     0,    30,     0,     0,     0,     0,    22,     0,     0,
       0,     0,   155,    97,     0,    87,   100,    87,   102,    90,
     110,   111,   112,   113,   115,   114,   119,   120,   121,   122,
     123,   124,   116,   117,   118,     0,     0,     0,     0,   143,
       0,     0,     0,    74,    69,    71,    81,    77,    78,    79,
      80,    82,     0,   162,     0,   185,     0,    37,    36,    53,
       0,    55,    58,   175,     0,   173,    28,     0,    23,    25,
       0,    27,   157,     0,     0,     0,   105,     0,     0,   141,
     125,   147,   145,     0,     0,     0,     0,    62,   190,   191,
     192,   193,   194,   188,     0,    51,     0,     0,   168,    29,
       0,   104,   101,     0,     0,   146,     0,   144,     0,     0,
      63,     0,    54,     0,    56,   169,   103,   106,   140,   148,
      83,    84,   189,    52
  };

  const short
  parser::yypgoto_[] =
  {
    -192,  -192,  -192,   -31,   177,  -192,  -192,  -192,    70,   182,
    -192,  -192,  -135,    94,  -192,  -192,   -14,  -192,  -192,   183,
     186,  -192,  -192,  -191,   196,   125,  -102,     9,  -192,   -84,
      16,   -42,  -192,  -192,  -192,    -6,  -192,     3,  -192,   188,
    -192,    -3,  -192,  -192,  -192,   189,  -192,  -192,  -192,    89,
    -192,   190,  -192,  -192,  -192,  -192,    -2
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     1,     2,    17,    18,   139,   140,   141,   142,    19,
      34,    59,   127,   128,   130,   316,   281,   282,   222,    20,
      21,    22,    23,   111,   112,   113,   114,   115,   116,    96,
      97,    98,    99,   100,   300,    45,   103,   259,   303,    25,
      26,    38,    64,   145,   122,    27,    28,   133,   134,   135,
      29,    30,    31,    54,    55,   204,   313
  };

  const short
  parser::yytable_[] =
  {
      53,   272,   228,   125,   117,   150,     4,   180,   125,   202,
     125,    24,   279,    46,   335,   301,   175,    48,   136,   288,
      42,     3,   308,   309,   310,    32,    43,   208,    49,   132,
     138,   143,   231,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    33,   232,   120,   121,    47,
     152,   153,   154,   155,   311,   312,   118,    35,   119,   208,
     151,   221,   146,   158,   159,    61,   336,   117,   182,    43,
     319,    43,    62,   227,   160,   161,   162,   163,   126,   203,
     137,   280,    36,   265,   302,   286,   -13,   298,   237,   255,
      56,   287,   -13,   205,    43,    50,    51,    37,   263,    57,
      39,    58,   184,   207,   208,    52,   234,   324,   160,   161,
     162,   163,   123,    40,   124,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    24,   256,   275,   276,    41,   261,   262,   325,   326,
     332,   333,   117,   117,   266,   267,   268,   269,   270,   271,
     117,   294,    44,   295,    66,   104,    68,    69,    70,    71,
     337,   157,     4,    60,    63,    65,   101,    43,   102,   129,
     131,   144,   147,   105,   106,   277,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,   107,   108,   149,   148,
     173,     4,   283,   156,   132,   157,   178,   176,   289,   177,
     179,   183,   206,    82,    83,    84,    85,   184,   185,   192,
     223,   224,   229,    86,    87,    88,   225,    89,   230,    90,
      91,   226,    92,   109,   110,   162,   233,     6,   235,     8,
       9,    10,    11,   193,    12,    13,    14,    15,    16,     4,
     236,   258,   260,   273,     5,   257,   125,   290,   284,   292,
      94,   274,   296,   318,    95,   304,   117,   314,   315,   307,
     317,   331,   320,   328,   329,   321,   299,    66,    67,    68,
      69,    70,    71,   194,   322,     6,     7,     8,     9,    10,
      11,   338,    12,    13,    14,    15,    16,   339,   343,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   195,
     291,   330,   278,   334,   196,   197,   181,   327,   198,   264,
     199,   200,   201,   323,   285,     0,    82,    83,    84,    85,
      66,    67,    68,    69,    70,    71,    86,    87,    88,   342,
      89,     0,    90,    91,     0,    92,     0,    93,     0,     0,
       0,     0,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,     0,     0,     0,    95,     0,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,    86,
      87,    88,     0,    89,     0,    90,    91,     0,    92,     0,
     174,   158,   159,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,   161,   162,   163,     0,     0,     0,     0,
       0,   158,   159,     0,   164,   238,    94,   167,   168,   169,
      95,   186,   160,   161,   162,   163,     0,     0,     0,   187,
     188,   189,   190,   191,   164,   165,   166,   167,   168,   169,
       0,   170,   171,   172,   158,   159,     0,     0,     0,     0,
       0,     0,     0,     0,   186,   160,   161,   162,   163,     0,
       0,     0,   187,   188,   189,   190,   191,   164,   165,   166,
     167,   168,   169,     0,   170,   171,   172,   158,   159,     0,
       0,   238,   297,     0,     0,     0,     0,     0,   160,   161,
     162,   163,     0,     0,     0,     0,     0,     0,     0,     0,
     164,   165,   166,   167,   168,   169,     0,   170,   171,   172,
     158,   159,     0,     0,   238,     0,     0,     0,     0,     0,
       0,   160,   161,   162,   163,     0,     0,     0,     0,     0,
       0,     0,     0,   164,   165,   166,   167,   168,   169,     0,
     170,   171,   172,   158,   159,     0,     0,     0,   293,     0,
       0,     0,     0,     0,   160,   161,   162,   163,     0,     0,
       0,     0,     0,     0,     0,     0,   164,   165,   166,   167,
     168,   169,     0,   170,   171,   172,   158,   159,     0,     0,
       0,   305,     0,     0,     0,     0,     0,   160,   161,   162,
     163,     0,     0,     0,     0,     0,     0,     0,     0,   164,
     165,   166,   167,   168,   169,     0,   170,   171,   172,   158,
     159,     0,     0,     0,   306,     0,     0,     0,     0,     0,
     160,   161,   162,   163,     0,     0,     0,     0,     0,     0,
       0,     0,   164,   165,   166,   167,   168,   169,     0,   170,
     171,   172,   158,   159,     0,     0,   340,     0,     0,     0,
       0,     0,     0,   160,   161,   162,   163,     0,     0,     0,
       0,     0,     0,     0,     0,   164,   165,   166,   167,   168,
     169,     0,   170,   171,   172,   158,   159,     0,     0,   341,
       0,     0,     0,     0,     0,     0,   160,   161,   162,   163,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   165,
     166,   167,   168,   169,     0,   170,   171,   172,   158,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   160,
     161,   162,   163,     0,     0,     0,     0,     0,     0,     0,
       0,   164,   165,   166,   167,   168,   169,     0,   170,   171,
     172,   158,   159,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,   161,   162,   163,     0,     0,     0,     0,
       0,     0,     0,     0,   164,   165,   166,   167,   168,   169,
       0,   170,     0,   172,   158,   159,     0,     0,     0,     0,
       0,     0,   158,   159,     0,   160,   161,   162,   163,     0,
       0,     0,     0,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,     0,   170,   164,   165,   166,   167,   168,
     169,   158,   159,     0,     0,   158,   159,     0,     0,     0,
       0,     0,   160,   161,   162,   163,   160,   161,   162,   163,
       0,     0,     0,     0,   164,     0,   166,   167,   168,   169,
       0,   167,   168,   169
  };

  const short
  parser::yycheck_[] =
  {
      31,   192,   137,     4,    46,    89,     4,   109,     4,     4,
       4,     2,     4,    39,    24,     5,   100,    79,     4,    67,
      73,     0,     3,     4,     5,     3,    79,    75,    90,    60,
      61,    62,    75,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     4,    89,    50,    51,    75,
      92,    93,    94,    95,    35,    36,    47,     4,    49,    75,
      91,    38,    65,    70,    71,    80,    74,   109,   110,    79,
      86,    79,    87,    67,    81,    82,    83,    84,    74,    74,
      66,    73,     4,   185,    74,    86,    73,    85,    73,   173,
       3,   226,    79,   124,    79,    75,    76,     4,    74,    73,
       4,    75,    78,    74,    75,    85,   148,   298,    81,    82,
      83,    84,    73,     4,    75,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   122,   174,    74,    75,     4,   178,   179,    74,    75,
      74,    75,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   235,    37,   237,     3,     4,     5,     6,     7,     8,
      74,    75,     4,    73,    88,    80,     4,    79,     5,     4,
       4,     4,    73,    22,    23,   206,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,     4,    73,
      73,     4,   223,    74,   225,    75,    73,    76,   229,    75,
      73,    79,    76,    52,    53,    54,    55,    78,    75,    39,
      76,    74,    65,    62,    63,    64,    75,    66,    65,    68,
      69,    85,    71,    72,    73,    83,    74,    40,    73,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,     4,
      67,    73,     5,     4,     9,    76,     4,     4,    76,     4,
      99,    80,    74,   284,   103,    76,   298,     4,     4,    79,
      75,    80,   293,   305,   306,    74,   257,     3,     4,     5,
       6,     7,     8,    86,    74,    40,    41,    42,    43,    44,
      45,    86,    47,    48,    49,    50,    51,     5,     4,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,   122,
     230,   307,   208,   317,   122,   122,   110,   304,   122,   184,
     122,   122,   122,   297,   225,    -1,    52,    53,    54,    55,
       3,     4,     5,     6,     7,     8,    62,    63,    64,   331,
      66,    -1,    68,    69,    -1,    71,    -1,    73,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,   103,    -1,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    -1,    66,    -1,    68,    69,    -1,    71,    -1,
      73,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    93,    74,    99,    96,    97,    98,
     103,    80,    81,    82,    83,    84,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    -1,
      -1,    -1,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    70,    71,    -1,
      -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      70,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,    70,    71,    -1,    -1,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    70,    71,    -1,    -1,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,    70,
      71,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    70,    71,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    -1,   100,   101,   102,    70,    71,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,    98,
      -1,   100,    -1,   102,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    -1,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    93,    94,    95,
      96,    97,    98,    -1,   100,    93,    94,    95,    96,    97,
      98,    70,    71,    -1,    -1,    70,    71,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    93,    -1,    95,    96,    97,    98,
      -1,    96,    97,    98
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,   106,   107,     0,     4,     9,    40,    41,    42,    43,
      44,    45,    47,    48,    49,    50,    51,   108,   109,   114,
     124,   125,   126,   127,   132,   144,   145,   150,   151,   155,
     156,   157,     3,     4,   115,     4,     4,     4,   146,     4,
       4,     4,    73,    79,    37,   140,    39,    75,    79,    90,
      75,    76,    85,   108,   158,   159,     3,    73,    75,   116,
      73,    80,    87,    88,   147,    80,     3,     4,     5,     6,
       7,     8,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    52,    53,    54,    55,    62,    63,    64,    66,
      68,    69,    71,    73,    99,   103,   134,   135,   136,   137,
     138,     4,     5,   141,     4,    22,    23,    35,    36,    72,
      73,   128,   129,   130,   131,   132,   133,   136,   132,   132,
     146,   146,   149,    73,    75,     4,    74,   117,   118,     4,
     119,     4,   108,   152,   153,   154,     4,    66,   108,   110,
     111,   112,   113,   108,     4,   148,   146,    73,    73,     4,
     134,   108,   136,   136,   136,   136,    74,    75,    70,    71,
      81,    82,    83,    84,    93,    94,    95,    96,    97,    98,
     100,   101,   102,    73,    73,   134,    76,    75,    73,    73,
     131,   129,   136,    79,    78,    75,    80,    88,    89,    90,
      91,    92,    39,    46,    86,   109,   114,   124,   125,   144,
     150,   156,     4,    74,   160,   108,    76,    74,    75,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    38,   123,    76,    74,    75,    85,    67,   117,    65,
      65,    75,    89,    74,   136,    73,    67,    73,    74,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   134,   136,    76,    73,   142,
       5,   136,   136,    74,   130,   131,   136,   136,   136,   136,
     136,   136,   128,     4,    80,    74,    75,   108,   118,     4,
      73,   121,   122,   108,    76,   154,    86,   117,    67,   108,
       4,   113,     4,    75,   134,   134,    74,    75,    85,   132,
     139,     5,    74,   143,    76,    75,    75,    79,     3,     4,
       5,    35,    36,   161,     4,     4,   120,    75,   108,    86,
     108,    74,    74,   135,   128,    74,    75,   142,   136,   136,
     140,    80,    74,    75,   121,    24,    74,    74,    86,     5,
      74,    74,   161,     4
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   105,   106,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   108,   108,   109,   109,   109,   109,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   113,   113,
     114,   115,   115,   116,   116,   117,   117,   118,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   120,   120,   121,   121,   122,   122,   123,   123,   124,
     125,   125,   125,   125,   126,   127,   127,   128,   129,   129,
     130,   130,   131,   131,   131,   131,   132,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   134,   134,   135,
     135,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   138,   138,   138,   138,   138,
     139,   139,   140,   141,   141,   142,   142,   143,   143,   144,
     145,   145,   145,   146,   147,   147,   148,   148,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   150,   151,   151,
     152,   152,   153,   153,   154,   154,   155,   155,   156,   157,
     157,   157,   157,   158,   158,   158,   159,   159,   160,   160,
     161,   161,   161,   161,   161
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     3,     4,     4,     4,     4,     2,
       2,     2,     2,     3,     1,     3,     1,     3,     3,     4,
       5,     1,     3,     2,     3,     1,     3,     3,     0,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     1,     3,     1,     3,     0,     2,     2,
       1,     2,     6,     7,     4,     1,     3,     1,     1,     3,
       1,     3,     1,     1,     3,     2,     4,     3,     3,     3,
       3,     3,     3,     6,     6,     1,     1,     0,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       3,     5,     3,     6,     5,     4,     6,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     5,     2,     3,     1,     3,     4,
       2,     3,     3,     2,     0,     3,     1,     3,     0,     2,
       2,     2,     3,     2,     2,     2,     2,     4,     7,     8,
       0,     1,     1,     3,     1,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     3,     4,     1,     3,     3,     5,
       1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"symbol\"",
  "\"identifier\"", "\"number\"", "\"unsigned number\"", "\"float\"",
  "\"auto-increment functor\"", "\"pragma directive\"",
  "\"relation qualifier output\"", "\"relation qualifier input\"",
  "\"relation qualifier printsize\"", "\"BRIE datastructure qualifier\"",
  "\"BTREE datastructure qualifier\"",
  "\"BTREE_DELETE datastructure qualifier\"",
  "\"equivalence relation qualifier\"",
  "\"relation qualifier overidable\"", "\"relation qualifier inline\"",
  "\"relation qualifier no_inline\"", "\"relation qualifier magic\"",
  "\"relation qualifier no_magic\"", "\"match predicate\"",
  "\"checks whether substring is contained in a string\"",
  "\"stateful functor\"", "\"concatenation of strings\"",
  "\"ordinal number of a string\"", "\"range\"", "\"length of a string\"",
  "\"sub-string of a string\"", "\"mean aggregator\"",
  "\"min aggregator\"", "\"max aggregator\"", "\"count aggregator\"",
  "\"sum aggregator\"", "\"true literal constraint\"",
  "\"false literal constraint\"", "\"plan keyword\"", "\"choice-domain\"",
  "\":-\"", "\"relation declaration\"", "\"functor declaration\"",
  "\"input directives declaration\"", "\"output directives declaration\"",
  "\"printsize directives declaration\"",
  "\"limitsize directives declaration\"",
  "\"override rules of super-component\"", "\"type declaration\"",
  "\"component declaration\"", "\"component instantiation\"",
  "\"numeric type declaration\"", "\"symbolic type declaration\"",
  "\"convert to float\"", "\"convert to signed integer\"",
  "\"convert to string\"", "\"convert to unsigned integer\"",
  "\"convert int to unsigned\"", "\"convert int to float\"",
  "\"convert unsigned to int\"", "\"convert unsigned to float\"",
  "\"convert float to int\"", "\"convert float to unsigned\"",
  "\"type cast\"", "\"@\"", "\"nil reference\"", "\"|\"", "\"[\"", "\"]\"",
  "\"_\"", "\"$\"", "\"+\"", "\"-\"", "\"!\"", "\"(\"", "\")\"", "\",\"",
  "\":\"", "\"::\"", "\";\"", "\".\"", "\"=\"", "\"*\"", "\"/\"", "\"^\"",
  "\"%\"", "\"{\"", "\"}\"", "\"<:\"", "\"<\"", "\">\"", "\"<=\"",
  "\">=\"", "\"!=\"", "\"band\"", "\"bor\"", "\"bxor\"", "\"bshl\"",
  "\"bshr\"", "\"bshru\"", "\"bnot\"", "\"land\"", "\"lor\"", "\"lxor\"",
  "\"lnot\"", "NEG", "$accept", "program", "unit", "qualified_name",
  "type_decl", "record_type_list", "union_type_list", "adt_branch_list",
  "adt_branch", "relation_decl", "relation_names", "attributes_list",
  "non_empty_attributes", "attribute", "relation_tags",
  "non_empty_attribute_names", "dependency", "dependency_list_aux",
  "dependency_list", "fact", "rule", "rule_def", "head", "body",
  "disjunction", "conjunction", "term", "atom", "constraint", "arg_list",
  "non_empty_arg_list", "arg", "functor_built_in", "aggregate_func",
  "aggregate_body", "query_plan", "query_plan_list", "plan_order",
  "non_empty_plan_order_list", "component_decl", "component_head",
  "component_type", "component_type_params", "component_param_list",
  "component_body", "component_init", "functor_decl",
  "functor_arg_type_list", "non_empty_functor_arg_type_list",
  "functor_attribute", "pragma", "directive_head", "directive_head_decl",
  "directive_list", "relation_directive_list", "non_empty_key_value_pairs",
  "kvp_value", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   304,   304,   311,   313,   318,   323,   327,   331,   335,
     339,   343,   347,   361,   365,   375,   379,   388,   392,   397,
     401,   405,   414,   416,   424,   428,   436,   440,   448,   452,
     466,   493,   497,   508,   511,   518,   522,   530,   540,   542,
     546,   550,   554,   558,   562,   566,   570,   574,   579,   583,
     587,   597,   602,   613,   617,   628,   632,   640,   642,   656,
     666,   670,   678,   694,   717,   735,   739,   749,   756,   760,
     768,   772,   783,   787,   791,   795,   805,   816,   820,   824,
     828,   832,   836,   842,   846,   852,   856,   866,   869,   875,
     879,   890,   894,   898,   903,   907,   911,   915,   919,   923,
     927,   931,   935,   939,   943,   947,   953,   978,   989,   993,
     999,  1003,  1007,  1011,  1015,  1019,  1023,  1027,  1031,  1035,
    1039,  1043,  1047,  1051,  1055,  1061,  1080,  1084,  1088,  1092,
    1096,  1100,  1104,  1108,  1112,  1119,  1123,  1127,  1131,  1135,
    1142,  1146,  1156,  1162,  1167,  1175,  1179,  1186,  1190,  1204,
    1218,  1223,  1228,  1239,  1248,  1250,  1260,  1264,  1275,  1279,
    1286,  1293,  1298,  1303,  1308,  1313,  1318,  1332,  1346,  1350,
    1360,  1361,  1368,  1372,  1379,  1383,  1397,  1401,  1411,  1422,
    1426,  1430,  1434,  1444,  1448,  1452,  1467,  1471,  1482,  1486,
    1494,  1498,  1502,  1506,  1510
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
#line 3820 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.cc"

#line 1516 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"


void yy::parser::error(const location_type &l, const std::string &m)
{
  driver.error(l, m);
}
