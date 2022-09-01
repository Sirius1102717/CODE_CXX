#include<bits/stdc++.h>
using namespace std;

int a[21];
bool visited[21];

bool bfs(int m, int len)
{
    // int tmp = m - 4;
    for ( int i = 1; i <= m; i++ ) {
        int tmp = len - a[i];
        for ( int j = m; j > 1; j-- ) {
            if ( a[i] + a[j] > len ) {
                return false;
            } else if ( a[i] + a[j] == len ) {
                break;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    int t, m;
    cin >> t;
    while ( t-- ) {
        cin >> m;
        int sum = 0;
        for ( int i = 1; i <= m; i++ ) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a + 1, a + 1 + m);
        cout << (bfs(m, sum / 4) ? "yes\n" : "no\n");
    }
    return 0;
}
