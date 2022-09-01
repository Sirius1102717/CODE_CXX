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

int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--) {
        int mp[5][5];
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cin >> mp[i][j];
            }
        }
        int h;
        for(int i = 0; i < 5; i++) {
            h = 1;
            for(int j = 0; j < 5; j++) {
                if(mp[i][j]) {
                    mp[i][j] = h++;
                } else {
                    mp[i][j] = 0;
                    h = 1;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(mp[i][j]) {
                    int width = mp[i][j];
                    int area = width;
                    for(int k = i - 1; k >= 0; k--) {
                        width = min(width, mp[k][j]);
                        area = max(area, (i - k + 1) * width);
                    }
                    ans = max(ans, area);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
