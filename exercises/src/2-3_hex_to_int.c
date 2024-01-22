#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

u_int32_t htoi(char hex_digits[])
{
    u_int32_t num = 0;
    u_int32_t digit = 0;
    u_int32_t i = 0;

    // Check if the hex number is beginning with 0x or 0X, if so change i to skip
    if (hex_digits[0] == '0' && hex_digits[1] == 'x' || hex_digits[1] == 'X') {
        i = 2;
    }

    for (; i < strlen(hex_digits); i++) {
        if (isdigit(hex_digits[i])) {
            digit = hex_digits[i] - '0';
        } else {
            digit = 10 + (tolower(hex_digits[i]) - 'a');
        }
        num = num * 16 + digit;
    }
    return num;
}

int main()
{
    char hex_digits[] = "0x2e";
    u_int32_t dec_number;

    dec_number = htoi(hex_digits);
    printf("the converted number is: %u", dec_number);

    return 0;
}