/* 求中序数 */

#include<stdio.h>

int main(void)
{
    int init, cnt;

    scanf("%d", &init);

    /*
    // Asc
    cnt = 2;
    while (cnt < 9) {
        printf("%d ", init % cnt);
        // printf("%d\n", init /= cnt);
        init /= cnt;
        cnt++;
    }
    */

    // Des
    cnt = 8;
    while (cnt > 2) {
        printf("%d ", init % cnt);
        // printf("%d\n", init /= cnt);
        init /= cnt;
        // Output: 1
        while (cnt == 3) {
            printf("%d\n", init);
            break;
        }
        cnt--;
    }

    return 0;
}