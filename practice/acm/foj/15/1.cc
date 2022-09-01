#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

int n, p;
int a[60];
int main(int argc, char *argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> p) {
        if (!n && !p) {
            break;
        }
        memset(a, 0, sizeof a);
        int ans = 0;
        int o = p - 1;
        while (1) {
            if (p && a[ans] == o) {
                cout << ans << endl;
                break;
            }
            if (p) {
                a[ans]++;
                p--;
            } else {
                p = a[ans];
                a[ans] = 0;
            }
            ++ans %= n;
        }
    }
    
    return 0;
}
