#include<bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,n;
    while ( cin >>n ){
        if ( n==0 )
            break;
        int A[10005];
        for ( i = 1;i <=n;i++ )
            cin >>A[i];
        int max_sum =0;
        int dp[10005] = {0};
        for ( i = 1;i<=n;i++ ){
            dp[i] = max( A[i], dp[i-1] + A[i] );/// A[i]比較大 或是dp[i-1] + A[i]比較大
            max_sum = max( max_sum, dp[i] );///比較過每個dp[i]看哪個大
        }//for

        if ( max_sum >0 )
            cout << "The maximum winning streak is "<<max_sum<<".\n";
        else
            cout << "Losing streak.\n";
    }//while


    return 0;
}//main
