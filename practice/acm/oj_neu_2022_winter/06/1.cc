#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
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
const ll MOD = 1e9 + 7;
int n;
int a[N];



int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    if(n & 1) {
        if (a[0] != 1) {
                cout << 0 << endl;
                return 0;
        }
        for (int i = 2; i < n; i += 2) {
            if (a[i] != 2) {
                cout << 0 << endl;
                return 0;
            }
        }
    } else {
        for (int i = 1; i <= n; i += 2) {
            if (a[i] != 2) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    n /= 2;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        ans <<= 1;
        ans %= MOD;
    }

    cout << ans << endl;
    
    

}
