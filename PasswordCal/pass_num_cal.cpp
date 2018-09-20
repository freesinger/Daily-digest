/* Calculate the number of combinics for Android password */

#include<iostream>                               // 1, 2, 3
#include<stack>
using namespace std;                             // 4, 5, 6
#define N 10                                    // 7, 8, 9
 
int d[N][N];
int countn;
bool pos[N] = {0};

/* bool justify(int number)
{
    if (number) {
        pos[number] = false;
        return true;
    } else {
        return false;
    }
} */

int cal(stack<int> S, int number, int step)
{
    S.push(number);
    step--;
    for (int i = 1; i < N; i++) {
        if (d[number][i] == 1) {
            S.push(i);
            step--;
            if (step == 0) {
                S.pop();
                countn++;
            } else {
                cal(S, i, step);
            }
        }
    }
    return countn;
}

int main(void)
{
    stack<int> S;
    countn = 0;
    int step; 

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            d[i][j] = 1;
            d[i][i] = 0;
        }
    }

    d[1][3] = d[1][6] = d[1][7] = d[1][8] = d[1][9] = 0;
    d[2][7] = d[2][8] = d[2][9] = 0;
    d[3][1] = d[3][4] = d[3][7] = d[3][8] = d[3][9] = 0;
    d[4][3] = d[4][6] = d[4][9] = 0;
    d[6][1] = d[6][4] = d[6][7] = 0;
    d[7][1] = d[7][2] = d[7][3] = d[7][6] = d[7][9] = 0;
    d[8][1] = d[8][2] = d[8][3] = 0;
    d[9][1] = d[9][2] = d[9][3] = d[9][4] = d[9][7] = 0;
     
    for (step = 1; step < N; step++)
        for (int num = 1; num < N; num++)
            pos[num] += cal(S, num, step);

    for (int i = 0; i < N; i++)
        cout << i << ", " << pos[i] << endl;

    return 0;
}