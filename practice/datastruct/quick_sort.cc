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

const int N = 1e6 + 5;

char c[N][4];
char cc[N][4];
int cnum[N];
int ccnum[N];

struct node {
    char color;
    int n;

    node(char color, int n) : color(color), n(n) {}
    node() = default;
};

bool cmp(node n1, node n2) {
    return n1.n < n2.n;
}

node a[N];
node b[N];
int partition(int p, int r) {
    int x = a[r].n;
    int i = p - 1;
    for(int j = p; j < r; j++) {
        if(a[j].n <= x) {
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quick_sort(int p, int r) {
    if(p < r) {
        int q = partition(p, r);
        quick_sort(p, q - 1);
        quick_sort(q + 1, r);
    }
}


int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string color, num;
    memset(c, 0, sizeof c);
    memset(cnum, 0, sizeof cnum);
    memset(cc, 0, sizeof cc);
    memset(ccnum, 0, sizeof ccnum);

    a[0] = node('a', 1);
    b[0] = node('a', 1);
    for(int i = 1; i <= n; i++) {
        cin >> color >> num;
        int rnum = stoi(num);
        a[i] = node(color[0], rnum);
        b[i] = a[i];
        // c[rnum][cnum[rnum]++] = color[0];
    }
    // int m = partition(a, 1, n);
    // partition(1, n);
    quick_sort(1, n);
    stable_sort(b + 1, b + 1 + n, cmp);
    // for(int i = 1; i <= n; i++)
        // cc[a[i].n][ccnum[a[i].n]++] = a[i].color;

    bool flag = 1;
    for (int i = 1; i <= n; i++) 
        flag &= a[i].color == b[i].color;
    // for(int i = 1; i <= n; i++)
        // flag &= !strcmp(cc[a[i].n] , c[a[i].n]);
    if(flag)
        cout << "Stable\n";
    else
        cout << "Not stable\n";

    for(int i = 1; i <= n; i++) {
        cout << a[i].color << ' ' << a[i].n << '\n';
    }

    return 0;
}
