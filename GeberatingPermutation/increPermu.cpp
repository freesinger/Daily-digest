/* Incremental Permutation */

#include<iostream>
#include<utility>
#include<time.h>

using namespace std;

int fact(int number)
{
    int res = number;

    while (--number)
        res *= number;

    return res;
}

// 由中介数求序号
int serialNum(int *arr, int N)
{
    int temp = arr[1];

    for (int i = 1; i < N - 1; i++)
        temp = temp * (N - i) + arr[i + 1];

    return temp;
}

// 由序号求中介数
void incSerialNum(int *arr, int N, int pre)
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
        // pos初值N+1错误 ++pos修复位置值
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
    float start, end, dur;
    start = clock();
    cin >> num;

    int raw[num + 1];
    int midV[num], next_midV[num];

    for (int i = 1; i < num + 1; i++)
        raw[i] = i;

    // 求初始中介数
    for (int j = 1; j < num + 1; j++) {
        int cnt = 0;
        for (int k = j + 1; k < num + 1; k++) {
            if (raw[k] < raw[j])
                cnt++;
        }
        // 顺序存储 a1 a2 a3注意倒序输出
        midV[num - raw[j] + 1] = cnt;
    }

    // 初始序号
    snum = serialNum(midV, num);
    
    // 初始排列
    for (int i = 1; i < num + 1; i++)
        cout << raw[i] << ' ';
    cout << endl;

    int total = fact(num);
    //while (--num)
    //   total *= num;

    while (--total) {
        snum++;

        incSerialNum(next_midV, num, snum);

        /* for (int i = 1; i < num; i++)
            cout << next_midV[i];
        cout << endl; */

        int res[num + 1];
        for (int i = 0; i < num + 1; i++)
            res[i] = 0;

        nextPerm(next_midV, res, num);
    }

    end = clock();
    dur = (double)(end - start) / CLOCKS_PER_SEC;

    cout << dur * 1000 << "ms" << endl;

    return 0;
}