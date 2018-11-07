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
void decSerailNum(int *arr, int N, int pre)
{
    int cnt = 2, extra;

    while (N--) {
        extra = pre % cnt;
        arr[N - 1] = extra;
        pre = (pre - extra) / cnt;
        cnt++;
    }
}

// 输出下一排列
void nextPerm(int *arr, int *res, int N)
{
    for (int i = 0; i < N; i++) {
        int pos = N - 1 - arr[i];
        while (pos >= 0) {
            if (!res[pos]) {
                res[pos] = N;
                break;
            } else {
                pos--;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << res[i] << ' ';
    
    cout << endl;
}

int main(void)
{
    int num, snum;
    cin >> num;

    int raw[num];
    int midV[num - 1], next_midV[num - 1];

    for (int i = 0; i < num; i++)
        raw[i] = i;

    // 求中介数
    for (int j = 0; j < num; j++) {
        int cnt = 0;
        for (int k = j + 1; k < num; k++) {
            if (raw[k] < raw[j])
                cnt++;
        }
        midV[j] = cnt;
    }

    int total = 1;

    while (num-- > 1)
        total *= num;
    
    while (--total) {
        snum = serialNum(midV, num);
        snum++;
        decSerailNum(next_midV, num, snum);

        int res[num];
        for (int i = 0; i < num; i++)
            res[i] = 0;

        nextPerm(next_midV, res, num);
    }

    return 0;
}