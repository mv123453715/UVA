#include <bits/stdc++.h>
#define maxn 2505
using namespace std;
int step[maxn], day[maxn], T, vis[maxn];
vector<int> G[maxn];///�w�qvector array
void bfs( int q ){
	queue<int> Q;
	Q.push(q);
	step[q] = 1;
	vis[q] = T;///�ĴX��case
	while ( !Q.empty() ){
		int cur = Q.front();
		Q.pop();
		for ( int i : G[cur] ){///���XG[cur]�����C��i
			if ( vis[i] != T ){
				vis[i] = T;///�ݹL
				step[i] = step[cur]+1;///�������X�ӤW�@��+1
				day[step[cur]]++;///��Ѫ��H��++
				Q.push(i);///��JQ
			}
		}
	}
	int maxday, max = 0;
	for ( int i=1; day[i]; i++ )
		if ( day[i] > max ){
			max = day[i];///�̤j
			maxday = i;///��i��
		}
	if ( max ) cout <<max <<' ' <<maxday <<'\n';
	else cout <<0 <<'\n';
	memset(day, 0, sizeof(day));///�令0
}
int main(){

	///�ƾڤj�~��
	///ios::sync_with_stdio( false );///�Ѱ�cin��cout�Pprintf�Mscanf���ݮe
	///cin.tie(0);///�Ѱ�cin��cout�j�w  �[�tcin cout
	int E, n, u, t, q;
	cin >>E;
	for ( int i=0; i<E; i++ ){
		cin >>n;
		while ( n-- ){
			cin >>u;
			G[i].emplace_back(u);///emplace_back���Npush_back�󦳮Ĳv
		}
	}
	cin >>t;
	while ( t-- ){
		T++;
		cin >>q;
		bfs(q);
	}
	return 0;
}
