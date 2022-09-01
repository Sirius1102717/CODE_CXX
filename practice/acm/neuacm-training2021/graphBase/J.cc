#include <iostream>
#include<string>
using namespace std;
const int N = 105;

bool mp[N][N] = { 0 };
int n, m, u, v;
void Floyd()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (mp[j][i] && mp[i][k]) {
                    mp[j][k] = 1;
                }
            }
        }
    }
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        mp[u][v] = 1;
    }

    Floyd();
    for (int i = 1; i <= n; i++) {
        int cnt = 1;
        for (int j = 1; j <= n; j++) {
            if (mp[i][j] || mp[j][i]) {
                cnt++;
            }
        }
        if (cnt == n) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
