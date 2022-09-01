#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include<string>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e4 + 5;
struct node
{
    int to, nex;
} e[N];

int dfn[N], book[N], head[N], num[N];
int in[N], out[N], low[N], a[N];
int cnt, tim, ans, n, m, x, y, sum;
stack<int> s;
void add(int x, int y)
{
    e[++cnt].nex = head[x];
    e[cnt].to = y;
    head[x] = cnt;
}

void tarjan(int x)
{
    dfn[x] = low[x] = ++tim;
    s.push(x);
    book[x] = 1;
    for (int i = head[x]; i; i = e[i].nex) {
        int to = e[i].to;
        if (!dfn[to]) {
            tarjan(to);
            low[x] = min(low[x], low[to]);
        }
        if (book[to]) {
            low[x] = min(low[x], low[to]);
        }
    }
    if (low[x] == dfn[x]) {
        ans++;
        while (s.size()) {
            num[ans]++;
            int now = s.top();
            s.pop();
            book[now] = 0;
            a[now] = ans;
            if (now == x) {
                break;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(head, 0, sizeof head);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    ans = cnt = tim = sum = 0;
    while (m--) {
        cin >> x >> y;
        add(x, y);
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (num[i] == n - 1) {
            sum++;
        }
    }
    cout << sum << "\n";

    return 0;
}
