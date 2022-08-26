#include <algorithm>
#include <iostream>
#include <queue>
typedef long long LL;

using namespace std;

int main() {
    LL n, m;
    cin >> n >> m;
    LL sum = 0;
    for(int i = 1; i <= n; i++) {
        LL x;
        cin >> x;
        sum += x;
    }
    if(sum < m) {
        cout << 0 << endl;
        return 0;
    }
    LL y;
    if(m % 2 == 0)
        y = m / 2;
    else
        y = m / 2 + 1;
    cout << sum - y << endl;
    return 0;
}
