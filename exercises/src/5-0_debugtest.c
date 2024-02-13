#include <stdio.h>

void test_func();

int main()
{
    long double start;
    long double end;
    long double step;

    
    printf("please enter start: ");
    scanf("%Lf", &start);

    printf("please enter end: ");
    scanf("%Lf", &end);

    printf("please enter step: ");
    scanf("%Lf", &step);
    

    while (start != end) {
        printf("%Lf\n", start);
        start += step;
    }

    return 0;
}
