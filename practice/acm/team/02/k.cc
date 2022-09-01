#include <algorithm>
#include <cmath>
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

int main(int argc, char* argv[]) {
    int n;
    ll k;
    ll tmp;

    while(cin >> n >> k) {
        ll tot = 0;
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            tot += tmp;
        }
        if(tot < k)
            cout << 0 << '\n';
        else
            cout << tot - ceil(k / 2.0) << '\n';
    }

    return 0;
}
