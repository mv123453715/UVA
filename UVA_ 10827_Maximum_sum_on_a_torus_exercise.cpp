#include<bits/stdc++.h>
using namespace std;

const int maxN = 80;
int A[maxN][maxN],s[maxN],f[maxN];
int n;

int re_row( int x ){
    if ( x <=n )
        return x;
    else
        return x-n;
}//re_row
int main() {
    int i,j,k,T;
    cin >> T;
    while (T--){
        cin >>n;
        for ( i = 1;i <=n;i++ )
            for ( j = 1;j <=n;j++ )
                cin >> A[i][j];
        int ans = 0;
        for ( i = 1; i <=n;i++ ){ ///從哪個row開始
            memset ( s,0,sizeof(s) );///s為row開始 不斷向下壓縮的序列
            for ( j = i;j<=i+n-1;j++ ){///第i row開始走到循環的n列
                int sum = 0;
                for ( k = 1;k<=n;k++ ){ ///算出s[k]的sum  加入新的一列A
                    s[k] += A[ re_row(j) ][k];
                    sum +=s[k];///加入壓縮後的  不是+A[ re_row(j) ][k]
                }//for

                memset ( f,0,sizeof(f) );///更新成0即可 因為可都不選  不可用-0x3f
                for ( k = 1;k<=n;k++ ){///正向找 max
                    f[k] = max(f[k],f[k-1] + s[k]);///0跟前一個+s[k]去比
                    ans = max( ans,f[k] );///比哪個大
                }//for
                //min
                memset ( f,0,sizeof(f) );///更新成0即可 因為可都不選  不可用0x3f
                for ( k = 1;k<=n;k++ ){  ///逆向找 max
                    f[k] = min(f[k],f[k-1] + s[k]);///0比較小  還是加入後比較小
                    ans = max( ans,sum-f[k] );///若最大在逆序則最小區間和在正序  用sum-f[k]掉即可
                }//for

            }//for
        }//for
        cout <<ans<<endl;
    }//while
    return 0;
}
