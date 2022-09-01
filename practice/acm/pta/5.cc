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
const int N = 105;

int a[N];

vector<int> v[N];
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int nn = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 10;
        nn += a[i];
    }
    int indx = 0;
    int pre = -1;
    int cur = 1;
    int k = 0;
    int num = 0;
    while(num < nn) {

        for(int j = cur; j <= n; j++) {
            if(a[j]-- > 0) {
                num++;
                if(j != pre) {
                    v[j].emplace_back(++indx);
                } else {
                    indx += 2;
                    v[j].emplace_back(indx);
                }
                cur = j + 1;
                pre = j;
                if(cur > n) cur = 1;
                break;
            } else {
                cur = j + 1;
                if(cur > n) cur = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << '#' << i << '\n';
        for(int j = 0; j < v[i].size(); j++) {
            if(j % 10 == 0) {
                cout << v[i][j];
            } else {
                cout << ' ' << v[i][j];
                if((j + 1) % 10 == 0) cout << '\n';
            }
        }
    }
    return 0;
}
