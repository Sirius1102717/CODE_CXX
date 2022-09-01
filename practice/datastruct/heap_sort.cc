#include <algorithm>
#include <cstring>
#include <deque>
#include <future>
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
const int H = 2e5 + 5;

int h;

int f[H];

void init() {
    f[0] = f[1] = 1;
    for(int i = 2; i < 50; i++)
        f[i] = f[i - 1] + f[i - 2];
}

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
    if(l <= h && a[l] > a[i]) largest = l;
    if(r <= h && a[r] > a[largest]) largest = r;

    if(largest != i) {
        swap(a[i], a[largest]);
        max_heapify(largest);
    }
}

void heap_sort() {
    for(int i = h / 2; i >= 1; i--)
        max_heapify(i);
    for(int i = 1; i <= h; i++) {
        int j = i;
        while(j >= 2) {
            swap(a[1], a[j]);
            j--;
            max_heapify(1);
        }
    }
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> h;
    cout << f[h];
    // for(int i = 1; i <= h; i++)
        // cin >> a[i];
    // heap_sort();
    // for(int i = 1; i <= h; i++)
        // cout << a[i] << ' ';

    return 0;
}
