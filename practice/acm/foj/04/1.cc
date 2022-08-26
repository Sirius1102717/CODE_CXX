#include <algorithm>
#include <cmath>
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

int x[50], y[50];
int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    int cnt = 0;
    while (~scanf("%d", &n) && n) {

        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }
        x[n] = x[0], y[n] = y[0];
        double area = 0;
        for (int i = 0; i < n; i++) {
            area += x[i] * y[i + 1] - y[i] * x[i + 1];
        }
        area = abs(area / 2.0);
        printf("%d %.1lf\n", ++cnt, area);
    }
    return 0;
}
