#include<bits/stdc++.h>
using namespace std;

int data[2002];
int bg[2002];
int en[2002];

int main()
{
	int t, n;
	while (~scanf("%d",&t)) {
		while (t --) {
			scanf("%d",&n);
			for (int i = 1; i <= n; ++ i) {
				scanf("%d",&data[i]);
			}
			int ans = 0;
			for (int i = n; i >= 1; -- i) {///從後往前
				bg[i] = 1;///每個設為1
				en[i] = 1;///每個設為1
				for (int j = n; j > i; -- j) {///從後往前
					if (data[i] < data[j] && bg[i] <= bg[j]) {///比較小 且bg j 比較小  加入前面
						bg[i] = bg[j]+1; ///加1
					}
					if (data[i] > data[j] && en[i] <= en[j]) {///比較小 且bg j 比較小  加入後面
						en[i] = en[j]+1;
					}
				}
				if (ans < bg[i]+en[i]-1) {/// 找到ans  -1  代表自己重複一次
					ans = bg[i]+en[i]-1;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
