#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e7 + 5;

int parent[N], sons[N], ans, n, a, b;

void init()
{
    fill(sons, sons + N, 1);
    ans = 0;
    for (int i = 1; i < N; i++) {
        parent[i] = i;
    }
}

int getParent(int x)
{
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = getParent(parent[x]);
}

void join(int x, int y)
{
    if (x < y) {
        swap(x, y);
    }
    int px = getParent(x);
    int py = getParent(y);
    if (px != py) {
        parent[px] = py;
        sons[py] += sons[px];
        // sons[px] = 0;
        ans = max(sons[py], ans);
    }
}

int main(int argc, char* argv[])
{

    while (~scanf("%d", &n)) {
        if (n == 0) {
            printf("1\n");
            continue;
        }
        init();
        while (n--) {
            scanf("%d%d", &a, &b);
            join(a, b);
        }
        printf("%d\n", ans);
    }

    return 0;
}
