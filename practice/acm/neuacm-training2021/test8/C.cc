#include <cmath>
#include <deque>
#include <iostream>
#include<string>
using namespace std;
const int N = 1e3 + 1;
int q, g, res = 0, l = 0, r = 0, len = 0;
char c;
deque<int> que;

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    while (q--) {
        cin >> c;
        if (c == 'L') {
            que.push_front(++res);
        } else if (c == 'R') {
            que.push_back(++res);
        } else if (c == 'G') {
            cin >> g;
            que.erase(que.begin() + g - 1, que.begin() + g);
        } else {
            cout << que[ceil((que.size() + 1) / 2.0) - 1] << "\n";
        }
    }

    return 0;
}
