#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int s[1005] = { 0 };
int dp[1005][35] = { 0 };

int main()
{
    //freopen("in.in","r",stdin);
    int t, w;
    while ( scanf("%d%d", &t, &w) != EOF ) {
        memset(dp, 0, sizeof(dp));
        memset(s, 0, sizeof(s));
        for ( int i = 1; i <= t; i++ )
            scanf("%d", &s[i]);

        if ( s[1] == 1 )dp[1][0] = 1;//对i=1的情况初始化
        else dp[1][1] = 1;

        for ( int i = 2; i <= t; i++ )
            dp[i][0] = dp[i - 1][0] + s[i] % 2;//对j=0的情况初始化

        for ( int i = 2; i <= t; i++ )
            for ( int j = 1; j <= w; j++ ) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);//状态转移
                if ( (s[i] + 1) % 2 == j % 2 )dp[i][j]++;//如果此时恰好在果树下，还可再吃一个苹果
            }
        int max_n = 0;
        for ( int i = 1; i <= t; i++ )
            if ( dp[i][w] > max_n )max_n = dp[i][w];
        printf("%d\n", max_n);
    }
    return 0;
}