#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
list<int> l;

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    string s;
    while(n--) {
        cin >> s >> x;
        if(s == "insert") {
            l.push_front(x);
        } else if(s == "deleteFirst") {
            l.erase(l.begin());
        } else if(s == "deleteLast") {

            l.erase(l.end());
        } else {
            auto it = l.begin();
            for (it; it != l.end(); ++it) {
                if (*it == x) {
                    break;
                }
            }
            l.erase(it);
        }
    }
    for(auto a : l) {
        cout << a << " ";
    }

    return 0;
}
