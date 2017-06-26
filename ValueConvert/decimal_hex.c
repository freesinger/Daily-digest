#include <stdio.h>

void convert(int n)
{
    if (n != 0) {
        convert(n / 16);
        if (n % 16 > 9)
            putchar('A' - 10 + n % 16);
        else
            putchar('0' + n % 16);
    }
}

int main(void) 
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Hex number is：0x");
    convert(number);
    printf("\n");

    return 0;
}