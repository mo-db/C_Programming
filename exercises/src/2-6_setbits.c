#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

u_int16_t get_bits(u_int16_t x, u_int16_t p, u_int16_t n)
{
    return (x >> (p-n)) & ~(~0 << n); 
}

// take rightmost n bits of y and put them into position p in x
u_int16_t set_bits(u_int16_t x, u_int16_t y, u_int16_t p, u_int16_t n)
{
    // mask = 1111 1110 0000 1111
    u_int16_t mask = (~0 << p) | ~(~0 << (p-n));
    return (x & mask) | ((y & ~(~0 << n)) << (p-n));
}

u_int16_t invert_bits(u_int16_t x, u_int16_t p, u_int16_t n)
{
    // speichern in temp, inverten, ~masken, orignal masken, zuammenbringen
    u_int16_t mask = (~0 << p) | ~(~0 << (p-n));
    u_int16_t temp = x;
    x &= ~mask;

    return (temp & mask) | (~x & ~mask);
}

u_int16_t rightrot_bits(u_int16_t x, u_int16_t n)
{
    // mask last bit alone, save in var, move right one, mask var into first bit, repeat for n
    u_int16_t var1 = 1;
    u_int16_t var2 = 15;
    for (int i = 0; i < n; i++) {
        u_int16_t temp = x & ~(~0 << var1);
        x = ((x >> 1) & ~(~0 << var2)) | (temp << var2);
    }
    
    return x;
}

u_int16_t bit_count()
{
    
    return 0;
}

int main() 
{
    // 0110 1000 1101 1011 
    u_int16_t x = 26843;

    // 0001 0010 1001 0110
    u_int16_t y = 4758;

    u_int16_t position = 12;
    u_int16_t n_bits = 4;

    printf("get_bits: %u\n", get_bits(x, position, n_bits));
    printf("set_bits: %u\n", set_bits(x, y, position, n_bits));
    printf("invert_bits: %u\n", invert_bits(x, position, n_bits));
    printf("rightrot_bits: %u\n", rightrot_bits(x, n_bits));

    // 0000 0000 0011 0100      -1 =
    // 0000 0000 0000 1111
    u_int16_t c = 16;
    printf("some test: %u\n", (c &= (c-1)));
}