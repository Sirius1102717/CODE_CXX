#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;

template <class T>
size_t getHash(T s)
{
    return hash<T>{}(s);
}
using iset = set<int>;
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    iset s;
    while ( n-- ) {
        int m;
        cin >> m;
        s.insert(m);
    }
    cout << s.size() << "\n";
    for_each(s.begin(), s.end(), [](auto c) {
        cout << c << " ";
    });
    return 0;
}
