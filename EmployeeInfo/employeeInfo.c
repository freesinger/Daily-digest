/* Filter specified employee */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 3

struct Employee {
    char *name; //char name[10]
    char *sex;  //char sex[10]
    int workYear;
    int wage;
}info[N];

void input(struct Employee *worker);
void output(struct Employee *worker);

int main(void)
{
    for (int i = 0; i < N; i++) {
        info[i].name = (char*)malloc(sizeof(char) * 10); 
        info[i].sex = (char*)malloc(sizeof(char) * 10);
    }
    input(info);
    output(info);

    return 0;
}

void input(struct Employee *worker)
{
    for (int i = 0; i < N; i++) {
         printf("Enter name, sex, workyear and wage: ");
         scanf("%s %s %d %d", worker[i].name, worker[i].sex, 
               &worker[i].workYear, &worker[i].wage);
    }
    putchar('\n');
}

void output(struct Employee *worker)
{
    for (int i = 0; i < N; i++)
        if (worker[i].workYear > 10 && worker[i].wage < 3000 && 
            !strcmp(worker[i].sex, "man"))
            printf("%s %s %d %d\n", worker[i].name, worker[i].sex, 
                   worker[i].workYear, worker[i].wage);
}