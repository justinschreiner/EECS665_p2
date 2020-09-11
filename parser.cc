// A Bison parser, made by GNU Bison 3.4.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

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





#include "grammar.hh"


// Unqualified %code blocks.
#line 40 "holyc.yy"

   // C std code for utility functions
   #include <iostream>
   #include <cstdlib>
   #include <fstream>

   // Our code for interoperation between scanner/parser
   #include "scanner.hpp"
   //#include "tokens.hpp"

  //Request tokens from our scanner member, not 
  // from a global function
  #undef yylex
  #define yylex scanner.yylex

#line 61 "parser.cc"


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



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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

#line 5 "holyc.yy"
namespace holyc {
#line 137 "parser.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
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
  Parser::Parser (holyc::Scanner &scanner_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
  {}
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
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
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

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
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
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
            yyla.type = yytranslate_ (yylex (&yyla.value));
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
      goto yydefault;

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
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
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


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 130 "holyc.yy"
    {}
#line 606 "parser.cc"
    break;

  case 3:
#line 132 "holyc.yy"
    {}
#line 612 "parser.cc"
    break;

  case 4:
#line 133 "holyc.yy"
    {}
#line 618 "parser.cc"
    break;

  case 5:
#line 135 "holyc.yy"
    {}
#line 624 "parser.cc"
    break;

  case 6:
#line 136 "holyc.yy"
    {}
#line 630 "parser.cc"
    break;

  case 7:
#line 138 "holyc.yy"
    {}
#line 636 "parser.cc"
    break;

  case 8:
#line 140 "holyc.yy"
    {}
#line 642 "parser.cc"
    break;

  case 9:
#line 141 "holyc.yy"
    {}
#line 648 "parser.cc"
    break;

  case 10:
#line 142 "holyc.yy"
    {}
#line 654 "parser.cc"
    break;

  case 11:
#line 143 "holyc.yy"
    {}
#line 660 "parser.cc"
    break;

  case 12:
#line 144 "holyc.yy"
    {}
#line 666 "parser.cc"
    break;

  case 13:
#line 145 "holyc.yy"
    {}
#line 672 "parser.cc"
    break;

  case 14:
#line 146 "holyc.yy"
    {}
#line 678 "parser.cc"
    break;

  case 15:
#line 148 "holyc.yy"
    {}
#line 684 "parser.cc"
    break;

  case 16:
#line 150 "holyc.yy"
    {}
#line 690 "parser.cc"
    break;

  case 17:
#line 151 "holyc.yy"
    {}
#line 696 "parser.cc"
    break;

  case 18:
#line 153 "holyc.yy"
    {}
#line 702 "parser.cc"
    break;

  case 19:
#line 154 "holyc.yy"
    {}
#line 708 "parser.cc"
    break;

  case 20:
#line 156 "holyc.yy"
    {}
#line 714 "parser.cc"
    break;

  case 21:
#line 158 "holyc.yy"
    {}
#line 720 "parser.cc"
    break;

  case 22:
#line 160 "holyc.yy"
    {}
#line 726 "parser.cc"
    break;

  case 23:
#line 161 "holyc.yy"
    {}
#line 732 "parser.cc"
    break;

  case 24:
#line 163 "holyc.yy"
    {}
#line 738 "parser.cc"
    break;

  case 25:
#line 164 "holyc.yy"
    {}
#line 744 "parser.cc"
    break;

  case 26:
#line 165 "holyc.yy"
    {}
#line 750 "parser.cc"
    break;

  case 27:
#line 166 "holyc.yy"
    {}
#line 756 "parser.cc"
    break;

  case 28:
#line 167 "holyc.yy"
    {}
#line 762 "parser.cc"
    break;

  case 29:
#line 168 "holyc.yy"
    {}
#line 768 "parser.cc"
    break;

  case 30:
#line 169 "holyc.yy"
    {}
#line 774 "parser.cc"
    break;

  case 31:
#line 170 "holyc.yy"
    {}
#line 780 "parser.cc"
    break;

  case 32:
#line 171 "holyc.yy"
    {}
#line 786 "parser.cc"
    break;

  case 33:
#line 172 "holyc.yy"
    {}
#line 792 "parser.cc"
    break;

  case 34:
#line 173 "holyc.yy"
    {}
#line 798 "parser.cc"
    break;

  case 35:
#line 174 "holyc.yy"
    {}
#line 804 "parser.cc"
    break;

  case 36:
#line 176 "holyc.yy"
    {}
#line 810 "parser.cc"
    break;

  case 37:
#line 178 "holyc.yy"
    {}
#line 816 "parser.cc"
    break;

  case 38:
#line 179 "holyc.yy"
    {}
#line 822 "parser.cc"
    break;

  case 39:
#line 181 "holyc.yy"
    {}
#line 828 "parser.cc"
    break;

  case 40:
#line 182 "holyc.yy"
    {}
#line 834 "parser.cc"
    break;

  case 41:
#line 184 "holyc.yy"
    {}
#line 840 "parser.cc"
    break;

  case 42:
#line 185 "holyc.yy"
    {}
#line 846 "parser.cc"
    break;

  case 43:
#line 187 "holyc.yy"
    {}
#line 852 "parser.cc"
    break;

  case 44:
#line 188 "holyc.yy"
    {}
#line 858 "parser.cc"
    break;

  case 45:
#line 190 "holyc.yy"
    {}
#line 864 "parser.cc"
    break;

  case 46:
#line 191 "holyc.yy"
    {}
#line 870 "parser.cc"
    break;

  case 47:
#line 193 "holyc.yy"
    {}
#line 876 "parser.cc"
    break;

  case 48:
#line 194 "holyc.yy"
    {}
#line 882 "parser.cc"
    break;

  case 49:
#line 195 "holyc.yy"
    {}
#line 888 "parser.cc"
    break;

  case 50:
#line 196 "holyc.yy"
    {}
#line 894 "parser.cc"
    break;

  case 51:
#line 197 "holyc.yy"
    {}
#line 900 "parser.cc"
    break;

  case 52:
#line 198 "holyc.yy"
    {}
#line 906 "parser.cc"
    break;

  case 54:
#line 201 "holyc.yy"
    {}
#line 912 "parser.cc"
    break;

  case 55:
#line 202 "holyc.yy"
    {}
#line 918 "parser.cc"
    break;

  case 56:
#line 203 "holyc.yy"
    {}
#line 924 "parser.cc"
    break;

  case 57:
#line 205 "holyc.yy"
    {}
#line 930 "parser.cc"
    break;

  case 58:
#line 206 "holyc.yy"
    {}
#line 936 "parser.cc"
    break;

  case 59:
#line 207 "holyc.yy"
    {}
#line 942 "parser.cc"
    break;

  case 60:
#line 209 "holyc.yy"
    {}
#line 948 "parser.cc"
    break;

  case 61:
#line 210 "holyc.yy"
    {}
#line 954 "parser.cc"
    break;

  case 62:
#line 213 "holyc.yy"
    {}
#line 960 "parser.cc"
    break;

  case 63:
#line 214 "holyc.yy"
    {}
#line 966 "parser.cc"
    break;

  case 64:
#line 215 "holyc.yy"
    {}
#line 972 "parser.cc"
    break;

  case 65:
#line 216 "holyc.yy"
    {}
#line 978 "parser.cc"
    break;

  case 66:
#line 217 "holyc.yy"
    {}
#line 984 "parser.cc"
    break;

  case 67:
#line 218 "holyc.yy"
    {}
#line 990 "parser.cc"
    break;

  case 68:
#line 219 "holyc.yy"
    {}
#line 996 "parser.cc"
    break;

  case 69:
#line 220 "holyc.yy"
    {}
#line 1002 "parser.cc"
    break;

  case 70:
#line 221 "holyc.yy"
    {}
#line 1008 "parser.cc"
    break;

  case 71:
#line 223 "holyc.yy"
    {}
#line 1014 "parser.cc"
    break;

  case 72:
#line 224 "holyc.yy"
    {}
#line 1020 "parser.cc"
    break;

  case 73:
#line 225 "holyc.yy"
    {}
#line 1026 "parser.cc"
    break;

  case 74:
#line 226 "holyc.yy"
    {}
#line 1032 "parser.cc"
    break;

  case 75:
#line 228 "holyc.yy"
    {}
#line 1038 "parser.cc"
    break;


#line 1042 "parser.cc"

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
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


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
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
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
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
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
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
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
    size_t yyi = 0;
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


  const signed char Parser::yypact_ninf_ = -118;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
    -118,     3,    58,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,     1,    36,  -118,  -118,  -118,    30,     6,    37,
    -118,    36,    28,    59,  -118,  -118,  -118,  -118,    58,    52,
    -118,    36,    36,    72,    38,  -118,   210,   259,    46,    41,
      36,  -118,    43,    44,    11,     2,  -118,  -118,    45,    51,
     259,  -118,   278,  -118,  -118,   259,  -118,  -118,  -118,  -118,
    -118,  -118,    47,    56,    84,  -118,   112,   -19,  -118,  -118,
      89,    54,   259,  -118,  -118,  -118,  -118,   259,    57,    65,
     259,   249,  -118,    68,  -118,  -118,    73,  -118,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
    -118,    74,  -118,  -118,  -118,    75,  -118,    -7,  -118,    92,
    -118,    84,  -118,   -19,   -19,    22,    22,    22,    22,    22,
      22,  -118,  -118,    94,  -118,   259,  -118,  -118,  -118,  -118,
     111,   156,   107,  -118,    97,  -118,   201,  -118
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       4,     0,     2,     1,    10,    11,    12,    13,     8,     9,
      14,     3,     0,     0,     6,     5,    75,     7,     0,     0,
      16,     0,     0,    18,    23,    15,    20,    17,     0,     0,
      19,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,    22,     0,     0,     0,    71,    73,    74,     0,    71,
       0,    65,     0,    67,    63,     0,    68,    34,    64,    66,
      41,    70,     0,    42,    44,    46,    53,    56,    59,    61,
      62,     0,     0,    24,     7,    25,    35,     0,     0,     0,
       0,     0,    28,     0,    60,    62,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,    36,    27,    26,     0,    37,     0,    39,     0,
      69,    43,    45,    54,    55,    47,    49,    50,    51,    52,
      48,    58,    57,     0,    72,     0,    38,    23,    23,    40,
       0,     0,    30,    32,     0,    23,     0,    31
  };

  const signed char
  Parser::yypgoto_[] =
  {
    -118,  -118,  -118,  -118,   126,     4,  -118,  -118,   101,  -118,
    -118,  -117,  -118,   -27,   -20,  -118,   -36,  -118,    49,    55,
      76,   -41,   -44,    83,   -29,     7
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     1,     2,    11,    39,    40,    14,    19,    22,    23,
      25,    29,    41,    60,    61,   107,    62,    63,    64,    65,
      66,    67,    68,    69,    85,    45
  };

  const unsigned char
  Parser::yytable_[] =
  {
      44,    71,    42,     3,    48,   125,    13,    70,    70,    43,
     130,   131,     4,     5,    83,     6,    77,     7,   136,    86,
      17,    70,    21,    98,    99,    78,    70,    79,    26,     8,
      80,     9,    21,   126,    81,    90,   101,    91,    46,    47,
      49,   102,    15,    70,   105,   108,    20,    74,    70,   113,
     114,    70,    70,    10,   121,   122,    31,    16,     4,     5,
      32,     6,    18,     7,     4,     5,    24,     6,    27,     7,
      50,    28,    33,    16,    34,     8,    31,     9,    72,    80,
      32,     8,    73,     9,    75,    76,    82,    89,    87,   129,
      35,    36,    88,    16,    77,   100,    70,    37,   103,    10,
      38,    44,    44,    42,    42,    10,   104,    44,   109,    42,
      43,    43,   124,   110,   123,    31,    43,     4,     5,    32,
       6,   127,     7,   128,   134,    90,   135,    91,    12,    30,
      92,    33,    16,    34,     8,    84,     9,   111,    93,    94,
       0,     0,    95,    96,   112,     0,    97,     0,     0,   132,
      36,     0,     0,     0,     0,     0,    37,     0,    10,    38,
      31,     0,     4,     5,    32,     6,     0,     7,   115,   116,
     117,   118,   119,   120,     0,     0,    33,    16,    34,     8,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,    36,     0,     0,     0,     0,
       0,    37,     0,    10,    38,    31,     0,     4,     5,    32,
       6,     0,     7,     0,    31,     0,     0,     0,    32,     0,
      51,    33,    16,    34,     8,    52,     9,     0,     0,    53,
       0,    16,     0,     0,    54,     0,     0,     0,     0,   137,
      36,     0,    55,     0,     0,    56,    37,     0,    10,    38,
       0,    57,     0,    31,    58,     0,    59,    32,     0,    51,
       0,     0,     0,    31,    52,     0,     0,    32,    53,    51,
      16,     0,     0,    54,    52,     0,     0,     0,    53,     0,
      16,    55,    31,    54,    56,     0,    32,     0,    51,   106,
       0,    55,     0,    58,    56,    59,     0,    53,     0,    16,
       0,     0,    54,    58,     0,    59,     0,     0,     0,     0,
      55,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,    59
  };

  const short
  Parser::yycheck_[] =
  {
      29,    37,    29,     0,    33,    12,     2,    36,    37,    29,
     127,   128,     6,     7,    50,     9,     5,    11,   135,    55,
      13,    50,    18,    42,    43,    14,    55,    16,    21,    23,
      28,    25,    28,    40,    32,    13,    72,    15,    31,    32,
      33,    77,    41,    72,    80,    81,    40,    40,    77,    90,
      91,    80,    81,    47,    98,    99,     4,    21,     6,     7,
       8,     9,    32,    11,     6,     7,    29,     9,    40,    11,
      32,    12,    20,    21,    22,    23,     4,    25,    32,    28,
       8,    23,    41,    25,    41,    41,    41,     3,    41,   125,
      38,    39,    36,    21,     5,    41,   125,    45,    41,    47,
      48,   130,   131,   130,   131,    47,    41,   136,    40,   136,
     130,   131,    37,    40,    40,     4,   136,     6,     7,     8,
       9,    29,    11,    29,    17,    13,    29,    15,     2,    28,
      18,    20,    21,    22,    23,    52,    25,    88,    26,    27,
      -1,    -1,    30,    31,    89,    -1,    34,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    48,
       4,    -1,     6,     7,     8,     9,    -1,    11,    92,    93,
      94,    95,    96,    97,    -1,    -1,    20,    21,    22,    23,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    47,    48,     4,    -1,     6,     7,     8,
       9,    -1,    11,    -1,     4,    -1,    -1,    -1,     8,    -1,
      10,    20,    21,    22,    23,    15,    25,    -1,    -1,    19,
      -1,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,    38,
      39,    -1,    32,    -1,    -1,    35,    45,    -1,    47,    48,
      -1,    41,    -1,     4,    44,    -1,    46,     8,    -1,    10,
      -1,    -1,    -1,     4,    15,    -1,    -1,     8,    19,    10,
      21,    -1,    -1,    24,    15,    -1,    -1,    -1,    19,    -1,
      21,    32,     4,    24,    35,    -1,     8,    -1,    10,    40,
      -1,    32,    -1,    44,    35,    46,    -1,    19,    -1,    21,
      -1,    -1,    24,    44,    -1,    46,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    46
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    50,    51,     0,     6,     7,     9,    11,    23,    25,
      47,    52,    53,    54,    55,    41,    21,    74,    32,    56,
      40,    54,    57,    58,    29,    59,    74,    40,    12,    60,
      57,     4,     8,    20,    22,    38,    39,    45,    48,    53,
      54,    61,    62,    63,    73,    74,    74,    74,    73,    74,
      32,    10,    15,    19,    24,    32,    35,    41,    44,    46,
      62,    63,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    65,    32,    41,    74,    41,    41,     5,    14,    16,
      28,    32,    41,    65,    72,    73,    65,    41,    36,     3,
      13,    15,    18,    26,    27,    30,    31,    34,    42,    43,
      41,    65,    65,    41,    41,    65,    40,    64,    65,    40,
      40,    67,    68,    70,    70,    69,    69,    69,    69,    69,
      69,    71,    71,    40,    37,    12,    40,    29,    29,    65,
      60,    60,    38,    38,    17,    29,    60,    38
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    49,    50,    51,    51,    52,    52,    53,    54,    54,
      54,    54,    54,    54,    54,    55,    56,    56,    57,    57,
      58,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    69,    70,    70,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    73,    73,    74
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     4,     2,     3,     1,     3,
       2,     3,     2,     0,     2,     2,     3,     3,     3,     3,
       7,    11,     7,     3,     2,     2,     3,     3,     4,     1,
       3,     1,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     4,     2,     2,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end file\"", "error", "$undefined", "AND", "AT", "ASSIGN", "BOOL",
  "BOOLPTR", "CARAT", "CHAR", "CHARLIT", "CHARPTR", "COMMA", "CROSS",
  "CROSSCROSS", "DASH", "DASHDASH", "ELSE", "EQUALS", "FALSE",
  "FROMCONSOLE", "ID", "IF", "INT", "INTLITERAL", "INTPTR", "GREATER",
  "GREATEREQ", "LBRACE", "LCURLY", "LESS", "LESSEQ", "LPAREN", "NOT",
  "NOTEQUALS", "NULLPTR", "OR", "RBRACE", "RCURLY", "RETURN", "RPAREN",
  "SEMICOLON", "SLASH", "STAR", "STRLITERAL", "TOCONSOLE", "TRUE", "VOID",
  "WHILE", "$accept", "program", "globals", "decl", "varDecl", "type",
  "fnDecl", "formals", "formalsList", "formalDecl", "fnBody", "stmtList",
  "stmt", "assignExp", "fncall", "actualsList", "exp", "orExp", "andExp",
  "reqExp", "addSubExp", "multDivExp", "dashNotExp", "term", "lval", "id", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,   130,   130,   132,   133,   135,   136,   138,   140,   141,
     142,   143,   144,   145,   146,   148,   150,   151,   153,   154,
     156,   158,   160,   161,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   176,   178,   179,   181,
     182,   184,   185,   187,   188,   190,   191,   193,   194,   195,
     196,   197,   198,   199,   201,   202,   203,   205,   206,   207,
     209,   210,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   223,   224,   225,   226,   228
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
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

  Parser::token_number_type
  Parser::yytranslate_ (int t)
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
      45,    46,    47,    48
    };
    const unsigned user_token_number_max_ = 303;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "holyc.yy"
} // holyc
#line 1605 "parser.cc"

#line 230 "holyc.yy"


void holyc::Parser::error(const std::string& err_message){
   /* For project grading, only report "syntax error"
      if a program has bad syntax. However, you will
      probably want better output for debugging. Thus,
      this error function prints a verbose message to 
      stdout, but only prints "syntax error" to stderr
   */
	std::cout << err_message << std::endl;
	std::cerr << "syntax error" << std::endl;
}
