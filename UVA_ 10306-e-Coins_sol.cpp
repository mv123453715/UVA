#include<bits/stdc++.h>
using namespace std;

int x[42],y[42];
int dp[302][302];

int main()
{
	int n,m,s;
	while (cin >> n){
        while (n --) {
            cin >> m >> s;
            for (int i = 0 ; i <= s ; ++ i)
                for (int j = 0 ; j <= s ; ++ j)
                    dp[i][j] = 100000; // init

            for (int i = 1 ; i <= m ; ++ i) {
                cin >> x[i] >> y[i];
                dp[x[i]][y[i]] = 1; /// one coin
            }//for

            for (int i = 1 ; i <= m ; ++ i) /// 跑過每個硬幣
                for (int j = x[i] ; j <= s ; ++ j)///固定一維
                    for (int k = y[i] ; k <= s ; ++ k)///跑另一維
                        if (dp[j][k] > dp[j-x[i]][k-y[i]]+1)///可能可以用上這個硬幣  放入後+1
                            dp[j][k] = dp[j-x[i]][k-y[i]]+1;

            int max = 100000;
            for (int i = 0 ; i <= s ; ++ i) ///跑過兩維
                for (int j = 0 ; j <= s ; ++ j)
                    if (i*i+j*j == s*s && max > dp[i][j])///剛好相等 且max較大  取小
                        max = dp[i][j];

            if (max == 100000)
                printf("not possible\n");
            else
                printf("%d\n",max);
        }//while
	}//while
	return 0;
}
