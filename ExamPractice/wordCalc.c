/* 统计单词 */

#include <stdio.h>
#include <string.h>

const int MAX = 100;

int main(void)
{
    char word[MAX];

    // while (scanf("%s", word) != ' ' || scanf("%s", word) != '\n')
    while (scanf("%s", word) != EOF) {
        int len = strlen(word);
        if (word[len - 1] == '.')
        {
            printf("%d", len - 1);
        } else {
            printf("%d ", len);
        }
    }

    return 0;
}