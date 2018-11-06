/* Dictionary Permutation */

#include<iostream>
#include<utility>
#include<cmath>

using namespace std;

void dicPermu(int *raw, int N)
{
    int temp, min_maxnum, id, flag = 1;

    for (int i = 2; i <= N; i++)
        flag *= i;

    while (--flag) {
        for (int j = N - 1; j > 0; j--)
            if (raw[j - 1] < raw[j]) {
                temp = j;
                // id = j;
                min_maxnum = raw[temp];
                break;
            }

        for (int i = temp; i < N; i++)
            if (raw[i] <= min_maxnum && raw[i] > raw[temp - 1]) {
                min_maxnum = raw[i];
                id = i;
            }

        // turning point
        // cout << temp + 1 << endl;

        if (temp == N - 1 || raw[temp - 1] == raw[temp + 1]) {
            swap(raw[temp], raw[temp - 1]);
        } else {
            swap(raw[temp - 1], raw[id]);
            // cout << raw[temp - 1] << ' ' << raw[temp] << endl;
        }

        for (int k = temp; k < N; k++)
            for (int l = k + 1; l < N; l++)
                if (raw[k] > raw[l])
                    swap(raw[k], raw[l]);

        for (int k = 0; k < N; k++)
            cout << raw[k] << ' ';

        cout << endl;
    }
}

int main(void)
{
    int num;
    cin >> num;

    int arr[num];
    
    for (int i = 0; i < num; i++)
        arr[i] = i + 1;

    for (int i = 0; i < num; i++)
        cout << arr[i] << ' ';
    cout << endl;

    dicPermu(arr, num);

    return 0;
}
