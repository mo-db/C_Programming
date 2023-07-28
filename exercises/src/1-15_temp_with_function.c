#include <stdio.h>

float fahr_to_celsius(float);
float celsius_to_fahr(float);

int main(void) {
    int fahr, celsius;

    for (fahr = 0; fahr < 300; fahr += 20) {
        printf("%3d %6.1f\n", fahr, fahr_to_celsius(fahr));
    }
    printf("\n");
    for (celsius = 0; celsius <= 300; celsius += 20) {
        printf("%3d %6.1f\n", celsius, celsius_to_fahr(celsius));

    }
}

float fahr_to_celsius(float fahr)
{
    float celsius = (5.0/9.0) * (fahr-32);
    return celsius;
}

float celsius_to_fahr(float celsius)
{
    float fahr = celsius * (9.0/5.0) + 32;
    return fahr;
}