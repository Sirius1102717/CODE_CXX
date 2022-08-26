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
const int N = 1e5 + 5;

int n, t;
int a;

int ans = 0;

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scanf("%d%d", &n, &t);
    int mmin, mmax = -INF;
    int ans = 0;
    scanf("%d", &mmin);
    int pre = mmin;
    while(--n) {
        scanf("%d", &a);
        if(a > pre) {
            if(a - mmin > mmax) {
                ans = 1;
                mmax = a - mmin;
            } else if(a - mmin == mmax)
                ans++;
        }
        mmin = min(mmin, a);
        pre = a;
    }
    printf("%d\n", ans);

    return 0;
}
