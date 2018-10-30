#include<stdio.h>

int main(void)
{
    int h, m, e;
    int eh;

    scanf("%d:%d", &h, &m);
    scanf("%d", &e);

    if (e >= 60 && e < 120) {
        e -= 60;
        eh = 1;
        h -= eh;
        if (m < e) {
            h -= 1;
            m = 60 + m - e;
        } else {
            m -= e;
        }
    }

    if (e >= 120 && e < 180) {
        e -= 120;
        eh = 2;
        h -= eh;
        if (m < e) {
            h -= 1;
            m = 60 + m - e;
        } else {
            m -= e;
        }
    }

    printf("%2d:%.2d\n", h, m);

    return 0;
}