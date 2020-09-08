//使用Java的考生請注意，最外層的類別(class)需命名為 main 。
//如果遇到超乎想像的狀況，請更改編譯器試看看!! 各編譯器特性不同!!
//預設測資、隨機測資、固定測資是用來幫助除錯用的。批改時，只看暗中測資是否通過!!
#include <bits/stdc++.h>
using namespace std;

bool check_bingo( bool used[5][5]  ){
	int i,j,k;
	for ( i = 0;i<5;i++ ){
		bool bingo = true;
		for( j = 0;j<5;j++ ){
			if ( used[i][j] == false )
				bingo = false;
		}//for
		if ( bingo == true )
			return bingo;
	}//for

	for ( i = 0;i<5;i++ ){
		bool bingo = true;
		for( j = 0;j<5;j++ ){
			if ( used[j][i] == false )
				bingo = false;
		}//for
		if ( bingo == true )
			return bingo;
	}//for

	bool bingo = true;
	for ( i = 0;i<5;i++ ){
		if ( used[i][i] == false )
			bingo = false;
	}//for

	if ( bingo == true )
		return bingo;

	bingo = true;
	for ( i = 0;i<5;i++ ){
		if ( used[i][4-i] == false )
			bingo = false;
	}//for

	if ( bingo == true )
		return bingo;

	return false;
}//check_bingo
int main(){
	int i,j,k,t;
	cin >>t;
	while ( t-- ){
		int bingo[5][5];
		for( i = 0;i<5;i++ ){
			for( j = 0;j<5;j++ ){
				if(  i == 2 && j ==2 )
					bingo[i][j] = -1;
				else
					cin >>bingo[i][j];
			}//for

		}//for
		/*
		for( i = 0;i<5;i++ ){
			for( j = 0;j<5;j++ )
				cout << bingo[i][j]<<" ";
			cout<<endl;
		}//for
		*/

		bool used[5][5];
		for( i = 0;i<5;i++ )
			fill( used[i],used[i]+5,false );
		used[2][2] =true; //free space

		int num;
		bool isbingo = false;
		for ( k = 0;k<75 ;k++ ){
			cin >>num;
			//cout <<num<<endl;
			for( i = 0;i<5;i++ ){
				for( j = 0;j<5;j++ ){
					if( num == bingo[i][j] )
						used[i][j] =true;

					if ( check_bingo(used )==true &&isbingo ==false ){
						cout<< "BINGO after "<< k+1 <<" numbers announced"<<endl;
						isbingo = true;
					}//if
				}//for
			}//for
		}//for



	}//while

}//main()
