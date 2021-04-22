#ifndef NUMBERS_H
#define NUMBERS_H

void int32_to_bytes(int i, unsigned char abyte[]);

void int24_to_bytes(int i, unsigned char abyte[]);

void int16_to_bytes(int i, unsigned char abyte[]);

void int8_to_bytes(int i, unsigned char abyte[]);

void to_hex(unsigned char c, char* hex);

#endif