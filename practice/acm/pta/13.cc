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
vector<vector<int>> v;

const int N = 1e5 + 5;

// int num[N];

struct ss {
    vector<int> v;
    int n;
}num[N];

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    
    cin >> n >> m;
    int a[105];
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < m; i++)
            cin >> a[i];
        bool fflag = 0;

        for (int j = 0; j < num[j].v.size(); j++) {

            bool flag = 1;
            for(int i = 0; i < m; i++) {
                if(a[i] != num[j].v[i]) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                fflag = 1;
                num[j].n++;
                break;
            }
        }
        if(!fflag) {
            num[num[k].v.size()].n = 1;
            vector<int> tmp;
            for(int i = 0; i < m; i++) {
                tmp.emplace_back(a[i]);
            }
            numv.emplace_back(tmp);
        }
    }
    sort(num, num + n, greater<int>());
    cout << v.size() << '\n';
    for(int i = 0; i < n; i++) {
        if(num[i]) {
            cout << num[i];
            for(int j = 0; j < m; j++) {
                cout << ' ' << v[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}
