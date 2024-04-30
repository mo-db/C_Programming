#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
} tnode;

typedef struct word_count {
    char *word;
    int count;
} word_count;


int select_input(int, char *[], FILE **, const char *);
int file_get_word(char *, const int, FILE *);
int cli_get_word(char *, const int);
tnode *create_node(char *);
int insert_node_alpha(tnode **, char*);
void print_tree(tnode *);

void tree_get_size(tnode *, int *);
tnode *create_word_ary(word_count *);
void word_ary_qsort();


int main(int argc, char *argv[])
{
    FILE *input_file = NULL;
    int input_status = 0; // 0=Error; 1=cli; 2=File;
    const char *Fallback_File = "/Users/moritz/Repos/C_Programming/exercises/src/tut.txt";
    input_status = select_input(argc, argv, &input_file, Fallback_File);
    if (!input_status) {
        return 1;
    }

    const int Word_Maxlen = 100;
    char word[Word_Maxlen];
    tnode *root_p = NULL;

    while (((input_status == 2) ?
            file_get_word(word, Word_Maxlen, input_file) :
            cli_get_word(word, Word_Maxlen)) != EOF) {
        if (!insert_node_alpha(&root_p, word)) {
            return 1;
        }
    }
    print_tree(root_p);

    //int size_counter = 0;
    //tree_get_size(root_p, &size_counter);
    //printf("%d\n", size_counter);


    if (input_status == 2) {
        fclose(input_file);
    }

    return 0;
}


int select_input(int argc, char *argv[],
                 FILE **input_file_p, const char *Fallback_File)
{
    if (argc > 1) {
        if (argv[1][1] == 'i') {
            printf("Using CLI input, please enter Text.\n");
            return 1;
        } else if (argv[1][1] == 'f') {
            if ((*input_file_p = fopen(argv[2], "r")) != NULL) {
                printf("Using provided file as input.\n");
                return 2;
            } else {
                printf("<error> file opening failed!\n");
                return 0;
            }
        } else {
            printf("ERROR: wrong cli args\n");
            printf("usage:\n");
            printf("  -i        (cli input)\n");
            printf("  -f [file] (file input)\n");
            printf("  no arg    (use fallback file)\n");
            return 0;
        }
    } else {
        printf("No CLI args provided, ");
        if ((*input_file_p = fopen(Fallback_File, "r")) != NULL) {
            printf("Using fallback file as input.\n");
            return 2;
        } else {
            printf("<error> couldn't open fallback file!\n");
            return 0;
        }
    }
}


int file_get_word(char *word, const int Word_Maxlen, FILE *input_file)
{
    int c, count = 0;
    while ((c = fgetc(input_file)) != EOF) {
        if (isalpha(c)) {
            word[count++] = c;
        } else if (count > 1) {
            word[count] = '\0';
            if (count < Word_Maxlen) {
                break;
            } else {
                printf("<error> word to long!");
                return EOF;
            }
        }
    }
    return c;
}


int cli_get_word(char *word, const int Word_Maxlen)
{

    int c, count = 0;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            word[count++] = c;
        } else if (count > 1) {
            word[count] = '\0';
            if (count < Word_Maxlen) {
                break;
            } else {
                printf("<error> word to long!");
                return EOF;
            }
        }
    }
    return c;

}


tnode *create_node(char *word)
{
    tnode *new_tnode;
    char *new_tnode_word;

    if ((new_tnode = malloc(sizeof(tnode))) == NULL) {
        printf("<error> node malloc failed!");
        return NULL;
    }
    if ((new_tnode_word = malloc(strlen(word)+1)) == NULL) {
        printf("<error> word malloc failed!");
        return NULL;
    }

    new_tnode->left = NULL;
    new_tnode->right = NULL;
    new_tnode->count = 1;

    strcpy(new_tnode_word, word);
    new_tnode->word = new_tnode_word;

    return new_tnode;
}


int insert_node_alpha(tnode **root_pp, char *word)
{
    int cmp;
    tnode *root_p = *root_pp;

    if (root_p == NULL) {
        if ((*root_pp = create_node(word)) == NULL) {
            return 0;
        } else {
            return 1;
        }
    }

    if ((cmp = strcmp(word, root_p->word)) == 0) {
        root_p->count++;
        return 1;
    } else if (cmp < 0) {
        return insert_node_alpha(&(root_p->left), word);
    } else {
        return insert_node_alpha(&(root_p->right), word);
    }
}


void print_tree(tnode *root_p)
{
    if (root_p->left != NULL) {
        print_tree(root_p->left);
    }
    printf("%s\t%d\n", root_p->word, root_p->count);
    if (root_p->right != NULL) {
        print_tree(root_p->right);
    }
}


void tree_get_size(tnode *root_p, int *counter)
{
    if (root_p->left != NULL) {
        print_tree(root_p->left);
    }
    (*counter)++;
    if (root_p->right != NULL) {
        print_tree(root_p->right);
    }
}
