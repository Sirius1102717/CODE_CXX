#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int l;
string a;
int tmp[6];
void solve()
{
    vector<int> v;
    v.push_back(stoi(a));
    while (1) {
        memset(tmp, 0, sizeof tmp);

        if (a.size() < l) {
            a.insert(0, l - a.size(), '0');
        }
        for (int i = 0; i < l; i++) {
            tmp[i] = a[i] - '0';
        }
        sort(tmp, tmp + l);
        int mmax = 0, mmin = 0;
        for (int i = 0; i < l; i++) {
            mmax += tmp[i] * pow(10, i);
            mmin += tmp[l - i - 1] * pow(10, i);
        }
        int rtmp = mmax - mmin;
        for (int i = 0; i < v.size(); i++) {
            if (rtmp == v[i]) {
                printf("%d %d %ld\n", i, rtmp, v.size() - i);
                return;
            }
        }
        
        v.push_back(rtmp);
        a = to_string(rtmp);
    }
}
int main(int argc, char* argv[])
{
    freopen("/home/freaver/CODE_C/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/output.txt", "w", stdout);
    while (cin >> a >> l, l) {
        solve();
    }

    return 0;
}
