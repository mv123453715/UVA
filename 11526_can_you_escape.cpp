#include <bits/stdc++.h>
using namespace std;

int step = 0;
bool visted[1000][1000];
bool DFS ( vector <vector<char>> map_all,int start_pos[2],int end_pos[2],int row,int col ){

    if ( (start_pos[0] == end_pos[0]) && (start_pos[1] == end_pos[1]) )
        return true;

    //up
    if ( (start_pos[0]-1 >=0 ) && map_all[start_pos[0]-1][start_pos[1]] != 'w' ){
        start_pos[0]--;
        step++;
        return true;
    }//if

    //down
    if ( (start_pos[0]+1 <row ) && map_all[start_pos[0]+1][start_pos[1]] != 'w' ){
        start_pos[0]++;
        step++;
        return true;
    }//if
    //left
    if ( (start_pos[1]-1 >=0 ) && map_all[start_pos[0]][start_pos[1]-1] != 'w' ){
        start_pos[1]--;
        step++;
        return true;
    }//if
    //right
    if ( (start_pos[1]+1 <col ) && map_all[start_pos[0]][start_pos[1]+1] != 'w' ){
        start_pos[1]++;
        step++;
        return true;
    }//if



    return false;
}//DFS

int main() {
    int row,col,u,j,k;
    int start[2],button[2];
    char c;
    vector <vector<char>> map_all;
    vector <char> temp;
    cin >> row >> col;
    for ( i =0;i <row ;i++ ){
        temp.clear();
        for ( j =0;j <col;j++ ){
            cin >> c;
            temp.push_back(c);
            if ( c == 's' )
                start = {i,j};
            else if ( c == 'b' )
                start = {i,j};
        }//for
        map_all.push_back(temp);
    }//for

    for ( i =0;i <row ;i++ )
            fill( visted[i][0],visted[i][0]+col,false );


    return 0;
}//main
