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
using ull = unsigned long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

ull b[255];
ull ans[255];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, len;
    ull ou, bb;
    while(cin >> n, n) {
        len = n * (n + 1) / 2;
        vector<ull> v;
        for(int i = 0; i < len; i++) {
            cin >> b[i];
            if(b[i] & 1) continue;
            v.emplace_back(b[i]);
        }
        bb = v[0];
        for(int i = 1; i < v.size(); i++)
            ou = __gcd(bb, v[i]);

        ans[0] = ou;
        ans[1] = b[0] / ou;
        int ansl = 2;
    label:
        for(int k = 1; k < len; k++) {
            for(int j = 0; j < ansl; j++) {
                for(int i = 0; i < j; i++) {
                    if(ans[i] * ans[j] == b[k]) {
                        goto label;
                    }
                }
            }
        }
    }
    return 0;
}
