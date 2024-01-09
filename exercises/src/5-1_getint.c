#include <stdio.h>
#include <ctype.h>

/*
This program should read a character stream from a text file
and write only the integers into an array. getint() converts one
integer per call.

Later write prog that saves into new file and prints only ints on the
same places like before, everything else are whitespaces
*/

void testprint(int x)
{
    printf("%i ", x);
}

int main()
{
    int testval = 3;
    if (testval <=5) {
        testprint(testval);
    }
    
    return 0;
}