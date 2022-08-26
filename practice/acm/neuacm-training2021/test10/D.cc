#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
const int N = 1e5 + 5;
int t, n, in[27], out[27];
string s;

int father[27];
int tot;

int find(int x)
{
    return x == -1 ? x : father[x] = find(father[x]);
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        father[fx] = fy;
    }
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    cin >> t;
    char c = 'a';
    while (t--) {
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        memset(father, -1, sizeof father);
        // for (int i = 1; i <= 26; i++) {
            // father[i] = i;
        // }
        cin >> n;
        while (n--) {
            cin >> s;
            int b = s[0] - 'a';
            int e = s[s.size() - 1] - 'a';
            in[b]++, in[e]++;
            join(b, e);
        }
        int s1 = 0, s2 = 0, cnt = 0;
        bool flag = 1;
        for (int i = 0; i < 26; i++) {
            if (find(i) == i && (in[i] || out[i])) {
                s1++;
            }
            if (abs(in[i] - out[i]) < 2) {
                if (in[i] != out[i]) {
                    cnt++;
                }
            } else {
                flag = 0;
            }
        }
        if (flag && cnt < 3 && s1 < 2) {
            cout << "Ordering is possible.\n";
        } else {
            cout << "The door cannot be opened.\n";
        }
    }
    return 0;
}
