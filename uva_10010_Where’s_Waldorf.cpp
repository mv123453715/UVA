#include <bits/stdc++.h>
using namespace std;
char grid[100][100];

bool my_strcmp( int row,int col,string s ){
  int cnt = 1;
  while( cnt < s.length() && grid[row+cnt][col] == s[cnt] ) cnt++;
  if ( cnt == s.length() ) return true;
  cnt = 1;
  while( cnt < s.length() && grid[row-cnt][col] == s[cnt] ) cnt++;
  if ( cnt == s.length() ) return true;
  cnt = 1;
  while( cnt < s.length() && grid[row][col+cnt] == s[cnt] ) cnt++;
  if ( cnt == s.length() ) return true;
  cnt = 1;
  while( cnt < s.length() && grid[row][col-cnt] == s[cnt] ) cnt++;
  if ( cnt == s.length() ) return true;
  cnt = 1;
  while( cnt < s.length() && grid[row+cnt][col-cnt] == s[cnt] ) cnt++;
  if ( cnt == s.length() ) return true;
  cnt = 1;
  while( cnt < s.length() && grid[row+cnt][col+cnt] == s[cnt] ) cnt++;
  if ( cnt == s.length() ) return true;
  cnt = 1;
  while( cnt < s.length() && grid[row-cnt][col-cnt] == s[cnt] ) cnt++;
  if ( cnt == s.length() ) return true;
  cnt = 1;
  while( cnt < s.length() && grid[row-cnt][col+cnt] == s[cnt] ) cnt++;
  if ( cnt == s.length() ) return true;
  return false;
}//my_strcmp

int main(){
    int i,j,k,m,n,test_num;
    cin >> test_num;
    while( test_num-- ){
      cin >>m>>n;
      memset( grid,0,sizeof(grid) );
      
      for( i = 0;i<m;i++ ){
        for( j = 0;j<n;j++ ){
          cin >> grid[i][j];
          grid[i][j] = tolower(grid[i][j]);
        }//for
      }//for  
      
      int str_num;
      cin >> str_num;
      string str[str_num];
      for ( i = 0;i<str_num;i++ )
        cin >>str[i];
     for ( k = 0;k <str_num;k++ ){
       bool isfind = false;
       for ( i = 0;i<str[k].length();i++ )
         str[k][i] = tolower(str[k][i]  );
       
       for ( i = 0;i<m && !isfind;i++ ){
         for( j = 0;j<n && !isfind;j++ ){
           if( str[k][0] == grid[i][j] &&my_strcmp( i,j,str[k] )==true ){
             isfind = true;
             cout << i+1 << " "<<j+1<<endl;
           
           }//if
         }//for
       }//for
     
     
     }//for
      
      if ( test_num>=1 )
        cout <<endl;
    
    }//while
  return 0;
}//main