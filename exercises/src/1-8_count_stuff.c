#include <stdio.h>

int main(void) 
{
    int c, blanks = 0, tabs = 0, new_lines = 0;

    // read input char by char and count occurrences
    while ((c = getchar()) != EOF) {
        if (c == ' ') 
            ++blanks;
        if (c == '\t') 
            ++tabs;
        if (c == '\n')
            ++new_lines;
    }
    
    printf("Counted %d blanks, %d tabs and %d new lines",
        blanks, tabs, new_lines);

}