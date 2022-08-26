#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ipair = pair<int, int>;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
double cal(int x1, int x2, int y1, int y2)
{
    return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}

double dp[20];
bool vis[400][400];

void bfs()
{
    queue<ipair> q;
    q.emplace(0, 0);
    vis[200][200] = 1;
    d
}
int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
