// count the number of occurrences of all words in some input
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

struct node {
    char *word;
    int count;
    struct node *left;
    struct node *right;
};

struct node *add_tree(struct node *, char *);
int file_get_word(char *, FILE *, int);

int main()
{
    printf("wtf!!!!!!!!!!!!!!!\n");
    sleep(1);

    printf("wtf!!!!!!!!!!!!!!!\n");
    printf("HALLO?????");

    sleep(1);
    printf("wtf!!!!!!!!!!!!!!!\n");

    sleep(1);
    printf("wtf!!!!!!!!!!!!!!!\n");
    //printf("argc: %d", argc);
    // if arg file, take cli arg, or take fallback file
    FILE *input_file = fopen("/Users/moritz/Repos/C_Programming/exercises/src/text.txt", "r");
    if (input_file == NULL) {
        printf("ERROR: file opening failed!\n");
        return 1;
    }
    // if arg cli ...
    int WORD_MAXLEN = 100;
    char word[WORD_MAXLEN];
    struct node *root;

    root = NULL;
    while (file_get_word(word, input_file, WORD_MAXLEN) != EOF) {
        printf("FAILLLURE>???");
        //sleep(1);
    }

    fclose(input_file);

    return 0;
}


// premise new line allways bevore EOF?
int file_get_word(char *word, FILE *fp, int maxlen)
{
    int c, count = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            word[count++] = c;
        } else if (count > 0) {
            word[count] = '\0';
            break;
        }
    }
    return 1;
}

int stdin_get_word(char *word, int WORD_MAXLEN)
{
    int c, count = 0;
    return 0;
}
