#include <algorithm>
#include <cstdio>
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
const int N = 1e6 + 5;
bool vis[N];
int n, a, b;
void dfs(int i)
{
    if (i > n) {
        // printf("%d\n", n - con);
        return;
    }
    if (!vis[i + a]) {
        dfs(i + a);
    }
    vis[i + a] = 1;
    if (!vis[i + b]) {
        dfs(i + b);
    }
    vis[i + b] = 1;
}
int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    while (scanf("%d%d%d", &n, &a, &b) != EOF) {
        if (!n && !a && !b) {
            break;
        }
        memset(vis, 0, sizeof vis);
        // vis[1] = 1;
        int count = 0;
        int tmp = 0;
        int con = 0;
        dfs(0);
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                con++;
            }
        }

        printf("%d\n", con);
        // for (int i = 0; i <= n1; i++) {
        // for (int j = 0; j <= n2; j++) {
        // tmp = i * a + j * b;
        // if (tmp > n) {
        // break;
        // }
        // if (!vis[tmp] && tmp) {
        // count++;
        // vis[tmp] = 1;
        // }
        // }
        // }
    }
    return 0;
}
