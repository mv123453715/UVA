
#include <bits/stdc++.h>
using namespace std;

int pos[100005][26];
int main(){
  int i,j,k,t_num;
  cin >> t_num;
  while(t_num-- ){
    string s ;
    cin >>s;
    long long int cnt = 0;
    fill( pos[s.length()],pos[s.length()]+26,s.length() );//初始化為n  代表這個字母不存在
    
	//利用倒著建字母表過濾掉重複的情況
    for( i =s.length()-1 ;i>=0;i-- ){  //從最後面開始擺上可選擇的字母位置
      memcpy( pos[i],pos[i+1],sizeof( pos[0] ) );   //前一個人複製後一個人
      pos[i][ s[i]-'A' ] = i;//新增自己的字母位置 給前一個人複製  而且可以做出更新  有2個A  則可以選擇前面一點的A
    }//for
    
    for( i = 0;i<26;i++ ){
      if ( pos[0][i] == s.length() ) //若不可選擇的為n 則不選
        continue;
      int x = pos[0][i];//拿出最近的pos
      for ( j = 0; j <26;j++ ){
        if ( pos[x+1][j] == s.length() )//為n跳過
          continue;
        int y = pos[x+1][j];//拿出可選最近的pos
        for( k = 0; k<26;k++  ){
          if ( pos[y+1][k] == s.length() )
            continue;
          cnt++;//有找到++  
        }//for
      }//for
    }//for
    cout <<cnt<<endl;
  }//while
  return 0;
}//main()

