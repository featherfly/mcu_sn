#include "numbers.h"

#include <stdio.h>

static char _hex_chars[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void int32_to_bytes(int i, unsigned char abyte[])
{
    abyte[3] = (unsigned char)(0xff & i);

    abyte[2] = (unsigned char)((0xff00 & i) >> 8);

    abyte[1] = (unsigned char)((0xff0000 & i) >> 16);

    abyte[0] = (unsigned char)((0xff000000 & i) >> 24);
}

void int16_to_bytes(int i, unsigned char abyte[])
{
    abyte[1] = (unsigned char)(0xff & i);

    abyte[0] = (unsigned char)((0xff00 & i) >> 8);
}

void int24_to_bytes(int i, unsigned char abyte[])
{
    abyte[2] = (unsigned char)(0xff & i);

    abyte[1] = (unsigned char)((0xff00 & i) >> 8);

    abyte[0] = (unsigned char)((0xff0000 & i) >> 16);
}
void int8_to_bytes(int i, unsigned char abyte[])
{
    abyte[0] = (unsigned char)(0xff & i);
}
    
void to_hex(unsigned char c, char* hex)
{
    if (c < 16)
    {
        sprintf(hex, "0%c", _hex_chars[c]);
    } else{
        sprintf(hex, "%X", c);
    }
}