# include <stdio.h>
# include <limits.h>

int main(void)
{
    int ui = 0;
    u_int32_t ut = 4;
    printf("unsigned int: %u\n", UINT_MAX);
    printf("sizeof uint: %lu\n", sizeof(UINT_MAX));

    long res = 2;
    for (int i = 0; i < 31; i++) {
        res *= 2;
    }
    printf("res: %ld\n", res);
}