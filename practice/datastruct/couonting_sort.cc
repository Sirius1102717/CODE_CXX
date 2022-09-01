#include <algorithm>
#include <array>
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
const int N = 2e6 + 5;

// array<int, N> a;
int a[N];
array<int, N> b;
array<int, N> c;

void counting_sort(int k) {
    c.fill(0);
    for(int j = 1; j <= k; j++)
        c[a[j]]++;
    for(int i = 1; i <= k; i++)
        c[i] += c[i - 1];
    for(int j = k; j >= 0; j--) {
        b[c[a[j]]] = a[j];
        c[a[j]] = c[a[j]] - 1;
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
    for (int i = 0; i < n; i++) cin >> a[i];
    // counting_sort(n);
    sort(a, a + n);
    for (int i = 0; i < n; i++) cout << a[i] << ' ';

    return 0;
}
