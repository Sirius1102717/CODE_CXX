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
int a[90];
int b[90];

int main(int argc, char* argv[]) {

    int n, r, p, c;
    while(cin >> n >> r) {
        if(!n && !r) {
            break;
        }
        for(int i = 1; i <= n; i++) {
            a[i] = n + 1 - i;
        }
        while(r--) {
            cin >> p >> c;
            for(int i = 1; i <= c; i++) {
                b[i] = a[p + i - 1];
            }
            for(int i = c + 1; i <= c + 1 + p; i++) {
                b[i] = a[i - c];
            }
            for(int i = p + c; i <= n; i++) {
                b[i] = a[i];
            }
            copy(b + 1, b + 1 + n, a + 1);
        }
        cout << a[1] << endl;
    }

    return 0;
}
