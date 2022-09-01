#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

int tim[35];

map<string, int> mm;

vector<int> v[35];
map<string, int> in;
map<int, string> out;

int point[35];

struct s {
    string name;
    int point;
    s(){};
    s(string name, int point) : name(name), point(point) {}
    bool operator<(s ss) {
        if(point < ss.point) {
            return 1;
        } else {
            if(point == ss.point) {
                return name < ss.name;
            } else
                return 0;
        }
    }
};

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int d;
    string name;
    s ss[35];
    while(cin >> n) {
        if(!n) break;
        memset(tim, 0, sizeof tim);
        memset(point, 0, sizeof point);
        in.clear();
        out.clear();
        
        for (int i = 0; i < n; i++) {
            v[i].clear();
        }
        for(int i = 0; i < n; i++) {
            cin >> name >> m;
            in[name] = i;
            out[i] = name;
            while(m--) {
                cin >> d;
                tim[d]++;
                v[i].push_back(d);
            }
        }
        for(int i = 0; i < n; i++) {
            for(auto a : v[i]) {
                point[i] += n+ 1 - tim[a];
            }
            ss[i] = s(out[i], point[i]);
        }
        sort(ss, ss + n);
        cout << ss[0].point << ' ' << ss->name << '\n';
    }

    return 0;
}
