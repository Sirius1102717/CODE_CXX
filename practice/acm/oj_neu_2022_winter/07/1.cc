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
const ll MOD = 1e9 + 7;
const int N = 1e3 + 5;

bool is_prime[N];
int prime[N];

void init() {
    memset(is_prime, 0, sizeof is_prime);
    int cnt = 0;
    is_prime[0] = 1, is_prime[1] = 1;
    for(int i = 2; i < N; i++) {
        if(!is_prime[i]) {
            for(int j = 2; j * i < N; j++)
                is_prime[i * j] = 1;
        }
    }
}

void cal(int x) {
    for(int i = 2; i <= x; i++) {
        if(!is_prime[i]) {
            while(x % i == 0) {

                x /= i;
                prime[i]++;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    init();
    cin >> n;
    for(int i = 2; i <= n; i++)
        cal(i);
    ll ans = 1;
    for(int i = 2; i <= n; i++) {
        if(!is_prime[i]) {
            ans *= (prime[i] + 1);
            ans %= MOD;
        }
    }
    cout << ans << endl;

    return 0;
}
