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
queue<string> q;
int p, c, w, cs;
void add(string& s1, string s2)
{
    s1 += s2;
    s1.append(w - s2.size() + cs - 1, '.');
}
int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> p >> c >> w >> cs) {
        string str;
        getline(cin, str);
        int i = 0;
        int j = 1;
        int k = 1;
        while(j <= c) {
            while(getline(cin, str)) {
                if(k == c) {
                    j++;
                    k = 1;
                    i = 0;
                    if(str.size() >= w) {
                        i += (j - 1) * p;
                        add(s[i++], str);
                        s[i++] = "#";
                    }
                } else {
                    i += (j - 1) * p;
                }
                // label:
                if(i < p * j) {
                    if(str.size() <= w) {
                        add(s[i], str);
                    } else {
                        add(s[i], str.substr(0, w));
                        q.push(str.substr(w));
                    }
                    s[i].append(cs, '.');
                } else {
                    k++;
                    i = 0;
                    i += (j - 1) * p;
                    while(!q.empty()) {
                        add(s[i++], q.front());
                        q.pop();
                    }
                    do {
                        if(str.size() <= w) {
                            add(s[i++], str);
                        } else {
                            add(s[i++], str.substr(0, w));
                            if(i == p * j) {
                                if(k == c) {
                                    j++;
                                    k = 1;
                                    i = 0;
                                    i += (j - 1) * p;
                                    s[i++] = "#";
                                    add(s[i++], str.substr(w));
                                }
                            } else {
                                add(s[i++], str.substr(w));
                            }
                        }

                    } while(i < p * j && getline(cin, str));
                }
                i++;
            }
        }
        for(int i = 0; i < p * c; i++) {
            cout << s[i] << endl;
        }
        cout << "#" << endl << '?' << endl;
    }

    return 0;
}
