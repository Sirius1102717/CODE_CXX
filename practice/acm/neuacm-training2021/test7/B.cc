#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;
int t, a, b, n, m, i, repeat;

int mp[105][105];

int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

map<char, int> w;

struct robot
{
    int x, y;
    int p;
}r[105];

void init()
{
    w['N'] = 0;
    w['E'] = 1;
    w['S'] = 2;
    w['W'] = 3;
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    char o;
    cin >> t;
    init();
    while ( t-- ) {
        memset(mp, 0, sizeof mp);
        int crash = 0, crashed = 0;
        cin >> a >> b;
        cin >> n >> m;
        for ( int j = 1; j <= n; j++ ) {
            cin >> r[j].x >> r[j].y >> o;
            r[j].p = w[o];
            mp[r[j].x][r[j].y] = j;
            // r[i].i = i;
        }
        while ( m-- ) {
            cin >> i >> o >> repeat;
            if ( !crash ) {
                while ( repeat-- ) {
                    if ( o == 'L' ) {
                        r[i].p += 3;
                        r[i].p %= 4;
                    } else if ( o == 'R' ) {
                        r[i].p += 1;
                        r[i].p %= 4;
                    } else {
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
                        // if ( r[i].x < 1 || r[i].x > a
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
        if ( crash && !crashed ) {
            printf("Robot %d crashes into the wall\n", crash);
        } else if ( crash && crashed ) {
            printf("Robot %d crashes into robot %d\n", crash, crashed);
        } else {
            printf("OK\n");
        }
    }
    return 0;
}
