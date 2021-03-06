#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
double mtx[1505][10];
double o[1505][10];
#define eps 1e-3
int main() {
    //freopen("in.txt", "r+t", stdin);
    int testcase;
    scanf("%d", &testcase);
    int i, j, k;
    while(testcase--) {
        for(i = 1; i <= 1500; i++) {
            scanf("%lf", &mtx[i][8]);
            mtx[i][1] = 1;
            mtx[i][2] = pow(i, 1), mtx[i][3] = pow(i, 2);
            mtx[i][4] = pow(i, 3), mtx[i][5] = pow(i, 4);
            mtx[i][6] = pow(i, 5), mtx[i][7] = pow(i, 6);
        }
        memcpy(o, mtx, sizeof(o));//  memory copy
        for(i = 1; i <= 8; i++) {
            k = i;
            for(j = i+1; j <= 1500; j++)//找最大
                if(fabs(mtx[k][i]) < fabs(mtx[j][i]))  //  fabs  返回double絕對值
                    k = j;
            if(fabs(mtx[k][i]) < eps) //最大都過小  代表都是0
                continue;
            if(k != i) {  //當k不是i  代表不是前八列
                for(j = 1; j <= 7+1; j++)
                    swap(mtx[k][j], mtx[i][j]);
            }//if
            for(j = 1; j <= 1500; j++) {
                if(i == j)  continue;//同一行不用做
                for(k = 7+1; k >= i; k--)//mtx[i][i]  代表pivot
                    mtx[j][k] -= mtx[j][i]/mtx[i][i]*mtx[i][k];   // mtx[j][k] = mtx[j][k] - mtx[j][i]/mtx[i][i]*mtx[i][k];  數字=原始數字- 頭一個/pivot*該數字
            }//for
        }//for
        int nosol[10] = {};
        double sol[10] = {};
        for(i = 7; i >= 1; i--) {
            if(fabs(mtx[i][8]) > eps && fabs(mtx[i][i]) < eps)
                nosol[i] = 1; //無解
            else {
                if(fabs(mtx[i][7+1]) < eps)
                    sol[i] = 0; // 左邊均為0  解為0
                else
                    sol[i] = mtx[i][7+1]/mtx[i][i]; //求解
            }
            for(j = i+1; j <= 7; j++) {  //只看前七個
                if(fabs(mtx[i][j]) > eps && nosol[j])
                    nosol[i] = 1;
            }
        }
        int hasSol = 1;
        for(i = 1; i <= 7; i++) {
            hasSol &= !nosol[i];//  hasSol = hasSol & !nosol[i]  //  看每個都有解
            if(round(sol[i]) < 0 || round(sol[i]) > 1000)   //round 四捨五入  0<= a <= 1000
                hasSol = 0;
            sol[i] = round(sol[i]);
        }


        //驗算
        if(hasSol) {
            for(i = 1; i <= 1500 && hasSol; i++) {
                double sum = 0;
                for(j = 1; j <= 7; j++)
                    sum += sol[j] * pow(i, j-1); // sum = sum +sol[j] * pow(i, j-1);
                if(fabs(sum-o[i][8]) > eps) { //若數值高於原本 eps  則無解
                    hasSol = 0;
                }//if
            }//for
        }//for

        if(hasSol == 0) {
            puts("This is a smart sequence!"); // 無解
        } else {
            for(i = 1; i <= 7; i++) {
                if(i != 1)  putchar(' ');
                printf("%.0lf", sol[i]);//四捨五入
            }
            puts("");
        }
    }
    return 0;
}
