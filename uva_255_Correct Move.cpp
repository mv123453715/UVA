//使用Java的考生請注意，最外層的類別(class)需命名為 main 。
//如果遇到超乎想像的狀況，請更改編譯器試看看!! 各編譯器特性不同!!
//預設測資、隨機測資、固定測資是用來幫助除錯用的。批改時，只看暗中測資是否通過!!
#include <bits/stdc++.h>
using namespace std;


int main(){
	int i,j,k,q,next_q;
	while( cin>>k>>q>>next_q ){
        int k_x = k/8,k_y = k%8;
        int q_x = q/8,q_y = q%8;
        int nq_x = next_q/8,nq_y = next_q%8;
        if ( k==q )
            cout << "Illegal state\n";
        else if( (q_x!=nq_x && q_y!=nq_y)
                || (nq_x==k_x && nq_y==k_y)
                || ( nq_y == q_y && q_x >=k_x && nq_x <=k_x )
                || ( nq_y == q_y && q_x <=k_x && nq_x >=k_x )
                || ( nq_x == q_x && q_y <=k_y && q_y >=k_y )
                || ( nq_x == q_x && q_y <=k_y && q_y >=k_y )
                ){
            cout << "Illegal move\n";
        }//else if
        else if ( ( nq_x+1 == k_x &&nq_y ==k_y )
                || ( nq_x-1 == k_x &&nq_y ==k_y )
                ||( nq_x+1 == k_x &&nq_y+1 ==k_y )
                ||( nq_x+1 == k_x &&nq_y-1 ==k_y )
                ||( nq_x-1 == k_x &&nq_y+1 ==k_y )
                ||( nq_x-1 == k_x &&nq_y-1 ==k_y ))
            cout << "Move not allowed\n";
        else if ( (next_q == 49 && k==56)
                 ||(next_q == 54 && k==63)
                 ||(next_q == 9 && k==0)
                 ||(next_q == 14 && k==7))
                cout << "Stop\n";

        else
            cout << "Continue\n";

	}//while
	return 0;
}//main()
