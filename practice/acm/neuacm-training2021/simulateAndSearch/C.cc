#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    int t;
    int n;
    string a, b;
    string s;
    cin >> t;
label:
    while (t--) {
        cin >> n >> s;
        int cnt = 0, e = 0, c = 0;
        int nnt = 0, tmp = 0;
        int pre[26];
        bool flag = 1;
        bool visited[26] = { 0 }, l[100] = { 0 };
        if (n & 1) {
            cout << "ERR\n";
            goto label;
        }
        while (n--) {
            cin >> a;
            if (a[0] == 'F') {
                cin >> a;
                if (visited[a[0] - 'a']) {
                    cout << "ERR\n";
                    goto label;
                } else {
                    visited[a[0] - 'a'] = 1;
                    pre[e] = a[0] - 'a';
                }
                cin >> a >> b;
                if (b[0] == 'n' && a[0] != 'n' && flag) {
                    tmp++;
                    l[e] = 1;
                    // fe.emplace('F');
                } else if (a > b || (a.size() == b.size()) || (a[0] == 'n' && b[0] != 'n') && flag) {
                    flag = 1;
                    c = e;
                }
            } else {
                nnt = max(nnt, tmp);
                // tmp = 0;
                visited[pre[e]] = 0;
                if (l[e]) {
                    tmp--, l[e] = 0;
                    e--;
                }
                if (c > 0 && e < c) {
                    flag = 0, c = 0;
                }
            }
        }
        if (e > 0) {
            cout << "ERR\n";
        } else {
            string jud = "O(";
            if (nnt) {
                jud += "n^";
                jud += to_string(nnt);
            } else {
                jud += '1';
            }
            jud += ')';
            cout << (jud == s ? "Yes" : "No") << "\n";
        }
    }

    return 0;
}
