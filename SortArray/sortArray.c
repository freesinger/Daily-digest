/* Sort the given array */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

int main(void)
{
    /* char (*str)[10] = malloc(N * 10 * sizeof(char));//多维数组空间的动态分配？
    char *temp = malloc(10 * sizeof(char));

    printf("Enter %d string: ", N);
    for (int i = 0; i < N; i++)
        scanf("%s", str[i]);
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (strlen(str[i]) > strlen(str[j])) {
                *temp = *str[i];
                *str[i] = *str[j];
                *str[j] = *temp;
            }
        }
    } */

    char *str[N] = {"ho", "shanea", "you", "arent", "seen"};
    char *temp, spec[N + 1];
    /* spec = malloc((N + 1) * sizeof(char)); */

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (strlen(str[i]) > strlen(str[j])) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }

    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
        printf("%s ", str[i]);
    putchar('\n');

    for (int i = 0; i < N; i++)
        //good taste code here
        spec[i] = (strlen(str[i]) > 2) ? *(str[i] + 2) : ' ';
    //necessary '\0' here
    spec[strlen(spec)] = '\0';

    puts(spec);

    return 0;
}