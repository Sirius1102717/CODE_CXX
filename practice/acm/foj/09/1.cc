#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
int a[105];

int main(int argc, char* argv[]) {
    int n, m;
    while(cin >> n >> m) {
        if (!n && !m) {
            break;
        }
        memset(a, 0, sizeof a);
        int t;
        int x;
        while(n--) {
            cin >> t;
            while (t--) {
                cin >> x;
                a[x]++;
            }
        }
        int ans;
        ans = 0;
        a[0] = -1;
        for(int i = 1; i < 101; i++) {
            if(a[i] >= m && a[i] > a[ans]) {
                ans = i;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
