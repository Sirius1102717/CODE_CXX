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


int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    vector<int> v;
    cin >> n;
    while ( n ) {
        int temp = n / 2;
        if ( n == 2 || n == 1 ) {
            v.emplace_back(n);
            break;
        } else if ( n == 4 ) {
            v.emplace_back(3);
            v.emplace_back(1);
            break;
        }
        if ( n % 2 == 0 ) {
            v.emplace_back(temp);
        } else {
            v.emplace_back(temp + 1);
        }
        n /= 2;
    }
    int len = v.size();
    ll ans = 1;
    for ( int i = len - 1; i >= 0; i-- ) {
        cout << v[i] << " ";
        ans *= v[i];
    }
    cout << "\n" << ans << "\n";

    return 0;
}
