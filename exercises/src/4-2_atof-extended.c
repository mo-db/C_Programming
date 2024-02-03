#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>


double atof_ex(char []);


int main()
{
    char string_sample[] = "52.89e-3";
    printf("converted double: %f\n", atof_ex(string_sample));
    return 0;
}


double atof_ex(char string_sample[])
{
    double value, power;
    int i, sign;

    for (i = 0; isspace(string_sample[i]); i++) {
        i++;
    }
    sign = (string_sample[i] == '-') ? -1 : 1;
    if (string_sample[i] == '+' || string_sample[i] == '-') {
        i++;
    }
    for (value = 0.0; isdigit(string_sample[i]); i++) {
        value = 10.0 * value + (string_sample[i] - '0');
    }
    if (string_sample[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(string_sample[i]); i++) {
        value = 10.0 * value + (string_sample[i] - '0');
        power *= 10.0;
    }
    
    // handle scientific notation
    int power_sign;
    double power_sci;
    if (string_sample[i] == 'e' || string_sample[i] == 'E') {
        i++;
    }
    power_sign = (string_sample[i] == '-') ? -1 : 1;
    if (string_sample[i] == '-' || string_sample[i] == '+') {
        i++;
    }
    if (power_sign == 1) {
        power_sci = pow(10, (string_sample[i] - '0'));
    } else if (power_sign == -1) {
        power_sci = pow(10, -(string_sample[i] - '0'));
    } else {
        printf("ERROR");
    }

    return (sign * value / power) * power_sci;
}