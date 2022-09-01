#include<iostream>
#include<algorithm>
using namespace std;

int dp[40001] = { 0 };

typedef struct
{
    int h;
    int a;
    int c;
}Stone;

Stone stones[401];


bool com(Stone &s1, Stone &s2)
{
    return s1.a < s2.a;
};


void zeroOnePack(int v, int w, int lim)
{
    for ( int i = lim; i >= w; i-- ) {
        dp[i] = max(dp[i], dp[i - w] + v);
    }
}

void comPack(int v, int w, int lim)
{
    for ( int i = w; i <= lim; i++ ) {
        dp[i] = max(dp[i], dp[i - w] + v);
    }
}

void mulPack(int v, int w, int lim, int n)
{
    if ( w * n >= lim ) {
        comPack(v, w, lim);
    } else {
        int k = 1;
        while ( k < n ) {
            zeroOnePack(k * w, k * v, lim);
            n -= k;
            k <<= 1;
        }
        zeroOnePack(n * w, n * v, lim);
    }
}



int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int k;


    cin >> k;
    for ( int i = 0; i < k; i++ ) {
        cin >> stones[i].h >> stones[i].a >> stones[i].c;
    }

    sort(stones, stones + k, com);
    for ( int i = 0; i < k; i++ ) {
        mulPack(stones[i].h, stones[i].h, stones[i].a, stones[i].c);
    }
    int ans = 0;
    for ( int i = 0; i < 40001; i++ ) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}