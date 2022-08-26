#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define eps 1e-6
#define LL long long
#define pii pair<int, int>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

const int MAXN = 400000;
//const int INF = 0x3f3f3f3f;
bool has[MAXN];
int fac[9] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320 };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int last[MAXN];
short int mov[MAXN];

struct State {
    int f, g;
    int s[20];
    int pos;
    int hash;
    bool operator<(const State& A) const {
        return A.f == f ? g > A.g : f > A.f;
    }
} ini, target;

int cal_h(int* s1) {
    int ans = 0;
    for(int i = 0; i < 16; i++) {
        if(s1[i] == 16) continue;
        int x = (s1[i] - 1) / 4, y = (s1[i] - 1) % 4;
        int nx = i / 4, ny = i % 4;
        ans += abs(x - nx) + abs(y - ny);
    }
    return ans;
}

priority_queue<State> q;

int Hash(int* s) {
    int res = 0;
    for(int i = 0; i < 16; i++) {
        int cnt = 0;
        for(int j = i + 1; j < 9; j++) {
            if(s[i] > s[j]) cnt++;
        }
        res += cnt * fac[8 - i];
    }
    return res;
}

int cal_pos(int pos, int i) {
    int nx = pos / 3 + dx[i], ny = pos % 3 + dy[i];
    if(nx < 0 || nx > 2 || ny < 0 || ny > 2) return -1;
    return nx * 3 + ny;
}

void BFS() {
    for(int i = 0; i < 9; i++)
        target.s[i] = i + 1;
    target.pos = 8;
    target.hash = 0;
    has[0] = 1;
    q.push(target);
    while(!q.empty()) {
        State ha = q.top();
        q.pop();
        State tmp;
        for(int i = 0; i < 4; i++) {
            tmp.pos = cal_pos(ha.pos, i);
            tmp.g = ha.g + 1;
            if(tmp.pos < 0) continue;
            for(int j = 0; j < 9; j++) {
                if(j == ha.pos)
                    tmp.s[j] = ha.s[tmp.pos];
                else if(j == tmp.pos)
                    tmp.s[j] = ha.s[ha.pos];
                else
                    tmp.s[j] = ha.s[j];
            }
            tmp.hash = Hash(tmp.s);
            if(has[tmp.hash]) continue;
            tmp.f = ha.f + cal_h(tmp.s);
            q.push(tmp);
            has[tmp.hash] = 1;
            last[tmp.hash] = ha.hash;
            mov[tmp.hash] = i;
        }
    }
}

void print_path(int x) {
    if(x == 0) return;
    int i = mov[x];
    if(!i)
        printf("d");
    else if(i == 1)
        printf("r");
    else if(i == 2)
        printf("u");
    else
        printf("l");
    print_path(last[x]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    memset(has, 0, sizeof(has));
    BFS();
    char tmp;
    while(cin >> tmp) {
        if(tmp != 'x')
            ini.s[0] = tmp - '0';
        else {
            ini.s[0] = 9;
            ini.pos = 0;
        }
        for(int i = 1; i < 9; i++) {
            cin >> tmp;
            if(tmp == 'x') {
                ini.s[i] = 9;
                ini.pos = i;
            } else
                ini.s[i] = tmp - '0';
        }
        ini.hash = Hash(ini.s);
        if(!has[ini.hash])
            printf("unsolvable");
        else
            print_path(ini.hash);
        puts("");
    }
    return 0;
}
