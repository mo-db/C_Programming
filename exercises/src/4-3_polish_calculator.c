#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

#define OP_SIZE_MAX 100
#define FOUND_NUMBER '0'

int getop(char []);
void push(double);
double pop(void);


int main()
{
    int type;
    double op2;
    char s[OP_SIZE_MAX];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case FOUND_NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
            } else {
                printf("error: zero devisor\n");
            }
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    printf("test\n");
    return 0;
}


#define STACK_DEPTH_MAX 100

int stack_position = 0;
double stack[STACK_DEPTH_MAX];


void push(double f)
{
    if (stack_position < STACK_DEPTH_MAX) {
        stack[stack_position++] = f;
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