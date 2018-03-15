/* 成绩排序 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int result;
} INFO ;

void swap(INFO *s, INFO *j)
{
    INFO temp;
    temp = *s;
    *s = *j;
    *j = temp;
}

int main(void)
{
    int num, sort;
    
    scanf("%d", &num);
    scanf("%d", &sort);
    
    // 动态分配
    INFO *info = malloc(sizeof(INFO) * num);

    for (int i = 0; i < num; i++)
        // 指针就是数组，对数据成员的选择符有所不同
        // scanf("%s%d", info[i].name, &info[i].result);
        scanf("%s%d", (info + i) -> name, &((info + i) -> result));
    
    switch (sort) {
        case 1: for (int i = 0; i < num; i++)
                    for (int j = i + 1; j < num; j++)
                        if (info[j].result < info[i].result)
                            swap(&info[i], &info[j]);
                break;
        case 0: for (int i = 0; i < num; i++)
                    for (int j = i + 1; j < num; j++)
                        if (info[j].result > info[i].result)
                            swap(&info[i], &info[j]);
                break;
        default: printf("error\n");
                 return 0;
    }

    printf("\n");
    for (int i = 0; i < num; i++)
        printf("%s %d\n", info[i].name, info[i].result);

    return 0;
}