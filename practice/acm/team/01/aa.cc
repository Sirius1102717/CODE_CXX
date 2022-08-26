#include <algorithm>
#include <cmath>
#include <cstdio>
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

string to_hex(int x) {
    string ans = "";
    int tmp;
    while(x) {
        tmp = x % 16;
        x /= 16;
        if(tmp > 9)
            ans += 'A' + tmp - 10;
        else
            ans += to_string(tmp);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    cout << ("11" < "A" ? true : false) << '\n';

    return 0;
}
