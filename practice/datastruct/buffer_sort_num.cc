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
// const int N = 2e5 + 5;
const int N = 2e5 + 5;

ll bit[N];
int n;

inline int lowbit(int x) {
    return x & -x;
}

ll get_sum(int i) {
    ll sum = 0;
    while(i > 0) {
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}

void add(int i, ll x) {
    while(i <= n) {
        bit[i] += x;
        i += lowbit(i);
    }
}


ll ans;
int a[N];
int tmp[N];
void merge_sort(int l, int r) {
    if(l == r) return;
    int mid = (l + r )>> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int ll = l, sst = l, rr = mid + 1;
    while(l <= mid && rr <= r) {
        if(a[l] <= a[rr])
            tmp[ll++] = a[l++];
        else {
            tmp[ll++] = a[rr++];
             ans += mid - l + 1;
        }
    }
    while(l <= mid)
        tmp[ll++] = a[l++];
    while(rr <= r)
        tmp[ll++] = a[rr++];
    for(int i = sst; i <= r; i++)
        a[i] = tmp[i];
    return;
}
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    merge_sort(0, n - 1);
    cout << ans << endl;

    return 0;
}
