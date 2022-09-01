#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int cal(int y, int m, int d)
{

    int ans = (y - 1) * 5 * 39;
    ans += (y - 1) / 3 * 5;
    ans += d;
    ans += (m - 1) * 20;
    if (y % 3) {
        ans -= (m - 1) / 2;
    }
    return ans;
}
int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, y, m, d;
    cin >> n;
    while (n--) {
        cin >> y >> m >> d;
        cout << cal(1000, 1, 1) - cal(y, m, d) << endl;
    }

    return 0;
}
