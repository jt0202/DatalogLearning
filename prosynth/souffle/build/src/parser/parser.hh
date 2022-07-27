// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file /home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_HOME_JOHANNES_TEST2_POPL2020_ARTIFACT_PROSYNTH_SOUFFLE_BUILD_SRC_PARSER_PARSER_HH_INCLUDED
# define YY_YY_HOME_JOHANNES_TEST2_POPL2020_ARTIFACT_PROSYNTH_SOUFFLE_BUILD_SRC_PARSER_PARSER_HH_INCLUDED
// "%code requires" blocks.
#line 36 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/src/parser/parser.yy"

    #include "AggregateOp.h"
    #include "FunctorOps.h"
    #include "ast/Aggregator.h"
    #include "ast/AliasType.h"
    #include "ast/AlgebraicDataType.h"
    #include "ast/Argument.h"
    #include "ast/Atom.h"
    #include "ast/Attribute.h"
    #include "ast/BinaryConstraint.h"
    #include "ast/BooleanConstraint.h"
    #include "ast/BranchType.h"
    #include "ast/BranchInit.h"
    #include "ast/Clause.h"
    #include "ast/Component.h"
    #include "ast/ComponentInit.h"
    #include "ast/ComponentType.h"
    #include "ast/Constraint.h"
    #include "ast/Counter.h"
    #include "ast/Directive.h"
    #include "ast/ExecutionOrder.h"
    #include "ast/ExecutionPlan.h"
    #include "ast/FunctionalConstraint.h"
    #include "ast/FunctorDeclaration.h"
    #include "ast/IntrinsicFunctor.h"
    #include "ast/Literal.h"
    #include "ast/NilConstant.h"
    #include "ast/NumericConstant.h"
    #include "ast/Pragma.h"
    #include "ast/QualifiedName.h"
    #include "ast/RecordInit.h"
    #include "ast/RecordType.h"
    #include "ast/Relation.h"
    #include "ast/StringConstant.h"
    #include "ast/SubsetType.h"
    #include "ast/SubsumptiveClause.h"
    #include "ast/Type.h"
    #include "ast/TypeCast.h"
    #include "ast/UnionType.h"
    #include "ast/UnnamedVariable.h"
    #include "ast/UserDefinedFunctor.h"
    #include "ast/Variable.h"
    #include "parser/Helper.h"
    #include "parser/ParserUtils.h"
    #include "souffle/RamTypes.h"
    #include "souffle/BinaryConstraintOps.h"
    #include "souffle/utility/ContainerUtil.h"
    #include "souffle/utility/StringUtil.h"

    #include <ostream>
    #include <string>
    #include <vector>

    using namespace souffle;

    using namespace souffle::parser;

    using yyscan_t = void*;

    #define YY_NULLPTR nullptr

    /* Macro to update locations as parsing proceeds */
#define YYLLOC_DEFAULT(Cur, Rhs, N)               \
    do {                                          \
        if (N) {                                  \
            (Cur).start = YYRHSLOC(Rhs, 1).start; \
            (Cur).end = YYRHSLOC(Rhs, N).end;     \
            (Cur).file = YYRHSLOC(Rhs, N).file;   \
        } else {                                  \
            (Cur).start = YYRHSLOC(Rhs, 0).end;   \
            (Cur).end = YYRHSLOC(Rhs, 0).end;     \
            (Cur).file = YYRHSLOC(Rhs, 0).file;   \
        }                                         \
    } while (0)

#line 124 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.hh"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif

#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 258 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // aggregate_func
      char dummy1[sizeof (AggregateOp)];

      // arg
      char dummy2[sizeof (Mov<Own<ast::Argument>>)];

      // atom
      char dummy3[sizeof (Mov<Own<ast::Atom>>)];

      // attribute
      // functor_attribute
      char dummy4[sizeof (Mov<Own<ast::Attribute>>)];

      // adt_branch
      char dummy5[sizeof (Mov<Own<ast::BranchType>>)];

      // fact
      char dummy6[sizeof (Mov<Own<ast::Clause>>)];

      // component_decl
      // component_head
      // component_body
      char dummy7[sizeof (Mov<Own<ast::Component>>)];

      // component_init
      char dummy8[sizeof (Mov<Own<ast::ComponentInit>>)];

      // component_type
      char dummy9[sizeof (Mov<Own<ast::ComponentType>>)];

      // constraint
      char dummy10[sizeof (Mov<Own<ast::Constraint>>)];

      // plan_order
      char dummy11[sizeof (Mov<Own<ast::ExecutionOrder>>)];

      // query_plan
      // query_plan_list
      char dummy12[sizeof (Mov<Own<ast::ExecutionPlan>>)];

      // dependency
      char dummy13[sizeof (Mov<Own<ast::FunctionalConstraint>>)];

      // functor_decl
      char dummy14[sizeof (Mov<Own<ast::FunctorDeclaration>>)];

      // pragma
      char dummy15[sizeof (Mov<Own<ast::Pragma>>)];

      // type_decl
      char dummy16[sizeof (Mov<Own<ast::Type>>)];

      // body
      // disjunction
      // conjunction
      // term
      // aggregate_body
      char dummy17[sizeof (Mov<RuleBody>)];

      // arg_list
      // non_empty_arg_list
      char dummy18[sizeof (Mov<VecOwn<ast::Argument>>)];

      // head
      char dummy19[sizeof (Mov<VecOwn<ast::Atom>>)];

      // record_type_list
      // attributes_list
      // non_empty_attributes
      // functor_arg_type_list
      // non_empty_functor_arg_type_list
      char dummy20[sizeof (Mov<VecOwn<ast::Attribute>>)];

      // adt_branch_list
      char dummy21[sizeof (Mov<VecOwn<ast::BranchType>>)];

      // rule
      // rule_def
      char dummy22[sizeof (Mov<VecOwn<ast::Clause>>)];

      // directive_head
      // directive_list
      // relation_directive_list
      char dummy23[sizeof (Mov<VecOwn<ast::Directive>>)];

      // dependency_list_aux
      // dependency_list
      char dummy24[sizeof (Mov<VecOwn<ast::FunctionalConstraint>>)];

      // relation_decl
      // relation_names
      char dummy25[sizeof (Mov<VecOwn<ast::Relation>>)];

      // non_empty_plan_order_list
      char dummy26[sizeof (Mov<ast::ExecutionOrder::ExecOrder>)];

      // qualified_name
      char dummy27[sizeof (Mov<ast::QualifiedName>)];

      // functor_built_in
      // kvp_value
      char dummy28[sizeof (Mov<std::string>)];

      // union_type_list
      // component_type_params
      // component_param_list
      char dummy29[sizeof (Mov<std::vector<ast::QualifiedName>>)];

      // non_empty_key_value_pairs
      char dummy30[sizeof (Mov<std::vector<std::pair
            <std::string, std::string>>>)];

      // non_empty_attribute_names
      char dummy31[sizeof (Mov<std::vector<std::string>>)];

      // directive_head_decl
      char dummy32[sizeof (ast::DirectiveType)];

      // relation_tags
      char dummy33[sizeof (std::set<RelationTag>)];

      // "symbol"
      // "identifier"
      // "number"
      // "unsigned number"
      // "float"
      char dummy34[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef SrcLocation location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        STRING = 258,
        IDENT = 259,
        NUMBER = 260,
        UNSIGNED = 261,
        FLOAT = 262,
        AUTOINC = 263,
        PRAGMA = 264,
        OUTPUT_QUALIFIER = 265,
        INPUT_QUALIFIER = 266,
        PRINTSIZE_QUALIFIER = 267,
        BRIE_QUALIFIER = 268,
        BTREE_QUALIFIER = 269,
        BTREE_DELETE_QUALIFIER = 270,
        EQREL_QUALIFIER = 271,
        OVERRIDABLE_QUALIFIER = 272,
        INLINE_QUALIFIER = 273,
        NO_INLINE_QUALIFIER = 274,
        MAGIC_QUALIFIER = 275,
        NO_MAGIC_QUALIFIER = 276,
        TMATCH = 277,
        TCONTAINS = 278,
        STATEFUL = 279,
        CAT = 280,
        ORD = 281,
        RANGE = 282,
        STRLEN = 283,
        SUBSTR = 284,
        MEAN = 285,
        MIN = 286,
        MAX = 287,
        COUNT = 288,
        SUM = 289,
        TRUELIT = 290,
        FALSELIT = 291,
        PLAN = 292,
        CHOICEDOMAIN = 293,
        IF = 294,
        DECL = 295,
        FUNCTOR = 296,
        INPUT_DECL = 297,
        OUTPUT_DECL = 298,
        PRINTSIZE_DECL = 299,
        LIMITSIZE_DECL = 300,
        OVERRIDE = 301,
        TYPE = 302,
        COMPONENT = 303,
        INSTANTIATE = 304,
        NUMBER_TYPE = 305,
        SYMBOL_TYPE = 306,
        TOFLOAT = 307,
        TONUMBER = 308,
        TOSTRING = 309,
        TOUNSIGNED = 310,
        ITOU = 311,
        ITOF = 312,
        UTOI = 313,
        UTOF = 314,
        FTOI = 315,
        FTOU = 316,
        AS = 317,
        AT = 318,
        NIL = 319,
        PIPE = 320,
        LBRACKET = 321,
        RBRACKET = 322,
        UNDERSCORE = 323,
        DOLLAR = 324,
        PLUS = 325,
        MINUS = 326,
        EXCLAMATION = 327,
        LPAREN = 328,
        RPAREN = 329,
        COMMA = 330,
        COLON = 331,
        DOUBLECOLON = 332,
        SEMICOLON = 333,
        DOT = 334,
        EQUALS = 335,
        STAR = 336,
        SLASH = 337,
        CARET = 338,
        PERCENT = 339,
        LBRACE = 340,
        RBRACE = 341,
        SUBTYPE = 342,
        LT = 343,
        GT = 344,
        LE = 345,
        GE = 346,
        NE = 347,
        BW_AND = 348,
        BW_OR = 349,
        BW_XOR = 350,
        BW_SHIFT_L = 351,
        BW_SHIFT_R = 352,
        BW_SHIFT_R_UNSIGNED = 353,
        BW_NOT = 354,
        L_AND = 355,
        L_OR = 356,
        L_XOR = 357,
        L_NOT = 358,
        NEG = 359
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AggregateOp&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AggregateOp& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::Argument>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::Argument>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::Atom>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::Atom>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::Attribute>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::Attribute>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::BranchType>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::BranchType>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::Clause>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::Clause>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::Component>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::Component>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::ComponentInit>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::ComponentInit>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::ComponentType>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::ComponentType>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::Constraint>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::Constraint>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::ExecutionOrder>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::ExecutionOrder>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::ExecutionPlan>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::ExecutionPlan>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::FunctionalConstraint>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::FunctionalConstraint>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::FunctorDeclaration>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::FunctorDeclaration>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::Pragma>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::Pragma>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<Own<ast::Type>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<Own<ast::Type>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<RuleBody>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<RuleBody>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<VecOwn<ast::Argument>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<VecOwn<ast::Argument>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<VecOwn<ast::Atom>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<VecOwn<ast::Atom>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<VecOwn<ast::Attribute>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<VecOwn<ast::Attribute>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<VecOwn<ast::BranchType>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<VecOwn<ast::BranchType>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<VecOwn<ast::Clause>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<VecOwn<ast::Clause>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<VecOwn<ast::Directive>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<VecOwn<ast::Directive>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<VecOwn<ast::FunctionalConstraint>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<VecOwn<ast::FunctionalConstraint>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<VecOwn<ast::Relation>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<VecOwn<ast::Relation>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<ast::ExecutionOrder::ExecOrder>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<ast::ExecutionOrder::ExecOrder>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<ast::QualifiedName>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<ast::QualifiedName>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<std::string>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<std::string>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<std::vector<ast::QualifiedName>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<std::vector<ast::QualifiedName>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<std::vector<std::pair
            <std::string, std::string>>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<std::vector<std::pair
            <std::string, std::string>>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mov<std::vector<std::string>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mov<std::vector<std::string>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ast::DirectiveType&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ast::DirectiveType& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::set<RelationTag>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::set<RelationTag>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 138: // aggregate_func
        value.template destroy< AggregateOp > ();
        break;

      case 136: // arg
        value.template destroy< Mov<Own<ast::Argument>> > ();
        break;

      case 132: // atom
        value.template destroy< Mov<Own<ast::Atom>> > ();
        break;

      case 118: // attribute
      case 154: // functor_attribute
        value.template destroy< Mov<Own<ast::Attribute>> > ();
        break;

      case 113: // adt_branch
        value.template destroy< Mov<Own<ast::BranchType>> > ();
        break;

      case 124: // fact
        value.template destroy< Mov<Own<ast::Clause>> > ();
        break;

      case 144: // component_decl
      case 145: // component_head
      case 149: // component_body
        value.template destroy< Mov<Own<ast::Component>> > ();
        break;

      case 150: // component_init
        value.template destroy< Mov<Own<ast::ComponentInit>> > ();
        break;

      case 146: // component_type
        value.template destroy< Mov<Own<ast::ComponentType>> > ();
        break;

      case 133: // constraint
        value.template destroy< Mov<Own<ast::Constraint>> > ();
        break;

      case 142: // plan_order
        value.template destroy< Mov<Own<ast::ExecutionOrder>> > ();
        break;

      case 140: // query_plan
      case 141: // query_plan_list
        value.template destroy< Mov<Own<ast::ExecutionPlan>> > ();
        break;

      case 121: // dependency
        value.template destroy< Mov<Own<ast::FunctionalConstraint>> > ();
        break;

      case 151: // functor_decl
        value.template destroy< Mov<Own<ast::FunctorDeclaration>> > ();
        break;

      case 155: // pragma
        value.template destroy< Mov<Own<ast::Pragma>> > ();
        break;

      case 109: // type_decl
        value.template destroy< Mov<Own<ast::Type>> > ();
        break;

      case 128: // body
      case 129: // disjunction
      case 130: // conjunction
      case 131: // term
      case 139: // aggregate_body
        value.template destroy< Mov<RuleBody> > ();
        break;

      case 134: // arg_list
      case 135: // non_empty_arg_list
        value.template destroy< Mov<VecOwn<ast::Argument>> > ();
        break;

      case 127: // head
        value.template destroy< Mov<VecOwn<ast::Atom>> > ();
        break;

      case 110: // record_type_list
      case 116: // attributes_list
      case 117: // non_empty_attributes
      case 152: // functor_arg_type_list
      case 153: // non_empty_functor_arg_type_list
        value.template destroy< Mov<VecOwn<ast::Attribute>> > ();
        break;

      case 112: // adt_branch_list
        value.template destroy< Mov<VecOwn<ast::BranchType>> > ();
        break;

      case 125: // rule
      case 126: // rule_def
        value.template destroy< Mov<VecOwn<ast::Clause>> > ();
        break;

      case 156: // directive_head
      case 158: // directive_list
      case 159: // relation_directive_list
        value.template destroy< Mov<VecOwn<ast::Directive>> > ();
        break;

      case 122: // dependency_list_aux
      case 123: // dependency_list
        value.template destroy< Mov<VecOwn<ast::FunctionalConstraint>> > ();
        break;

      case 114: // relation_decl
      case 115: // relation_names
        value.template destroy< Mov<VecOwn<ast::Relation>> > ();
        break;

      case 143: // non_empty_plan_order_list
        value.template destroy< Mov<ast::ExecutionOrder::ExecOrder> > ();
        break;

      case 108: // qualified_name
        value.template destroy< Mov<ast::QualifiedName> > ();
        break;

      case 137: // functor_built_in
      case 161: // kvp_value
        value.template destroy< Mov<std::string> > ();
        break;

      case 111: // union_type_list
      case 147: // component_type_params
      case 148: // component_param_list
        value.template destroy< Mov<std::vector<ast::QualifiedName>> > ();
        break;

      case 160: // non_empty_key_value_pairs
        value.template destroy< Mov<std::vector<std::pair
            <std::string, std::string>>> > ();
        break;

      case 120: // non_empty_attribute_names
        value.template destroy< Mov<std::vector<std::string>> > ();
        break;

      case 157: // directive_head_decl
        value.template destroy< ast::DirectiveType > ();
        break;

      case 119: // relation_tags
        value.template destroy< std::set<RelationTag> > ();
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 5: // "number"
      case 6: // "unsigned number"
      case 7: // "float"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::END || tok == token::AUTOINC || tok == token::PRAGMA || tok == token::OUTPUT_QUALIFIER || tok == token::INPUT_QUALIFIER || tok == token::PRINTSIZE_QUALIFIER || tok == token::BRIE_QUALIFIER || tok == token::BTREE_QUALIFIER || tok == token::BTREE_DELETE_QUALIFIER || tok == token::EQREL_QUALIFIER || tok == token::OVERRIDABLE_QUALIFIER || tok == token::INLINE_QUALIFIER || tok == token::NO_INLINE_QUALIFIER || tok == token::MAGIC_QUALIFIER || tok == token::NO_MAGIC_QUALIFIER || tok == token::TMATCH || tok == token::TCONTAINS || tok == token::STATEFUL || tok == token::CAT || tok == token::ORD || tok == token::RANGE || tok == token::STRLEN || tok == token::SUBSTR || tok == token::MEAN || tok == token::MIN || tok == token::MAX || tok == token::COUNT || tok == token::SUM || tok == token::TRUELIT || tok == token::FALSELIT || tok == token::PLAN || tok == token::CHOICEDOMAIN || tok == token::IF || tok == token::DECL || tok == token::FUNCTOR || tok == token::INPUT_DECL || tok == token::OUTPUT_DECL || tok == token::PRINTSIZE_DECL || tok == token::LIMITSIZE_DECL || tok == token::OVERRIDE || tok == token::TYPE || tok == token::COMPONENT || tok == token::INSTANTIATE || tok == token::NUMBER_TYPE || tok == token::SYMBOL_TYPE || tok == token::TOFLOAT || tok == token::TONUMBER || tok == token::TOSTRING || tok == token::TOUNSIGNED || tok == token::ITOU || tok == token::ITOF || tok == token::UTOI || tok == token::UTOF || tok == token::FTOI || tok == token::FTOU || tok == token::AS || tok == token::AT || tok == token::NIL || tok == token::PIPE || tok == token::LBRACKET || tok == token::RBRACKET || tok == token::UNDERSCORE || tok == token::DOLLAR || tok == token::PLUS || tok == token::MINUS || tok == token::EXCLAMATION || tok == token::LPAREN || tok == token::RPAREN || tok == token::COMMA || tok == token::COLON || tok == token::DOUBLECOLON || tok == token::SEMICOLON || tok == token::DOT || tok == token::EQUALS || tok == token::STAR || tok == token::SLASH || tok == token::CARET || tok == token::PERCENT || tok == token::LBRACE || tok == token::RBRACE || tok == token::SUBTYPE || tok == token::LT || tok == token::GT || tok == token::LE || tok == token::GE || tok == token::NE || tok == token::BW_AND || tok == token::BW_OR || tok == token::BW_XOR || tok == token::BW_SHIFT_L || tok == token::BW_SHIFT_R || tok == token::BW_SHIFT_R_UNSIGNED || tok == token::BW_NOT || tok == token::L_AND || tok == token::L_OR || tok == token::L_XOR || tok == token::L_NOT || tok == token::NEG);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::END || tok == token::AUTOINC || tok == token::PRAGMA || tok == token::OUTPUT_QUALIFIER || tok == token::INPUT_QUALIFIER || tok == token::PRINTSIZE_QUALIFIER || tok == token::BRIE_QUALIFIER || tok == token::BTREE_QUALIFIER || tok == token::BTREE_DELETE_QUALIFIER || tok == token::EQREL_QUALIFIER || tok == token::OVERRIDABLE_QUALIFIER || tok == token::INLINE_QUALIFIER || tok == token::NO_INLINE_QUALIFIER || tok == token::MAGIC_QUALIFIER || tok == token::NO_MAGIC_QUALIFIER || tok == token::TMATCH || tok == token::TCONTAINS || tok == token::STATEFUL || tok == token::CAT || tok == token::ORD || tok == token::RANGE || tok == token::STRLEN || tok == token::SUBSTR || tok == token::MEAN || tok == token::MIN || tok == token::MAX || tok == token::COUNT || tok == token::SUM || tok == token::TRUELIT || tok == token::FALSELIT || tok == token::PLAN || tok == token::CHOICEDOMAIN || tok == token::IF || tok == token::DECL || tok == token::FUNCTOR || tok == token::INPUT_DECL || tok == token::OUTPUT_DECL || tok == token::PRINTSIZE_DECL || tok == token::LIMITSIZE_DECL || tok == token::OVERRIDE || tok == token::TYPE || tok == token::COMPONENT || tok == token::INSTANTIATE || tok == token::NUMBER_TYPE || tok == token::SYMBOL_TYPE || tok == token::TOFLOAT || tok == token::TONUMBER || tok == token::TOSTRING || tok == token::TOUNSIGNED || tok == token::ITOU || tok == token::ITOF || tok == token::UTOI || tok == token::UTOF || tok == token::FTOI || tok == token::FTOU || tok == token::AS || tok == token::AT || tok == token::NIL || tok == token::PIPE || tok == token::LBRACKET || tok == token::RBRACKET || tok == token::UNDERSCORE || tok == token::DOLLAR || tok == token::PLUS || tok == token::MINUS || tok == token::EXCLAMATION || tok == token::LPAREN || tok == token::RPAREN || tok == token::COMMA || tok == token::COLON || tok == token::DOUBLECOLON || tok == token::SEMICOLON || tok == token::DOT || tok == token::EQUALS || tok == token::STAR || tok == token::SLASH || tok == token::CARET || tok == token::PERCENT || tok == token::LBRACE || tok == token::RBRACE || tok == token::SUBTYPE || tok == token::LT || tok == token::GT || tok == token::LE || tok == token::GE || tok == token::NE || tok == token::BW_AND || tok == token::BW_OR || tok == token::BW_XOR || tok == token::BW_SHIFT_L || tok == token::BW_SHIFT_R || tok == token::BW_SHIFT_R_UNSIGNED || tok == token::BW_NOT || tok == token::L_AND || tok == token::L_OR || tok == token::L_XOR || tok == token::L_NOT || tok == token::NEG);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::STRING || tok == token::IDENT || tok == token::NUMBER || tok == token::UNSIGNED || tok == token::FLOAT);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::STRING || tok == token::IDENT || tok == token::NUMBER || tok == token::UNSIGNED || tok == token::FLOAT);
      }
#endif
    };

    /// Build a parser object.
    parser (ParserDriver &driver_yyarg, yyscan_t yyscanner_yyarg);
    virtual ~parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENT (std::string v, location_type l)
      {
        return symbol_type (token::IDENT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::IDENT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER (std::string v, location_type l)
      {
        return symbol_type (token::NUMBER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NUMBER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNSIGNED (std::string v, location_type l)
      {
        return symbol_type (token::UNSIGNED, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UNSIGNED (const std::string& v, const location_type& l)
      {
        return symbol_type (token::UNSIGNED, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (std::string v, location_type l)
      {
        return symbol_type (token::FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AUTOINC (location_type l)
      {
        return symbol_type (token::AUTOINC, std::move (l));
      }
#else
      static
      symbol_type
      make_AUTOINC (const location_type& l)
      {
        return symbol_type (token::AUTOINC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRAGMA (location_type l)
      {
        return symbol_type (token::PRAGMA, std::move (l));
      }
#else
      static
      symbol_type
      make_PRAGMA (const location_type& l)
      {
        return symbol_type (token::PRAGMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUTPUT_QUALIFIER (location_type l)
      {
        return symbol_type (token::OUTPUT_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_OUTPUT_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::OUTPUT_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INPUT_QUALIFIER (location_type l)
      {
        return symbol_type (token::INPUT_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_INPUT_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::INPUT_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINTSIZE_QUALIFIER (location_type l)
      {
        return symbol_type (token::PRINTSIZE_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_PRINTSIZE_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::PRINTSIZE_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BRIE_QUALIFIER (location_type l)
      {
        return symbol_type (token::BRIE_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_BRIE_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::BRIE_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BTREE_QUALIFIER (location_type l)
      {
        return symbol_type (token::BTREE_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_BTREE_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::BTREE_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BTREE_DELETE_QUALIFIER (location_type l)
      {
        return symbol_type (token::BTREE_DELETE_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_BTREE_DELETE_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::BTREE_DELETE_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQREL_QUALIFIER (location_type l)
      {
        return symbol_type (token::EQREL_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_EQREL_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::EQREL_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OVERRIDABLE_QUALIFIER (location_type l)
      {
        return symbol_type (token::OVERRIDABLE_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_OVERRIDABLE_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::OVERRIDABLE_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INLINE_QUALIFIER (location_type l)
      {
        return symbol_type (token::INLINE_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_INLINE_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::INLINE_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NO_INLINE_QUALIFIER (location_type l)
      {
        return symbol_type (token::NO_INLINE_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_NO_INLINE_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::NO_INLINE_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAGIC_QUALIFIER (location_type l)
      {
        return symbol_type (token::MAGIC_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_MAGIC_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::MAGIC_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NO_MAGIC_QUALIFIER (location_type l)
      {
        return symbol_type (token::NO_MAGIC_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_NO_MAGIC_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::NO_MAGIC_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TMATCH (location_type l)
      {
        return symbol_type (token::TMATCH, std::move (l));
      }
#else
      static
      symbol_type
      make_TMATCH (const location_type& l)
      {
        return symbol_type (token::TMATCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCONTAINS (location_type l)
      {
        return symbol_type (token::TCONTAINS, std::move (l));
      }
#else
      static
      symbol_type
      make_TCONTAINS (const location_type& l)
      {
        return symbol_type (token::TCONTAINS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATEFUL (location_type l)
      {
        return symbol_type (token::STATEFUL, std::move (l));
      }
#else
      static
      symbol_type
      make_STATEFUL (const location_type& l)
      {
        return symbol_type (token::STATEFUL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAT (location_type l)
      {
        return symbol_type (token::CAT, std::move (l));
      }
#else
      static
      symbol_type
      make_CAT (const location_type& l)
      {
        return symbol_type (token::CAT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ORD (location_type l)
      {
        return symbol_type (token::ORD, std::move (l));
      }
#else
      static
      symbol_type
      make_ORD (const location_type& l)
      {
        return symbol_type (token::ORD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RANGE (location_type l)
      {
        return symbol_type (token::RANGE, std::move (l));
      }
#else
      static
      symbol_type
      make_RANGE (const location_type& l)
      {
        return symbol_type (token::RANGE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRLEN (location_type l)
      {
        return symbol_type (token::STRLEN, std::move (l));
      }
#else
      static
      symbol_type
      make_STRLEN (const location_type& l)
      {
        return symbol_type (token::STRLEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUBSTR (location_type l)
      {
        return symbol_type (token::SUBSTR, std::move (l));
      }
#else
      static
      symbol_type
      make_SUBSTR (const location_type& l)
      {
        return symbol_type (token::SUBSTR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MEAN (location_type l)
      {
        return symbol_type (token::MEAN, std::move (l));
      }
#else
      static
      symbol_type
      make_MEAN (const location_type& l)
      {
        return symbol_type (token::MEAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MIN (location_type l)
      {
        return symbol_type (token::MIN, std::move (l));
      }
#else
      static
      symbol_type
      make_MIN (const location_type& l)
      {
        return symbol_type (token::MIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX (location_type l)
      {
        return symbol_type (token::MAX, std::move (l));
      }
#else
      static
      symbol_type
      make_MAX (const location_type& l)
      {
        return symbol_type (token::MAX, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COUNT (location_type l)
      {
        return symbol_type (token::COUNT, std::move (l));
      }
#else
      static
      symbol_type
      make_COUNT (const location_type& l)
      {
        return symbol_type (token::COUNT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUM (location_type l)
      {
        return symbol_type (token::SUM, std::move (l));
      }
#else
      static
      symbol_type
      make_SUM (const location_type& l)
      {
        return symbol_type (token::SUM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUELIT (location_type l)
      {
        return symbol_type (token::TRUELIT, std::move (l));
      }
#else
      static
      symbol_type
      make_TRUELIT (const location_type& l)
      {
        return symbol_type (token::TRUELIT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSELIT (location_type l)
      {
        return symbol_type (token::FALSELIT, std::move (l));
      }
#else
      static
      symbol_type
      make_FALSELIT (const location_type& l)
      {
        return symbol_type (token::FALSELIT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLAN (location_type l)
      {
        return symbol_type (token::PLAN, std::move (l));
      }
#else
      static
      symbol_type
      make_PLAN (const location_type& l)
      {
        return symbol_type (token::PLAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHOICEDOMAIN (location_type l)
      {
        return symbol_type (token::CHOICEDOMAIN, std::move (l));
      }
#else
      static
      symbol_type
      make_CHOICEDOMAIN (const location_type& l)
      {
        return symbol_type (token::CHOICEDOMAIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DECL (location_type l)
      {
        return symbol_type (token::DECL, std::move (l));
      }
#else
      static
      symbol_type
      make_DECL (const location_type& l)
      {
        return symbol_type (token::DECL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNCTOR (location_type l)
      {
        return symbol_type (token::FUNCTOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FUNCTOR (const location_type& l)
      {
        return symbol_type (token::FUNCTOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INPUT_DECL (location_type l)
      {
        return symbol_type (token::INPUT_DECL, std::move (l));
      }
#else
      static
      symbol_type
      make_INPUT_DECL (const location_type& l)
      {
        return symbol_type (token::INPUT_DECL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUTPUT_DECL (location_type l)
      {
        return symbol_type (token::OUTPUT_DECL, std::move (l));
      }
#else
      static
      symbol_type
      make_OUTPUT_DECL (const location_type& l)
      {
        return symbol_type (token::OUTPUT_DECL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINTSIZE_DECL (location_type l)
      {
        return symbol_type (token::PRINTSIZE_DECL, std::move (l));
      }
#else
      static
      symbol_type
      make_PRINTSIZE_DECL (const location_type& l)
      {
        return symbol_type (token::PRINTSIZE_DECL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LIMITSIZE_DECL (location_type l)
      {
        return symbol_type (token::LIMITSIZE_DECL, std::move (l));
      }
#else
      static
      symbol_type
      make_LIMITSIZE_DECL (const location_type& l)
      {
        return symbol_type (token::LIMITSIZE_DECL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OVERRIDE (location_type l)
      {
        return symbol_type (token::OVERRIDE, std::move (l));
      }
#else
      static
      symbol_type
      make_OVERRIDE (const location_type& l)
      {
        return symbol_type (token::OVERRIDE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE (location_type l)
      {
        return symbol_type (token::TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE (const location_type& l)
      {
        return symbol_type (token::TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPONENT (location_type l)
      {
        return symbol_type (token::COMPONENT, std::move (l));
      }
#else
      static
      symbol_type
      make_COMPONENT (const location_type& l)
      {
        return symbol_type (token::COMPONENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INSTANTIATE (location_type l)
      {
        return symbol_type (token::INSTANTIATE, std::move (l));
      }
#else
      static
      symbol_type
      make_INSTANTIATE (const location_type& l)
      {
        return symbol_type (token::INSTANTIATE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER_TYPE (location_type l)
      {
        return symbol_type (token::NUMBER_TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER_TYPE (const location_type& l)
      {
        return symbol_type (token::NUMBER_TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYMBOL_TYPE (location_type l)
      {
        return symbol_type (token::SYMBOL_TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_SYMBOL_TYPE (const location_type& l)
      {
        return symbol_type (token::SYMBOL_TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOFLOAT (location_type l)
      {
        return symbol_type (token::TOFLOAT, std::move (l));
      }
#else
      static
      symbol_type
      make_TOFLOAT (const location_type& l)
      {
        return symbol_type (token::TOFLOAT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TONUMBER (location_type l)
      {
        return symbol_type (token::TONUMBER, std::move (l));
      }
#else
      static
      symbol_type
      make_TONUMBER (const location_type& l)
      {
        return symbol_type (token::TONUMBER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOSTRING (location_type l)
      {
        return symbol_type (token::TOSTRING, std::move (l));
      }
#else
      static
      symbol_type
      make_TOSTRING (const location_type& l)
      {
        return symbol_type (token::TOSTRING, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOUNSIGNED (location_type l)
      {
        return symbol_type (token::TOUNSIGNED, std::move (l));
      }
#else
      static
      symbol_type
      make_TOUNSIGNED (const location_type& l)
      {
        return symbol_type (token::TOUNSIGNED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ITOU (location_type l)
      {
        return symbol_type (token::ITOU, std::move (l));
      }
#else
      static
      symbol_type
      make_ITOU (const location_type& l)
      {
        return symbol_type (token::ITOU, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ITOF (location_type l)
      {
        return symbol_type (token::ITOF, std::move (l));
      }
#else
      static
      symbol_type
      make_ITOF (const location_type& l)
      {
        return symbol_type (token::ITOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UTOI (location_type l)
      {
        return symbol_type (token::UTOI, std::move (l));
      }
#else
      static
      symbol_type
      make_UTOI (const location_type& l)
      {
        return symbol_type (token::UTOI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UTOF (location_type l)
      {
        return symbol_type (token::UTOF, std::move (l));
      }
#else
      static
      symbol_type
      make_UTOF (const location_type& l)
      {
        return symbol_type (token::UTOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FTOI (location_type l)
      {
        return symbol_type (token::FTOI, std::move (l));
      }
#else
      static
      symbol_type
      make_FTOI (const location_type& l)
      {
        return symbol_type (token::FTOI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FTOU (location_type l)
      {
        return symbol_type (token::FTOU, std::move (l));
      }
#else
      static
      symbol_type
      make_FTOU (const location_type& l)
      {
        return symbol_type (token::FTOU, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AS (location_type l)
      {
        return symbol_type (token::AS, std::move (l));
      }
#else
      static
      symbol_type
      make_AS (const location_type& l)
      {
        return symbol_type (token::AS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AT (location_type l)
      {
        return symbol_type (token::AT, std::move (l));
      }
#else
      static
      symbol_type
      make_AT (const location_type& l)
      {
        return symbol_type (token::AT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NIL (location_type l)
      {
        return symbol_type (token::NIL, std::move (l));
      }
#else
      static
      symbol_type
      make_NIL (const location_type& l)
      {
        return symbol_type (token::NIL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PIPE (location_type l)
      {
        return symbol_type (token::PIPE, std::move (l));
      }
#else
      static
      symbol_type
      make_PIPE (const location_type& l)
      {
        return symbol_type (token::PIPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACKET (location_type l)
      {
        return symbol_type (token::LBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACKET (const location_type& l)
      {
        return symbol_type (token::LBRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACKET (location_type l)
      {
        return symbol_type (token::RBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACKET (const location_type& l)
      {
        return symbol_type (token::RBRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNDERSCORE (location_type l)
      {
        return symbol_type (token::UNDERSCORE, std::move (l));
      }
#else
      static
      symbol_type
      make_UNDERSCORE (const location_type& l)
      {
        return symbol_type (token::UNDERSCORE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR (location_type l)
      {
        return symbol_type (token::DOLLAR, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR (const location_type& l)
      {
        return symbol_type (token::DOLLAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCLAMATION (location_type l)
      {
        return symbol_type (token::EXCLAMATION, std::move (l));
      }
#else
      static
      symbol_type
      make_EXCLAMATION (const location_type& l)
      {
        return symbol_type (token::EXCLAMATION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (location_type l)
      {
        return symbol_type (token::LPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const location_type& l)
      {
        return symbol_type (token::LPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (location_type l)
      {
        return symbol_type (token::RPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const location_type& l)
      {
        return symbol_type (token::RPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLECOLON (location_type l)
      {
        return symbol_type (token::DOUBLECOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_DOUBLECOLON (const location_type& l)
      {
        return symbol_type (token::DOUBLECOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (location_type l)
      {
        return symbol_type (token::DOT, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const location_type& l)
      {
        return symbol_type (token::DOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUALS (location_type l)
      {
        return symbol_type (token::EQUALS, std::move (l));
      }
#else
      static
      symbol_type
      make_EQUALS (const location_type& l)
      {
        return symbol_type (token::EQUALS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR (location_type l)
      {
        return symbol_type (token::STAR, std::move (l));
      }
#else
      static
      symbol_type
      make_STAR (const location_type& l)
      {
        return symbol_type (token::STAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASH (location_type l)
      {
        return symbol_type (token::SLASH, std::move (l));
      }
#else
      static
      symbol_type
      make_SLASH (const location_type& l)
      {
        return symbol_type (token::SLASH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARET (location_type l)
      {
        return symbol_type (token::CARET, std::move (l));
      }
#else
      static
      symbol_type
      make_CARET (const location_type& l)
      {
        return symbol_type (token::CARET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERCENT (location_type l)
      {
        return symbol_type (token::PERCENT, std::move (l));
      }
#else
      static
      symbol_type
      make_PERCENT (const location_type& l)
      {
        return symbol_type (token::PERCENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (location_type l)
      {
        return symbol_type (token::LBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACE (const location_type& l)
      {
        return symbol_type (token::LBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (location_type l)
      {
        return symbol_type (token::RBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACE (const location_type& l)
      {
        return symbol_type (token::RBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUBTYPE (location_type l)
      {
        return symbol_type (token::SUBTYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_SUBTYPE (const location_type& l)
      {
        return symbol_type (token::SUBTYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT (location_type l)
      {
        return symbol_type (token::LT, std::move (l));
      }
#else
      static
      symbol_type
      make_LT (const location_type& l)
      {
        return symbol_type (token::LT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT (location_type l)
      {
        return symbol_type (token::GT, std::move (l));
      }
#else
      static
      symbol_type
      make_GT (const location_type& l)
      {
        return symbol_type (token::GT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE (location_type l)
      {
        return symbol_type (token::LE, std::move (l));
      }
#else
      static
      symbol_type
      make_LE (const location_type& l)
      {
        return symbol_type (token::LE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE (location_type l)
      {
        return symbol_type (token::GE, std::move (l));
      }
#else
      static
      symbol_type
      make_GE (const location_type& l)
      {
        return symbol_type (token::GE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE (location_type l)
      {
        return symbol_type (token::NE, std::move (l));
      }
#else
      static
      symbol_type
      make_NE (const location_type& l)
      {
        return symbol_type (token::NE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BW_AND (location_type l)
      {
        return symbol_type (token::BW_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_BW_AND (const location_type& l)
      {
        return symbol_type (token::BW_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BW_OR (location_type l)
      {
        return symbol_type (token::BW_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_BW_OR (const location_type& l)
      {
        return symbol_type (token::BW_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BW_XOR (location_type l)
      {
        return symbol_type (token::BW_XOR, std::move (l));
      }
#else
      static
      symbol_type
      make_BW_XOR (const location_type& l)
      {
        return symbol_type (token::BW_XOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BW_SHIFT_L (location_type l)
      {
        return symbol_type (token::BW_SHIFT_L, std::move (l));
      }
#else
      static
      symbol_type
      make_BW_SHIFT_L (const location_type& l)
      {
        return symbol_type (token::BW_SHIFT_L, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BW_SHIFT_R (location_type l)
      {
        return symbol_type (token::BW_SHIFT_R, std::move (l));
      }
#else
      static
      symbol_type
      make_BW_SHIFT_R (const location_type& l)
      {
        return symbol_type (token::BW_SHIFT_R, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BW_SHIFT_R_UNSIGNED (location_type l)
      {
        return symbol_type (token::BW_SHIFT_R_UNSIGNED, std::move (l));
      }
#else
      static
      symbol_type
      make_BW_SHIFT_R_UNSIGNED (const location_type& l)
      {
        return symbol_type (token::BW_SHIFT_R_UNSIGNED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BW_NOT (location_type l)
      {
        return symbol_type (token::BW_NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_BW_NOT (const location_type& l)
      {
        return symbol_type (token::BW_NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L_AND (location_type l)
      {
        return symbol_type (token::L_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_L_AND (const location_type& l)
      {
        return symbol_type (token::L_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L_OR (location_type l)
      {
        return symbol_type (token::L_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_L_OR (const location_type& l)
      {
        return symbol_type (token::L_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L_XOR (location_type l)
      {
        return symbol_type (token::L_XOR, std::move (l));
      }
#else
      static
      symbol_type
      make_L_XOR (const location_type& l)
      {
        return symbol_type (token::L_XOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L_NOT (location_type l)
      {
        return symbol_type (token::L_NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_L_NOT (const location_type& l)
      {
        return symbol_type (token::L_NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEG (location_type l)
      {
        return symbol_type (token::NEG, std::move (l));
      }
#else
      static
      symbol_type
      make_NEG (const location_type& l)
      {
        return symbol_type (token::NEG, l);
      }
#endif


  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const unsigned char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 843,     ///< Last index in yytable_.
      yynnts_ = 57,  ///< Number of nonterminal symbols.
      yyfinal_ = 3, ///< Termination state number.
      yyntokens_ = 105  ///< Number of tokens.
    };


    // User arguments.
    ParserDriver &driver;
    yyscan_t yyscanner;
  };

  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104
    };
    const int user_token_number_max_ = 359;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 138: // aggregate_func
        value.move< AggregateOp > (std::move (that.value));
        break;

      case 136: // arg
        value.move< Mov<Own<ast::Argument>> > (std::move (that.value));
        break;

      case 132: // atom
        value.move< Mov<Own<ast::Atom>> > (std::move (that.value));
        break;

      case 118: // attribute
      case 154: // functor_attribute
        value.move< Mov<Own<ast::Attribute>> > (std::move (that.value));
        break;

      case 113: // adt_branch
        value.move< Mov<Own<ast::BranchType>> > (std::move (that.value));
        break;

      case 124: // fact
        value.move< Mov<Own<ast::Clause>> > (std::move (that.value));
        break;

      case 144: // component_decl
      case 145: // component_head
      case 149: // component_body
        value.move< Mov<Own<ast::Component>> > (std::move (that.value));
        break;

      case 150: // component_init
        value.move< Mov<Own<ast::ComponentInit>> > (std::move (that.value));
        break;

      case 146: // component_type
        value.move< Mov<Own<ast::ComponentType>> > (std::move (that.value));
        break;

      case 133: // constraint
        value.move< Mov<Own<ast::Constraint>> > (std::move (that.value));
        break;

      case 142: // plan_order
        value.move< Mov<Own<ast::ExecutionOrder>> > (std::move (that.value));
        break;

      case 140: // query_plan
      case 141: // query_plan_list
        value.move< Mov<Own<ast::ExecutionPlan>> > (std::move (that.value));
        break;

      case 121: // dependency
        value.move< Mov<Own<ast::FunctionalConstraint>> > (std::move (that.value));
        break;

      case 151: // functor_decl
        value.move< Mov<Own<ast::FunctorDeclaration>> > (std::move (that.value));
        break;

      case 155: // pragma
        value.move< Mov<Own<ast::Pragma>> > (std::move (that.value));
        break;

      case 109: // type_decl
        value.move< Mov<Own<ast::Type>> > (std::move (that.value));
        break;

      case 128: // body
      case 129: // disjunction
      case 130: // conjunction
      case 131: // term
      case 139: // aggregate_body
        value.move< Mov<RuleBody> > (std::move (that.value));
        break;

      case 134: // arg_list
      case 135: // non_empty_arg_list
        value.move< Mov<VecOwn<ast::Argument>> > (std::move (that.value));
        break;

      case 127: // head
        value.move< Mov<VecOwn<ast::Atom>> > (std::move (that.value));
        break;

      case 110: // record_type_list
      case 116: // attributes_list
      case 117: // non_empty_attributes
      case 152: // functor_arg_type_list
      case 153: // non_empty_functor_arg_type_list
        value.move< Mov<VecOwn<ast::Attribute>> > (std::move (that.value));
        break;

      case 112: // adt_branch_list
        value.move< Mov<VecOwn<ast::BranchType>> > (std::move (that.value));
        break;

      case 125: // rule
      case 126: // rule_def
        value.move< Mov<VecOwn<ast::Clause>> > (std::move (that.value));
        break;

      case 156: // directive_head
      case 158: // directive_list
      case 159: // relation_directive_list
        value.move< Mov<VecOwn<ast::Directive>> > (std::move (that.value));
        break;

      case 122: // dependency_list_aux
      case 123: // dependency_list
        value.move< Mov<VecOwn<ast::FunctionalConstraint>> > (std::move (that.value));
        break;

      case 114: // relation_decl
      case 115: // relation_names
        value.move< Mov<VecOwn<ast::Relation>> > (std::move (that.value));
        break;

      case 143: // non_empty_plan_order_list
        value.move< Mov<ast::ExecutionOrder::ExecOrder> > (std::move (that.value));
        break;

      case 108: // qualified_name
        value.move< Mov<ast::QualifiedName> > (std::move (that.value));
        break;

      case 137: // functor_built_in
      case 161: // kvp_value
        value.move< Mov<std::string> > (std::move (that.value));
        break;

      case 111: // union_type_list
      case 147: // component_type_params
      case 148: // component_param_list
        value.move< Mov<std::vector<ast::QualifiedName>> > (std::move (that.value));
        break;

      case 160: // non_empty_key_value_pairs
        value.move< Mov<std::vector<std::pair
            <std::string, std::string>>> > (std::move (that.value));
        break;

      case 120: // non_empty_attribute_names
        value.move< Mov<std::vector<std::string>> > (std::move (that.value));
        break;

      case 157: // directive_head_decl
        value.move< ast::DirectiveType > (std::move (that.value));
        break;

      case 119: // relation_tags
        value.move< std::set<RelationTag> > (std::move (that.value));
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 5: // "number"
      case 6: // "unsigned number"
      case 7: // "float"
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 138: // aggregate_func
        value.copy< AggregateOp > (YY_MOVE (that.value));
        break;

      case 136: // arg
        value.copy< Mov<Own<ast::Argument>> > (YY_MOVE (that.value));
        break;

      case 132: // atom
        value.copy< Mov<Own<ast::Atom>> > (YY_MOVE (that.value));
        break;

      case 118: // attribute
      case 154: // functor_attribute
        value.copy< Mov<Own<ast::Attribute>> > (YY_MOVE (that.value));
        break;

      case 113: // adt_branch
        value.copy< Mov<Own<ast::BranchType>> > (YY_MOVE (that.value));
        break;

      case 124: // fact
        value.copy< Mov<Own<ast::Clause>> > (YY_MOVE (that.value));
        break;

      case 144: // component_decl
      case 145: // component_head
      case 149: // component_body
        value.copy< Mov<Own<ast::Component>> > (YY_MOVE (that.value));
        break;

      case 150: // component_init
        value.copy< Mov<Own<ast::ComponentInit>> > (YY_MOVE (that.value));
        break;

      case 146: // component_type
        value.copy< Mov<Own<ast::ComponentType>> > (YY_MOVE (that.value));
        break;

      case 133: // constraint
        value.copy< Mov<Own<ast::Constraint>> > (YY_MOVE (that.value));
        break;

      case 142: // plan_order
        value.copy< Mov<Own<ast::ExecutionOrder>> > (YY_MOVE (that.value));
        break;

      case 140: // query_plan
      case 141: // query_plan_list
        value.copy< Mov<Own<ast::ExecutionPlan>> > (YY_MOVE (that.value));
        break;

      case 121: // dependency
        value.copy< Mov<Own<ast::FunctionalConstraint>> > (YY_MOVE (that.value));
        break;

      case 151: // functor_decl
        value.copy< Mov<Own<ast::FunctorDeclaration>> > (YY_MOVE (that.value));
        break;

      case 155: // pragma
        value.copy< Mov<Own<ast::Pragma>> > (YY_MOVE (that.value));
        break;

      case 109: // type_decl
        value.copy< Mov<Own<ast::Type>> > (YY_MOVE (that.value));
        break;

      case 128: // body
      case 129: // disjunction
      case 130: // conjunction
      case 131: // term
      case 139: // aggregate_body
        value.copy< Mov<RuleBody> > (YY_MOVE (that.value));
        break;

      case 134: // arg_list
      case 135: // non_empty_arg_list
        value.copy< Mov<VecOwn<ast::Argument>> > (YY_MOVE (that.value));
        break;

      case 127: // head
        value.copy< Mov<VecOwn<ast::Atom>> > (YY_MOVE (that.value));
        break;

      case 110: // record_type_list
      case 116: // attributes_list
      case 117: // non_empty_attributes
      case 152: // functor_arg_type_list
      case 153: // non_empty_functor_arg_type_list
        value.copy< Mov<VecOwn<ast::Attribute>> > (YY_MOVE (that.value));
        break;

      case 112: // adt_branch_list
        value.copy< Mov<VecOwn<ast::BranchType>> > (YY_MOVE (that.value));
        break;

      case 125: // rule
      case 126: // rule_def
        value.copy< Mov<VecOwn<ast::Clause>> > (YY_MOVE (that.value));
        break;

      case 156: // directive_head
      case 158: // directive_list
      case 159: // relation_directive_list
        value.copy< Mov<VecOwn<ast::Directive>> > (YY_MOVE (that.value));
        break;

      case 122: // dependency_list_aux
      case 123: // dependency_list
        value.copy< Mov<VecOwn<ast::FunctionalConstraint>> > (YY_MOVE (that.value));
        break;

      case 114: // relation_decl
      case 115: // relation_names
        value.copy< Mov<VecOwn<ast::Relation>> > (YY_MOVE (that.value));
        break;

      case 143: // non_empty_plan_order_list
        value.copy< Mov<ast::ExecutionOrder::ExecOrder> > (YY_MOVE (that.value));
        break;

      case 108: // qualified_name
        value.copy< Mov<ast::QualifiedName> > (YY_MOVE (that.value));
        break;

      case 137: // functor_built_in
      case 161: // kvp_value
        value.copy< Mov<std::string> > (YY_MOVE (that.value));
        break;

      case 111: // union_type_list
      case 147: // component_type_params
      case 148: // component_param_list
        value.copy< Mov<std::vector<ast::QualifiedName>> > (YY_MOVE (that.value));
        break;

      case 160: // non_empty_key_value_pairs
        value.copy< Mov<std::vector<std::pair
            <std::string, std::string>>> > (YY_MOVE (that.value));
        break;

      case 120: // non_empty_attribute_names
        value.copy< Mov<std::vector<std::string>> > (YY_MOVE (that.value));
        break;

      case 157: // directive_head_decl
        value.copy< ast::DirectiveType > (YY_MOVE (that.value));
        break;

      case 119: // relation_tags
        value.copy< std::set<RelationTag> > (YY_MOVE (that.value));
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 5: // "number"
      case 6: // "unsigned number"
      case 7: // "float"
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 138: // aggregate_func
        value.move< AggregateOp > (YY_MOVE (s.value));
        break;

      case 136: // arg
        value.move< Mov<Own<ast::Argument>> > (YY_MOVE (s.value));
        break;

      case 132: // atom
        value.move< Mov<Own<ast::Atom>> > (YY_MOVE (s.value));
        break;

      case 118: // attribute
      case 154: // functor_attribute
        value.move< Mov<Own<ast::Attribute>> > (YY_MOVE (s.value));
        break;

      case 113: // adt_branch
        value.move< Mov<Own<ast::BranchType>> > (YY_MOVE (s.value));
        break;

      case 124: // fact
        value.move< Mov<Own<ast::Clause>> > (YY_MOVE (s.value));
        break;

      case 144: // component_decl
      case 145: // component_head
      case 149: // component_body
        value.move< Mov<Own<ast::Component>> > (YY_MOVE (s.value));
        break;

      case 150: // component_init
        value.move< Mov<Own<ast::ComponentInit>> > (YY_MOVE (s.value));
        break;

      case 146: // component_type
        value.move< Mov<Own<ast::ComponentType>> > (YY_MOVE (s.value));
        break;

      case 133: // constraint
        value.move< Mov<Own<ast::Constraint>> > (YY_MOVE (s.value));
        break;

      case 142: // plan_order
        value.move< Mov<Own<ast::ExecutionOrder>> > (YY_MOVE (s.value));
        break;

      case 140: // query_plan
      case 141: // query_plan_list
        value.move< Mov<Own<ast::ExecutionPlan>> > (YY_MOVE (s.value));
        break;

      case 121: // dependency
        value.move< Mov<Own<ast::FunctionalConstraint>> > (YY_MOVE (s.value));
        break;

      case 151: // functor_decl
        value.move< Mov<Own<ast::FunctorDeclaration>> > (YY_MOVE (s.value));
        break;

      case 155: // pragma
        value.move< Mov<Own<ast::Pragma>> > (YY_MOVE (s.value));
        break;

      case 109: // type_decl
        value.move< Mov<Own<ast::Type>> > (YY_MOVE (s.value));
        break;

      case 128: // body
      case 129: // disjunction
      case 130: // conjunction
      case 131: // term
      case 139: // aggregate_body
        value.move< Mov<RuleBody> > (YY_MOVE (s.value));
        break;

      case 134: // arg_list
      case 135: // non_empty_arg_list
        value.move< Mov<VecOwn<ast::Argument>> > (YY_MOVE (s.value));
        break;

      case 127: // head
        value.move< Mov<VecOwn<ast::Atom>> > (YY_MOVE (s.value));
        break;

      case 110: // record_type_list
      case 116: // attributes_list
      case 117: // non_empty_attributes
      case 152: // functor_arg_type_list
      case 153: // non_empty_functor_arg_type_list
        value.move< Mov<VecOwn<ast::Attribute>> > (YY_MOVE (s.value));
        break;

      case 112: // adt_branch_list
        value.move< Mov<VecOwn<ast::BranchType>> > (YY_MOVE (s.value));
        break;

      case 125: // rule
      case 126: // rule_def
        value.move< Mov<VecOwn<ast::Clause>> > (YY_MOVE (s.value));
        break;

      case 156: // directive_head
      case 158: // directive_list
      case 159: // relation_directive_list
        value.move< Mov<VecOwn<ast::Directive>> > (YY_MOVE (s.value));
        break;

      case 122: // dependency_list_aux
      case 123: // dependency_list
        value.move< Mov<VecOwn<ast::FunctionalConstraint>> > (YY_MOVE (s.value));
        break;

      case 114: // relation_decl
      case 115: // relation_names
        value.move< Mov<VecOwn<ast::Relation>> > (YY_MOVE (s.value));
        break;

      case 143: // non_empty_plan_order_list
        value.move< Mov<ast::ExecutionOrder::ExecOrder> > (YY_MOVE (s.value));
        break;

      case 108: // qualified_name
        value.move< Mov<ast::QualifiedName> > (YY_MOVE (s.value));
        break;

      case 137: // functor_built_in
      case 161: // kvp_value
        value.move< Mov<std::string> > (YY_MOVE (s.value));
        break;

      case 111: // union_type_list
      case 147: // component_type_params
      case 148: // component_param_list
        value.move< Mov<std::vector<ast::QualifiedName>> > (YY_MOVE (s.value));
        break;

      case 160: // non_empty_key_value_pairs
        value.move< Mov<std::vector<std::pair
            <std::string, std::string>>> > (YY_MOVE (s.value));
        break;

      case 120: // non_empty_attribute_names
        value.move< Mov<std::vector<std::string>> > (YY_MOVE (s.value));
        break;

      case 157: // directive_head_decl
        value.move< ast::DirectiveType > (YY_MOVE (s.value));
        break;

      case 119: // relation_tags
        value.move< std::set<RelationTag> > (YY_MOVE (s.value));
        break;

      case 3: // "symbol"
      case 4: // "identifier"
      case 5: // "number"
      case 6: // "unsigned number"
      case 7: // "float"
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

} // yy
#line 4064 "/home/johannes/test2/popl2020-artifact/prosynth/souffle/build/src/parser/parser.hh"





#endif // !YY_YY_HOME_JOHANNES_TEST2_POPL2020_ARTIFACT_PROSYNTH_SOUFFLE_BUILD_SRC_PARSER_PARSER_HH_INCLUDED
