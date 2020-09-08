#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct Num {
    int  n,r; //n代表數字  r 代表取mod
    bool odd; //是否為奇數
};

bool comp(const Num& a, const Num& b) { //用&  true代表a<b false 代表a>b
    bool flag = false;
    if(a.r < b.r) flag = true; //a<b true
    else if(a.r == b.r) { // ==
        if (a.odd && !b.odd) flag = true; // a is odd b is even return true a<b true
        else if (!a.odd && b.odd) flag = false; // a>b return false
        else if (a.odd && b.odd) flag = (a.n > b.n); //return a > b 做到逆序
        else flag = (a.n < b.n); //return a <b 做到順序
    }
    return flag;
}

int main() {
    int n,m,t;
    Num a[10000];
    while (cin >> n >> m && !(n == 0 && m == 0)) {
        cout << n << " " << m << endl;
        for (int i = 0; i < n; i++) { //邊讀邊處理基本資料
            cin >> t;
            a[i].n = t;
            a[i].r = t%m;
            if(t%2 != 0) a[i].odd = true;
            else a[i].odd = false;
        }
        sort(a, a + n,comp); // sort( array,index,comp )
        for (int i = 0; i < n; i++)

            cout << a[i].n << endl;
    }
    cout << "0 0" << endl;
    return 0;
}
