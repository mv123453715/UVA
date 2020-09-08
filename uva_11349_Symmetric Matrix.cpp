//使用Java的考生請注意，最外層的類別(class)需命名為 main 。
//如果遇到超乎想像的狀況，請更改編譯器試看看!! 各編譯器特性不同!!
//預設測資、隨機測資、固定測資是用來幫助除錯用的。批改時，只看暗中測資是否通過!!
#include <bits/stdc++.h>
using namespace std;
int main(){
  int i,j,k,n;
  cin >>n;
  int test_num = 0;
  while( n-- ){
    char c;
    cin >>c >>c;
    int m = 0;
    cin >>m;
    long long int arr[m][m];
    for( i = 0;i<m;i++ )
      for( j = 0;j<m;j++ )
        cin >>arr[i][j];
    bool sym = true;
    for( i = 0;(i<m) && sym;i++ )
      for( j = 0;(j<m) && sym;j++ )
        if ( arr[i][j] != arr[m-i-1][m-j-1] ||arr[i][j]<0  )
          sym =false;

    cout << "Test #" <<++test_num<<": ";
    if ( sym ==true || m == 0)
      cout << "Symmetric."<<endl;
    else
      cout << "Non-symmetric."<<endl;
  }//while

  return 0;
}//main()
