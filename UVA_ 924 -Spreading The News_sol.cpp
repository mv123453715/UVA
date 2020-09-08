#include <bits/stdc++.h>
#define maxn 2505
using namespace std;
int step[maxn], day[maxn], T, vis[maxn];
vector<int> G[maxn];///定義vector array
void bfs( int q ){
	queue<int> Q;
	Q.push(q);
	step[q] = 1;
	vis[q] = T;///第幾個case
	while ( !Q.empty() ){
		int cur = Q.front();
		Q.pop();
		for ( int i : G[cur] ){///拿出G[cur]中的每個i
			if ( vis[i] != T ){
				vis[i] = T;///看過
				step[i] = step[cur]+1;///全部拿出來上一輪+1
				day[step[cur]]++;///當天的人數++
				Q.push(i);///放入Q
			}
		}
	}
	int maxday, max = 0;
	for ( int i=1; day[i]; i++ )
		if ( day[i] > max ){
			max = day[i];///最大
			maxday = i;///第i天
		}
	if ( max ) cout <<max <<' ' <<maxday <<'\n';
	else cout <<0 <<'\n';
	memset(day, 0, sizeof(day));///改成0
}
int main(){

	///數據大才用
	///ios::sync_with_stdio( false );///解除cin跟cout與printf和scanf的兼容
	///cin.tie(0);///解除cin跟cout綁定  加速cin cout
	int E, n, u, t, q;
	cin >>E;
	for ( int i=0; i<E; i++ ){
		cin >>n;
		while ( n-- ){
			cin >>u;
			G[i].emplace_back(u);///emplace_back取代push_back更有效率
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
