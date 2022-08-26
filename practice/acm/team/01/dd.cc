#include <bits/stdc++.h>
#define register
#define il inline
#define int long long
#define ll long long
#define maxn 500005
#define modd 1000000007
#define pa pair<int, int>
using namespace std;
il int read() {
    int x = 0, w = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') w = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x * w;
}
int x[maxn], c[maxn], ans[maxn];
struct node {
    int id, ans;
} p[maxn];
bool cmp(node a, node b) {
    if(a.ans != b.ans)
        return a.ans < b.ans;
    else
        return a.id < b.id;
}

signed main() {
    int t = read();
    while(t--) {
        int n = read(), h = read(), hh = read();
        for(int i = 1; i <= n; ++i) {
            x[i] = read();
        }
        for(int i = 1; i <= n; ++i) {
            c[i] = read();
        }
        for(int i = 1; i <= n; ++i) {
            int t = x[i];
            t %= 2 * hh;
            int tmp;

            if(t > hh) {
                int nowh = 2 * hh - h;
                if(nowh <= h) {
                    ans[i] = x[i] + c[i];
                } else {
                    ans[i] = x[i] + (2 * hh - t - h) + c[i];
                }
            } else {
                int nowh = t;
                if(nowh <= h) {
                    ans[i] = x[i] + c[i];
                } else {
                    ans[i] = x[i] + (2 * hh - t - h) + c[i];
                }
            }
        }
        for(int i = 1; i <= n; ++i) {
            p[i].id = i, p[i].ans = ans[i];
        }
        sort(p + 1, p + 1 + n, cmp);
        cout << p[1].id << endl;
    }
    return 0;
}
