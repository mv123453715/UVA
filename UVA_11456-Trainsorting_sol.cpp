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
			for (int i = n; i >= 1; -- i) {///�q�᩹�e
				bg[i] = 1;///�C�ӳ]��1
				en[i] = 1;///�C�ӳ]��1
				for (int j = n; j > i; -- j) {///�q�᩹�e
					if (data[i] < data[j] && bg[i] <= bg[j]) {///����p �Bbg j ����p  �[�J�e��
						bg[i] = bg[j]+1; ///�[1
					}
					if (data[i] > data[j] && en[i] <= en[j]) {///����p �Bbg j ����p  �[�J�᭱
						en[i] = en[j]+1;
					}
				}
				if (ans < bg[i]+en[i]-1) {/// ���ans  -1  �N��ۤv���Ƥ@��
					ans = bg[i]+en[i]-1;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
