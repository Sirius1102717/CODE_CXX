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

int n, m;
int sumn, summ;

int a[105], b[105];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> m) {
        if(!n && !m) {
            break;
        }
        sumn = 0, summ = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sumn += a[i];
        }
        for(int i = 0; i < m; i++) {
            cin >> b[i];
            summ += b[i];
        }
        sort(a, a + n);
        sort(b, b + m);
        int tmp = summ - sumn;
        int aa = INF, bb = INF, aaa, bbb;
        if(tmp % 2) {
            cout << -1 << endl;
            continue;
        }
        bool flag = 0;
        tmp /= 2;
        for(int i = 0; i < n; i++) {

            aaa = a[i];
            for(int j = 0; j < m; j++) {
                if(aaa + tmp == b[j]) {
                    bbb = b[j];
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                if(aaa + bbb < aa + bb) {
                    aa = aaa, bb = bbb;
                }
            }
        }
        if(flag) {
            cout << aa << " " << bb << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
