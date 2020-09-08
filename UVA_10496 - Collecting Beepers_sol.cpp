#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define SC struct coord
/// fake bottom-up DP�A�P�˪��l���D�i��|��\�h�M�C
SC
{
    int x,y;
}xy[11];
int N;
int dp[1<<11][11];    /// lookup table for memoization
int adj[11][11];  /// adjacency matrix�C���I�����Z���C
int ans;        /// TSP������

void TSP(int s, int i, int s_size)///0 �� 0 �ثe�����
{

    if (s_size == N)///�������L�ᨫ�^���I
    {
        // �̫�A�[�W�@���^����I����A�Φ��������u�C
        if (dp[s][i] + adj[i][0] < ans)
            ans = dp[s][i] + adj[i][0];

        return;
    }

    for (int j=1; j<=N; ++j) /// �u����0�I�H�~���I
        if (!(s & (1 << j)))///�p�G�O0�N�]
        {
            // ss = s + {j};
            int ss = s | (1 << j);///s��C���I�i���
            if (!dp[ss][j] || dp[s][i] + adj[i][j] < dp[ss][j])/// !dp[ss][j]��0  �Ϊ̬O��p
            {
                dp[ss][j] = dp[s][i] + adj[i][j];
                TSP(ss, j, s_size + 1);///�b���U�� size+1
            }
        }
}

int main(void)
{


    int i,j,k;
    int T;
    int x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&x,&y);
        scanf("%d %d",&xy[0].x,&xy[0].y);
        scanf("%d",&N);
        for(i=1;i<=N;i++)
            scanf("%d %d",&xy[i].x,&xy[i].y);

       ///�p�⵴��t�Z �ۥ[
        for(i=0;i<N;i++)
            for(j=i+1;j<=N;j++)
            {
                adj[i][j] = abs(xy[i].x-xy[j].x)+abs(xy[i].y-xy[j].y);///�u�����a��  ���i�ר�
                adj[j][i] = adj[i][j]; ///�@��
            }
        memset(dp, 0, sizeof(dp));
        ans = 1e9;
        TSP(0, 0, 0);   // �O�ӤH�q��0�I�X�o�C
        printf("The shortest path has length %d\n",ans);
    }


    return 0;
}
