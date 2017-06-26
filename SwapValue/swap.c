/* Swap value */

#include <stdio.h>

void swap(int *num_1, int *num_2);

int main(void)
{
    int a, b;

    printf("Enter number a&b: ");
    scanf("%d%d", &a, &b);

    swap(&a, &b);

    printf("Now the value of a&b: %d %d", a, b);
    printf("\n");

    return 0;
}

void swap(int *num_1, int *num_2)
{
    int temp;

    temp = *num_1;
    *num_1 = *num_2;
    *num_2 = temp;
}