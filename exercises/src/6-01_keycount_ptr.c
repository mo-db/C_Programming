#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define WORD_MAXLEN 20

struct key {
    char *word;
    int count;
} keytab[] = {
    "char", 0,
    {"const", 0},
    "int", 0,
    "while", 0
};

int get_word(char *, FILE *, int);
int bin_search(char *, struct key *, int);

int main()
{
    struct key *p;
    FILE *input_file = fopen("/Users/moritz/Repos/C_Programming/exercises/src/testfile.txt", "r");
    if (input_file == NULL) {
        printf("ERROR: file opening failed!\n");
        return 1;
    }

    int n_keys = sizeof(keytab) / sizeof(*keytab);
    char word[WORD_MAXLEN];
    while (get_word(word, input_file, WORD_MAXLEN) != EOF) {
        int match_position = bin_search(word, keytab, n_keys);
        if (match_position > 0) {
            (keytab[match_position].count)++;
        }  
    }

    for (int i = 0; i < n_keys; i++) {
        printf("%s, %d\n", keytab[i].word, keytab[i].count);
    }

    fclose(input_file);
    return 0;
}

int get_word(char *word, FILE *fp, int maxlen)
{
    const int min_wordlength = 2;
    word[min_wordlength - 1] = '\0';
    int c, cnt = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            word[cnt++] = c;
        } else if (word[min_wordlength - 1] != '\0') {
            break;
        } else {
            cnt = 0;
        }
    }
    if (c != EOF) {
        word[cnt] = '\0';
    }
    return c;
}

int bin_search(char *word, struct key *keytab, int n_keys)
{
    int i;
    for (i = 0; i < n_keys; i++) {
        if (strcmp(word, keytab[i].word) == 0) {
            return i;
        } 
    }
    return -1;
}
