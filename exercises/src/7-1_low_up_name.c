#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char c;
    while ((c = getchar()) != EOF) {
        putchar((islower(argv[0][5]) ? tolower(c) : c));
    }
    return 0;
}
