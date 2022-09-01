#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

bool mp[6][6] = { 0 };
int step;
bool flag = 0;
int dir[5][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1}, {0, 0} };
void f(int r, int c)
{
    for ( int i = 0; i < 5; i++ ) {
        mp[r + dir[i][0]][c + dir[i][1]] = !mp[r + dir[i][0]][c + dir[i][1]];
    }
}

bool check()
{
    bool res = mp[1][1];
    for ( int i = 1; i <= 4; i++ ) {
        for ( int j = 1; j <= 4; j++ ) {
            if ( res != mp[i][j] ) {
                return 0;
            }
        }
    }
    return 1;
}

void dfs(int r, int c, int deep)
{
    if ( step == deep ) {
        flag = check();
        return;
    }
    if ( flag || r == 5 ) {
        return;
    }
    f(r, c);
    if ( c < 4 ) {
        dfs(r, c + 1, deep + 1);
    } else {
        dfs(r + 1, 1, deep + 1);
    }
    f(r, c);
    if ( c < 4 ) {
        dfs(r, c + 1, deep);
    } else {
        dfs(r + 1, 1, deep);
    }
}

int main(int argc, char *argv[])
{
    char ch;

    for ( int i = 1; i <= 4; i++ ) {
        for ( int j = 1; j <= 4; j++ ) {
            cin >> ch;
            if ( ch == 'b' ) {
                mp[i][j] = 1;
            }
        }
    }
    for ( step = 0; step <= 16; step++ ) {
        dfs(1, 1, 0);
        if ( flag ) {
            break;
        }

    }
    if ( flag ) {
        cout << step << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}
