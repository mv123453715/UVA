#include <bits/stdc++.h>
using namespace std;

const int MAXN = 64;
int main() {
  int testcase;
  int N, M, P;
  int u, v, a, b;
  scanf("%d", &testcase);
  while (testcase--) {
    scanf("%d %d", &N, &M);

    int g[MAXN][MAXN], profit[MAXN] = {};
    int dp[1<<12][12];
    memset(g, 0x3f, sizeof(g));///設成無窮大
    for (int i = 0; i < M; i++) {
      scanf("%d %d %d.%d", &u, &v, &a, &b);
      g[u][v] = min(g[u][v], a * 100 + b);
      g[v][u] = min(g[v][u], a * 100 + b);
    }

    scanf("%d", &P);
    for (int i = 0; i < P; i++) {
      scanf("%d %d.%d", &u, &a, &b);
      profit[u] += a * 100 + b;
    }

    // floyd algorithm
    for (int i = 0; i <= N; i++)
      g[i][i] = 0;
    for (int k = 0; k <= N; k++)
      for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    // get store
    vector<int> S;
    for (int i = 0; i <= N; i++) {
      if (profit[i] > 0)
        S.push_back(i);
    }

    // run dp
    vector< pair<int, int> > o;
    for (int i = 0; i < (1<<S.size()); i++) {
      for (int j = 0; j < S.size(); j++)
        dp[i][j] = -0x3f3f3f3f;///負無窮大
      o.push_back(make_pair(__builtin_popcount(i), i));  ///make_pair 創造pair   __builtin_popcount 算有幾個1
    }

    int ret = -0x3f3f3f3f;
    for (int i = 0; i < S.size(); i++) {
      u = S[i];
      dp[1<<i][i] = -g[0][u] + profit[u];///收益-成本
    }

    sort(o.begin(), o.end());///預設  左邊先排序  升序
    for (int i = 0; i < o.size(); i++) {
      int state = o[i].second;///second代表第二個數字
      for (int j = 0; j < S.size(); j++) {
        if (dp[state][j] == -0x3f3f3f3f)///為負無窮大  跳過
          continue;

        u = S[j];
        ret = max(ret, dp[state][j] - g[u][0]);  ///嘗試返回原點  求最大profit
        for (int k = 0; k < S.size(); k++) { ///
          if ((state>>k)&1) ///右移一個  最右邊不是0continue
            continue;
          v = S[k];
          dp[state|(1<<k)][k] = max(dp[state|(1<<k)][k], dp[state][j] - g[u][v] + profit[v]); ///選擇第k個路徑去走  去比較扣掉成本+pro是否更賺
        }
      }
    }

    if (ret > 0)
      printf("Daniel can save $%d.%02d\n", ret/100, ret%100);
    else
      printf("Don't leave the house\n");
  }
  return 0;
}
