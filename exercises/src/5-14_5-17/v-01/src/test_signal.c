#include <signal.h>
// https://stackoverflow.com/questions/1591361/understanding-typedefs-for-function-pointers-in-c


//void (*signal(int, void(*)(int)))(int);

typedef void (*SignalHandler)(int);

//   type    |   this is a function pointer on return |
SignalHandler signal(int signum, SignalHandler handler);


int (*(*foo)(void ))[3];
void (*) test(int) (int);

typedef int (*foo_ptr) (int, int);
foo_ptr foo;




void test_func1(int);
void test_func2(int);

void my_signal(int, void (*) (int));



int main()
{
    int value = 2;
    my_signal(value, test_func1);
    return 0;
}