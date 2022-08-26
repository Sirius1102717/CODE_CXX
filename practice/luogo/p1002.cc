#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;

template <class T>
size_t getHash(T s)
{
    return hash<T>{}(s);
}

using ipair = pair<int, int>;

int dp[23][23] = { 0 };
bool mmap[23][23] = { 0 };
const int hx[] = { 0, 1, -1, -1, 1, 2, -2, -2, 2 };
const int hy[] = { 0, 2, -2, 2, -2, 1, -1, 1, -1 };


void tempInit(int first, int second)
{
    mmap[first][second] = 1;
}

void init(ipair horse)
{
    for ( int i = 0; i < 9; i++ ) {
        mmap[horse.first + hx[i]][horse.second + hy[i]] = 1;
    }

    dp[2][1] = 1;
    // dp[1][2] = 1;

}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    ipair b, horse;
    cin >> b.first >> b.second >> horse.first >> horse.second;
    b.first += 2;
    b.second += 2;
    horse.first += 2;
    horse.second += 2;
    init(horse);
    for ( int i = 2; i <= b.first; i++ ) {
        // for ( int i1 = 0; i1 <= i; i1++ ) {
        for ( int j = 2; j <= b.second; j++ ) {
            // for ( int j1 = 0; j1 <= j; j1++ ) {
            if ( mmap[i][j] ) {
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }

    }

    cout << dp[b.first][b.second];
    return 0;
}
