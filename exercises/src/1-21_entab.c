/*
 * 
 *
 * 
*/

# include <stdio.h>
# define TAB_SIZE 5

int main(void)
{
    printf("----|----|----|----|----|----|----|----|\n");
    int c, n_blanks, pos = 1;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            //printf("Bevore Tab: %d ", pos);
            // printf("pos test 1 = %d", pos);
            n_blanks = (1 + TAB_SIZE) - (pos % TAB_SIZE);
            int i;
            for (i = 0; i < n_blanks; ++i) {
                putchar(' ');
                ++pos;
            }
            //printf("Pos: %d, Blanks: %d\n", pos, n_blanks);
        } else if (c == '\n'){
            putchar(c);
            pos = 0;
        } else {
            putchar(c);
            ++pos;
        }
    }
}