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