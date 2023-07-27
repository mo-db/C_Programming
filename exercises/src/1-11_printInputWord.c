#include <stdio.h>

int main(void) 
{
    /*
     * If we are inside a word, print to output.
     * Then when the word ends print a new line
     * so long until there is a normal character again
    */
    int c, outside_word = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (outside_word == 0)
                printf("\n");
            outside_word = 1;
        } else {
            putchar(c);
            outside_word = 0;
        }
            

    }

}