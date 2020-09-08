#include<bits/stdc++.h>
using namespace std;

long long int f[51][51][51];
int main() {
    int i,j,k,p,N,K,M;

    memset( f,0,sizeof(f) );
    for ( i = 0; i <51;i++ )
        f[0][0][i] = 1;  ///0個bar  0個分割 最大i單位 為1

    for ( i = 1; i <51;i++ )
        for ( j= 1; j <51;j++ )
            for ( k = 1; k <51;k++ )
                for ( p = 1; p <=i && p<=k;p++ )  /// p <= i 怕overflow   i-p,j-1,k  p 1~k
                    f[i][j][k] += f[i-p][j-1][k];///公式 f[i][j][k] += f[i-p][j-1][k]

    while( cin >>N>>K>>M){
        cout << f[N][K][M]<<endl;
    }//while
    return 0;
}//main()
