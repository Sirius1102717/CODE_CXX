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

string s[5000];

int p, c, w, cs;
void add(string& s1, string s2) {
    s1 += s2;
    s1.append(w - s2.size() + cs - 1, '.');
}
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    queue<string> q;
    bool flag = 0;
    while(cin >> p >> c >> w >> cs) {
        string str;
        getline(cin, str);
        int j = 1;
        int i;
        int k = 1, l = 1, o = 0;
        while(o < p * c) {
            i = o * j;
            if(flag) {
                i = 0;
                while(!q.empty() && i < p) {
                    add(s[i++], q.front());
                    q.pop();
                }
                while(i < p) {
                    getline(cin, str);
                    if(str.size() <= w) {
                        add(s[i], str);
                    } else {
                        s[i] += str.substr(0, w);
                        if(i == p - 1 && k == c) {
                            s[i + 1] = "#";
                            s[i + 2] += str.substr(w);
                            i += 2;
                        } else {
                            q.push(str.substr(w));
                        }
                    }
                    i++;
                }
                if(k == c && i == p) {
                    i = 0;
                    j = l++ * c;
                }
                flag = 0;
            } else {
                getline(cin, str);
                if(str.size() <= w) {
                    add(s[i], str);
                    s[i].append(cs, '.');
                } else {
                    s[i] += str.substr(0, w);
                    s[i] += '.';
                    q.push(str.substr(w));
                }
                i++;
                i %= p;
                if(!i) {
                    k++;
                    flag = 1;
                }
            }
            o++;
        }
        for(int i = 0; i < p * c; i++) {
            cout << s[i] << endl;
        }
        cout << "#" << endl << '?' << endl;
    }

    return 0;
}
