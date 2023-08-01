# include <stdio.h>
# define TAB_SIZE 4

int main(void)
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int i;
            for (i = 0; i < TAB_SIZE; ++i)
                putchar(' ');
        } else {
            putchar(c);
        }
    }
}