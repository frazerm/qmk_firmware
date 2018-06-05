#include "calc.h"

#include <string.h>
#include <print.h>

static bool shift_buffer_cursor(uint8_t shift);
static bool delete_from_buffer(void);
static bool append_to_buffer(char c);
static char keycode_to_ascii_number(uint16_t keycode);
static void pretty_print_buffer(void);

bool calc_mode = false;

char buffer[CALC_BUFFER_LENGTH];
uint8_t buffer_head   = 0;
uint8_t buffer_cursor = 0;

const char keycode_to_ascii_lut[10] = {
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
};

void pretty_print_buffer(void)
{
    for (int i = 0 ; i < CALC_BUFFER_LENGTH ; i++)
        uprintf("%c", buffer[i]);

    uprint("<\n");

    for (int i = 0 ; i <= CALC_BUFFER_LENGTH ; i++)
    {
        if (i == buffer_head && i == buffer_cursor)
            uprint("|");
        else if (i == buffer_head)
            uprint("|");
        else if (i == buffer_cursor)
            uprint("^");
        else
            uprint(" ");
    }

    uprint("\n");
    return;
}

static char keycode_to_ascii_number(uint16_t keycode)
{
    if (KC_1 <= keycode  &&  keycode <= KC_0)
        return keycode_to_ascii_lut[keycode - KC_1];

    return '\0';
}

static bool append_to_buffer(char c)
{
    if (buffer_head >= CALC_BUFFER_LENGTH)
        return false;

    if (buffer_cursor < buffer_head)
    {
        // we need to shift part of the buffer forward
        if (buffer_head >= CALC_BUFFER_LENGTH)
            // not enough space
            return false;

        memmove(buffer +buffer_cursor, buffer + buffer_cursor - 1, buffer_head-buffer_cursor);
    }

    buffer[buffer_cursor] = c;
    buffer_head++;
    buffer_cursor++;

    return true;
}

static bool delete_from_buffer(void)
{
    if (buffer_cursor <= 0)
        return false;

    if (buffer_cursor < buffer_head)
        memmove(buffer + buffer_cursor - 1, buffer + buffer_cursor, buffer_head-buffer_cursor);

    buffer_head--;
    buffer_cursor--;

    return true;
}

static bool shift_buffer_cursor(uint8_t shift)
{
    uint8_t new_cursor = buffer_cursor + shift;

    if (new_cursor < 0 || new_cursor > buffer_head)
    {
        return false;
    }

    buffer_cursor = new_cursor;

    return true;
}

bool process_calc_key_press(uint16_t keycode)
{
    
    #ifdef CALCULATOR_ENABLE

    if (!calc_mode)
        return false;
    // else

    switch (keycode)
    {
    case CALC_RET:
        // TODO: calculate
        break;
    case CALC_PLS:
        if (append_to_buffer('+'))
            SEND_STRING("+");
        break;
    case CALC_MIN:
        if (append_to_buffer('-'))
            SEND_STRING("-");
        break;
    case CALC_MUL:
        if (append_to_buffer('*'))
            SEND_STRING("*");
        break;
    case CALC_DIV:
        if (append_to_buffer('/'))
            SEND_STRING("/");
        break;
    case CALC_POW:
        if (append_to_buffer('^'))
            SEND_STRING("^");
        break;
    case KC_SPC:
        if (append_to_buffer(' '))
            SEND_STRING(" ");
        break;
    case KC_BSPC:
        if (delete_from_buffer())
            SEND_STRING(SS_TAP(X_BSPACE));
        break;
    case KC_LEFT:
        if (shift_buffer_cursor(-1))
            SEND_STRING(SS_TAP(X_LEFT));
        break;
    case KC_RIGHT:
        if (shift_buffer_cursor(1))
            SEND_STRING(SS_TAP(X_RIGHT));
        break;
    default:
        uprintf("%d\n", keycode_to_ascii_number(keycode));
        if (KC_1 <= keycode  &&  keycode <= KC_0)
        {
            char c = keycode_to_ascii_number(keycode);
            if (append_to_buffer(c))
            {
                char s[2];
                s[0] = c;
                s[1] = '\0';
                send_string(s);
            }
        }
        else
        {
            uprint("not recognised\n");
            return false;
        }
        break;
    }



    pretty_print_buffer();

    return true;
    #endif
}

void calc_mode_enter(void)
{
    #ifdef CALCULATOR_ENABLE
    uprint("calculator mode enabled\n");

    calc_mode       = true;
    buffer_head     = 0;
    buffer_cursor   = 0;
    #endif
}

void calc_mode_exit(void)
{
    #ifdef CALCULATOR_ENABLE
    uprint("calculator mode disabled\n");
    calc_mode = false;
    #endif
}
