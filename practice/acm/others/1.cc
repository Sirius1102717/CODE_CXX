#include <algorithm>
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

int fa[62][62];
bool vis[62];

int get_int(char c) {
    if(c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    if(c >= 'A' && c <= 'Z') {
        return c - 'A' + 26;
    }
    return c - '0' + 52;
}

char get_char(int a) {

    if(a >= 0 && a < 26) {
        return a + 'a';
    }
    if(a >= 26 && a < 52) {
        return a - 26 + 'A';
    }
    return a - 52 + '0';
}

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    string s;
    memset(fa, 0, sizeof fa);
    while(n--) {
        cin >> s;
        int x = get_int(s[0]);
        int xson = get_int(s[3]);
        int xfa = get_int(s[2]);
        if(fa[xson][x] || fa[x][xfa] || fa[xson][xfa]) {
            cout << "No Anwser";
            return 0;
        }
        vis[x] = vis[xson] = vis[xfa] = 1;
        fa[x][xson] = fa[xfa][xson] = fa[xfa][x] = 1;
    }
    string ans = "";
    int num = 0;
    for(int i = 0; i < 62; i++) {
        if(vis[i]) {
            num++;
        }
    }
    while(num--) {

        for(int i = 0; i < 62; i++) {
            if(vis[i]) {
                bool flag = 1;
                for(int j = 0; j < 62; j++) {
                    if(vis[j] && fa[j][i]) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    vis[i] = 0;
                    ans += get_char(i);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
