#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const double EPS = 1e-8;

// int dp[5001] = { 0 };



typedef struct
{
    int l;
    int w;
    bool flag;
}Stick;

Stick sticks[5001];

bool com(const Stick &p1, const Stick &p2)
{
    if ( p1.l != p2.l ) {
        return p1.l > p2.l;
    } else {
        return p1.w > p2.w;
    }
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while ( t-- ) {
        memset(sticks, 0, sizeof sticks);
        int n;
        cin >> n;
        for ( int i = 0; i < n; i++ ) {
            cin >> sticks[i].l >> sticks[i].w;
            sticks[i].flag = 0;
        }

        sort(sticks, sticks + n, com);

        int ans = 0;
        int w;
        for ( int i = 0; i < n; i++ ) {
            if ( sticks[i].flag ) {
                continue;
            }
            w = sticks[i].w;
            for ( int j = i + 1; j < n; j++ ) {
                if ( !sticks[j].flag && w >= sticks[j].w ) {
                    sticks[j].flag = 1;
                    w = sticks[j].w;
                }
            }
            ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}
