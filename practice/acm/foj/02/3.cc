#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
const int N = 105;
int n;
struct node
{
    int t, f;
    node(int t, int f)
    {
        this->t = t;
        this->f = f;
    }
    node() {}
} s[N];

node flip(int t, int f, int dir[])
{
    switch (t) {
        case 1:
            switch (f) {
                case 2:
                    if (!dir[3]) {
                        return node(2, 6);
                    } else if (!dir[1]) {
                        return node(3, 2);
                    } else {
                        return node(0, 0);
                    }
                case 3:
                    if (!dir[2]) {
                        return node(2, 3);
                    } else if (!dir[4]) {
                        return node(3, 6);
                    } else {
                        return node(0, 0);
                    }
                case 4:
                    if (!dir[1]) {
                        return node(2, 4);
                    } else {
                        return node(0, 0);
                    }
                case 5:
                    if (!dir[2]) {
                        return node(3, 5);
                    } else {
                        return node(0, 0);
                    }
                default:
                    return node(0, 0);
            }
        case 2: {
            switch (f) {
                case 1:
                    if (!dir[3]) {
                        return node(1, 5);
                    } else if (!dir[2]) {
                        return node(3, 2);
                    } else {
                        return node(0, 0);
                    }
                case 3:
                    if (!dir[1]) {
                        return node(2, 1);
                    } else if (!dir[4]) {
                        return node(3, 2);
                    } else {
                        return node(0, 0);
                    }
                case 4:
                    if (!dir[2]) {
                        return node(3, 4);
                    } else {
                        return node(0, 0);
                    }
                case 6:
                    if (!dir[1]) {
                        return node(3, 6);
                    } else {
                        return node(0, 0);
                    }
                default:
                    return node(0, 0);
            }
        }
        case 3: {
            switch (f) {
                case 1:
                    if (!dir[1]) {
                        return node(2, 1);
                    } else if (!dir[3]) {
                        return node(3, 2);
                    } else {
                        return node(0, 0);
                    }
                case 2:
                    if (!dir[1]) {
                        return node(2, 1);
                    } else if (!dir[4]) {
                        return node(3, 2);
                    } else {
                        return node(0, 0);
                    }
                case 4:
                    if (!dir[2]) {
                        return node(3, 4);
                    } else {
                        return node(0, 0);
                    }
                case 6:
                    if (!dir[1]) {
                        return node(3, 6);
                    } else {
                        return node(0, 0);
                    }
                default:
                    return node(0, 0);
            }
        }
    }
}
void solve() {}
int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].t >> s[i].f;
    }

    return 0;
}
