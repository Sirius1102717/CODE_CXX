#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 2e6 + 1;



int m, d, nodes = 0;
ll si = 0, ai = 0, s[MAXN], a[MAXN];

void query(int x)
{
    int i = lower_bound(s + 1, s + si + 1, ai - x + 1) - s;
    nodes = a[s[i]];
    cout << nodes << "\n";
}

void add(int x)
{
    x = (x + nodes) % d;
    a[++ai] = x;
    while (si && a[s[si]] <= x) {
        si--;
    }
    s[++si] = ai;
}

int main(int argc, char *argv[])
{
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int x;
    char c[1];
    cin >> m >> d;
    while ( m-- ) {
        cin >> c >> x;
        if ( c[0] == 'A' ) {
            add(x);
        } else {
            query(x);
        }
    }

    return 0;
}
