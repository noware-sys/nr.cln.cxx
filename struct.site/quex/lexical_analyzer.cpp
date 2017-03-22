#include "lexical_analyzer"
#include <quex/code_base/analyzer/C-adaptions.h>
QUEX_NAMESPACE_MAIN_OPEN
/* Global */QUEX_NAME(Mode)  QUEX_NAME(GLOBAL);
/* Global */QUEX_NAME(Mode)  QUEX_NAME(STRING_ABSOLUTE);
/* Global */QUEX_NAME(Mode)  QUEX_NAME(STRING_RELATIVE);
#ifndef __QUEX_INDICATOR_DUMPED_TOKEN_ID_DEFINED
    static QUEX_TYPE_TOKEN_ID    QUEX_NAME_TOKEN(DumpedTokenIdObject);
#endif
#define self  (*(QUEX_TYPE_DERIVED_ANALYZER*)me)
#define __self_result_token_id    QUEX_NAME_TOKEN(DumpedTokenIdObject)

void
QUEX_NAME(GLOBAL_on_entry)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* FromMode) {
    (void)me;
    (void)FromMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(GLOBAL).has_entry_from(FromMode);
#   endif

}

void
QUEX_NAME(GLOBAL_on_exit)(QUEX_TYPE_ANALYZER* me, const QUEX_NAME(Mode)* ToMode)  {
    (void)me;
    (void)ToMode;
#   ifdef QUEX_OPTION_RUNTIME_MODE_TRANSITION_CHECK
    QUEX_NAME(GLOBAL).has_exit_to(ToMode);
#   endif

}

#if defined(QUEX_OPTION_INDENTATION_TRIGGER) 
void
QUEX_NAME(GLOBAL_on_indentation)(QUEX_TYPE_ANALYZER*    me, 
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
QUEX_NAME(GLOBAL_has_base)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_GLOBAL): return true;
    default:
    ;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): GLOBAL, \n", Mode->name);
    __quex_assert(false);
    return false;
    
}
bool
QUEX_NAME(GLOBAL_has_entry_from)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;
    return true; /* default */
}
bool
QUEX_NAME(GLOBAL_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
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
                QUEX_NAME(GLOBAL_counter)((ME), (BEGIN), (END));     \
                __quex_debug_counter();       \
            } while(0)
#else
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) /* empty */
#endif
#ifdef __QUEX_OPTION_COUNTER
static void
QUEX_NAME(GLOBAL_counter)(QUEX_TYPE_ANALYZER* me, QUEX_TYPE_CHARACTER* LexemeBegin, QUEX_TYPE_CHARACTER* LexemeEnd)
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
QUEX_NAME(GLOBAL_analyzer_function)(QUEX_TYPE_ANALYZER* me) 
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
    const QUEX_TYPE_CHARACTER      Skipper750_Closer[2]           = { 0x2A, 0x2F,  };
    const QUEX_TYPE_CHARACTER      Skipper750_Opener[2]           = { 0x2F, 0x2A,  };
    const QUEX_TYPE_CHARACTER*     Skipper750_Opener_it           = 0x0;
    QUEX_TYPE_ACCEPTANCE_ID        last_acceptance               /* un-initilized */;
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
    size_t                         counter                        = 0;
    QUEX_TYPE_CHARACTER_POSITION   reference_p                    = (QUEX_TYPE_CHARACTER_POSITION)0x0;
    const QUEX_TYPE_CHARACTER*     Skipper750_Closer_it           = 0x0;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    const size_t                   PositionRegisterN              = (size_t)1;
    QUEX_TYPE_CHARACTER_POSITION   position[1]                    = { 0};
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    const QUEX_TYPE_CHARACTER*     Skipper750_CloserEnd           = Skipper750_Closer + (ptrdiff_t)2;
    const QUEX_TYPE_CHARACTER*     Skipper750_OpenerEnd           = Skipper750_Opener + (ptrdiff_t)2;
#   ifdef QUEX_OPTION_COLUMN_NUMBER_COUNTING
#   endif /* QUEX_OPTION_COLUMN_NUMBER_COUNTING */
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */
#   define GLOBAL             (QUEX_NAME(GLOBAL))
#   define STRING_ABSOLUTE    (QUEX_NAME(STRING_ABSOLUTE))
#   define STRING_RELATIVE    (QUEX_NAME(STRING_RELATIVE))

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
_1049: /* INIT_STATE_TRANSITION_BLOCK */
    { last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1); __quex_debug("last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1)\n"); }
    input = *(me->buffer._input_p);
    __quex_debug("Init State\n");
    __quex_debug_state(985);
    if( input < 0x2D ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 985, 749);
            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: goto _996;
            case 0x9: goto _1050;
            case 0xA: goto _1051;
            case 0xB: 
            case 0xC: goto _996;
            case 0xD: goto _1052;
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
            case 0x1F: goto _996;
            case 0x20: goto _1052;
            case 0x21: goto _1053;
            case 0x22: goto _996;
            case 0x23: goto _993;
            case 0x24: goto _988;
            case 0x25: goto _1054;
            case 0x26: 
            case 0x27: 
            case 0x28: 
            case 0x29: goto _996;
            case 0x2A: goto _1055;
            case 0x2B: goto _1056;
            case 0x2C: goto _996;

        }
    } else {
        if( input < 0x5C ) {
            switch( input ) {
                case 0x2D: goto _1057;
                case 0x2E: goto _1058;
                case 0x2F: goto _994;
                case 0x30: 
                case 0x31: 
                case 0x32: 
                case 0x33: 
                case 0x34: 
                case 0x35: 
                case 0x36: 
                case 0x37: 
                case 0x38: 
                case 0x39: goto _1059;
                case 0x3A: goto _996;
                case 0x3B: goto _1060;
                case 0x3C: goto _996;
                case 0x3D: goto _1061;
                case 0x3E: 
                case 0x3F: 
                case 0x40: 
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
                case 0x5B: goto _996;

            }
        } else {
            if( input < 0x66 ) {
                switch( input ) {
                    case 0x5C: goto _990;
                    case 0x5D: goto _996;
                    case 0x5E: goto _1062;
                    case 0x5F: 
                    case 0x60: 
                    case 0x61: 
                    case 0x62: 
                    case 0x63: 
                    case 0x64: goto _996;
                    case 0x65: goto _1004;

                }
            } else {
                if( input < 0x7B ) {
                    goto _996;
                } else if( input == 0x7B ) {
                    goto _1063;
                } else if( input == 0x7C ) {
                    goto _996;
                } else if( input == 0x7D ) {
                    goto _1064;
                } else {
                    goto _996;
                }
            }
        }
    }
    __quex_debug_drop_out(985);

goto _1066; /* TERMINAL_FAILURE */

_985:


    ++(me->buffer._input_p);
    goto _1049;


    __quex_assert_no_passage();
_1067: /* (1022 from 1028) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1022: /* (1022 from 1022) (1022 from 1026) (1022 from 994) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1022);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1022, 1068);
        case 0xA: goto _1023;
        case 0xD: goto _1025;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1022;
        case 0x5C: goto _1024;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1022;

    }
_1068:
    __quex_debug_drop_out(1022);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1066; /* TERMINAL_FAILURE */
    case 716: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_716;

}

    __quex_assert_no_passage();
_1007: /* (1007 from 986) (1007 from 987) (1007 from 988) (1007 from 989) (1007 from 991) (1007 from 992) (1007 from 993) (1007 from 994) (1007 from 995) (1007 from 996) (1007 from 997) (1007 from 998) (1007 from 999) (1007 from 1000) (1007 from 1001) (1007 from 1002) (1007 from 1003) (1007 from 1004) (1007 from 1005) (1007 from 1006) */

    ++(me->buffer._input_p);
    __quex_debug_state(1007);
    __quex_debug_drop_out(1007);
goto TERMINAL_740;

    __quex_assert_no_passage();
_1008: /* (1008 from 986) (1008 from 988) (1008 from 987) (1008 from 990) (1008 from 989) (1008 from 992) (1008 from 991) (1008 from 993) (1008 from 996) (1008 from 995) (1008 from 998) (1008 from 997) (1008 from 1000) (1008 from 999) (1008 from 1002) (1008 from 1001) (1008 from 1004) (1008 from 1003) (1008 from 1006) (1008 from 1005) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1008);
    if( input >= 0x30 ) {
        goto _1012;
    } else if( input == 0x2F ) {

    } else if( input >= 0x2 ) {
        goto _1012;
    } else if( input == 0x1 ) {

    } else {
        QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1008, 1070);
    }
_1070:
    __quex_debug_drop_out(1008);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1066; /* TERMINAL_FAILURE */
    case 738: me->buffer._input_p -= 1;  goto TERMINAL_738;
    case 712: me->buffer._input_p -= 1;  goto TERMINAL_712;
    case 713: me->buffer._input_p -= 1;  goto TERMINAL_713;
    case 714: me->buffer._input_p -= 1;  goto TERMINAL_714;
    case 720: me->buffer._input_p -= 1;  goto TERMINAL_720;
    case 721: me->buffer._input_p -= 1;  goto TERMINAL_721;
    case 726: me->buffer._input_p -= 1;  goto TERMINAL_726;
    case 727: me->buffer._input_p -= 1;  goto TERMINAL_727;
    case 728: me->buffer._input_p -= 1;  goto TERMINAL_728;
    case 729: me->buffer._input_p -= 1;  goto TERMINAL_729;
    case 730: me->buffer._input_p -= 1;  goto TERMINAL_730;
    case 732: me->buffer._input_p -= 1;  goto TERMINAL_732;
    case 733: me->buffer._input_p -= 1;  goto TERMINAL_733;
    case 734: me->buffer._input_p -= 1;  goto TERMINAL_734;
    case 735: me->buffer._input_p -= 1;  goto TERMINAL_735;

}

    __quex_assert_no_passage();
_1011: /* (1011 from 987) (1011 from 988) (1011 from 989) (1011 from 986) (1011 from 995) (1011 from 996) (1011 from 997) (1011 from 998) (1011 from 991) (1011 from 992) (1011 from 993) (1011 from 994) (1011 from 1003) (1011 from 1004) (1011 from 1005) (1011 from 1006) (1011 from 999) (1011 from 1000) (1011 from 1001) (1011 from 1002) */

    ++(me->buffer._input_p);
    __quex_debug_state(1011);
    __quex_debug_drop_out(1011);
goto TERMINAL_739;

    __quex_assert_no_passage();
_1072: /* (1024 from 1028) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1024: /* (1024 from 1024) (1024 from 1026) (1024 from 1027) (1024 from 1022) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1024);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1024, 1073);
        case 0x9: goto _1024;
        case 0xA: goto _1026;
        case 0xD: 
        case 0x20: goto _1024;

    }
_1073:
    __quex_debug_drop_out(1024);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1066; /* TERMINAL_FAILURE */
    case 716: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_716;

}

    __quex_assert_no_passage();
_1046: /* (1046 from 1046) (1046 from 988) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1046);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1046, 1074);
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
        case 0x7A: goto _1046;

    }
_1074:
    __quex_debug_drop_out(1046);
goto TERMINAL_719;

    __quex_assert_no_passage();
_1031: /* (1031 from 1031) (1031 from 993) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1031);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1031, 1075);
        case 0x9: 
        case 0xA: 
        case 0xD: 
        case 0x20: goto _1031;
        case 0x69: goto _1030;
        case 0x73: goto _1029;

    }
_1075:
    __quex_debug_drop_out(1031);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1010: /* (1010 from 1010) (1010 from 1009) (1010 from 1006) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1010);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1010, 1076);
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1010;

    }
_1076:
    __quex_debug_drop_out(1010);
goto TERMINAL_738;

    __quex_assert_no_passage();
_1009: /* (1009 from 1001) (1009 from 1009) (1009 from 989) (1009 from 1006) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1009);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1009, 1077);
        case 0x2C: 
        case 0x2E: goto _1010;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1009;

    }
_1077:
    __quex_debug_drop_out(1009);
goto TERMINAL_738;

    __quex_assert_no_passage();
_1078: /* (1028 from 1028) (1028 from 1027) (1028 from 1026) */
    { last_acceptance = 716; __quex_debug("last_acceptance = 716\n"); }

_1028:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1028);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1028, 1079);
        case 0x9: goto _1072;
        case 0xA: goto _1078;
        case 0xD: goto _1080;
        case 0x20: goto _1072;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1067;
        case 0x5C: goto _1072;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1067;

    }
_1079:
    __quex_debug_drop_out(1028);
goto TERMINAL_716;

    __quex_assert_no_passage();
_1012: /* (1012 from 1008) */

    ++(me->buffer._input_p);
    __quex_debug_state(1012);
    __quex_debug_drop_out(1012);
goto TERMINAL_731;

    __quex_assert_no_passage();
_1080: /* (1027 from 1028) */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_1027: /* (1027 from 1026) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1027);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1027, 1082);
        case 0x9: goto _1024;
        case 0xA: goto _1078;
        case 0xD: 
        case 0x20: goto _1024;

    }
_1082:
    __quex_debug_drop_out(1027);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1066; /* TERMINAL_FAILURE */
    case 716: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_716;

}

    __quex_assert_no_passage();
_1029: /* (1029 from 993) (1029 from 1031) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1029);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1029, 1083);
        case 0x65: goto _1038;

    }
_1083:
    __quex_debug_drop_out(1029);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1030: /* (1030 from 993) (1030 from 1031) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1030);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1030, 1084);
        case 0x6E: goto _1032;

    }
_1084:
    __quex_debug_drop_out(1030);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1023: /* (1023 from 1025) (1023 from 1022) */

    ++(me->buffer._input_p);
    __quex_debug_state(1023);
    __quex_debug_drop_out(1023);
goto TERMINAL_716;

    __quex_assert_no_passage();
_1025: /* (1025 from 1022) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1025);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1025, 1086);
        case 0xA: goto _1023;

    }
_1086:
    __quex_debug_drop_out(1025);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1066; /* TERMINAL_FAILURE */
    case 716: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_716;

}

    __quex_assert_no_passage();
_1026: /* (1026 from 1024) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1026);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1026, 1087);
        case 0x9: goto _1024;
        case 0xA: goto _1078;
        case 0xD: goto _1027;
        case 0x20: goto _1024;
        case 0x28: 
        case 0x29: 
        case 0x44: 
        case 0x45: 
        case 0x49: 
        case 0x4C: 
        case 0x4E: 
        case 0x57: goto _1022;
        case 0x5C: goto _1024;
        case 0x5F: 
        case 0x65: 
        case 0x69: 
        case 0x6E: 
        case 0x72: 
        case 0x73: 
        case 0x76: 
        case 0x7B: 
        case 0x7D: goto _1022;

    }
_1087:
    __quex_debug_drop_out(1026);
switch( last_acceptance ) {
    case ((QUEX_TYPE_ACCEPTANCE_ID)-1):  goto _1066; /* TERMINAL_FAILURE */
    case 716: __quex_assert(position[0] != 0x0);
me->buffer._input_p = position[0];
 goto TERMINAL_716;

}

    __quex_assert_no_passage();
_1032: /* (1032 from 1030) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1032);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1032, 1088);
        case 0x63: goto _1033;

    }
_1088:
    __quex_debug_drop_out(1032);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1033: /* (1033 from 1032) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1033);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1033, 1089);
        case 0x6C: goto _1034;

    }
_1089:
    __quex_debug_drop_out(1033);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1034: /* (1034 from 1033) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1034);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1034, 1090);
        case 0x75: goto _1035;

    }
_1090:
    __quex_debug_drop_out(1034);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1035: /* (1035 from 1034) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1035);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1035, 1091);
        case 0x64: goto _1036;

    }
_1091:
    __quex_debug_drop_out(1035);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1036: /* (1036 from 1035) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1036);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1036, 1092);
        case 0x65: goto _1037;

    }
_1092:
    __quex_debug_drop_out(1036);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1037: /* (1037 from 1036) */

    ++(me->buffer._input_p);
    __quex_debug_state(1037);
    __quex_debug_drop_out(1037);
goto TERMINAL_718;

    __quex_assert_no_passage();
_1038: /* (1038 from 1029) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1038);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1038, 1094);
        case 0x72: goto _1039;

    }
_1094:
    __quex_debug_drop_out(1038);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1039: /* (1039 from 1038) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1039);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1039, 1095);
        case 0x69: goto _1040;

    }
_1095:
    __quex_debug_drop_out(1039);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1040: /* (1040 from 1039) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1040);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1040, 1096);
        case 0x61: goto _1041;

    }
_1096:
    __quex_debug_drop_out(1040);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1041: /* (1041 from 1040) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1041);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1041, 1097);
        case 0x6C: goto _1042;

    }
_1097:
    __quex_debug_drop_out(1041);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1042: /* (1042 from 1041) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1042);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1042, 1098);
        case 0x69: goto _1043;

    }
_1098:
    __quex_debug_drop_out(1042);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1043: /* (1043 from 1042) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1043);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1043, 1099);
        case 0x7A: goto _1044;

    }
_1099:
    __quex_debug_drop_out(1043);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1044: /* (1044 from 1043) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1044);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1044, 1100);
        case 0x65: goto _1045;

    }
_1100:
    __quex_debug_drop_out(1044);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1045: /* (1045 from 1044) */

    ++(me->buffer._input_p);
    __quex_debug_state(1045);
    __quex_debug_drop_out(1045);
goto TERMINAL_717;

    __quex_assert_no_passage();
_1047: /* (1047 from 987) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1047);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1047, 1102);
        case 0x3D: goto _1048;

    }
_1102:
    __quex_debug_drop_out(1047);
goto TERMINAL_724;

    __quex_assert_no_passage();
_1048: /* (1048 from 1047) */

    ++(me->buffer._input_p);
    __quex_debug_state(1048);
    __quex_debug_drop_out(1048);
goto TERMINAL_725;

    __quex_assert_no_passage();
_1013: /* (1013 from 1004) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1013);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1013, 1104);
        case 0x64: goto _1017;

    }
_1104:
    __quex_debug_drop_out(1013);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1014: /* (1014 from 1004) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1014);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1014, 1105);
        case 0x68: goto _1015;

    }
_1105:
    __quex_debug_drop_out(1014);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1015: /* (1015 from 1014) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1015);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1015, 1106);
        case 0x6F: goto _1016;

    }
_1106:
    __quex_debug_drop_out(1015);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1016: /* (1016 from 1015) */

    ++(me->buffer._input_p);
    __quex_debug_state(1016);
    __quex_debug_drop_out(1016);
goto TERMINAL_736;

    __quex_assert_no_passage();
_1017: /* (1017 from 1013) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1017);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1017, 1108);
        case 0x6C: goto _1018;

    }
_1108:
    __quex_debug_drop_out(1017);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1018: /* (1018 from 1017) */

    ++(me->buffer._input_p);
    __quex_debug_state(1018);
    __quex_debug_drop_out(1018);
goto TERMINAL_737;

    __quex_assert_no_passage();
_1019: /* (1019 from 997) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1019);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1019, 1110);
        case 0x3D: goto _1020;

    }
_1110:
    __quex_debug_drop_out(1019);
goto TERMINAL_722;

    __quex_assert_no_passage();
_1020: /* (1020 from 1019) */

    ++(me->buffer._input_p);
    __quex_debug_state(1020);
    __quex_debug_drop_out(1020);
goto TERMINAL_723;

    __quex_assert_no_passage();
_1021: /* (1021 from 994) */

    ++(me->buffer._input_p);
    __quex_debug_state(1021);
    __quex_debug_drop_out(1021);
goto TERMINAL_715;

    __quex_assert_no_passage();
_1064: /* (986 from 985) */
    { last_acceptance = 735; __quex_debug("last_acceptance = 735\n"); }

_986:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(986);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 986, 1113);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;

    }
_1113:
    __quex_debug_drop_out(986);
goto TERMINAL_735;

    __quex_assert_no_passage();
_1053: /* (987 from 985) */
    { last_acceptance = 726; __quex_debug("last_acceptance = 726\n"); }

_987:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(987);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 987, 1114);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;
        case 0x3D: goto _1047;

    }
_1114:
    __quex_debug_drop_out(987);
goto TERMINAL_726;

    __quex_assert_no_passage();
_988: /* (988 from 985) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(988);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 988, 1115);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;
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
        case 0x7A: goto _1046;

    }
_1115:
    __quex_debug_drop_out(988);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1057: /* (989 from 985) */
    { last_acceptance = 729; __quex_debug("last_acceptance = 729\n"); }

_989:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(989);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 989, 1116);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1009;

    }
_1116:
    __quex_debug_drop_out(989);
goto TERMINAL_729;

    __quex_assert_no_passage();
_990: /* (990 from 985) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(990);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 990, 1117);
        case 0x2F: goto _1008;

    }
_1117:
    __quex_debug_drop_out(990);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1051: /* (991 from 985) */
    { last_acceptance = 714; __quex_debug("last_acceptance = 714\n"); }

_991:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(991);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 991, 1118);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;

    }
_1118:
    __quex_debug_drop_out(991);
goto TERMINAL_714;

    __quex_assert_no_passage();
_1063: /* (992 from 985) */
    { last_acceptance = 734; __quex_debug("last_acceptance = 734\n"); }

_992:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(992);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 992, 1119);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;

    }
_1119:
    __quex_debug_drop_out(992);
goto TERMINAL_734;

    __quex_assert_no_passage();
_993: /* (993 from 985) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(993);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 993, 1120);
        case 0x9: 
        case 0xA: 
        case 0xD: 
        case 0x20: goto _1031;
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;
        case 0x69: goto _1030;
        case 0x73: goto _1029;

    }
_1120:
    __quex_debug_drop_out(993);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_994: /* (994 from 985) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(994);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 994, 1121);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2A: goto _1021;
        case 0x2F: goto _1022;

    }
_1121:
    __quex_debug_drop_out(994);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1054: /* (995 from 985) */
    { last_acceptance = 733; __quex_debug("last_acceptance = 733\n"); }

_995:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(995);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 995, 1122);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;

    }
_1122:
    __quex_debug_drop_out(995);
goto TERMINAL_733;

    __quex_assert_no_passage();
_996: /* (996 from 985) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(996);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 996, 1123);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;

    }
_1123:
    __quex_debug_drop_out(996);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1061: /* (997 from 985) */
    { last_acceptance = 727; __quex_debug("last_acceptance = 727\n"); }

_997:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(997);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 997, 1124);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;
        case 0x3D: goto _1019;

    }
_1124:
    __quex_debug_drop_out(997);
goto TERMINAL_727;

    __quex_assert_no_passage();
_1062: /* (998 from 985) */
    { last_acceptance = 732; __quex_debug("last_acceptance = 732\n"); }

_998:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(998);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 998, 1125);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;

    }
_1125:
    __quex_debug_drop_out(998);
goto TERMINAL_732;

    __quex_assert_no_passage();
_1050: /* (999 from 985) */
    { last_acceptance = 713; __quex_debug("last_acceptance = 713\n"); }

_999:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(999);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 999, 1126);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;

    }
_1126:
    __quex_debug_drop_out(999);
goto TERMINAL_713;

    __quex_assert_no_passage();
_1055: /* (1000 from 985) */
    { last_acceptance = 730; __quex_debug("last_acceptance = 730\n"); }

_1000:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1000);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1000, 1127);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;

    }
_1127:
    __quex_debug_drop_out(1000);
goto TERMINAL_730;

    __quex_assert_no_passage();
_1056: /* (1001 from 985) */
    { last_acceptance = 728; __quex_debug("last_acceptance = 728\n"); }

_1001:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1001);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1001, 1128);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1009;

    }
_1128:
    __quex_debug_drop_out(1001);
goto TERMINAL_728;

    __quex_assert_no_passage();
_1052: /* (1002 from 985) */
    { last_acceptance = 712; __quex_debug("last_acceptance = 712\n"); }

_1002:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1002);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1002, 1129);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;

    }
_1129:
    __quex_debug_drop_out(1002);
goto TERMINAL_712;

    __quex_assert_no_passage();
_1060: /* (1003 from 985) */
    { last_acceptance = 720; __quex_debug("last_acceptance = 720\n"); }

_1003:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1003);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1003, 1130);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;

    }
_1130:
    __quex_debug_drop_out(1003);
goto TERMINAL_720;

    __quex_assert_no_passage();
_1004: /* (1004 from 985) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1004);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1004, 1131);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;
        case 0x63: goto _1014;
        case 0x6E: goto _1013;

    }
_1131:
    __quex_debug_drop_out(1004);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1058: /* (1005 from 985) */
    { last_acceptance = 721; __quex_debug("last_acceptance = 721\n"); }

_1005:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1005);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1005, 1132);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2F: goto _1008;

    }
_1132:
    __quex_debug_drop_out(1005);
goto TERMINAL_721;

    __quex_assert_no_passage();
_1059: /* (1006 from 985) */
    { last_acceptance = 738; __quex_debug("last_acceptance = 738\n"); }

_1006:

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1006);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1006, 1133);
        case 0x22: goto _1007;
        case 0x27: goto _1011;
        case 0x2C: 
        case 0x2E: goto _1010;
        case 0x2F: goto _1008;
        case 0x30: 
        case 0x31: 
        case 0x32: 
        case 0x33: 
        case 0x34: 
        case 0x35: 
        case 0x36: 
        case 0x37: 
        case 0x38: 
        case 0x39: goto _1009;

    }
_1133:
    __quex_debug_drop_out(1006);
goto TERMINAL_738;
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

TERMINAL_712:
    __quex_debug("* terminal 712:   <skip: ... (check also base modes)>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 131 "lexical_analyzer.qx"
    goto __SKIP;
    
#   line 1806 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_713:
    __quex_debug("* terminal 713:   <skip: ... (check also base modes)>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4);

    {
#   line 131 "lexical_analyzer.qx"
    goto __SKIP;
    
#   line 1821 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_714:
    __quex_debug("* terminal 714:   <skip>\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_LINES_ADD(1);
__QUEX_IF_COUNT_COLUMNS_SET(1);
    {
__SKIP:
    /* Character Set Skipper: '['\t', '\n'], '\r', ' '' */
    QUEX_BUFFER_ASSERT_CONSISTENCY(&me->buffer);
__QUEX_IF_COUNT_COLUMNS(reference_p = me->buffer._input_p);
    while( 1 + 1 == 2 ) {
_746:
        if( (*me->buffer._input_p) < 0xB ) {
            switch( (*me->buffer._input_p) ) {
                case 0x0: QUEX_GOTO_RELOAD(_748, 746, 749);
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
_748:

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

TERMINAL_715:
    __quex_debug("* terminal 715:   {D_COMMENT_STREAM_BEGINNING}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
    Skipper750_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper750_Opener;
    Skipper750_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper750_Closer;
    /* text_end                           = QUEX_NAME(Buffer_text_end)(&me->buffer); */
    __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));


_751:

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
                    goto _752;
            }
            if( input == *Skipper750_Closer_it ) {
                    ++Skipper750_Closer_it;
                    if( Skipper750_Closer_it == Skipper750_CloserEnd ) {
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
                        Skipper750_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper750_Opener;
                        Skipper750_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper750_Closer;
                        goto CONTINUE_750;
                    }
            } else {
                    Skipper750_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper750_Closer;
            }
            if( input == *Skipper750_Opener_it ) {
                    ++Skipper750_Opener_it;
                    if( Skipper750_Opener_it == Skipper750_OpenerEnd ) {
                        ++counter;
                        Skipper750_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper750_Opener;
                        Skipper750_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper750_Closer;
                        goto CONTINUE_750;
                    }
            } else {
                    Skipper750_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper750_Opener;
            }
CONTINUE_750:

    __QUEX_IF_COUNT_IF( input == (QUEX_TYPE_CHARACTER)'\n' ) {
            __QUEX_IF_COUNT_LINES_ADD((size_t)1);
            __QUEX_IF_COUNT_COLUMNS_SET((size_t)0);
            __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));
    }

            ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
    }

_752:
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
            goto _751; /* End of range reached.             */
    }
    /* Here, either the loading failed or it is not enough space to carry a closing delimiter */
    me->buffer._input_p = me->buffer._lexeme_start_p;
    QUEX_ERROR_EXIT("\nLexical analyzer mode 'GLOBAL':\n"
                        "End of file occurred before closing skip range delimiter!\n"                "The 'on_skip_range_open' handler has not been specified.");

    }
    goto __REENTRY_PREPARATION;

TERMINAL_716:
    __quex_debug("* terminal 716:   {D_COMMENT_BLOCK}([inverse({D_NEW_LINE})]|({D_BACKSLASH}{D_WHITESPACE}*{D_NEW_LINE}))*{D_NEW_LINE}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 138 "lexical_analyzer.qx"
    
        // We are within a comment. Do not do anything.
    
    
#   line 2024 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_717:
    __quex_debug("* terminal 717:   {D_PRAGMA}{D_WHITESPACE}*\"serialize\"\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 147 "lexical_analyzer.qx"
    self_send(QUEX_TKN_SERIALIZE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2037 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_718:
    __quex_debug("* terminal 718:   {D_PRAGMA}{D_WHITESPACE}*\"include\"\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 148 "lexical_analyzer.qx"
    self_send(QUEX_TKN_INCLUDE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2050 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_719:
    __quex_debug("* terminal 719:   {D_IDENTIFIER}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
    {
#   line 149 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_IDENTIFIER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2065 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_720:
    __quex_debug("* terminal 720:   {D_STATEMENT_END}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 150 "lexical_analyzer.qx"
    self_send(QUEX_TKN_STATEMENT_END);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2079 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_721:
    __quex_debug("* terminal 721:   {D_CONCATENATION}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 151 "lexical_analyzer.qx"
    self_send(QUEX_TKN_CONCATENATION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2093 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_722:
    __quex_debug("* terminal 722:   \"==\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
#   line 154 "lexical_analyzer.qx"
    self_send(QUEX_TKN_EQUALITY_RELATIVE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2107 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_723:
    __quex_debug("* terminal 723:   \"===\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(3);
    {
#   line 155 "lexical_analyzer.qx"
    self_send(QUEX_TKN_EQUALITY_ABSOLUTE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2121 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_724:
    __quex_debug("* terminal 724:   \"!=\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
    {
#   line 156 "lexical_analyzer.qx"
    self_send(QUEX_TKN_INEQUALITY_RELATIVE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2135 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_725:
    __quex_debug("* terminal 725:   \"!==\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(3);
    {
#   line 157 "lexical_analyzer.qx"
    self_send(QUEX_TKN_INEQUALITY_ABSOLUTE);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2149 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_726:
    __quex_debug("* terminal 726:   \"!\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 158 "lexical_analyzer.qx"
    self_send(QUEX_TKN_NEGATION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2163 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_727:
    __quex_debug("* terminal 727:   \"=\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 159 "lexical_analyzer.qx"
    self_send(QUEX_TKN_ASSIGNMENT);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2177 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_728:
    __quex_debug("* terminal 728:   \"+\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 160 "lexical_analyzer.qx"
    self_send(QUEX_TKN_ADDITION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2191 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_729:
    __quex_debug("* terminal 729:   \"-\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 161 "lexical_analyzer.qx"
    self_send(QUEX_TKN_SUBSTRACTION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2205 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_730:
    __quex_debug("* terminal 730:   \"*\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 162 "lexical_analyzer.qx"
    self_send(QUEX_TKN_MULTIPLICATION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2219 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_731:
    __quex_debug("* terminal 731:   {D_DIVISION}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 163 "lexical_analyzer.qx"
    self_send(QUEX_TKN_DIVISION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2232 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_732:
    __quex_debug("* terminal 732:   \"^\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 164 "lexical_analyzer.qx"
    self_send(QUEX_TKN_EXPONENTIATION);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2246 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_733:
    __quex_debug("* terminal 733:   \"%\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 165 "lexical_analyzer.qx"
    self_send(QUEX_TKN_MODULO);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2260 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_734:
    __quex_debug("* terminal 734:   \"{\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 167 "lexical_analyzer.qx"
    self_send(QUEX_TKN_BRACE_BEGINNING);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2274 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_735:
    __quex_debug("* terminal 735:   \"}\"\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
    {
#   line 168 "lexical_analyzer.qx"
    self_send(QUEX_TKN_BRACE_END);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2288 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_736:
    __quex_debug("* terminal 736:   {D_OUTPUT}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(4);
    {
#   line 170 "lexical_analyzer.qx"
    self_send(QUEX_TKN_OUTPUT);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2302 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_737:
    __quex_debug("* terminal 737:   {D_ENDL}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(4);
    {
#   line 171 "lexical_analyzer.qx"
    self_send(QUEX_TKN_ENDL);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2316 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_738:
    __quex_debug("* terminal 738:   {D_NUMBER}\n");
    __QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
    {
#   line 174 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_NUMBER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2331 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_739:
    __quex_debug("* terminal 739:   {D_QUOTE_SINGLE}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 180 "lexical_analyzer.qx"
    QUEX_NAME(push_mode)(&self, &STRING_ABSOLUTE);self_send(QUEX_TKN_STRING_ABSOLUTE_BEGINNING);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2344 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_740:
    __quex_debug("* terminal 740:   {D_QUOTE_DOUBLE}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 181 "lexical_analyzer.qx"
    QUEX_NAME(push_mode)(&self, &STRING_RELATIVE);self_send(QUEX_TKN_STRING_RELATIVE_BEGINNING);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2357 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;


_1066: /* TERMINAL: FAILURE */
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
#   line 123 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_FAILURE);
    
        RETURN;
    
    
#   line 2385 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION_2;


/* TERMINAL: END_OF_STREAM */
_749:
__QUEX_IF_COUNT_SHIFT_VALUES();
    {
#   line 116 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_TERMINATION);
    
        RETURN;
    
    
#   line 2402 "lexical_analyzer.cpp"

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
        case 746: { goto _746; }
        case 748: { goto _748; }
        case 749: { goto _749; }
        case 751: { goto _751; }
        case 985: { goto _985; }
        case 986: { goto _986; }
        case 987: { goto _987; }
        case 988: { goto _988; }
        case 989: { goto _989; }
        case 990: { goto _990; }
        case 991: { goto _991; }
        case 992: { goto _992; }
        case 993: { goto _993; }
        case 994: { goto _994; }
        case 995: { goto _995; }
        case 996: { goto _996; }
        case 997: { goto _997; }
        case 998: { goto _998; }
        case 999: { goto _999; }
        case 1000: { goto _1000; }
        case 1001: { goto _1001; }
        case 1002: { goto _1002; }
        case 1003: { goto _1003; }
        case 1004: { goto _1004; }
        case 1005: { goto _1005; }
        case 1006: { goto _1006; }
        case 1007: { goto _1007; }
        case 1008: { goto _1008; }
        case 1009: { goto _1009; }
        case 1010: { goto _1010; }
        case 1011: { goto _1011; }
        case 1012: { goto _1012; }
        case 1013: { goto _1013; }
        case 1014: { goto _1014; }
        case 1015: { goto _1015; }
        case 1016: { goto _1016; }
        case 1017: { goto _1017; }
        case 1018: { goto _1018; }
        case 1019: { goto _1019; }
        case 1020: { goto _1020; }
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
        case 1038: { goto _1038; }
        case 1039: { goto _1039; }
        case 1040: { goto _1040; }
        case 1041: { goto _1041; }
        case 1042: { goto _1042; }
        case 1043: { goto _1043; }
        case 1044: { goto _1044; }
        case 1045: { goto _1045; }
        case 1046: { goto _1046; }
        case 1047: { goto _1047; }
        case 1048: { goto _1048; }
        case 1050: { goto _1050; }
        case 1051: { goto _1051; }
        case 1052: { goto _1052; }
        case 1053: { goto _1053; }
        case 1054: { goto _1054; }
        case 1055: { goto _1055; }
        case 1056: { goto _1056; }
        case 1057: { goto _1057; }
        case 1058: { goto _1058; }
        case 1059: { goto _1059; }
        case 1060: { goto _1060; }
        case 1061: { goto _1061; }
        case 1062: { goto _1062; }
        case 1063: { goto _1063; }
        case 1064: { goto _1064; }
        case 1067: { goto _1067; }
        case 1068: { goto _1068; }
        case 1070: { goto _1070; }
        case 1072: { goto _1072; }
        case 1073: { goto _1073; }
        case 1074: { goto _1074; }
        case 1075: { goto _1075; }
        case 1076: { goto _1076; }
        case 1077: { goto _1077; }
        case 1078: { goto _1078; }
        case 1079: { goto _1079; }
        case 1080: { goto _1080; }
        case 1082: { goto _1082; }
        case 1083: { goto _1083; }
        case 1084: { goto _1084; }
        case 1086: { goto _1086; }
        case 1087: { goto _1087; }
        case 1088: { goto _1088; }
        case 1089: { goto _1089; }
        case 1090: { goto _1090; }
        case 1091: { goto _1091; }
        case 1092: { goto _1092; }
        case 1094: { goto _1094; }
        case 1095: { goto _1095; }
        case 1096: { goto _1096; }
        case 1097: { goto _1097; }
        case 1098: { goto _1098; }
        case 1099: { goto _1099; }
        case 1100: { goto _1100; }
        case 1102: { goto _1102; }
        case 1104: { goto _1104; }
        case 1105: { goto _1105; }
        case 1106: { goto _1106; }
        case 1108: { goto _1108; }
        case 1110: { goto _1110; }
        case 1113: { goto _1113; }
        case 1114: { goto _1114; }
        case 1115: { goto _1115; }
        case 1116: { goto _1116; }
        case 1117: { goto _1117; }
        case 1118: { goto _1118; }
        case 1119: { goto _1119; }
        case 1120: { goto _1120; }
        case 1121: { goto _1121; }
        case 1122: { goto _1122; }
        case 1123: { goto _1123; }
        case 1124: { goto _1124; }
        case 1125: { goto _1125; }
        case 1126: { goto _1126; }
        case 1127: { goto _1127; }
        case 1128: { goto _1128; }
        case 1129: { goto _1129; }
        case 1130: { goto _1130; }
        case 1131: { goto _1131; }
        case 1132: { goto _1132; }
        case 1133: { goto _1133; }

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
#   undef GLOBAL
#   undef STRING_ABSOLUTE
#   undef STRING_RELATIVE
#   undef self
}
#include <quex/code_base/temporary_macros_off>
#ifdef      __QUEX_COUNT_VOID
#   undef   __QUEX_COUNT_VOID
#endif
#ifdef      __QUEX_OPTION_COUNTER
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) \
            do {                              \
                QUEX_NAME(GLOBAL_counter)((ME), (BEGIN), (END));     \
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
#   define GLOBAL             (QUEX_NAME(GLOBAL))
#   define STRING_ABSOLUTE    (QUEX_NAME(STRING_ABSOLUTE))
#   define STRING_RELATIVE    (QUEX_NAME(STRING_RELATIVE))

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
_1153: /* INIT_STATE_TRANSITION_BLOCK */
    input = *(me->buffer._input_p);
    __quex_debug("Init State\n");
    __quex_debug_state(1148);
    if( input < 0xA ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1148, 749);
            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: 
            case 0x9: goto _1151;

        }
    } else {
        if( input == 0xA ) {
            goto _1149;
        } else if( input < 0x5C ) {
            goto _1151;
        } else if( input == 0x5C ) {
            goto _1150;
        } else {
            goto _1151;
        }
    }
    __quex_debug_drop_out(1148);

goto _1066; /* TERMINAL_FAILURE */

_1148:


    ++(me->buffer._input_p);
    goto _1153;


    __quex_assert_no_passage();
_1152: /* (1152 from 1151) (1152 from 1149) */

    ++(me->buffer._input_p);
    __quex_debug_state(1152);
    __quex_debug_drop_out(1152);
goto TERMINAL_741;

    __quex_assert_no_passage();
_1149: /* (1149 from 1148) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1149);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1149, 1156);
        case 0x27: goto _1152;

    }
_1156:
    __quex_debug_drop_out(1149);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1150: /* (1150 from 1148) */

    ++(me->buffer._input_p);
    __quex_debug_state(1150);
    __quex_debug_drop_out(1150);
goto TERMINAL_742;

    __quex_assert_no_passage();
_1151: /* (1151 from 1148) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1151);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1151, 1158);
        case 0x27: goto _1152;

    }
_1158:
    __quex_debug_drop_out(1151);
goto TERMINAL_742;
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

TERMINAL_741:
    __quex_debug("* terminal 741:   {D_QUOTE_SINGLE}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 201 "lexical_analyzer.qx"
    QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_STRING_ABSOLUTE_END);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2842 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_742:
    __quex_debug("* terminal 742:   {D_ANY_CHAR}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 203 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_CHARACTER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 2856 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;


_1066: /* TERMINAL: FAILURE */
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
#   line 123 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_FAILURE);
    
        RETURN;
    
    
#   line 2885 "lexical_analyzer.cpp"
    
#   line 206 "lexical_analyzer.qx"
    
        self_accumulator_add (Lexeme, LexemeEnd);
    
    
#   line 2892 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION_2;


/* TERMINAL: END_OF_STREAM */
_749:
__QUEX_IF_COUNT_SHIFT_VALUES();
    {
#   line 116 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_TERMINATION);
    
        RETURN;
    
    
#   line 2909 "lexical_analyzer.cpp"

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
        case 749: { goto _749; }
        case 1148: { goto _1148; }
        case 1149: { goto _1149; }
        case 1150: { goto _1150; }
        case 1151: { goto _1151; }
        case 1152: { goto _1152; }
        case 1156: { goto _1156; }
        case 1158: { goto _1158; }

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
#   undef GLOBAL
#   undef STRING_ABSOLUTE
#   undef STRING_RELATIVE
#   undef self
}
#include <quex/code_base/temporary_macros_off>
#ifdef      __QUEX_COUNT_VOID
#   undef   __QUEX_COUNT_VOID
#endif
#ifdef      __QUEX_OPTION_COUNTER
#    define __QUEX_COUNT_VOID(ME, BEGIN, END) \
            do {                              \
                QUEX_NAME(GLOBAL_counter)((ME), (BEGIN), (END));     \
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
#   define GLOBAL             (QUEX_NAME(GLOBAL))
#   define STRING_ABSOLUTE    (QUEX_NAME(STRING_ABSOLUTE))
#   define STRING_RELATIVE    (QUEX_NAME(STRING_RELATIVE))

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
_1177: /* INIT_STATE_TRANSITION_BLOCK */
    input = *(me->buffer._input_p);
    __quex_debug("Init State\n");
    __quex_debug_state(1172);
    if( input < 0xA ) {
        switch( input ) {
            case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1172, 749);
            case 0x2: 
            case 0x3: 
            case 0x4: 
            case 0x5: 
            case 0x6: 
            case 0x7: 
            case 0x8: 
            case 0x9: goto _1175;

        }
    } else {
        if( input == 0xA ) {
            goto _1173;
        } else if( input < 0x5C ) {
            goto _1175;
        } else if( input == 0x5C ) {
            goto _1174;
        } else {
            goto _1175;
        }
    }
    __quex_debug_drop_out(1172);

goto _1066; /* TERMINAL_FAILURE */

_1172:


    ++(me->buffer._input_p);
    goto _1177;


    __quex_assert_no_passage();
_1176: /* (1176 from 1175) (1176 from 1173) */

    ++(me->buffer._input_p);
    __quex_debug_state(1176);
    __quex_debug_drop_out(1176);
goto TERMINAL_743;

    __quex_assert_no_passage();
_1173: /* (1173 from 1172) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1173);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1173, 1180);
        case 0x22: goto _1176;

    }
_1180:
    __quex_debug_drop_out(1173);

goto _1066; /* TERMINAL_FAILURE */

    __quex_assert_no_passage();
_1174: /* (1174 from 1172) */

    ++(me->buffer._input_p);
    __quex_debug_state(1174);
    __quex_debug_drop_out(1174);
goto TERMINAL_744;

    __quex_assert_no_passage();
_1175: /* (1175 from 1172) */

    ++(me->buffer._input_p);
    input = *(me->buffer._input_p);
    __quex_debug_state(1175);
    switch( input ) {
        case 0x0: QUEX_GOTO_RELOAD(__RELOAD_FORWARD, 1175, 1182);
        case 0x22: goto _1176;

    }
_1182:
    __quex_debug_drop_out(1175);
goto TERMINAL_744;
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

TERMINAL_743:
    __quex_debug("* terminal 743:   {D_QUOTE_DOUBLE}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 227 "lexical_analyzer.qx"
    QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_STRING_RELATIVE_END);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3218 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;

TERMINAL_744:
    __quex_debug("* terminal 744:   {D_ANY_CHAR}\n");
    __QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
    {
#   line 229 "lexical_analyzer.qx"
    QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
    self_send(QUEX_TKN_CHARACTER);
    QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();
    
#   line 3232 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION;


_1066: /* TERMINAL: FAILURE */
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
#   line 123 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_FAILURE);
    
        RETURN;
    
    
#   line 3261 "lexical_analyzer.cpp"
    
#   line 232 "lexical_analyzer.qx"
    
        self_accumulator_add (Lexeme, LexemeEnd);
    
    
#   line 3268 "lexical_analyzer.cpp"

    }
    goto __REENTRY_PREPARATION_2;


/* TERMINAL: END_OF_STREAM */
_749:
__QUEX_IF_COUNT_SHIFT_VALUES();
    {
#   line 116 "lexical_analyzer.qx"
    
        self_send (QUEX_TKN_TERMINATION);
    
        RETURN;
    
    
#   line 3285 "lexical_analyzer.cpp"

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
        case 749: { goto _749; }
        case 1172: { goto _1172; }
        case 1173: { goto _1173; }
        case 1174: { goto _1174; }
        case 1175: { goto _1175; }
        case 1176: { goto _1176; }
        case 1180: { goto _1180; }
        case 1182: { goto _1182; }

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
#   undef GLOBAL
#   undef STRING_ABSOLUTE
#   undef STRING_RELATIVE
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
   static const char  token_id_str_IDENTIFIER[]                = "IDENTIFIER";
   static const char  token_id_str_INCLUDE[]                   = "INCLUDE";
   static const char  token_id_str_INEQUALITY_ABSOLUTE[]       = "INEQUALITY_ABSOLUTE";
   static const char  token_id_str_INEQUALITY_RELATIVE[]       = "INEQUALITY_RELATIVE";
   static const char  token_id_str_MODULO[]                    = "MODULO";
   static const char  token_id_str_MULTIPLICATION[]            = "MULTIPLICATION";
   static const char  token_id_str_NEGATION[]                  = "NEGATION";
   static const char  token_id_str_NUMBER[]                    = "NUMBER";
   static const char  token_id_str_OUTPUT[]                    = "OUTPUT";
   static const char  token_id_str_PRAGMA[]                    = "PRAGMA";
   static const char  token_id_str_SERIALIZE[]                 = "SERIALIZE";
   static const char  token_id_str_STATEMENT_END[]             = "STATEMENT_END";
   static const char  token_id_str_STRING[]                    = "STRING";
   static const char  token_id_str_STRING_ABSOLUTE_BEGINNING[] = "STRING_ABSOLUTE_BEGINNING";
   static const char  token_id_str_STRING_ABSOLUTE_END[]       = "STRING_ABSOLUTE_END";
   static const char  token_id_str_STRING_RELATIVE_BEGINNING[] = "STRING_RELATIVE_BEGINNING";
   static const char  token_id_str_STRING_RELATIVE_END[]       = "STRING_RELATIVE_END";
   static const char  token_id_str_SUBSTRACTION[]              = "SUBSTRACTION";
       

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
   case QUEX_TKN_IDENTIFIER:                return token_id_str_IDENTIFIER;
   case QUEX_TKN_INCLUDE:                   return token_id_str_INCLUDE;
   case QUEX_TKN_INEQUALITY_ABSOLUTE:       return token_id_str_INEQUALITY_ABSOLUTE;
   case QUEX_TKN_INEQUALITY_RELATIVE:       return token_id_str_INEQUALITY_RELATIVE;
   case QUEX_TKN_MODULO:                    return token_id_str_MODULO;
   case QUEX_TKN_MULTIPLICATION:            return token_id_str_MULTIPLICATION;
   case QUEX_TKN_NEGATION:                  return token_id_str_NEGATION;
   case QUEX_TKN_NUMBER:                    return token_id_str_NUMBER;
   case QUEX_TKN_OUTPUT:                    return token_id_str_OUTPUT;
   case QUEX_TKN_PRAGMA:                    return token_id_str_PRAGMA;
   case QUEX_TKN_SERIALIZE:                 return token_id_str_SERIALIZE;
   case QUEX_TKN_STATEMENT_END:             return token_id_str_STATEMENT_END;
   case QUEX_TKN_STRING:                    return token_id_str_STRING;
   case QUEX_TKN_STRING_ABSOLUTE_BEGINNING: return token_id_str_STRING_ABSOLUTE_BEGINNING;
   case QUEX_TKN_STRING_ABSOLUTE_END:       return token_id_str_STRING_ABSOLUTE_END;
   case QUEX_TKN_STRING_RELATIVE_BEGINNING: return token_id_str_STRING_RELATIVE_BEGINNING;
   case QUEX_TKN_STRING_RELATIVE_END:       return token_id_str_STRING_RELATIVE_END;
   case QUEX_TKN_SUBSTRACTION:              return token_id_str_SUBSTRACTION;

   }
}

QUEX_NAMESPACE_TOKEN_CLOSE

