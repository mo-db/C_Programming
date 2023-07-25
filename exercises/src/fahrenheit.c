#include <stdio.h>

int main(void) {
    /*
    // My shity version

    float fahrenheit = 0;
    float celsius;
    printf("Fahrenheit Celsius\n");
    for (int n = 0; n < 16; n++)
    {
        celsius = (5.0/9.0) * (fahrenheit-32.0);
        printf("%3.0f\t%6.1f\n", fahrenheit, celsius);
        fahrenheit += 20;
    }
    */


   // for statement version
   

    int fahr;
    for (fahr = 300; fahr >= 0; fahr -= 20) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
    }
}