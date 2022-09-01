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

int nextWord(string s, int index)
{
    for (int i = index + 1; i < s.size(); i++) {
        if (s[i] == ',' || s[i] == '.' || s[i] == ' ') {
            if (i == s.size() - 1) {
                return s.size();
            }
            return i;
        }
    }
    return s.size();
}

int preWord(string s, int index)
{
    for (int i = index - 1; i >= 0; i--) {
        if (s[i] == ',' || s[i] == '.' || s[i] == ' ') {
            return i;
        }
    }
    return 0;
}

int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    int n;
    while (~scanf("%d", &n)) {
        int m;
        getchar();
        while (n--) {
            string s;
            getline(cin, s);
            cin >> m;
            string order;
            string to;
            int index = 0;
            while (m--) {
                cin >> order;
                getline(cin.ignore(), to);
                if (order[0] == 'f') {
                    if (to[0] == 'c') {
                        index++;
                    } else {
                        index = nextWord(s, index);
                    }
                } else if (order[0] == 'b') {
                    if (to[0] == 'c') {
                    } else {
                        index = preWord(s, index);
                    }
                    index > 0 ? index-- : index;
                } else if (order[0] == 'd') {
                    if (to[0] == 'c') {
                        s.erase(index, 1);
                    } else {
                        s.erase(index, nextWord(s, index) - index + 1);
                    }
                    // index > 0 ? index-- : index;
                } else {
                    to.erase(0, 1);
                    to.erase(to.size() - 1);
                    // s.insert(index + 1, to);
                    s.insert(index, to);
                    index += to.size();
                    // index++;
                }
            }
            s.insert(index, "^");
            cout << s << endl;
        }
    }
    return 0;
}
