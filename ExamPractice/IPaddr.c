/* IP地址 */

#include <stdio.h>

int main(void)
{
    int add[4];

    scanf("%d.%d.%d.%d", &add[0], &add[1], &add[2], &add[3]);
    for (int i = 0; i < 4; i++) {
        if (add[i] < 0 || add[i] > 255) {
            printf("No!\n");
            return 0;
        }
    }
    printf("Yes!\n");

    return 0;
}