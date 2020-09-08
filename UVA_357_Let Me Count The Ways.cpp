#include<bits/stdc++.h>
using namespace std;
#define N 30001

int main()
{
    int price[5] = { 1,5,10,25,50};
    long long cents[N] = {1};

    for (int i = 0; i <5; i++){ ///跑過每種面額
        for (int j = price[i]; j < N; j++){  ///從那個面額開始起手 小於的不管
            cents[j] += cents[j - price[i]];///使用該面額後的種類數 = 使用該面額前的種類數 + 使用新面額的種類數
        }//for
    }//for
    int n;
    while (cin >>n)
        if (cents[n] == 1)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", cents[n], n);

    return 0;
}
