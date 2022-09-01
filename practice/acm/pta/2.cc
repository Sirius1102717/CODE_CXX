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

struct node {
    int start;
    int end;
    node() : start(-1), end(-1) {}
} t[1005];

inline int get_time(string s) {
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3));
    return hh * 60 + mm;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int num;
    string o, tim;
    cin >> n;
    while(n--) {
        for(int i = 1; i <= 1000; i++)
            t[i] = node();
        while(cin >> num) {
            cin >> o >> tim;
            if(!num) break;
            if(o[0] == 'S')
                t[num].start = get_time(tim);
            else
                t[num].end = get_time(tim);
        }
        int tot_time = 0, tot = 0;
        for(int i = 1; i <= 1000; i++) {
            if(~t[i].start && ~t[i].end) {
                tot_time += t[i].end - t[i].start;
                tot++;
            }
        }
        if(tot) 
            printf("%d %.0lf\n", tot, tot_time * 1.0/ tot);
            // cout << tot << ' ' << ceil(tot_time * 1.0 / tot) << '\n';
        else
            printf("0 0\n");
    }

    return 0;
}
