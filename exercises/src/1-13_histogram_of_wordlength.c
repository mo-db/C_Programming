#include <stdio.h>

int main(void) 
{
    /*
     * If we are inside a word, print to output.
     * Then when the word ends print a new line
     * so long until there is a normal character again
    */
    int c, char_count = 0, word_length = 0;
    int HISTO_SIZE = 20;

    int len_ary[HISTO_SIZE];
    for (int i = 0; i < HISTO_SIZE; ++i)
        len_ary[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (word_length != 0)
                ++len_ary[word_length-1];
                word_length = 0;
        } else {
            ++word_length;
        }
    }

    for (int i = 0; i < HISTO_SIZE; ++i) {
        printf("%4d ", i);
        for (int j = 0; j < len_ary[i]; ++j) {
            printf("#");
        }
        printf("\n");
    }
}