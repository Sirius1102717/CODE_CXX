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

int main(int argc, char *argv[]) {
    
    ll t, p;
    cin >> t;
    while(t--) {
        cin >> p;
        cout << p * 6 << " 3\n";
        cout << p << ' ' << p * 2 << ' ' << p * 3 << '\n';
    }
    return 0;
}
