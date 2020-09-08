#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

long long f[55][55][55];
//f(i. j, k) = sum( f(i-p, j-1,  k)  p = 1..k )

int main()
{
	///reset 0
	memset( f,0,sizeof(f) );
	/*
	for (int i = 0; i < 51; ++ i)
        for (int j = 0; j < 51; ++ j)
            for (int k = 0; k < 51; ++ k)
                f[i][j][k] = 0LL;
    */

	for (int i = 0; i < 51; ++ i)
		f[0][0][i] = 1LL;///0個bar  0個分割 最大i單位 為1

    for (int i = 1; i < 51; ++ i)
        for (int j = 1; j < 51; ++ j)///
            for (int k = 1; k < 51; ++ k)///
                for (int p = 1; p <= k && p <= i; ++ p)/// p <= i 怕overflow   i-p,j-1,k  p 1~k
                    f[i][j][k] += f[i-p][j-1][k];

	int n,k,m;
	while (cin >> n >> k >> m)

		cout << f[n][k][m] << endl;

    return 0;
}
