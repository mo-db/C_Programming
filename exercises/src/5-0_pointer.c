#include <stdio.h>


int strcmp_ary(char [],  char []);
int strcmp_ptr(char *, char *);


int main()
{
    int test[3] = {8, 3, 9};
    for (int i = 0; i < 3; i++) {
        printf("%i ", test[i]);
    }
    

    return 0;
}


int strcmp_ary(char s[], char t[])
{
    int i;

    for (i = 0; s[i] == t[i]; i++) {
        if (s[i] == '0') {
            return 0;
        }
    }
    return s[i] - t[i];
}


int strcmp_ptr(char *s, char *t)
{
    return 0;
}