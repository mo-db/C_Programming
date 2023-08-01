# include <stdio.h>
# define TAB_SIZE 4

int main(void)
{
    int c, nb, pos;
    nb = 0;
    pos = 1;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            nb = TAB_SIZE - (pos - 1) % TAB_SIZE;
            while (nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
        } else if (c == '\n' ) {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }
}