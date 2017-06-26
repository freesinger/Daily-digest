/* Filter specified employee */
#include <stdio.h>
#include <string.h>

#define N 3

struct Employee {
    char name[10];
    char sex[6];
    int workYear;
    int wage;
};

void input(struct Employee *worker);
void output(struct Employee *worker);

int main(void)
{
    struct Employee info[N]; 
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