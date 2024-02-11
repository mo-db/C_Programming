#include <stdio.h>

void test_func();

int main()
{
    long double start;
    long double end;
    long double step;

    
    printf("please enter start: ");
    scanf("%Ld", &start);

    printf("please enter end: ");
    scanf("%Ld", &end);

    printf("please enter step: ");
    scanf("%Ld", &step);
    

    while (start <= end) {
        printf("%Ld\n", start);
        start += step;
    }

    return 0;
}
