/* 最大最小数 */

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int num;

    while (scanf("%d", &num) != EOF) {
        int s[num], min, max;

        for (int i = 0; i < num; i++)
            scanf("%d", &s[i]);

        min = max = s[0];

        for (int i = 0; i < num; i++) {
            if (s[i] < min)
                swap(&s[i], &min);
            if (s[i] > max)
                swap(&s[i], &max);
        }
        printf("%d %d\n", min, max);
    }
    return 0;
}
