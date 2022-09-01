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

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(;;) {
        int math, greedy, geometry, dp, gradp, other;
        cin >> math >> greedy >> geometry >> dp >> gradp >> other;
        if(!math && !greedy && !geometry && !dp && !gradp && !other) break;
        int md = math + dp, gg = greedy + gradp, go = geometry + other;
        int mmin = min(gg, min(md, go));
        int mdmin = min(md % 3, min(gg, go));
        int ggmin = min(gg % 3, min(md, go));
        int gomin = min(go % 3, min(gg, md));
        int mdgomin = min(go % 3, min(md % 3, gg));
        int gggomin = min(go % 3, min(gg % 3, md));
        int ggmdmin = min(gg % 3, min(md % 3, go));
        int ll = md / 3 + gg / 3 + go / 3 + min(md % 3, min(gg % 3, go % 3));
        int rr = mmin + (gg - mmin) / 3 + (go - mmin) / 3 + (md - mmin) / 3;
        int ans = max(ll, rr);
        ans = max(ans, md / 3 + (go - mdmin) / 3 + (gg - mdmin) / 3 + mdmin);
        ans = max(ans, gg / 3 + (md - ggmin) / 3 + (go - ggmin) / 3 + ggmin);
        ans = max(ans, go / 3 + (md - gomin) / 3 + (gg - gomin) / 3 + gomin);
        ans = max(ans, go / 3 + md / 3 + (gg - mdgomin) / 3 + mdgomin);
        ans = max(ans, go / 3 + gg / 3 + (md - gggomin) / 3 + gggomin);
        ans = max(ans, gg / 3 + md / 3 + (go - ggmdmin) / 3 + ggmdmin);
        cout << ans << '\n';
    }

    return 0;
}
