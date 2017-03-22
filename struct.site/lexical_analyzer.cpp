#include "lexical_analyzer"
#include <quex/code_base/analyzer/C-adaptions.h>
QUEX_NAMESPACE_MAIN_OPEN
/* Global */QUEX_NAME(Mode)  QUEX_NAME(FUNCTION_DEFINITION);
/* Global */QUEX_NAME(Mode)  QUEX_NAME(STRING_RELATIVE);
/* Global */QUEX_NAME(Mode)  QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS);
/* Global */QUEX_NAME(Mode)  QUEX_NAME(STRING_ABSOLUTE);
/* Global */QUEX_NAME(Mode)  QUEX_NAME(SCOPE);
/* Global */QUEX_NAME(Mode)  QUEX_NAME(EXPRESSION);
#ifndef __QUEX_INDICATOR_DUMPED_TOKEN_ID_DEFINED
    static QUEX_TYPE_TOKEN_ID    QUEX_NAME_TOKEN(DumpedTokenIdObject);
#endif
#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
#define __self_result_token_id    QUEX_NAME_TOKEN(DumpedTokenIdObject)

void
QUEX_NAME(FUNCTION_DEFINITION_on_entry)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* FromMode) {
    (void)me;
    (void)FromMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(FUNCTION_DEFINITION).has_entry_from(FromMode);
#   endif

}

void
QUEX_NAME(FUNCTION_DEFINITION_on_exit)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* ToMode)  {
    (void)me;
    (void)ToMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(FUNCTION_DEFINITION).has_exit_to(ToMode);
#   endif

}

#if defined(QUEX_OPTION_INDENTATION_TRIGGER) 
void
QUEX_NAME(FUNCTION_DEFINITION_on_indentation)(QUEX_TYPE_ANALYZER*    me, 
                                        QUEX_TYPE_INDENTATION  Indentation, 
                                        QUEX_TYPE_CHARACTER*   Begin) {
    (void)me;
    (void)Indentation;
    (void)Begin;
    return;
}
#endif

#ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
bool
QUEX_NAME(FUNCTION_DEFINITION_has_base)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION): return true;
    default:
    ;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION, \n", Mode->name);
    __quex_assert(false);
    return false;
    
}
bool
QUEX_NAME(FUNCTION_DEFINITION_has_entry_from)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return true; /* default */
}
bool
QUEX_NAME(FUNCTION_DEFINITION_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return false;
}
#endif    

void
QUEX_NAME(STRING_RELATIVE_on_entry)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* FromMode) {
    (void)me;
    (void)FromMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(STRING_RELATIVE).has_entry_from(FromMode);
#   endif

}

void
QUEX_NAME(STRING_RELATIVE_on_exit)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* ToMode)  {
    (void)me;
    (void)ToMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(STRING_RELATIVE).has_exit_to(ToMode);
#   endif

}

#if defined(QUEX_OPTION_INDENTATION_TRIGGER) 
void
QUEX_NAME(STRING_RELATIVE_on_indentation)(QUEX_TYPE_ANALYZER*    me, 
                                        QUEX_TYPE_INDENTATION  Indentation, 
                                        QUEX_TYPE_CHARACTER*   Begin) {
    (void)me;
    (void)Indentation;
    (void)Begin;
    return;
}
#endif

#ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
bool
QUEX_NAME(STRING_RELATIVE_has_base)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_STRING_RELATIVE): return true;
    default:
    ;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): STRING_RELATIVE, \n", Mode->name);
    __quex_assert(false);
    return false;
    
}
bool
QUEX_NAME(STRING_RELATIVE_has_entry_from)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return true; /* default */
}
bool
QUEX_NAME(STRING_RELATIVE_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return false;
}
#endif    

void
QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS_on_entry)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* FromMode) {
    (void)me;
    (void)FromMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS).has_entry_from(FromMode);
#   endif

}

void
QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS_on_exit)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* ToMode)  {
    (void)me;
    (void)ToMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS).has_exit_to(ToMode);
#   endif

}

#if defined(QUEX_OPTION_INDENTATION_TRIGGER) 
void
QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS_on_indentation)(QUEX_TYPE_ANALYZER*    me, 
                                        QUEX_TYPE_INDENTATION  Indentation, 
                                        QUEX_TYPE_CHARACTER*   Begin) {
    (void)me;
    (void)Indentation;
    (void)Begin;
    return;
}
#endif

#ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
bool
QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS_has_base)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION_PARAMETERS): return true;
    default:
    ;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION_PARAMETERS, \n", Mode->name);
    __quex_assert(false);
    return false;
    
}
bool
QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS_has_entry_from)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return true; /* default */
}
bool
QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return false;
}
#endif    

void
QUEX_NAME(STRING_ABSOLUTE_on_entry)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* FromMode) {
    (void)me;
    (void)FromMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(STRING_ABSOLUTE).has_entry_from(FromMode);
#   endif

}

void
QUEX_NAME(STRING_ABSOLUTE_on_exit)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* ToMode)  {
    (void)me;
    (void)ToMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(STRING_ABSOLUTE).has_exit_to(ToMode);
#   endif

}

#if defined(QUEX_OPTION_INDENTATION_TRIGGER) 
void
QUEX_NAME(STRING_ABSOLUTE_on_indentation)(QUEX_TYPE_ANALYZER*    me, 
                                        QUEX_TYPE_INDENTATION  Indentation, 
                                        QUEX_TYPE_CHARACTER*   Begin) {
    (void)me;
    (void)Indentation;
    (void)Begin;
    return;
}
#endif

#ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
bool
QUEX_NAME(STRING_ABSOLUTE_has_base)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_STRING_ABSOLUTE): return true;
    default:
    ;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): STRING_ABSOLUTE, \n", Mode->name);
    __quex_assert(false);
    return false;
    
}
bool
QUEX_NAME(STRING_ABSOLUTE_has_entry_from)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return true; /* default */
}
bool
QUEX_NAME(STRING_ABSOLUTE_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return false;
}
#endif    

void
QUEX_NAME(SCOPE_on_entry)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* FromMode) {
    (void)me;
    (void)FromMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(SCOPE).has_entry_from(FromMode);
#   endif

}

void
QUEX_NAME(SCOPE_on_exit)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* ToMode)  {
    (void)me;
    (void)ToMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(SCOPE).has_exit_to(ToMode);
#   endif

}

#if defined(QUEX_OPTION_INDENTATION_TRIGGER) 
void
QUEX_NAME(SCOPE_on_indentation)(QUEX_TYPE_ANALYZER*    me, 
                                        QUEX_TYPE_INDENTATION  Indentation, 
                                        QUEX_TYPE_CHARACTER*   Begin) {
    (void)me;
    (void)Indentation;
    (void)Begin;
    return;
}
#endif

#ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
bool
QUEX_NAME(SCOPE_has_base)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_SCOPE): return true;
    default:
    ;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): SCOPE, \n", Mode->name);
    __quex_assert(false);
    return false;
    
}
bool
QUEX_NAME(SCOPE_has_entry_from)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return true; /* default */
}
bool
QUEX_NAME(SCOPE_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return false;
}
#endif    

void
QUEX_NAME(EXPRESSION_on_entry)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* FromMode) {
    (void)me;
    (void)FromMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(EXPRESSION).has_entry_from(FromMode);
#   endif

}

void
QUEX_NAME(EXPRESSION_on_exit)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* ToMode)  {
    (void)me;
    (void)ToMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(EXPRESSION).has_exit_to(ToMode);
#   endif

}

#if defined(QUEX_OPTION_INDENTATION_TRIGGER) 
void
QUEX_NAME(EXPRESSION_on_indentation)(QUEX_TYPE_ANALYZER*    me, 
                                        QUEX_TYPE_INDENTATION  Indentation, 
                                        QUEX_TYPE_CHARACTER*   Begin) {
    (void)me;
    (void)Indentation;
    (void)Begin;
    return;
}
#endif

#ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
bool
QUEX_NAME(EXPRESSION_has_base)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_EXPRESSION): return true;
    default:
    ;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): EXPRESSION, \n", Mode->name);
    __quex_assert(false);
    return false;
    
}
bool
QUEX_NAME(EXPRESSION_has_entry_from)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return true; /* default */
}
bool
QUEX_NAME(EXPRESSION_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return false;
}
#endif    
#undef self
#undef __self_result_token_id
QUEX_NAMESPACE_MAIN_CLOSE

/* #include "lexical_analyzer"*/
QUEX_NAMESPACE_MAIN_OPEN
QUEX_TYPE_CHARACTER  QUEX_LEXEME_NULL_IN_ITS_NAMESPACE = (QUEX_TYPE_CHARACTER)0;
#ifdef      __QUEX_COUNT_VOID
#   undef   __QUEX_COUNT_VOID
#endif
#ifdef      __QUEX_OPTION_COUNTER
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) \
            do {                              \
                QUEX_NAME(FUNCTION_DEFINITION_counter)((ME), (BEGIN), (END));     \
                __quex_debug_counter();       \
            } while(0)
#else
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) /* empty */
#endif
#ifdef __QUEX_OPTION_COUNTER
static void
QUEX_NAME(FUNCTION_DEFINITION_counter)(QUEX_TYPE_ANALYZER* me, QUEX_TYPE_CHARACTER* LexemeBegin, QUEX_TYPE_CHARACTER* LexemeEnd)
{
#   define self (*me)
    QUEX_TYPE_CHARACTER* iterator    = LexemeBegin;
#   if defined(QUEX_OPTION_COLUMN_NUMBER_COUNTING)
    const QUEX_TYPE_CHARACTER* reference_p = LexemeBegin;
#   endif
__QUEX_IF_COUNT_COLUMNS(reference_p = iterator);
    __QUEX_IF_COUNT_SHIFT_VALUES();

    __quex_assert(LexemeBegin <= LexemeEnd);
    for(iterator=LexemeBegin; iterator < LexemeEnd; ) {
        if( (*(iterator)) >= 0xB ) {
                            ++(((iterator)));
            continue;
        } else if( (*(iterator)) == 0xA ) {
            __QUEX_IF_COUNT_LINES_ADD((size_t)1);
        __QUEX_IF_COUNT_COLUMNS_SET((size_t)1);
        __QUEX_IF_COUNT_COLUMNS(reference_p = (iterator) + 1);
                ++(((iterator)));
            continue;
        } else if( (*(iterator)) == 0x9 ) {
                    __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((iterator) - reference_p)));
        __QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
        __QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4);
        __QUEX_IF_COUNT_COLUMNS(reference_p = (iterator) + 1);
                ++(((iterator)));
            continue;
        } else {
                            ++(((iterator)));
            continue;
        }

    }
    __quex_assert(iterator == LexemeEnd); /* Otherwise, lexeme violates codec character boundaries. */
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)((iterator - reference_p)));
   return;
#  undef self
}
#endif /* __QUEX_OPTION_COUNTER */
#include <quex/code_base/analyzer/member/basic>
#include <quex/code_base/buffer/Buffer>
#ifdef QUEX_OPTION_TOKEN_POLICY_QUEUE
#   include <quex/code_base/token/TokenQueue>
#endif

#ifdef    CONTINUE
#   undef CONTINUE
#endif
#define   CONTINUE goto __REENTRY_PREPARATION; 

#ifdef    RETURN
#   undef RETURN
#endif

#define RETURN    __QUEX_PURE_RETURN;
#include <quex/code_base/temporary_macros_on>

__QUEX_TYPE_ANALYZER_RETURN_VALUE  
QUEX_NAME(FUNCTION_DEFINITION_analyzer_function)(QUEX_TYPE_ANALYZER* me) 
{
    /* NOTE: Different modes correspond to different analyzer functions. The 
     *       analyzer functions are all located inside the main class as static
     *       functions. That means, they are something like 'globals'. They 
     *       receive a pointer to the lexical analyzer, since static members do
     *       not have access to the 'this' pointer.                          */
#   if defined(QUEX_OPTION_TOKEN_POLICY_SINGLE)
    register QUEX_TYPE_TOKEN_ID __self_result_token_id 
           = (QUEX_TYPE_TOKEN_ID)__QUEX_SETTING_TOKEN_ID_UNINITIALIZED;
#   endif
#   ifdef     self
#       undef self
#   endif
#   define self (*((QUEX_TYPE_ANALYZER*)me))
    const QUEX_TYPE_CHARACTER      Skipper956_Closer[2]           = { 0x2A, 0x2F,  };
    const QUEX_TYPE_CHARACTER      Skipper956_Opener[2]           = { 0x2F, 0x2A,  };
    const QUEX_TYPE_CHARACTER*     Skipper956_OpenerEnd           = Skipper956_Opener + (ptrdiff_t)2;
    const QUEX_TYPE_CHARACTER*     Skipper956_CloserEnd           = Skipper956_Closer + (ptrdiff_t)2;
    size_t                         counter                        = 0;
    const QUEX_TYPE_CHARACTER*     Skipper956_Opener_it           = 0x0;
    QUEX_TYPE_CHARACTER_POSITION   reference_p                    = (QUEX_TYPE_CHARACTER_POSITION)0x0;
    const size_t                   PositionRegisterN              = (size_t)1;
    QUEX_TYPE_ACCEPTANCE_ID        last_acceptance               /* un-initilized */;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    QUEX_TYPE_CHARACTER_POSITION   position[1]                    = { 0};
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
    const QUEX_TYPE_CHARACTER*     Skipper956_Closer_it           = 0x0;
#   ifdef QUEX_OPTION_COLUMN_NUMBER_COUNTING
#   endif /* QUEX_OPTION_COLUMN_NUMBER_COUNTING */
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */
#   define FUNCTION_DEFINITION               (QUEX_NAME(FUNCTION_DEFINITION))
#   define STRING_RELATIVE                   (QUEX_NAME(STRING_RELATIVE))
#   define FUNCTION_DEFINITION_PARAMETERS    (QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS))
#   define STRING_ABSOLUTE                   (QUEX_NAME(STRING_ABSOLUTE))
#   define SCOPE                             (QUEX_NAME(SCOPE))
#   define EXPRESSION                        (QUEX_NAME(EXPRESSION))

    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE) \
       || defined(QUEX_OPTION_ASSERTS)
    me->DEBUG_analyzer_function_at_entry = me->current_analyzer_function;
#   endif
__REENTRY:
    me->buffer._lexeme_start_p = me->buffer._input_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_1038: /* INIT_STATE_TRANSITION_BLOCK */
    { last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1); __quex_debug("last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1)\n"); }
    input = *(me->buffer._input_p);
    __quex_debug("Init State\n");
    __quex_debug_state(1021);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1021, 955);
        case 0x9: goto _1026;
        case 0xA: goto _1028;
        case 0xD: 
        case 0x20: goto _1025;
        case 0x28: goto _1024;
        case 0x2F: goto _1029;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1022;
        case 0x7B: goto _1027;
        case 0x7D: goto _1023;

    }
    __quex_debug_drop_out(1021);

goto _1040; /* TERMINAL_FAILURE */

_1021:


    ++(me->buffer._input_p);
    goto _1038;


    __quex_assert_no_passage();
_1041: /* (1031 from 1036) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1031: /* (1031 from 1031) (1031 from 1035) (1031 from 1029) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1031);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1031, 1042);
        case 0xA: goto _1034;
        case 0xD: goto _1033;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1031;
        case 0x5C: goto _1032;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1031;

    }
_1042:
    __quex_debug_drop_out(1031);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */
    case 861: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_861;

}

    __quex_assert_no_passage();
_1043: /* (1032 from 1036) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1032: /* (1032 from 1032) (1032 from 1031) (1032 from 1035) (1032 from 1037) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1032);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1032, 1044);
        case 0x9: goto _1032;
        case 0xA: goto _1035;
        case 0xD: 
        case 0x20: goto _1032;

    }
_1044:
    __quex_debug_drop_out(1032);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */
    case 861: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_861;

}

    __quex_assert_no_passage();
_1022: /* (1022 from 1022) (1022 from 1021) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1022);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1022, 1045);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1022;

    }
_1045:
    __quex_debug_drop_out(1022);
goto TERMINAL_862;

    __quex_assert_no_passage();
_1046: /* (1036 from 1036) (1036 from 1035) (1036 from 1037) */
    { last_acceptance = 861; __quex_debug("last_acceptance = 861\n"); }

_1036:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1036);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1036, 1047);
        case 0x9: goto _1043;
        case 0xA: goto _1046;
        case 0xD: goto _1048;
        case 0x20: goto _1043;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1041;
        case 0x5C: goto _1043;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1041;

    }
_1047:
    __quex_debug_drop_out(1036);
goto TERMINAL_861;

    __quex_assert_no_passage();
_1034: /* (1034 from 1033) (1034 from 1031) */

    ++(me->buffer._input_p);
    __quex_debug_state(1034);
    __quex_debug_drop_out(1034);
goto TERMINAL_861;

    __quex_assert_no_passage();
_1048: /* (1037 from 1036) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1037: /* (1037 from 1035) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1037);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1037, 1050);
        case 0x9: goto _1032;
        case 0xA: goto _1046;
        case 0xD: 
        case 0x20: goto _1032;

    }
_1050:
    __quex_debug_drop_out(1037);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */
    case 861: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_861;

}

    __quex_assert_no_passage();
_1030: /* (1030 from 1029) */

    ++(me->buffer._input_p);
    __quex_debug_state(1030);
    __quex_debug_drop_out(1030);
goto TERMINAL_860;

    __quex_assert_no_passage();
_1033: /* (1033 from 1031) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1033);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1033, 1052);
        case 0xA: goto _1034;

    }
_1052:
    __quex_debug_drop_out(1033);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */
    case 861: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_861;

}

    __quex_assert_no_passage();
_1035: /* (1035 from 1032) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1035);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1035, 1053);
        case 0x9: goto _1032;
        case 0xA: goto _1046;
        case 0xD: goto _1037;
        case 0x20: goto _1032;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1031;
        case 0x5C: goto _1032;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1031;

    }
_1053:
    __quex_debug_drop_out(1035);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */
    case 861: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_861;

}

    __quex_assert_no_passage();
_1024: /* (1024 from 1021) */

    ++(me->buffer._input_p);
    __quex_debug_state(1024);
    __quex_debug_drop_out(1024);
goto TERMINAL_863;

    __quex_assert_no_passage();
_1025: /* (1025 from 1021) */

    ++(me->buffer._input_p);
    __quex_debug_state(1025);
    __quex_debug_drop_out(1025);
goto TERMINAL_857;

    __quex_assert_no_passage();
_1026: /* (1026 from 1021) */

    ++(me->buffer._input_p);
    __quex_debug_state(1026);
    __quex_debug_drop_out(1026);
goto TERMINAL_858;

    __quex_assert_no_passage();
_1027: /* (1027 from 1021) */

    ++(me->buffer._input_p);
    __quex_debug_state(1027);
    __quex_debug_drop_out(1027);
goto TERMINAL_864;

    __quex_assert_no_passage();
_1028: /* (1028 from 1021) */

    ++(me->buffer._input_p);
    __quex_debug_state(1028);
    __quex_debug_drop_out(1028);
goto TERMINAL_859;

    __quex_assert_no_passage();
_1029: /* (1029 from 1021) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1029);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1029, 1059);
        case 0x2A: goto _1030;
        case 0x2F: goto _1031;

    }
_1059:
    __quex_debug_drop_out(1029);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1023: /* (1023 from 1021) */

    ++(me->buffer._input_p);
    __quex_debug_state(1023);
    __quex_debug_drop_out(1023);
goto TERMINAL_865;
    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */

    /* Lexeme setup: 
     *
     * There is a temporary zero stored at the end of each lexeme, if the action 
     * references to the 'Lexeme'. 'LexemeNull' provides a reference to an empty
     * zero terminated string.                                                    */
#if defined(QUEX_OPTION_ASSERTS)
#   define Lexeme       QUEX_NAME(access_Lexeme)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeBegin  QUEX_NAME(access_LexemeBegin)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeL      QUEX_NAME(access_LexemeL)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeEnd    QUEX_NAME(access_LexemeEnd)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#else
#   define Lexeme       (me->buffer._lexeme_start_p)
#   define LexemeBegin  Lexeme
#   define LexemeL      ((size_t)(me->buffer._input_p - me->buffer._lexeme_start_p))
#   define LexemeEnd    me->buffer._input_p
#endif

#define LexemeNull      (&QUEX_LEXEME_NULL)

TERMINAL_857:
    __quex_debug("* terminal 857:   <skip: ... (check also base modes)>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 245 "lexical_analyzer.qx"
    goto __SKIP;
    
#   line 987 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_858:
    __quex_debug("* terminal 858:   <skip: ... (check also base modes)>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4);

    {
#   line 245 "lexical_analyzer.qx"
    goto __SKIP;
    
#   line 1002 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_859:
    __quex_debug("* terminal 859:   <skip>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_LINES_ADD(1);
__QUEX_IF_COUNT_COLUMNS_SET(1);
    {
__SKIP:
    /* Character Set Skipper: '['\t', '\n'], '\r', ' '' */
    QUEX_BUFFER_ASSERT_CONSISTENCY(&me->buffer);
__QUEX_IF_COUNT_COLUMNS(reference_p = me->buffer._input_p);
    while( 1 + 1 == 2 ) {
_952:
        if( (*me->buffer._input_p) < 0xB ) {
            switch( (*me->buffer._input_p) ) {
                case 0x0: QUEX_GOTO_RELOAD(_954, 952, 955);
                case 0x1:
                case 0x2:
                case 0x3:
                case 0x4:
                case 0x5:
                case 0x6:
                case 0x7:
                case 0x8: __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
                case 0x9:             __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
            __QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
            __QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4);
            __QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p) + 1);
                    ++((me->buffer._input_p));
                continue;
                case 0xA: __QUEX_IF_COUNT_LINES_ADD((size_t)1);
            __QUEX_IF_COUNT_COLUMNS_SET((size_t)1);
            __QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p) + 1);
                    ++((me->buffer._input_p));
                continue;

            }
        } else {
            if( (*me->buffer._input_p) < 0xD ) {
                __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
            } else if( (*me->buffer._input_p) == 0xD ) {
                        ++((me->buffer._input_p));
                continue;
            } else if( (*me->buffer._input_p) < 0x20 ) {
                __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
            } else if( (*me->buffer._input_p) == 0x20 ) {
                        ++((me->buffer._input_p));
                continue;
            } else {
                __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
            }
        }

    __quex_assert_no_passage();
_954:

    __quex_debug1("__RELOAD_FORWARD");
    __quex_assert(*((me->buffer._input_p)) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
me->buffer._lexeme_start_p = (me->buffer._input_p);

        __quex_debug_reload_before(); /* Leave macro here to report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);
        ++((me->buffer._input_p));
__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);
    }

    }
    goto __REENTRY_PREPARATION;

TERMINAL_860:
    __quex_debug("* terminal 860:   {D_COMMENT_STREAM_BEGINNING}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
    Skipper956_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper956_Opener;
    Skipper956_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper956_Closer;
    /* text_end                           = QUEX_NAME(Buffer_text_end)(&me->buffer); */
    __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));


_957:

    QUEX_BUFFER_ASSERT_CONSISTENCY(&me->buffer);
    __quex_assert(QUEX_NAME(Buffer_content_size)(&me->buffer) >= 2 );

    /* NOTE: If _input_p == end of buffer, then it will drop out immediately out of the
        *       loop below and drop into the buffer reload procedure.                      */

    /* Loop eating characters: Break-out as soon as the First Character of the Delimiter
        * (FCD) is reached. Thus, the FCD plays also the role of the Buffer Limit Code. There
        * are two reasons for break-out:
        *    (1) we reached a limit (end-of-file or buffer-limit)
        *    (2) there was really the FCD in the character stream
        * This must be distinguished after the loop was exited. But, during the 'swallowing'
        * we are very fast, because we do not have to check for two different characters.  */
    while( 1 + 1 == 2 ) {
            input = *(me->buffer._input_p);

            if( input == QUEX_SETTING_BUFFER_LIMIT_CODE ) {
                    goto _958;
            }
            if( input == *Skipper956_Closer_it ) {
                    ++Skipper956_Closer_it;
                    if( Skipper956_Closer_it == Skipper956_CloserEnd ) {
                        if( counter == 0 ) {
                            /* NOTE: The initial state does not increment the input_p. When it detects that
                                * it is located on a buffer border, it automatically triggers a reload. No
                                * need here to reload the buffer. */
                            ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
                                    __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer)
                                            - reference_p));

                            /* No need for re-entry preparation. Acceptance flags and modes are untouched after skipping. */
                            goto __REENTRY; /* End of range reached. */
                        }
                        --counter;
                        Skipper956_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper956_Opener;
                        Skipper956_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper956_Closer;
                        goto CONTINUE_956;
                    }
            } else {
                    Skipper956_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper956_Closer;
            }
            if( input == *Skipper956_Opener_it ) {
                    ++Skipper956_Opener_it;
                    if( Skipper956_Opener_it == Skipper956_OpenerEnd ) {
                        ++counter;
                        Skipper956_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper956_Opener;
                        Skipper956_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper956_Closer;
                        goto CONTINUE_956;
                    }
            } else {
                    Skipper956_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper956_Opener;
            }
CONTINUE_956:

    __QUEX_IF_COUNT_IF( input == (QUEX_TYPE_CHARACTER)'\n' ) {
            __QUEX_IF_COUNT_LINES_ADD((size_t)1);
            __QUEX_IF_COUNT_COLUMNS_SET((size_t)0);
            __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));
    }

            ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
    }

_958:
    QUEX_BUFFER_ASSERT_CONSISTENCY_LIGHT(&me->buffer);
    /* -- When loading new content it is checked that the beginning of the lexeme
        *    is not 'shifted' out of the buffer. In the case of skipping, we do not care about
        *    the lexeme at all, so do not restrict the load procedure and set the lexeme start
        *    to the actual input position.                                                    */
    me->buffer._lexeme_start_p = me->buffer._input_p;

    __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer)
                                        - reference_p));

    if( QUEX_NAME(Buffer_is_end_of_file)(&me->buffer) == false ) {
            QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position,
                                                PositionRegisterN);
            /* Recover '_input_p' from lexeme start
                * (inverse of what we just did before the loading) */
            me->buffer._input_p = me->buffer._lexeme_start_p;
            /* After reload, we need to increment _input_p. That's how the game is supposed to be played.
                * But, we recovered from lexeme start pointer, and this one does not need to be incremented. */
            /* text_end = QUEX_NAME(Buffer_text_end)(&me->buffer); */
            __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));

            QUEX_BUFFER_ASSERT_CONSISTENCY(&me->buffer);
            goto _957; /* End of range reached.             */
    }
    /* Here, either the loading failed or it is not enough space to carry a closing delimiter */
    me->buffer._input_p = me->buffer._lexeme_start_p;
    QUEX_ERROR_EXIT("\nLexical analyzer mode 'FUNCTION_DEFINITION':\n"
                        "End of file occurred before closing skip range delimiter!\n"                "The 'on_skip_range_open' handler has not been specified.");

    }
    goto __REENTRY_PREPARATION;

TERMINAL_861:
    __quex_debug("* terminal 861:   {D_COMMENT_BLOCK}([inverse({D_NEW_LINE})]|({D_BACKSLASH}{D_WHITESPACE}*{D_NEW_LINE}))*{D_NEW_LINE}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 252 "lexical_analyzer.qx"
    
        // We are within a comment. Do not do anything.
    
    
#   line 1205 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_862:
    __quex_debug("* terminal 862:   {D_IDENTIFIER}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
    {
#   line 399 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_IDENTIFIER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 1220 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_863:
    __quex_debug("* terminal 863:   \"(\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 401 "lexical_analyzer.qx"
    QUEX_NAME(push_mode)(&self, &FUNCTION_DEFINITION_PARAMETERS);self_send(QUEX_TKN_PARENTHESIS_BEGINNING);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 1234 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_864:
    __quex_debug("* terminal 864:   \"{\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 403 "lexical_analyzer.qx"
    self_send(QUEX_TKN_BRACE_BEGINNING);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 1248 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_865:
    __quex_debug("* terminal 865:   \"}\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 405 "lexical_analyzer.qx"
    QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_BRACE_END);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 1262 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;


_1040: /* TERMINAL: FAILURE */
    if(QUEX_NAME(Buffer_is_end_of_file)(&me->buffer)) {
        /* Init state is going to detect 'input == buffer limit code', and
         * enter the reload procedure, which will decide about 'end of stream'. */
    } else {
        /* In init state 'input = *input_p' and we need to increment
         * in order to avoid getting stalled. Else, input = *(input_p - 1),
         * so 'input_p' points already to the next character.                   */
        if( me->buffer._input_p == me->buffer._lexeme_start_p ) {
            /* Step over non-matching character */
            ++(me->buffer._input_p);
        }
    }
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    QUEX_LEXEME_TERMINATING_ZERO_SET(&me->buffer);
    {
#   line 237 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_FAILURE);
    
        RETURN;
    
    
#   line 1291 "lexical_analyzer.cpp"
    
#   line 408 "lexical_analyzer.qx"
    
        self_accumulator_add (Lexeme, LexemeEnd);
    
    
#   line 1298 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION_2;


/* TERMINAL: END_OF_STREAM */
_955:
__QUEX_IF_COUNT_SHIFT_VALUES();
    {
#   line 230 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_TERMINATION);
    
        RETURN;
    
    
#   line 1315 "lexical_analyzer.cpp"

    }
    /* End of Stream causes a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.                    */
    RETURN;

__REENTRY_PREPARATION:
    /* (*) Common point for **restarting** lexical analysis.
     *     at each time when CONTINUE is called at the end of a pattern.     */
 

    /* FAILURE needs not to run through 'on_after_match'. It enters here.    */
__REENTRY_PREPARATION_2:

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL

#   ifndef __QUEX_OPTION_PLAIN_ANALYZER_OBJECT
#   ifdef  QUEX_OPTION_TOKEN_POLICY_QUEUE
    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) {
        return;
    }
#   else
    if( self_token_get_id() != __QUEX_SETTING_TOKEN_ID_UNINITIALIZED) {
        return __self_result_token_id;
    }
#   endif
#   endif


    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */

    /*  If a mode change happened, then the function must first return and
     *  indicate that another mode function is to be called. At this point, 
     *  we to force a 'return' on a mode change. 
     *
     *  Pseudo Code: if( previous_mode != current_mode ) {
     *                   return 0;
     *               }
     *
     *  When the analyzer returns, the caller function has to watch if a mode 
     *  change occurred. If not it can call this function again.             */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)        || defined(QUEX_OPTION_ASSERTS)
    if( me->DEBUG_analyzer_function_at_entry != me->current_analyzer_function ) 
#   endif
    { 
#       if defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)
        self_token_set_id(__QUEX_SETTING_TOKEN_ID_UNINITIALIZED);
        __QUEX_PURE_RETURN;
#       elif defined(QUEX_OPTION_ASSERTS)
        QUEX_ERROR_EXIT("Mode change without immediate return from the lexical analyzer.");
#       endif
    }

    goto __REENTRY;

    __quex_assert_no_passage();
__RELOAD_FORWARD:

    __quex_debug1("__RELOAD_FORWARD");
    __quex_assert(*(me->buffer._input_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {

        __quex_debug_reload_before(); /* Leave macro here to report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
__STATE_ROUTER:
    switch( target_state_index ) {
        case 952: { goto _952; }
        case 954: { goto _954; }
        case 955: { goto _955; }
        case 957: { goto _957; }
        case 1021: { goto _1021; }
        case 1022: { goto _1022; }
        case 1023: { goto _1023; }
        case 1024: { goto _1024; }
        case 1025: { goto _1025; }
        case 1026: { goto _1026; }
        case 1027: { goto _1027; }
        case 1028: { goto _1028; }
        case 1029: { goto _1029; }
        case 1030: { goto _1030; }
        case 1031: { goto _1031; }
        case 1032: { goto _1032; }
        case 1033: { goto _1033; }
        case 1034: { goto _1034; }
        case 1035: { goto _1035; }
        case 1036: { goto _1036; }
        case 1037: { goto _1037; }
        case 1041: { goto _1041; }
        case 1042: { goto _1042; }
        case 1043: { goto _1043; }
        case 1044: { goto _1044; }
        case 1045: { goto _1045; }
        case 1046: { goto _1046; }
        case 1047: { goto _1047; }
        case 1048: { goto _1048; }
        case 1050: { goto _1050; }
        case 1052: { goto _1052; }
        case 1053: { goto _1053; }
        case 1059: { goto _1059; }

        default:
            __QUEX_STD_fprintf(stderr, "State router: index = %i\n", (int)target_state_index);
            QUEX_ERROR_EXIT("State router: unknown index.\n");
    }
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */

    /* Prevent compiler warning 'unused variable': use variables once in a part of the code*/
    /* that is never reached (and deleted by the compiler anyway).*/
    (void)QUEX_LEXEME_NULL;
    (void)QUEX_NAME_TOKEN(DumpedTokenIdObject);
    QUEX_ERROR_EXIT("Unreachable code has been reached.\n");
#   undef FUNCTION_DEFINITION
#   undef STRING_RELATIVE
#   undef FUNCTION_DEFINITION_PARAMETERS
#   undef STRING_ABSOLUTE
#   undef SCOPE
#   undef EXPRESSION
#   undef self
}
#include <quex/code_base/temporary_macros_off>
#ifdef      __QUEX_COUNT_VOID
#   undef   __QUEX_COUNT_VOID
#endif
#ifdef      __QUEX_OPTION_COUNTER
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) \
            do {                              \
                QUEX_NAME(FUNCTION_DEFINITION_counter)((ME), (BEGIN), (END));     \
                __quex_debug_counter();       \
            } while(0)
#else
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) /* empty */
#endif

#include <quex/code_base/analyzer/member/basic>
#include <quex/code_base/buffer/Buffer>
#ifdef QUEX_OPTION_TOKEN_POLICY_QUEUE
#   include <quex/code_base/token/TokenQueue>
#endif

#ifdef    CONTINUE
#   undef CONTINUE
#endif
#define   CONTINUE goto __REENTRY_PREPARATION; 

#ifdef    RETURN
#   undef RETURN
#endif

#define RETURN    __QUEX_PURE_RETURN;
#include <quex/code_base/temporary_macros_on>

__QUEX_TYPE_ANALYZER_RETURN_VALUE  
QUEX_NAME(STRING_RELATIVE_analyzer_function)(QUEX_TYPE_ANALYZER* me) 
{
    /* NOTE: Different modes correspond to different analyzer functions. The 
     *       analyzer functions are all located inside the main class as static
     *       functions. That means, they are something like 'globals'. They 
     *       receive a pointer to the lexical analyzer, since static members do
     *       not have access to the 'this' pointer.                          */
#   if defined(QUEX_OPTION_TOKEN_POLICY_SINGLE)
    register QUEX_TYPE_TOKEN_ID __self_result_token_id 
           = (QUEX_TYPE_TOKEN_ID)__QUEX_SETTING_TOKEN_ID_UNINITIALIZED;
#   endif
#   ifdef     self
#       undef self
#   endif
#   define self (*((QUEX_TYPE_ANALYZER*)me))
    void*                          position                       = (void*)0x0;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    const size_t                   PositionRegisterN              = (size_t)0;
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */
#   define FUNCTION_DEFINITION               (QUEX_NAME(FUNCTION_DEFINITION))
#   define STRING_RELATIVE                   (QUEX_NAME(STRING_RELATIVE))
#   define FUNCTION_DEFINITION_PARAMETERS    (QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS))
#   define STRING_ABSOLUTE                   (QUEX_NAME(STRING_ABSOLUTE))
#   define SCOPE                             (QUEX_NAME(SCOPE))
#   define EXPRESSION                        (QUEX_NAME(EXPRESSION))

    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE) \
       || defined(QUEX_OPTION_ASSERTS)
    me->DEBUG_analyzer_function_at_entry = me->current_analyzer_function;
#   endif
__REENTRY:
    me->buffer._lexeme_start_p = me->buffer._input_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_1109: /* INIT_STATE_TRANSITION_BLOCK */
    input = *(me->buffer._input_p);
    __quex_debug("Init State\n");
    __quex_debug_state(1101);
    if( input < 0xB ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1101, 955);
            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: 
            case 0x9: goto _1104;

        }
    } else {
        if( input < 0x22 ) {
            goto _1104;
        } else if( input == 0x22 ) {
            goto _1103;
        } else if( input < 0x5C ) {
            goto _1104;
        } else if( input == 0x5C ) {
            goto _1102;
        } else {
            goto _1104;
        }
    }
    __quex_debug_drop_out(1101);

goto _1040; /* TERMINAL_FAILURE */

_1101:


    ++(me->buffer._input_p);
    goto _1109;


    __quex_assert_no_passage();
_1106: /* (1106 from 1102) */

    ++(me->buffer._input_p);
    __quex_debug_state(1106);
    __quex_debug_drop_out(1106);
goto TERMINAL_866;

    __quex_assert_no_passage();
_1107: /* (1107 from 1102) */

    ++(me->buffer._input_p);
    __quex_debug_state(1107);
    __quex_debug_drop_out(1107);
goto TERMINAL_867;

    __quex_assert_no_passage();
_1105: /* (1105 from 1102) */

    ++(me->buffer._input_p);
    __quex_debug_state(1105);
    __quex_debug_drop_out(1105);
goto TERMINAL_869;

    __quex_assert_no_passage();
_1108: /* (1108 from 1102) */

    ++(me->buffer._input_p);
    __quex_debug_state(1108);
    __quex_debug_drop_out(1108);
goto TERMINAL_868;

    __quex_assert_no_passage();
_1102: /* (1102 from 1101) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1102);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1102, 1115);
        case 0x22: goto _1108;
        case 0x4E: goto _1106;
        case 0x54: goto _1107;
        case 0x5C: goto _1105;
        case 0x6E: goto _1106;
        case 0x74: goto _1107;

    }
_1115:
    __quex_debug_drop_out(1102);
goto TERMINAL_871;

    __quex_assert_no_passage();
_1103: /* (1103 from 1101) */

    ++(me->buffer._input_p);
    __quex_debug_state(1103);
    __quex_debug_drop_out(1103);
goto TERMINAL_870;

    __quex_assert_no_passage();
_1104: /* (1104 from 1101) */

    ++(me->buffer._input_p);
    __quex_debug_state(1104);
    __quex_debug_drop_out(1104);
goto TERMINAL_871;
    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */

    /* Lexeme setup: 
     *
     * There is a temporary zero stored at the end of each lexeme, if the action 
     * references to the 'Lexeme'. 'LexemeNull' provides a reference to an empty
     * zero terminated string.                                                    */
#if defined(QUEX_OPTION_ASSERTS)
#   define Lexeme       QUEX_NAME(access_Lexeme)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeBegin  QUEX_NAME(access_LexemeBegin)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeL      QUEX_NAME(access_LexemeL)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeEnd    QUEX_NAME(access_LexemeEnd)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#else
#   define Lexeme       (me->buffer._lexeme_start_p)
#   define LexemeBegin  Lexeme
#   define LexemeL      ((size_t)(me->buffer._input_p - me->buffer._lexeme_start_p))
#   define LexemeEnd    me->buffer._input_p
#endif

#define LexemeNull      (&QUEX_LEXEME_NULL)

TERMINAL_866:
    __quex_debug("* terminal 866:   {D_ENDL}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
#   line 337 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_ENDL);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 1680 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_867:
    __quex_debug("* terminal 867:   {D_TAB}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
#   line 338 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_TAB);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 1695 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_868:
    __quex_debug("* terminal 868:   {D_BACKSLASHED_QUOTE_DOUBLE}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
#   line 339 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_BACKSLASHED_QUOTE_DOUBLE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 1710 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_869:
    __quex_debug("* terminal 869:   {D_BACKSLASHED_BACKSLASH}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
#   line 340 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_BACKSLASHED_BACKSLASH);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 1725 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_870:
    __quex_debug("* terminal 870:   {D_QUOTE_DOUBLE}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 344 "lexical_analyzer.qx"
    QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_STRING_RELATIVE_END);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 1739 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_871:
    __quex_debug("* terminal 871:   {D_ANY_CHARACTER}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 346 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_CHARACTER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 1753 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;


_1040: /* TERMINAL: FAILURE */
    if(QUEX_NAME(Buffer_is_end_of_file)(&me->buffer)) {
        /* Init state is going to detect 'input == buffer limit code', and
         * enter the reload procedure, which will decide about 'end of stream'. */
    } else {
        /* In init state 'input = *input_p' and we need to increment
         * in order to avoid getting stalled. Else, input = *(input_p - 1),
         * so 'input_p' points already to the next character.                   */
        if( me->buffer._input_p == me->buffer._lexeme_start_p ) {
            /* Step over non-matching character */
            ++(me->buffer._input_p);
        }
    }
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    QUEX_LEXEME_TERMINATING_ZERO_SET(&me->buffer);
    {
#   line 237 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_FAILURE);
    
        RETURN;
    
    
#   line 1782 "lexical_analyzer.cpp"
    
#   line 349 "lexical_analyzer.qx"
    
        self_accumulator_add (Lexeme, LexemeEnd);
    
    
#   line 1789 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION_2;


/* TERMINAL: END_OF_STREAM */
_955:
__QUEX_IF_COUNT_SHIFT_VALUES();
    {
#   line 230 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_TERMINATION);
    
        RETURN;
    
    
#   line 1806 "lexical_analyzer.cpp"

    }
    /* End of Stream causes a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.                    */
    RETURN;

__REENTRY_PREPARATION:
    /* (*) Common point for **restarting** lexical analysis.
     *     at each time when CONTINUE is called at the end of a pattern.     */
 

    /* FAILURE needs not to run through 'on_after_match'. It enters here.    */
__REENTRY_PREPARATION_2:

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL

#   ifndef __QUEX_OPTION_PLAIN_ANALYZER_OBJECT
#   ifdef  QUEX_OPTION_TOKEN_POLICY_QUEUE
    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) {
        return;
    }
#   else
    if( self_token_get_id() != __QUEX_SETTING_TOKEN_ID_UNINITIALIZED) {
        return __self_result_token_id;
    }
#   endif
#   endif


    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */

    /*  If a mode change happened, then the function must first return and
     *  indicate that another mode function is to be called. At this point, 
     *  we to force a 'return' on a mode change. 
     *
     *  Pseudo Code: if( previous_mode != current_mode ) {
     *                   return 0;
     *               }
     *
     *  When the analyzer returns, the caller function has to watch if a mode 
     *  change occurred. If not it can call this function again.             */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)        || defined(QUEX_OPTION_ASSERTS)
    if( me->DEBUG_analyzer_function_at_entry != me->current_analyzer_function ) 
#   endif
    { 
#       if defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)
        self_token_set_id(__QUEX_SETTING_TOKEN_ID_UNINITIALIZED);
        __QUEX_PURE_RETURN;
#       elif defined(QUEX_OPTION_ASSERTS)
        QUEX_ERROR_EXIT("Mode change without immediate return from the lexical analyzer.");
#       endif
    }

    goto __REENTRY;

    __quex_assert_no_passage();
__RELOAD_FORWARD:

    __quex_debug1("__RELOAD_FORWARD");
    __quex_assert(*(me->buffer._input_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {

        __quex_debug_reload_before(); /* Leave macro here to report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
__STATE_ROUTER:
    switch( target_state_index ) {
        case 955: { goto _955; }
        case 1101: { goto _1101; }
        case 1102: { goto _1102; }
        case 1103: { goto _1103; }
        case 1104: { goto _1104; }
        case 1105: { goto _1105; }
        case 1106: { goto _1106; }
        case 1107: { goto _1107; }
        case 1108: { goto _1108; }
        case 1115: { goto _1115; }

        default:
            __QUEX_STD_fprintf(stderr, "State router: index = %i\n", (int)target_state_index);
            QUEX_ERROR_EXIT("State router: unknown index.\n");
    }
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */

    /* Prevent compiler warning 'unused variable': use variables once in a part of the code*/
    /* that is never reached (and deleted by the compiler anyway).*/
    (void)QUEX_LEXEME_NULL;
    (void)QUEX_NAME_TOKEN(DumpedTokenIdObject);
    QUEX_ERROR_EXIT("Unreachable code has been reached.\n");
#   undef FUNCTION_DEFINITION
#   undef STRING_RELATIVE
#   undef FUNCTION_DEFINITION_PARAMETERS
#   undef STRING_ABSOLUTE
#   undef SCOPE
#   undef EXPRESSION
#   undef self
}
#include <quex/code_base/temporary_macros_off>
#ifdef      __QUEX_COUNT_VOID
#   undef   __QUEX_COUNT_VOID
#endif
#ifdef      __QUEX_OPTION_COUNTER
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) \
            do {                              \
                QUEX_NAME(FUNCTION_DEFINITION_counter)((ME), (BEGIN), (END));     \
                __quex_debug_counter();       \
            } while(0)
#else
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) /* empty */
#endif

#include <quex/code_base/analyzer/member/basic>
#include <quex/code_base/buffer/Buffer>
#ifdef QUEX_OPTION_TOKEN_POLICY_QUEUE
#   include <quex/code_base/token/TokenQueue>
#endif

#ifdef    CONTINUE
#   undef CONTINUE
#endif
#define   CONTINUE goto __REENTRY_PREPARATION; 

#ifdef    RETURN
#   undef RETURN
#endif

#define RETURN    __QUEX_PURE_RETURN;
#include <quex/code_base/temporary_macros_on>

__QUEX_TYPE_ANALYZER_RETURN_VALUE  
QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS_analyzer_function)(QUEX_TYPE_ANALYZER* me) 
{
    /* NOTE: Different modes correspond to different analyzer functions. The 
     *       analyzer functions are all located inside the main class as static
     *       functions. That means, they are something like 'globals'. They 
     *       receive a pointer to the lexical analyzer, since static members do
     *       not have access to the 'this' pointer.                          */
#   if defined(QUEX_OPTION_TOKEN_POLICY_SINGLE)
    register QUEX_TYPE_TOKEN_ID __self_result_token_id 
           = (QUEX_TYPE_TOKEN_ID)__QUEX_SETTING_TOKEN_ID_UNINITIALIZED;
#   endif
#   ifdef     self
#       undef self
#   endif
#   define self (*((QUEX_TYPE_ANALYZER*)me))
    const QUEX_TYPE_CHARACTER      Skipper1120_Closer[2]          = { 0x2A, 0x2F,  };
    const QUEX_TYPE_CHARACTER      Skipper1120_Opener[2]          = { 0x2F, 0x2A,  };
    QUEX_TYPE_CHARACTER_POSITION   position[1]                    = { 0};
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
    const QUEX_TYPE_CHARACTER*     Skipper1120_Opener_it          = 0x0;
    size_t                         counter                        = 0;
    QUEX_TYPE_CHARACTER_POSITION   reference_p                    = (QUEX_TYPE_CHARACTER_POSITION)0x0;
    const size_t                   PositionRegisterN              = (size_t)1;
    QUEX_TYPE_ACCEPTANCE_ID        last_acceptance               /* un-initilized */;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    const QUEX_TYPE_CHARACTER*     Skipper1120_OpenerEnd          = Skipper1120_Opener + (ptrdiff_t)2;
    const QUEX_TYPE_CHARACTER*     Skipper1120_CloserEnd          = Skipper1120_Closer + (ptrdiff_t)2;
    const QUEX_TYPE_CHARACTER*     Skipper1120_Closer_it          = 0x0;
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
#   ifdef QUEX_OPTION_COLUMN_NUMBER_COUNTING
#   endif /* QUEX_OPTION_COLUMN_NUMBER_COUNTING */
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */
#   define FUNCTION_DEFINITION               (QUEX_NAME(FUNCTION_DEFINITION))
#   define STRING_RELATIVE                   (QUEX_NAME(STRING_RELATIVE))
#   define FUNCTION_DEFINITION_PARAMETERS    (QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS))
#   define STRING_ABSOLUTE                   (QUEX_NAME(STRING_ABSOLUTE))
#   define SCOPE                             (QUEX_NAME(SCOPE))
#   define EXPRESSION                        (QUEX_NAME(EXPRESSION))

    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE) \
       || defined(QUEX_OPTION_ASSERTS)
    me->DEBUG_analyzer_function_at_entry = me->current_analyzer_function;
#   endif
__REENTRY:
    me->buffer._lexeme_start_p = me->buffer._input_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_1173: /* INIT_STATE_TRANSITION_BLOCK */
    { last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1); __quex_debug("last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1)\n"); }
    input = *(me->buffer._input_p);
    __quex_debug("Init State\n");
    __quex_debug_state(1159);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1159, 955);
        case 0x9: goto _1161;
        case 0xA: goto _1160;
        case 0xD: 
        case 0x20: goto _1162;
        case 0x29: goto _1163;
        case 0x2F: goto _1164;

    }
    __quex_debug_drop_out(1159);

goto _1040; /* TERMINAL_FAILURE */

_1159:


    ++(me->buffer._input_p);
    goto _1173;


    __quex_assert_no_passage();
_1175: /* (1166 from 1171) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1166: /* (1166 from 1166) (1166 from 1164) (1166 from 1170) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1166);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1166, 1176);
        case 0xA: goto _1169;
        case 0xD: goto _1168;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1166;
        case 0x5C: goto _1167;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1166;

    }
_1176:
    __quex_debug_drop_out(1166);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */
    case 882: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_882;

}

    __quex_assert_no_passage();
_1177: /* (1167 from 1171) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1167: /* (1167 from 1167) (1167 from 1170) (1167 from 1172) (1167 from 1166) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1167);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1167, 1178);
        case 0x9: goto _1167;
        case 0xA: goto _1170;
        case 0xD: 
        case 0x20: goto _1167;

    }
_1178:
    __quex_debug_drop_out(1167);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */
    case 882: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_882;

}

    __quex_assert_no_passage();
_1179: /* (1171 from 1171) (1171 from 1172) (1171 from 1170) */
    { last_acceptance = 882; __quex_debug("last_acceptance = 882\n"); }

_1171:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1171);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1171, 1180);
        case 0x9: goto _1177;
        case 0xA: goto _1179;
        case 0xD: goto _1181;
        case 0x20: goto _1177;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1175;
        case 0x5C: goto _1177;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1175;

    }
_1180:
    __quex_debug_drop_out(1171);
goto TERMINAL_882;

    __quex_assert_no_passage();
_1169: /* (1169 from 1168) (1169 from 1166) */

    ++(me->buffer._input_p);
    __quex_debug_state(1169);
    __quex_debug_drop_out(1169);
goto TERMINAL_882;

    __quex_assert_no_passage();
_1181: /* (1172 from 1171) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1172: /* (1172 from 1170) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1172);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1172, 1183);
        case 0x9: goto _1167;
        case 0xA: goto _1179;
        case 0xD: 
        case 0x20: goto _1167;

    }
_1183:
    __quex_debug_drop_out(1172);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */
    case 882: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_882;

}

    __quex_assert_no_passage();
_1165: /* (1165 from 1164) */

    ++(me->buffer._input_p);
    __quex_debug_state(1165);
    __quex_debug_drop_out(1165);
goto TERMINAL_881;

    __quex_assert_no_passage();
_1168: /* (1168 from 1166) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1168);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1168, 1185);
        case 0xA: goto _1169;

    }
_1185:
    __quex_debug_drop_out(1168);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */
    case 882: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_882;

}

    __quex_assert_no_passage();
_1170: /* (1170 from 1167) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1170);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1170, 1186);
        case 0x9: goto _1167;
        case 0xA: goto _1179;
        case 0xD: goto _1172;
        case 0x20: goto _1167;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1166;
        case 0x5C: goto _1167;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1166;

    }
_1186:
    __quex_debug_drop_out(1170);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */
    case 882: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_882;

}

    __quex_assert_no_passage();
_1160: /* (1160 from 1159) */

    ++(me->buffer._input_p);
    __quex_debug_state(1160);
    __quex_debug_drop_out(1160);
goto TERMINAL_880;

    __quex_assert_no_passage();
_1161: /* (1161 from 1159) */

    ++(me->buffer._input_p);
    __quex_debug_state(1161);
    __quex_debug_drop_out(1161);
goto TERMINAL_879;

    __quex_assert_no_passage();
_1162: /* (1162 from 1159) */

    ++(me->buffer._input_p);
    __quex_debug_state(1162);
    __quex_debug_drop_out(1162);
goto TERMINAL_878;

    __quex_assert_no_passage();
_1163: /* (1163 from 1159) */

    ++(me->buffer._input_p);
    __quex_debug_state(1163);
    __quex_debug_drop_out(1163);
goto TERMINAL_883;

    __quex_assert_no_passage();
_1164: /* (1164 from 1159) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1164);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1164, 1191);
        case 0x2A: goto _1165;
        case 0x2F: goto _1166;

    }
_1191:
    __quex_debug_drop_out(1164);

goto _1040; /* TERMINAL_FAILURE */
    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */

    /* Lexeme setup: 
     *
     * There is a temporary zero stored at the end of each lexeme, if the action 
     * references to the 'Lexeme'. 'LexemeNull' provides a reference to an empty
     * zero terminated string.                                                    */
#if defined(QUEX_OPTION_ASSERTS)
#   define Lexeme       QUEX_NAME(access_Lexeme)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeBegin  QUEX_NAME(access_LexemeBegin)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeL      QUEX_NAME(access_LexemeL)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeEnd    QUEX_NAME(access_LexemeEnd)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#else
#   define Lexeme       (me->buffer._lexeme_start_p)
#   define LexemeBegin  Lexeme
#   define LexemeL      ((size_t)(me->buffer._input_p - me->buffer._lexeme_start_p))
#   define LexemeEnd    me->buffer._input_p
#endif

#define LexemeNull      (&QUEX_LEXEME_NULL)

TERMINAL_878:
    __quex_debug("* terminal 878:   <skip: ... (check also base modes)>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 245 "lexical_analyzer.qx"
    goto __SKIP;
    
#   line 2338 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_879:
    __quex_debug("* terminal 879:   <skip: ... (check also base modes)>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4);

    {
#   line 245 "lexical_analyzer.qx"
    goto __SKIP;
    
#   line 2353 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_880:
    __quex_debug("* terminal 880:   <skip>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_LINES_ADD(1);
__QUEX_IF_COUNT_COLUMNS_SET(1);
    {
__SKIP:
    /* Character Set Skipper: '['\t', '\n'], '\r', ' '' */
    QUEX_BUFFER_ASSERT_CONSISTENCY(&me->buffer);
__QUEX_IF_COUNT_COLUMNS(reference_p = me->buffer._input_p);
    while( 1 + 1 == 2 ) {
_1118:
        if( (*me->buffer._input_p) < 0xB ) {
            switch( (*me->buffer._input_p) ) {
                case 0x0: QUEX_GOTO_RELOAD(_1119, 1118, 955);
                case 0x1:
                case 0x2:
                case 0x3:
                case 0x4:
                case 0x5:
                case 0x6:
                case 0x7:
                case 0x8: __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
                case 0x9:             __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
            __QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
            __QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4);
            __QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p) + 1);
                    ++((me->buffer._input_p));
                continue;
                case 0xA: __QUEX_IF_COUNT_LINES_ADD((size_t)1);
            __QUEX_IF_COUNT_COLUMNS_SET((size_t)1);
            __QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p) + 1);
                    ++((me->buffer._input_p));
                continue;

            }
        } else {
            if( (*me->buffer._input_p) < 0xD ) {
                __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
            } else if( (*me->buffer._input_p) == 0xD ) {
                        ++((me->buffer._input_p));
                continue;
            } else if( (*me->buffer._input_p) < 0x20 ) {
                __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
            } else if( (*me->buffer._input_p) == 0x20 ) {
                        ++((me->buffer._input_p));
                continue;
            } else {
                __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
            }
        }

    __quex_assert_no_passage();
_1119:

    __quex_debug1("__RELOAD_FORWARD");
    __quex_assert(*((me->buffer._input_p)) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
me->buffer._lexeme_start_p = (me->buffer._input_p);

        __quex_debug_reload_before(); /* Leave macro here to report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);
        ++((me->buffer._input_p));
__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);
    }

    }
    goto __REENTRY_PREPARATION;

TERMINAL_881:
    __quex_debug("* terminal 881:   {D_COMMENT_STREAM_BEGINNING}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
    Skipper1120_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1120_Opener;
    Skipper1120_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1120_Closer;
    /* text_end                           = QUEX_NAME(Buffer_text_end)(&me->buffer); */
    __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));


_1120:

    QUEX_BUFFER_ASSERT_CONSISTENCY(&me->buffer);
    __quex_assert(QUEX_NAME(Buffer_content_size)(&me->buffer) >= 2 );

    /* NOTE: If _input_p == end of buffer, then it will drop out immediately out of the
        *       loop below and drop into the buffer reload procedure.                      */

    /* Loop eating characters: Break-out as soon as the First Character of the Delimiter
        * (FCD) is reached. Thus, the FCD plays also the role of the Buffer Limit Code. There
        * are two reasons for break-out:
        *    (1) we reached a limit (end-of-file or buffer-limit)
        *    (2) there was really the FCD in the character stream
        * This must be distinguished after the loop was exited. But, during the 'swallowing'
        * we are very fast, because we do not have to check for two different characters.  */
    while( 1 + 1 == 2 ) {
            input = *(me->buffer._input_p);

            if( input == QUEX_SETTING_BUFFER_LIMIT_CODE ) {
                    goto _1121;
            }
            if( input == *Skipper1120_Closer_it ) {
                    ++Skipper1120_Closer_it;
                    if( Skipper1120_Closer_it == Skipper1120_CloserEnd ) {
                        if( counter == 0 ) {
                            /* NOTE: The initial state does not increment the input_p. When it detects that
                                * it is located on a buffer border, it automatically triggers a reload. No
                                * need here to reload the buffer. */
                            ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
                                    __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer)
                                            - reference_p));

                            /* No need for re-entry preparation. Acceptance flags and modes are untouched after skipping. */
                            goto __REENTRY; /* End of range reached. */
                        }
                        --counter;
                        Skipper1120_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1120_Opener;
                        Skipper1120_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1120_Closer;
                        goto CONTINUE_1120;
                    }
            } else {
                    Skipper1120_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1120_Closer;
            }
            if( input == *Skipper1120_Opener_it ) {
                    ++Skipper1120_Opener_it;
                    if( Skipper1120_Opener_it == Skipper1120_OpenerEnd ) {
                        ++counter;
                        Skipper1120_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1120_Opener;
                        Skipper1120_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1120_Closer;
                        goto CONTINUE_1120;
                    }
            } else {
                    Skipper1120_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1120_Opener;
            }
CONTINUE_1120:

    __QUEX_IF_COUNT_IF( input == (QUEX_TYPE_CHARACTER)'\n' ) {
            __QUEX_IF_COUNT_LINES_ADD((size_t)1);
            __QUEX_IF_COUNT_COLUMNS_SET((size_t)0);
            __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));
    }

            ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
    }

_1121:
    QUEX_BUFFER_ASSERT_CONSISTENCY_LIGHT(&me->buffer);
    /* -- When loading new content it is checked that the beginning of the lexeme
        *    is not 'shifted' out of the buffer. In the case of skipping, we do not care about
        *    the lexeme at all, so do not restrict the load procedure and set the lexeme start
        *    to the actual input position.                                                    */
    me->buffer._lexeme_start_p = me->buffer._input_p;

    __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer)
                                        - reference_p));

    if( QUEX_NAME(Buffer_is_end_of_file)(&me->buffer) == false ) {
            QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position,
                                                PositionRegisterN);
            /* Recover '_input_p' from lexeme start
                * (inverse of what we just did before the loading) */
            me->buffer._input_p = me->buffer._lexeme_start_p;
            /* After reload, we need to increment _input_p. That's how the game is supposed to be played.
                * But, we recovered from lexeme start pointer, and this one does not need to be incremented. */
            /* text_end = QUEX_NAME(Buffer_text_end)(&me->buffer); */
            __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));

            QUEX_BUFFER_ASSERT_CONSISTENCY(&me->buffer);
            goto _1120; /* End of range reached.             */
    }
    /* Here, either the loading failed or it is not enough space to carry a closing delimiter */
    me->buffer._input_p = me->buffer._lexeme_start_p;
    QUEX_ERROR_EXIT("\nLexical analyzer mode 'FUNCTION_DEFINITION_PARAMETERS':\n"
                        "End of file occurred before closing skip range delimiter!\n"                "The 'on_skip_range_open' handler has not been specified.");

    }
    goto __REENTRY_PREPARATION;

TERMINAL_882:
    __quex_debug("* terminal 882:   {D_COMMENT_BLOCK}([inverse({D_NEW_LINE})]|({D_BACKSLASH}{D_WHITESPACE}*{D_NEW_LINE}))*{D_NEW_LINE}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 252 "lexical_analyzer.qx"
    
        // We are within a comment. Do not do anything.
    
    
#   line 2556 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_883:
    __quex_debug("* terminal 883:   \")\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 415 "lexical_analyzer.qx"
    QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_PARENTHESIS_END);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2570 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;


_1040: /* TERMINAL: FAILURE */
    if(QUEX_NAME(Buffer_is_end_of_file)(&me->buffer)) {
        /* Init state is going to detect 'input == buffer limit code', and
         * enter the reload procedure, which will decide about 'end of stream'. */
    } else {
        /* In init state 'input = *input_p' and we need to increment
         * in order to avoid getting stalled. Else, input = *(input_p - 1),
         * so 'input_p' points already to the next character.                   */
        if( me->buffer._input_p == me->buffer._lexeme_start_p ) {
            /* Step over non-matching character */
            ++(me->buffer._input_p);
        }
    }
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    QUEX_LEXEME_TERMINATING_ZERO_SET(&me->buffer);
    {
#   line 237 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_FAILURE);
    
        RETURN;
    
    
#   line 2599 "lexical_analyzer.cpp"
    
#   line 418 "lexical_analyzer.qx"
    
        self_accumulator_add (Lexeme, LexemeEnd);
    
    
#   line 2606 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION_2;


/* TERMINAL: END_OF_STREAM */
_955:
__QUEX_IF_COUNT_SHIFT_VALUES();
    {
#   line 230 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_TERMINATION);
    
        RETURN;
    
    
#   line 2623 "lexical_analyzer.cpp"

    }
    /* End of Stream causes a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.                    */
    RETURN;

__REENTRY_PREPARATION:
    /* (*) Common point for **restarting** lexical analysis.
     *     at each time when CONTINUE is called at the end of a pattern.     */
 

    /* FAILURE needs not to run through 'on_after_match'. It enters here.    */
__REENTRY_PREPARATION_2:

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL

#   ifndef __QUEX_OPTION_PLAIN_ANALYZER_OBJECT
#   ifdef  QUEX_OPTION_TOKEN_POLICY_QUEUE
    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) {
        return;
    }
#   else
    if( self_token_get_id() != __QUEX_SETTING_TOKEN_ID_UNINITIALIZED) {
        return __self_result_token_id;
    }
#   endif
#   endif


    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */

    /*  If a mode change happened, then the function must first return and
     *  indicate that another mode function is to be called. At this point, 
     *  we to force a 'return' on a mode change. 
     *
     *  Pseudo Code: if( previous_mode != current_mode ) {
     *                   return 0;
     *               }
     *
     *  When the analyzer returns, the caller function has to watch if a mode 
     *  change occurred. If not it can call this function again.             */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)        || defined(QUEX_OPTION_ASSERTS)
    if( me->DEBUG_analyzer_function_at_entry != me->current_analyzer_function ) 
#   endif
    { 
#       if defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)
        self_token_set_id(__QUEX_SETTING_TOKEN_ID_UNINITIALIZED);
        __QUEX_PURE_RETURN;
#       elif defined(QUEX_OPTION_ASSERTS)
        QUEX_ERROR_EXIT("Mode change without immediate return from the lexical analyzer.");
#       endif
    }

    goto __REENTRY;

    __quex_assert_no_passage();
__RELOAD_FORWARD:

    __quex_debug1("__RELOAD_FORWARD");
    __quex_assert(*(me->buffer._input_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {

        __quex_debug_reload_before(); /* Leave macro here to report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
__STATE_ROUTER:
    switch( target_state_index ) {
        case 955: { goto _955; }
        case 1118: { goto _1118; }
        case 1119: { goto _1119; }
        case 1120: { goto _1120; }
        case 1159: { goto _1159; }
        case 1160: { goto _1160; }
        case 1161: { goto _1161; }
        case 1162: { goto _1162; }
        case 1163: { goto _1163; }
        case 1164: { goto _1164; }
        case 1165: { goto _1165; }
        case 1166: { goto _1166; }
        case 1167: { goto _1167; }
        case 1168: { goto _1168; }
        case 1169: { goto _1169; }
        case 1170: { goto _1170; }
        case 1171: { goto _1171; }
        case 1172: { goto _1172; }
        case 1175: { goto _1175; }
        case 1176: { goto _1176; }
        case 1177: { goto _1177; }
        case 1178: { goto _1178; }
        case 1179: { goto _1179; }
        case 1180: { goto _1180; }
        case 1181: { goto _1181; }
        case 1183: { goto _1183; }
        case 1185: { goto _1185; }
        case 1186: { goto _1186; }
        case 1191: { goto _1191; }

        default:
            __QUEX_STD_fprintf(stderr, "State router: index = %i\n", (int)target_state_index);
            QUEX_ERROR_EXIT("State router: unknown index.\n");
    }
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */

    /* Prevent compiler warning 'unused variable': use variables once in a part of the code*/
    /* that is never reached (and deleted by the compiler anyway).*/
    (void)QUEX_LEXEME_NULL;
    (void)QUEX_NAME_TOKEN(DumpedTokenIdObject);
    QUEX_ERROR_EXIT("Unreachable code has been reached.\n");
#   undef FUNCTION_DEFINITION
#   undef STRING_RELATIVE
#   undef FUNCTION_DEFINITION_PARAMETERS
#   undef STRING_ABSOLUTE
#   undef SCOPE
#   undef EXPRESSION
#   undef self
}
#include <quex/code_base/temporary_macros_off>
#ifdef      __QUEX_COUNT_VOID
#   undef   __QUEX_COUNT_VOID
#endif
#ifdef      __QUEX_OPTION_COUNTER
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) \
            do {                              \
                QUEX_NAME(FUNCTION_DEFINITION_counter)((ME), (BEGIN), (END));     \
                __quex_debug_counter();       \
            } while(0)
#else
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) /* empty */
#endif

#include <quex/code_base/analyzer/member/basic>
#include <quex/code_base/buffer/Buffer>
#ifdef QUEX_OPTION_TOKEN_POLICY_QUEUE
#   include <quex/code_base/token/TokenQueue>
#endif

#ifdef    CONTINUE
#   undef CONTINUE
#endif
#define   CONTINUE goto __REENTRY_PREPARATION; 

#ifdef    RETURN
#   undef RETURN
#endif

#define RETURN    __QUEX_PURE_RETURN;
#include <quex/code_base/temporary_macros_on>

__QUEX_TYPE_ANALYZER_RETURN_VALUE  
QUEX_NAME(STRING_ABSOLUTE_analyzer_function)(QUEX_TYPE_ANALYZER* me) 
{
    /* NOTE: Different modes correspond to different analyzer functions. The 
     *       analyzer functions are all located inside the main class as static
     *       functions. That means, they are something like 'globals'. They 
     *       receive a pointer to the lexical analyzer, since static members do
     *       not have access to the 'this' pointer.                          */
#   if defined(QUEX_OPTION_TOKEN_POLICY_SINGLE)
    register QUEX_TYPE_TOKEN_ID __self_result_token_id 
           = (QUEX_TYPE_TOKEN_ID)__QUEX_SETTING_TOKEN_ID_UNINITIALIZED;
#   endif
#   ifdef     self
#       undef self
#   endif
#   define self (*((QUEX_TYPE_ANALYZER*)me))
    void*                          position                       = (void*)0x0;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    const size_t                   PositionRegisterN              = (size_t)0;
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */
#   define FUNCTION_DEFINITION               (QUEX_NAME(FUNCTION_DEFINITION))
#   define STRING_RELATIVE                   (QUEX_NAME(STRING_RELATIVE))
#   define FUNCTION_DEFINITION_PARAMETERS    (QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS))
#   define STRING_ABSOLUTE                   (QUEX_NAME(STRING_ABSOLUTE))
#   define SCOPE                             (QUEX_NAME(SCOPE))
#   define EXPRESSION                        (QUEX_NAME(EXPRESSION))

    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE) \
       || defined(QUEX_OPTION_ASSERTS)
    me->DEBUG_analyzer_function_at_entry = me->current_analyzer_function;
#   endif
__REENTRY:
    me->buffer._lexeme_start_p = me->buffer._input_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_1206: /* INIT_STATE_TRANSITION_BLOCK */
    input = *(me->buffer._input_p);
    __quex_debug("Init State\n");
    __quex_debug_state(1203);
    if( input < 0xA ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1203, 955);
            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: 
            case 0x9: goto _1204;

        }
    } else {
        if( input == 0xA ) {

        } else if( input < 0x27 ) {
            goto _1204;
        } else if( input == 0x27 ) {
            goto _1205;
        } else {
            goto _1204;
        }
    }
    __quex_debug_drop_out(1203);

goto _1040; /* TERMINAL_FAILURE */

_1203:


    ++(me->buffer._input_p);
    goto _1206;


    __quex_assert_no_passage();
_1204: /* (1204 from 1203) */

    ++(me->buffer._input_p);
    __quex_debug_state(1204);
    __quex_debug_drop_out(1204);
goto TERMINAL_885;

    __quex_assert_no_passage();
_1205: /* (1205 from 1203) */

    ++(me->buffer._input_p);
    __quex_debug_state(1205);
    __quex_debug_drop_out(1205);
goto TERMINAL_884;
    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */

    /* Lexeme setup: 
     *
     * There is a temporary zero stored at the end of each lexeme, if the action 
     * references to the 'Lexeme'. 'LexemeNull' provides a reference to an empty
     * zero terminated string.                                                    */
#if defined(QUEX_OPTION_ASSERTS)
#   define Lexeme       QUEX_NAME(access_Lexeme)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeBegin  QUEX_NAME(access_LexemeBegin)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeL      QUEX_NAME(access_LexemeL)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeEnd    QUEX_NAME(access_LexemeEnd)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#else
#   define Lexeme       (me->buffer._lexeme_start_p)
#   define LexemeBegin  Lexeme
#   define LexemeL      ((size_t)(me->buffer._input_p - me->buffer._lexeme_start_p))
#   define LexemeEnd    me->buffer._input_p
#endif

#define LexemeNull      (&QUEX_LEXEME_NULL)

TERMINAL_884:
    __quex_debug("* terminal 884:   {D_QUOTE_SINGLE}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 313 "lexical_analyzer.qx"
    QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_STRING_ABSOLUTE_END);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2929 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_885:
    __quex_debug("* terminal 885:   {D_ANY_CHARACTER}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 315 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_CHARACTER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2943 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;


_1040: /* TERMINAL: FAILURE */
    if(QUEX_NAME(Buffer_is_end_of_file)(&me->buffer)) {
        /* Init state is going to detect 'input == buffer limit code', and
         * enter the reload procedure, which will decide about 'end of stream'. */
    } else {
        /* In init state 'input = *input_p' and we need to increment
         * in order to avoid getting stalled. Else, input = *(input_p - 1),
         * so 'input_p' points already to the next character.                   */
        if( me->buffer._input_p == me->buffer._lexeme_start_p ) {
            /* Step over non-matching character */
            ++(me->buffer._input_p);
        }
    }
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    QUEX_LEXEME_TERMINATING_ZERO_SET(&me->buffer);
    {
#   line 237 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_FAILURE);
    
        RETURN;
    
    
#   line 2972 "lexical_analyzer.cpp"
    
#   line 318 "lexical_analyzer.qx"
    
        self_accumulator_add (Lexeme, LexemeEnd);
    
    
#   line 2979 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION_2;


/* TERMINAL: END_OF_STREAM */
_955:
__QUEX_IF_COUNT_SHIFT_VALUES();
    {
#   line 230 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_TERMINATION);
    
        RETURN;
    
    
#   line 2996 "lexical_analyzer.cpp"

    }
    /* End of Stream causes a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.                    */
    RETURN;

__REENTRY_PREPARATION:
    /* (*) Common point for **restarting** lexical analysis.
     *     at each time when CONTINUE is called at the end of a pattern.     */
 

    /* FAILURE needs not to run through 'on_after_match'. It enters here.    */
__REENTRY_PREPARATION_2:

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL

#   ifndef __QUEX_OPTION_PLAIN_ANALYZER_OBJECT
#   ifdef  QUEX_OPTION_TOKEN_POLICY_QUEUE
    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) {
        return;
    }
#   else
    if( self_token_get_id() != __QUEX_SETTING_TOKEN_ID_UNINITIALIZED) {
        return __self_result_token_id;
    }
#   endif
#   endif


    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */

    /*  If a mode change happened, then the function must first return and
     *  indicate that another mode function is to be called. At this point, 
     *  we to force a 'return' on a mode change. 
     *
     *  Pseudo Code: if( previous_mode != current_mode ) {
     *                   return 0;
     *               }
     *
     *  When the analyzer returns, the caller function has to watch if a mode 
     *  change occurred. If not it can call this function again.             */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)        || defined(QUEX_OPTION_ASSERTS)
    if( me->DEBUG_analyzer_function_at_entry != me->current_analyzer_function ) 
#   endif
    { 
#       if defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)
        self_token_set_id(__QUEX_SETTING_TOKEN_ID_UNINITIALIZED);
        __QUEX_PURE_RETURN;
#       elif defined(QUEX_OPTION_ASSERTS)
        QUEX_ERROR_EXIT("Mode change without immediate return from the lexical analyzer.");
#       endif
    }

    goto __REENTRY;

    __quex_assert_no_passage();
__RELOAD_FORWARD:

    __quex_debug1("__RELOAD_FORWARD");
    __quex_assert(*(me->buffer._input_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {

        __quex_debug_reload_before(); /* Leave macro here to report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
__STATE_ROUTER:
    switch( target_state_index ) {
        case 955: { goto _955; }
        case 1203: { goto _1203; }
        case 1204: { goto _1204; }
        case 1205: { goto _1205; }

        default:
            __QUEX_STD_fprintf(stderr, "State router: index = %i\n", (int)target_state_index);
            QUEX_ERROR_EXIT("State router: unknown index.\n");
    }
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */

    /* Prevent compiler warning 'unused variable': use variables once in a part of the code*/
    /* that is never reached (and deleted by the compiler anyway).*/
    (void)QUEX_LEXEME_NULL;
    (void)QUEX_NAME_TOKEN(DumpedTokenIdObject);
    QUEX_ERROR_EXIT("Unreachable code has been reached.\n");
#   undef FUNCTION_DEFINITION
#   undef STRING_RELATIVE
#   undef FUNCTION_DEFINITION_PARAMETERS
#   undef STRING_ABSOLUTE
#   undef SCOPE
#   undef EXPRESSION
#   undef self
}
#include <quex/code_base/temporary_macros_off>
#ifdef      __QUEX_COUNT_VOID
#   undef   __QUEX_COUNT_VOID
#endif
#ifdef      __QUEX_OPTION_COUNTER
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) \
            do {                              \
                QUEX_NAME(FUNCTION_DEFINITION_counter)((ME), (BEGIN), (END));     \
                __quex_debug_counter();       \
            } while(0)
#else
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) /* empty */
#endif

#include <quex/code_base/analyzer/member/basic>
#include <quex/code_base/buffer/Buffer>
#ifdef QUEX_OPTION_TOKEN_POLICY_QUEUE
#   include <quex/code_base/token/TokenQueue>
#endif

#ifdef    CONTINUE
#   undef CONTINUE
#endif
#define   CONTINUE goto __REENTRY_PREPARATION; 

#ifdef    RETURN
#   undef RETURN
#endif

#define RETURN    __QUEX_PURE_RETURN;
#include <quex/code_base/temporary_macros_on>

__QUEX_TYPE_ANALYZER_RETURN_VALUE  
QUEX_NAME(SCOPE_analyzer_function)(QUEX_TYPE_ANALYZER* me) 
{
    /* NOTE: Different modes correspond to different analyzer functions. The 
     *       analyzer functions are all located inside the main class as static
     *       functions. That means, they are something like 'globals'. They 
     *       receive a pointer to the lexical analyzer, since static members do
     *       not have access to the 'this' pointer.                          */
#   if defined(QUEX_OPTION_TOKEN_POLICY_SINGLE)
    register QUEX_TYPE_TOKEN_ID __self_result_token_id 
           = (QUEX_TYPE_TOKEN_ID)__QUEX_SETTING_TOKEN_ID_UNINITIALIZED;
#   endif
#   ifdef     self
#       undef self
#   endif
#   define self (*((QUEX_TYPE_ANALYZER*)me))
    const QUEX_TYPE_CHARACTER      Skipper1212_Closer[2]          = { 0x2A, 0x2F,  };
    const QUEX_TYPE_CHARACTER      Skipper1212_Opener[2]          = { 0x2F, 0x2A,  };
    const QUEX_TYPE_CHARACTER*     Skipper1212_CloserEnd          = Skipper1212_Closer + (ptrdiff_t)2;
    const QUEX_TYPE_CHARACTER*     Skipper1212_Closer_it          = 0x0;
    QUEX_TYPE_CHARACTER_POSITION   position[1]                    = { 0};
    size_t                         counter                        = 0;
    const QUEX_TYPE_CHARACTER*     Skipper1212_Opener_it          = 0x0;
    QUEX_TYPE_CHARACTER_POSITION   reference_p                    = (QUEX_TYPE_CHARACTER_POSITION)0x0;
    QUEX_TYPE_ACCEPTANCE_ID        last_acceptance               /* un-initilized */;
    const size_t                   PositionRegisterN              = (size_t)1;
    const QUEX_TYPE_CHARACTER*     Skipper1212_OpenerEnd          = Skipper1212_Opener + (ptrdiff_t)2;
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
#   ifdef QUEX_OPTION_COLUMN_NUMBER_COUNTING
#   endif /* QUEX_OPTION_COLUMN_NUMBER_COUNTING */
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */
#   define FUNCTION_DEFINITION               (QUEX_NAME(FUNCTION_DEFINITION))
#   define STRING_RELATIVE                   (QUEX_NAME(STRING_RELATIVE))
#   define FUNCTION_DEFINITION_PARAMETERS    (QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS))
#   define STRING_ABSOLUTE                   (QUEX_NAME(STRING_ABSOLUTE))
#   define SCOPE                             (QUEX_NAME(SCOPE))
#   define EXPRESSION                        (QUEX_NAME(EXPRESSION))

    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE) \
       || defined(QUEX_OPTION_ASSERTS)
    me->DEBUG_analyzer_function_at_entry = me->current_analyzer_function;
#   endif
__REENTRY:
    me->buffer._lexeme_start_p = me->buffer._input_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_1436: /* INIT_STATE_TRANSITION_BLOCK */
    { last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1); __quex_debug("last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1)\n"); }
    input = *(me->buffer._input_p);
    __quex_debug("Init State\n");
    __quex_debug_state(1379);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1379, 955);
        case 0x9: goto _1395;
        case 0xA: goto _1380;
        case 0xD: 
        case 0x20: goto _1383;
        case 0x22: goto _1396;
        case 0x23: goto _1391;
        case 0x24: goto _1385;
        case 0x27: goto _1393;
        case 0x28: goto _1390;
        case 0x2B: 
        case 0x2D: goto _1397;
        case 0x2E: goto _1386;
        case 0x2F: goto _1381;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1387;
        case 0x3B: goto _1389;
        case 0x3D: goto _1384;
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: goto _1398;
        case 0x65: goto _1394;
        case 0x66: goto _1392;
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;
        case 0x7B: goto _1382;
        case 0x7D: goto _1388;

    }
    __quex_debug_drop_out(1379);

goto _1040; /* TERMINAL_FAILURE */

_1379:


    ++(me->buffer._input_p);
    goto _1436;


    __quex_assert_no_passage();
_1398: /* (1398 from 1398) (1398 from 1394) (1398 from 1392) (1398 from 1406) (1398 from 1405) (1398 from 1404) (1398 from 1403) (1398 from 1402) (1398 from 1401) (1398 from 1379) (1398 from 1410) (1398 from 1409) (1398 from 1408) (1398 from 1407) (1398 from 1387) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1398);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1398, 1438);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1438:
    __quex_debug_drop_out(1398);
goto TERMINAL_907;

    __quex_assert_no_passage();
_1439: /* (1429 from 1434) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1429: /* (1429 from 1429) (1429 from 1381) (1429 from 1433) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1429);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1429, 1440);
        case 0xA: goto _1432;
        case 0xD: goto _1431;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1429;
        case 0x5C: goto _1430;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1429;

    }
_1440:
    __quex_debug_drop_out(1429);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */
    case 896: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_896;

}

    __quex_assert_no_passage();
_1441: /* (1430 from 1434) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1430: /* (1430 from 1430) (1430 from 1429) (1430 from 1435) (1430 from 1433) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1430);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1430, 1442);
        case 0x9: goto _1430;
        case 0xA: goto _1433;
        case 0xD: 
        case 0x20: goto _1430;

    }
_1442:
    __quex_debug_drop_out(1430);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */
    case 896: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_896;

}

    __quex_assert_no_passage();
_1427: /* (1427 from 1427) (1427 from 1385) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1427);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1427, 1443);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1427;

    }
_1443:
    __quex_debug_drop_out(1427);
goto TERMINAL_899;

    __quex_assert_no_passage();
_1400: /* (1400 from 1400) (1400 from 1399) (1400 from 1387) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1400);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1400, 1444);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1400;

    }
_1444:
    __quex_debug_drop_out(1400);
goto TERMINAL_902;

    __quex_assert_no_passage();
_1445: /* (1434 from 1434) (1434 from 1433) (1434 from 1435) */
    { last_acceptance = 896; __quex_debug("last_acceptance = 896\n"); }

_1434:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1434);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1434, 1446);
        case 0x9: goto _1441;
        case 0xA: goto _1445;
        case 0xD: goto _1447;
        case 0x20: goto _1441;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1439;
        case 0x5C: goto _1441;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1439;

    }
_1446:
    __quex_debug_drop_out(1434);
goto TERMINAL_896;

    __quex_assert_no_passage();
_1391: /* (1391 from 1391) (1391 from 1379) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1391);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1391, 1448);
        case 0x9: 
        case 0xA: 
        case 0xD: 
        case 0x20: goto _1391;
        case 0x69: goto _1412;
        case 0x73: goto _1411;

    }
_1448:
    __quex_debug_drop_out(1391);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1432: /* (1432 from 1431) (1432 from 1429) */

    ++(me->buffer._input_p);
    __quex_debug_state(1432);
    __quex_debug_drop_out(1432);
goto TERMINAL_896;

    __quex_assert_no_passage();
_1447: /* (1435 from 1434) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1435: /* (1435 from 1433) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1435);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1435, 1450);
        case 0x9: goto _1430;
        case 0xA: goto _1445;
        case 0xD: 
        case 0x20: goto _1430;

    }
_1450:
    __quex_debug_drop_out(1435);
switch( last_acceptance ) {
    case 896: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_896;
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */

}

    __quex_assert_no_passage();
_1399: /* (1399 from 1399) (1399 from 1397) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1399);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1399, 1451);
        case 0x2C: 
        case 0x2E: goto _1400;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1399;

    }
_1451:
    __quex_debug_drop_out(1399);
goto TERMINAL_902;

    __quex_assert_no_passage();
_1408: /* (1408 from 1407) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1408);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1408, 1452);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: goto _1398;
        case 0x6F: goto _1409;
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1452:
    __quex_debug_drop_out(1408);
goto TERMINAL_907;

    __quex_assert_no_passage();
_1409: /* (1409 from 1408) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1409);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1409, 1453);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: goto _1398;
        case 0x6E: goto _1410;
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1453:
    __quex_debug_drop_out(1409);
goto TERMINAL_907;

    __quex_assert_no_passage();
_1410: /* (1410 from 1409) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1410);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1410, 1454);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1454:
    __quex_debug_drop_out(1410);
goto TERMINAL_901;

    __quex_assert_no_passage();
_1411: /* (1411 from 1391) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1411);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1411, 1455);
        case 0x65: goto _1419;

    }
_1455:
    __quex_debug_drop_out(1411);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1412: /* (1412 from 1391) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1412);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1412, 1456);
        case 0x6E: goto _1413;

    }
_1456:
    __quex_debug_drop_out(1412);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1413: /* (1413 from 1412) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1413);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1413, 1457);
        case 0x63: goto _1414;

    }
_1457:
    __quex_debug_drop_out(1413);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1414: /* (1414 from 1413) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1414);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1414, 1458);
        case 0x6C: goto _1415;

    }
_1458:
    __quex_debug_drop_out(1414);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1415: /* (1415 from 1414) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1415);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1415, 1459);
        case 0x75: goto _1416;

    }
_1459:
    __quex_debug_drop_out(1415);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1416: /* (1416 from 1415) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1416);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1416, 1460);
        case 0x64: goto _1417;

    }
_1460:
    __quex_debug_drop_out(1416);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1417: /* (1417 from 1416) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1417);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1417, 1461);
        case 0x65: goto _1418;

    }
_1461:
    __quex_debug_drop_out(1417);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1418: /* (1418 from 1417) */

    ++(me->buffer._input_p);
    __quex_debug_state(1418);
    __quex_debug_drop_out(1418);
goto TERMINAL_898;

    __quex_assert_no_passage();
_1419: /* (1419 from 1411) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1419);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1419, 1463);
        case 0x72: goto _1420;

    }
_1463:
    __quex_debug_drop_out(1419);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1420: /* (1420 from 1419) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1420);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1420, 1464);
        case 0x69: goto _1421;

    }
_1464:
    __quex_debug_drop_out(1420);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1421: /* (1421 from 1420) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1421);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1421, 1465);
        case 0x61: goto _1422;

    }
_1465:
    __quex_debug_drop_out(1421);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1422: /* (1422 from 1421) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1422);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1422, 1466);
        case 0x6C: goto _1423;

    }
_1466:
    __quex_debug_drop_out(1422);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1423: /* (1423 from 1422) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1423);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1423, 1467);
        case 0x69: goto _1424;

    }
_1467:
    __quex_debug_drop_out(1423);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1424: /* (1424 from 1423) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1424);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1424, 1468);
        case 0x7A: goto _1425;

    }
_1468:
    __quex_debug_drop_out(1424);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1425: /* (1425 from 1424) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1425);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1425, 1469);
        case 0x65: goto _1426;

    }
_1469:
    __quex_debug_drop_out(1425);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1426: /* (1426 from 1425) */

    ++(me->buffer._input_p);
    __quex_debug_state(1426);
    __quex_debug_drop_out(1426);
goto TERMINAL_897;

    __quex_assert_no_passage();
_1428: /* (1428 from 1381) */

    ++(me->buffer._input_p);
    __quex_debug_state(1428);
    __quex_debug_drop_out(1428);
goto TERMINAL_895;

    __quex_assert_no_passage();
_1431: /* (1431 from 1429) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1431);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1431, 1472);
        case 0xA: goto _1432;

    }
_1472:
    __quex_debug_drop_out(1431);
switch( last_acceptance ) {
    case 896: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_896;
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */

}

    __quex_assert_no_passage();
_1433: /* (1433 from 1430) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1433);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1433, 1473);
        case 0x9: goto _1430;
        case 0xA: goto _1445;
        case 0xD: goto _1435;
        case 0x20: goto _1430;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1429;
        case 0x5C: goto _1430;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1429;

    }
_1473:
    __quex_debug_drop_out(1433);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1040; /* TERMINAL_FAILURE */
    case 896: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_896;

}

    __quex_assert_no_passage();
_1387: /* (1387 from 1387) (1387 from 1379) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1387);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1387, 1474);
        case 0x2C: 
        case 0x2E: goto _1400;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1387;
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1474:
    __quex_debug_drop_out(1387);
goto TERMINAL_902;

    __quex_assert_no_passage();
_1401: /* (1401 from 1394) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1401);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1401, 1475);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: goto _1398;
        case 0x68: goto _1402;
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1475:
    __quex_debug_drop_out(1401);
goto TERMINAL_907;

    __quex_assert_no_passage();
_1402: /* (1402 from 1401) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1402);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1402, 1476);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: goto _1398;
        case 0x6F: goto _1403;
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1476:
    __quex_debug_drop_out(1402);
goto TERMINAL_907;

    __quex_assert_no_passage();
_1403: /* (1403 from 1402) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1403);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1403, 1477);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1477:
    __quex_debug_drop_out(1403);
goto TERMINAL_900;

    __quex_assert_no_passage();
_1404: /* (1404 from 1392) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1404);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1404, 1478);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: goto _1398;
        case 0x6E: goto _1405;
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1478:
    __quex_debug_drop_out(1404);
goto TERMINAL_907;

    __quex_assert_no_passage();
_1405: /* (1405 from 1404) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1405);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1405, 1479);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: goto _1398;
        case 0x63: goto _1406;
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1479:
    __quex_debug_drop_out(1405);
goto TERMINAL_907;

    __quex_assert_no_passage();
_1406: /* (1406 from 1405) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1406);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1406, 1480);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: goto _1398;
        case 0x74: goto _1407;
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1480:
    __quex_debug_drop_out(1406);
goto TERMINAL_907;

    __quex_assert_no_passage();
_1407: /* (1407 from 1406) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1407);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1407, 1481);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: goto _1398;
        case 0x69: goto _1408;
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1481:
    __quex_debug_drop_out(1407);
goto TERMINAL_907;

    __quex_assert_no_passage();
_1380: /* (1380 from 1379) */

    ++(me->buffer._input_p);
    __quex_debug_state(1380);
    __quex_debug_drop_out(1380);
goto TERMINAL_894;

    __quex_assert_no_passage();
_1381: /* (1381 from 1379) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1381);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1381, 1483);
        case 0x2A: goto _1428;
        case 0x2F: goto _1429;

    }
_1483:
    __quex_debug_drop_out(1381);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1382: /* (1382 from 1379) */

    ++(me->buffer._input_p);
    __quex_debug_state(1382);
    __quex_debug_drop_out(1382);
goto TERMINAL_908;

    __quex_assert_no_passage();
_1383: /* (1383 from 1379) */

    ++(me->buffer._input_p);
    __quex_debug_state(1383);
    __quex_debug_drop_out(1383);
goto TERMINAL_892;

    __quex_assert_no_passage();
_1384: /* (1384 from 1379) */

    ++(me->buffer._input_p);
    __quex_debug_state(1384);
    __quex_debug_drop_out(1384);
goto TERMINAL_911;

    __quex_assert_no_passage();
_1385: /* (1385 from 1379) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1385);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1385, 1487);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1427;

    }
_1487:
    __quex_debug_drop_out(1385);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1386: /* (1386 from 1379) */

    ++(me->buffer._input_p);
    __quex_debug_state(1386);
    __quex_debug_drop_out(1386);
goto TERMINAL_906;

    __quex_assert_no_passage();
_1388: /* (1388 from 1379) */

    ++(me->buffer._input_p);
    __quex_debug_state(1388);
    __quex_debug_drop_out(1388);
goto TERMINAL_909;

    __quex_assert_no_passage();
_1389: /* (1389 from 1379) */

    ++(me->buffer._input_p);
    __quex_debug_state(1389);
    __quex_debug_drop_out(1389);
goto TERMINAL_905;

    __quex_assert_no_passage();
_1390: /* (1390 from 1379) */

    ++(me->buffer._input_p);
    __quex_debug_state(1390);
    __quex_debug_drop_out(1390);
goto TERMINAL_910;

    __quex_assert_no_passage();
_1392: /* (1392 from 1379) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1392);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1392, 1492);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: goto _1398;
        case 0x75: goto _1404;
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1492:
    __quex_debug_drop_out(1392);
goto TERMINAL_907;

    __quex_assert_no_passage();
_1393: /* (1393 from 1379) */

    ++(me->buffer._input_p);
    __quex_debug_state(1393);
    __quex_debug_drop_out(1393);
goto TERMINAL_903;

    __quex_assert_no_passage();
_1394: /* (1394 from 1379) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1394);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1394, 1494);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: goto _1398;
        case 0x63: goto _1401;
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1398;

    }
_1494:
    __quex_debug_drop_out(1394);
goto TERMINAL_907;

    __quex_assert_no_passage();
_1395: /* (1395 from 1379) */

    ++(me->buffer._input_p);
    __quex_debug_state(1395);
    __quex_debug_drop_out(1395);
goto TERMINAL_893;

    __quex_assert_no_passage();
_1396: /* (1396 from 1379) */

    ++(me->buffer._input_p);
    __quex_debug_state(1396);
    __quex_debug_drop_out(1396);
goto TERMINAL_904;

    __quex_assert_no_passage();
_1397: /* (1397 from 1379) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1397);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1397, 1497);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1399;

    }
_1497:
    __quex_debug_drop_out(1397);

goto _1040; /* TERMINAL_FAILURE */
    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */

    /* Lexeme setup: 
     *
     * There is a temporary zero stored at the end of each lexeme, if the action 
     * references to the 'Lexeme'. 'LexemeNull' provides a reference to an empty
     * zero terminated string.                                                    */
#if defined(QUEX_OPTION_ASSERTS)
#   define Lexeme       QUEX_NAME(access_Lexeme)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeBegin  QUEX_NAME(access_LexemeBegin)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeL      QUEX_NAME(access_LexemeL)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeEnd    QUEX_NAME(access_LexemeEnd)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#else
#   define Lexeme       (me->buffer._lexeme_start_p)
#   define LexemeBegin  Lexeme
#   define LexemeL      ((size_t)(me->buffer._input_p - me->buffer._lexeme_start_p))
#   define LexemeEnd    me->buffer._input_p
#endif

#define LexemeNull      (&QUEX_LEXEME_NULL)

TERMINAL_892:
    __quex_debug("* terminal 892:   <skip: ... (check also base modes)>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 245 "lexical_analyzer.qx"
    goto __SKIP;
    
#   line 5223 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_893:
    __quex_debug("* terminal 893:   <skip: ... (check also base modes)>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4);

    {
#   line 245 "lexical_analyzer.qx"
    goto __SKIP;
    
#   line 5238 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_894:
    __quex_debug("* terminal 894:   <skip>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_LINES_ADD(1);
__QUEX_IF_COUNT_COLUMNS_SET(1);
    {
__SKIP:
    /* Character Set Skipper: '['\t', '\n'], '\r', ' '' */
    QUEX_BUFFER_ASSERT_CONSISTENCY(&me->buffer);
__QUEX_IF_COUNT_COLUMNS(reference_p = me->buffer._input_p);
    while( 1 + 1 == 2 ) {
_1210:
        if( (*me->buffer._input_p) < 0xB ) {
            switch( (*me->buffer._input_p) ) {
                case 0x0: QUEX_GOTO_RELOAD(_1211, 1210, 955);
                case 0x1:
                case 0x2:
                case 0x3:
                case 0x4:
                case 0x5:
                case 0x6:
                case 0x7:
                case 0x8: __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
                case 0x9:             __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
            __QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
            __QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4);
            __QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p) + 1);
                    ++((me->buffer._input_p));
                continue;
                case 0xA: __QUEX_IF_COUNT_LINES_ADD((size_t)1);
            __QUEX_IF_COUNT_COLUMNS_SET((size_t)1);
            __QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p) + 1);
                    ++((me->buffer._input_p));
                continue;

            }
        } else {
            if( (*me->buffer._input_p) < 0xD ) {
                __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
            } else if( (*me->buffer._input_p) == 0xD ) {
                        ++((me->buffer._input_p));
                continue;
            } else if( (*me->buffer._input_p) < 0x20 ) {
                __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
            } else if( (*me->buffer._input_p) == 0x20 ) {
                        ++((me->buffer._input_p));
                continue;
            } else {
                __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
            }
        }

    __quex_assert_no_passage();
_1211:

    __quex_debug1("__RELOAD_FORWARD");
    __quex_assert(*((me->buffer._input_p)) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
me->buffer._lexeme_start_p = (me->buffer._input_p);

        __quex_debug_reload_before(); /* Leave macro here to report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);
        ++((me->buffer._input_p));
__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);
    }

    }
    goto __REENTRY_PREPARATION;

TERMINAL_895:
    __quex_debug("* terminal 895:   {D_COMMENT_STREAM_BEGINNING}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
    Skipper1212_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1212_Opener;
    Skipper1212_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1212_Closer;
    /* text_end                           = QUEX_NAME(Buffer_text_end)(&me->buffer); */
    __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));


_1212:

    QUEX_BUFFER_ASSERT_CONSISTENCY(&me->buffer);
    __quex_assert(QUEX_NAME(Buffer_content_size)(&me->buffer) >= 2 );

    /* NOTE: If _input_p == end of buffer, then it will drop out immediately out of the
        *       loop below and drop into the buffer reload procedure.                      */

    /* Loop eating characters: Break-out as soon as the First Character of the Delimiter
        * (FCD) is reached. Thus, the FCD plays also the role of the Buffer Limit Code. There
        * are two reasons for break-out:
        *    (1) we reached a limit (end-of-file or buffer-limit)
        *    (2) there was really the FCD in the character stream
        * This must be distinguished after the loop was exited. But, during the 'swallowing'
        * we are very fast, because we do not have to check for two different characters.  */
    while( 1 + 1 == 2 ) {
            input = *(me->buffer._input_p);

            if( input == QUEX_SETTING_BUFFER_LIMIT_CODE ) {
                    goto _1213;
            }
            if( input == *Skipper1212_Closer_it ) {
                    ++Skipper1212_Closer_it;
                    if( Skipper1212_Closer_it == Skipper1212_CloserEnd ) {
                        if( counter == 0 ) {
                            /* NOTE: The initial state does not increment the input_p. When it detects that
                                * it is located on a buffer border, it automatically triggers a reload. No
                                * need here to reload the buffer. */
                            ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
                                    __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer)
                                            - reference_p));

                            /* No need for re-entry preparation. Acceptance flags and modes are untouched after skipping. */
                            goto __REENTRY; /* End of range reached. */
                        }
                        --counter;
                        Skipper1212_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1212_Opener;
                        Skipper1212_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1212_Closer;
                        goto CONTINUE_1212;
                    }
            } else {
                    Skipper1212_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1212_Closer;
            }
            if( input == *Skipper1212_Opener_it ) {
                    ++Skipper1212_Opener_it;
                    if( Skipper1212_Opener_it == Skipper1212_OpenerEnd ) {
                        ++counter;
                        Skipper1212_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1212_Opener;
                        Skipper1212_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1212_Closer;
                        goto CONTINUE_1212;
                    }
            } else {
                    Skipper1212_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1212_Opener;
            }
CONTINUE_1212:

    __QUEX_IF_COUNT_IF( input == (QUEX_TYPE_CHARACTER)'\n' ) {
            __QUEX_IF_COUNT_LINES_ADD((size_t)1);
            __QUEX_IF_COUNT_COLUMNS_SET((size_t)0);
            __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));
    }

            ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
    }

_1213:
    QUEX_BUFFER_ASSERT_CONSISTENCY_LIGHT(&me->buffer);
    /* -- When loading new content it is checked that the beginning of the lexeme
        *    is not 'shifted' out of the buffer. In the case of skipping, we do not care about
        *    the lexeme at all, so do not restrict the load procedure and set the lexeme start
        *    to the actual input position.                                                    */
    me->buffer._lexeme_start_p = me->buffer._input_p;

    __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer)
                                        - reference_p));

    if( QUEX_NAME(Buffer_is_end_of_file)(&me->buffer) == false ) {
            QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position,
                                                PositionRegisterN);
            /* Recover '_input_p' from lexeme start
                * (inverse of what we just did before the loading) */
            me->buffer._input_p = me->buffer._lexeme_start_p;
            /* After reload, we need to increment _input_p. That's how the game is supposed to be played.
                * But, we recovered from lexeme start pointer, and this one does not need to be incremented. */
            /* text_end = QUEX_NAME(Buffer_text_end)(&me->buffer); */
            __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));

            QUEX_BUFFER_ASSERT_CONSISTENCY(&me->buffer);
            goto _1212; /* End of range reached.             */
    }
    /* Here, either the loading failed or it is not enough space to carry a closing delimiter */
    me->buffer._input_p = me->buffer._lexeme_start_p;
    QUEX_ERROR_EXIT("\nLexical analyzer mode 'SCOPE':\n"
                        "End of file occurred before closing skip range delimiter!\n"                "The 'on_skip_range_open' handler has not been specified.");

    }
    goto __REENTRY_PREPARATION;

TERMINAL_896:
    __quex_debug("* terminal 896:   {D_COMMENT_BLOCK}([inverse({D_NEW_LINE})]|({D_BACKSLASH}{D_WHITESPACE}*{D_NEW_LINE}))*{D_NEW_LINE}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 252 "lexical_analyzer.qx"
    
        // We are within a comment. Do not do anything.
    
    
#   line 5441 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_897:
    __quex_debug("* terminal 897:   {D_PRAGMA}{D_WHITESPACE}*\"serialize\"\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 261 "lexical_analyzer.qx"
    self_send(QUEX_TKN_SERIALIZE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5454 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_898:
    __quex_debug("* terminal 898:   {D_PRAGMA}{D_WHITESPACE}*\"include\"\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 262 "lexical_analyzer.qx"
    self_send(QUEX_TKN_INCLUDE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5467 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_899:
    __quex_debug("* terminal 899:   \\${D_IDENTIFIER}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
    {
#   line 263 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_IDENTIFIER_VARIABLE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5482 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_900:
    __quex_debug("* terminal 900:   {D_OUTPUT}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(4);
    {
#   line 264 "lexical_analyzer.qx"
    QUEX_NAME(push_mode)(&self, &EXPRESSION);self_send(QUEX_TKN_OUTPUT);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5496 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_901:
    __quex_debug("* terminal 901:   \"function\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(8);
    {
#   line 265 "lexical_analyzer.qx"
    QUEX_NAME(push_mode)(&self, &FUNCTION_DEFINITION);self_send(QUEX_TKN_FUNCTION_DEFINITION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5510 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_902:
    __quex_debug("* terminal 902:   {D_NUMBER}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
    {
#   line 266 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_NUMBER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5525 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_903:
    __quex_debug("* terminal 903:   {D_QUOTE_SINGLE}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 268 "lexical_analyzer.qx"
    QUEX_NAME(push_mode)(&self, &STRING_ABSOLUTE);self_send(QUEX_TKN_STRING_ABSOLUTE_BEGINNING);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5539 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_904:
    __quex_debug("* terminal 904:   {D_QUOTE_DOUBLE}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 269 "lexical_analyzer.qx"
    QUEX_NAME(push_mode)(&self, &STRING_RELATIVE);self_send(QUEX_TKN_STRING_RELATIVE_BEGINNING);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5553 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_905:
    __quex_debug("* terminal 905:   {D_STATEMENT_END}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 272 "lexical_analyzer.qx"
    self_send(QUEX_TKN_STATEMENT_END);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5567 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_906:
    __quex_debug("* terminal 906:   {D_CONCATENATION}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 273 "lexical_analyzer.qx"
    self_send(QUEX_TKN_CONCATENATION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5581 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_907:
    __quex_debug("* terminal 907:   {D_IDENTIFIER}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
    {
#   line 275 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_IDENTIFIER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5596 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_908:
    __quex_debug("* terminal 908:   \"{\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 279 "lexical_analyzer.qx"
    QUEX_NAME(push_mode)(&self, &SCOPE);self_send(QUEX_TKN_BRACE_BEGINNING);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5610 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_909:
    __quex_debug("* terminal 909:   \"}\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 280 "lexical_analyzer.qx"
    QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_BRACE_END);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5624 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_910:
    __quex_debug("* terminal 910:   \"(\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 283 "lexical_analyzer.qx"
    QUEX_NAME(push_mode)(&self, &EXPRESSION);self_send(QUEX_TKN_PARENTHESIS_BEGINNING);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5638 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_911:
    __quex_debug("* terminal 911:   \"=\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 285 "lexical_analyzer.qx"
    QUEX_NAME(push_mode)(&self, &EXPRESSION);self_send(QUEX_TKN_ASSIGNMENT);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 5652 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;


_1040: /* TERMINAL: FAILURE */
    if(QUEX_NAME(Buffer_is_end_of_file)(&me->buffer)) {
        /* Init state is going to detect 'input == buffer limit code', and
         * enter the reload procedure, which will decide about 'end of stream'. */
    } else {
        /* In init state 'input = *input_p' and we need to increment
         * in order to avoid getting stalled. Else, input = *(input_p - 1),
         * so 'input_p' points already to the next character.                   */
        if( me->buffer._input_p == me->buffer._lexeme_start_p ) {
            /* Step over non-matching character */
            ++(me->buffer._input_p);
        }
    }
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 237 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_FAILURE);
    
        RETURN;
    
    
#   line 5680 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION_2;


/* TERMINAL: END_OF_STREAM */
_955:
__QUEX_IF_COUNT_SHIFT_VALUES();
    {
#   line 230 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_TERMINATION);
    
        RETURN;
    
    
#   line 5697 "lexical_analyzer.cpp"

    }
    /* End of Stream causes a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.                    */
    RETURN;

__REENTRY_PREPARATION:
    /* (*) Common point for **restarting** lexical analysis.
     *     at each time when CONTINUE is called at the end of a pattern.     */
 

    /* FAILURE needs not to run through 'on_after_match'. It enters here.    */
__REENTRY_PREPARATION_2:

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL

#   ifndef __QUEX_OPTION_PLAIN_ANALYZER_OBJECT
#   ifdef  QUEX_OPTION_TOKEN_POLICY_QUEUE
    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) {
        return;
    }
#   else
    if( self_token_get_id() != __QUEX_SETTING_TOKEN_ID_UNINITIALIZED) {
        return __self_result_token_id;
    }
#   endif
#   endif


    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */

    /*  If a mode change happened, then the function must first return and
     *  indicate that another mode function is to be called. At this point, 
     *  we to force a 'return' on a mode change. 
     *
     *  Pseudo Code: if( previous_mode != current_mode ) {
     *                   return 0;
     *               }
     *
     *  When the analyzer returns, the caller function has to watch if a mode 
     *  change occurred. If not it can call this function again.             */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)        || defined(QUEX_OPTION_ASSERTS)
    if( me->DEBUG_analyzer_function_at_entry != me->current_analyzer_function ) 
#   endif
    { 
#       if defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)
        self_token_set_id(__QUEX_SETTING_TOKEN_ID_UNINITIALIZED);
        __QUEX_PURE_RETURN;
#       elif defined(QUEX_OPTION_ASSERTS)
        QUEX_ERROR_EXIT("Mode change without immediate return from the lexical analyzer.");
#       endif
    }

    goto __REENTRY;

    __quex_assert_no_passage();
__RELOAD_FORWARD:

    __quex_debug1("__RELOAD_FORWARD");
    __quex_assert(*(me->buffer._input_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {

        __quex_debug_reload_before(); /* Leave macro here to report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
__STATE_ROUTER:
    switch( target_state_index ) {
        case 955: { goto _955; }
        case 1210: { goto _1210; }
        case 1211: { goto _1211; }
        case 1212: { goto _1212; }
        case 1379: { goto _1379; }
        case 1380: { goto _1380; }
        case 1381: { goto _1381; }
        case 1382: { goto _1382; }
        case 1383: { goto _1383; }
        case 1384: { goto _1384; }
        case 1385: { goto _1385; }
        case 1386: { goto _1386; }
        case 1387: { goto _1387; }
        case 1388: { goto _1388; }
        case 1389: { goto _1389; }
        case 1390: { goto _1390; }
        case 1391: { goto _1391; }
        case 1392: { goto _1392; }
        case 1393: { goto _1393; }
        case 1394: { goto _1394; }
        case 1395: { goto _1395; }
        case 1396: { goto _1396; }
        case 1397: { goto _1397; }
        case 1398: { goto _1398; }
        case 1399: { goto _1399; }
        case 1400: { goto _1400; }
        case 1401: { goto _1401; }
        case 1402: { goto _1402; }
        case 1403: { goto _1403; }
        case 1404: { goto _1404; }
        case 1405: { goto _1405; }
        case 1406: { goto _1406; }
        case 1407: { goto _1407; }
        case 1408: { goto _1408; }
        case 1409: { goto _1409; }
        case 1410: { goto _1410; }
        case 1411: { goto _1411; }
        case 1412: { goto _1412; }
        case 1413: { goto _1413; }
        case 1414: { goto _1414; }
        case 1415: { goto _1415; }
        case 1416: { goto _1416; }
        case 1417: { goto _1417; }
        case 1418: { goto _1418; }
        case 1419: { goto _1419; }
        case 1420: { goto _1420; }
        case 1421: { goto _1421; }
        case 1422: { goto _1422; }
        case 1423: { goto _1423; }
        case 1424: { goto _1424; }
        case 1425: { goto _1425; }
        case 1426: { goto _1426; }
        case 1427: { goto _1427; }
        case 1428: { goto _1428; }
        case 1429: { goto _1429; }
        case 1430: { goto _1430; }
        case 1431: { goto _1431; }
        case 1432: { goto _1432; }
        case 1433: { goto _1433; }
        case 1434: { goto _1434; }
        case 1435: { goto _1435; }
        case 1438: { goto _1438; }
        case 1439: { goto _1439; }
        case 1440: { goto _1440; }
        case 1441: { goto _1441; }
        case 1442: { goto _1442; }
        case 1443: { goto _1443; }
        case 1444: { goto _1444; }
        case 1445: { goto _1445; }
        case 1446: { goto _1446; }
        case 1447: { goto _1447; }
        case 1448: { goto _1448; }
        case 1450: { goto _1450; }
        case 1451: { goto _1451; }
        case 1452: { goto _1452; }
        case 1453: { goto _1453; }
        case 1454: { goto _1454; }
        case 1455: { goto _1455; }
        case 1456: { goto _1456; }
        case 1457: { goto _1457; }
        case 1458: { goto _1458; }
        case 1459: { goto _1459; }
        case 1460: { goto _1460; }
        case 1461: { goto _1461; }
        case 1463: { goto _1463; }
        case 1464: { goto _1464; }
        case 1465: { goto _1465; }
        case 1466: { goto _1466; }
        case 1467: { goto _1467; }
        case 1468: { goto _1468; }
        case 1469: { goto _1469; }
        case 1472: { goto _1472; }
        case 1473: { goto _1473; }
        case 1474: { goto _1474; }
        case 1475: { goto _1475; }
        case 1476: { goto _1476; }
        case 1477: { goto _1477; }
        case 1478: { goto _1478; }
        case 1479: { goto _1479; }
        case 1480: { goto _1480; }
        case 1481: { goto _1481; }
        case 1483: { goto _1483; }
        case 1487: { goto _1487; }
        case 1492: { goto _1492; }
        case 1494: { goto _1494; }
        case 1497: { goto _1497; }

        default:
            __QUEX_STD_fprintf(stderr, "State router: index = %i\n", (int)target_state_index);
            QUEX_ERROR_EXIT("State router: unknown index.\n");
    }
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */

    /* Prevent compiler warning 'unused variable': use variables once in a part of the code*/
    /* that is never reached (and deleted by the compiler anyway).*/
    (void)QUEX_LEXEME_NULL;
    (void)QUEX_NAME_TOKEN(DumpedTokenIdObject);
    QUEX_ERROR_EXIT("Unreachable code has been reached.\n");
#   undef FUNCTION_DEFINITION
#   undef STRING_RELATIVE
#   undef FUNCTION_DEFINITION_PARAMETERS
#   undef STRING_ABSOLUTE
#   undef SCOPE
#   undef EXPRESSION
#   undef self
}
#include <quex/code_base/temporary_macros_off>
#ifdef      __QUEX_COUNT_VOID
#   undef   __QUEX_COUNT_VOID
#endif
#ifdef      __QUEX_OPTION_COUNTER
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) \
            do {                              \
                QUEX_NAME(FUNCTION_DEFINITION_counter)((ME), (BEGIN), (END));     \
                __quex_debug_counter();       \
            } while(0)
#else
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) /* empty */
#endif

#include <quex/code_base/analyzer/member/basic>
#include <quex/code_base/buffer/Buffer>
#ifdef QUEX_OPTION_TOKEN_POLICY_QUEUE
#   include <quex/code_base/token/TokenQueue>
#endif

#ifdef    CONTINUE
#   undef CONTINUE
#endif
#define   CONTINUE goto __REENTRY_PREPARATION; 

#ifdef    RETURN
#   undef RETURN
#endif

#define RETURN    __QUEX_PURE_RETURN;
#include <quex/code_base/temporary_macros_on>

__QUEX_TYPE_ANALYZER_RETURN_VALUE  
QUEX_NAME(EXPRESSION_analyzer_function)(QUEX_TYPE_ANALYZER* me) 
{
    /* NOTE: Different modes correspond to different analyzer functions. The 
     *       analyzer functions are all located inside the main class as static
     *       functions. That means, they are something like 'globals'. They 
     *       receive a pointer to the lexical analyzer, since static members do
     *       not have access to the 'this' pointer.                          */
#   if defined(QUEX_OPTION_TOKEN_POLICY_SINGLE)
    register QUEX_TYPE_TOKEN_ID __self_result_token_id 
           = (QUEX_TYPE_TOKEN_ID)__QUEX_SETTING_TOKEN_ID_UNINITIALIZED;
#   endif
#   ifdef     self
#       undef self
#   endif
#   define self (*((QUEX_TYPE_ANALYZER*)me))
    const QUEX_TYPE_CHARACTER      Skipper1500_Closer[2]          = { 0x2A, 0x2F,  };
    const QUEX_TYPE_CHARACTER      Skipper1500_Opener[2]          = { 0x2F, 0x2A,  };
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
    const QUEX_TYPE_CHARACTER*     Skipper1500_OpenerEnd          = Skipper1500_Opener + (ptrdiff_t)2;
    size_t                         counter                        = 0;
    QUEX_TYPE_CHARACTER_POSITION   reference_p                    = (QUEX_TYPE_CHARACTER_POSITION)0x0;
    QUEX_TYPE_ACCEPTANCE_ID        last_acceptance               /* un-initilized */;
    const QUEX_TYPE_CHARACTER*     Skipper1500_Opener_it          = 0x0;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    const size_t                   PositionRegisterN              = (size_t)2;
    QUEX_TYPE_CHARACTER_POSITION   position[2]                    = { 0, 0};
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    const QUEX_TYPE_CHARACTER*     Skipper1500_CloserEnd          = Skipper1500_Closer + (ptrdiff_t)2;
    const QUEX_TYPE_CHARACTER*     Skipper1500_Closer_it          = 0x0;
#   ifdef QUEX_OPTION_COLUMN_NUMBER_COUNTING
#   endif /* QUEX_OPTION_COLUMN_NUMBER_COUNTING */
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */
#   define FUNCTION_DEFINITION               (QUEX_NAME(FUNCTION_DEFINITION))
#   define STRING_RELATIVE                   (QUEX_NAME(STRING_RELATIVE))
#   define FUNCTION_DEFINITION_PARAMETERS    (QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS))
#   define STRING_ABSOLUTE                   (QUEX_NAME(STRING_ABSOLUTE))
#   define SCOPE                             (QUEX_NAME(SCOPE))
#   define EXPRESSION                        (QUEX_NAME(EXPRESSION))

    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE) \
       || defined(QUEX_OPTION_ASSERTS)
    me->DEBUG_analyzer_function_at_entry = me->current_analyzer_function;
#   endif
__REENTRY:
    me->buffer._lexeme_start_p = me->buffer._input_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);
_1770: /* INIT_STATE_TRANSITION_BLOCK */
    input = *(me->buffer._input_p);
    __quex_debug("Init State\n");
    __quex_debug_state(1714);
    if( input < 0x2E ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1714, 955);
            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: goto _1739;
            case 0x9: goto _1732;
            case 0xA: goto _1737;
            case 0xB: 
            case 0xC: goto _1739;
            case 0xD: goto _1730;
            case 0xE: 
            case 0xF: 
            case 0x10: 
            case 0x11: 
            case 0x12: 
            case 0x13: 
            case 0x14: 
            case 0x15: 
            case 0x16: 
            case 0x17: 
            case 0x18: 
            case 0x19: 
            case 0x1A: 
            case 0x1B: 
            case 0x1C: 
            case 0x1D: 
            case 0x1E: 
            case 0x1F: goto _1739;
            case 0x20: goto _1730;
            case 0x21: goto _1741;
            case 0x22: goto _1733;
            case 0x23: goto _1739;
            case 0x24: goto _1735;
            case 0x25: goto _1722;
            case 0x26: goto _1724;
            case 0x27: goto _1719;
            case 0x28: goto _1720;
            case 0x29: goto _1725;
            case 0x2A: goto _1726;
            case 0x2B: goto _1715;
            case 0x2C: goto _1739;
            case 0x2D: goto _1734;

        }
    } else {
        if( input < 0x5E ) {
            switch( input ) {
                case 0x2E: goto _1721;
                case 0x2F: goto _1771;
                case 0x30: 
                case 0x31: 
                case 0x32: 
                case 0x33: 
                case 0x34: 
                case 0x35: 
                case 0x36: 
                case 0x37: 
                case 0x38: 
                case 0x39: goto _1716;
                case 0x3A: goto _1739;
                case 0x3B: goto _1718;
                case 0x3C: goto _1717;
                case 0x3D: goto _1727;
                case 0x3E: goto _1738;
                case 0x3F: 
                case 0x40: goto _1739;
                case 0x41: 
                case 0x42: 
                case 0x43: 
                case 0x44: 
                case 0x45: 
                case 0x46: 
                case 0x47: 
                case 0x48: 
                case 0x49: 
                case 0x4A: 
                case 0x4B: 
                case 0x4C: 
                case 0x4D: 
                case 0x4E: 
                case 0x4F: 
                case 0x50: 
                case 0x51: 
                case 0x52: 
                case 0x53: 
                case 0x54: 
                case 0x55: 
                case 0x56: 
                case 0x57: 
                case 0x58: 
                case 0x59: 
                case 0x5A: goto _1736;
                case 0x5B: 
                case 0x5C: 
                case 0x5D: goto _1739;

            }
        } else {
            if( input < 0x66 ) {
                switch( input ) {
                    case 0x5E: goto _1723;
                    case 0x5F: goto _1736;
                    case 0x60: goto _1739;
                    case 0x61: 
                    case 0x62: 
                    case 0x63: 
                    case 0x64: goto _1736;
                    case 0x65: goto _1729;

                }
            } else {
                if( input < 0x7B ) {
                    switch( input ) {
                        case 0x66: 
                        case 0x67: 
                        case 0x68: 
                        case 0x69: 
                        case 0x6A: 
                        case 0x6B: 
                        case 0x6C: 
                        case 0x6D: 
                        case 0x6E: 
                        case 0x6F: 
                        case 0x70: 
                        case 0x71: 
                        case 0x72: 
                        case 0x73: goto _1736;
                        case 0x74: goto _1728;
                        case 0x75: 
                        case 0x76: 
                        case 0x77: 
                        case 0x78: 
                        case 0x79: 
                        case 0x7A: goto _1736;

                    }
                } else {
                    if( input == 0x7B ) {
                        goto _1739;
                    } else if( input == 0x7C ) {
                        goto _1731;
                    } else {
                        goto _1739;
                    }
                }
            }
        }
    }
    __quex_debug_drop_out(1714);

goto _1040; /* TERMINAL_FAILURE */

_1714:


    ++(me->buffer._input_p);
    goto _1770;


    __quex_assert_no_passage();
_1755: /* (1755 from 1755) (1755 from 1716) (1755 from 1760) (1755 from 1729) (1755 from 1769) (1755 from 1763) (1755 from 1764) (1755 from 1736) (1755 from 1728) (1755 from 1761) (1755 from 1762) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1755);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1755, 1773);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1755;

    }
_1773:
    __quex_debug_drop_out(1755);
goto TERMINAL_950;

    __quex_assert_no_passage();
_1774: /* (1747 from 1740) */
    position[1] = me->buffer._input_p; __quex_debug("position[1] = input_p;\n");
    goto _1747;
_1775: /* (1747 from 1752) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1747: /* (1747 from 1747) (1747 from 1751) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1747);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1747, 1776);
        case 0xA: goto _1748;
        case 0xD: goto _1750;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1747;
        case 0x5C: goto _1749;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1747;

    }
_1776:
    __quex_debug_drop_out(1747);
switch( last_acceptance ) {
    case 922: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_922;
    case 926: __quex_assert(position[1] != 0x0);
me->buffer._input_p = position[1];
 goto TERMINAL_926;

}

    __quex_assert_no_passage();
_1743: /* (1743 from 1727) (1743 from 1728) (1743 from 1729) (1743 from 1730) (1743 from 1731) (1743 from 1732) (1743 from 1733) (1743 from 1734) (1743 from 1735) (1743 from 1736) (1743 from 1737) (1743 from 1738) (1743 from 1739) (1743 from 1741) (1743 from 1715) (1743 from 1716) (1743 from 1717) (1743 from 1718) (1743 from 1719) (1743 from 1720) (1743 from 1721) (1743 from 1722) (1743 from 1723) (1743 from 1724) (1743 from 1725) (1743 from 1726) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1743);
    if( input >= 0x30 ) {
        goto _1744;
    } else if( input == 0x2F ) {

    } else if( input >= 0x2 ) {
        goto _1744;
    } else if( input == 0x1 ) {

    } else {
        QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1743, 1777);
    }
_1777:
    __quex_debug_drop_out(1743);
goto TERMINAL_926;

    __quex_assert_no_passage();
_1778: /* (1749 from 1752) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1749: /* (1749 from 1749) (1749 from 1747) (1749 from 1753) (1749 from 1751) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1749);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1749, 1779);
        case 0x9: goto _1749;
        case 0xA: goto _1751;
        case 0xD: 
        case 0x20: goto _1749;

    }
_1779:
    __quex_debug_drop_out(1749);
switch( last_acceptance ) {
    case 922: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_922;
    case 926: __quex_assert(position[1] != 0x0);
me->buffer._input_p = position[1];
 goto TERMINAL_926;

}

    __quex_assert_no_passage();
_1756: /* (1756 from 1756) (1756 from 1735) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1756);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1756, 1780);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1756;

    }
_1780:
    __quex_debug_drop_out(1756);
goto TERMINAL_943;

    __quex_assert_no_passage();
_1744: /* (1744 from 1743) (1744 from 1740) */

    ++(me->buffer._input_p);
    __quex_debug_state(1744);
    __quex_debug_drop_out(1744);
goto TERMINAL_926;

    __quex_assert_no_passage();
_1758: /* (1758 from 1758) (1758 from 1757) (1758 from 1716) (1758 from 1769) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1758);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1758, 1782);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1758;

    }
_1782:
    __quex_debug_drop_out(1758);
goto TERMINAL_944;

    __quex_assert_no_passage();
_1783: /* (1752 from 1752) (1752 from 1751) (1752 from 1753) */
    { last_acceptance = 922; __quex_debug("last_acceptance = 922\n"); }

_1752:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1752);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1752, 1784);
        case 0x9: goto _1778;
        case 0xA: goto _1783;
        case 0xD: goto _1785;
        case 0x20: goto _1778;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1775;
        case 0x5C: goto _1778;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1775;

    }
_1784:
    __quex_debug_drop_out(1752);
goto TERMINAL_922;

    __quex_assert_no_passage();
_1757: /* (1757 from 1757) (1757 from 1734) (1757 from 1715) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1757);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1757, 1786);
        case 0x2C: 
        case 0x2E: goto _1758;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1757;

    }
_1786:
    __quex_debug_drop_out(1757);
goto TERMINAL_944;

    __quex_assert_no_passage();
_1748: /* (1748 from 1747) (1748 from 1750) */

    ++(me->buffer._input_p);
    __quex_debug_state(1748);
    __quex_debug_drop_out(1748);
goto TERMINAL_922;

    __quex_assert_no_passage();
_1785: /* (1753 from 1752) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1753: /* (1753 from 1751) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1753);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1753, 1788);
        case 0x9: goto _1749;
        case 0xA: goto _1783;
        case 0xD: 
        case 0x20: goto _1749;

    }
_1788:
    __quex_debug_drop_out(1753);
switch( last_acceptance ) {
    case 922: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_922;
    case 926: __quex_assert(position[1] != 0x0);
me->buffer._input_p = position[1];
 goto TERMINAL_926;

}

    __quex_assert_no_passage();
_1769: /* (1769 from 1769) (1769 from 1716) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1769);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1769, 1789);
        case 0x2C: 
        case 0x2E: goto _1758;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1769;
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1755;

    }
_1789:
    __quex_debug_drop_out(1769);
goto TERMINAL_944;

    __quex_assert_no_passage();
_1742: /* (1742 from 1741) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1742);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1742, 1790);
        case 0x3D: goto _1745;

    }
_1790:
    __quex_debug_drop_out(1742);
goto TERMINAL_934;

    __quex_assert_no_passage();
_1745: /* (1745 from 1742) */

    ++(me->buffer._input_p);
    __quex_debug_state(1745);
    __quex_debug_drop_out(1745);
goto TERMINAL_932;

    __quex_assert_no_passage();
_1746: /* (1746 from 1740) */

    ++(me->buffer._input_p);
    __quex_debug_state(1746);
    __quex_debug_drop_out(1746);
goto TERMINAL_921;

    __quex_assert_no_passage();
_1750: /* (1750 from 1747) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1750);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1750, 1793);
        case 0xA: goto _1748;

    }
_1793:
    __quex_debug_drop_out(1750);
switch( last_acceptance ) {
    case 922: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_922;
    case 926: __quex_assert(position[1] != 0x0);
me->buffer._input_p = position[1];
 goto TERMINAL_926;

}

    __quex_assert_no_passage();
_1751: /* (1751 from 1749) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1751);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1751, 1794);
        case 0x9: goto _1749;
        case 0xA: goto _1783;
        case 0xD: goto _1753;
        case 0x20: goto _1749;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1747;
        case 0x5C: goto _1749;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1747;

    }
_1794:
    __quex_debug_drop_out(1751);
switch( last_acceptance ) {
    case 922: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_922;
    case 926: __quex_assert(position[1] != 0x0);
me->buffer._input_p = position[1];
 goto TERMINAL_926;

}

    __quex_assert_no_passage();
_1754: /* (1754 from 1738) */

    ++(me->buffer._input_p);
    __quex_debug_state(1754);
    __quex_debug_drop_out(1754);
goto TERMINAL_938;

    __quex_assert_no_passage();
_1759: /* (1759 from 1731) */

    ++(me->buffer._input_p);
    __quex_debug_state(1759);
    __quex_debug_drop_out(1759);
goto TERMINAL_930;

    __quex_assert_no_passage();
_1760: /* (1760 from 1729) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1760);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1760, 1797);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: goto _1755;
        case 0x64: goto _1761;
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1755;

    }
_1797:
    __quex_debug_drop_out(1760);
goto TERMINAL_950;

    __quex_assert_no_passage();
_1761: /* (1761 from 1760) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1761);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1761, 1798);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: goto _1755;
        case 0x6C: goto _1762;
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1755;

    }
_1798:
    __quex_debug_drop_out(1761);
goto TERMINAL_950;

    __quex_assert_no_passage();
_1762: /* (1762 from 1761) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1762);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1762, 1799);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1755;

    }
_1799:
    __quex_debug_drop_out(1762);
goto TERMINAL_948;

    __quex_assert_no_passage();
_1763: /* (1763 from 1728) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1763);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1763, 1800);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: goto _1755;
        case 0x62: goto _1764;
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1755;

    }
_1800:
    __quex_debug_drop_out(1763);
goto TERMINAL_950;

    __quex_assert_no_passage();
_1764: /* (1764 from 1763) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1764);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1764, 1801);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1755;

    }
_1801:
    __quex_debug_drop_out(1764);
goto TERMINAL_949;

    __quex_assert_no_passage();
_1765: /* (1765 from 1727) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1765);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1765, 1802);
        case 0x3D: goto _1766;

    }
_1802:
    __quex_debug_drop_out(1765);
goto TERMINAL_933;

    __quex_assert_no_passage();
_1766: /* (1766 from 1765) */

    ++(me->buffer._input_p);
    __quex_debug_state(1766);
    __quex_debug_drop_out(1766);
goto TERMINAL_931;

    __quex_assert_no_passage();
_1767: /* (1767 from 1724) */

    ++(me->buffer._input_p);
    __quex_debug_state(1767);
    __quex_debug_drop_out(1767);
goto TERMINAL_929;

    __quex_assert_no_passage();
_1768: /* (1768 from 1717) */

    ++(me->buffer._input_p);
    __quex_debug_state(1768);
    __quex_debug_drop_out(1768);
goto TERMINAL_939;

    __quex_assert_no_passage();
_1715: /* (1715 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1715);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1715, 1806);
        case 0x2F: goto _1743;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1757;

    }
_1806:
    __quex_debug_drop_out(1715);
goto TERMINAL_923;

    __quex_assert_no_passage();
_1716: /* (1716 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1716);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1716, 1807);
        case 0x2C: 
        case 0x2E: goto _1758;
        case 0x2F: goto _1743;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1769;
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1755;

    }
_1807:
    __quex_debug_drop_out(1716);
goto TERMINAL_944;

    __quex_assert_no_passage();
_1717: /* (1717 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1717);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1717, 1808);
        case 0x2F: goto _1743;
        case 0x3D: goto _1768;

    }
_1808:
    __quex_debug_drop_out(1717);
goto TERMINAL_937;

    __quex_assert_no_passage();
_1718: /* (1718 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1718);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1718, 1809);
        case 0x2F: goto _1743;

    }
_1809:
    __quex_debug_drop_out(1718);
goto TERMINAL_940;

    __quex_assert_no_passage();
_1719: /* (1719 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1719);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1719, 1810);
        case 0x2F: goto _1743;

    }
_1810:
    __quex_debug_drop_out(1719);
goto TERMINAL_945;

    __quex_assert_no_passage();
_1720: /* (1720 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1720);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1720, 1811);
        case 0x2F: goto _1743;

    }
_1811:
    __quex_debug_drop_out(1720);
goto TERMINAL_942;

    __quex_assert_no_passage();
_1721: /* (1721 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1721);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1721, 1812);
        case 0x2F: goto _1743;

    }
_1812:
    __quex_debug_drop_out(1721);
goto TERMINAL_947;

    __quex_assert_no_passage();
_1722: /* (1722 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1722);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1722, 1813);
        case 0x2F: goto _1743;

    }
_1813:
    __quex_debug_drop_out(1722);
goto TERMINAL_927;

    __quex_assert_no_passage();
_1723: /* (1723 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1723);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1723, 1814);
        case 0x2F: goto _1743;

    }
_1814:
    __quex_debug_drop_out(1723);
goto TERMINAL_928;

    __quex_assert_no_passage();
_1724: /* (1724 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1724);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1724, 1815);
        case 0x26: goto _1767;
        case 0x2F: goto _1743;

    }
_1815:
    __quex_debug_drop_out(1724);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1725: /* (1725 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1725);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1725, 1816);
        case 0x2F: goto _1743;

    }
_1816:
    __quex_debug_drop_out(1725);
goto TERMINAL_941;

    __quex_assert_no_passage();
_1726: /* (1726 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1726);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1726, 1817);
        case 0x2F: goto _1743;

    }
_1817:
    __quex_debug_drop_out(1726);
goto TERMINAL_925;

    __quex_assert_no_passage();
_1727: /* (1727 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1727);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1727, 1818);
        case 0x2F: goto _1743;
        case 0x3D: goto _1765;

    }
_1818:
    __quex_debug_drop_out(1727);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1728: /* (1728 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1728);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1728, 1819);
        case 0x2F: goto _1743;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: goto _1755;
        case 0x61: goto _1763;
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1755;

    }
_1819:
    __quex_debug_drop_out(1728);
goto TERMINAL_950;

    __quex_assert_no_passage();
_1729: /* (1729 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1729);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1729, 1820);
        case 0x2F: goto _1743;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: goto _1755;
        case 0x6E: goto _1760;
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1755;

    }
_1820:
    __quex_debug_drop_out(1729);
goto TERMINAL_950;

    __quex_assert_no_passage();
_1730: /* (1730 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1730);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1730, 1821);
        case 0x2F: goto _1743;

    }
_1821:
    __quex_debug_drop_out(1730);
goto TERMINAL_918;

    __quex_assert_no_passage();
_1731: /* (1731 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1731);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1731, 1822);
        case 0x2F: goto _1743;
        case 0x7C: goto _1759;

    }
_1822:
    __quex_debug_drop_out(1731);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1732: /* (1732 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1732);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1732, 1823);
        case 0x2F: goto _1743;

    }
_1823:
    __quex_debug_drop_out(1732);
goto TERMINAL_919;

    __quex_assert_no_passage();
_1733: /* (1733 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1733);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1733, 1824);
        case 0x2F: goto _1743;

    }
_1824:
    __quex_debug_drop_out(1733);
goto TERMINAL_946;

    __quex_assert_no_passage();
_1734: /* (1734 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1734);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1734, 1825);
        case 0x2F: goto _1743;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1757;

    }
_1825:
    __quex_debug_drop_out(1734);
goto TERMINAL_924;

    __quex_assert_no_passage();
_1735: /* (1735 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1735);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1735, 1826);
        case 0x2F: goto _1743;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1756;

    }
_1826:
    __quex_debug_drop_out(1735);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1736: /* (1736 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1736);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1736, 1827);
        case 0x2F: goto _1743;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: 
        case 0x41: 
        case 0x42: 
        case 0x43: 
        case 0x44: 
        case 0x45: 
        case 0x46: 
        case 0x47: 
        case 0x48: 
        case 0x49: 
        case 0x4A: 
        case 0x4B: 
        case 0x4C: 
        case 0x4D: 
        case 0x4E: 
        case 0x4F: 
        case 0x50: 
        case 0x51: 
        case 0x52: 
        case 0x53: 
        case 0x54: 
        case 0x55: 
        case 0x56: 
        case 0x57: 
        case 0x58: 
        case 0x59: 
        case 0x5A: 
        case 0x5F: 
        case 0x61: 
        case 0x62: 
        case 0x63: 
        case 0x64: 
        case 0x65: 
        case 0x66: 
        case 0x67: 
        case 0x68: 
        case 0x69: 
        case 0x6A: 
        case 0x6B: 
        case 0x6C: 
        case 0x6D: 
        case 0x6E: 
        case 0x6F: 
        case 0x70: 
        case 0x71: 
        case 0x72: 
        case 0x73: 
        case 0x74: 
        case 0x75: 
        case 0x76: 
        case 0x77: 
        case 0x78: 
        case 0x79: 
        case 0x7A: goto _1755;

    }
_1827:
    __quex_debug_drop_out(1736);
goto TERMINAL_950;

    __quex_assert_no_passage();
_1737: /* (1737 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1737);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1737, 1828);
        case 0x2F: goto _1743;

    }
_1828:
    __quex_debug_drop_out(1737);
goto TERMINAL_920;

    __quex_assert_no_passage();
_1738: /* (1738 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1738);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1738, 1829);
        case 0x2F: goto _1743;
        case 0x3D: goto _1754;

    }
_1829:
    __quex_debug_drop_out(1738);
goto TERMINAL_936;

    __quex_assert_no_passage();
_1739: /* (1739 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1739);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1739, 1830);
        case 0x2F: goto _1743;

    }
_1830:
    __quex_debug_drop_out(1739);

goto _1040; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1771: /* (1740 from 1714) */
    { last_acceptance = 926; __quex_debug("last_acceptance = 926\n"); }

_1740:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1740);
    if( input < 0x2A ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1740, 1831);
            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: 
            case 0x9: 
            case 0xA: 
            case 0xB: 
            case 0xC: 
            case 0xD: 
            case 0xE: 
            case 0xF: 
            case 0x10: 
            case 0x11: 
            case 0x12: 
            case 0x13: 
            case 0x14: 
            case 0x15: 
            case 0x16: 
            case 0x17: 
            case 0x18: 
            case 0x19: 
            case 0x1A: 
            case 0x1B: 
            case 0x1C: 
            case 0x1D: 
            case 0x1E: 
            case 0x1F: 
            case 0x20: 
            case 0x21: 
            case 0x22: 
            case 0x23: 
            case 0x24: 
            case 0x25: 
            case 0x26: 
            case 0x27: 
            case 0x28: 
            case 0x29: goto _1744;

        }
    } else {
        if( input == 0x2A ) {
            goto _1746;
        } else if( input < 0x2F ) {
            goto _1744;
        } else if( input == 0x2F ) {
            goto _1774;
        } else {
            goto _1744;
        }
    }
_1831:
    __quex_debug_drop_out(1740);
goto TERMINAL_926;

    __quex_assert_no_passage();
_1741: /* (1741 from 1714) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1741);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1741, 1832);
        case 0x2F: goto _1743;
        case 0x3D: goto _1742;

    }
_1832:
    __quex_debug_drop_out(1741);
goto TERMINAL_935;
    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */

    /* Lexeme setup: 
     *
     * There is a temporary zero stored at the end of each lexeme, if the action 
     * references to the 'Lexeme'. 'LexemeNull' provides a reference to an empty
     * zero terminated string.                                                    */
#if defined(QUEX_OPTION_ASSERTS)
#   define Lexeme       QUEX_NAME(access_Lexeme)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeBegin  QUEX_NAME(access_LexemeBegin)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeL      QUEX_NAME(access_LexemeL)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#   define LexemeEnd    QUEX_NAME(access_LexemeEnd)((const char*)__FILE__, (size_t)__LINE__, &me->buffer)
#else
#   define Lexeme       (me->buffer._lexeme_start_p)
#   define LexemeBegin  Lexeme
#   define LexemeL      ((size_t)(me->buffer._input_p - me->buffer._lexeme_start_p))
#   define LexemeEnd    me->buffer._input_p
#endif

#define LexemeNull      (&QUEX_LEXEME_NULL)

TERMINAL_918:
    __quex_debug("* terminal 918:   <skip: ... (check also base modes)>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 245 "lexical_analyzer.qx"
    goto __SKIP;
    
#   line 8013 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_919:
    __quex_debug("* terminal 919:   <skip: ... (check also base modes)>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4);

    {
#   line 245 "lexical_analyzer.qx"
    goto __SKIP;
    
#   line 8028 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_920:
    __quex_debug("* terminal 920:   <skip>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_LINES_ADD(1);
__QUEX_IF_COUNT_COLUMNS_SET(1);
    {
__SKIP:
    /* Character Set Skipper: '['\t', '\n'], '\r', ' '' */
    QUEX_BUFFER_ASSERT_CONSISTENCY(&me->buffer);
__QUEX_IF_COUNT_COLUMNS(reference_p = me->buffer._input_p);
    while( 1 + 1 == 2 ) {
_1498:
        if( (*me->buffer._input_p) < 0xB ) {
            switch( (*me->buffer._input_p) ) {
                case 0x0: QUEX_GOTO_RELOAD(_1499, 1498, 955);
                case 0x1:
                case 0x2:
                case 0x3:
                case 0x4:
                case 0x5:
                case 0x6:
                case 0x7:
                case 0x8: __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
                case 0x9:             __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
            __QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
            __QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4);
            __QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p) + 1);
                    ++((me->buffer._input_p));
                continue;
                case 0xA: __QUEX_IF_COUNT_LINES_ADD((size_t)1);
            __QUEX_IF_COUNT_COLUMNS_SET((size_t)1);
            __QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p) + 1);
                    ++((me->buffer._input_p));
                continue;

            }
        } else {
            if( (*me->buffer._input_p) < 0xD ) {
                __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
            } else if( (*me->buffer._input_p) == 0xD ) {
                        ++((me->buffer._input_p));
                continue;
            } else if( (*me->buffer._input_p) < 0x20 ) {
                __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
            } else if( (*me->buffer._input_p) == 0x20 ) {
                        ++((me->buffer._input_p));
                continue;
            } else {
                __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
                goto __REENTRY;
            }
        }

    __quex_assert_no_passage();
_1499:

    __quex_debug1("__RELOAD_FORWARD");
    __quex_assert(*((me->buffer._input_p)) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));
me->buffer._lexeme_start_p = (me->buffer._input_p);

        __quex_debug_reload_before(); /* Leave macro here to report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);
        ++((me->buffer._input_p));
__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);
    }

    }
    goto __REENTRY_PREPARATION;

TERMINAL_921:
    __quex_debug("* terminal 921:   {D_COMMENT_STREAM_BEGINNING}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
    Skipper1500_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1500_Opener;
    Skipper1500_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1500_Closer;
    /* text_end                           = QUEX_NAME(Buffer_text_end)(&me->buffer); */
    __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));


_1500:

    QUEX_BUFFER_ASSERT_CONSISTENCY(&me->buffer);
    __quex_assert(QUEX_NAME(Buffer_content_size)(&me->buffer) >= 2 );

    /* NOTE: If _input_p == end of buffer, then it will drop out immediately out of the
        *       loop below and drop into the buffer reload procedure.                      */

    /* Loop eating characters: Break-out as soon as the First Character of the Delimiter
        * (FCD) is reached. Thus, the FCD plays also the role of the Buffer Limit Code. There
        * are two reasons for break-out:
        *    (1) we reached a limit (end-of-file or buffer-limit)
        *    (2) there was really the FCD in the character stream
        * This must be distinguished after the loop was exited. But, during the 'swallowing'
        * we are very fast, because we do not have to check for two different characters.  */
    while( 1 + 1 == 2 ) {
            input = *(me->buffer._input_p);

            if( input == QUEX_SETTING_BUFFER_LIMIT_CODE ) {
                    goto _1501;
            }
            if( input == *Skipper1500_Closer_it ) {
                    ++Skipper1500_Closer_it;
                    if( Skipper1500_Closer_it == Skipper1500_CloserEnd ) {
                        if( counter == 0 ) {
                            /* NOTE: The initial state does not increment the input_p. When it detects that
                                * it is located on a buffer border, it automatically triggers a reload. No
                                * need here to reload the buffer. */
                            ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
                                    __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer)
                                            - reference_p));

                            /* No need for re-entry preparation. Acceptance flags and modes are untouched after skipping. */
                            goto __REENTRY; /* End of range reached. */
                        }
                        --counter;
                        Skipper1500_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1500_Opener;
                        Skipper1500_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1500_Closer;
                        goto CONTINUE_1500;
                    }
            } else {
                    Skipper1500_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1500_Closer;
            }
            if( input == *Skipper1500_Opener_it ) {
                    ++Skipper1500_Opener_it;
                    if( Skipper1500_Opener_it == Skipper1500_OpenerEnd ) {
                        ++counter;
                        Skipper1500_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1500_Opener;
                        Skipper1500_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1500_Closer;
                        goto CONTINUE_1500;
                    }
            } else {
                    Skipper1500_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1500_Opener;
            }
CONTINUE_1500:

    __QUEX_IF_COUNT_IF( input == (QUEX_TYPE_CHARACTER)'\n' ) {
            __QUEX_IF_COUNT_LINES_ADD((size_t)1);
            __QUEX_IF_COUNT_COLUMNS_SET((size_t)0);
            __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));
    }

            ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
    }

_1501:
    QUEX_BUFFER_ASSERT_CONSISTENCY_LIGHT(&me->buffer);
    /* -- When loading new content it is checked that the beginning of the lexeme
        *    is not 'shifted' out of the buffer. In the case of skipping, we do not care about
        *    the lexeme at all, so do not restrict the load procedure and set the lexeme start
        *    to the actual input position.                                                    */
    me->buffer._lexeme_start_p = me->buffer._input_p;

    __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer)
                                        - reference_p));

    if( QUEX_NAME(Buffer_is_end_of_file)(&me->buffer) == false ) {
            QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position,
                                                PositionRegisterN);
            /* Recover '_input_p' from lexeme start
                * (inverse of what we just did before the loading) */
            me->buffer._input_p = me->buffer._lexeme_start_p;
            /* After reload, we need to increment _input_p. That's how the game is supposed to be played.
                * But, we recovered from lexeme start pointer, and this one does not need to be incremented. */
            /* text_end = QUEX_NAME(Buffer_text_end)(&me->buffer); */
            __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));

            QUEX_BUFFER_ASSERT_CONSISTENCY(&me->buffer);
            goto _1500; /* End of range reached.             */
    }
    /* Here, either the loading failed or it is not enough space to carry a closing delimiter */
    me->buffer._input_p = me->buffer._lexeme_start_p;
    QUEX_ERROR_EXIT("\nLexical analyzer mode 'EXPRESSION':\n"
                        "End of file occurred before closing skip range delimiter!\n"                "The 'on_skip_range_open' handler has not been specified.");

    }
    goto __REENTRY_PREPARATION;

TERMINAL_922:
    __quex_debug("* terminal 922:   {D_COMMENT_BLOCK}([inverse({D_NEW_LINE})]|({D_BACKSLASH}{D_WHITESPACE}*{D_NEW_LINE}))*{D_NEW_LINE}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 252 "lexical_analyzer.qx"
    
        // We are within a comment. Do not do anything.
    
    
#   line 8231 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_923:
    __quex_debug("* terminal 923:   \"+\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 356 "lexical_analyzer.qx"
    self_send(QUEX_TKN_ADDITION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8245 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_924:
    __quex_debug("* terminal 924:   \"-\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 357 "lexical_analyzer.qx"
    self_send(QUEX_TKN_SUBSTRACTION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8259 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_925:
    __quex_debug("* terminal 925:   \"*\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 358 "lexical_analyzer.qx"
    self_send(QUEX_TKN_MULTIPLICATION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8273 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_926:
    __quex_debug("* terminal 926:   {D_DIVISION}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 359 "lexical_analyzer.qx"
    self_send(QUEX_TKN_DIVISION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8286 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_927:
    __quex_debug("* terminal 927:   \"%\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 360 "lexical_analyzer.qx"
    self_send(QUEX_TKN_MODULO);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8300 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_928:
    __quex_debug("* terminal 928:   \"^\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 361 "lexical_analyzer.qx"
    self_send(QUEX_TKN_EXPONENTIATION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8314 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_929:
    __quex_debug("* terminal 929:   \"&&\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
#   line 363 "lexical_analyzer.qx"
    self_send(QUEX_TKN_LOGIC_AND);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8328 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_930:
    __quex_debug("* terminal 930:   \"||\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
#   line 364 "lexical_analyzer.qx"
    self_send(QUEX_TKN_LOGIC_OR);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8342 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_931:
    __quex_debug("* terminal 931:   \"===\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(3);
    {
#   line 366 "lexical_analyzer.qx"
    self_send(QUEX_TKN_EQUALITY_ABSOLUTE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8356 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_932:
    __quex_debug("* terminal 932:   \"!==\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(3);
    {
#   line 367 "lexical_analyzer.qx"
    self_send(QUEX_TKN_INEQUALITY_ABSOLUTE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8370 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_933:
    __quex_debug("* terminal 933:   \"==\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
#   line 368 "lexical_analyzer.qx"
    self_send(QUEX_TKN_EQUALITY_RELATIVE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8384 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_934:
    __quex_debug("* terminal 934:   \"!=\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
#   line 369 "lexical_analyzer.qx"
    self_send(QUEX_TKN_INEQUALITY_RELATIVE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8398 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_935:
    __quex_debug("* terminal 935:   \"!\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 370 "lexical_analyzer.qx"
    self_send(QUEX_TKN_NEGATION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8412 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_936:
    __quex_debug("* terminal 936:   \">\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 372 "lexical_analyzer.qx"
    self_send(QUEX_TKN_GREATER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8426 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_937:
    __quex_debug("* terminal 937:   \"<\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 373 "lexical_analyzer.qx"
    self_send(QUEX_TKN_LOWER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8440 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_938:
    __quex_debug("* terminal 938:   \">=\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
#   line 374 "lexical_analyzer.qx"
    self_send(QUEX_TKN_GREATER_EQUAL);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8454 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_939:
    __quex_debug("* terminal 939:   \"<=\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
#   line 375 "lexical_analyzer.qx"
    self_send(QUEX_TKN_LOWER_EQUAL);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8468 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_940:
    __quex_debug("* terminal 940:   {D_STATEMENT_END}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 377 "lexical_analyzer.qx"
    QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_STATEMENT_END);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8482 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_941:
    __quex_debug("* terminal 941:   \")\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 378 "lexical_analyzer.qx"
    QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_PARENTHESIS_END);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8496 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_942:
    __quex_debug("* terminal 942:   \"(\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 379 "lexical_analyzer.qx"
    QUEX_NAME(push_mode)(&self, &EXPRESSION);self_send(QUEX_TKN_PARENTHESIS_BEGINNING);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8510 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_943:
    __quex_debug("* terminal 943:   \\${D_IDENTIFIER}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
    {
#   line 382 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_IDENTIFIER_VARIABLE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8525 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_944:
    __quex_debug("* terminal 944:   {D_NUMBER}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
    {
#   line 383 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_NUMBER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8540 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_945:
    __quex_debug("* terminal 945:   {D_QUOTE_SINGLE}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 384 "lexical_analyzer.qx"
    QUEX_NAME(push_mode)(&self, &STRING_ABSOLUTE);self_send(QUEX_TKN_STRING_ABSOLUTE_BEGINNING);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8554 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_946:
    __quex_debug("* terminal 946:   {D_QUOTE_DOUBLE}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 385 "lexical_analyzer.qx"
    QUEX_NAME(push_mode)(&self, &STRING_RELATIVE);self_send(QUEX_TKN_STRING_RELATIVE_BEGINNING);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8568 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_947:
    __quex_debug("* terminal 947:   {D_CONCATENATION}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 386 "lexical_analyzer.qx"
    self_send(QUEX_TKN_CONCATENATION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8582 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_948:
    __quex_debug("* terminal 948:   \"endl\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(4);
    {
#   line 387 "lexical_analyzer.qx"
    self_send(QUEX_TKN_ENDL);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8596 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_949:
    __quex_debug("* terminal 949:   \"tab\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(3);
    {
#   line 388 "lexical_analyzer.qx"
    self_send(QUEX_TKN_TAB);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8610 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_950:
    __quex_debug("* terminal 950:   {D_IDENTIFIER}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
    {
#   line 389 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_IDENTIFIER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 8625 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;


_1040: /* TERMINAL: FAILURE */
    if(QUEX_NAME(Buffer_is_end_of_file)(&me->buffer)) {
        /* Init state is going to detect 'input == buffer limit code', and
         * enter the reload procedure, which will decide about 'end of stream'. */
    } else {
        /* In init state 'input = *input_p' and we need to increment
         * in order to avoid getting stalled. Else, input = *(input_p - 1),
         * so 'input_p' points already to the next character.                   */
        if( me->buffer._input_p == me->buffer._lexeme_start_p ) {
            /* Step over non-matching character */
            ++(me->buffer._input_p);
        }
    }
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    QUEX_LEXEME_TERMINATING_ZERO_SET(&me->buffer);
    {
#   line 237 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_FAILURE);
    
        RETURN;
    
    
#   line 8654 "lexical_analyzer.cpp"
    
#   line 392 "lexical_analyzer.qx"
    
        self_accumulator_add (Lexeme, LexemeEnd);
    
    
#   line 8661 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION_2;


/* TERMINAL: END_OF_STREAM */
_955:
__QUEX_IF_COUNT_SHIFT_VALUES();
    {
#   line 230 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_TERMINATION);
    
        RETURN;
    
    
#   line 8678 "lexical_analyzer.cpp"

    }
    /* End of Stream causes a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.                    */
    RETURN;

__REENTRY_PREPARATION:
    /* (*) Common point for **restarting** lexical analysis.
     *     at each time when CONTINUE is called at the end of a pattern.     */
 

    /* FAILURE needs not to run through 'on_after_match'. It enters here.    */
__REENTRY_PREPARATION_2:

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL

#   ifndef __QUEX_OPTION_PLAIN_ANALYZER_OBJECT
#   ifdef  QUEX_OPTION_TOKEN_POLICY_QUEUE
    if( QUEX_NAME(TokenQueue_is_full)(&self._token_queue) ) {
        return;
    }
#   else
    if( self_token_get_id() != __QUEX_SETTING_TOKEN_ID_UNINITIALIZED) {
        return __self_result_token_id;
    }
#   endif
#   endif


    /* Post context positions do not have to be reset or initialized. If a state
     * is reached which is associated with 'end of post context' it is clear what
     * post context is meant. This results from the ways the state machine is 
     * constructed. Post context position's live cycle:
     *
     * (1)   unitialized (don't care)
     * (1.b) on buffer reload it may, or may not be adapted (don't care)
     * (2)   when a post context begin state is passed, then it is **SET** (now: take care)
     * (2.b) on buffer reload it **is adapted**.
     * (3)   when a terminal state of the post context is reached (which can only be reached
     *       for that particular post context), then the post context position is used
     *       to reset the input position.                                              */

    /*  If a mode change happened, then the function must first return and
     *  indicate that another mode function is to be called. At this point, 
     *  we to force a 'return' on a mode change. 
     *
     *  Pseudo Code: if( previous_mode != current_mode ) {
     *                   return 0;
     *               }
     *
     *  When the analyzer returns, the caller function has to watch if a mode 
     *  change occurred. If not it can call this function again.             */
#   if    defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)        || defined(QUEX_OPTION_ASSERTS)
    if( me->DEBUG_analyzer_function_at_entry != me->current_analyzer_function ) 
#   endif
    { 
#       if defined(QUEX_OPTION_AUTOMATIC_ANALYSIS_CONTINUATION_ON_MODE_CHANGE)
        self_token_set_id(__QUEX_SETTING_TOKEN_ID_UNINITIALIZED);
        __QUEX_PURE_RETURN;
#       elif defined(QUEX_OPTION_ASSERTS)
        QUEX_ERROR_EXIT("Mode change without immediate return from the lexical analyzer.");
#       endif
    }

    goto __REENTRY;

    __quex_assert_no_passage();
__RELOAD_FORWARD:

    __quex_debug1("__RELOAD_FORWARD");
    __quex_assert(*(me->buffer._input_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {

        __quex_debug_reload_before(); /* Leave macro here to report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
__STATE_ROUTER:
    switch( target_state_index ) {
        case 955: { goto _955; }
        case 1498: { goto _1498; }
        case 1499: { goto _1499; }
        case 1500: { goto _1500; }
        case 1714: { goto _1714; }
        case 1715: { goto _1715; }
        case 1716: { goto _1716; }
        case 1717: { goto _1717; }
        case 1718: { goto _1718; }
        case 1719: { goto _1719; }
        case 1720: { goto _1720; }
        case 1721: { goto _1721; }
        case 1722: { goto _1722; }
        case 1723: { goto _1723; }
        case 1724: { goto _1724; }
        case 1725: { goto _1725; }
        case 1726: { goto _1726; }
        case 1727: { goto _1727; }
        case 1728: { goto _1728; }
        case 1729: { goto _1729; }
        case 1730: { goto _1730; }
        case 1731: { goto _1731; }
        case 1732: { goto _1732; }
        case 1733: { goto _1733; }
        case 1734: { goto _1734; }
        case 1735: { goto _1735; }
        case 1736: { goto _1736; }
        case 1737: { goto _1737; }
        case 1738: { goto _1738; }
        case 1739: { goto _1739; }
        case 1740: { goto _1740; }
        case 1741: { goto _1741; }
        case 1742: { goto _1742; }
        case 1743: { goto _1743; }
        case 1744: { goto _1744; }
        case 1745: { goto _1745; }
        case 1746: { goto _1746; }
        case 1747: { goto _1747; }
        case 1748: { goto _1748; }
        case 1749: { goto _1749; }
        case 1750: { goto _1750; }
        case 1751: { goto _1751; }
        case 1752: { goto _1752; }
        case 1753: { goto _1753; }
        case 1754: { goto _1754; }
        case 1755: { goto _1755; }
        case 1756: { goto _1756; }
        case 1757: { goto _1757; }
        case 1758: { goto _1758; }
        case 1759: { goto _1759; }
        case 1760: { goto _1760; }
        case 1761: { goto _1761; }
        case 1762: { goto _1762; }
        case 1763: { goto _1763; }
        case 1764: { goto _1764; }
        case 1765: { goto _1765; }
        case 1766: { goto _1766; }
        case 1767: { goto _1767; }
        case 1768: { goto _1768; }
        case 1769: { goto _1769; }
        case 1771: { goto _1771; }
        case 1773: { goto _1773; }
        case 1774: { goto _1774; }
        case 1775: { goto _1775; }
        case 1776: { goto _1776; }
        case 1777: { goto _1777; }
        case 1778: { goto _1778; }
        case 1779: { goto _1779; }
        case 1780: { goto _1780; }
        case 1782: { goto _1782; }
        case 1783: { goto _1783; }
        case 1784: { goto _1784; }
        case 1785: { goto _1785; }
        case 1786: { goto _1786; }
        case 1788: { goto _1788; }
        case 1789: { goto _1789; }
        case 1790: { goto _1790; }
        case 1793: { goto _1793; }
        case 1794: { goto _1794; }
        case 1797: { goto _1797; }
        case 1798: { goto _1798; }
        case 1799: { goto _1799; }
        case 1800: { goto _1800; }
        case 1801: { goto _1801; }
        case 1802: { goto _1802; }
        case 1806: { goto _1806; }
        case 1807: { goto _1807; }
        case 1808: { goto _1808; }
        case 1809: { goto _1809; }
        case 1810: { goto _1810; }
        case 1811: { goto _1811; }
        case 1812: { goto _1812; }
        case 1813: { goto _1813; }
        case 1814: { goto _1814; }
        case 1815: { goto _1815; }
        case 1816: { goto _1816; }
        case 1817: { goto _1817; }
        case 1818: { goto _1818; }
        case 1819: { goto _1819; }
        case 1820: { goto _1820; }
        case 1821: { goto _1821; }
        case 1822: { goto _1822; }
        case 1823: { goto _1823; }
        case 1824: { goto _1824; }
        case 1825: { goto _1825; }
        case 1826: { goto _1826; }
        case 1827: { goto _1827; }
        case 1828: { goto _1828; }
        case 1829: { goto _1829; }
        case 1830: { goto _1830; }
        case 1831: { goto _1831; }
        case 1832: { goto _1832; }

        default:
            __QUEX_STD_fprintf(stderr, "State router: index = %i\n", (int)target_state_index);
            QUEX_ERROR_EXIT("State router: unknown index.\n");
    }
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */

    /* Prevent compiler warning 'unused variable': use variables once in a part of the code*/
    /* that is never reached (and deleted by the compiler anyway).*/
    (void)QUEX_LEXEME_NULL;
    (void)QUEX_NAME_TOKEN(DumpedTokenIdObject);
    QUEX_ERROR_EXIT("Unreachable code has been reached.\n");
#   undef FUNCTION_DEFINITION
#   undef STRING_RELATIVE
#   undef FUNCTION_DEFINITION_PARAMETERS
#   undef STRING_ABSOLUTE
#   undef SCOPE
#   undef EXPRESSION
#   undef self
}
#include <quex/code_base/temporary_macros_off>
QUEX_NAMESPACE_MAIN_CLOSE


QUEX_NAMESPACE_TOKEN_OPEN

const char*
QUEX_NAME_TOKEN(map_id_to_name)(const QUEX_TYPE_TOKEN_ID TokenID)
{
   static char  error_string[64];
   static const char  uninitialized_string[] = "<UNINITIALIZED>";
   static const char  termination_string[]   = "<TERMINATION>";
#  if defined(QUEX_OPTION_INDENTATION_TRIGGER)
   static const char  indent_string[]        = "<INDENT>";
   static const char  dedent_string[]        = "<DEDENT>";
   static const char  nodent_string[]        = "<NODENT>";
#  endif
   static const char  token_id_str_ADDITION[]                  = "ADDITION";
   static const char  token_id_str_ASSIGNMENT[]                = "ASSIGNMENT";
   static const char  token_id_str_BACKSLASHED_BACKSLASH[]     = "BACKSLASHED_BACKSLASH";
   static const char  token_id_str_BACKSLASHED_QUOTE_DOUBLE[]  = "BACKSLASHED_QUOTE_DOUBLE";
   static const char  token_id_str_BRACE_BEGINNING[]           = "BRACE_BEGINNING";
   static const char  token_id_str_BRACE_END[]                 = "BRACE_END";
   static const char  token_id_str_CHARACTER[]                 = "CHARACTER";
   static const char  token_id_str_CONCATENATION[]             = "CONCATENATION";
   static const char  token_id_str_DIVISION[]                  = "DIVISION";
   static const char  token_id_str_ENDL[]                      = "ENDL";
   static const char  token_id_str_EQUALITY_ABSOLUTE[]         = "EQUALITY_ABSOLUTE";
   static const char  token_id_str_EQUALITY_RELATIVE[]         = "EQUALITY_RELATIVE";
   static const char  token_id_str_EXPONENTIATION[]            = "EXPONENTIATION";
   static const char  token_id_str_FAILURE[]                   = "FAILURE";
   static const char  token_id_str_FUNCTION_DEFINITION[]       = "FUNCTION_DEFINITION";
   static const char  token_id_str_GREATER[]                   = "GREATER";
   static const char  token_id_str_GREATER_EQUAL[]             = "GREATER_EQUAL";
   static const char  token_id_str_IDENTIFIER[]                = "IDENTIFIER";
   static const char  token_id_str_IDENTIFIER_VARIABLE[]       = "IDENTIFIER_VARIABLE";
   static const char  token_id_str_INCLUDE[]                   = "INCLUDE";
   static const char  token_id_str_INEQUALITY_ABSOLUTE[]       = "INEQUALITY_ABSOLUTE";
   static const char  token_id_str_INEQUALITY_RELATIVE[]       = "INEQUALITY_RELATIVE";
   static const char  token_id_str_LOGIC_AND[]                 = "LOGIC_AND";
   static const char  token_id_str_LOGIC_OR[]                  = "LOGIC_OR";
   static const char  token_id_str_LOWER[]                     = "LOWER";
   static const char  token_id_str_LOWER_EQUAL[]               = "LOWER_EQUAL";
   static const char  token_id_str_MODULO[]                    = "MODULO";
   static const char  token_id_str_MULTIPLICATION[]            = "MULTIPLICATION";
   static const char  token_id_str_NEGATION[]                  = "NEGATION";
   static const char  token_id_str_NUMBER[]                    = "NUMBER";
   static const char  token_id_str_OUTPUT[]                    = "OUTPUT";
   static const char  token_id_str_PARENTHESIS_BEGINNING[]     = "PARENTHESIS_BEGINNING";
   static const char  token_id_str_PARENTHESIS_END[]           = "PARENTHESIS_END";
   static const char  token_id_str_SERIALIZE[]                 = "SERIALIZE";
   static const char  token_id_str_STATEMENT_END[]             = "STATEMENT_END";
   static const char  token_id_str_STRING[]                    = "STRING";
   static const char  token_id_str_STRING_ABSOLUTE_BEGINNING[] = "STRING_ABSOLUTE_BEGINNING";
   static const char  token_id_str_STRING_ABSOLUTE_END[]       = "STRING_ABSOLUTE_END";
   static const char  token_id_str_STRING_RELATIVE_BEGINNING[] = "STRING_RELATIVE_BEGINNING";
   static const char  token_id_str_STRING_RELATIVE_END[]       = "STRING_RELATIVE_END";
   static const char  token_id_str_SUBSTRACTION[]              = "SUBSTRACTION";
   static const char  token_id_str_TAB[]                       = "TAB";
       

   /* NOTE: This implementation works only for token id types that are 
    *       some type of integer or enum. In case an alien type is to
    *       used, this function needs to be redefined.                  */
   switch( TokenID ) {
   default: {
       __QUEX_STD_sprintf(error_string, "<UNKNOWN TOKEN-ID: %i>", (int)TokenID);
       return error_string;
   }
   case QUEX_TKN_TERMINATION:    return termination_string;
   case QUEX_TKN_UNINITIALIZED:  return uninitialized_string;
#  if defined(QUEX_OPTION_INDENTATION_TRIGGER)
   case QUEX_TKN_INDENT:         return indent_string;
   case QUEX_TKN_DEDENT:         return dedent_string;
   case QUEX_TKN_NODENT:         return nodent_string;
#  endif
   case QUEX_TKN_ADDITION:                  return token_id_str_ADDITION;
   case QUEX_TKN_ASSIGNMENT:                return token_id_str_ASSIGNMENT;
   case QUEX_TKN_BACKSLASHED_BACKSLASH:     return token_id_str_BACKSLASHED_BACKSLASH;
   case QUEX_TKN_BACKSLASHED_QUOTE_DOUBLE:  return token_id_str_BACKSLASHED_QUOTE_DOUBLE;
   case QUEX_TKN_BRACE_BEGINNING:           return token_id_str_BRACE_BEGINNING;
   case QUEX_TKN_BRACE_END:                 return token_id_str_BRACE_END;
   case QUEX_TKN_CHARACTER:                 return token_id_str_CHARACTER;
   case QUEX_TKN_CONCATENATION:             return token_id_str_CONCATENATION;
   case QUEX_TKN_DIVISION:                  return token_id_str_DIVISION;
   case QUEX_TKN_ENDL:                      return token_id_str_ENDL;
   case QUEX_TKN_EQUALITY_ABSOLUTE:         return token_id_str_EQUALITY_ABSOLUTE;
   case QUEX_TKN_EQUALITY_RELATIVE:         return token_id_str_EQUALITY_RELATIVE;
   case QUEX_TKN_EXPONENTIATION:            return token_id_str_EXPONENTIATION;
   case QUEX_TKN_FAILURE:                   return token_id_str_FAILURE;
   case QUEX_TKN_FUNCTION_DEFINITION:       return token_id_str_FUNCTION_DEFINITION;
   case QUEX_TKN_GREATER:                   return token_id_str_GREATER;
   case QUEX_TKN_GREATER_EQUAL:             return token_id_str_GREATER_EQUAL;
   case QUEX_TKN_IDENTIFIER:                return token_id_str_IDENTIFIER;
   case QUEX_TKN_IDENTIFIER_VARIABLE:       return token_id_str_IDENTIFIER_VARIABLE;
   case QUEX_TKN_INCLUDE:                   return token_id_str_INCLUDE;
   case QUEX_TKN_INEQUALITY_ABSOLUTE:       return token_id_str_INEQUALITY_ABSOLUTE;
   case QUEX_TKN_INEQUALITY_RELATIVE:       return token_id_str_INEQUALITY_RELATIVE;
   case QUEX_TKN_LOGIC_AND:                 return token_id_str_LOGIC_AND;
   case QUEX_TKN_LOGIC_OR:                  return token_id_str_LOGIC_OR;
   case QUEX_TKN_LOWER:                     return token_id_str_LOWER;
   case QUEX_TKN_LOWER_EQUAL:               return token_id_str_LOWER_EQUAL;
   case QUEX_TKN_MODULO:                    return token_id_str_MODULO;
   case QUEX_TKN_MULTIPLICATION:            return token_id_str_MULTIPLICATION;
   case QUEX_TKN_NEGATION:                  return token_id_str_NEGATION;
   case QUEX_TKN_NUMBER:                    return token_id_str_NUMBER;
   case QUEX_TKN_OUTPUT:                    return token_id_str_OUTPUT;
   case QUEX_TKN_PARENTHESIS_BEGINNING:     return token_id_str_PARENTHESIS_BEGINNING;
   case QUEX_TKN_PARENTHESIS_END:           return token_id_str_PARENTHESIS_END;
   case QUEX_TKN_SERIALIZE:                 return token_id_str_SERIALIZE;
   case QUEX_TKN_STATEMENT_END:             return token_id_str_STATEMENT_END;
   case QUEX_TKN_STRING:                    return token_id_str_STRING;
   case QUEX_TKN_STRING_ABSOLUTE_BEGINNING: return token_id_str_STRING_ABSOLUTE_BEGINNING;
   case QUEX_TKN_STRING_ABSOLUTE_END:       return token_id_str_STRING_ABSOLUTE_END;
   case QUEX_TKN_STRING_RELATIVE_BEGINNING: return token_id_str_STRING_RELATIVE_BEGINNING;
   case QUEX_TKN_STRING_RELATIVE_END:       return token_id_str_STRING_RELATIVE_END;
   case QUEX_TKN_SUBSTRACTION:              return token_id_str_SUBSTRACTION;
   case QUEX_TKN_TAB:                       return token_id_str_TAB;

   }
}

QUEX_NAMESPACE_TOKEN_CLOSE

