#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int st,ed,wei;
} ;

bool compare( const Edge &a, Edge b ){
    return a.wei < b.wei;
}//compare

int findRoot( vector <int >& group,int x ){///要用&  否則鐵定timeout
    if ( group[x] == x )
        return x;
    else{
        group[x] = findRoot( group,group[x] );
        return group[x];
    }//else
}//findRoot




int main(){
    int i,j,k,m,n;
    while( cin>>m>>n && m!=0 && n!=0 ){

        vector <int > group(m);
        for( i = 0;i<m;i++ )
            group[i] = i;

        vector< Edge > edge(n);
        for( i = 0;i<n;i++ )
            cin >> edge[i].st >> edge[i].ed >> edge[i].wei ;


        ///sort cost 升序
        sort( edge.begin(),edge.end(),compare );

        int total_save = 0;


        cout << "i st ed cost group\n";
        for( j = 0;j<n;j++ )
            cout << j<<" "<<edge[j].st << " " << edge[j].ed << " " << edge[j].wei<<endl;
        cout << "vex\n";
        for( j = 0;j<m;j++ )
            cout << j<<" "<<group[j]<<endl;

        for( i = 0;i<n;i++ ){



            int temp1 = findRoot( group,edge[i].st );///起點跟終點是同一個group  代表可以省下這個edge
            int temp2 = findRoot( group,edge[i].ed );
            if ( temp1 == temp2  ){ ///防止迴圈
                total_save += edge[i].wei;
                cout << "iterator "<<i<<endl;
                cout << "vex\n";
                for( j = 0;j<m;j++ )
                    cout << j<<" "<<group[j]<<endl;

                cout << "total_save: "<<total_save<<endl;
                continue;
            }//if

            group[ temp1  ] = temp2;///否則把起點變成終點的group
            cout << "iterator "<<i<<endl;
            //cout << "edge\n";
           // for( j = 0;j<n;j++ )
           //     cout << j<<" "<<edge[j].st << " " << edge[j].ed << " " << edge[j].wei<<endl;
            cout << "vex\n";
            for( j = 0;j<m;j++ )
                cout << j<<" "<<group[j]<<endl;

            cout << "total_save: "<<total_save<<endl;

        }//for

        cout << total_save<<endl;
        //printf( "%d\n",total_save );



    }//while
    return 0;
}//main

