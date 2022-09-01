#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
int n, m, r, q, t, s, ts, te;

using um = unordered_map<int, int>;

inline int lc(int x) {
    return x << 1;
}

inline int rc(int x) {
    return x << 1 | 1;
}

struct stu {
    bool a[1261];

    stu() {
        memset(a, 0, sizeof a);
    }
} S[10001];

void change(bool* a, int ts, int te) {
    for(int i = ts; i < te; i++) {
        a[i] = 1;
    }
}

int query(bool* a, int ts, int te) {
    int res = 0;
    for(int i = ts; i < te; i++) {
        if(a[i]) {
            res++;
        }
    }
    return res;
}

um mp[1005];

int main(int argc, char* argv[]) {

    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n >> m) {
        mp->clear();
        memset(S, 0, sizeof S);
        if(!n && !m) {
            break;
        }
        cin >> r;
        while(r--) {
            cin >> t >> n >> m >> s;
            if(s) {
                mp[n][m] = t;
            } else {
                change(S[m].a, mp[n][m], t);
            }
        }
        cin >> q;
        while(q--) {
            cin >> ts >> te >> m;
            cout << query(S[m].a, ts, te) << endl;
        }
    }

    return 0;
}