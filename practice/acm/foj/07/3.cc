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
using ipair = pair<int, int>;

int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m;

    while(m--) {
        int mp[5][5];
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cin >> mp[i][j];
            }
        }
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                int h = 1;
                if(mp[i][j]) {
                    mp[i][j] = h++;
                } else {
                    h = 1;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < 5; i++) {
            stack<ipair> s;
            for(int j = 0; j < 5; j++) {
                int l = 0;
                int tmp = 0;
                if(mp[i][j]) {
                    l++;
                    if(s.empty() || mp[i][j] >= mp[s.top().first][s.top().second]) {
                        s.emplace(i, j);
                    } else {
                        while(!s.empty() && mp[s.top().first][s.top().second] > mp[i][j]) {
                            int width = s.empty() ? l : ++tmp;
                            ans = max(mp[s.top().first][s.top().second] * width, ans);
                            s.pop();
                        }
                        tmp = 0;
                    }
                } else {
                    tmp = 0;
                    while(!s.empty()) {
                        ipair index = s.top();
                        s.pop();
                        ans = max(ans, mp[index.first][index.second] * ++tmp);
                        l = 0;
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
