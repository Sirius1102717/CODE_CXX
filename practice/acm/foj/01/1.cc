#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 3e5;
bool isPrime[N];

void e_prime()
{
    memset(isPrime, 0, sizeof isPrime);
    isPrime[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!isPrime[i]) {
            for (int j = 2; j * i < N; j++) {
                isPrime[i * j] = 1;
            }
        }
    }
}
int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    int n;
    e_prime();
    while (cin >> n, n) {
        int m = n << 1;
        int ans = 0;
        for (int i = n + 1; i <= m; i++) {
            if (!isPrime[i]) {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
