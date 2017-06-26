/* Calculate sum of random number of integers in array */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int num, random;
    int counter = 0, sum = 0;

    printf("Enter number(> 2): ");
    scanf("%d", &num);
    
    //array must declare here
    int array[num];
    int flag[num];

    for (int i = 0; i < num; i++)
        flag[i] = 0;

    printf("Enter %d numbers: ", num);
    for (int i = 0; i < num; i++)
        scanf("%d", &array[i]);
    /* do {
        scanf("%d", &array[i]);
        sum += array[i];
        i++;
    } while (getchar() != '\n' && i < n); */

    printf("Enter random number: ");
    scanf("%d", &random);

    printf("Sum of %d random numbers = ", random);
    while (1) {
        srand((unsigned)time(NULL));
        int value = rand() % num; //value in range 0 ~ n - 1

        if (flag[value] == 0) {
            flag[value] = 1;
            counter++;
            printf("%d ", array[value]);
            if (counter < random) 
                printf("+ ");
            sum += array[value];
        }
        if (counter == random) 
            break;
    }
    printf("= %d\n", sum);
    
    return 0;
}