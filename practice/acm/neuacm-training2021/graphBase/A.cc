#include<iostream>
#include <cstring>
#include<string>
using namespace std;
const double EPS = 1e-8;

char mp[8][8];
bool visit[8];

int n, k, used, tot;
void dfs(int cur)
{
    if (k == used) {
        tot++;
        return;
    }
    if (cur >= n) {
        return;
    }
    for (int j = 0; j < n; j++) {
        if (used + n - cur < k) {
            break;
        }
        if (!visit[j] && mp[cur][j] == '#') {
            visit[j] = 1;
            used++;
            dfs(cur + 1);
            visit[j] = 0;
            used--;
        }
    }
    dfs(cur + 1);
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n, n != -1) {
        cin >> k;
        used = tot = 0;
        memset(visit, 0, sizeof visit);
        for (int i = 0; i < n; i++) {
            cin >> mp[i];
        }
        dfs(0);
        cout << tot << "\n";
    }
    return 0;
}
