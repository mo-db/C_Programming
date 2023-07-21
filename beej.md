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



- store pointer in var
```c
int i;
int *p;  // p is a pointer, but is uninitialized and points to garbage

p = &i;  // p is assigned the address of i--p now "points to" i
```



- The address of a thing can be stored in a pointer to that thing
- *dereferencing* the pointer
    - use the original *variable* through the *pointer*
    - like looking at an adress and then going to the house
    - dereference operator is called *indirection operator* is also an 
        *asterisk* *
```c
#include <stdio.h>

int main(void)
{
    int i;
    int *p;  // this is NOT a dereference--this is a type "int*"

    p = &i;  // p now points to i, p holds address of i

    i = 10;  // i is now 10
    *p = 20; // the thing p points to (namely i!) is now 20!!

    printf("i is %d\n", i);   // prints "20"
    printf("i is %d\n", *p);  // "20"! dereference-p is the same as i!
}
```



## Passing pointers as arguments
- every argument you pass a function gets copied into parameters of
    that function and you then can return one thing at the end
- pass a reference pointer and so you can change things in the
    function without the need of returning anything
```c
#include <stdio.h>

void increment(int *p)  // note that it accepts a pointer to an int
{
    *p = *p + 1;        // add one to the thing p points to
}

int main(void)
{
    int i = 10;
    int *j = &i;  // note the address-of; turns it into a pointer to i

    printf("i is %d\n", i);        // prints "10"
    printf("i is also %d\n", *j);  // prints "10"

    increment(j);                  // j is an int*--to i

    printf("i is %d\n", i);        // prints "11"!
}
```



- the *scanf* function works by passing an adress to it
```c
int i = 0;

scanf("%d", &i);         // pretend you typed "12"
printf("i is %d\n", i);  // prints "i is 12"
```


## NULL Pointer
- setting a pointer to NULL indicates that it doesnt point to anything
- dereferencing a NULL pointer could result in a crash



## Note on Declaring Pointers
```c
int a;
int *p;

int a, *p; //Variables with * infront are pointers
```


## sizeof and Pointers
- *sizeof* operates on the type of the expression
```c
int *p;

// Prints size of an 'int'
printf("%zu\n", sizeof(int));

// p is type 'int *', so prints size of 'int*'
printf("%zu\n", sizeof p);

// *p is type 'int', so prints size of 'int'
printf("%zu\n", sizeof *p);
```



# Arrays
- in C arrays are just syntactic sugar that are actually pointers
    and stuff deep down!
- *sizeof* array only works by dividing the result by the size of
    each element of that array
    - this only works in the scope the array was defined!
```C
int x[12];

printf("%zu\n", sizeof x); // 48 total bytes
printf("%zu\n", sizeof(int)); // 4 bytes per int

printf("%zu\n", sizeof x / sizeof(int)); //48/4 = 12 ints!
```
- if you pass an array to a function, you`re only passing a pointer
    to the first element
```C
void foo(int x[12])
{
    printf("%zu\n", sizeof x);     // 8?! What happened to 48?
    printf("%zu\n", sizeof(int));  // 4 bytes per int

    printf("%zu\n", sizeof x / sizeof(int));  // 8/4 = 2 ints?? WRONG.
}
```


# Array Initializers
```C
int a[5] = {22, 37, 3490};

// is the same as:

int a[5] = {22, 37, 3490, 0, 0};
```
- common shortcut to set entire array to 0 
```C
int a[100] = {0};
```
- one can set specific elements in the initializer
```C
int a[10] = {0, 11, 22, [5]=55, 66, 77};
// Output: 0 11 22 0 0 55 66 77 0 0
```
- if you give no size, C uses the size of given number
    of initializers



# Out of Bounds
- printing more elements than wich are in an array results in
    undefined behavior



# Multidimensional Arrays
```C
#include <stdio.h>

int main(void)
{
    int row, col;

    int a[2][5] = {      // Initialize a 2D array
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9}
    };

    for (row = 0; row < 2; row++) {
        for (col = 0; col < 5; col++) {
            printf("(%d,%d) = %d\n", row, col, a[row][col]);
        }
    }
}
```
- you can initialize with explicit indexes
```C
int a[3][3] = {[0][0]=1, [1][1]=1, [2][2]=1};
```


# Arrays and Pointers
- a pointer to an array points only to the first element
```C
#include <stdio.h>

int main(void)
{
    int a[5] = {11, 22, 33, 44, 55};
    int *p;

    p = &a[0];  // p points to the array
                // Well, to the first element, actually

    printf("%d\n", *p);  // Prints "11"
}
```
- same thing as
```C
p = &a[0];  // p points to the array

// is the same as:

p = a;      // p points to the array, but much nicer-looking!
```


# Passing single dim arrays to functions
```C
#include <stdio.h>

// Passing as a pointer to the first element
void times2(int *a, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 2);
}

// Same thing, but using array notation
void times3(int a[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 3);
}

// Same thing, but using array notation with size
void times4(int a[5], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d\n", a[i] * 4);
}

int main(void)
{
    int x[5] = {11, 22, 33, 44, 55};

    times2(x, 5);
    times3(x, 5);
    times4(x, 5);
}
```



# Changing arrays in functions
```C
#include <stdio.h>

void double_array(int *a, int len)
{
    // Multiply each element by 2
    //
    // This doubles the values in x in main() since x and a both point
    // to the same array in memory!

    for (int i = 0; i < len; i++)
        a[i] *= 2;
}

int main(void)
{
    int x[5] = {1, 2, 3, 4, 5};

    double_array(x, 5);

    for (int i = 0; i < 5; i++)
        printf("%d\n", x[i]);  // 2, 4, 6, 8, 10!
}
```
- functions can make changes to arrays that are visable for the caller



# Multidim arrays to functions
```C
#include <stdio.h>

void print_2D_array(int a[2][3])
{
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++)
            printf("%d ", a[row][col]);
        printf("\n");
    }
}

int main(void)
{
    int x[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    print_2D_array(x);
}
```