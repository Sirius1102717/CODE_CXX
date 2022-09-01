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
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;


int isPrime[N];

void init()
{
    int m = 0;
    memset(isPrime, 0, sizeof isPrime);
    isPrime[1] = 1;
    for ( int i = 2; i < N; i++ ) {
        if (!isPrime[i]) {
            for (int j = 2; j * i <= N; j++) {
                isPrime[j * i] = 1;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int a, d, n;
    while (cin >> a >> d >> n) {
        if (!a && !d && !n) {
            break;
        }
        int b = a;
        while (n--) {
            while (isPrime[b]) {
                b += d;
            }
            b += d;
        }
        b -= d;
        cout << b << endl;
    }
    
    return 0;
}
