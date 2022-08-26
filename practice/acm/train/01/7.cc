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
const ll MOD = 100000007;
const int N = 1e5 + 5;
ll f[N];
ll t[N];

void init() {
    f[1] = 1, f[2] = 2, f[3] = 4, f[4] = 8, f[5] = 16;
    t[1] = 1, t[2] = 2, t[3] = 4;
    for(int i = 6; i <= N; i++) {
        // f[i] = f[i - 1] + f[i - 2] + f[i - 3] + f[i - 4] + f[i - 5] + 1;
        f[i] = (f[i - 1] % MOD + f[i - 2] % MOD + f[i - 3] % MOD + f[i - 4] % MOD + f[i - 5] % MOD + 1) % MOD;
    }
    for(int i = 4; i <= N; i++) {
        t[i] = (t[i - 1] % MOD + t[i - 2] % MOD + t[i - 3] % MOD + 1) % MOD;
    }
}
ll q_mul(ll a, ll b, ll p) {
    ll sum = 0;
    while(b) {
        if(b & 1) sum = (sum + a) % p;
        a <<= 1;
        a %= p;
        b >>= 1;
    }
    return sum;
}
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    string s;
    while(cin >> s) {
        if(s[0] == '#') break;
        int l = 0, r = 0;
        ll ans = 1;
        int len = 1;
        bool flag = (s[0] == '8' || s[0] == '0') ? 1 : 0;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1])
                len++;
            else {
                if(flag)
                    // ans = q_mul(ans, t[len], MOD);
                    ans = ((ans % MOD) * (t[len] % MOD)) % MOD;
                else
                    // ans = q_mul(ans, f[len], MOD);
                    ans = ((ans % MOD) * (f[len] % MOD)) % MOD;
                len = 1;
                flag = (s[i] == '8' || s[i] == '0') ? 1 : 0;
            }
        }
        if(flag)
            // ans = q_mul(ans, t[len], MOD);
            ans = ((ans % MOD) * (t[len] % MOD)) % MOD;
        else
            // ans = q_mul(ans, f[len], MOD);
            ans = ((ans % MOD) * (f[len] % MOD)) % MOD;

        cout << ans << '\n';
    }
}
