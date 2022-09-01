#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int N = 45;

ll w[N], v[N];
int n, tot;
ll ans;

pair<ll, ll> p[1 << 21];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> tot;
    for(int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
    }
    int n1 = n >> 1;
    int len = 1 << n1;
    for(int i = 0; i < len; i++) {
        ll sw = 0, sv = 0;
        for(int j = 0; j < n1; j++) {
            if(i >> j & 1) {
                sw += w[j], sv += v[j];
            }
        }
        p[i] = make_pair(sw, sv);
        
    }

    return 0;
}
