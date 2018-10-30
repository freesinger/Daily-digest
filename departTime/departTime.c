#include<stdio.h>

int main(void)
{
    int h, m, e;
    int eh;

    scanf("%d:%d", &h, &m);
    scanf("%d", &e);

    if (e > 60 && e < 120) {
        e -= 60;
        eh = 1;
        h -= eh;
        if (m < e) {
            h -= 1;
            m = 60 + e - m;
        } else {
            m -= e;
        }
    }

    printf("%2d:%.2d\n", h, m);

    return 0;
}