#include <stdio.h>

// studend is an alias of the struct decleration
typedef struct
{
    char name[50];
    int id[10];
    int age;
    int grades[5];

} student;

// a struct of "type" point
struct pnt
{
    int x;
    int y;
} p1, p2, p3;

typedef struct
{
    int x;
    int y;
} point;

typedef struct
{
    int test_ary[2];
} data;

void print_student(student s)
{
    printf("Age: %d\n", s.age);
}

// Counts the occurences of c keywords in given input stream
int main()
{
    student karl;
    karl.age = 26;
    print_student(karl);
    // init a struct with list of initializers
    point point1 = {4, 8};

    point points[10];
    for (int i = 0; i < 10; i++) {
        points[i].x = i;
        points[i].y = 9 - i;
    }
    /*
    printf("Points: \n\n");
    for (int i = 0; i < 10; i++) {
        printf("Point %d: %d, %d\n", i, points[i].x, points[i].y);
    }
    */

    data x, y;

    /*
    int ary1[2];
    int ary2[2];
    x.test_ary = ary1;
    y.test_ary = ary2;
    */

    x.test_ary[0] = 1;
    x.test_ary[1] = 2;

    y.test_ary[0] = 9;
    y.test_ary[1] = 9;

    // the pointer to array gets memory copied here
    x = y;
    
    // so with this line we also change y, isnt the case if no pointer to ary, just array
    x.test_ary[1] = 7;

    for (int i = 0; i < 2; i++) {
        printf("Array: %d\n", x.test_ary[i]);
    }

    return 0;
}