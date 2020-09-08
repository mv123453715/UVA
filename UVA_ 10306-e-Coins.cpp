#include<bits/stdc++.h>
using namespace std;

struct COIN{
    int x,y;
};

int main(){

    int i,j,k,n,m,s;
    cin >>n;
    while ( n-- ){
        int m,s;
        cin >>m>>s;
        COIN coin[m+1];
        int dp[s+1][s+1];

        for ( i = 0; i <s+1;i++ )
            fill( dp[i],dp[i] +s+1,0x3f3f3f3f );///�n��fill memset�O��byte�ާ@  0x3f3f3f3f ���i+1��INF

        for( i = 1; i <=m;i++ ){
            cin >> coin[i].x >> coin[i].y;
            dp[coin[i].x][coin[i].y] = 1;
        }//for

        for ( i = 1 ;i <=m;i++ )/// �]�L�C�ӵw��
            for( j = coin[i].x;j<=s;j++ )///�T�w�@��
                for( k = coin[i].y;k<=s;k++ )///�]�t�@��
                    dp[j][k] = min( dp[j][k],dp[j-coin[i].x][k-coin[i].y]+1 );///�i��i�H�ΤW�o�ӵw��  ��J��+1

        int min_num = 0x3f3f3f3f;///INF
        for( i = 0 ;i<=s;i++) ///�]�L���
            for( j = 0 ;j<=s;j++)
                if ( s*s == (i*i+j*j) )  ///��n�۵� ��min
                    min_num = min(min_num,  dp[i][j]);

        if ( min_num == 0x3f3f3f3f )
            cout<<"not possible\n";
        else
            cout<<min_num <<endl;
    }//while
	return 0;
}//main
