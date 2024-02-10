#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

void recursive_reverse(char [], int, int);

int main()
{
    char string[] = "Moritz";
    printf("test:%d", sizeof(string));

    recursive_reverse(string, 0, (sizeof(string) - 2));

    printf("Reversed: ");
    for (int i = 0; i < sizeof(string); i++) {
        printf("%c", string[i]);
    }
    
    return 0;
}

void recursive_reverse(char string[], int index_left, int index_right)
{
    if (index_left >= index_right) {
        return;
    }
    char temp = string[index_left];
    string[index_left] = string[index_right];
    string[index_right] = temp;

    recursive_reverse(string, ++index_left, --index_right);
}