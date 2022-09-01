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
const int N = 1e3 + 5;
double p[N], q[N];

double w[N][N];
double e[N][N];
double root[N][N];
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 0; i <= n; i++)
        cin >> q[i];
    for(int i = 1; i <= n + 1; i++)
        w[i][i - 1] = e[i][i - 1] = q[i - 1];
    for(int len = 1; len <= n; len++) {
        for(int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            e[i][j] = INF;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            for(int k = i; k <= j; k++) {
                double tmp = e[i][k - 1] + e[k + 1][j] + w[i][j];
                if(tmp < e[i][j]) {
                    e[i][j] = tmp;
                    root[i][j] = k;
                }
            }
        }
    }
    cout << "各子树的根：" << endl;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << root[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
