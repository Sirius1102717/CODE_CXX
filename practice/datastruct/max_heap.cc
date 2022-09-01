#include <future>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
const int H = 5e5 + 5;

int h;

inline int left(int x) {
    return x << 1;
}

inline int right(int x) {
    return x << 1 | 1;
}

int a[H];

void max_heapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l <= h && a[l] > a[i]) largest = l;
    if (r <= h && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        max_heapify(largest);
    }
}

void build_max_heap() {
    for (int i = h / 2; i >= 1; i--) max_heapify(i);
}

int main(int argc, char *argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h;
    for (int i = 1; i <= h; i++) cin >> a[i];
    build_max_heap();
    for (int i = 1; i <= h; i++) cout << a[i] << ' ';
    
    return 0;
}
