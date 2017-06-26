/* Calculate a facorial result of a interger */

#include <stdio.h>

int main(void)
{
    int input, i;
    long int result = 1;

    printf("Enter a integer: ");
    scanf("%d", &input);
    printf("Result: %d! = ", input);

    for (i = input; i > 1; i--) {
        printf("%d * ", i);
        result *= i;
    }
    printf("1 = %ld\n", result);
    
    return 0;
}