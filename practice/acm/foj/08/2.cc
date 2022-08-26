#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

int ans[38][38];

struct node
{
    int r, n;
    node()
    {
        r = 38;
        n = 0;
    }
} ansR[38];

map<int, string> m;
void init()
{
    m[26] = "ld", m[27] = "mb", m[28] = "mp", m[29] = "nc", m[30] = "nd", m[31] = "ng", m[32] = "nt", m[33] = "nw", m[34] = "ps", m[35] = "qu", m[36] = "cw", m[37] = "ts", m[38] = "a";
}

int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    string str;
    int n;
    cin >> n;
    init();
    getline(cin, str);
    while(n--) {
        getline(cin, str);
        istringstream is = istringstream(str);
        string s;
        while(is >> s) {
            if(s.size() < 2) {
                continue;
            }
            for(int a = 0; a < s.size() - 1; a++) {
                int i = a;
                int l, r;
                for(int j = 0; j < 26; j++) {
                    if(s[i] == j + 'a') {
                        l = j;
                        i++;
                        for(int k = 26; k < 38; k++) {
                            string tmp = "";
                            tmp += s[i - 1];
                            tmp += s[i];
                            if(tmp == m[k]) {
                                l = k;
                                i++;
                                break;
                            }
                        }
                        break;
                    }
                }
                if(i >= s.size()) {
                    continue;
                }
                for(int j = 0; j < 26; j++) {
                    if(s[i] == j + 'a') {
                        r = j;
                        for(int k = 26; k < 38; k++) {
                            string tmp = "";
                            tmp += s[i];
                            tmp += s[i + 1];
                            if(tmp == m[k]) {
                                i++;
                                r = k;
                                break;
                            }
                        }
                        break;
                    }
                }
                ans[l][r]++;
                if(ans[l][r] > ansR[l].n || ans[l][r] == ansR[l].n && r < ansR[l].r) {
                    ansR[l].r = r;
                    ansR[l].n = ans[l][r];
                }
            }
        }
    }
    for(int i = 0; i < 38; i++) {
        if(i < 26) {
            printf("%c ", i + 'a');
        } else {
            cout << m[i] << " ";
        }
        if(ansR[i].r < 26) {
            printf("%c ", ansR[i].r + 'a');
        } else {
            cout << m[ansR[i].r] << " ";
        }
        printf("%d\n", ansR[i].n);
    }

    return 0;
}
