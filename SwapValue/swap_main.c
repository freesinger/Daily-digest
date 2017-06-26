/* Swap value in main() */

#include <stdio.h>

int main(void)
{
    int a, b, temp;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    
    temp = a;
    a = b;
    b = temp;

    printf("Value now is: %d %d", a, b);
    printf("\n");
    
    return 0;
}