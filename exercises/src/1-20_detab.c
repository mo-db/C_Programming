# include <stdio.h>
# define TAB_SIZE 8

int main(void)
{
    int c, n_blanks, pos;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            n_blanks = (TAB_SIZE - pos) % TAB_SIZE;
            int i;
            for (i = 0; i < TAB_SIZE; ++i)
                putchar(' ');
        } else {
            putchar(c);
        }
    }
}