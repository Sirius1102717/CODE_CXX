#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
int n, m;
vector<int> h;

int main(int argc, char *argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int x;
    while(n--) {
        cin >> m;
        h.clear();
        for (int i = 0; i < m; i++) {

            cin >> x;
            h.push_back(x);
        }
        int ans = 0;
        int index = -INF;
        for (int i = 0; i < m; i++) {
            int tmp = h[i];
            if (tmp <= index + 10 && tmp >= index - 10) {
                continue;
            }
            ans++;
            index = h[i] + 10;
        }
        cout << ans << endl;
    }
    
    return 0;
}
