#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

int mp[10][10];

bool in(int x, int y) {
    for(int i = 0; i < 8; i++) {
        if(mp[x][i]) return 0;
    }
    for(int i = 0; i < 8; i++) {
        if(mp[i][y]) return 0;
    }
    int i = x, j = y;
    while(i >= 0 && j >= 0) {
        if(mp[i][j]) return 0;
        i--, j--;
    }
    i = x, j = y;
    while(i >= 0 && j < 8) {
        if(mp[i][j]) return 0;
        i--, j++;
    }
    i = x, j = y;
    while(i < 8 && j < 8) {
        if(mp[i][j]) return 0;
        i++, j++;
    }
    i = x, j = y;
    while(i < 8 && j >= 0) {
        if(mp[i][j]) return 0;
        i++, j--;
    }
    return 1;
}

bool dfs(int cnt) {
    if(cnt == 8) {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                cout << (mp[i][j] ? 'Q' : '.');
            }
            cout << endl;
        }
        return 1;
    }
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(in(i, j)) {
                mp[i][j] = 1;
                if(dfs(cnt + 1))
                    return 1;
                else
                    mp[i][j] = 0;
            }
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, x, y;
    cin >> k;
    memset(mp, 0, sizeof mp);
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        mp[x][y] = 1;
    }
    dfs(k);

    return 0;
}
