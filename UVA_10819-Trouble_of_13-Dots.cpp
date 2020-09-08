#include<bits/stdc++.h>
using namespace std;

struct ITEM{
    int p,f;
};

int main(){
    int i,j,k,m,n;
    while( cin >>m >>n ){
        ITEM item[n];
        if ( m> 1800 ) /// 超過2000可摺200  故超過1800 可以買到2000的東西
            m+=200;
        for( i = 0;i <n ;i++ )
            cin >> item[i].p >> item[i].f;

        int dp[m+1];
        fill ( dp,dp+m+1,0 );
        for( i = 0;i <n ;i++ ){
            for( j = m; j -item[i].p>=0 ;j-- ){
                dp[j] = max( dp[j],dp[j-item[i].p] + item[i].f );
            }//for
        }//for
        int f = m;///預設為最高
		while (f > 0 && dp[f] == dp[f-1])  ///開始往下找
            --f;

        if (f <= 2000 && m > 2000)///如果f不超過2000  且m超過2000  要把200吐回去
		    cout <<dp[m-200]<<endl;///需要換行
        else
            cout << dp[m]<<endl;///需要換行
    }//while
    return 0;
}//main
