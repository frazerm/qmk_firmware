#include "calc.h"

uint8_t tokenise_buffer(char* buffer, uint8_t buffer_length, struct token *stack)
{
    struct token *stack_end = stack;

    for (int i = 0 ; i < buffer_length ; i++)
    {
        char c = buffer[i];
        if (is_number(c))
        {
            char current_number[CALC_BUFFER_LENGTH];
            int j = 0;

            do { 
                current_number[j] = c;
                j++;
                i++;
                c = buffer[i];
            } while (i < buffer_length  &&  is_number(c));

            current_number[i] = '\0';

            stack_end->type = TOK_NUM;
            stack_end->val  = atof(current_number);
        }
         else if (c == CH_PLUS)
            stack_end->type = TOK_PLUS;
        else if (c == CH_MINUS)
            stack_end->type = TOK_MINUS;
        else if (c == CH_MUL)
            stack_end->type = TOK_MUL;
        else if (c == CH_DIV)
            stack_end->type = TOK_DIV;
        else if (c == CH_POW)
            stack_end->type = TOK_POW;
        else
            continue;

        stack_end++;
        
    }

    return stack_end - stack;
}

void print_float(float f)
{
    char res[32];
    sprintf(res, "%g", f);
    uprintf("%s\n", res);
    return;
}

uint8_t handle_op(struct token *lhs, struct token *rhs, struct token *op, struct token *result)
{
    // uprintf("%d\n", op->type);

    // print_float(lhs->val);
    // print_float(rhs->val);

    switch (op->type)
    {
    case TOK_PLUS:
        result->val = lhs->val + rhs->val;
        break;
    case TOK_MINUS:
        result->val = lhs->val - rhs->val;
        break;
    case TOK_MUL:
        result->val = lhs->val * rhs->val;
        break;
    case TOK_DIV:
        result->val = lhs->val / rhs->val;
        break;
    case TOK_POW:
        result->val = powf(lhs->val, rhs->val);
        break;
    case TOK_NUM:
    default:
        return -1;
    }

    result->type = TOK_NUM;

    return 0;
}

uint8_t reduce_stack(struct token *instack, uint8_t stack_size)
{
    struct token outstack[stack_size];

    uint8_t head = 0;

    for (uint8_t i = 0 ; i < stack_size ; i++)
    {
        struct token *t = &instack[i];

        if (is_op(t))
        {
            if (head < 1)
            {
                uprintf("outstack has %d items\n", head);
                return -1;
            }

            struct token *lhs = &outstack[head-1];
            struct token *rhs = &outstack[head];

            uint8_t res = handle_op(lhs, rhs, t, lhs);

            if (res)
            {
                uprint("op error");
                return -1;
            }

            head--;
        }
        else if (t->type == TOK_NUM)
        {
           outstack[head] = *t;
           head++;
        }
    }

    for (uint8_t i = 0 ; i < head ; i++)
    {
        instack[i] = outstack[i];
    }

    return head;
}