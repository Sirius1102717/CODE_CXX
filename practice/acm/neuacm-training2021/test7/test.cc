#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;
//E 0 N 1 W 2 S 3
int dir[4][2] = { 0,1,1,0,0,-1,-1,0 };
int mp[103][105];
map<char, int>w;
void init()
{
    // w['E'] = 0;
    // w['N'] = 1;
    // w['W'] = 2;
    // w['S'] = 3;
    w['N'] = 0;
    w['E'] = 1;
    w['S'] = 2;
    w['W'] = 3;
}
struct robot
{
    int x, y;
    int p;
}r[105];
int main()
{
    int t, n, m, a, b;
    cin >> t;
    init();
    while ( t-- ) {
        cin >> a >> b;
        cin >> n >> m;
        char o;
        memset(mp, 0, sizeof(mp));
        for ( int j = 1; j <= n; j++ ) {
            cin >> r[j].x >> r[j].y >> o;
            r[j].p = w[o];
            mp[r[j].x][r[j].y] = j;
        }
        int crash = 0, crashed = 0;
        int i, repeat;
        while ( m-- ) {
            cin >> i >> o >> repeat;
            if ( !crash ) {
                while ( repeat-- ) {
                    if ( o == 'L' )r[i].p = (r[i].p + 3) % 4;
                    if ( o == 'R' )r[i].p = (r[i].p + 1) % 4;
                    if ( o == 'F' ) {
                        int xi = r[i].x + dir[r[i].p][0];
                        int yi = r[i].y + dir[r[i].p][1];
                        if ( xi < 1 || xi > a || yi < 1 || yi > b ) {
                            crash = i;
                        } else if ( mp[xi][yi] ) {
                            crash = i;
                            crashed = mp[xi][yi];
                        } else {
                            mp[r[i].x][r[i].y] = 0;
                            r[i].x = xi;
                            r[i].y = yi;
                            mp[xi][yi] = i;
                        }
                        // mp[r[i].x][r[i].y] = 0;
                        // r[i].x += dir[r[i].p][0];
                        // r[i].y += dir[r[i].p][1];
                        // if ( r[i].x < 1 || r[i].x > i
                        //     || r[i].y < 1 || r[i].y > b ) {
                        //     crash = i;
                        // } else if ( mp[r[i].x][r[i].y] ) {
                        //     crash = i;
                        //     crashed = mp[r[i].x][r[i].y];
                        // } else {
                        //     mp[r[i].x][r[i].y] = i;
                        // }

                    }
                }
            }
        }
        //for(int i=1;i<=n;i++)
           // cout<<r[i].x<<' '<<r[i].y<<' '<<r[i].p<<endl;
        if ( crash && !crashed ) {
            cout << "Robot " << crash << " crashes into the wall" << endl;
        } else if ( crash && crashed ) {
            cout << "Robot " << crash << " crashes into robot " << crashed << endl;
        } else cout << "OK" << endl;
    }
    return 0;
}
