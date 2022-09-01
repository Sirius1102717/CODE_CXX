#include <iostream>
#include <string>
using namespace std;
const int N = 1e3 + 1;

int parent[N];

int in, out;

void init(int n)
{
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int getParent(int n)
{
    if (n == parent[n]) {
        return n;
    }
    return parent[n] = getParent(parent[n]);
}

void join(int x, int y)
{
    int px = getParent(x), py = getParent(y);
    if (px != py) {
        parent[px] = py;
    }
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, ans;
    while (cin >> n, n) {
        cin >> m;
        ans = -1;
        init(n);
        for (int i = 0; i < m; i++) {
            cin >> in >> out;
            join(in, out);
        }
        for (int i = 1; i <= n; i++) {
            if (getParent(i) == i) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
