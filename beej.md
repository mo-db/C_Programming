# Functions
- expressions passed to functions get *copied* to parameters of the 
    function
- to get more data of a function: *passing by reference*
- *prototype* declaration of function to allow defenition everywhere
    ```c
    int foo(void);  // This is the prototype!
    ```


# Pointers
- *references*: a variable refers to an object of some type
- each byte of memory is identified by an integer
    - if datatype is larger than a byte, the data is stored in
        adjacent but not necessarily in order
- *pointer* is a variable that holds an adress of data
    - like if you have sorted Post-it's and write the index of one
        Post-it on another
    - or like the adress of a house isn't the house itself, but
        *tells you where to find it!*
- pointers become indispensable when used with *function calls*
- use *&* to find the adress of data
- *%p* prints a pointer
```c
#include <stdio.h>

int main(void)
{
    int i = 10;

    printf("The value of i is %d\n", i);
    printf("And its address is %p\n", (void *)&i);

    // %p expects the argument to be a pointer to void
    // so we cast it to make the compiler happy.
}
```