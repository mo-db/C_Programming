#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

int get_array_size(int);
void atof_recursive(char [], int);

int sign;

// recursively convert integer to string 
int main()
{
    int number = -188;
    sign = (number < 0) ? -1 : 1;
    number *= sign;

    int string_size = get_array_size(number);
    char string[1000]; // need to use malloc if i want to use string_size var

    atof_recursive(string, number);
    
    printf("array: \n");
    for (int i = 0; i < 3; i++) {
        printf("%c", string[i]);
    }

    return 0;
}


int get_array_size(int number)
{
    int size;
    for (size = 1; (number /= 10) > 0; size++) {
        ;
    }
    return size;
}


void atof_recursive(char string[], int number)
{
    static int counter = 0;
    if (number / 10) {
        atof_recursive(string, number / 10);
    }
    string[counter++] = (number % 10 + '0');
}