#include <stdio.h>

void swap2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    typedef char (*func)();
    typedef func ary[];
    typedef ary *z2();

    char (*(*z1())[])();

    
    int x = 42;
    int y = 17;
    int *ptr_ary[] = {&x, &y};
    printf("Original: \n\nx_ptr: %d \ny_ptr: %d\n", *ptr_ary[0], *ptr_ary[1]);

    int *t = ptr_ary[0];
    ptr_ary[0] = ptr_ary[1];
    ptr_ary[1] = t;

    printf("Swaped: \n\nx_ptr: %d \ny_ptr: %d\n", *ptr_ary[0], *ptr_ary[1]);

    int i = 3;
    int k = 8;
    int * test_ptr;
    int test_ary[]  = {i, k};

    i += 3;
    k--;
    //printf("I: %d \nK: %d\n", i, k);
    //printf("I: %d \nK: %d\n", test_ary[0], test_ary[1]);
    char c_1[] = "test";
    char c_2[] = "hallo";
    char *c_ptr_ary[] = {c_1, c_2};


    //swap2(&x, &y);
    //printf("x: %d \nY: %d\n", x, y);
    return 0;
}
