#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e6;

template <class T>
size_t getHash(T s)
{
    return hash<T>{}(s);
}

vector<int> v;
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        int m;
        cin >> m;
        v.emplace_back(m);
    }
    sort(v.begin(), v.end());
    int ans = MAXN;
    int i = 0;
    int j = 0;
    while ( i < n && j < n ) {
        while ( v[j] + 1 == v[j + 1] ) {
            j++;
        }
        ans = min(j - i + 1, ans);
        j++;
        i = j;
    }
    cout << ans << "\n";
    return 0;
}
