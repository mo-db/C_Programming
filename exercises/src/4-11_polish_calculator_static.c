#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

#define OP_SIZE_MAX 100
#define FOUND_NUMBER '0'

int get_op(char []);
void push(double);
double pop(void);
int exec_command(int);


int main()
{
    int type, tval;
    tval = 1;
    double op2;
    char op_array[OP_SIZE_MAX];

    while ((type = get_op(op_array)) != EOF) {
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
        case '\n':
            if (!tval) {
                tval = 1;
                break;
            }
            printf("\t%.8g\n", pop());
            break;
        default:
            tval = 0;
            if (!exec_command(type)) {
                printf("error: unknown command %s\n", op_array);
            }
            break;
        }
    }

    return 0;
}


#define STACK_DEPTH_MAX 100

int stack_position = 0;
int sign = 0;
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

int exec_command(int command)
{
    switch (command)
    {
    case 'p':
        printf("stack top value: %0.3f\n", stack[0]);
        return 1;
    case 'c':
        printf("clearing stack...\n");
        for (int i = 0; i < STACK_DEPTH_MAX; i++) {
            stack[i] = 0.0;
        }
        return 1;
    default:
        printf("test\n");
        return 0;
    }
}

int get_char(void);
void unget_char(int);

int get_op(char op_array[])
{
    int i, c, c_next;
    static int last_c;

    if (last_c == 0) {
        c = get_char();
    } else {
        c = last_c;
        last_c = 0;
    }
    // while char is ' ' or '\t' get next char
    while ((op_array[0] = c) == ' ' || c == '\t') {
        c = get_char();
    }

    op_array[1] = '\0';

    sign = 1;
    if (c == '-') {
        if (isdigit(c_next = get_char()) || c_next == '.') {
            op_array[0] = c_next;
            c = c_next;
            sign = -1;
        } else {
            last_c = c_next;
        }
    }

    if (!isdigit(c) && c != '.') {
        return c;
    }
    i = 0;
    if (isdigit(c)) {
        while (isdigit(op_array[++i] = c = get_char())) {
            ;
        }
    }
    if (c == '.') {
        while (isdigit(op_array[++i] = c = get_char())) {
            ;
        }
    }
    op_array[i] = '\0';
    if (c != EOF) {
        last_c = c;
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

void unget_char(int c)
{
    if (buffer_position >= BUFFER_SIZE) {
        printf("unget_char: too many characters\n");
    } else {
        buffer[buffer_position++] = c;
    }
}
