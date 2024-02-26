#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define OP_SIZE_MAX 100
#define FOUND_NUMBER '0'

void push(double);
double pop(void);
int get_op(char [], char *);
int get_char(void);


int main(int argc, char * argv[])
{
    int type;
    int * argc_ptr = &argc;
    double op2;
    char op_array[OP_SIZE_MAX];

    while (--argc > 0 && argv != NULL && (type = get_op(op_array, *++argv)) != EOF) {
        switch (type) {
        case FOUND_NUMBER:
            push(atof(op_array));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
            } else {
                printf("error: zero devisor\n");
            }
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                push((int)pop() % (int)op2);
            } else {
                printf("error: zero devisor\n");
            }
            break;
        default:
            printf("error: unknown command %s\n", op_array);
            break;
        }
    }

    printf("%.8g\n", pop());

    return 0;
}


#define STACK_DEPTH_MAX 100

int stack_position = 0;
int sign;
double stack[STACK_DEPTH_MAX];

void push(double f)
{
    if (stack_position < STACK_DEPTH_MAX) {
        stack[stack_position++] = f * sign;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}


double pop(void)
{
    if (stack_position > 0) {
        return stack[--stack_position];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


int get_op(char op_array[], char * v)
{
    int length = strlen(v);

    if (length == 1 && !isdigit(*v)) {
        return *v;
    }

    sign = 1;
    if (*v == '-') {
        sign = -1;
        v++;
    }

    for (int i = 0; i < length; i++) {
        (op_array[i] = *v);
        v++;
    }

    return FOUND_NUMBER;
}


#define BUFFER_SIZE 100
int buffer_position = 0;
char buffer[BUFFER_SIZE];
int get_char(void)
{
    return (buffer_position > 0) ? buffer[--buffer_position] : getchar();
}