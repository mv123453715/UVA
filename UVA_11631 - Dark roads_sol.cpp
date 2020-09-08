#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
  int start;
  int end;
  int cost;
};

bool edgeCompare(const Edge& a, const Edge& b){
  return a.cost < b.cost;
}

int findRoot(vector<int>& group, int x){
  if(x == group[x])
    return x;///�۵�����return
  return group[x] = findRoot(group, group[x]);///�~���
}

int main(){
  int m, n;
  while(scanf("%d%d", &m, &n) != EOF && m != 0 && n != 0){
    vector<int> group(m);
    for(int i = 0 ; i < m ; ++i){///group is i
      group[i] = i;
    }

    vector<Edge> edges(n);
    for(int i = 0 ; i < n ; ++i){
      scanf("%d%d%d", &(edges[i].start), &(edges[i].end), &(edges[i].cost));
    }

    sort(edges.begin(), edges.end(), edgeCompare);///�ɧ�
    int totalSave = 0;
    for(int i = 0 ; i < n ; ++i ){
      if(findRoot(group, edges[i].start) == findRoot(group, edges[i].end)){///�۵��N���OMST���|  �G�ۥ[
        //cout << "edges[i].cost: "<<edges[i].cost;
        totalSave += edges[i].cost;
        continue;
      }//if

      group[findRoot(group, edges[i].start)] = findRoot(group, edges[i].end);///�Nend��s��start
    }//for


    printf("%d\n", totalSave);

    //for(int i = 0 ; i < m ; ++i)///group is i
      //cout << group[i]<<" ";

  }
  return 0;
}
