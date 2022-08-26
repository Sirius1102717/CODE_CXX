#include <cstdio>
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
int n, q;
int s[100005];
int t[50005];

int main(int argc, char *argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &t[i]);
    }
    int ans = 0;
    for (int i = 0; i < q; i++) {
        if (binary_search(s, s + n, t[i])) {
            ans++;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
