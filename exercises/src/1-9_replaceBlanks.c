#include <stdio.h>

int main(void) 
{
    int c, blank_check = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (blank_check == 0)
                putchar(c);
            blank_check = 1;
        } else {
            blank_check = 0;
            putchar(c);
        }
    }

}