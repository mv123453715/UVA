#include<bits/stdc++.h>
using namespace std;

int n ;
int main(){
    int i,j,k,T;
    cin >>T;
    while( T-- ){
        cin >>n;
        int A[n+1];
        for ( i = 1;i <=n;i++ )
            cin >> A[i];
        int ans = 0;
        int bg[n+1],en[n+1];
        for( i = n;i>=1;i-- ){///每個人當中心
            bg[i] = 1,en[i] = 1;///每個初始是1
            for( j = n;j>i;j-- ){///從後面開始挑列車
                if ( A[i] < A[j] && bg[i] <=bg[j] )///較大 可放入前面
                    bg[i] = bg[j]+1 ;///+1
                if ( A[i] > A[j] && en[i] <=en[j] )///較小  可放入後面
                    en[i] = en[j]+1 ;///+1
                ans = max(ans,bg[i]+en[i]-1);///自己重複
            }//for
        }//for

        cout<<"bg\n";
        for( i = 1;i<=n;i++ )
            cout <<bg[i] << " ";
        cout << "\nen\n";
        for( i = 1;i<=n;i++ )
            cout <<en[i] << " ";


        cout <<ans<<endl;
    }//while
    return 0;
}//main
