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

int n, w, d;
int p, s;
int l, r;

struct cake {
    int x, y;
    int w, d;
    cake(int ww, int dd) {
        x = 0, y = 0;
        w = ww, d = dd;
    }

    bool friend operator<(cake c1, cake c2) {
        return c1.w * c1.d < c2.w * c2.d;
    }
};

void add(int& x, int& y, int s, int d, int w) {

    while(1) {
        if(w < s) {
            s -= w;
            x += w;
        } else {
            x += s;
            return;
        }
        if(d < s) {
            s -= d;
            y += d;
        } else {
            y += s;
            return;
        }
        if(x < s) {
            s -= x;
            x = 0;
        } else {
            x -= s;
            return;
        }
        if(y < s) {
            s -= y;
            y = 0;
        } else {
            y -= s;
            return;
        }
    }
}

inline bool judge(int x, int y, cake c) {
    return c.x <= x && c.y <= y && c.x + c.w >= x && c.y + c.d >= y;
}

int main(int argc, char* argv[]) {

    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> w >> d) {
        if(!n && !w && !d) {
            break;
        }
        vector<cake> c;
        c.emplace_back(w, d);
        while(n--) {
            cin >> p >> s;
            p--;
            cake cur = c[p];
            int x = cur.x, y = cur.y;
            add(x, y, s, cur.d, cur.w);
            for(int i = 0; i < c.size(); i++) {
                cake tmp = c[i];
                if(judge(x, y, tmp)) {
                    c.erase(c.begin() + i);
                    cake l = tmp;
                    if(y == tmp.y || y == tmp.y + tmp.d) {
                        int xx = x - tmp.x;
                        l.w = xx;
                        tmp.w -= xx;
                    } else {
                        int yy = y - tmp.y;
                        l.d = yy;
                        tmp.d -= yy;
                    }
                    tmp.x = x, tmp.y = y;
                    if(l.d * l.w <= tmp.d * tmp.w) {
                        c.push_back(l);
                        c.push_back(tmp);
                    } else {
                        c.push_back(tmp);
                        c.push_back(l);
                    }
                    // if(l.d * l.w >  tmp.d * tmp.w) {
                    // c.push_back(tmp);
                    // c.push_back(l);
                    // } else {
                    // c.push_back(l);
                    // c.push_back(tmp);
                    // }
                    break;
                }
            }
        }
        sort(c.begin(), c.end());
        for_each(c.begin(), c.end(), [](cake e) { cout << e.d * e.w << " "; });
        cout << endl;
    }

    return 0;
}