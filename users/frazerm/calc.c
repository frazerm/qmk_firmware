#include "calc.h"

uint8_t tokenise_buffer(char* buffer, struct token *stack)
{
    struct token *stack_end = stack;

    for (char *b = buffer; *b != '\0'; b++)
    {
        if (is_number(*b)  ||  *b == CH_DOT ||  (*b == CH_MINUS  &&  is_number(*(b+1))))
        {
            char current_number[CALC_BUFFER_LENGTH];
            int i = 0;
            
            do { 
                current_number[i] = *b;
                i++;
                b++;
            } while (is_number(*b)  ||  *b == CH_DOT);

            current_number[i] = '\0';

            stack_end->type = TOK_NUM;
            stack_end->val  = atof(current_number);
        }
        else if (*b == CH_PLUS)
            stack_end->type = TOK_PLUS;
        else if (*b == CH_MINUS)
            stack_end->type = TOK_MINUS;
        else if (*b == CH_MUL)
            stack_end->type = TOK_MUL;
        else if (*b == CH_DIV)
            stack_end->type = TOK_DIV;
        else if (*b == CH_POW)
            stack_end->type = TOK_POW;
        else
            continue;

        stack_end++;
    }

    return stack_end - stack;
}