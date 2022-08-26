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
int a, b;
int aa, bb;

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cin >> a >> b;
    while(--n) {
        cin >> aa >> bb;
        if(aa >= a && bb >= b) {
            a = aa, b = bb;
            continue;
        }
        int d1 = a / aa;
        int d2 = b / bb;
        if(a % aa) d1++;
        if(b % bb) d2++;
        int d = max(d1, d2);
        a = d * aa;
        b = d * bb;
    }

    return 0;
}
