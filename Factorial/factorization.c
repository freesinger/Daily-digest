/* Prime factorize a postive integer */

#include <stdio.h>

int main(void)
{
    int input, i;

    printf("Enter a postive number: ");
    scanf("%d", &input);
    printf("Result: %d = ", input);

    if (input == 1)
        printf("1");

    for (i = 2; i < input; i++)
        while (i != input) {
            if (input % i == 0) {
                printf("%d * ", i);
                input = input / i;
            } else break;
        }
    printf("%d\n", input);

    return 0;
}
