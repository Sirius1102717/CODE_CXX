#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
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
const int N = 1e5 + 5;
int num[N];
int n;
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int x;
    memset(num, 0, sizeof num);
    for(int i = 0; i < n; i++) {
        cin >> x;
        num[x]++;
    }
    int ans = 0, tmp = 0;
    for(int i = 0; i < N; i++) {
        if(num[i]) {
            ans++;
            tmp += num[i] - 1;
        }
    }
    if(tmp & 1)
        cout << ans - 1 << endl;
    else
        cout << ans << endl;

    return 0;
}
