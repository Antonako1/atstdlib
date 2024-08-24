/*+++
    ATSTDLIB REGEX C SOURCE - Antonako1
    
    Licensed under MIT
---*/
#include <atstdlib_regex.h>
#include <atstdlib_string.h>
#include <string.h>

/*+++
THOMPSON NFA REGEX IMPLEMENTATION

Heavy inspiration taken from Russ Cox:
    https://swtch.com/~rsc/regexp/regexp1.html
---*/



/// @brief infix to postfix
/// @param str infix string
/// @return postfix str. NULLPTR on failure
U8 *infix_to_postfix(U8 *str){
    static U8 buf[8000];
    U8 *res = buf;
    U64 num_of_alts = 0;
    U64 num_of_groups = 0;
    struct {
        U64 num_of_alts;
        U64 num_of_groups;
    } stack[128], *s_ptr;
    s_ptr = stack;
    for(U64 i = 0; i < ustrlen(str); i++){
        U8 c = str[i];
        printf("%c, %lld, %lld\n\n", c, num_of_alts, num_of_groups);
        switch(c){
        case '(': //push stack
            if(s_ptr >= stack+128) return NULLPTR;
            s_ptr->num_of_alts = num_of_alts;
            s_ptr->num_of_groups = num_of_groups;
            s_ptr++;
            num_of_alts = 0;
            num_of_groups = 0;
            break;
        case ')': //pop stack
            if(s_ptr == stack) return NULLPTR;
            if(num_of_groups == 0) return NULLPTR;
            s_ptr--;
            num_of_alts = s_ptr->num_of_alts;
            num_of_groups = s_ptr->num_of_groups;
            break;
        case '|': //alternation
            num_of_alts++;
            break;
        case '+':
        case '*':
        case '?':
            break;
        default: 
            *res++ = c;
            break;
        }
    }
    printf("AAA: %s\n", buf);
    return buf;
}

U0 postfix_to_nfa(){

}

BOOLEAN check_str_against_regex(U8 *regex_str, U8 *input_str){
    U8 *res = infix_to_postfix(regex_str);
    // printf("%s\n", res);
    return TRUE;
}