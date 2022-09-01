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

int mp[505][505];

int main(int argc, char* argv[]) {
    int n, w, h, s, t, x, y;
    while(cin >> n, n) {
        cin >> w >> h;
        memset(mp, 0, sizeof mp);
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            mp[y][x] = 1;
        }
        cin >> s >> t;
        int ans = 0;

        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                int it = i + t, js = j + s;
                if(it <= h + 1 && js <= w + 1) {
                    int tmp = 0;
                    for(int k = i; k < it; k++) {
                        for(int l = j; l < js; l++) {
                            if(mp[k][l]) {
                                tmp++;
                            }
                        }
                    }
                    ans = max(ans, tmp);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
