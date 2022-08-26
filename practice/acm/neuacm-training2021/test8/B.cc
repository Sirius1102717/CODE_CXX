#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int n, m, q, l, r;
int a[N];
void f()
{
    a[0] = 1;
    a[1] = 1;
    int i = 2;
    while (i <= N) {
        a[i] = a[i - 1] + a[i - 2];
        i++;
    }
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    f();
    while (cin >> n) {
        cin >> m;
        while (m--) {
            cin >> q >> l >> r;
            
        }
    }

    return 0;
}
