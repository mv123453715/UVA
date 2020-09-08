#include<bits/stdc++.h>
using namespace std;

struct XY{
    int x,y;
};

int n,ans,dp[1<<11][11],adj[11][11];
XY bear[11],s;

void TSP( int s,int d,int s_size ){
    int i,j,k;
    if ( s_size == n  ){
        ans =min( ans,dp[s][d] + adj[d][0] );///從s到d  的dp  再從d回到0
        return ;
    }//if
    else{
        for( i = 1; i <=n ;i ++ ){
            if ( !( s&(1<<i) ) ){ ///s沒去過第i個bear點
                //cout << "s:"<<s<<endl;
                int ss = s | (1<<i);///去過ss這些地方 + 上新的bear點
                if ( !dp[ss][i] ||  dp[ss][i]  > dp[s][d]+adj[d][i] ){///!dp[ss][i]是0 沒更新過或者ss到i跟dp[s][d] + d走到i比較
                    dp[ss][i]  =  dp[s][d]+adj[d][i];
                    TSP( ss,i,s_size+1 );
                }//if
            }//if
        }//for
    }//else
}//TSP

int main() {
    int i,j,k,T;
    cin >>T;
    while( T-- ){
        cin >>s.x >>s.y>>bear[0].x>>bear[0].y;///原點
        cin >>n;

        for( i = 1;i <=n;i++ )
            cin >> bear[i].x>>bear[i].y;

        for( i = 0;i <=n;i++ )
            fill ( adj[i],adj[i]+n+1,0 );

        for( i = 0;i <=n;i++ ){
            for( j = i+1;j <=n;j++ ){///對稱
                adj[i][j] = abs(bear[i].x - bear[j].x) + abs(bear[i].y - bear[j].y);
                adj[j][i] = adj[i][j];
            }//for
        }//for

        memset( dp,0,sizeof(dp) );
        ans = 0x3f3f3f;
        TSP(0,0,0);
        cout <<"The shortest path has length "<< ans<<endl;
    }//while
    return 0;
}//main()
