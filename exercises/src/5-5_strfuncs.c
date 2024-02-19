#include <stdio.h>
#include <string.h>

void my_strcpy(char *, char *, int n);

int main()
{
    char cs[100] = "base string for testing";
    char *ct = "second one";

    int n = 3;
    my_strcpy(cs, ct, n);

    puts(cs);
    /*
    printf("strcpy: ");
    for (int i = 0; *(cs + i) != '\0'; i++) { // kann man array schreibweise verwenden?
        printf("%c", *(cs + i));
    }
    */
    return 0;
}

void my_strcpy(char *cs, char *ct, int n)
{
    while (*ct && n-- > 0) {
        *cs++ = *ct++;
    }
}