#include <bits/stdc++.h>
using namespace std;
int p[1005], pt;
void sieve() { //create prime_tb
    int mark[1005] = {}, i, j;
    pt = 0;
    for(i = 2; i < 1000; i++) {
        if(mark[i] == 0) {
            for(j = i+i; j < 1000; j += i)
                mark[j] = 1;
            p[pt++] = i;// 所有質數
        }//if
    }//for
    cout<< "pt:"<<pt<<endl;

    for(i = 0; i < 1000; i++)
        cout << " p[" << i << "]:" << p[i] <<endl;
}//sieve
int main() {
    sieve();
    int A, B, i, cases = 0;
    while(scanf("%d %d", &A, &B) == 2) {
        if(A == 0)  break;
        queue<int> Q;// BFS Queue
        int dp[1005] = {}, used[1005] = {};// init
        Q.push(A); // push A in rear
        used[A] = 1;// used
        while(!Q.empty() && !used[B]) {// scan all or find B
            A = Q.front(), Q.pop();//  take num from front
            for(i = 0; i < pt && p[i] < A; i++) { // pt is 168  質數比A小
                if(used[A+p[i]] == 0 && A%p[i] == 0) {//加入質數  且是質因數
                    if(A+p[i] <= B) {// <= B就push
                        dp[A+p[i]] = dp[A]+1; // 加一層
                        used[A+p[i]] = 1;// 改成used
                        Q.push(A+p[i]);
                    }//if
                }//if
            }//for
        }//while
        printf("Case %d: ", ++cases);
        if(used[B])//有被找到就輸出
            printf("%d\n", dp[B]);
        else    //沒有就放-1
            puts("-1");
    }//while
    return 0;
}//main
