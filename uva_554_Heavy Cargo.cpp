#include <bits/stdc++.h>
using namespace std;
struct City{
  int to,load;
};

typedef vector<City>::iterator it;// vector iterator data type
vector <City>Link[201];
int MST( int st,int ed ){
  int used[201];
  int dis[201];
  fill( used,used+201,0 );
  fill( dis,dis+201,0 );
  dis[st] = 0xfffffff;//not 1<<31  it is minus
  deque<int> Q;
  for( it i = Link[st].begin(); i != Link[st].end();i++   ){//用it i 代替Link[st][i] 
    if ( dis[i->to] < min( dis[st],i->load ) ){//st到周遭的點和load取min
      dis[i->to] = min( dis[st],i->load );//update
      if ( used[i->to] == 0 ){// if not used push to Q
        used[i->to] = 1 ;
        Q.push_back( i->to );
      }//if
    }//if
  }//for
  while( !Q.empty() ){
    int vex = Q.front();//前端拿出第一個vex
    Q.pop_front();
    //cout<< "Q start\n";
    used[vex] = 0;//可允許倒退走  ex:第三輪的點可以走回第二輪的點  重點是要求path 中最小wei的盡量大  
    for( it i = Link[vex].begin(); i != Link[vex].end();i++   ){
      if ( dis[i->to] < min( dis[vex],i->load ) ){//vex到周遭的點和load取min
        dis[i->to] = min( dis[vex],i->load );//update
        if ( used[i->to] == 0 ){// if not used push to Q
          used[i->to] = 1 ;
          Q.push_back( i->to );
        }//if
      }//if
    }//for
  }//while
  return dis[ed];
}//MST


int main() {
  int i,j,k,n,r;
  int test_num = 1;
  while( cin >>n >>r ){
    if( n==0&&r==0 )
      break;
    map <string,int> graph;
    string x,y;
    int load,encode = 0;
    for( i =0;i<201;i++ )
      Link[i].clear();  
    while( r-- ){
      cin >> x>>y>>load;
      if ( graph[x] == 0){
        encode++;
        graph[x] = encode;
      }//if
      if (  graph[y] == 0 ){
        encode++;
        graph[y] = encode;
      }//if  
      int nx = graph[x],ny = graph[y];
      City temp;
      temp.to = ny,temp.load = load;
      //cout <<"load:"<<load<<endl;
      Link[nx].push_back( temp );
      temp.to = nx,temp.load = load;
      Link[ny].push_back( temp );
    }//while
    cin >>x>>y;
    cout << "Scenario #"<<test_num<<endl;
    test_num++;
    cout << MST( graph[x],graph[y] ) <<" tons"<<endl<<endl;
  
  }//while
    return 0;
}
