
#include "lexical_analyzer"

#include <quex/code_base/analyzer/C-adaptions.h>
/* The file 'multi.i' contains implementations which are the same for all 
 * possibly generated analyzers. If QUEX_OPTION_MULTI is defined, it is
 * NOT supposed to be included here. If not--in which case we have a single
 * analzer--then it is included.                                             */
#include <quex/code_base/single.i>

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

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION): return true;
    case QUEX_NAME(ModeID_STRING_RELATIVE): return true;
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION_PARAMETERS): return true;
    case QUEX_NAME(ModeID_STRING_ABSOLUTE): return true;
    case QUEX_NAME(ModeID_SCOPE): return true;
    case QUEX_NAME(ModeID_EXPRESSION): return true;
    default:
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_RELATIVE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_ABSOLUTE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(SCOPE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(EXPRESSION)) ) return true;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION, STRING_RELATIVE, FUNCTION_DEFINITION_PARAMETERS, STRING_ABSOLUTE, SCOPE, EXPRESSION, \n", Mode->name);
    __quex_assert(false);
    return false;
    
}
bool
QUEX_NAME(FUNCTION_DEFINITION_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION): return true;
    case QUEX_NAME(ModeID_STRING_RELATIVE): return true;
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION_PARAMETERS): return true;
    case QUEX_NAME(ModeID_STRING_ABSOLUTE): return true;
    case QUEX_NAME(ModeID_SCOPE): return true;
    case QUEX_NAME(ModeID_EXPRESSION): return true;
    default:
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_RELATIVE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_ABSOLUTE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(SCOPE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(EXPRESSION)) ) return true;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION, STRING_RELATIVE, FUNCTION_DEFINITION_PARAMETERS, STRING_ABSOLUTE, SCOPE, EXPRESSION, \n", Mode->name);
    __quex_assert(false);
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

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION): return true;
    case QUEX_NAME(ModeID_STRING_RELATIVE): return true;
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION_PARAMETERS): return true;
    case QUEX_NAME(ModeID_STRING_ABSOLUTE): return true;
    case QUEX_NAME(ModeID_SCOPE): return true;
    case QUEX_NAME(ModeID_EXPRESSION): return true;
    default:
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_RELATIVE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_ABSOLUTE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(SCOPE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(EXPRESSION)) ) return true;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION, STRING_RELATIVE, FUNCTION_DEFINITION_PARAMETERS, STRING_ABSOLUTE, SCOPE, EXPRESSION, \n", Mode->name);
    __quex_assert(false);
    return false;
    
}
bool
QUEX_NAME(STRING_RELATIVE_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION): return true;
    case QUEX_NAME(ModeID_STRING_RELATIVE): return true;
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION_PARAMETERS): return true;
    case QUEX_NAME(ModeID_STRING_ABSOLUTE): return true;
    case QUEX_NAME(ModeID_SCOPE): return true;
    case QUEX_NAME(ModeID_EXPRESSION): return true;
    default:
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_RELATIVE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_ABSOLUTE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(SCOPE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(EXPRESSION)) ) return true;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION, STRING_RELATIVE, FUNCTION_DEFINITION_PARAMETERS, STRING_ABSOLUTE, SCOPE, EXPRESSION, \n", Mode->name);
    __quex_assert(false);
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

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION): return true;
    case QUEX_NAME(ModeID_STRING_RELATIVE): return true;
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION_PARAMETERS): return true;
    case QUEX_NAME(ModeID_STRING_ABSOLUTE): return true;
    case QUEX_NAME(ModeID_SCOPE): return true;
    case QUEX_NAME(ModeID_EXPRESSION): return true;
    default:
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_RELATIVE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_ABSOLUTE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(SCOPE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(EXPRESSION)) ) return true;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION, STRING_RELATIVE, FUNCTION_DEFINITION_PARAMETERS, STRING_ABSOLUTE, SCOPE, EXPRESSION, \n", Mode->name);
    __quex_assert(false);
    return false;
    
}
bool
QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION): return true;
    case QUEX_NAME(ModeID_STRING_RELATIVE): return true;
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION_PARAMETERS): return true;
    case QUEX_NAME(ModeID_STRING_ABSOLUTE): return true;
    case QUEX_NAME(ModeID_SCOPE): return true;
    case QUEX_NAME(ModeID_EXPRESSION): return true;
    default:
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_RELATIVE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_ABSOLUTE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(SCOPE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(EXPRESSION)) ) return true;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION, STRING_RELATIVE, FUNCTION_DEFINITION_PARAMETERS, STRING_ABSOLUTE, SCOPE, EXPRESSION, \n", Mode->name);
    __quex_assert(false);
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

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION): return true;
    case QUEX_NAME(ModeID_STRING_RELATIVE): return true;
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION_PARAMETERS): return true;
    case QUEX_NAME(ModeID_STRING_ABSOLUTE): return true;
    case QUEX_NAME(ModeID_SCOPE): return true;
    case QUEX_NAME(ModeID_EXPRESSION): return true;
    default:
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_RELATIVE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_ABSOLUTE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(SCOPE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(EXPRESSION)) ) return true;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION, STRING_RELATIVE, FUNCTION_DEFINITION_PARAMETERS, STRING_ABSOLUTE, SCOPE, EXPRESSION, \n", Mode->name);
    __quex_assert(false);
    return false;
    
}
bool
QUEX_NAME(STRING_ABSOLUTE_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION): return true;
    case QUEX_NAME(ModeID_STRING_RELATIVE): return true;
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION_PARAMETERS): return true;
    case QUEX_NAME(ModeID_STRING_ABSOLUTE): return true;
    case QUEX_NAME(ModeID_SCOPE): return true;
    case QUEX_NAME(ModeID_EXPRESSION): return true;
    default:
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_RELATIVE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_ABSOLUTE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(SCOPE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(EXPRESSION)) ) return true;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION, STRING_RELATIVE, FUNCTION_DEFINITION_PARAMETERS, STRING_ABSOLUTE, SCOPE, EXPRESSION, \n", Mode->name);
    __quex_assert(false);
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

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION): return true;
    case QUEX_NAME(ModeID_STRING_RELATIVE): return true;
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION_PARAMETERS): return true;
    case QUEX_NAME(ModeID_STRING_ABSOLUTE): return true;
    case QUEX_NAME(ModeID_SCOPE): return true;
    case QUEX_NAME(ModeID_EXPRESSION): return true;
    default:
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_RELATIVE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_ABSOLUTE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(SCOPE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(EXPRESSION)) ) return true;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION, STRING_RELATIVE, FUNCTION_DEFINITION_PARAMETERS, STRING_ABSOLUTE, SCOPE, EXPRESSION, \n", Mode->name);
    __quex_assert(false);
    return false;
    
}
bool
QUEX_NAME(SCOPE_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION): return true;
    case QUEX_NAME(ModeID_STRING_RELATIVE): return true;
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION_PARAMETERS): return true;
    case QUEX_NAME(ModeID_STRING_ABSOLUTE): return true;
    case QUEX_NAME(ModeID_SCOPE): return true;
    case QUEX_NAME(ModeID_EXPRESSION): return true;
    default:
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_RELATIVE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_ABSOLUTE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(SCOPE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(EXPRESSION)) ) return true;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION, STRING_RELATIVE, FUNCTION_DEFINITION_PARAMETERS, STRING_ABSOLUTE, SCOPE, EXPRESSION, \n", Mode->name);
    __quex_assert(false);
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

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION): return true;
    case QUEX_NAME(ModeID_STRING_RELATIVE): return true;
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION_PARAMETERS): return true;
    case QUEX_NAME(ModeID_STRING_ABSOLUTE): return true;
    case QUEX_NAME(ModeID_SCOPE): return true;
    case QUEX_NAME(ModeID_EXPRESSION): return true;
    default:
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_RELATIVE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_ABSOLUTE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(SCOPE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(EXPRESSION)) ) return true;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION, STRING_RELATIVE, FUNCTION_DEFINITION_PARAMETERS, STRING_ABSOLUTE, SCOPE, EXPRESSION, \n", Mode->name);
    __quex_assert(false);
    return false;
    
}
bool
QUEX_NAME(EXPRESSION_has_exit_to)(const QUEX_NAME(Mode)* Mode) {
    (void)Mode;

    switch( Mode->id ) {
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION): return true;
    case QUEX_NAME(ModeID_STRING_RELATIVE): return true;
    case QUEX_NAME(ModeID_FUNCTION_DEFINITION_PARAMETERS): return true;
    case QUEX_NAME(ModeID_STRING_ABSOLUTE): return true;
    case QUEX_NAME(ModeID_SCOPE): return true;
    case QUEX_NAME(ModeID_EXPRESSION): return true;
    default:
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_RELATIVE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS)) ) return true;
        if( Mode->has_base(&QUEX_NAME(STRING_ABSOLUTE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(SCOPE)) ) return true;
        if( Mode->has_base(&QUEX_NAME(EXPRESSION)) ) return true;
    }
    __QUEX_STD_fprintf(stderr, "mode '%s' is not one of (and not a derived mode of): FUNCTION_DEFINITION, STRING_RELATIVE, FUNCTION_DEFINITION_PARAMETERS, STRING_ABSOLUTE, SCOPE, EXPRESSION, \n", Mode->name);
    __quex_assert(false);
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
/*  'QUEX_GOTO_STATE' requires 'QUEX_LABEL_STATE_ROUTER' */
#   define QUEX_LABEL_STATE_ROUTER _18
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
#   ifdef QUEX_OPTION_COLUMN_NUMBER_COUNTING
    QUEX_TYPE_CHARACTER_POSITION   reference_p                    = (QUEX_TYPE_CHARACTER_POSITION)0x0;
#   endif /* QUEX_OPTION_COLUMN_NUMBER_COUNTING */
    (void)me;
    __QUEX_IF_COUNT_SHIFT_VALUES();
    /* Allow LexemeBegin == LexemeEnd (e.g. END_OF_STREAM)
     * => Caller does not need to check
     * BUT, if so quit immediately after 'shift values'. */
    __quex_assert(LexemeBegin <= LexemeEnd);
    if(LexemeBegin == LexemeEnd) return;
    me->buffer._input_p = LexemeBegin;

    /* (1134 from BEFORE_ENTRY)  */
    input = *(me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

_9:
    __quex_debug("Init State\n");
    __quex_debug_state(1134);
if     ( input >= 0xB )  goto _4;
else if( input == 0xA )  goto _2;
else if( input == 0x9 )  goto _3;
else                     goto _4;


    __quex_assert_no_passage();
_8:
    /* (1134 from 1138)  */
    goto _9;


    __quex_assert_no_passage();
_6:
    /* (DROP_OUT from 1136)  */
    goto _11;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_5:
    /* (DROP_OUT from 1135)  */
    goto _12;


    __quex_assert_no_passage();
_7:
    /* (DROP_OUT from 1137)  */
    goto _13;


    __quex_assert_no_passage();
_2:
    /* (1136 from 1134)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1136);
goto _6;


    __quex_assert_no_passage();
_3:
    /* (1137 from 1134)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1137);
goto _7;


    __quex_assert_no_passage();
_4:
    /* (1135 from 1134)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1135);
goto _5;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_11:
    __quex_debug("* TERMINAL LINE\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

if( me->buffer._input_p != LexemeEnd ) goto _8;

goto _0;

_13:
    __quex_debug("* TERMINAL GRID\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

if( me->buffer._input_p != LexemeEnd ) goto _8;

goto _0;

_12:
    __quex_debug("* TERMINAL COLUMN\n");
if( me->buffer._input_p != LexemeEnd ) goto _8;

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));

goto _0;

_17:
    __quex_debug("* TERMINAL <BEYOND>\n");
    --(me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));

goto _0;

_19: /* TERMINAL: FAILURE */
goto _17;
_0:
     __quex_assert(me->buffer._input_p == LexemeEnd); /* Otherwise, lexeme violates codec character boundaries. */
    return;
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_18:
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */
#   undef self
#   undef QUEX_LABEL_STATE_ROUTER
#    if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
     goto _18; /* in QUEX_GOTO_STATE       */
#    endif
    /* Avoid compiler warning: Unused label for 'TERMINAL <BEYOND>' */
    goto _17;
    goto _19;
    (void)target_state_index;
    (void)target_state_else_index;
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
#define   CONTINUE do { goto _2; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _3; } while(0)
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
/*  'QUEX_GOTO_STATE' requires 'QUEX_LABEL_STATE_ROUTER' */
#   define QUEX_LABEL_STATE_ROUTER _105
#   define COMMENT                           (QUEX_NAME(COMMENT))
#   define FUNCTION_DEFINITION               (QUEX_NAME(FUNCTION_DEFINITION))
#   define STRING_RELATIVE                   (QUEX_NAME(STRING_RELATIVE))
#   define FAILURE                           (QUEX_NAME(FAILURE))
#   define FUNCTION_DEFINITION_PARAMETERS    (QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS))
#   define STRING_ABSOLUTE                   (QUEX_NAME(STRING_ABSOLUTE))
#   define SCOPE                             (QUEX_NAME(SCOPE))
#   define EXPRESSION                        (QUEX_NAME(EXPRESSION))

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
    const QUEX_TYPE_CHARACTER      Skipper1118_Closer[2]          = { 0x2A, 0x2F,  };
    const QUEX_TYPE_CHARACTER      Skipper1118_Opener[2]          = { 0x2F, 0x2A,  };
    QUEX_TYPE_CHARACTER_POSITION   position[1]                    = { 0};
    size_t                         counter                        = 0;
    const QUEX_TYPE_CHARACTER*     Skipper1118_CloserEnd          = Skipper1118_Closer + (ptrdiff_t)2;
    const QUEX_TYPE_CHARACTER*     Skipper1118_Closer_it          = 0x0;
    QUEX_TYPE_ACCEPTANCE_ID        last_acceptance               /* un-initilized */;
    const QUEX_TYPE_CHARACTER*     Skipper1118_OpenerEnd          = Skipper1118_Opener + (ptrdiff_t)2;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    const size_t                   PositionRegisterN              = (size_t)1;
    const QUEX_TYPE_CHARACTER*     Skipper1118_Opener_it          = 0x0;
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
#   ifdef QUEX_OPTION_COLUMN_NUMBER_COUNTING
    QUEX_TYPE_CHARACTER_POSITION   reference_p                    = (QUEX_TYPE_CHARACTER_POSITION)0x0;
#   endif /* QUEX_OPTION_COLUMN_NUMBER_COUNTING */

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
_104:
    me->buffer._lexeme_start_p = me->buffer._input_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);

    /* (1062 from BEFORE_ENTRY)  */
    { last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1); __quex_debug("last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1)\n"); }

_43:
    input = *(me->buffer._input_p);


    __quex_debug("Init State\n");
    __quex_debug_state(1062);
switch( input ) {
case 0x0: goto _34;
case 0x9: goto _10;
case 0xA: goto _12;
case 0xD: 
case 0x20: goto _11;
case 0x28: goto _6;
case 0x2F: goto _5;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _8;
case 0x7B: goto _7;
case 0x7D: goto _9;
default: goto _21;
}


    __quex_assert_no_passage();
_32:
    /* (1062 from RELOAD_FORWARD)  */
    ++(me->buffer._input_p);

    goto _43;


    __quex_assert_no_passage();
_31:
    /* (DROP_OUT from 1073) (DROP_OUT from 1075)  */

    goto _46;
_44:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_22:
    /* (DROP_OUT from 1064)  */
    goto _47;


    __quex_assert_no_passage();
_28:
    /* (DROP_OUT from 1070)  */
    goto _49;


    __quex_assert_no_passage();
_27:
    /* (DROP_OUT from 1069)  */
    goto _50;


    __quex_assert_no_passage();
_26:
    /* (DROP_OUT from 1068)  */
    goto _51;


    __quex_assert_no_passage();
_25:
    /* (DROP_OUT from 1067)  */
    goto _52;


    __quex_assert_no_passage();
_24:
    /* (DROP_OUT from 1066)  */
    goto _53;


    __quex_assert_no_passage();
_29:
    /* (DROP_OUT from 1071)  */
    goto _54;


    __quex_assert_no_passage();
_23:
    /* (DROP_OUT from 1065)  */
    goto _55;


    __quex_assert_no_passage();
_21:
    /* (DROP_OUT from 1063) (DROP_OUT from 1062)  */
        me->buffer._input_p = me->buffer._lexeme_start_p + 1;
goto _48;
    goto _44;


    __quex_assert_no_passage();
_30:
    /* (DROP_OUT from 1072) (DROP_OUT from 1074) (DROP_OUT from 1076)  */
switch( last_acceptance ) {
case 8:     __quex_assert(position[0] != (void*)0);
    me->buffer._input_p = position[0];
goto _46;
case ((QUEX_TYPE_ACCEPTANCE_ID)-1):     me->buffer._input_p = me->buffer._lexeme_start_p + 1;
goto _48;
}

    goto _44;


    __quex_assert_no_passage();
_5:
    /* (1063 from 1062) (1063 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1063);
switch( input ) {
case 0x0: goto _35;
case 0x2A: goto _13;
case 0x2F: goto _14;
default: goto _21;
}


    __quex_assert_no_passage();
_6:
    /* (1064 from 1062)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1064);
goto _22;


    __quex_assert_no_passage();
_7:
    /* (1065 from 1062)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1065);
goto _23;


    __quex_assert_no_passage();
_8:
    /* (1066 from 1062) (1066 from RELOAD_FORWARD) (1066 from 1066)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1066);
switch( input ) {
case 0x0: goto _36;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _8;
default: goto _24;
}


    __quex_assert_no_passage();
_9:
    /* (1067 from 1062)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1067);
goto _25;


    __quex_assert_no_passage();
_10:
    /* (1068 from 1062)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1068);
goto _26;


    __quex_assert_no_passage();
_11:
    /* (1069 from 1062)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1069);
goto _27;


    __quex_assert_no_passage();
_12:
    /* (1070 from 1062)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1070);
goto _28;


    __quex_assert_no_passage();
_13:
    /* (1071 from 1063)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1071);
goto _29;


    __quex_assert_no_passage();
_15:
    /* (1072 from 1075)  */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_68:
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1072);
switch( input ) {
case 0x0: goto _37;
case 0x1: goto _30;
case 0xA: goto _16;
case 0x5C: goto _17;
default: goto _14;
}


    __quex_assert_no_passage();
_14:
    /* (1072 from 1074) (1072 from RELOAD_FORWARD) (1072 from 1076) (1072 from 1072) (1072 from 1063)  */
    goto _68;


    __quex_assert_no_passage();
_16:
    /* (1073 from 1072) (1073 from 1075)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1073);
goto _31;


    __quex_assert_no_passage();
_17:
    /* (1074 from 1076) (1074 from RELOAD_FORWARD) (1074 from 1072) (1074 from 1074)  */
_72:
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1074);
switch( input ) {
case 0x0: goto _38;
case 0x1: goto _30;
case 0x9: goto _17;
case 0xA: goto _19;
case 0xD: goto _20;
case 0x20: 
case 0x5C: goto _17;
default: goto _14;
}


    __quex_assert_no_passage();
_18:
    /* (1074 from 1075)  */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

    goto _72;


    __quex_assert_no_passage();
_19:
    /* (1075 from 1074) (1075 from 1076)  */

    { last_acceptance = 8; __quex_debug("last_acceptance = 8\n"); }

_75:
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1075);
switch( input ) {
case 0x0: goto _40;
case 0x1: goto _31;
case 0xA: goto _16;
case 0x5C: goto _18;
default: goto _15;
}


    __quex_assert_no_passage();
_39:
    /* (1075 from RELOAD_FORWARD)  */
    goto _75;


    __quex_assert_no_passage();
_20:
    /* (1076 from 1074) (1076 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1076);
switch( input ) {
case 0x0: goto _41;
case 0x1: goto _30;
case 0xA: goto _19;
case 0x5C: goto _17;
default: goto _14;
}

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_33:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    self_send (QUEX_TKN_TERMINATION);

    RETURN;


#   line 1266 "lexical_analyzer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
goto _3;
_48:
    __quex_debug("* TERMINAL FAILURE\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    self_send (QUEX_TKN_FAILURE);

    RETURN;


    self_accumulator_add (Lexeme, LexemeEnd);


#   line 1285 "lexical_analyzer.cpp"

}
goto _1;
_0:
    __quex_debug("* TERMINAL character set skipper\n");

    /* (1104 from BEFORE_ENTRY)  */
_91:
    input = *(me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

_90:
    __quex_debug("Init State\n");
    __quex_debug_state(1104);
switch( input ) {
case 0x0: goto _88;
case 0x9: goto _80;
case 0xA: goto _82;
case 0xD: 
case 0x20: goto _81;
default: goto _79;
}


    __quex_assert_no_passage();
_89:
    /* (1104 from 1109)  */
    goto _90;


    __quex_assert_no_passage();
_87:
    /* (1104 from RELOAD_FORWARD)  */
    ++(me->buffer._input_p);

    goto _91;


    __quex_assert_no_passage();
_84:
    /* (DROP_OUT from 1106)  */
    goto _93;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_86:
    /* (DROP_OUT from 1108)  */
    goto _94;


    __quex_assert_no_passage();
_83:
    /* (DROP_OUT from 1105)  */
    goto _95;


    __quex_assert_no_passage();
_85:
    /* (DROP_OUT from 1107)  */
    goto _96;


    __quex_assert_no_passage();
_79:
    /* (1105 from 1104)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1105);
goto _83;


    __quex_assert_no_passage();
_80:
    /* (1106 from 1104)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1106);
goto _84;


    __quex_assert_no_passage();
_81:
    /* (1107 from 1104)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1107);
goto _85;


    __quex_assert_no_passage();
_82:
    /* (1108 from 1104)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1108);
goto _86;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_94:
    __quex_debug("* TERMINAL LINE\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

goto _89;

_93:
    __quex_debug("* TERMINAL GRID\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

goto _89;

_96:
    __quex_debug("* TERMINAL COLUMN\n");
goto _89;

_95:
    __quex_debug("* TERMINAL <BEYOND>\n");
    --(me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));

goto _1;


_49:
    __quex_debug("* TERMINAL <skip>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_LINES_ADD(1);
__QUEX_IF_COUNT_COLUMNS_SET(1);
{
goto _0;


#   line 1445 "lexical_analyzer.cpp"

}
goto _2;
_51:
    __quex_debug("* TERMINAL <skip>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

{
goto _0;


#   line 1460 "lexical_analyzer.cpp"

}
goto _2;
_50:
    __quex_debug("* TERMINAL <skip>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
goto _0;


#   line 1472 "lexical_analyzer.cpp"

}
goto _2;
_54:
    __quex_debug("* TERMINAL SKIP NESTED RANGE\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);

    Skipper1118_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1118_Opener;
    Skipper1118_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1118_Closer;
    /* text_end                           = QUEX_NAME(Buffer_text_end)(&me->buffer); */
    __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));


_101:
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
            goto _102;
        }
        if( input == *Skipper1118_Closer_it ) {
            ++Skipper1118_Closer_it;
            if( Skipper1118_Closer_it == Skipper1118_CloserEnd ) {
                if( counter == 0 ) {
                    /* NOTE: The initial state does not increment the input_p. When it detects that
                     * it is located on a buffer border, it automatically triggers a reload. No 
                     * need here to reload the buffer. */
                    ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
                            __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer)
                                    - reference_p));

                    /* No need for re-entry preparation. Acceptance flags and modes are untouched after skipping. */
                    goto _1; /* End of range reached. */
                }
                --counter;
                Skipper1118_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1118_Opener;
                Skipper1118_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1118_Closer;
                goto CONTINUE_1118;
            }
        } else {
            Skipper1118_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1118_Closer;
        }
        if( input == *Skipper1118_Opener_it ) {
            ++Skipper1118_Opener_it;
            if( Skipper1118_Opener_it == Skipper1118_OpenerEnd ) {
                ++counter;
                Skipper1118_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1118_Opener;
                Skipper1118_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1118_Closer;
                goto CONTINUE_1118;
            }
        } else {
            Skipper1118_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1118_Opener;
        }
CONTINUE_1118:

    __QUEX_IF_COUNT_IF( input == (QUEX_TYPE_CHARACTER)10 ) { 
        __QUEX_IF_COUNT_LINES_ADD((size_t)1);
        __QUEX_IF_COUNT_COLUMNS_SET((size_t)0);
        __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));
    }

        ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
    }

_102:
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
        goto _101; /* End of range reached.             */
    }
    /* Here, either the loading failed or it is not enough space to carry a closing delimiter */
    me->buffer._input_p = me->buffer._lexeme_start_p;
    #define Delimiter "{D_COMMENT_STREAM_ENDING}"
#define Counter counter
/**/QUEX_ERROR_EXIT("\nLexical analyzer mode 'FUNCTION_DEFINITION':\n"
    "End of file occurred before closing skip range delimiter!\n"
    "The 'on_skip_range_open' handler has not been specified.");
__QUEX_PURE_RETURN;
/**/
#undef Delimiter

#undef Counter


_46:
    __quex_debug("* TERMINAL \"//\"([^\\n]|(\\\\[ \\t]*\\r?\\n))*\\r?\\n\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    // We are within a comment. Do not do anything.


#   line 1597 "lexical_analyzer.cpp"

}
goto _2;
_53:
    __quex_debug("* TERMINAL {D_IDENTIFIER}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
{
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
self_send(QUEX_TKN_IDENTIFIER);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 1611 "lexical_analyzer.cpp"

}
goto _2;
_47:
    __quex_debug("* TERMINAL \"(\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(push_mode)(&self, &FUNCTION_DEFINITION_PARAMETERS);self_send(QUEX_TKN_PARENTHESIS_BEGINNING);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 1624 "lexical_analyzer.cpp"

}
goto _2;
_55:
    __quex_debug("* TERMINAL \"{\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
self_send(QUEX_TKN_BRACE_BEGINNING);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 1637 "lexical_analyzer.cpp"

}
goto _2;
_52:
    __quex_debug("* TERMINAL \"}\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_BRACE_END);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 1650 "lexical_analyzer.cpp"

}
goto _2;
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_105:
    switch( target_state_index ) {
        case 5: { goto _5; }
        case 8: { goto _8; }
        case 14: { goto _14; }
        case 17: { goto _17; }
        case 20: { goto _20; }
        case 21: { goto _21; }
        case 24: { goto _24; }
        case 30: { goto _30; }
        case 31: { goto _31; }
        case 32: { goto _32; }
        case 33: { goto _33; }
        case 39: { goto _39; }
        case 87: { goto _87; }

        default:
            __QUEX_STD_fprintf(stderr, "State router: index = %i\n", (int)target_state_index);
            QUEX_ERROR_EXIT("State router: unknown index.\n");
    }
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_36:
    /* (RELOAD_FORWARD from 1066)  */
    target_state_index = QUEX_LABEL(8); target_state_else_index = QUEX_LABEL(24);

_103:
    __quex_debug3("RELOAD_FORWARD: success->%i; failure->%i", (int)target_state_index, (int)target_state_else_index);
    __quex_assert(*(me->buffer._input_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {

        __quex_debug_reload_before();          /* Report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);   /* may use 'computed goto' */
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);  /* may use 'computed goto' */


    __quex_assert_no_passage();
_37:
    /* (RELOAD_FORWARD from 1072)  */
    target_state_index = QUEX_LABEL(14); target_state_else_index = QUEX_LABEL(30);

    goto _103;


    __quex_assert_no_passage();
_38:
    /* (RELOAD_FORWARD from 1074)  */
    target_state_index = QUEX_LABEL(17); target_state_else_index = QUEX_LABEL(30);

    goto _103;


    __quex_assert_no_passage();
_40:
    /* (RELOAD_FORWARD from 1075)  */
    target_state_index = QUEX_LABEL(39); target_state_else_index = QUEX_LABEL(31);

    goto _103;


    __quex_assert_no_passage();
_41:
    /* (RELOAD_FORWARD from 1076)  */
    target_state_index = QUEX_LABEL(20); target_state_else_index = QUEX_LABEL(30);

    goto _103;


    __quex_assert_no_passage();
_34:
    /* (RELOAD_FORWARD from 1062)  */
    target_state_index = QUEX_LABEL(32); target_state_else_index = QUEX_LABEL(33);

    goto _103;


    __quex_assert_no_passage();
_35:
    /* (RELOAD_FORWARD from 1063)  */
    target_state_index = QUEX_LABEL(5); target_state_else_index = QUEX_LABEL(21);

    goto _103;


    __quex_assert_no_passage();
_88:
    /* (RELOAD_FORWARD from 1104)  */
    target_state_index = QUEX_LABEL(87); target_state_else_index = QUEX_LABEL(33);

    (me->buffer._lexeme_start_p) = (me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));

    goto _103;

_3:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_2:
/* CONTINUE -- after executing 'on_after_match' code. */

_1:
/* CONTINUE -- without executing 'on_after_match' (e.g. on FAILURE). */


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


goto _104;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _3; /* in RETURN                */
    goto _2; /* in CONTINUE              */
    goto _1; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _105; /* in QUEX_GOTO_STATE       */
#   endif

    /* Prevent compiler warning 'unused variable'.                           */
    (void)QUEX_LEXEME_NULL;
    (void)QUEX_NAME_TOKEN(DumpedTokenIdObject);
    /* target_state_index and target_state_else_index appear when 
     * QUEX_GOTO_STATE is used without computed goto-s.                      */
    (void)target_state_index;
    (void)target_state_else_index;

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL
#   undef COMMENT
#   undef FUNCTION_DEFINITION
#   undef STRING_RELATIVE
#   undef FAILURE
#   undef FUNCTION_DEFINITION_PARAMETERS
#   undef STRING_ABSOLUTE
#   undef SCOPE
#   undef EXPRESSION
#   undef self
#   undef QUEX_LABEL_STATE_ROUTER
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
#define   CONTINUE do { goto _0; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _2; } while(0)
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
/*  'QUEX_GOTO_STATE' requires 'QUEX_LABEL_STATE_ROUTER' */
#   define QUEX_LABEL_STATE_ROUTER _43
#   define COMMENT                           (QUEX_NAME(COMMENT))
#   define FUNCTION_DEFINITION               (QUEX_NAME(FUNCTION_DEFINITION))
#   define STRING_RELATIVE                   (QUEX_NAME(STRING_RELATIVE))
#   define FAILURE                           (QUEX_NAME(FAILURE))
#   define FUNCTION_DEFINITION_PARAMETERS    (QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS))
#   define STRING_ABSOLUTE                   (QUEX_NAME(STRING_ABSOLUTE))
#   define SCOPE                             (QUEX_NAME(SCOPE))
#   define EXPRESSION                        (QUEX_NAME(EXPRESSION))

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
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    const size_t                   PositionRegisterN              = (size_t)0;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
    QUEX_TYPE_CHARACTER_POSITION*  position                       = 0x0;

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
_42:
    me->buffer._lexeme_start_p = me->buffer._input_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);

    /* (1195 from BEFORE_ENTRY)  */
_23:
    input = *(me->buffer._input_p);


    __quex_debug("Init State\n");
    __quex_debug_state(1195);
switch( input ) {
case 0x0: goto _20;
case 0x1: 
case 0xA: goto _11;
case 0x22: goto _6;
case 0x5C: goto _4;
default: goto _5;
}


    __quex_assert_no_passage();
_18:
    /* (1195 from RELOAD_FORWARD)  */
    ++(me->buffer._input_p);

    goto _23;


    __quex_assert_no_passage();
_12:
    /* (DROP_OUT from 1196) (DROP_OUT from 1197)  */

    goto _26;
_24:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_17:
    /* (DROP_OUT from 1202)  */
    goto _28;


    __quex_assert_no_passage();
_16:
    /* (DROP_OUT from 1201)  */
    goto _29;


    __quex_assert_no_passage();
_15:
    /* (DROP_OUT from 1200)  */
    goto _30;


    __quex_assert_no_passage();
_14:
    /* (DROP_OUT from 1199)  */
    goto _31;


    __quex_assert_no_passage();
_13:
    /* (DROP_OUT from 1198)  */
    goto _32;


    __quex_assert_no_passage();
_11:
    /* (DROP_OUT from 1195)  */
        me->buffer._input_p = me->buffer._lexeme_start_p + 1;
goto _27;
    goto _24;


    __quex_assert_no_passage();
_4:
    /* (1196 from 1195) (1196 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1196);
switch( input ) {
case 0x0: goto _21;
case 0x22: goto _8;
case 0x4E: goto _10;
case 0x54: goto _7;
case 0x5C: goto _9;
case 0x6E: goto _10;
case 0x74: goto _7;
default: goto _12;
}


    __quex_assert_no_passage();
_5:
    /* (1197 from 1195)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1197);
goto _12;


    __quex_assert_no_passage();
_6:
    /* (1198 from 1195)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1198);
goto _13;


    __quex_assert_no_passage();
_7:
    /* (1199 from 1196)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1199);
goto _14;


    __quex_assert_no_passage();
_8:
    /* (1200 from 1196)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1200);
goto _15;


    __quex_assert_no_passage();
_9:
    /* (1201 from 1196)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1201);
goto _16;


    __quex_assert_no_passage();
_10:
    /* (1202 from 1196)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1202);
goto _17;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_19:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    self_send (QUEX_TKN_TERMINATION);

    RETURN;


#   line 2123 "lexical_analyzer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
goto _2;
_27:
    __quex_debug("* TERMINAL FAILURE\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    self_send (QUEX_TKN_FAILURE);

    RETURN;


    self_accumulator_add (Lexeme, LexemeEnd);


    self_accumulator_add (Lexeme, LexemeEnd);


#   line 2145 "lexical_analyzer.cpp"

}
goto _1;
_28:
    __quex_debug("* TERMINAL {D_ENDL}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
self_send(QUEX_TKN_ENDL);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 2159 "lexical_analyzer.cpp"

}
goto _0;
_31:
    __quex_debug("* TERMINAL {D_TAB}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
self_send(QUEX_TKN_TAB);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 2173 "lexical_analyzer.cpp"

}
goto _0;
_30:
    __quex_debug("* TERMINAL {D_BACKSLASHED_QUOTE_DOUBLE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
self_send(QUEX_TKN_BACKSLASHED_QUOTE_DOUBLE);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 2187 "lexical_analyzer.cpp"

}
goto _0;
_29:
    __quex_debug("* TERMINAL {D_BACKSLASHED_BACKSLASH}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
self_send(QUEX_TKN_BACKSLASHED_BACKSLASH);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 2201 "lexical_analyzer.cpp"

}
goto _0;
_32:
    __quex_debug("* TERMINAL {D_QUOTE_DOUBLE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_STRING_RELATIVE_END);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 2214 "lexical_analyzer.cpp"

}
goto _0;
_26:
    __quex_debug("* TERMINAL {D_ANY_CHARACTER}\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
self_send(QUEX_TKN_CHARACTER);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 2227 "lexical_analyzer.cpp"

}
goto _0;
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_43:
    switch( target_state_index ) {
        case 4: { goto _4; }
        case 12: { goto _12; }
        case 18: { goto _18; }
        case 19: { goto _19; }

        default:
            __QUEX_STD_fprintf(stderr, "State router: index = %i\n", (int)target_state_index);
            QUEX_ERROR_EXIT("State router: unknown index.\n");
    }
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_20:
    /* (RELOAD_FORWARD from 1195)  */
    target_state_index = QUEX_LABEL(18); target_state_else_index = QUEX_LABEL(19);

_41:
    __quex_debug3("RELOAD_FORWARD: success->%i; failure->%i", (int)target_state_index, (int)target_state_else_index);
    __quex_assert(*(me->buffer._input_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {

        __quex_debug_reload_before();          /* Report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);   /* may use 'computed goto' */
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);  /* may use 'computed goto' */


    __quex_assert_no_passage();
_21:
    /* (RELOAD_FORWARD from 1196)  */
    target_state_index = QUEX_LABEL(4); target_state_else_index = QUEX_LABEL(12);

    goto _41;

_2:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_0:
/* CONTINUE -- after executing 'on_after_match' code. */

_1:
/* CONTINUE -- without executing 'on_after_match' (e.g. on FAILURE). */


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


goto _42;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _2; /* in RETURN                */
    goto _0; /* in CONTINUE              */
    goto _1; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _43; /* in QUEX_GOTO_STATE       */
#   endif

    /* Prevent compiler warning 'unused variable'.                           */
    (void)QUEX_LEXEME_NULL;
    (void)QUEX_NAME_TOKEN(DumpedTokenIdObject);
    /* target_state_index and target_state_else_index appear when 
     * QUEX_GOTO_STATE is used without computed goto-s.                      */
    (void)target_state_index;
    (void)target_state_else_index;

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL
#   undef COMMENT
#   undef FUNCTION_DEFINITION
#   undef STRING_RELATIVE
#   undef FAILURE
#   undef FUNCTION_DEFINITION_PARAMETERS
#   undef STRING_ABSOLUTE
#   undef SCOPE
#   undef EXPRESSION
#   undef self
#   undef QUEX_LABEL_STATE_ROUTER
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
#define   CONTINUE do { goto _2; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _3; } while(0)
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
/*  'QUEX_GOTO_STATE' requires 'QUEX_LABEL_STATE_ROUTER' */
#   define QUEX_LABEL_STATE_ROUTER _91
#   define COMMENT                           (QUEX_NAME(COMMENT))
#   define FUNCTION_DEFINITION               (QUEX_NAME(FUNCTION_DEFINITION))
#   define STRING_RELATIVE                   (QUEX_NAME(STRING_RELATIVE))
#   define FAILURE                           (QUEX_NAME(FAILURE))
#   define FUNCTION_DEFINITION_PARAMETERS    (QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS))
#   define STRING_ABSOLUTE                   (QUEX_NAME(STRING_ABSOLUTE))
#   define SCOPE                             (QUEX_NAME(SCOPE))
#   define EXPRESSION                        (QUEX_NAME(EXPRESSION))

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
    const QUEX_TYPE_CHARACTER      Skipper1314_Closer[2]          = { 0x2A, 0x2F,  };
    const QUEX_TYPE_CHARACTER      Skipper1314_Opener[2]          = { 0x2F, 0x2A,  };
    const QUEX_TYPE_CHARACTER*     Skipper1314_Closer_it          = 0x0;
    QUEX_TYPE_CHARACTER_POSITION   position[1]                    = { 0};
    size_t                         counter                        = 0;
    QUEX_TYPE_ACCEPTANCE_ID        last_acceptance               /* un-initilized */;
    const QUEX_TYPE_CHARACTER*     Skipper1314_Opener_it          = 0x0;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    const size_t                   PositionRegisterN              = (size_t)1;
    const QUEX_TYPE_CHARACTER*     Skipper1314_OpenerEnd          = Skipper1314_Opener + (ptrdiff_t)2;
    const QUEX_TYPE_CHARACTER*     Skipper1314_CloserEnd          = Skipper1314_Closer + (ptrdiff_t)2;
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
#   ifdef QUEX_OPTION_COLUMN_NUMBER_COUNTING
    QUEX_TYPE_CHARACTER_POSITION   reference_p                    = (QUEX_TYPE_CHARACTER_POSITION)0x0;
#   endif /* QUEX_OPTION_COLUMN_NUMBER_COUNTING */

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
_90:
    me->buffer._lexeme_start_p = me->buffer._input_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);

    /* (1264 from BEFORE_ENTRY)  */
    { last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1); __quex_debug("last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1)\n"); }

_36:
    input = *(me->buffer._input_p);


    __quex_debug("Init State\n");
    __quex_debug_state(1264);
switch( input ) {
case 0x0: goto _28;
case 0x9: goto _7;
case 0xA: goto _8;
case 0xD: 
case 0x20: goto _5;
case 0x29: goto _9;
case 0x2F: goto _6;
default: goto _18;
}


    __quex_assert_no_passage();
_26:
    /* (1264 from RELOAD_FORWARD)  */
    ++(me->buffer._input_p);

    goto _36;


    __quex_assert_no_passage();
_18:
    /* (DROP_OUT from 1264) (DROP_OUT from 1266)  */

        me->buffer._input_p = me->buffer._lexeme_start_p + 1;
goto _39;
_37:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_19:
    /* (DROP_OUT from 1265)  */
    goto _40;


    __quex_assert_no_passage();
_25:
    /* (DROP_OUT from 1272) (DROP_OUT from 1274)  */
    goto _41;


    __quex_assert_no_passage();
_23:
    /* (DROP_OUT from 1270)  */
    goto _42;


    __quex_assert_no_passage();
_22:
    /* (DROP_OUT from 1269)  */
    goto _43;


    __quex_assert_no_passage();
_21:
    /* (DROP_OUT from 1268)  */
    goto _44;


    __quex_assert_no_passage();
_20:
    /* (DROP_OUT from 1267)  */
    goto _45;


    __quex_assert_no_passage();
_24:
    /* (DROP_OUT from 1275) (DROP_OUT from 1273) (DROP_OUT from 1271)  */
switch( last_acceptance ) {
case 8:     __quex_assert(position[0] != (void*)0);
    me->buffer._input_p = position[0];
goto _41;
case ((QUEX_TYPE_ACCEPTANCE_ID)-1):     me->buffer._input_p = me->buffer._lexeme_start_p + 1;
goto _39;
}

    goto _37;


    __quex_assert_no_passage();
_5:
    /* (1265 from 1264)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1265);
goto _19;


    __quex_assert_no_passage();
_6:
    /* (1266 from RELOAD_FORWARD) (1266 from 1264)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1266);
switch( input ) {
case 0x0: goto _29;
case 0x2A: goto _10;
case 0x2F: goto _11;
default: goto _18;
}


    __quex_assert_no_passage();
_7:
    /* (1267 from 1264)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1267);
goto _20;


    __quex_assert_no_passage();
_8:
    /* (1268 from 1264)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1268);
goto _21;


    __quex_assert_no_passage();
_9:
    /* (1269 from 1264)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1269);
goto _22;


    __quex_assert_no_passage();
_10:
    /* (1270 from 1266)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1270);
goto _23;


    __quex_assert_no_passage();
_11:
    /* (1271 from 1273) (1271 from RELOAD_FORWARD) (1271 from 1271) (1271 from 1266) (1271 from 1275)  */
_54:
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1271);
switch( input ) {
case 0x0: goto _30;
case 0x1: goto _24;
case 0xA: goto _13;
case 0x5C: goto _14;
default: goto _11;
}


    __quex_assert_no_passage();
_12:
    /* (1271 from 1274)  */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

    goto _54;


    __quex_assert_no_passage();
_13:
    /* (1272 from 1274) (1272 from 1271)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1272);
goto _25;


    __quex_assert_no_passage();
_14:
    /* (1273 from RELOAD_FORWARD) (1273 from 1273) (1273 from 1275) (1273 from 1271)  */
_58:
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1273);
switch( input ) {
case 0x0: goto _31;
case 0x1: goto _24;
case 0x9: goto _14;
case 0xA: goto _16;
case 0xD: goto _17;
case 0x20: 
case 0x5C: goto _14;
default: goto _11;
}


    __quex_assert_no_passage();
_15:
    /* (1273 from 1274)  */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

    goto _58;


    __quex_assert_no_passage();
_16:
    /* (1274 from 1273) (1274 from 1275)  */

    { last_acceptance = 8; __quex_debug("last_acceptance = 8\n"); }

_61:
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1274);
switch( input ) {
case 0x0: goto _33;
case 0x1: goto _25;
case 0xA: goto _13;
case 0x5C: goto _15;
default: goto _12;
}


    __quex_assert_no_passage();
_32:
    /* (1274 from RELOAD_FORWARD)  */
    goto _61;


    __quex_assert_no_passage();
_17:
    /* (1275 from 1273) (1275 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1275);
switch( input ) {
case 0x0: goto _34;
case 0x1: goto _24;
case 0xA: goto _16;
case 0x5C: goto _14;
default: goto _11;
}

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_27:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    self_send (QUEX_TKN_TERMINATION);

    RETURN;


#   line 2768 "lexical_analyzer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
goto _3;
_39:
    __quex_debug("* TERMINAL FAILURE\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    self_send (QUEX_TKN_FAILURE);

    RETURN;


    self_accumulator_add (Lexeme, LexemeEnd);


    self_accumulator_add (Lexeme, LexemeEnd);


    self_accumulator_add (Lexeme, LexemeEnd);


#   line 2793 "lexical_analyzer.cpp"

}
goto _1;
_0:
    __quex_debug("* TERMINAL character set skipper\n");

    /* (1300 from BEFORE_ENTRY)  */
_77:
    input = *(me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

_76:
    __quex_debug("Init State\n");
    __quex_debug_state(1300);
switch( input ) {
case 0x0: goto _74;
case 0x9: goto _65;
case 0xA: goto _67;
case 0xD: 
case 0x20: goto _66;
default: goto _68;
}


    __quex_assert_no_passage();
_75:
    /* (1300 from 1305)  */
    goto _76;


    __quex_assert_no_passage();
_73:
    /* (1300 from RELOAD_FORWARD)  */
    ++(me->buffer._input_p);

    goto _77;


    __quex_assert_no_passage();
_70:
    /* (DROP_OUT from 1302)  */
    goto _79;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_72:
    /* (DROP_OUT from 1304)  */
    goto _80;


    __quex_assert_no_passage();
_69:
    /* (DROP_OUT from 1301)  */
    goto _81;


    __quex_assert_no_passage();
_71:
    /* (DROP_OUT from 1303)  */
    goto _82;


    __quex_assert_no_passage();
_65:
    /* (1304 from 1300)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1304);
goto _72;


    __quex_assert_no_passage();
_66:
    /* (1301 from 1300)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1301);
goto _69;


    __quex_assert_no_passage();
_67:
    /* (1302 from 1300)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1302);
goto _70;


    __quex_assert_no_passage();
_68:
    /* (1303 from 1300)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1303);
goto _71;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_79:
    __quex_debug("* TERMINAL LINE\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

goto _75;

_80:
    __quex_debug("* TERMINAL GRID\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

goto _75;

_81:
    __quex_debug("* TERMINAL COLUMN\n");
goto _75;

_82:
    __quex_debug("* TERMINAL <BEYOND>\n");
    --(me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));

goto _1;


_44:
    __quex_debug("* TERMINAL <skip>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_LINES_ADD(1);
__QUEX_IF_COUNT_COLUMNS_SET(1);
{
goto _0;


#   line 2953 "lexical_analyzer.cpp"

}
goto _2;
_45:
    __quex_debug("* TERMINAL <skip>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

{
goto _0;


#   line 2968 "lexical_analyzer.cpp"

}
goto _2;
_40:
    __quex_debug("* TERMINAL <skip>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
goto _0;


#   line 2980 "lexical_analyzer.cpp"

}
goto _2;
_42:
    __quex_debug("* TERMINAL SKIP NESTED RANGE\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);

    Skipper1314_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1314_Opener;
    Skipper1314_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1314_Closer;
    /* text_end                           = QUEX_NAME(Buffer_text_end)(&me->buffer); */
    __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));


_87:
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
            goto _88;
        }
        if( input == *Skipper1314_Closer_it ) {
            ++Skipper1314_Closer_it;
            if( Skipper1314_Closer_it == Skipper1314_CloserEnd ) {
                if( counter == 0 ) {
                    /* NOTE: The initial state does not increment the input_p. When it detects that
                     * it is located on a buffer border, it automatically triggers a reload. No 
                     * need here to reload the buffer. */
                    ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
                            __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer)
                                    - reference_p));

                    /* No need for re-entry preparation. Acceptance flags and modes are untouched after skipping. */
                    goto _1; /* End of range reached. */
                }
                --counter;
                Skipper1314_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1314_Opener;
                Skipper1314_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1314_Closer;
                goto CONTINUE_1314;
            }
        } else {
            Skipper1314_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1314_Closer;
        }
        if( input == *Skipper1314_Opener_it ) {
            ++Skipper1314_Opener_it;
            if( Skipper1314_Opener_it == Skipper1314_OpenerEnd ) {
                ++counter;
                Skipper1314_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1314_Opener;
                Skipper1314_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1314_Closer;
                goto CONTINUE_1314;
            }
        } else {
            Skipper1314_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1314_Opener;
        }
CONTINUE_1314:

    __QUEX_IF_COUNT_IF( input == (QUEX_TYPE_CHARACTER)10 ) { 
        __QUEX_IF_COUNT_LINES_ADD((size_t)1);
        __QUEX_IF_COUNT_COLUMNS_SET((size_t)0);
        __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));
    }

        ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
    }

_88:
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
        goto _87; /* End of range reached.             */
    }
    /* Here, either the loading failed or it is not enough space to carry a closing delimiter */
    me->buffer._input_p = me->buffer._lexeme_start_p;
    #define Delimiter "{D_COMMENT_STREAM_ENDING}"
#define Counter counter
/**/QUEX_ERROR_EXIT("\nLexical analyzer mode 'FUNCTION_DEFINITION_PARAMETERS':\n"
    "End of file occurred before closing skip range delimiter!\n"
    "The 'on_skip_range_open' handler has not been specified.");
__QUEX_PURE_RETURN;
/**/
#undef Delimiter

#undef Counter


_41:
    __quex_debug("* TERMINAL \"//\"([^\\n]|(\\\\[ \\t]*\\r?\\n))*\\r?\\n\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    // We are within a comment. Do not do anything.


#   line 3105 "lexical_analyzer.cpp"

}
goto _2;
_43:
    __quex_debug("* TERMINAL \")\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_PARENTHESIS_END);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 3118 "lexical_analyzer.cpp"

}
goto _2;
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_91:
    switch( target_state_index ) {
        case 6: { goto _6; }
        case 11: { goto _11; }
        case 14: { goto _14; }
        case 17: { goto _17; }
        case 18: { goto _18; }
        case 24: { goto _24; }
        case 25: { goto _25; }
        case 26: { goto _26; }
        case 27: { goto _27; }
        case 32: { goto _32; }
        case 73: { goto _73; }

        default:
            __QUEX_STD_fprintf(stderr, "State router: index = %i\n", (int)target_state_index);
            QUEX_ERROR_EXIT("State router: unknown index.\n");
    }
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_30:
    /* (RELOAD_FORWARD from 1271)  */
    target_state_index = QUEX_LABEL(11); target_state_else_index = QUEX_LABEL(24);

_89:
    __quex_debug3("RELOAD_FORWARD: success->%i; failure->%i", (int)target_state_index, (int)target_state_else_index);
    __quex_assert(*(me->buffer._input_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {

        __quex_debug_reload_before();          /* Report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);   /* may use 'computed goto' */
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);  /* may use 'computed goto' */


    __quex_assert_no_passage();
_31:
    /* (RELOAD_FORWARD from 1273)  */
    target_state_index = QUEX_LABEL(14); target_state_else_index = QUEX_LABEL(24);

    goto _89;


    __quex_assert_no_passage();
_33:
    /* (RELOAD_FORWARD from 1274)  */
    target_state_index = QUEX_LABEL(32); target_state_else_index = QUEX_LABEL(25);

    goto _89;


    __quex_assert_no_passage();
_34:
    /* (RELOAD_FORWARD from 1275)  */
    target_state_index = QUEX_LABEL(17); target_state_else_index = QUEX_LABEL(24);

    goto _89;


    __quex_assert_no_passage();
_28:
    /* (RELOAD_FORWARD from 1264)  */
    target_state_index = QUEX_LABEL(26); target_state_else_index = QUEX_LABEL(27);

    goto _89;


    __quex_assert_no_passage();
_29:
    /* (RELOAD_FORWARD from 1266)  */
    target_state_index = QUEX_LABEL(6); target_state_else_index = QUEX_LABEL(18);

    goto _89;


    __quex_assert_no_passage();
_74:
    /* (RELOAD_FORWARD from 1300)  */
    target_state_index = QUEX_LABEL(73); target_state_else_index = QUEX_LABEL(27);

    (me->buffer._lexeme_start_p) = (me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));

    goto _89;

_3:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_2:
/* CONTINUE -- after executing 'on_after_match' code. */

_1:
/* CONTINUE -- without executing 'on_after_match' (e.g. on FAILURE). */


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


goto _90;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _3; /* in RETURN                */
    goto _2; /* in CONTINUE              */
    goto _1; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _91; /* in QUEX_GOTO_STATE       */
#   endif

    /* Prevent compiler warning 'unused variable'.                           */
    (void)QUEX_LEXEME_NULL;
    (void)QUEX_NAME_TOKEN(DumpedTokenIdObject);
    /* target_state_index and target_state_else_index appear when 
     * QUEX_GOTO_STATE is used without computed goto-s.                      */
    (void)target_state_index;
    (void)target_state_else_index;

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL
#   undef COMMENT
#   undef FUNCTION_DEFINITION
#   undef STRING_RELATIVE
#   undef FAILURE
#   undef FUNCTION_DEFINITION_PARAMETERS
#   undef STRING_ABSOLUTE
#   undef SCOPE
#   undef EXPRESSION
#   undef self
#   undef QUEX_LABEL_STATE_ROUTER
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
#define   CONTINUE do { goto _0; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _2; } while(0)
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
/*  'QUEX_GOTO_STATE' requires 'QUEX_LABEL_STATE_ROUTER' */
#   define QUEX_LABEL_STATE_ROUTER _22
#   define COMMENT                           (QUEX_NAME(COMMENT))
#   define FUNCTION_DEFINITION               (QUEX_NAME(FUNCTION_DEFINITION))
#   define STRING_RELATIVE                   (QUEX_NAME(STRING_RELATIVE))
#   define FAILURE                           (QUEX_NAME(FAILURE))
#   define FUNCTION_DEFINITION_PARAMETERS    (QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS))
#   define STRING_ABSOLUTE                   (QUEX_NAME(STRING_ABSOLUTE))
#   define SCOPE                             (QUEX_NAME(SCOPE))
#   define EXPRESSION                        (QUEX_NAME(EXPRESSION))

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
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    const size_t                   PositionRegisterN              = (size_t)0;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
    QUEX_TYPE_CHARACTER_POSITION*  position                       = 0x0;

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
_21:
    me->buffer._lexeme_start_p = me->buffer._input_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);

    /* (1331 from BEFORE_ENTRY)  */
_13:
    input = *(me->buffer._input_p);


    __quex_debug("Init State\n");
    __quex_debug_state(1331);
switch( input ) {
case 0x0: goto _11;
case 0x1: 
case 0xA: goto _6;
case 0x27: goto _5;
default: goto _4;
}


    __quex_assert_no_passage();
_9:
    /* (1331 from RELOAD_FORWARD)  */
    ++(me->buffer._input_p);

    goto _13;


    __quex_assert_no_passage();
_7:
    /* (DROP_OUT from 1332)  */
    goto _15;
_14:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_8:
    /* (DROP_OUT from 1333)  */
    goto _17;


    __quex_assert_no_passage();
_6:
    /* (DROP_OUT from 1331)  */
        me->buffer._input_p = me->buffer._lexeme_start_p + 1;
goto _16;
    goto _14;


    __quex_assert_no_passage();
_4:
    /* (1332 from 1331)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1332);
goto _7;


    __quex_assert_no_passage();
_5:
    /* (1333 from 1331)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1333);
goto _8;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_10:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    self_send (QUEX_TKN_TERMINATION);

    RETURN;


#   line 3485 "lexical_analyzer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
goto _2;
_16:
    __quex_debug("* TERMINAL FAILURE\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    self_send (QUEX_TKN_FAILURE);

    RETURN;


    self_accumulator_add (Lexeme, LexemeEnd);


    self_accumulator_add (Lexeme, LexemeEnd);


    self_accumulator_add (Lexeme, LexemeEnd);


    self_accumulator_add (Lexeme, LexemeEnd);


#   line 3513 "lexical_analyzer.cpp"

}
goto _1;
_17:
    __quex_debug("* TERMINAL {D_QUOTE_SINGLE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_STRING_ABSOLUTE_END);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 3526 "lexical_analyzer.cpp"

}
goto _0;
_15:
    __quex_debug("* TERMINAL {D_ANY_CHARACTER}\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
self_send(QUEX_TKN_CHARACTER);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 3539 "lexical_analyzer.cpp"

}
goto _0;
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_22:
    switch( target_state_index ) {
        case 9: { goto _9; }
        case 10: { goto _10; }

        default:
            __QUEX_STD_fprintf(stderr, "State router: index = %i\n", (int)target_state_index);
            QUEX_ERROR_EXIT("State router: unknown index.\n");
    }
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_11:
    /* (RELOAD_FORWARD from 1331)  */
    target_state_index = QUEX_LABEL(9); target_state_else_index = QUEX_LABEL(10);


    __quex_debug3("RELOAD_FORWARD: success->%i; failure->%i", (int)target_state_index, (int)target_state_else_index);
    __quex_assert(*(me->buffer._input_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {

        __quex_debug_reload_before();          /* Report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);   /* may use 'computed goto' */
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);  /* may use 'computed goto' */

_2:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_0:
/* CONTINUE -- after executing 'on_after_match' code. */

_1:
/* CONTINUE -- without executing 'on_after_match' (e.g. on FAILURE). */


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


goto _21;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _2; /* in RETURN                */
    goto _0; /* in CONTINUE              */
    goto _1; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _22; /* in QUEX_GOTO_STATE       */
#   endif

    /* Prevent compiler warning 'unused variable'.                           */
    (void)QUEX_LEXEME_NULL;
    (void)QUEX_NAME_TOKEN(DumpedTokenIdObject);
    /* target_state_index and target_state_else_index appear when 
     * QUEX_GOTO_STATE is used without computed goto-s.                      */
    (void)target_state_index;
    (void)target_state_else_index;

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL
#   undef COMMENT
#   undef FUNCTION_DEFINITION
#   undef STRING_RELATIVE
#   undef FAILURE
#   undef FUNCTION_DEFINITION_PARAMETERS
#   undef STRING_ABSOLUTE
#   undef SCOPE
#   undef EXPRESSION
#   undef self
#   undef QUEX_LABEL_STATE_ROUTER
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
#define   CONTINUE do { goto _2; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _3; } while(0)
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
/*  'QUEX_GOTO_STATE' requires 'QUEX_LABEL_STATE_ROUTER' */
#   define QUEX_LABEL_STATE_ROUTER _273
#   define COMMENT                           (QUEX_NAME(COMMENT))
#   define FUNCTION_DEFINITION               (QUEX_NAME(FUNCTION_DEFINITION))
#   define STRING_RELATIVE                   (QUEX_NAME(STRING_RELATIVE))
#   define FAILURE                           (QUEX_NAME(FAILURE))
#   define FUNCTION_DEFINITION_PARAMETERS    (QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS))
#   define STRING_ABSOLUTE                   (QUEX_NAME(STRING_ABSOLUTE))
#   define SCOPE                             (QUEX_NAME(SCOPE))
#   define EXPRESSION                        (QUEX_NAME(EXPRESSION))

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
    const QUEX_TYPE_CHARACTER      Skipper1638_Closer[2]          = { 0x2A, 0x2F,  };
    const QUEX_TYPE_CHARACTER      Skipper1638_Opener[2]          = { 0x2F, 0x2A,  };
    const QUEX_TYPE_CHARACTER*     Skipper1638_CloserEnd          = Skipper1638_Closer + (ptrdiff_t)2;
    size_t                         counter                        = 0;
    const QUEX_TYPE_CHARACTER*     Skipper1638_Closer_it          = 0x0;
    QUEX_TYPE_ACCEPTANCE_ID        last_acceptance               /* un-initilized */;
    const QUEX_TYPE_CHARACTER*     Skipper1638_Opener_it          = 0x0;
    const size_t                   PositionRegisterN              = (size_t)1;
    QUEX_TYPE_CHARACTER_POSITION   position[1]                    = { 0};
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    const QUEX_TYPE_CHARACTER*     Skipper1638_OpenerEnd          = Skipper1638_Opener + (ptrdiff_t)2;
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
#   ifdef QUEX_OPTION_COLUMN_NUMBER_COUNTING
    QUEX_TYPE_CHARACTER_POSITION   reference_p                    = (QUEX_TYPE_CHARACTER_POSITION)0x0;
#   endif /* QUEX_OPTION_COLUMN_NUMBER_COUNTING */

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
_272:
    me->buffer._lexeme_start_p = me->buffer._input_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);

    /* (1531 from BEFORE_ENTRY)  */
    { last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1); __quex_debug("last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1)\n"); }

_127:
    input = *(me->buffer._input_p);


    __quex_debug("Init State\n");
    __quex_debug_state(1531);
switch( input ) {
case 0x0: goto _122;
case 0x9: goto _14;
case 0xA: goto _10;
case 0xD: 
case 0x20: goto _16;
case 0x22: goto _11;
case 0x23: goto _9;
case 0x24: goto _19;
case 0x27: goto _8;
case 0x28: goto _5;
case 0x2B: 
case 0x2D: goto _12;
case 0x2E: goto _57;
case 0x2F: goto _58;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _6;
case 0x3B: goto _15;
case 0x3D: goto _18;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: goto _13;
case 0x65: goto _60;
case 0x66: goto _59;
case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _13;
case 0x7B: goto _17;
case 0x7D: goto _7;
default: goto _61;
}


    __quex_assert_no_passage();
_120:
    /* (1531 from RELOAD_FORWARD)  */
    ++(me->buffer._input_p);

    goto _127;


    __quex_assert_no_passage();
_61:
    /* (DROP_OUT from 1563) (DROP_OUT from 1550) (DROP_OUT from 1557) (DROP_OUT from 1560) (DROP_OUT from 1554) (DROP_OUT from 1567) (DROP_OUT from 1564) (DROP_OUT from 1558) (DROP_OUT from 1533) (DROP_OUT from 1555) (DROP_OUT from 1565) (DROP_OUT from 1559) (DROP_OUT from 1562) (DROP_OUT from 1556) (DROP_OUT from 1531) (DROP_OUT from 1543) (DROP_OUT from 1540) (DROP_OUT from 1568) (DROP_OUT from 1566)  */

        me->buffer._input_p = me->buffer._lexeme_start_p + 1;
goto _130;
_128:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_75:
    /* (DROP_OUT from 1551)  */
    goto _132;


    __quex_assert_no_passage();
_68:
    /* (DROP_OUT from 1541)  */
    goto _133;


    __quex_assert_no_passage();
_77:
    /* (DROP_OUT from 1569)  */
    goto _134;


    __quex_assert_no_passage();
_71:
    /* (DROP_OUT from 1546)  */
    goto _135;


    __quex_assert_no_passage();
_64:
    /* (DROP_OUT from 1536)  */
    goto _136;


    __quex_assert_no_passage();
_82:
    /* (DROP_OUT from 1583) (DROP_OUT from 1584)  */
    goto _131;


    __quex_assert_no_passage();
_76:
    /* (DROP_OUT from 1561)  */
    goto _137;


    __quex_assert_no_passage();
_78:
    /* (DROP_OUT from 1572)  */
    goto _138;


    __quex_assert_no_passage();
_72:
    /* (DROP_OUT from 1547)  */
    goto _139;


    __quex_assert_no_passage();
_65:
    /* (DROP_OUT from 1552) (DROP_OUT from 1553) (DROP_OUT from 1537)  */
    goto _140;


    __quex_assert_no_passage();
_79:
    /* (DROP_OUT from 1579)  */
    goto _141;


    __quex_assert_no_passage();
_73:
    /* (DROP_OUT from 1548)  */
    goto _142;


    __quex_assert_no_passage();
_66:
    /* (DROP_OUT from 1538)  */
    goto _143;


    __quex_assert_no_passage();
_69:
    /* (DROP_OUT from 1542)  */
    goto _144;


    __quex_assert_no_passage();
_62:
    /* (DROP_OUT from 1532)  */
    goto _145;


    __quex_assert_no_passage();
_80:
    /* (DROP_OUT from 1580)  */
    goto _146;


    __quex_assert_no_passage();
_74:
    /* (DROP_OUT from 1549)  */
    goto _147;


    __quex_assert_no_passage();
_67:
    /* (DROP_OUT from 1539)  */
    goto _148;


    __quex_assert_no_passage();
_70:
    /* (DROP_OUT from 1545)  */
    goto _149;


    __quex_assert_no_passage();
_63:
    /* (DROP_OUT from 1575) (DROP_OUT from 1578) (DROP_OUT from 1544) (DROP_OUT from 1573) (DROP_OUT from 1576) (DROP_OUT from 1570) (DROP_OUT from 1534) (DROP_OUT from 1574) (DROP_OUT from 1577) (DROP_OUT from 1571) (DROP_OUT from 1535)  */
    goto _150;


    __quex_assert_no_passage();
_81:
    /* (DROP_OUT from 1585) (DROP_OUT from 1582) (DROP_OUT from 1581)  */
switch( last_acceptance ) {
case 8:     __quex_assert(position[0] != (void*)0);
    me->buffer._input_p = position[0];
goto _131;
case ((QUEX_TYPE_ACCEPTANCE_ID)-1):     me->buffer._input_p = me->buffer._lexeme_start_p + 1;
goto _130;
}

    goto _128;


    __quex_assert_no_passage();
_5:
    /* (1536 from 1531)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1536);
goto _64;


    __quex_assert_no_passage();
_6:
    /* (1537 from 1537) (1537 from 1531) (1537 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1537);
switch( input ) {
case 0x0: goto _83;
case 0x2C: 
case 0x2E: goto _22;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _6;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _65;
}


    __quex_assert_no_passage();
_7:
    /* (1538 from 1531)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1538);
goto _66;


    __quex_assert_no_passage();
_8:
    /* (1539 from 1531)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1539);
goto _67;


    __quex_assert_no_passage();
_9:
    /* (1540 from 1540) (1540 from 1531) (1540 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1540);
switch( input ) {
case 0x0: goto _84;
case 0x9: case 0xA: 
case 0xD: 
case 0x20: goto _9;
case 0x69: goto _24;
case 0x73: goto _23;
default: goto _61;
}


    __quex_assert_no_passage();
_10:
    /* (1541 from 1531)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1541);
goto _68;


    __quex_assert_no_passage();
_11:
    /* (1542 from 1531)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1542);
goto _69;


    __quex_assert_no_passage();
_12:
    /* (1543 from 1531) (1543 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1543);
if     ( input >= 0x3A )  goto _61;
else if( input >= 0x30 )  goto _21;
else if( input >= 0x1 )   goto _61;
else                      goto _85;


    __quex_assert_no_passage();
_13:
    /* (1544 from 1571) (1544 from 1544) (1544 from 1535) (1544 from 1572) (1544 from 1531) (1544 from 1577) (1544 from RELOAD_FORWARD) (1544 from 1573) (1544 from 1578) (1544 from 1537) (1544 from 1576) (1544 from 1574) (1544 from 1579) (1544 from 1570) (1544 from 1575) (1544 from 1534)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1544);
switch( input ) {
case 0x0: goto _86;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _63;
}


    __quex_assert_no_passage();
_14:
    /* (1545 from 1531)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1545);
goto _70;


    __quex_assert_no_passage();
_15:
    /* (1546 from 1531)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1546);
goto _71;


    __quex_assert_no_passage();
_16:
    /* (1547 from 1531)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1547);
goto _72;


    __quex_assert_no_passage();
_17:
    /* (1548 from 1531)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1548);
goto _73;


    __quex_assert_no_passage();
_18:
    /* (1549 from 1531)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1549);
goto _74;


    __quex_assert_no_passage();
_19:
    /* (1550 from RELOAD_FORWARD) (1550 from 1531)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1550);
switch( input ) {
case 0x0: goto _87;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _20;
default: goto _61;
}


    __quex_assert_no_passage();
_20:
    /* (1551 from 1550) (1551 from 1551) (1551 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1551);
switch( input ) {
case 0x0: goto _88;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _20;
default: goto _75;
}


    __quex_assert_no_passage();
_21:
    /* (1552 from RELOAD_FORWARD) (1552 from 1552) (1552 from 1543)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1552);
switch( input ) {
case 0x0: goto _89;
case 0x2C: 
case 0x2E: goto _22;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _21;
default: goto _65;
}


    __quex_assert_no_passage();
_22:
    /* (1553 from 1552) (1553 from 1537) (1553 from RELOAD_FORWARD) (1553 from 1553)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1553);
if     ( input >= 0x3A )  goto _65;
else if( input >= 0x30 )  goto _22;
else if( input >= 0x1 )   goto _65;
else                      goto _90;


    __quex_assert_no_passage();
_23:
    /* (1554 from 1540) (1554 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1554);
if     ( input == 0x65 )  goto _31;
else if( input == 0x0 )   goto _91;
else                      goto _61;


    __quex_assert_no_passage();
_24:
    /* (1555 from RELOAD_FORWARD) (1555 from 1540)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1555);
if     ( input == 0x6E )  goto _25;
else if( input == 0x0 )   goto _92;
else                      goto _61;


    __quex_assert_no_passage();
_25:
    /* (1556 from 1555) (1556 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1556);
if     ( input == 0x63 )  goto _26;
else if( input == 0x0 )   goto _93;
else                      goto _61;


    __quex_assert_no_passage();
_26:
    /* (1557 from 1556) (1557 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1557);
if     ( input == 0x6C )  goto _27;
else if( input == 0x0 )   goto _94;
else                      goto _61;


    __quex_assert_no_passage();
_27:
    /* (1558 from RELOAD_FORWARD) (1558 from 1557)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1558);
if     ( input == 0x75 )  goto _28;
else if( input == 0x0 )   goto _95;
else                      goto _61;


    __quex_assert_no_passage();
_28:
    /* (1559 from 1558) (1559 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1559);
if     ( input == 0x64 )  goto _29;
else if( input == 0x0 )   goto _96;
else                      goto _61;


    __quex_assert_no_passage();
_29:
    /* (1560 from RELOAD_FORWARD) (1560 from 1559)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1560);
if     ( input == 0x65 )  goto _30;
else if( input == 0x0 )   goto _97;
else                      goto _61;


    __quex_assert_no_passage();
_30:
    /* (1561 from 1560)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1561);
goto _76;


    __quex_assert_no_passage();
_31:
    /* (1562 from RELOAD_FORWARD) (1562 from 1554)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1562);
if     ( input == 0x72 )  goto _32;
else if( input == 0x0 )   goto _98;
else                      goto _61;


    __quex_assert_no_passage();
_32:
    /* (1563 from 1562) (1563 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1563);
if     ( input == 0x69 )  goto _33;
else if( input == 0x0 )   goto _99;
else                      goto _61;


    __quex_assert_no_passage();
_33:
    /* (1564 from 1563) (1564 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1564);
if     ( input == 0x61 )  goto _34;
else if( input == 0x0 )   goto _100;
else                      goto _61;


    __quex_assert_no_passage();
_34:
    /* (1565 from 1564) (1565 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1565);
if     ( input == 0x6C )  goto _35;
else if( input == 0x0 )   goto _101;
else                      goto _61;


    __quex_assert_no_passage();
_35:
    /* (1566 from RELOAD_FORWARD) (1566 from 1565)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1566);
if     ( input == 0x69 )  goto _36;
else if( input == 0x0 )   goto _102;
else                      goto _61;


    __quex_assert_no_passage();
_36:
    /* (1567 from 1566) (1567 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1567);
if     ( input == 0x7A )  goto _37;
else if( input == 0x0 )   goto _103;
else                      goto _61;


    __quex_assert_no_passage();
_37:
    /* (1568 from RELOAD_FORWARD) (1568 from 1567)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1568);
if     ( input == 0x65 )  goto _38;
else if( input == 0x0 )   goto _104;
else                      goto _61;


    __quex_assert_no_passage();
_38:
    /* (1569 from 1568)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1569);
goto _77;


    __quex_assert_no_passage();
_39:
    /* (1570 from 1535) (1570 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1570);
switch( input ) {
case 0x0: goto _105;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: goto _13;
case 0x68: goto _40;
case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _63;
}


    __quex_assert_no_passage();
_40:
    /* (1571 from 1570) (1571 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1571);
switch( input ) {
case 0x0: goto _106;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: goto _13;
case 0x6F: goto _41;
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _63;
}


    __quex_assert_no_passage();
_41:
    /* (1572 from 1571) (1572 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1572);
switch( input ) {
case 0x0: goto _107;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _78;
}


    __quex_assert_no_passage();
_42:
    /* (1573 from 1534) (1573 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1573);
switch( input ) {
case 0x0: goto _108;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: goto _13;
case 0x6E: goto _43;
case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _63;
}


    __quex_assert_no_passage();
_43:
    /* (1574 from RELOAD_FORWARD) (1574 from 1573)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1574);
switch( input ) {
case 0x0: goto _109;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: goto _13;
case 0x63: goto _44;
case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _63;
}


    __quex_assert_no_passage();
_44:
    /* (1575 from 1574) (1575 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1575);
switch( input ) {
case 0x0: goto _110;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: goto _13;
case 0x74: goto _45;
case 0x75: case 0x76: case 0x77: case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _63;
}


    __quex_assert_no_passage();
_45:
    /* (1576 from RELOAD_FORWARD) (1576 from 1575)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1576);
switch( input ) {
case 0x0: goto _111;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: case 0x68: goto _13;
case 0x69: goto _46;
case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _63;
}


    __quex_assert_no_passage();
_46:
    /* (1577 from 1576) (1577 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1577);
switch( input ) {
case 0x0: goto _112;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: goto _13;
case 0x6F: goto _47;
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _63;
}


    __quex_assert_no_passage();
_47:
    /* (1578 from RELOAD_FORWARD) (1578 from 1577)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1578);
switch( input ) {
case 0x0: goto _113;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: goto _13;
case 0x6E: goto _48;
case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _63;
}


    __quex_assert_no_passage();
_48:
    /* (1579 from 1578) (1579 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1579);
switch( input ) {
case 0x0: goto _114;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _79;
}


    __quex_assert_no_passage();
_49:
    /* (1580 from 1533)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1580);
goto _80;


    __quex_assert_no_passage();
_51:
    /* (1581 from 1584)  */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_229:
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1581);
switch( input ) {
case 0x0: goto _115;
case 0x1: goto _81;
case 0xA: goto _54;
case 0x5C: goto _52;
default: goto _50;
}


    __quex_assert_no_passage();
_50:
    /* (1581 from 1533) (1581 from RELOAD_FORWARD) (1581 from 1582) (1581 from 1581) (1581 from 1585)  */
    goto _229;


    __quex_assert_no_passage();
_53:
    /* (1582 from 1584)  */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_231:
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1582);
switch( input ) {
case 0x0: goto _116;
case 0x1: goto _81;
case 0x9: goto _52;
case 0xA: goto _55;
case 0xD: goto _56;
case 0x20: 
case 0x5C: goto _52;
default: goto _50;
}


    __quex_assert_no_passage();
_52:
    /* (1582 from 1585) (1582 from RELOAD_FORWARD) (1582 from 1581) (1582 from 1582)  */
    goto _231;


    __quex_assert_no_passage();
_54:
    /* (1583 from 1581) (1583 from 1584)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1583);
goto _82;


    __quex_assert_no_passage();
_55:
    /* (1584 from 1585) (1584 from 1582)  */

    { last_acceptance = 8; __quex_debug("last_acceptance = 8\n"); }

_236:
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1584);
switch( input ) {
case 0x0: goto _118;
case 0x1: goto _82;
case 0xA: goto _54;
case 0x5C: goto _53;
default: goto _51;
}


    __quex_assert_no_passage();
_117:
    /* (1584 from RELOAD_FORWARD)  */
    goto _236;


    __quex_assert_no_passage();
_56:
    /* (1585 from RELOAD_FORWARD) (1585 from 1582)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1585);
switch( input ) {
case 0x0: goto _119;
case 0x1: goto _81;
case 0xA: goto _55;
case 0x5C: goto _52;
default: goto _50;
}


    __quex_assert_no_passage();
_57:
    /* (1532 from 1531)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1532);
goto _62;


    __quex_assert_no_passage();
_58:
    /* (1533 from RELOAD_FORWARD) (1533 from 1531)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1533);
switch( input ) {
case 0x0: goto _123;
case 0x2A: goto _49;
case 0x2F: goto _50;
default: goto _61;
}


    __quex_assert_no_passage();
_59:
    /* (1534 from RELOAD_FORWARD) (1534 from 1531)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1534);
switch( input ) {
case 0x0: goto _124;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: goto _13;
case 0x75: goto _42;
case 0x76: case 0x77: case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _63;
}


    __quex_assert_no_passage();
_60:
    /* (1535 from 1531) (1535 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1535);
switch( input ) {
case 0x0: goto _125;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: goto _13;
case 0x63: goto _39;
case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _13;
default: goto _63;
}

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_121:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    self_send (QUEX_TKN_TERMINATION);

    RETURN;


#   line 5018 "lexical_analyzer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
goto _3;
_130:
    __quex_debug("* TERMINAL FAILURE\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    self_send (QUEX_TKN_FAILURE);

    RETURN;


    self_accumulator_add (Lexeme, LexemeEnd);


    self_accumulator_add (Lexeme, LexemeEnd);


    self_accumulator_add (Lexeme, LexemeEnd);


    self_accumulator_add (Lexeme, LexemeEnd);


#   line 5046 "lexical_analyzer.cpp"

}
goto _1;
_0:
    __quex_debug("* TERMINAL character set skipper\n");

    /* (1624 from BEFORE_ENTRY)  */
_259:
    input = *(me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

_258:
    __quex_debug("Init State\n");
    __quex_debug_state(1624);
switch( input ) {
case 0x0: goto _256;
case 0x9: goto _248;
case 0xA: goto _250;
case 0xD: 
case 0x20: goto _249;
default: goto _247;
}


    __quex_assert_no_passage();
_257:
    /* (1624 from 1629)  */
    goto _258;


    __quex_assert_no_passage();
_255:
    /* (1624 from RELOAD_FORWARD)  */
    ++(me->buffer._input_p);

    goto _259;


    __quex_assert_no_passage();
_252:
    /* (DROP_OUT from 1626)  */
    goto _261;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_254:
    /* (DROP_OUT from 1628)  */
    goto _262;


    __quex_assert_no_passage();
_251:
    /* (DROP_OUT from 1625)  */
    goto _263;


    __quex_assert_no_passage();
_253:
    /* (DROP_OUT from 1627)  */
    goto _264;


    __quex_assert_no_passage();
_247:
    /* (1625 from 1624)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1625);
goto _251;


    __quex_assert_no_passage();
_248:
    /* (1626 from 1624)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1626);
goto _252;


    __quex_assert_no_passage();
_249:
    /* (1627 from 1624)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1627);
goto _253;


    __quex_assert_no_passage();
_250:
    /* (1628 from 1624)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1628);
goto _254;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_262:
    __quex_debug("* TERMINAL LINE\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

goto _257;

_261:
    __quex_debug("* TERMINAL GRID\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

goto _257;

_264:
    __quex_debug("* TERMINAL COLUMN\n");
goto _257;

_263:
    __quex_debug("* TERMINAL <BEYOND>\n");
    --(me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));

goto _1;


_133:
    __quex_debug("* TERMINAL <skip>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_LINES_ADD(1);
__QUEX_IF_COUNT_COLUMNS_SET(1);
{
goto _0;


#   line 5206 "lexical_analyzer.cpp"

}
goto _2;
_149:
    __quex_debug("* TERMINAL <skip>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

{
goto _0;


#   line 5221 "lexical_analyzer.cpp"

}
goto _2;
_139:
    __quex_debug("* TERMINAL <skip>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
goto _0;


#   line 5233 "lexical_analyzer.cpp"

}
goto _2;
_146:
    __quex_debug("* TERMINAL SKIP NESTED RANGE\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);

    Skipper1638_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1638_Opener;
    Skipper1638_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1638_Closer;
    /* text_end                           = QUEX_NAME(Buffer_text_end)(&me->buffer); */
    __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));


_269:
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
            goto _270;
        }
        if( input == *Skipper1638_Closer_it ) {
            ++Skipper1638_Closer_it;
            if( Skipper1638_Closer_it == Skipper1638_CloserEnd ) {
                if( counter == 0 ) {
                    /* NOTE: The initial state does not increment the input_p. When it detects that
                     * it is located on a buffer border, it automatically triggers a reload. No 
                     * need here to reload the buffer. */
                    ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
                            __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer)
                                    - reference_p));

                    /* No need for re-entry preparation. Acceptance flags and modes are untouched after skipping. */
                    goto _1; /* End of range reached. */
                }
                --counter;
                Skipper1638_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1638_Opener;
                Skipper1638_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1638_Closer;
                goto CONTINUE_1638;
            }
        } else {
            Skipper1638_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1638_Closer;
        }
        if( input == *Skipper1638_Opener_it ) {
            ++Skipper1638_Opener_it;
            if( Skipper1638_Opener_it == Skipper1638_OpenerEnd ) {
                ++counter;
                Skipper1638_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1638_Opener;
                Skipper1638_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper1638_Closer;
                goto CONTINUE_1638;
            }
        } else {
            Skipper1638_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper1638_Opener;
        }
CONTINUE_1638:

    __QUEX_IF_COUNT_IF( input == (QUEX_TYPE_CHARACTER)10 ) { 
        __QUEX_IF_COUNT_LINES_ADD((size_t)1);
        __QUEX_IF_COUNT_COLUMNS_SET((size_t)0);
        __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));
    }

        ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
    }

_270:
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
        goto _269; /* End of range reached.             */
    }
    /* Here, either the loading failed or it is not enough space to carry a closing delimiter */
    me->buffer._input_p = me->buffer._lexeme_start_p;
    #define Delimiter "{D_COMMENT_STREAM_ENDING}"
#define Counter counter
/**/QUEX_ERROR_EXIT("\nLexical analyzer mode 'SCOPE':\n"
    "End of file occurred before closing skip range delimiter!\n"
    "The 'on_skip_range_open' handler has not been specified.");
__QUEX_PURE_RETURN;
/**/
#undef Delimiter

#undef Counter


_131:
    __quex_debug("* TERMINAL \"//\"([^\\n]|(\\\\[ \\t]*\\r?\\n))*\\r?\\n\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    // We are within a comment. Do not do anything.


#   line 5358 "lexical_analyzer.cpp"

}
goto _2;
_134:
    __quex_debug("* TERMINAL {D_PRAGMA}{D_WHITESPACE}*\"serialize\"\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
self_send(QUEX_TKN_SERIALIZE);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5370 "lexical_analyzer.cpp"

}
goto _2;
_137:
    __quex_debug("* TERMINAL {D_PRAGMA}{D_WHITESPACE}*\"include\"\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
self_send(QUEX_TKN_INCLUDE);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5382 "lexical_analyzer.cpp"

}
goto _2;
_132:
    __quex_debug("* TERMINAL \\${D_IDENTIFIER}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
{
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
self_send(QUEX_TKN_IDENTIFIER_VARIABLE);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5396 "lexical_analyzer.cpp"

}
goto _2;
_138:
    __quex_debug("* TERMINAL {D_OUTPUT}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(4);
{
QUEX_NAME(push_mode)(&self, &EXPRESSION);self_send(QUEX_TKN_OUTPUT);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5409 "lexical_analyzer.cpp"

}
goto _2;
_141:
    __quex_debug("* TERMINAL \"function\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(8);
{
QUEX_NAME(push_mode)(&self, &FUNCTION_DEFINITION);self_send(QUEX_TKN_FUNCTION_DEFINITION);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5422 "lexical_analyzer.cpp"

}
goto _2;
_140:
    __quex_debug("* TERMINAL {D_NUMBER}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
{
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
self_send(QUEX_TKN_NUMBER);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5436 "lexical_analyzer.cpp"

}
goto _2;
_148:
    __quex_debug("* TERMINAL {D_QUOTE_SINGLE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(push_mode)(&self, &STRING_ABSOLUTE);self_send(QUEX_TKN_STRING_ABSOLUTE_BEGINNING);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5449 "lexical_analyzer.cpp"

}
goto _2;
_144:
    __quex_debug("* TERMINAL {D_QUOTE_DOUBLE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(push_mode)(&self, &STRING_RELATIVE);self_send(QUEX_TKN_STRING_RELATIVE_BEGINNING);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5462 "lexical_analyzer.cpp"

}
goto _2;
_135:
    __quex_debug("* TERMINAL {D_STATEMENT_END}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
self_send(QUEX_TKN_STATEMENT_END);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5475 "lexical_analyzer.cpp"

}
goto _2;
_145:
    __quex_debug("* TERMINAL {D_CONCATENATION}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
self_send(QUEX_TKN_CONCATENATION);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5488 "lexical_analyzer.cpp"

}
goto _2;
_150:
    __quex_debug("* TERMINAL {D_IDENTIFIER}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
{
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
self_send(QUEX_TKN_IDENTIFIER);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5502 "lexical_analyzer.cpp"

}
goto _2;
_142:
    __quex_debug("* TERMINAL \"{\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(push_mode)(&self, &SCOPE);self_send(QUEX_TKN_BRACE_BEGINNING);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5515 "lexical_analyzer.cpp"

}
goto _2;
_143:
    __quex_debug("* TERMINAL \"}\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_BRACE_END);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5528 "lexical_analyzer.cpp"

}
goto _2;
_136:
    __quex_debug("* TERMINAL \"(\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(push_mode)(&self, &EXPRESSION);self_send(QUEX_TKN_PARENTHESIS_BEGINNING);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5541 "lexical_analyzer.cpp"

}
goto _2;
_147:
    __quex_debug("* TERMINAL \"=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(push_mode)(&self, &EXPRESSION);self_send(QUEX_TKN_ASSIGNMENT);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 5554 "lexical_analyzer.cpp"

}
goto _2;
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_273:
    switch( target_state_index ) {
        case 6: { goto _6; }
        case 9: { goto _9; }
        case 12: { goto _12; }
        case 13: { goto _13; }
        case 19: { goto _19; }
        case 20: { goto _20; }
        case 21: { goto _21; }
        case 22: { goto _22; }
        case 23: { goto _23; }
        case 24: { goto _24; }
        case 25: { goto _25; }
        case 26: { goto _26; }
        case 27: { goto _27; }
        case 28: { goto _28; }
        case 29: { goto _29; }
        case 31: { goto _31; }
        case 32: { goto _32; }
        case 33: { goto _33; }
        case 34: { goto _34; }
        case 35: { goto _35; }
        case 36: { goto _36; }
        case 37: { goto _37; }
        case 39: { goto _39; }
        case 40: { goto _40; }
        case 41: { goto _41; }
        case 42: { goto _42; }
        case 43: { goto _43; }
        case 44: { goto _44; }
        case 45: { goto _45; }
        case 46: { goto _46; }
        case 47: { goto _47; }
        case 48: { goto _48; }
        case 50: { goto _50; }
        case 52: { goto _52; }
        case 56: { goto _56; }
        case 58: { goto _58; }
        case 59: { goto _59; }
        case 60: { goto _60; }
        case 61: { goto _61; }
        case 63: { goto _63; }
        case 65: { goto _65; }
        case 75: { goto _75; }
        case 78: { goto _78; }
        case 79: { goto _79; }
        case 81: { goto _81; }
        case 82: { goto _82; }
        case 117: { goto _117; }
        case 120: { goto _120; }
        case 121: { goto _121; }
        case 255: { goto _255; }

        default:
            __QUEX_STD_fprintf(stderr, "State router: index = %i\n", (int)target_state_index);
            QUEX_ERROR_EXIT("State router: unknown index.\n");
    }
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_118:
    /* (RELOAD_FORWARD from 1584)  */
    target_state_index = QUEX_LABEL(117); target_state_else_index = QUEX_LABEL(82);

_271:
    __quex_debug3("RELOAD_FORWARD: success->%i; failure->%i", (int)target_state_index, (int)target_state_else_index);
    __quex_assert(*(me->buffer._input_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {

        __quex_debug_reload_before();          /* Report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);   /* may use 'computed goto' */
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);  /* may use 'computed goto' */


    __quex_assert_no_passage();
_104:
    /* (RELOAD_FORWARD from 1568)  */
    target_state_index = QUEX_LABEL(37); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_86:
    /* (RELOAD_FORWARD from 1544)  */
    target_state_index = QUEX_LABEL(13); target_state_else_index = QUEX_LABEL(63);

    goto _271;


    __quex_assert_no_passage();
_109:
    /* (RELOAD_FORWARD from 1574)  */
    target_state_index = QUEX_LABEL(43); target_state_else_index = QUEX_LABEL(63);

    goto _271;


    __quex_assert_no_passage();
_100:
    /* (RELOAD_FORWARD from 1564)  */
    target_state_index = QUEX_LABEL(33); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_98:
    /* (RELOAD_FORWARD from 1562)  */
    target_state_index = QUEX_LABEL(31); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_123:
    /* (RELOAD_FORWARD from 1533)  */
    target_state_index = QUEX_LABEL(58); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_89:
    /* (RELOAD_FORWARD from 1552)  */
    target_state_index = QUEX_LABEL(21); target_state_else_index = QUEX_LABEL(65);

    goto _271;


    __quex_assert_no_passage();
_112:
    /* (RELOAD_FORWARD from 1577)  */
    target_state_index = QUEX_LABEL(46); target_state_else_index = QUEX_LABEL(63);

    goto _271;


    __quex_assert_no_passage();
_94:
    /* (RELOAD_FORWARD from 1557)  */
    target_state_index = QUEX_LABEL(26); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_116:
    /* (RELOAD_FORWARD from 1582)  */
    target_state_index = QUEX_LABEL(52); target_state_else_index = QUEX_LABEL(81);

    goto _271;


    __quex_assert_no_passage();
_103:
    /* (RELOAD_FORWARD from 1567)  */
    target_state_index = QUEX_LABEL(36); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_85:
    /* (RELOAD_FORWARD from 1543)  */
    target_state_index = QUEX_LABEL(12); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_108:
    /* (RELOAD_FORWARD from 1573)  */
    target_state_index = QUEX_LABEL(42); target_state_else_index = QUEX_LABEL(63);

    goto _271;


    __quex_assert_no_passage();
_99:
    /* (RELOAD_FORWARD from 1563)  */
    target_state_index = QUEX_LABEL(32); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_97:
    /* (RELOAD_FORWARD from 1560)  */
    target_state_index = QUEX_LABEL(29); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_122:
    /* (RELOAD_FORWARD from 1531)  */
    target_state_index = QUEX_LABEL(120); target_state_else_index = QUEX_LABEL(121);

    goto _271;


    __quex_assert_no_passage();
_88:
    /* (RELOAD_FORWARD from 1551)  */
    target_state_index = QUEX_LABEL(20); target_state_else_index = QUEX_LABEL(75);

    goto _271;


    __quex_assert_no_passage();
_111:
    /* (RELOAD_FORWARD from 1576)  */
    target_state_index = QUEX_LABEL(45); target_state_else_index = QUEX_LABEL(63);

    goto _271;


    __quex_assert_no_passage();
_93:
    /* (RELOAD_FORWARD from 1556)  */
    target_state_index = QUEX_LABEL(25); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_115:
    /* (RELOAD_FORWARD from 1581)  */
    target_state_index = QUEX_LABEL(50); target_state_else_index = QUEX_LABEL(81);

    goto _271;


    __quex_assert_no_passage();
_84:
    /* (RELOAD_FORWARD from 1540)  */
    target_state_index = QUEX_LABEL(9); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_107:
    /* (RELOAD_FORWARD from 1572)  */
    target_state_index = QUEX_LABEL(41); target_state_else_index = QUEX_LABEL(78);

    goto _271;


    __quex_assert_no_passage();
_106:
    /* (RELOAD_FORWARD from 1571)  */
    target_state_index = QUEX_LABEL(40); target_state_else_index = QUEX_LABEL(63);

    goto _271;


    __quex_assert_no_passage();
_96:
    /* (RELOAD_FORWARD from 1559)  */
    target_state_index = QUEX_LABEL(28); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_87:
    /* (RELOAD_FORWARD from 1550)  */
    target_state_index = QUEX_LABEL(19); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_102:
    /* (RELOAD_FORWARD from 1566)  */
    target_state_index = QUEX_LABEL(35); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_92:
    /* (RELOAD_FORWARD from 1555)  */
    target_state_index = QUEX_LABEL(24); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_125:
    /* (RELOAD_FORWARD from 1535)  */
    target_state_index = QUEX_LABEL(60); target_state_else_index = QUEX_LABEL(63);

    goto _271;


    __quex_assert_no_passage();
_83:
    /* (RELOAD_FORWARD from 1537)  */
    target_state_index = QUEX_LABEL(6); target_state_else_index = QUEX_LABEL(65);

    goto _271;


    __quex_assert_no_passage();
_114:
    /* (RELOAD_FORWARD from 1579)  */
    target_state_index = QUEX_LABEL(48); target_state_else_index = QUEX_LABEL(79);

    goto _271;


    __quex_assert_no_passage();
_119:
    /* (RELOAD_FORWARD from 1585)  */
    target_state_index = QUEX_LABEL(56); target_state_else_index = QUEX_LABEL(81);

    goto _271;


    __quex_assert_no_passage();
_105:
    /* (RELOAD_FORWARD from 1570)  */
    target_state_index = QUEX_LABEL(39); target_state_else_index = QUEX_LABEL(63);

    goto _271;


    __quex_assert_no_passage();
_95:
    /* (RELOAD_FORWARD from 1558)  */
    target_state_index = QUEX_LABEL(27); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_110:
    /* (RELOAD_FORWARD from 1575)  */
    target_state_index = QUEX_LABEL(44); target_state_else_index = QUEX_LABEL(63);

    goto _271;


    __quex_assert_no_passage();
_101:
    /* (RELOAD_FORWARD from 1565)  */
    target_state_index = QUEX_LABEL(34); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_91:
    /* (RELOAD_FORWARD from 1554)  */
    target_state_index = QUEX_LABEL(23); target_state_else_index = QUEX_LABEL(61);

    goto _271;


    __quex_assert_no_passage();
_124:
    /* (RELOAD_FORWARD from 1534)  */
    target_state_index = QUEX_LABEL(59); target_state_else_index = QUEX_LABEL(63);

    goto _271;


    __quex_assert_no_passage();
_90:
    /* (RELOAD_FORWARD from 1553)  */
    target_state_index = QUEX_LABEL(22); target_state_else_index = QUEX_LABEL(65);

    goto _271;


    __quex_assert_no_passage();
_113:
    /* (RELOAD_FORWARD from 1578)  */
    target_state_index = QUEX_LABEL(47); target_state_else_index = QUEX_LABEL(63);

    goto _271;


    __quex_assert_no_passage();
_256:
    /* (RELOAD_FORWARD from 1624)  */
    target_state_index = QUEX_LABEL(255); target_state_else_index = QUEX_LABEL(121);

    (me->buffer._lexeme_start_p) = (me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));

    goto _271;

_3:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_2:
/* CONTINUE -- after executing 'on_after_match' code. */

_1:
/* CONTINUE -- without executing 'on_after_match' (e.g. on FAILURE). */


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


goto _272;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _3; /* in RETURN                */
    goto _2; /* in CONTINUE              */
    goto _1; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _273; /* in QUEX_GOTO_STATE       */
#   endif

    /* Prevent compiler warning 'unused variable'.                           */
    (void)QUEX_LEXEME_NULL;
    (void)QUEX_NAME_TOKEN(DumpedTokenIdObject);
    /* target_state_index and target_state_else_index appear when 
     * QUEX_GOTO_STATE is used without computed goto-s.                      */
    (void)target_state_index;
    (void)target_state_else_index;

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL
#   undef COMMENT
#   undef FUNCTION_DEFINITION
#   undef STRING_RELATIVE
#   undef FAILURE
#   undef FUNCTION_DEFINITION_PARAMETERS
#   undef STRING_ABSOLUTE
#   undef SCOPE
#   undef EXPRESSION
#   undef self
#   undef QUEX_LABEL_STATE_ROUTER
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
#define   CONTINUE do { goto _2; } while(0)

#ifdef    RETURN
#   undef RETURN
#endif
#define   RETURN   do { goto _3; } while(0)
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
/*  'QUEX_GOTO_STATE' requires 'QUEX_LABEL_STATE_ROUTER' */
#   define QUEX_LABEL_STATE_ROUTER _315
#   define COMMENT                           (QUEX_NAME(COMMENT))
#   define FUNCTION_DEFINITION               (QUEX_NAME(FUNCTION_DEFINITION))
#   define STRING_RELATIVE                   (QUEX_NAME(STRING_RELATIVE))
#   define FAILURE                           (QUEX_NAME(FAILURE))
#   define FUNCTION_DEFINITION_PARAMETERS    (QUEX_NAME(FUNCTION_DEFINITION_PARAMETERS))
#   define STRING_ABSOLUTE                   (QUEX_NAME(STRING_ABSOLUTE))
#   define SCOPE                             (QUEX_NAME(SCOPE))
#   define EXPRESSION                        (QUEX_NAME(EXPRESSION))

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
    const QUEX_TYPE_CHARACTER      Skipper2037_Closer[2]          = { 0x2A, 0x2F,  };
    const QUEX_TYPE_CHARACTER      Skipper2037_Opener[2]          = { 0x2F, 0x2A,  };
    const QUEX_TYPE_CHARACTER*     Skipper2037_Closer_it          = 0x0;
    const QUEX_TYPE_CHARACTER*     Skipper2037_Opener_it          = 0x0;
    size_t                         counter                        = 0;
    const QUEX_TYPE_CHARACTER*     Skipper2037_OpenerEnd          = Skipper2037_Opener + (ptrdiff_t)2;
    const QUEX_TYPE_CHARACTER*     Skipper2037_CloserEnd          = Skipper2037_Closer + (ptrdiff_t)2;
    QUEX_TYPE_ACCEPTANCE_ID        last_acceptance               /* un-initilized */;
    const size_t                   PositionRegisterN              = (size_t)1;
    QUEX_TYPE_GOTO_LABEL           target_state_else_index        = QUEX_GOTO_LABEL_VOID;
    QUEX_TYPE_CHARACTER_POSITION   position[1]                    = { 0};
    QUEX_TYPE_CHARACTER            input                          = (QUEX_TYPE_CHARACTER)(0x00);
    QUEX_TYPE_GOTO_LABEL           target_state_index             = QUEX_GOTO_LABEL_VOID;
#   ifdef QUEX_OPTION_COLUMN_NUMBER_COUNTING
    QUEX_TYPE_CHARACTER_POSITION   reference_p                    = (QUEX_TYPE_CHARACTER_POSITION)0x0;
#   endif /* QUEX_OPTION_COLUMN_NUMBER_COUNTING */

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
_314:
    me->buffer._lexeme_start_p = me->buffer._input_p;
    QUEX_LEXEME_TERMINATING_ZERO_UNDO(&me->buffer);

    /* (1911 from BEFORE_ENTRY)  */
    { last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1); __quex_debug("last_acceptance = ((QUEX_TYPE_ACCEPTANCE_ID)-1)\n"); }

_150:
    input = *(me->buffer._input_p);


    __quex_debug("Init State\n");
    __quex_debug_state(1911);
switch( input ) {
case 0x0: goto _144;
case 0x9: goto _13;
case 0xA: goto _12;
case 0xD: 
case 0x20: goto _15;
case 0x21: goto _65;
case 0x22: goto _8;
case 0x24: goto _9;
case 0x25: goto _64;
case 0x26: goto _23;
case 0x27: goto _19;
case 0x28: goto _7;
case 0x29: goto _66;
case 0x2A: goto _60;
case 0x2B: goto _11;
case 0x2D: goto _20;
case 0x2E: goto _10;
case 0x2F: goto _22;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _17;
case 0x3B: goto _62;
case 0x3C: goto _18;
case 0x3D: goto _63;
case 0x3E: goto _61;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: goto _21;
case 0x5E: goto _6;
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: goto _21;
case 0x65: goto _14;
case 0x66: case 0x67: case 0x68: goto _21;
case 0x69: goto _59;
case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: goto _21;
case 0x74: goto _5;
case 0x75: case 0x76: case 0x77: case 0x78: case 0x79: case 0x7A: goto _21;
case 0x7C: goto _16;
default: goto _67;
}


    __quex_assert_no_passage();
_142:
    /* (1911 from RELOAD_FORWARD)  */
    ++(me->buffer._input_p);

    goto _150;


    __quex_assert_no_passage();
_67:
    /* (DROP_OUT from 1916) (DROP_OUT from 1931) (DROP_OUT from 1938) (DROP_OUT from 1911) (DROP_OUT from 1937) (DROP_OUT from 1924)  */

        me->buffer._input_p = me->buffer._lexeme_start_p + 1;
goto _153;
_151:
    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_94:
    /* (DROP_OUT from 1953)  */
    goto _154;


    __quex_assert_no_passage();
_87:
    /* (DROP_OUT from 1939)  */
    goto _155;


    __quex_assert_no_passage();
_81:
    /* (DROP_OUT from 1928)  */
    goto _156;


    __quex_assert_no_passage();
_74:
    /* (DROP_OUT from 1919)  */
    goto _157;


    __quex_assert_no_passage();
_83:
    /* (DROP_OUT from 1947) (DROP_OUT from 1932) (DROP_OUT from 1946)  */
    goto _158;


    __quex_assert_no_passage();
_77:
    /* (DROP_OUT from 1923)  */
    goto _159;


    __quex_assert_no_passage();
_70:
    /* (DROP_OUT from 1914)  */
    goto _161;


    __quex_assert_no_passage();
_95:
    /* (DROP_OUT from 1955)  */
    goto _162;


    __quex_assert_no_passage();
_99:
    /* (DROP_OUT from 1959)  */
    goto _163;


    __quex_assert_no_passage();
_88:
    /* (DROP_OUT from 1940)  */
    goto _164;


    __quex_assert_no_passage();
_82:
    /* (DROP_OUT from 1930)  */
    goto _165;


    __quex_assert_no_passage();
_91:
    /* (DROP_OUT from 1948)  */
    goto _166;


    __quex_assert_no_passage();
_84:
    /* (DROP_OUT from 1933)  */
    goto _167;


    __quex_assert_no_passage();
_78:
    /* (DROP_OUT from 1925)  */
    goto _168;


    __quex_assert_no_passage();
_71:
    /* (DROP_OUT from 1915)  */
    goto _169;


    __quex_assert_no_passage();
_96:
    /* (DROP_OUT from 1956)  */
    goto _170;


    __quex_assert_no_passage();
_100:
    /* (DROP_OUT from 1960)  */
    goto _171;


    __quex_assert_no_passage();
_92:
    /* (DROP_OUT from 1949)  */
    goto _173;


    __quex_assert_no_passage();
_85:
    /* (DROP_OUT from 1934)  */
    goto _174;


    __quex_assert_no_passage();
_79:
    /* (DROP_OUT from 1926)  */
    goto _175;


    __quex_assert_no_passage();
_105:
    /* (DROP_OUT from 1971)  */
    goto _176;


    __quex_assert_no_passage();
_72:
    /* (DROP_OUT from 1917)  */
    goto _177;


    __quex_assert_no_passage();
_97:
    /* (DROP_OUT from 1957)  */
    goto _178;


    __quex_assert_no_passage();
_75:
    /* (DROP_OUT from 1921)  */
    goto _179;


    __quex_assert_no_passage();
_90:
    /* (DROP_OUT from 1944) (DROP_OUT from 1943)  */
    goto _172;


    __quex_assert_no_passage();
_68:
    /* (DROP_OUT from 1962) (DROP_OUT from 1951) (DROP_OUT from 1966) (DROP_OUT from 1963) (DROP_OUT from 1954) (DROP_OUT from 1929) (DROP_OUT from 1936) (DROP_OUT from 1920) (DROP_OUT from 1964) (DROP_OUT from 1961) (DROP_OUT from 1912) (DROP_OUT from 1950) (DROP_OUT from 1965)  */
    goto _160;


    __quex_assert_no_passage();
_93:
    /* (DROP_OUT from 1952)  */
    goto _180;


    __quex_assert_no_passage();
_86:
    /* (DROP_OUT from 1935)  */
    goto _181;


    __quex_assert_no_passage();
_80:
    /* (DROP_OUT from 1927)  */
    goto _182;


    __quex_assert_no_passage();
_73:
    /* (DROP_OUT from 1918)  */
    goto _183;


    __quex_assert_no_passage();
_98:
    /* (DROP_OUT from 1958)  */
    goto _184;


    __quex_assert_no_passage();
_76:
    /* (DROP_OUT from 1922)  */
    goto _185;


    __quex_assert_no_passage();
_69:
    /* (DROP_OUT from 1913)  */
    goto _186;


    __quex_assert_no_passage();
_103:
    /* (DROP_OUT from 1969)  */
        me->buffer._input_p -= 3;
goto _160;
    goto _151;


    __quex_assert_no_passage();
_104:
    /* (DROP_OUT from 1970)  */
        me->buffer._input_p -= 4;
goto _160;
    goto _151;


    __quex_assert_no_passage();
_89:
    /* (DROP_OUT from 1941) (DROP_OUT from 1942) (DROP_OUT from 1945)  */
switch( last_acceptance ) {
case 8:     __quex_assert(position[0] != (void*)0);
    me->buffer._input_p = position[0];
goto _172;
case ((QUEX_TYPE_ACCEPTANCE_ID)-1):     me->buffer._input_p = me->buffer._lexeme_start_p + 1;
goto _153;
}

    goto _151;


    __quex_assert_no_passage();
_101:
    /* (DROP_OUT from 1967)  */
        me->buffer._input_p -= 1;
goto _160;
    goto _151;


    __quex_assert_no_passage();
_102:
    /* (DROP_OUT from 1968)  */
        me->buffer._input_p -= 2;
goto _160;
    goto _151;


    __quex_assert_no_passage();
_5:
    /* (1920 from RELOAD_FORWARD) (1920 from 1911)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1920);
switch( input ) {
case 0x0: goto _106;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: goto _21;
case 0x61: goto _41;
case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _68;
}


    __quex_assert_no_passage();
_6:
    /* (1921 from 1911)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1921);
goto _75;


    __quex_assert_no_passage();
_7:
    /* (1922 from 1911)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1922);
goto _76;


    __quex_assert_no_passage();
_8:
    /* (1923 from 1911)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1923);
goto _77;


    __quex_assert_no_passage();
_9:
    /* (1924 from 1911) (1924 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1924);
switch( input ) {
case 0x0: goto _107;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _40;
default: goto _67;
}


    __quex_assert_no_passage();
_10:
    /* (1925 from 1911)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1925);
goto _78;


    __quex_assert_no_passage();
_11:
    /* (1926 from RELOAD_FORWARD) (1926 from 1911)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1926);
if     ( input >= 0x3A )  goto _79;
else if( input >= 0x30 )  goto _33;
else if( input >= 0x1 )   goto _79;
else                      goto _108;


    __quex_assert_no_passage();
_12:
    /* (1927 from 1911)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1927);
goto _80;


    __quex_assert_no_passage();
_13:
    /* (1928 from 1911)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1928);
goto _81;


    __quex_assert_no_passage();
_14:
    /* (1929 from RELOAD_FORWARD) (1929 from 1911)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1929);
switch( input ) {
case 0x0: goto _109;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: goto _21;
case 0x6E: goto _37;
case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _68;
}


    __quex_assert_no_passage();
_15:
    /* (1930 from 1911)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1930);
goto _82;


    __quex_assert_no_passage();
_16:
    /* (1931 from RELOAD_FORWARD) (1931 from 1911)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1931);
if     ( input == 0x7C )  goto _36;
else if( input == 0x0 )   goto _110;
else                      goto _67;


    __quex_assert_no_passage();
_17:
    /* (1932 from 1911) (1932 from 1932) (1932 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1932);
switch( input ) {
case 0x0: goto _111;
case 0x2C: 
case 0x2E: goto _34;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _17;
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _83;
}


    __quex_assert_no_passage();
_18:
    /* (1933 from 1911) (1933 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1933);
if     ( input == 0x3D )  goto _35;
else if( input == 0x0 )   goto _112;
else                      goto _84;


    __quex_assert_no_passage();
_19:
    /* (1934 from 1911)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1934);
goto _85;


    __quex_assert_no_passage();
_20:
    /* (1935 from 1911) (1935 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1935);
if     ( input >= 0x3A )  goto _86;
else if( input >= 0x30 )  goto _33;
else if( input >= 0x1 )   goto _86;
else                      goto _113;


    __quex_assert_no_passage();
_21:
    /* (1936 from 1963) (1936 from 1920) (1936 from 1911) (1936 from 1950) (1936 from 1932) (1936 from RELOAD_FORWARD) (1936 from 1964) (1936 from 1951) (1936 from 1961) (1936 from 1965) (1936 from 1936) (1936 from 1954) (1936 from 1929) (1936 from 1952) (1936 from 1966) (1936 from 1955) (1936 from 1962) (1936 from 1912)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1936);
switch( input ) {
case 0x0: goto _114;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _68;
}


    __quex_assert_no_passage();
_22:
    /* (1937 from RELOAD_FORWARD) (1937 from 1911)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1937);
switch( input ) {
case 0x0: goto _115;
case 0x2A: goto _25;
case 0x2F: goto _26;
default: goto _67;
}


    __quex_assert_no_passage();
_23:
    /* (1938 from 1911) (1938 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1938);
if     ( input == 0x26 )  goto _24;
else if( input == 0x0 )   goto _116;
else                      goto _67;


    __quex_assert_no_passage();
_24:
    /* (1939 from 1938)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1939);
goto _87;


    __quex_assert_no_passage();
_25:
    /* (1940 from 1937)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1940);
goto _88;


    __quex_assert_no_passage();
_27:
    /* (1941 from 1944)  */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_220:
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1941);
switch( input ) {
case 0x0: goto _117;
case 0x1: goto _89;
case 0xA: goto _30;
case 0x5C: goto _28;
default: goto _26;
}


    __quex_assert_no_passage();
_26:
    /* (1941 from RELOAD_FORWARD) (1941 from 1945) (1941 from 1942) (1941 from 1937) (1941 from 1941)  */
    goto _220;


    __quex_assert_no_passage();
_29:
    /* (1942 from 1944)  */
    position[0] = me->buffer._input_p; __quex_debug("position[0] = input_p;\n");

_222:
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1942);
switch( input ) {
case 0x0: goto _118;
case 0x1: goto _89;
case 0x9: goto _28;
case 0xA: goto _31;
case 0xD: goto _32;
case 0x20: 
case 0x5C: goto _28;
default: goto _26;
}


    __quex_assert_no_passage();
_28:
    /* (1942 from 1945) (1942 from 1941) (1942 from RELOAD_FORWARD) (1942 from 1942)  */
    goto _222;


    __quex_assert_no_passage();
_30:
    /* (1943 from 1941) (1943 from 1944)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1943);
goto _90;


    __quex_assert_no_passage();
_31:
    /* (1944 from 1945) (1944 from 1942)  */

    { last_acceptance = 8; __quex_debug("last_acceptance = 8\n"); }

_227:
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1944);
switch( input ) {
case 0x0: goto _120;
case 0x1: goto _90;
case 0xA: goto _30;
case 0x5C: goto _29;
default: goto _27;
}


    __quex_assert_no_passage();
_119:
    /* (1944 from RELOAD_FORWARD)  */
    goto _227;


    __quex_assert_no_passage();
_32:
    /* (1945 from RELOAD_FORWARD) (1945 from 1942)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1945);
switch( input ) {
case 0x0: goto _121;
case 0x1: goto _89;
case 0xA: goto _31;
case 0x5C: goto _28;
default: goto _26;
}


    __quex_assert_no_passage();
_33:
    /* (1946 from 1935) (1946 from 1926) (1946 from RELOAD_FORWARD) (1946 from 1946)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1946);
switch( input ) {
case 0x0: goto _122;
case 0x2C: 
case 0x2E: goto _34;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: goto _33;
default: goto _83;
}


    __quex_assert_no_passage();
_34:
    /* (1947 from 1946) (1947 from 1947) (1947 from RELOAD_FORWARD) (1947 from 1932)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1947);
if     ( input >= 0x3A )  goto _83;
else if( input >= 0x30 )  goto _34;
else if( input >= 0x1 )   goto _83;
else                      goto _123;


    __quex_assert_no_passage();
_35:
    /* (1948 from 1933)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1948);
goto _91;


    __quex_assert_no_passage();
_36:
    /* (1949 from 1931)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1949);
goto _92;


    __quex_assert_no_passage();
_37:
    /* (1950 from 1929) (1950 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1950);
switch( input ) {
case 0x0: goto _124;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: goto _21;
case 0x64: goto _38;
case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _68;
}


    __quex_assert_no_passage();
_38:
    /* (1951 from 1950) (1951 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1951);
switch( input ) {
case 0x0: goto _125;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: goto _21;
case 0x6C: goto _39;
case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _68;
}


    __quex_assert_no_passage();
_39:
    /* (1952 from RELOAD_FORWARD) (1952 from 1951)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1952);
switch( input ) {
case 0x0: goto _126;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _93;
}


    __quex_assert_no_passage();
_40:
    /* (1953 from 1953) (1953 from 1924) (1953 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1953);
switch( input ) {
case 0x0: goto _127;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _40;
default: goto _94;
}


    __quex_assert_no_passage();
_41:
    /* (1954 from RELOAD_FORWARD) (1954 from 1920)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1954);
switch( input ) {
case 0x0: goto _128;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: goto _21;
case 0x62: goto _42;
case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _68;
}


    __quex_assert_no_passage();
_42:
    /* (1955 from 1954) (1955 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1955);
switch( input ) {
case 0x0: goto _129;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _95;
}


    __quex_assert_no_passage();
_43:
    /* (1956 from 1918) (1956 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1956);
if     ( input == 0x3D )  goto _44;
else if( input == 0x0 )   goto _130;
else                      goto _96;


    __quex_assert_no_passage();
_44:
    /* (1957 from 1956)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1957);
goto _97;


    __quex_assert_no_passage();
_45:
    /* (1958 from RELOAD_FORWARD) (1958 from 1916)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1958);
if     ( input == 0x3D )  goto _46;
else if( input == 0x0 )   goto _131;
else                      goto _98;


    __quex_assert_no_passage();
_46:
    /* (1959 from 1958)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1959);
goto _99;


    __quex_assert_no_passage();
_47:
    /* (1960 from 1914)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1960);
goto _100;


    __quex_assert_no_passage();
_48:
    /* (1961 from 1912) (1961 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1961);
switch( input ) {
case 0x0: goto _132;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: goto _21;
case 0x76: goto _49;
case 0x77: case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _68;
}


    __quex_assert_no_passage();
_49:
    /* (1962 from RELOAD_FORWARD) (1962 from 1961)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1962);
switch( input ) {
case 0x0: goto _133;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: goto _21;
case 0x65: goto _50;
case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _68;
}


    __quex_assert_no_passage();
_50:
    /* (1963 from 1962) (1963 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1963);
switch( input ) {
case 0x0: goto _134;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: goto _21;
case 0x72: goto _51;
case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _68;
}


    __quex_assert_no_passage();
_51:
    /* (1964 from 1963) (1964 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1964);
switch( input ) {
case 0x0: goto _135;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: goto _21;
case 0x73: goto _52;
case 0x74: case 0x75: case 0x76: case 0x77: case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _68;
}


    __quex_assert_no_passage();
_52:
    /* (1965 from 1964) (1965 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1965);
switch( input ) {
case 0x0: goto _136;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: goto _21;
case 0x65: goto _53;
case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _68;
}


    __quex_assert_no_passage();
_53:
    /* (1966 from RELOAD_FORWARD) (1966 from 1965)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1966);
switch( input ) {
case 0x0: goto _137;
case 0x2F: goto _54;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: case 0x6E: case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _68;
}


    __quex_assert_no_passage();
_54:
    /* (1967 from 1966) (1967 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1967);
if     ( input == 0x7B )  goto _55;
else if( input == 0x0 )   goto _138;
else                      goto _101;


    __quex_assert_no_passage();
_55:
    /* (1968 from RELOAD_FORWARD) (1968 from 1967)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1968);
if     ( input == 0x32 )  goto _56;
else if( input == 0x0 )   goto _139;
else                      goto _102;


    __quex_assert_no_passage();
_56:
    /* (1969 from 1968) (1969 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1969);
if     ( input == 0x2C )  goto _57;
else if( input == 0x0 )   goto _140;
else                      goto _103;


    __quex_assert_no_passage();
_57:
    /* (1970 from RELOAD_FORWARD) (1970 from 1969)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1970);
if     ( input == 0x7D )  goto _58;
else if( input == 0x0 )   goto _141;
else                      goto _104;


    __quex_assert_no_passage();
_58:
    /* (1971 from 1970)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1971);
goto _105;


    __quex_assert_no_passage();
_59:
    /* (1912 from RELOAD_FORWARD) (1912 from 1911)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1912);
switch( input ) {
case 0x0: goto _145;
case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: 
case 0x38: case 0x39: 
case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: 
case 0x48: case 0x49: case 0x4A: case 0x4B: case 0x4C: case 0x4D: case 0x4E: case 0x4F: 
case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57: 
case 0x58: case 0x59: case 0x5A: 
case 0x5F: 
case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: 
case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D: goto _21;
case 0x6E: goto _48;
case 0x6F: 
case 0x70: case 0x71: case 0x72: case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: 
case 0x78: case 0x79: case 0x7A: goto _21;
default: goto _68;
}


    __quex_assert_no_passage();
_60:
    /* (1913 from 1911)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1913);
goto _69;


    __quex_assert_no_passage();
_61:
    /* (1914 from 1911) (1914 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1914);
if     ( input == 0x3D )  goto _47;
else if( input == 0x0 )   goto _146;
else                      goto _70;


    __quex_assert_no_passage();
_62:
    /* (1915 from 1911)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1915);
goto _71;


    __quex_assert_no_passage();
_63:
    /* (1916 from 1911) (1916 from RELOAD_FORWARD)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1916);
if     ( input == 0x3D )  goto _45;
else if( input == 0x0 )   goto _147;
else                      goto _67;


    __quex_assert_no_passage();
_64:
    /* (1917 from 1911)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1917);
goto _72;


    __quex_assert_no_passage();
_65:
    /* (1918 from RELOAD_FORWARD) (1918 from 1911)  */

    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1918);
if     ( input == 0x3D )  goto _43;
else if( input == 0x0 )   goto _148;
else                      goto _73;


    __quex_assert_no_passage();
_66:
    /* (1919 from 1911)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(1919);
goto _74;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_143:
    __quex_debug("* TERMINAL END_OF_STREAM\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    self_send (QUEX_TKN_TERMINATION);

    RETURN;


#   line 7618 "lexical_analyzer.cpp"

}
    /* End of Stream FORCES a return from the lexical analyzer, so that no
     * tokens can be filled after the termination token.
     */
goto _3;
_153:
    __quex_debug("* TERMINAL FAILURE\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    self_send (QUEX_TKN_FAILURE);

    RETURN;


    self_accumulator_add (Lexeme, LexemeEnd);


    self_accumulator_add (Lexeme, LexemeEnd);


    self_accumulator_add (Lexeme, LexemeEnd);


    self_accumulator_add (Lexeme, LexemeEnd);


    self_accumulator_add (Lexeme, LexemeEnd);


#   line 7649 "lexical_analyzer.cpp"

}
goto _1;
_0:
    __quex_debug("* TERMINAL character set skipper\n");

    /* (2023 from BEFORE_ENTRY)  */
_301:
    input = *(me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

_300:
    __quex_debug("Init State\n");
    __quex_debug_state(2023);
switch( input ) {
case 0x0: goto _298;
case 0x9: goto _292;
case 0xA: goto _290;
case 0xD: 
case 0x20: goto _289;
default: goto _291;
}


    __quex_assert_no_passage();
_299:
    /* (2023 from 2028)  */
    goto _300;


    __quex_assert_no_passage();
_297:
    /* (2023 from RELOAD_FORWARD)  */
    ++(me->buffer._input_p);

    goto _301;


    __quex_assert_no_passage();
_293:
    /* (DROP_OUT from 2024)  */
    goto _303;

    __quex_debug("Drop-Out Catcher\n");


    __quex_assert_no_passage();
_295:
    /* (DROP_OUT from 2026)  */
    goto _304;


    __quex_assert_no_passage();
_294:
    /* (DROP_OUT from 2025)  */
    goto _305;


    __quex_assert_no_passage();
_296:
    /* (DROP_OUT from 2027)  */
    goto _306;


    __quex_assert_no_passage();
_289:
    /* (2024 from 2023)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(2024);
goto _293;


    __quex_assert_no_passage();
_290:
    /* (2025 from 2023)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(2025);
goto _294;


    __quex_assert_no_passage();
_291:
    /* (2026 from 2023)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(2026);
goto _295;


    __quex_assert_no_passage();
_292:
    /* (2027 from 2023)  */
    ++(me->buffer._input_p);

    input = *(me->buffer._input_p);


    __quex_debug_state(2027);
goto _296;

    /* (*) Terminal states _______________________________________________________
     *
     * States that implement actions of the 'winner patterns.                     */
_305:
    __quex_debug("* TERMINAL LINE\n");
__QUEX_IF_COUNT_LINES_ADD((size_t)1);

    __QUEX_IF_COUNT_COLUMNS((me->counter._column_number_at_end) = (size_t)1);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

goto _299;

_306:
    __quex_debug("* TERMINAL GRID\n");
__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p - 1)));

__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

__QUEX_IF_COUNT_COLUMNS(reference_p = (me->buffer._input_p));

goto _299;

_303:
    __quex_debug("* TERMINAL COLUMN\n");
goto _299;

_304:
    __quex_debug("* TERMINAL <BEYOND>\n");
    --(me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));

goto _1;


_182:
    __quex_debug("* TERMINAL <skip>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_LINES_ADD(1);
__QUEX_IF_COUNT_COLUMNS_SET(1);
{
goto _0;


#   line 7809 "lexical_analyzer.cpp"

}
goto _2;
_156:
    __quex_debug("* TERMINAL <skip>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end -= 1);
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end &= ~ ((size_t)0x3));
__QUEX_IF_COUNT_COLUMNS(self.counter._column_number_at_end += 4 + 1);

{
goto _0;


#   line 7824 "lexical_analyzer.cpp"

}
goto _2;
_165:
    __quex_debug("* TERMINAL <skip>\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
goto _0;


#   line 7836 "lexical_analyzer.cpp"

}
goto _2;
_164:
    __quex_debug("* TERMINAL SKIP NESTED RANGE\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);

    Skipper2037_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper2037_Opener;
    Skipper2037_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper2037_Closer;
    /* text_end                           = QUEX_NAME(Buffer_text_end)(&me->buffer); */
    __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));


_311:
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
            goto _312;
        }
        if( input == *Skipper2037_Closer_it ) {
            ++Skipper2037_Closer_it;
            if( Skipper2037_Closer_it == Skipper2037_CloserEnd ) {
                if( counter == 0 ) {
                    /* NOTE: The initial state does not increment the input_p. When it detects that
                     * it is located on a buffer border, it automatically triggers a reload. No 
                     * need here to reload the buffer. */
                    ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
                            __QUEX_IF_COUNT_COLUMNS_ADD((size_t)(QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer)
                                    - reference_p));

                    /* No need for re-entry preparation. Acceptance flags and modes are untouched after skipping. */
                    goto _1; /* End of range reached. */
                }
                --counter;
                Skipper2037_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper2037_Opener;
                Skipper2037_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper2037_Closer;
                goto CONTINUE_2037;
            }
        } else {
            Skipper2037_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper2037_Closer;
        }
        if( input == *Skipper2037_Opener_it ) {
            ++Skipper2037_Opener_it;
            if( Skipper2037_Opener_it == Skipper2037_OpenerEnd ) {
                ++counter;
                Skipper2037_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper2037_Opener;
                Skipper2037_Closer_it = (QUEX_TYPE_CHARACTER*)Skipper2037_Closer;
                goto CONTINUE_2037;
            }
        } else {
            Skipper2037_Opener_it = (QUEX_TYPE_CHARACTER*)Skipper2037_Opener;
        }
CONTINUE_2037:

    __QUEX_IF_COUNT_IF( input == (QUEX_TYPE_CHARACTER)10 ) { 
        __QUEX_IF_COUNT_LINES_ADD((size_t)1);
        __QUEX_IF_COUNT_COLUMNS_SET((size_t)0);
        __QUEX_IF_COUNT_COLUMNS(reference_p = QUEX_NAME(Buffer_tell_memory_adr)(&me->buffer));
    }

        ++(me->buffer._input_p); /* Now, BLC cannot occur. See above. */
    }

_312:
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
        goto _311; /* End of range reached.             */
    }
    /* Here, either the loading failed or it is not enough space to carry a closing delimiter */
    me->buffer._input_p = me->buffer._lexeme_start_p;
    #define Delimiter "{D_COMMENT_STREAM_ENDING}"
#define Counter counter
/**/QUEX_ERROR_EXIT("\nLexical analyzer mode 'EXPRESSION':\n"
    "End of file occurred before closing skip range delimiter!\n"
    "The 'on_skip_range_open' handler has not been specified.");
__QUEX_PURE_RETURN;
/**/
#undef Delimiter

#undef Counter


_172:
    __quex_debug("* TERMINAL \"//\"([^\\n]|(\\\\[ \\t]*\\r?\\n))*\\r?\\n\n");
__QUEX_COUNT_VOID(&self, LexemeBegin, LexemeEnd);
{
    // We are within a comment. Do not do anything.


#   line 7961 "lexical_analyzer.cpp"

}
goto _2;
_175:
    __quex_debug("* TERMINAL \"+\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
self_send(QUEX_TKN_ADDITION);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 7974 "lexical_analyzer.cpp"

}
goto _2;
_181:
    __quex_debug("* TERMINAL \"-\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
self_send(QUEX_TKN_SUBSTRACTION);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 7987 "lexical_analyzer.cpp"

}
goto _2;
_186:
    __quex_debug("* TERMINAL \"*\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
self_send(QUEX_TKN_MULTIPLICATION);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8000 "lexical_analyzer.cpp"

}
goto _2;
_176:
    __quex_debug("* TERMINAL {D_DIVISION}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(12);
{
self_send(QUEX_TKN_DIVISION);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8013 "lexical_analyzer.cpp"

}
goto _2;
_177:
    __quex_debug("* TERMINAL \"%\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
self_send(QUEX_TKN_MODULO);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8026 "lexical_analyzer.cpp"

}
goto _2;
_179:
    __quex_debug("* TERMINAL \"^\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
self_send(QUEX_TKN_EXPONENTIATION);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8039 "lexical_analyzer.cpp"

}
goto _2;
_155:
    __quex_debug("* TERMINAL \"&&\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{
self_send(QUEX_TKN_LOGIC_AND);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8052 "lexical_analyzer.cpp"

}
goto _2;
_173:
    __quex_debug("* TERMINAL \"||\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{
self_send(QUEX_TKN_LOGIC_OR);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8065 "lexical_analyzer.cpp"

}
goto _2;
_163:
    __quex_debug("* TERMINAL \"===\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(3);
{
self_send(QUEX_TKN_EQUALITY_ABSOLUTE);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8078 "lexical_analyzer.cpp"

}
goto _2;
_178:
    __quex_debug("* TERMINAL \"!==\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(3);
{
self_send(QUEX_TKN_INEQUALITY_ABSOLUTE);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8091 "lexical_analyzer.cpp"

}
goto _2;
_184:
    __quex_debug("* TERMINAL \"==\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{
self_send(QUEX_TKN_EQUALITY_RELATIVE);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8104 "lexical_analyzer.cpp"

}
goto _2;
_170:
    __quex_debug("* TERMINAL \"!=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{
self_send(QUEX_TKN_INEQUALITY_RELATIVE);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8117 "lexical_analyzer.cpp"

}
goto _2;
_183:
    __quex_debug("* TERMINAL \"!\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
self_send(QUEX_TKN_NEGATION);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8130 "lexical_analyzer.cpp"

}
goto _2;
_161:
    __quex_debug("* TERMINAL \">\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
self_send(QUEX_TKN_GREATER);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8143 "lexical_analyzer.cpp"

}
goto _2;
_167:
    __quex_debug("* TERMINAL \"<\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
self_send(QUEX_TKN_LOWER);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8156 "lexical_analyzer.cpp"

}
goto _2;
_171:
    __quex_debug("* TERMINAL \">=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{
self_send(QUEX_TKN_GREATER_EQUAL);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8169 "lexical_analyzer.cpp"

}
goto _2;
_166:
    __quex_debug("* TERMINAL \"<=\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(2);
{
self_send(QUEX_TKN_LOWER_EQUAL);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8182 "lexical_analyzer.cpp"

}
goto _2;
_169:
    __quex_debug("* TERMINAL {D_STATEMENT_END}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_STATEMENT_END);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8195 "lexical_analyzer.cpp"

}
goto _2;
_157:
    __quex_debug("* TERMINAL \")\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(pop_mode)(&self);self_send(QUEX_TKN_PARENTHESIS_END);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8208 "lexical_analyzer.cpp"

}
goto _2;
_185:
    __quex_debug("* TERMINAL \"(\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(push_mode)(&self, &EXPRESSION);self_send(QUEX_TKN_PARENTHESIS_BEGINNING);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8221 "lexical_analyzer.cpp"

}
goto _2;
_154:
    __quex_debug("* TERMINAL \\${D_IDENTIFIER}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
{
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
self_send(QUEX_TKN_IDENTIFIER_VARIABLE);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8235 "lexical_analyzer.cpp"

}
goto _2;
_158:
    __quex_debug("* TERMINAL {D_NUMBER}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
{
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
self_send(QUEX_TKN_NUMBER);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8249 "lexical_analyzer.cpp"

}
goto _2;
_174:
    __quex_debug("* TERMINAL {D_QUOTE_SINGLE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(push_mode)(&self, &STRING_ABSOLUTE);self_send(QUEX_TKN_STRING_ABSOLUTE_BEGINNING);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8262 "lexical_analyzer.cpp"

}
goto _2;
_159:
    __quex_debug("* TERMINAL {D_QUOTE_DOUBLE}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
QUEX_NAME(push_mode)(&self, &STRING_RELATIVE);self_send(QUEX_TKN_STRING_RELATIVE_BEGINNING);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8275 "lexical_analyzer.cpp"

}
goto _2;
_168:
    __quex_debug("* TERMINAL {D_CONCATENATION}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(1);
{
self_send(QUEX_TKN_CONCATENATION);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8288 "lexical_analyzer.cpp"

}
goto _2;
_180:
    __quex_debug("* TERMINAL \"endl\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(4);
{
self_send(QUEX_TKN_ENDL);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8301 "lexical_analyzer.cpp"

}
goto _2;
_162:
    __quex_debug("* TERMINAL \"tab\"\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(3);
{
self_send(QUEX_TKN_TAB);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8314 "lexical_analyzer.cpp"

}
goto _2;
_160:
    __quex_debug("* TERMINAL {D_IDENTIFIER}\n");
__QUEX_IF_COUNT_SHIFT_VALUES();
__QUEX_IF_COUNT_COLUMNS_ADD(LexemeL);
{
QUEX_NAME_TOKEN(take_text)(self_write_token_p(), &self, self.buffer._lexeme_start_p, self.buffer._input_p);
self_send(QUEX_TKN_IDENTIFIER);
QUEX_SETTING_AFTER_SEND_CONTINUE_OR_RETURN();


#   line 8328 "lexical_analyzer.cpp"

}
goto _2;
#   ifndef QUEX_OPTION_COMPUTED_GOTOS
    __quex_assert_no_passage();
_315:
    switch( target_state_index ) {
        case 5: { goto _5; }
        case 9: { goto _9; }
        case 11: { goto _11; }
        case 14: { goto _14; }
        case 16: { goto _16; }
        case 17: { goto _17; }
        case 18: { goto _18; }
        case 20: { goto _20; }
        case 21: { goto _21; }
        case 22: { goto _22; }
        case 23: { goto _23; }
        case 26: { goto _26; }
        case 28: { goto _28; }
        case 32: { goto _32; }
        case 33: { goto _33; }
        case 34: { goto _34; }
        case 37: { goto _37; }
        case 38: { goto _38; }
        case 39: { goto _39; }
        case 40: { goto _40; }
        case 41: { goto _41; }
        case 42: { goto _42; }
        case 43: { goto _43; }
        case 45: { goto _45; }
        case 48: { goto _48; }
        case 49: { goto _49; }
        case 50: { goto _50; }
        case 51: { goto _51; }
        case 52: { goto _52; }
        case 53: { goto _53; }
        case 54: { goto _54; }
        case 55: { goto _55; }
        case 56: { goto _56; }
        case 57: { goto _57; }
        case 59: { goto _59; }
        case 61: { goto _61; }
        case 63: { goto _63; }
        case 65: { goto _65; }
        case 67: { goto _67; }
        case 68: { goto _68; }
        case 70: { goto _70; }
        case 73: { goto _73; }
        case 79: { goto _79; }
        case 83: { goto _83; }
        case 84: { goto _84; }
        case 86: { goto _86; }
        case 89: { goto _89; }
        case 90: { goto _90; }
        case 93: { goto _93; }
        case 94: { goto _94; }
        case 95: { goto _95; }
        case 96: { goto _96; }
        case 98: { goto _98; }
        case 101: { goto _101; }
        case 102: { goto _102; }
        case 103: { goto _103; }
        case 104: { goto _104; }
        case 119: { goto _119; }
        case 142: { goto _142; }
        case 143: { goto _143; }
        case 297: { goto _297; }

        default:
            __QUEX_STD_fprintf(stderr, "State router: index = %i\n", (int)target_state_index);
            QUEX_ERROR_EXIT("State router: unknown index.\n");
    }
#   endif /* QUEX_OPTION_COMPUTED_GOTOS */


    __quex_assert_no_passage();
_141:
    /* (RELOAD_FORWARD from 1970)  */
    target_state_index = QUEX_LABEL(57); target_state_else_index = QUEX_LABEL(104);

_313:
    __quex_debug3("RELOAD_FORWARD: success->%i; failure->%i", (int)target_state_index, (int)target_state_else_index);
    __quex_assert(*(me->buffer._input_p) == QUEX_SETTING_BUFFER_LIMIT_CODE);
    if( me->buffer._memory._end_of_file_p == 0x0 ) {

        __quex_debug_reload_before();          /* Report source position. */
        QUEX_NAME(buffer_reload_forward)(&me->buffer, (QUEX_TYPE_CHARACTER_POSITION*)position, PositionRegisterN);

        __quex_debug_reload_after();
        QUEX_GOTO_STATE(target_state_index);   /* may use 'computed goto' */
    }
    __quex_debug("reload impossible\n");
    QUEX_GOTO_STATE(target_state_else_index);  /* may use 'computed goto' */


    __quex_assert_no_passage();
_128:
    /* (RELOAD_FORWARD from 1954)  */
    target_state_index = QUEX_LABEL(41); target_state_else_index = QUEX_LABEL(68);

    goto _313;


    __quex_assert_no_passage();
_109:
    /* (RELOAD_FORWARD from 1929)  */
    target_state_index = QUEX_LABEL(14); target_state_else_index = QUEX_LABEL(68);

    goto _313;


    __quex_assert_no_passage();
_133:
    /* (RELOAD_FORWARD from 1962)  */
    target_state_index = QUEX_LABEL(49); target_state_else_index = QUEX_LABEL(68);

    goto _313;


    __quex_assert_no_passage();
_124:
    /* (RELOAD_FORWARD from 1950)  */
    target_state_index = QUEX_LABEL(37); target_state_else_index = QUEX_LABEL(68);

    goto _313;


    __quex_assert_no_passage();
_122:
    /* (RELOAD_FORWARD from 1946)  */
    target_state_index = QUEX_LABEL(33); target_state_else_index = QUEX_LABEL(83);

    goto _313;


    __quex_assert_no_passage();
_146:
    /* (RELOAD_FORWARD from 1914)  */
    target_state_index = QUEX_LABEL(61); target_state_else_index = QUEX_LABEL(70);

    goto _313;


    __quex_assert_no_passage();
_112:
    /* (RELOAD_FORWARD from 1933)  */
    target_state_index = QUEX_LABEL(18); target_state_else_index = QUEX_LABEL(84);

    goto _313;


    __quex_assert_no_passage();
_136:
    /* (RELOAD_FORWARD from 1965)  */
    target_state_index = QUEX_LABEL(52); target_state_else_index = QUEX_LABEL(68);

    goto _313;


    __quex_assert_no_passage();
_117:
    /* (RELOAD_FORWARD from 1941)  */
    target_state_index = QUEX_LABEL(26); target_state_else_index = QUEX_LABEL(89);

    goto _313;


    __quex_assert_no_passage();
_140:
    /* (RELOAD_FORWARD from 1969)  */
    target_state_index = QUEX_LABEL(56); target_state_else_index = QUEX_LABEL(103);

    goto _313;


    __quex_assert_no_passage();
_127:
    /* (RELOAD_FORWARD from 1953)  */
    target_state_index = QUEX_LABEL(40); target_state_else_index = QUEX_LABEL(94);

    goto _313;


    __quex_assert_no_passage();
_108:
    /* (RELOAD_FORWARD from 1926)  */
    target_state_index = QUEX_LABEL(11); target_state_else_index = QUEX_LABEL(79);

    goto _313;


    __quex_assert_no_passage();
_132:
    /* (RELOAD_FORWARD from 1961)  */
    target_state_index = QUEX_LABEL(48); target_state_else_index = QUEX_LABEL(68);

    goto _313;


    __quex_assert_no_passage();
_123:
    /* (RELOAD_FORWARD from 1947)  */
    target_state_index = QUEX_LABEL(34); target_state_else_index = QUEX_LABEL(83);

    goto _313;


    __quex_assert_no_passage();
_121:
    /* (RELOAD_FORWARD from 1945)  */
    target_state_index = QUEX_LABEL(32); target_state_else_index = QUEX_LABEL(89);

    goto _313;


    __quex_assert_no_passage();
_145:
    /* (RELOAD_FORWARD from 1912)  */
    target_state_index = QUEX_LABEL(59); target_state_else_index = QUEX_LABEL(68);

    goto _313;


    __quex_assert_no_passage();
_111:
    /* (RELOAD_FORWARD from 1932)  */
    target_state_index = QUEX_LABEL(17); target_state_else_index = QUEX_LABEL(83);

    goto _313;


    __quex_assert_no_passage();
_135:
    /* (RELOAD_FORWARD from 1964)  */
    target_state_index = QUEX_LABEL(51); target_state_else_index = QUEX_LABEL(68);

    goto _313;


    __quex_assert_no_passage();
_116:
    /* (RELOAD_FORWARD from 1938)  */
    target_state_index = QUEX_LABEL(23); target_state_else_index = QUEX_LABEL(67);

    goto _313;


    __quex_assert_no_passage();
_139:
    /* (RELOAD_FORWARD from 1968)  */
    target_state_index = QUEX_LABEL(55); target_state_else_index = QUEX_LABEL(102);

    goto _313;


    __quex_assert_no_passage();
_107:
    /* (RELOAD_FORWARD from 1924)  */
    target_state_index = QUEX_LABEL(9); target_state_else_index = QUEX_LABEL(67);

    goto _313;


    __quex_assert_no_passage();
_131:
    /* (RELOAD_FORWARD from 1958)  */
    target_state_index = QUEX_LABEL(45); target_state_else_index = QUEX_LABEL(98);

    goto _313;


    __quex_assert_no_passage();
_130:
    /* (RELOAD_FORWARD from 1956)  */
    target_state_index = QUEX_LABEL(43); target_state_else_index = QUEX_LABEL(96);

    goto _313;


    __quex_assert_no_passage();
_120:
    /* (RELOAD_FORWARD from 1944)  */
    target_state_index = QUEX_LABEL(119); target_state_else_index = QUEX_LABEL(90);

    goto _313;


    __quex_assert_no_passage();
_110:
    /* (RELOAD_FORWARD from 1931)  */
    target_state_index = QUEX_LABEL(16); target_state_else_index = QUEX_LABEL(67);

    goto _313;


    __quex_assert_no_passage();
_126:
    /* (RELOAD_FORWARD from 1952)  */
    target_state_index = QUEX_LABEL(39); target_state_else_index = QUEX_LABEL(93);

    goto _313;


    __quex_assert_no_passage();
_115:
    /* (RELOAD_FORWARD from 1937)  */
    target_state_index = QUEX_LABEL(22); target_state_else_index = QUEX_LABEL(67);

    goto _313;


    __quex_assert_no_passage();
_148:
    /* (RELOAD_FORWARD from 1918)  */
    target_state_index = QUEX_LABEL(65); target_state_else_index = QUEX_LABEL(73);

    goto _313;


    __quex_assert_no_passage();
_106:
    /* (RELOAD_FORWARD from 1920)  */
    target_state_index = QUEX_LABEL(5); target_state_else_index = QUEX_LABEL(68);

    goto _313;


    __quex_assert_no_passage();
_138:
    /* (RELOAD_FORWARD from 1967)  */
    target_state_index = QUEX_LABEL(54); target_state_else_index = QUEX_LABEL(101);

    goto _313;


    __quex_assert_no_passage();
_144:
    /* (RELOAD_FORWARD from 1911)  */
    target_state_index = QUEX_LABEL(142); target_state_else_index = QUEX_LABEL(143);

    goto _313;


    __quex_assert_no_passage();
_129:
    /* (RELOAD_FORWARD from 1955)  */
    target_state_index = QUEX_LABEL(42); target_state_else_index = QUEX_LABEL(95);

    goto _313;


    __quex_assert_no_passage();
_118:
    /* (RELOAD_FORWARD from 1942)  */
    target_state_index = QUEX_LABEL(28); target_state_else_index = QUEX_LABEL(89);

    goto _313;


    __quex_assert_no_passage();
_134:
    /* (RELOAD_FORWARD from 1963)  */
    target_state_index = QUEX_LABEL(50); target_state_else_index = QUEX_LABEL(68);

    goto _313;


    __quex_assert_no_passage();
_125:
    /* (RELOAD_FORWARD from 1951)  */
    target_state_index = QUEX_LABEL(38); target_state_else_index = QUEX_LABEL(68);

    goto _313;


    __quex_assert_no_passage();
_114:
    /* (RELOAD_FORWARD from 1936)  */
    target_state_index = QUEX_LABEL(21); target_state_else_index = QUEX_LABEL(68);

    goto _313;


    __quex_assert_no_passage();
_147:
    /* (RELOAD_FORWARD from 1916)  */
    target_state_index = QUEX_LABEL(63); target_state_else_index = QUEX_LABEL(67);

    goto _313;


    __quex_assert_no_passage();
_113:
    /* (RELOAD_FORWARD from 1935)  */
    target_state_index = QUEX_LABEL(20); target_state_else_index = QUEX_LABEL(86);

    goto _313;


    __quex_assert_no_passage();
_137:
    /* (RELOAD_FORWARD from 1966)  */
    target_state_index = QUEX_LABEL(53); target_state_else_index = QUEX_LABEL(68);

    goto _313;


    __quex_assert_no_passage();
_298:
    /* (RELOAD_FORWARD from 2023)  */
    target_state_index = QUEX_LABEL(297); target_state_else_index = QUEX_LABEL(143);

    (me->buffer._lexeme_start_p) = (me->buffer._input_p);

__QUEX_IF_COUNT_COLUMNS_ADD((size_t)(((me->buffer._input_p) - reference_p)));

    goto _313;

_3:
/* RETURN -- after executing 'on_after_match' code. */
    __QUEX_PURE_RETURN;


_2:
/* CONTINUE -- after executing 'on_after_match' code. */

_1:
/* CONTINUE -- without executing 'on_after_match' (e.g. on FAILURE). */


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


goto _314;

    __quex_assert_no_passage();

    /* Following labels are referenced in macros. It cannot be detected
     * whether the macros are applied in user code or not. To avoid compiler.
     * warnings of unused labels, they are referenced in unreachable code.   */
    goto _3; /* in RETURN                */
    goto _2; /* in CONTINUE              */
    goto _1; /* in CONTINUE and skippers */
#   if ! defined(QUEX_OPTION_COMPUTED_GOTOS)
    goto _315; /* in QUEX_GOTO_STATE       */
#   endif

    /* Prevent compiler warning 'unused variable'.                           */
    (void)QUEX_LEXEME_NULL;
    (void)QUEX_NAME_TOKEN(DumpedTokenIdObject);
    /* target_state_index and target_state_else_index appear when 
     * QUEX_GOTO_STATE is used without computed goto-s.                      */
    (void)target_state_index;
    (void)target_state_else_index;

#   undef Lexeme
#   undef LexemeBegin
#   undef LexemeEnd
#   undef LexemeNull
#   undef LexemeL
#   undef COMMENT
#   undef FUNCTION_DEFINITION
#   undef STRING_RELATIVE
#   undef FAILURE
#   undef FUNCTION_DEFINITION_PARAMETERS
#   undef STRING_ABSOLUTE
#   undef SCOPE
#   undef EXPRESSION
#   undef self
#   undef QUEX_LABEL_STATE_ROUTER
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

