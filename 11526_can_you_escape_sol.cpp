#include <bits/stdc++.h>

using namespace std;
typedef struct BFS_state{
    int x, y, len;
};

int R, C, v[1001][1001], tag;
char map_all[1001][1001];
BFS_state not_out;
int step[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
BFS_state new_state(int x, int y, int len){ //  new_state
    BFS_state t;
    t.x = x;
    t.y = y;
    t.len = len;
    return t;
}

bool state_q(BFS_state a, BFS_state b){
    return (a.x == b.x && a.y == b.y);
}

bool in_bound(int x, int y, int V){ // 在邊界內
    return (x >=0 && x < C && y >= 0 && y < R && v[y][x] != V && map_all[y][x] != 'w');
}

BFS_state BFS(BFS_state s, BFS_state e,int V){
    queue<BFS_state> que; //  queue<int> q    q.push(10);     q.front()     q.back()    q.pop()刪前面     q.size()
    que.push(s);
    while(!que.empty()){
        BFS_state tmp = que.front();
        que.pop();
        if(v[tmp.y][tmp.x] == V)//相同就不做
            continue;
        v[tmp.y][tmp.x] = V;

        if(state_q(e, tmp)){//走到結束
            return tmp;
        }//if

        for(int i = 0; i < 4; i++){
            if(in_bound(tmp.x+step[i][1], tmp.y+step[i][0], V))
                que.push(new_state(tmp.x+step[i][1], tmp.y+step[i][0], tmp.len+1));
        }//for
    }//while
    return not_out;
}//BFS

int main(){
    char e;
    not_out = new_state(0,0,-1);
    tag = 1;
    memset(v, 0, sizeof(v));// 將v全部放0
    while(scanf("%d%d%c",&R, &C, &e) != EOF){
        BFS_state start, button, exit;
        for(int i = 0; i < R; i++){
            gets(map_all[i]);
            for(int j = 0; j < C; j++){
                if(map_all[i][j] == 's')
                    start = new_state(j, i, 0); // set start
                else if(map_all[i][j] == 'b')
                    button = new_state(j, i, 0); // set button
                else if(map_all[i][j] == 'e')
                    exit = new_state(j, i, 0);  // set end
            }//for
        }//for
        BFS_state ans1 = BFS(start, button, tag++);
        if(ans1.len < 0)
            printf("No solution.\n");
        else{
            BFS_state ans2 = BFS(ans1, exit, tag++);
            if(ans2.len < 0)
                printf("No solution.\n");
            else{
                printf("Escape in %d steps.\n",ans2.len);
            }//else
        }//else
    }//while
    return 0;
}
