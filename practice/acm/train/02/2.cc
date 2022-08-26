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

struct node {
    string name;
    int weekday;
    int start;
    bool operator<(const node& n) {
        return (weekday < n.weekday) || (weekday == n.weekday && start < n.start);
    }
} t[505];

bool vis[505];
struct nnode {
    int weekday;
    int start;
    int indx;
};

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    string name;
    int weekday, start;
    int indx;
lab:
    while(cin >> n, n) {
        int ans = 0;
        int cw = INF, cs = INF, cd;
        map<string, int> m;
        queue<nnode> q;
        for(int i = 0; i < n; i++) {
            vis[i] = 0;
            cin >> name >> weekday >> start;
            t[i].name = name, t[i].weekday = weekday, t[i].start = start;
        }
        sort(t, t + n);
        for(int i = 0; i < n; i++)
            m[t[i].name] = i;
        cin >> p;
        ans += p;
        while(p--) {
            cin >> name;
            indx = m[name];
            vis[indx] = 1;
            // if(t[indx].weekday <= cw) {
            // if(t[indx].weekday == cw) {
            // cs = min(cs, t[indx].start);
            // } else {
            // cw = t[indx].weekday;
            // cs = t[indx].start;
            // }
            // cd = cs + 30;
            // }
            //
        }
        int bi = -1, ei = n;
        int prew = -1, pres = -1;
        for(int i = 0; i < n; i++) {
            if(vis[i]) {
                if(t[i].weekday < prew || (t[i].weekday == prew && t[i].start <= pres + 30)) {
                    cout << "-1\n";
                    goto lab;
                }
                q.push(nnode{ t[i].weekday, t[i].start, i });
            }
        }
        int pw, ps;
        if(q.size()) {
            pw = q.front().weekday, ps = q.front().start, bi = q.front().indx;
            q.pop();
        } else {
            pw = ps = -1;
        }
        if(q.size()) {
            cw = q.front().weekday, cs = q.front().start, ei = q.front().indx;
            q.pop();
        } else {
            cw = cs = INF;
        }
        int ppw = -1, pps = -30;
        for(int i = 0; i < bi; i++) {
            if((t[i].weekday > ppw || t[i].start >= pps + 30) && (t[i].weekday <= pw && (t[i].start + 30 <= ps || t[i].weekday < pw))) {
                ppw = t[i].weekday, pps = t[i].start;
                ans++;
            }
        }
        do {
            for(int i = bi + 1; i < ei; i++) {
                if((t[i].start >= ps + 30 || t[i].weekday > pw) && t[i].weekday <= cw && (t[i].start + 30 <= cs || t[i].weekday < cw)) {
                    ans++;
                    ps = t[i].start;
                    pw = t[i].weekday;
                    bi = i;
                    if(q.size()) {
                        cw = q.front().weekday, cs = q.front().start, ei = q.front().indx;
                        q.pop();
                    }
                }
            }
        } while(!q.empty());
        for(int i = ei + 1; i < n; i++) {
            if(!vis[i]) {
                if(t[i].start >= ps + 30 || t[i].weekday > pw) {
                    ans++;
                    ps = t[i].start;
                    pw = t[i].weekday;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
