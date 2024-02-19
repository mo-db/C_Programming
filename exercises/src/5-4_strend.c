#include <string.h>
#include <stdio.h>

int strend(char *, char *);


int main()
{
    char *s = "this is a tesft";
    char *t = "tesft";

    printf("%d\n", strend(s, t));

    return 0;
}


int strend(char *s, char *t)
{
    // https://stackoverflow.com/questions/492384/how-to-find-the-size-of-an-array-from-a-pointer-pointing-to-the-first-element-a
    // Using sizeof on array pointer isn't possible (returns 1), use strlen for strings
    // or store the size when allocating
    int s_len = strlen(s);
    int t_len = strlen(t);

    s += s_len;
    t += t_len;

    while (t_len > 0 && *s-- == *t--) {
        t_len--;
        *s-- = *t;
    }

    if (t_len) {
        return 0;
    }

    return 1;
}