// count the number of occurrences of all words in some input
#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct node {
    char *word;
    int count;
    struct node *left;
    struct node *right;
};

struct node *add_tree(struct node *, char *);
int file_get_word(char *, FILE *, int);
int stdin_get_word(char *, int);


int main(int argc, char *argv[])
{
    int cli_input = 0;
    int file_input = 0;
    int use_fallback = 0;

    const char *fallback_file = "/Users/moritz/Repos/C_Programming/exercises/src/text.txt";
    if (argc > 1) {
        if (argv[1][1] == 'i') {
            cli_input = 1; 
            printf("please enter input:\n");
        } else if (argv[1][1] == 'f') {
            file_input = 1;
            printf("using arg file\n");
        } else {
            printf("ERROR: wrong cli args\n");
            printf("usage:\n");
            printf("  -i        (cli input)\n");
            printf("  -f [file] (file input)\n");
            printf("  no arg    (use fallback file)\n");
            return 1;
        }
    } else {
        use_fallback = 1;
        file_input = 1;
        printf("no arg, using fallback file\n");
    }

    FILE *input_file;
    if (file_input == 1) {
        if (use_fallback == 1) {
            input_file = fopen(fallback_file, "r");
        } else {
            input_file = fopen(argv[2], "r");
        }
        if (input_file == NULL) {
            printf("ERROR: file opening failed!\n");
            return 1;
        }
    }

    int WORD_MAXLEN = 100;
    char word[WORD_MAXLEN];
    struct node *root;

    root = NULL;
    int return_val = 0;
    while ((return_val = ((file_input == 1) ?
            file_get_word(word, input_file, WORD_MAXLEN) :
            stdin_get_word(word, WORD_MAXLEN))) != EOF) {
        printf("RETURN: %d\n", return_val);
        break;
    }

    if (file_input == 1) {
        fclose(input_file);
    }
    return 0;
}


// premise new line allways bevore EOF?
int file_get_word(char *word, FILE *fp, int maxlen)
{
    return 1;
}

int stdin_get_word(char *word, int WORD_MAXLEN)
{
    return 2;
}
