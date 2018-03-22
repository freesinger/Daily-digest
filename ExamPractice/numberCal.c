/* 统计数字出现次数 */

#include <stdio.h>

static int counter = 0;

void process(int number, int target)
{
    if (number == target)
        counter++;
    if (number >= 10 && number < 100) {
        process(number % 10, target);
        process(number / 10, target);
    }
    if (number >= 100 && number < 1000) {
        process(number % 100, target);
        process(number / 100, target);
    }
    if (number >= 1000 && number < 10000) {
        process(number % 1000, target);
        process(number / 1000, target);
    }
}

int main(void)
{
    int low, high, number;

    printf("Enter range: ");
    scanf("%d%d", &low, &high);
    printf("Number you want cal: ");
    scanf("%d", &number);

    while (low < high)
        process(low++, number);

    printf("%d shows time: %d\n", number, counter);

    return 0;
}