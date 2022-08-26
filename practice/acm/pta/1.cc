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

int main(int argc, char *argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >>x;
    int cnt = 1;
    int num = 1;
    while(num < x) {
        num = num * 10 + 1;
        cnt++;
    }
    while(1) {
        cout << num / x;
        if (num % x == 0) 
            break;
        num = num % x * 10 + 1;
        cnt++;
    }
    cout << ' ' << cnt;
    

    return 0;
}
