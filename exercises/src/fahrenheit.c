#include <stdio.h>

int main(void)
{
    int fahrenheit = 0;
    int celsius;
    printf("Fahrenheit Celsius\n");
    for (int n = 0; n < 16; n++)
    {
        celsius = 5 * (fahrenheit-32) / 9;
        printf("%d\t%d\n", fahrenheit, celsius);
        fahrenheit += 20;
    }
}