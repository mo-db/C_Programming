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
int create_word_ary(tnode **, tnode *);
void word_ary_qsort(tnode *, int);
void wc_swap(int *, int *);


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


    int tree_size = 0;
    tree_get_size(root_p, &tree_size);
    tnode *wc_ary = malloc(sizeof(tnode) * tree_size);
    if (wc_ary == NULL) {
        printf("<error> wc_ary malloc failed!");
        return 1;
    }

    if (!create_word_ary(&wc_ary, root_p)) { return 1; }
    for (int i = 0; i < tree_size; i++) {
        printf("%d\n", wc_ary[i].count);
    }

    word_ary_qsort(wc_ary, tree_size);
    for (int i = 0; i < tree_size; i++) {
        printf("%d - ", wc_ary[i].count);
        printf("%s\n", wc_ary[i].word);
    }

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
        tree_get_size(root_p->left, counter);
    }
    (*counter)++;
    if (root_p->right != NULL) {
        tree_get_size(root_p->right, counter);
    }
}


int create_word_ary(tnode **wc_pp, tnode *root_p)
{
    static int i = 0;
    static int error_indicator = 1;

    if (root_p->left != NULL) {
        create_word_ary(wc_pp, root_p->left);
    }

    // executed for each node in tree
    if (error_indicator != 1) { return error_indicator; }

    tnode *new_wc;
    new_wc = root_p;
    //if (i == 2) { new_wc = NULL; }
    if (new_wc == NULL) {
        printf("<error> testerror\n");
        error_indicator = 0;
        return error_indicator;
    }
    (*wc_pp)[i++] = *new_wc;

    if (root_p->right != NULL) {
        create_word_ary(wc_pp, root_p->right);
    }
    return error_indicator;
}


void word_ary_qsort(tnode *wc_ary, int high)
{
    int i = 0;
    int j = high;

    if (j < 1) {
        return;
    }

    while (i < j) {
        do {
            i++;
        } while ((wc_ary[i].count < (*wc_ary).count) && i <= high);
        do {
            j--;
        } while ((wc_ary[j].count > (*wc_ary).count) && j > 0);
        if (i < j) {
            wc_swap(&(wc_ary[i].count), &(wc_ary[j].count));
        }

    }
    wc_swap(&((*wc_ary).count), &(wc_ary[j].count));

    word_ary_qsort(wc_ary, j);
    word_ary_qsort((wc_ary+j+1), (high-j-1));  
}


void wc_swap(int *v1, int *v2)
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

