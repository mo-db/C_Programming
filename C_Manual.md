### Hello World
- int main() __so main gives back integer with return__



### Vars and Types
- int: char, int, short, long or long long
- unsigned ints: unsigned ", ...
- floats: float, double
- no boolean type in C! But can be defined by doing:
    ```c
    #define BOOL char
    #define FALSE 0
    #define TRUE 1
    ```


### Arrays
- int numbers[10]; array with size 10
- Multidimensional:
    ```c
    char vowels[2][5] = {
      {'A', 'E', 'I', 'O', 'U'},
      {'a', 'e', 'i', 'o', 'u'}
    };
    int val vowels[2][3]; // would be o
    ```


### If statement
- if(a == / < / > b) {};
- if(a < b && / || / != b > c) {}; __&& AND, || OR, != NOT__



### Strings sind in C char arrays
- pointer to character array: __string only usable for reading__
    ```c
    char * name = "John Smith";
    ```
- normal string
    - empty brackets: compiler calculates size automatic!
    - you have to make the string 1 more than acutal length 
        because of special char that indicates the length of a string
    ```c
    char name[] = "John Smith";
    /* is the same as */
    char name[11] = "John Smith";
    int age = 27;
    printf("%s is %d years old.\n", name, age);
    strlen(name); //length of string passed as arg
    strncmp(name "Jonas", 5); //compare if equal, return 0
    strncat();
    sprintf(); //Writes to string
    ```

### While Loop
- Can be infinite if allways true (non 0)
    ```c
    while (1) {
        /* do something */
    }
    ```
- break and continue can halt or continue the loop and skip the rest


### Standard library
The function printf is defined in the c standard library. A library is a compiled source code which can be linked with a program. This allows the functionality exposed by the library to be used from that program. Since the code in the library is already compiled there is no need to compile it again. Only the code you write needs to be compiled and linked with the library files.

When you write a program in c and compile it, the standard c libraries are included automatically to your program which lets you use the standard c functions like printf and scanf.

Why the line #include <stdio.h> is needed then? The file stdio.h contains only the declaration or prototype of the functions like printf. The only purpose it serves is to help the compiler know whether the functions are used like they are supposed to, i.e., whether the data type of the arguments matches the data type given in the declaration, or the number of arguments to the functions, use of return value of the function.

    It is a widely accepted convention that header file "*.h" should not contain any code that may require memory to be allocated in memory sections. For example : MAcros, function and variable declarations
    Definition of any library function is contained in library archives.
        Library archive files are *.a (libc.a or libm.a)
        LIbrary archives will have library object files similar to the ones you generate when you compile the code (*.o file).
        These *.o files are pre-compiled source code that are kept there to let you use it whenever needed.

Just for your information, you can extract out any object file from this archive, resolve its dependencies and then compile it with your code using

gcc -c my_file.o lib_obj1.o lib_obj2.o 