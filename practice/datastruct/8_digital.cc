#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
using ll = long long;
using ull = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
int goal[16][2] = { { 3, 3 }, { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 0 }, { 1, 1 }, { 1, 2 }, { 1, 3 }, { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 }, { 3, 0 }, { 3, 1 }, { 3, 2 } };
struct matrix {
    int a[4][4];
    ll tot;
    bool operator<(matrix x) const {
        return tot < x.tot;
    }
} f, st;

ll cal(matrix x) {
    ll tot = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            tot += x.a[i][j], tot *= 10;
    return tot;
}

struct hash_matrix {
    size_t operator()(const matrix& i) const {
        return i.tot;
    }
};

struct equal_to_matrix {
    bool operator()(const matrix& m1, const matrix& m2) const {
        return m1.tot == m2.tot;
    }
};

int h(matrix a) {
    int ret = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++) {
            int w = a.a[i][j];
            ret += abs(i - goal[w][0]) + abs(j - goal[w][1]);
        }
            // if(a.a[i][j] != st.a[i][j]) ret++;
    return ret;
}
int fx, fy;
// int h(matrix a) {
// int ret = 0;
// int i, j;
// int x, y;
// for(i = 0; i < 4; i++) {
// for(j = 0; j < 4; j++) {
// if(a.a[i][j] != st.a[i][j]) {
// int num = a.a[i][j];
// if(!num) {
// x = y = 3;
// } else {
// x = num / 4;
// y = num - 4 * x - 1;
// ret += abs(x - i) + abs(y - j);
// }
// }
// }
// ret += sqrt(pow((i % 4 - j % 4), 2) + pow((i / 4 - j / 4), 2));
// }
// return ret;
// }

struct node {
    matrix a;
    int g;
    node(matrix a, int g) : a(a), g(g) {}

    bool operator<(node x) const {
        return g + h(a) > x.g + h(x.a);
    }
};

priority_queue<node> q;
unordered_set<matrix, hash_matrix, equal_to_matrix> s;
// set<matrix> s;

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    int cnt = 1;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%d", &f.a[i][j]);
            st.a[i][j] = cnt++;
            cnt %= 16;
        }
    }
    int bh = h(f);
    q.emplace(f, 0);
    while(!q.empty()) {
        node x = q.top();
        q.pop();
        if(!h(x.a)) {
            printf("%d\n", x.g);
            return 0;
        }
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(!x.a.a[i][j]) fx = i, fy = j;
        for(int i = 0; i < 4; i++) {
            int xx = fx + dir[i][0], yy = fy + dir[i][1];
            if(xx >= 0 && xx < 4 && yy >= 0 && yy < 4) {
                swap(x.a.a[fx][fy], x.a.a[xx][yy]);
                x.a.tot = cal(x.a);
                if(h(x.a) <= bh && x.g < 45 && !s.count(x.a)) {
                    s.insert(x.a);
                    q.emplace(x.a, x.g + 1);
                }
                swap(x.a.a[fx][fy], x.a.a[xx][yy]);
                x.a.tot = cal(x.a);
            }
        }
    }
    return 0;
}
