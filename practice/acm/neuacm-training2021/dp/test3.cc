#include<iostream>/* dp[i]表示石头能否达到第i高度，能到达为1，不能达到则为0*/
#include<cstring>
#include<algorithm>
using namespace std;
int dp[60000], k[60000];
struct thing
{
    int h;//石块的初始高度;
    int maxh;//石块所能达到的最大高度;
    int num;//石块的数目;
};
struct thing q[60000];
bool add(thing a, thing b)
{
    return a.maxh < b.maxh;
}
int main()
{
    int n;
    cin >> n;
    for ( int i = 1; i <= n; i++ )     {
        cin >> q[i].h >> q[i].maxh >> q[i].num;
    }
    memset(dp, 0, sizeof(dp));
    sort(q + 1, q + n + 1, add);//先将石块按照能够达到的最大高度进行排序，从小到大;
    dp[0] = 1;
    int ans = 0;
    for ( int i = 1; i <= n; i++ )     {
        memset(k, 0, sizeof(k));
        for ( int j = q[i].h; j <= q[i].maxh; j++ )//按照第i种石头的初始高度-->第i种石头的最大高度;
        {
            if ( dp[j] == 0 && dp[j - q[i].h] == 1 && q[i].num > k[j - q[i].h] )//如果j不能到达同时j减去第i种石头的初始高度能够达到，而且第i种石头的数量足够;
            {
                dp[j] = 1;//能够达到，赋值为1;
                k[j] = k[j - q[i].h] + 1;//计数，记录第i种石头的个数;
                if ( ans < j )
                    ans = j;
            }
        }
    }
    cout << ans << endl;
    return 0;
}