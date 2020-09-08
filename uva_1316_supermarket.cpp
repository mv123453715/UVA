#include <bits/stdc++.h>
using namespace std;

int n;
int f[10200];
struct note{
    int p,d;
} ;
note q[10100];
int cmp(note a,note b){
    return a.p>b.p;
}//cmp
// tree

int getf(int v)
{
    if(f[v]==-1)
        return v;  //如果当天没被占，就放在当天卖
    else{//如果当天被占，就往前找（祖宗）
        f[v]=getf(f[v]); //union
        return f[v];
    }//else
}
int main()
{
    while(  cin >>n ){
        memset(f,-1,sizeof(f)); //f[i]不能·等于·i;天数是不连贯的，和商品标号也没有也无关系。
        int maxn=-1;
        for(int i=1; i<=n; i++)
            cin >> q[i].p>>q[i].d;

        sort(q+1,q+n+1,cmp);//最大的先
        int sum=0;
        for(int i=1; i<=n; i++){
            int t=getf(q[i].d);//返回第几天卖
            if(t>0) {          //天数为<=0?不存在的，如果如此，这件商品，只能丢弃了。
                sum+=q[i].p;    //加入最大值
                f[t]=t-1;   //t天被占用后，它的祖宗应该指向前一天。 為了讓撞到後可以往錢找
            }//if
        }//for
        cout <<sum <<endl;
    }
    return 0;
}
