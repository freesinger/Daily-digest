/* 矩阵转置 */

#include <stdio.h>

int main(void)
{
    int N, num, temp;
    scanf("%d", &N);
	int s[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &s[i][j]);
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            temp = s[i][j];
            s[i][j] = s[j][i];
            s[j][i] = temp;
        }
    } 
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
			printf("%d ", s[i][j]);
    	printf("\n");
    }
    return 0;
}