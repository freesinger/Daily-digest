/* Incremental Permutation */

#include<iostream>
#include<utility>
#include<cmath>

using namespace std;

// 由中介数求序号
int serialNum(int *arr, int N)
{
    int temp = arr[1];

    for (int i = 1; i < N - 1; i++)
        temp = temp * (N - i) + arr[i + 1];

    return temp;
}

// 由序号求中介数
void incSerailNum(int *arr, int N, int pre)
{
    int cnt = 2, extra;

    while (N) {
        extra = pre % cnt;
        arr[--N] = extra;
        pre = (pre - extra) / cnt;
        cnt++;
        //cout << pre << ' ' << extra << N << endl;
    }
}

// 输出下一排列
void nextPerm(int *arr, int *res, int N)
{
    int temp, pos;
    int num = N;

    for (int i = 1; i < N; i++) {
        pos = N;
        temp = arr[i] + 1;
        // cout << pos << ' ' << temp << endl;
        while (temp != 0) {
            if (res[pos] == 0) {
                pos--;
                temp--;
            } else {
                pos--;
            }
        }
        // pos初值N+1数组越界 ++pos修复位置值
        res[++pos] = num--;
        // cout << res[pos] << ' ' << pos << endl;
    }

    for (int i = 1; i < N + 1; i++)
        if (res[i] == 0)
            res[i] = 1;
    /*for (int i = 1; i <= N; i++) {
        pos = N - arr[i];
        while (pos >= 1) {
            if (!res[pos]) {
                res[pos] = num--;
                break;
            } else {
                pos--;
            }
        }
    }*/

    for (int i = 1; i < N + 1; i++)
        cout << res[i] << ' ';
    
    cout << endl;
}

int main(void)
{
    int num, snum;
    cin >> num;

    int raw[num + 1];
    int midV[num], next_midV[num];

    //for (int i = 0; i < num; i++)
    //    raw[i] = i;

    raw[1] = 8, raw[2] = 3, raw[3] = 9;
    raw[4] = 6, raw[5] = 4, raw[6] = 7;
    raw[7] = 5, raw[8] = 2, raw[9] = 1;

    // 求中介数
    for (int j = 1; j < num + 1; j++) {
        int cnt = 0;
        for (int k = j + 1; k < num + 1; k++) {
            if (raw[k] < raw[j])
                cnt++;
        }
        // 顺序存储 a1 a2 a3注意倒序输出
        midV[num - raw[j] + 1] = cnt;
    }

    //cout << midV[1] << midV[2] << endl;
    for (int i = 1; i < num; i++)
        cout << midV[i];
    cout << endl;

    snum = serialNum(midV, num);
    cout << snum << endl;

    snum++;
    cout << snum << endl;

    incSerailNum(next_midV, num, snum);

    for (int i = 1; i < num; i++)
        cout << next_midV[i];
    cout << endl;

    int res[num + 1];
    for (int i = 0; i < num + 1; i++)
        res[i] = 0;

    nextPerm(next_midV, res, num);

    /*int total = 1;
    while (num-- > 1)
        total *= num;
    
    while (--total) {
        snum = serialNum(midV, num);
        snum++;
        decSerailNum(next_midV, num, snum);
        int res[num];
        for (int i = 0; i < num; i++)
            res[num] = 0;
        nextPerm(next_midV, res, num);
    }*/

    return 0;
}