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

int mp[101][11];

int p, s;
void f(int x, int y)
{
    for(int i = 0; i < p; i++) {
        for (int j = 0; j < s; j++) {
            if (mp[i][j] == INF) {
                while (mp[i][j++] != INF && mp[j++][i]) {
                    
                }
            }
        }
    }
}
int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> p >> s, p) {
        bool flag = 1;
        string ss;
        for(int i = 0; i < p; i++) {
            for(int j = 0; j < s; j++) {
                cin >> ss;
                if(ss[0] != '?') {
                    mp[i][j] = stoi(ss);
                } else {
                    mp[i][j] = INF;
                }
            }
        }
        for(int i = 0; i < p; i++) {
            for(int j = 0; j < s; j++) {
            }
        }
    }
    return 0;
}
