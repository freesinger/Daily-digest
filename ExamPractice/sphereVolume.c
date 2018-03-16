/* 空间球体体积 */

#include <stdio.h>
#include <math.h>

#define PI acos(-1)

int main(void)
{
    double x0, x1, y0, y1, z0, z1;
    double r, V;

    while(scanf("%lf%lf%lf%lf%lf%lf", &x0, &y0, &z0, &x1, &y1, &z1) != EOF) {
        r = sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2) + pow(z0 - z1,2));
        V = 4 * PI * pow(r, 3) / 3;
        printf("%.3f %.3f\n", r, V);
    }

    return 0;
}
