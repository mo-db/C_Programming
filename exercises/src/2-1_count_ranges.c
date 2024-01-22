# include <stdio.h>
# include <limits.h>

int main(void)
{
    printf("unsigned int: %u\n", UINT_MAX);
    printf("sizeof uint: %lu\n", sizeof(UINT_MAX));

    long res = 2;
    for (int i = 0; i < 31; i++) {
        res *= 2;
    }
    printf("res: %ld\n", res);
    char b = 'b';

    int testi = 0x1f;
    int test2 = '\x1f';
    unsigned char test3 = '\xff';
    unsigned int test4 = 121;

    printf("sizeof 'a'             = %zu\n", sizeof 'a');
    printf("sizeof 'b'             = %zu\n", sizeof b);
    printf("test: %u", test3);
}