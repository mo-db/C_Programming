#include <stdio.h>

// jakob example:
//typedef int (*foo_ptr) (int, int) ;

// from the 2nd comment:
//typedef int op_func(int, int);

int my_add(int x, int y) { return x + y;}
int my_sub(int x, int y) { return x - y;}
int my_mult(int x, int y){ return x * y;}
int my_div(int x, int y) { return x / y;}
int my_modu(int x, int y){ return x % y;}


// no typedef: 
//      int my_operation(int (*foo) (int, int), int x, int y)
// jakob example:
//      int my_operation(foo_ptr foo, int x, int y)
// 2nd comment:
//      int my_operation(op_func *foo, int x, int y)
typedef int op_func(int, int);

int my_operation(op_func *foo, int x, int y)
{
    int result = foo(x, y) + foo(x, y);
    return result;
}

/*
the operation function is a little algorithmus that
calls operation on two values given as args. Use function
pointers to do this. -> why and how much smarter is the
use of function pointers in such a situation?
*/
int main(int argc, char * argv[])
{
    int x = 2;
    int y = 4;
    int my_result = my_operation(my_mult, x, y);
    printf("result: %d\n", my_result);
    return 0;
}