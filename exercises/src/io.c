#include <stdio.h>

void testio(char testc) 
{
    printf("printing test character: %c\n", testc);
}

int getLine(char *file_name, char *line, int char_max, int current_line)
{
    FILE *fp = fopen("%s", "r"); // how fopen with variable?



    fclose(fp);
    
}