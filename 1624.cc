#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

int main(int argc, char* argv[]) {
    freopen("/home/sirius/CODE_CXX/input.txt", "r", stdin);
    // freopen("/home/sirius/CODE_CXX/output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin >> s) {
        map<char, int> indx;
        int len[128];
        for(int i = 0; i < 128; i++)
            indx[char(i)] = len[i] = -1;
        char c;
        for(int i = 0; i < s.size(); i++) {
            c = s[i];
            if(~indx[c])
                len[int(c)] = max(len[int(c)], i - indx[c] - 1);
            else
                indx[c] = i;
        }
        int maxlen = -1;
        for(int i = 0; i < 128; i++)
            maxlen = max(maxlen, len[i]);

        cout << maxlen << endl;
    }
    return 0;
}
