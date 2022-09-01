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

int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    int con = 0;
label:
    while (~scanf("%d%d%d", &a, &b, &c)) {
        if (!a && !b && !c) {
            break;
        }
        for (int r = 1; r <= 100; r++) {
            if (a % r) {
                continue;
            }
            int p = a / r;
            for (int s = -100; s <= 100; s++) {
                if (!s) {
                    if (c) {
                        continue;
                    }
                    if (!(b % r)) {
                        int q = b / r;
                        if (p > r || (p == r && q >= s)) {
                            printf("%d %d %d %d\n", p, q, r, s);
                            goto label;
                        }
                    }
                    int q = 0;
                    if (b % p) {
                        continue;
                    }
                    int tmp = b / p;
                    if (p > r || (p == r && q >= tmp)) {
                        printf("%d %d %d %d\n", p, q, r, tmp);
                        goto label;
                    }
                }
                if (c % s) {
                    continue;
                }
                int q = c / s;
                if (q * r + p * s == b) {
                    if (p > r || (p == r && q >= s)) {
                        printf("%d %d %d %d\n", p, q, r, s);
                        goto label;
                    }
                }
            }
        }
        printf("Impossible\n");
    }
    return 0;
}
