#include<bits/stdc++.h>
using namespace std;
const int maxn = 80;
int a[maxn][maxn],s[maxn],f[maxn];  //s为row压缩后的序列。
int n;
inline int down(int x) {  // 为了从最后一行跳到第一行
    return x <= n ? x : x - n;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int ans = 0;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d",&a[i][j]);
        for(int i = 1; i <= n; i++) {// 從第一行開始
            memset(s,0,sizeof(s));
            for(int j = i; j <= n+i-1; j++) {     // 環狀n列都跑過  // 记录每列第i行到第down(j)行的和
                int sum,r = down(j);
                sum = 0;
                for(int k = 1; k <= n; k++) {
                    s[k] += a[r][k];
                    sum += s[k];
                }//for

                cout << "sum: "<<sum<<endl;
                cout << "s\n";
                for(int l = 1; l <= n; l++)
                    cout <<s[l]<< " ";
                cout <<endl;



                //第一輪  0~n
                memset(f,0,sizeof(f));
                for(int k = 1; k <= n; k++) { //最大连续和
                    f[k] = max(f[k],f[k-1]+s[k]);
                    ans = max(f[k],ans);
                }

                cout << "f max\n";
                for(int l = 1; l <= n; l++)
                    cout <<f[l]<< " ";
                cout <<endl;

                cout << "ans:"<<ans<<endl;


                //最後一輪
                memset(f,0,sizeof(f));
                for(int k = 1; k <= n; k++) { //最小连续和
                    f[k] = min(f[k],f[k-1]+s[k]);
                    ans = max(ans,sum - f[k]);//逆著 用sum -f[k] 取最大
                }

                cout << "f min \n";
                for(int l = 1; l <= n; l++)
                    cout <<f[l]<< " ";
                cout <<endl;

                cout << "ans:"<<ans<<endl;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
