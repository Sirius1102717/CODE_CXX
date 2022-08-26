#include <cstring>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;
vector<int> a;
ll dp[2][105];
int binarySearch(int n, function<bool(int)> f)
{
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (f(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    int n;
    while (cin >> n) {

        for (int i = 0; i < n; i++) {
            int j;
            cin >> j;
            a.push_back(j);
        }
        vector<vector<int>> d, cnt;
        for (int v : a) {
            int i = binarySearch(d.size(), [&](int i) { return d[i].back() >= v; });
            int c = 1;
            if (i > 0) {
                int k = binarySearch(d[i - 1].size(), [&](int k) { return d[i - 1][k] < v; });
                c = cnt[i - 1].back() - cnt[i - 1][k];
            }
            if (i == d.size()) {
                d.push_back({ v });
                cnt.push_back({ 0, c });
            } else {
                d[i].push_back(v);
                cnt[i].push_back(cnt[i].back() + c);
            }
        }
        return cnt.back().back();
    }
    return 0;
}