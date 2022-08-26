#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using iter = multiset<int>:: iterator;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

multiset<int> m;
int n;

int ans = 0;

int x;
int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    m.insert(-INF);
    m.insert(INF);
    cin >> n;
    cin >> x;
    ans += x;
    while (--n) {
        cin >> x;
        iter it = m.insert(x);
        it--;
        iter l = it;
        it++;
        it++;
        iter r = it;
        it--;
        if (*l == -INF) {
            ans += abs(x - *r);
        } else if (*r == INF) {
            ans += abs(x - *l);
        } else {
            ans += min(abs(x - *l), abs(x - *r));
        }
    }
    cout << ans << endl;
    return 0;
}
