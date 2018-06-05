#ifndef FRAZERM_CALC_H
#define FRAZERM_CALC_H

#include "frazerm.h"
#include "string.h"

#define CH_PLUS             43
#define CH_MINUS            45
#define CH_MUL              42
#define CH_DIV              47
#define CH_POW              94
#define CH_DOT              46

#define CALC_BUFFER_LENGTH  32
#define CALC_STACK_LENGTH   32

enum token_type
{
    TOK_NUM = 0,
    TOK_PLUS,
    TOK_MINUS,
    TOK_MUL,
    TOK_DIV,
    TOK_POW
};

enum tokeniser_status
{
    OK,
    CALC_ERR_BAD_OP,
    CALC_ERR_BAD_STACK,
};

struct token
{
    enum token_type type;
    float           val;
};

inline bool is_number(char c)
{
    return 48 <= c  &&  c <= 57;
}

inline bool is_op(struct token *token)
{
    return (TOK_PLUS <= token->type)  &&  (token->type <= TOK_POW);
}

void calc_mode_enter(void);
void calc_mode_exit(void);
bool process_calc_key_press(uint16_t keycode);

uint8_t tokenise_buffer(char* buffer, struct token *stack);

#endif //FRAZERM_CALC_H