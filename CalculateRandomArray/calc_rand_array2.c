/* Calculate sum of random number of integers in array */
/****** This version will output all possible sum ******/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int factorial(int num)
{
    int i = 1;

    while (num > 1) {
        i *= num;
        num--; 
    }

    return i;
}

int choose(int base, int chosen)
{
    int i = 1;

    while (i < chosen) {
        base *= (base - 1);
        i++;
    }

    return base;
}

int main(void)
{
    int num, random;
    int counter = 0;
    /* int size_temp = factorial(num); */    
    //assign here is wrong

    printf("Enter number(> 2): ");
    scanf("%d", &num);
    
    //array must declare here
    int array[num];
    int flag[num];
    int size_temp = factorial(num);
    int sum_array[size_temp];

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
    int temp = choose(num, random);

    /* for (int i = 0; i < temp; i++)
       sum_array[i] = 0; */

    for (int i = 0; i < temp; i++) {
        sum_array[i] = 0;   //sum_array can be assign here
        while (1) {
            srand((unsigned)time(NULL));
            int value = rand() % num; //value in range 0 ~ n - 1
            
            if (flag[value] == 0) {
                flag[value] = 1;
                counter++;
                sum_array[i] += array[value];
            }
            if (counter == random) { 
                counter = 0;  //counter must be clear
                break;
            }  
        }
    }
    
    printf("All possible sum: ");
    for (int i = 0; i < temp; i++)
        printf("%d ", sum_array[i]);
    printf("\n");

    return 0;
}