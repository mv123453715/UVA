#include<bits/stdc++.h>
using namespace std;
const int  max_n = 2505;

int e,n,temp,T,p;
vector <int> G[max_n];///vector array
int day[max_n],step[max_n];
bool visted[max_n];

void BFS ( int p){
    int j,k;
    fill( visted,visted+max_n,false );
    fill( day,day+max_n,0 );
    fill( step,step+max_n,0 );

    deque <int> Q;
    Q.push_back( p );
    step[p]++;
    visted[p] = true;
    while ( !Q.empty() ){
        int vex = Q[0];
        Q.pop_front();
        for( int i : G[vex] ){
            if ( visted[ i ] == false ){
                visted[ i ] =true;
                step[i] = step[vex]+1;
                day[step[vex]]++;///  這個step的人數計算
                Q.push_back( i );
            }//if
        }//for
    }//while

    int max_size = 0,max_size_day = 0;
    for( int i = 0;i <e ;i++ ){
        if( max_size < day[i] ){
            max_size = day[i];
            max_size_day = i;///第幾天
        }//if
    }//for

    if ( max_size >0 )
        cout << max_size << " "<<max_size_day <<endl;
    else
        cout << "0\n";
}//BFS


int main(){
    int i,j,k;
    cin >>e;
    for ( i = 0;i<e;i++ ){
        cin >>n;
        while( n--){
            cin >>temp;
            G[i].push_back( temp );
        }//while
    }//for

    cin >> T;
    while ( T-- ){
        cin >> p;
        BFS(p);
    }//while

    return 0;
}//main

