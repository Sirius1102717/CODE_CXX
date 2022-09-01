#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

const int N = 100;

int mp[N][N];

int dis[N][N];

int n;

void floyd(int begin) {

    copy(mp, mp + N, dis);

    for (int k = 0 ; k < n; k++) {
        for (int i =0 ; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[i][k] = min(dis[i][j] = dis[j][k], dis[i][k]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
