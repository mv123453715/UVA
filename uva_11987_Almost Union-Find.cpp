
//使用Java的考生請注意，最外層的類別(class)需命名為 main 。
//如果遇到超乎想像的狀況，請更改編譯器試看看!! 各編譯器特性不同!!
//預設測資、隨機測資、固定測資是用來幫助除錯用的。批改時，只看暗中測資是否通過!!
#include <bits/stdc++.h>
using namespace std;

int main(){
  int i,j,k,n,m;
  while (cin >>n>>m){
    int num_set[n+1];
    for ( i = 1;i<n+1;i++ )
      num_set[i] = i;

    while ( m-- ){
      int cmd;
      int e1,e2;
      cin >>cmd;
      if( cmd == 1 ){
        cin>>e1>>e2;
        if ( num_set[e1] != num_set[e2] ){
          int temp = num_set[e2];
          for ( i = 1;i<n+1;i++ )
            if ( num_set[i] == temp )
              num_set[i] = num_set[e1];
        }//if

      }//if
      else if ( cmd ==2 ){
        cin>>e1>>e2;
          if ( num_set[e1] != num_set[e2] ){
            num_set[e1] = num_set[e2];
        }//if

      }//else if
      else if ( cmd ==3 ){
        cin >>e1;
        long long int res = 0,cnt = 0;
        for ( i = 1;i<n+1;i++ ){
          if ( num_set[i] == num_set[e1] ){
            res += i;
            cnt++;
          }//if
        }//for
        cout << cnt << " " <<res<<endl;
      }//else
    }//while
  }//while
  return 0;
}//main
