#include <algorithm>
#include <cstdio>
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
const int SENTINEL = 1e9 + 5;
const int N = 5e5 + 5;

int l[N], r[N];
int a[N];

ll cnt = 0;

void final_merge(int* a, int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    for(int i = 0; i < n1; i++)
        l[i] = a[left + i];
    for(int i = 0; i < n2; i++)
        r[i] = a[mid + i];

    l[n1] = SENTINEL, r[n2] = SENTINEL;

    int i = 0, j = 0;
    for(int k = left; k < right; k++) {
        cnt++;
        if(l[i] <= r[j])
            a[k] = l[i++];
        else
            a[k] = r[j++];
    }
}

void merge_sort(int* a, int left, int right) {
    if(right > left + 1) {
        int mid = (left + right) >> 1;
        merge_sort(a, left, mid);
        merge_sort(a, mid, right);
        final_merge(a, left, mid, right);
    }
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(a, 0, n);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n%lld\n", cnt);

    return 0;
}
