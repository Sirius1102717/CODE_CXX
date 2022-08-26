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
const int N = 3e5 +5;

bool is_ms_prime[N];

vector<int> vms;

void init() {
    memset(is_ms_prime, 0, sizeof is_ms_prime);
    for (int i = 1; i < 6; i++) {
        is_ms_prime[i] = 1;
    }
    vms.push_back(6);
    for (int i = 6; i < N; i++) {
        int j = i % 7;
        if (j == 1 || j == 6) {
            for (int k = 2; k * i < N; k++) {
                is_ms_prime[k * i] = 1;
            }
            // vms.push_back(i);
            // bool flag = 1;
            // for (int k = 0; k < vms.size() - 1; k++) {
                // if (i % vms[k] == 0) {
                    // flag = 0;
                    // break;
                // }
            // }
            // if (flag) {
                // is_ms_prime[i] = 1;
            // }
        } else {
            is_ms_prime[i] = 1;
        }
    }
}

int ms;
int main(int argc, char *argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    while (cin >> ms) {
        if (ms == 1) {
            break;
        }
        cout << ms << ": ";
        for (int j = 6; j <= ms; j++) {
            if (!is_ms_prime[j]) {
                if (ms % j == 0) {
                    cout << j << " ";
                }
            }
        }
        cout << endl;
    }
    
    return 0;
}
