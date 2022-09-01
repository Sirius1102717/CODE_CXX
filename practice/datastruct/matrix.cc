#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const ll INF = 0x3f3f3f3f;
const int N = 1e3 + 5;
// #define int long long

int p[N + 1];
int m[N][N];
int s[N][N];
int n;

struct node {
    int row;
    int line;
} t[N];

void make_chain(int n) {
    p[1] = t[1].row;
    for(int i = 2; i <= n; i++) {
        if(t[i].row == t[i - 1].line) p[i] = t[i].row;
    }
    p[n + 1] = t[n].line;
}

void matrixchain(int n) {
    memset(m, 0, sizeof(m));
    for(int r = 1; r <= (n - 1); r++) {
        for(int i = 1; i <= n; i++) {
            int j = i + r;
            m[i][j] = INF;
            for(int k = i; k < j; k++) {
                m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1]);
            }
        }
    }
}
int main() {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    cin >> n;
    int pre = -1;
    int x, y;
    for(int i = 1; i <= n; i++)
        cin >> t[i].row >> t[i].line;

    // memset(m, 0, sizeof m);

    // for(int i = 2; i <= n; i++) {
    // for(int j = 0; j < n - i + 1; j++) {
    // m[j][j + i - 1] = INF;
    // for(int k = 0; k < i - 1; k++) {
    // if(m[j][j + i - 1] > m[j][j + k] + m[j + k + 1][j + i - 1] + p[j] * p[j + k + 1] * p[j + i]) {
    // m[j][j + i - 1] = m[j][j + k] + m[j + k + 1][j + i - 1] + p[j] * p[j + k + 1] * p[j + i];
    // s[j][j + i - 1] = k;
    // }
    // }
    // }
    // }
    make_chain(n);
    matrixchain(n);
    cout << m[1][n] << endl;
    return 0;
}