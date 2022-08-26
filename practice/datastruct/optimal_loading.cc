#include <algorithm>
#include <cstring>
#include <deque>
#include <ios>
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

int n, k, sum = 0;
int w[N];

bool check(int p) {
    int i = 0;
    for(int j = 0; j < k; j++) {
        int tmp = 0;
        while(tmp + w[i] <= p) {
            tmp += w[i++];
            if(i == n) return 1;
        }
    }
    return 0;
}

int solve() {
    int l = 0, r = sum;
    int mid;
    while(r > l + 1) {
        mid = (r + l) >> 1;

        if(check(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> w[i], sum += w[i];

    cout << solve() << endl;

    return 0;
}
