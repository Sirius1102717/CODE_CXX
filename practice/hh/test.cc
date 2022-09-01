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

ll a[100];
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n) {
        ll ans = 0;
        ll tmp = 1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        for (int i = n - 1; i >= 0; i--) {
            ans += tmp++ * a[i];
        }
        cout << ans << endl;
    }

    return 0;
}
