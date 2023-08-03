/*
Replace strings of blanks by the minimum number of 
tabs and blanks possible.

- Tabstop every 8 position

*/

# include <stdio.h>
# define TAB_SIZE 8

int main(void)
{
    int c, pos, blank_len, n_tabs, n_blanks;


    n_tabs = blank_len / TAB_SIZE;
    n_blanks = blank_len % TAB_SIZE;
    printf("TABS: %d\n", n_tabs);
    printf("BLANKS: %d\n", n_blanks);


    pos = 1;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blank_len;
            ++pos;
        } else {
            n_tabs = blank_len / TAB_SIZE;
            n_blanks = blank_len % TAB_SIZE;
            blank_len = 0;
            ++pos;
        }
    }
}